#pragma once
#include "../sparse/sparse_arith.h"
#include "../sci/interp1.h"
#include "../algo/search.h"
#include "../spec/legendreP.h"

namespace slisc {
// ref: https://wuli.wiki/online/FEDVR.html
// ### the FEDVR global grid does not include the first and last Gaussian points ###
// i.e. the number of total Gaussian points is Nfe*(Ngs-1)-1
// Ngs include both ends of an FE

// calculate FEDVR global index `iFEDVR` from FE index `iFE` and DVR index `iDVR`
inline Long indFEDVR(Long_I iFE, Long_I iDVR, Long_I Ngs)
{ return (Ngs-1) * iFE + iDVR - 1; }

// calculate FE index and DVR index from global FEDVR index `iFEDVR`
inline Long indFE(Long_I iFEDVR, Long_I Ngs)
{ return (iFEDVR + 1) / (Ngs - 1); }

inline Long indDVR(Long_I iFEDVR, Long_I Ngs)
{ return (iFEDVR + 1) % (Ngs - 1); }

// interp 1D FEDVR grid
// x does not include both end points
// bounds include both end points
#ifdef SLS_USE_GSL
Doub fe_min(VecDoub_I x, Long_I Ngs);
Doub fe_max(VecDoub_I x, Long_I Ngs);

// given global FEDVR grid and function value, interpolate using basis polynomials
inline Comp fedvr_interp1(VecDoub_I x, VecComp_I y, Long_I Ngs, Doub_I x_q)
{
	Long Nx = x.size();
	if ((Nx+1)%(Ngs-1) != 0)
		SLS_ERR("(Nx+1)%(Ngs-1) != 0");
	Long Nb = (Nx+1)/(Ngs-1);
	// Doub xmin = fe_min(x, Ngs), xmax = fe_max(x, Ngs);
	Long ix; // grid index
	if (lookup(ix, x, x_q))
		return y[ix];
	Long iFE = indFE(ix, Ngs); // FE index
	Long start = indFEDVR(iFE, 0, Ngs);

	if (iFE == 0) { // first FE
		VecDoub x1(Ngs); VecComp y1(Ngs);
		Doub xmin = fe_min(x, Ngs);
		if (x_q <= xmin)
			return 0;
		x1[0] = xmin;
		copy(cut(x1, 1, Ngs-1), cut(x, 0, Ngs-1));
		y1[0] = 0;
		copy(cut(y1, 1, Ngs-1), cut(y, 0, Ngs-1));
		poly_comp_interp1 poly(x1, y1);
		return poly(x_q);
	}
	else if (iFE == Nb - 1) { // last FE
		VecDoub x1(Ngs); VecComp y1(Ngs);
		Doub xmax = fe_max(x, Ngs);
		if (x_q >= xmax)
			return 0;
		x1.end() = xmax;
		copy(cut(x1, 0, Ngs-1), cut(x, Nx-Ngs+1, Ngs-1));
		y1.end() = 0;
		copy(cut(y1, 0, Ngs-1), cut(y, Nx-Ngs+1, Ngs-1));
		poly_comp_interp1 poly(x1, y1);
		return poly(x_q);
	}
	else {
		poly_comp_interp1 poly(cut(x, start, Ngs), cut(y, start, Ngs));
		return poly(x_q);
	}
}

// 2d interp for fedvr
inline Comp fedvr_interp2(VecDoub_I x, VecDoub_I y, CmatComp_I val,
	Long_I Ngs, Doub_I x_q, Doub_I y_q)
{
	Long Nx = x.size(), Ny = y.size();
	if ((Nx+1)%(Ngs-1) != 0)
		SLS_ERR("(Nx+1)%(Ngs-1) != 0");
	if ((Ny+1)%(Ngs-1) != 0)
		SLS_ERR("(Ny+1)%(Ngs-1) != 0");
	Long Nbx = (Nx+1)/(Ngs-1), Nby = (Ny+1)/(Ngs-1);
	// Doub x_min = fe_min(x, Ngs), x_max = fe_max(x, Ngs);
	// Doub y_min = fe_min(y, Ngs), y_max = fe_max(y, Ngs);
	Long ix, iy; // grid index
	lookup(ix, x, x_q); lookup(iy, y, y_q);
	Long iFEx = indFE(ix, Ngs), iFEy = indFE(iy, Ngs); // FE index
	if (iFEx == 0 || iFEy == 0 || iFEx == Nbx - 1 || iFEy == Nby - 1) // 1st FE
		SLS_ERR("not implemented!");
	VecDoub y1(Ngs); VecComp val1(Ngs);
	Long start = indFEDVR(iFEy, 0, Ngs);
	SvecDoubC x_sli =  cut(x, ix, Ngs);
	for (Long j = start; j < start + Ngs; ++j) {
		poly_comp_interp1 poly(x_sli, cut0(val, ix, Ngs, j));
		val1[j-start] = poly(x_q);
		y1[j-start] = y[j];
	}
	poly_comp_interp1 poly(y1, val1);
	return poly(y_q);
}
#endif

// number of non-zero elements in fedvr second derivative matrix
inline Long fedvr_d2_nnz(Long_I Ngs, Long_I Nfe)
{
	return (Ngs*Ngs - 1)*Nfe - 4 * Ngs + 3;
}


// generate Gauss-Lobatto abscissas x and weights w
// ref: https://wuli.wiki/changed/GLquad.html
// x is in [-1,1]
// data from https://keisan.casio.com/exec/system/1280801905
// also verified with Mathematica to last digit
// use ~38 digits data in case Qdoub is needed
inline void GaussLobatto(VecDoub_O x, VecDoub_O w)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != w.size())
		SLS_ERR("wrong shape!");
#endif
	Long_I N = x.size();
	Long N2 = N/2;
	x[0] = -1; x[N - 1] = 1;
	// only set 0 <= x < 1 and w for x >= 0! Others will be calculated. index is 0 based!
	if (N == 4) {
		x[2] = 0.44721359549995793928183473374625524709;

		w[2] = 0.83333333333333333333333333333333333333;
		w[3] = 0.16666666666666666666666666666666666667;
	}
	else if (N == 6) {
		x[3] = 0.28523151648064509631415099404087907192;
		x[4] = 0.76505532392946469285100297395933815037;

		w[3] = 0.55485837703548635301672052512130868086;
		w[4] = 0.37847495629784698031661280821202465248;
		w[5] = 0.066666666666666666666666666666666666667;
	}
	else if (N == 8) {
		x[4] = 0.2092992179024788687686572603453512553;
		x[5] = 0.59170018143314230214451073139795318995;
		x[6] = 0.8717401485096066153374457612206634381;

		w[4] = 0.41245879465870388156705297140220978948;
		w[5] = 0.34112269248350436476424067710774817178;
		w[6] = 0.2107042271435060393829920657757563245;
		w[7] = 0.035714285714285714285714285714285714286;
	}
	else if (N == 10) {
		x[5] = 0.16527895766638702462621976595817353323;
		x[6] = 0.47792494981044449566117509273125799789;
		x[7] = 0.73877386510550507500310617485983072502;
		x[8] = 0.91953390816645881382893266082233813415;

		w[5] = 0.32753976118389745665651052791689314471;
		w[6] = 0.29204268367968375787558225737444389221;
		w[7] = 0.22488934206312645211945782173104784275;
		w[8] = 0.13330599085107011112622717075539289811;
		w[9] = 0.022222222222222222222222222222222222222;
	}
	else if (N == 12) {
		x[6] = 0.1365529328549275548640618557396938969;
		x[7] = 0.3995309409653489322643497915669669005;
		x[8] = 0.63287615303186067766240485444365585824;
		x[9] = 0.81927932164400667834864158171690266069;
		x[10] = 0.94489927222288222340758013830321871361;

		w[6] = 0.2714052409106961770002883384996028404;
		w[7] = 0.25127560319920128029324441214759618333;
		w[8] = 0.2125084177610211453583020773668662702;
		w[9] = 0.15797470556437011516467106270034026825;
		w[10] = 0.09168451741319613066834259413407928631;
		w[11] = 0.015151515151515151515151515151515151515;
	}
	else if (N == 14) {
		x[7] = 0.11633186888370386765877670973616016794;
		x[8] = 0.34272401334271284504390340364167464483;
		x[9] = 0.55063940292864705531662270585908063446;
		x[10] = 0.72886859909132614058467240052088159566;
		x[11] = 0.86780105383034725100022020290826421325;
		x[12] = 0.95993504526726090135510016201542438907;

		w[7] = 0.2316127944684570588896283572926391903;
		w[8] = 0.21912625300977075487116252395416761296;
		w[9] = 0.1948261493734161186403317783758845121;
		w[10] = 0.1600218517629521424128209979875946405;
		w[11] = 0.11658665589871165154099667065465023;
		w[12] = 0.0668372844976812846340706607460528251;
		w[13] = 0.010989010989010989010989010989010989011;
	}
	else if (N == 16) {
		x[8] = 0.10132627352194944784303300504591776253;
		x[9] = 0.29983046890076320809835345472230064782;
		x[10] = 0.48605942188713761178189078584687469689;
		x[11] = 0.65238870288249308946788321964058148032;
		x[12] = 0.79200829186181506393108827096314570581;
		x[13] = 0.89920053309347209299462826151984947675;
		x[14] = 0.96956804627021793295224273836745924139;

		w[8] = 0.20195830817822987148919912541094012055;
		w[9] = 0.19369002382520358431691359885352203031;
		w[10] = 0.17749191339170412530107566952835777016;
		w[11] = 0.15402698080716428081564494048499451545;
		w[12] = 0.12425538213251409834953633265731320077;
		w[13] = 0.0893936973259308009910520801660837149;
		w[14] = 0.0508503610059199054032449195654553145;
		w[15] = 0.0083333333333333333333333333333333333333;
	}
	else if (N == 18) {
		x[9] = 0.0897490934846521110226450100885617349606;
		x[10] = 0.2663626528782809841676653320255959420651;
		x[11] = 0.4344150369121239753422871367406747958497;
		x[12] = 0.5885048343186617611735358931935594690008;
		x[13] = 0.7236793292832426813062103653020706791495;
		x[14] = 0.8355935352180902137136463623279372574336;
		x[15] = 0.9206491853475338738378546254312774235623;
		x[16] = 0.9761055574121985428645189243417000667618;

		w[9] = 0.179015863439703082293818806943525168195;
		w[10] = 0.1732621094894562260106144038266834217245;
		w[11] = 0.1619395172376024892643267067002284719607;
		w[12] = 0.1454119615738022679830032104944267724854;
		w[13] = 0.1242105331329671002633963588967467799607;
		w[14] = 0.099016271717502802394423605318672107918;
		w[15] = 0.07063716688563366499922296016778633310129;
		w[16] = 0.0399706288109140661375991764101008792943;
		w[17] = 0.006535947712418300653594771241830065359477;
	}
	else if (N == 20) {
		x[10] = 0.08054593723882183797594451815955446302239;
		x[11] = 0.2395517059229864951824013569270880719415;
		x[12] = 0.3923531837139092993864747038158243666652;
		x[13] = 0.5349928640318862616481359618289839830069;
		x[14] = 0.6637764022903112898464033229711588524757;
		x[15] = 0.7753682609520558704143175275946913433727;
		x[16] = 0.8668779780899501413098472146162852139629;
		x[17] = 0.9359344988126654357161815849306269299156;
		x[18] = 0.9807437048939141719254464385842309152299;

		w[10] = 0.1607432863878457490077267264490839339021;
		w[11] = 0.1565801026474754871581698967936433723031;
		w[12] = 0.1483615540709168258147130137339666049312;
		w[13] = 0.1363004823587241844897807929890319817441;
		w[14] = 0.1207092276286747250994297050023933598723;
		w[15] = 0.1019914996994508156837812057328865208675;
		w[16] = 0.08063176399611960314477684611372057166604;
		w[17] = 0.05718180212756682600475362717324278250521;
		w[18] = 0.03223712318848894149160502811729403010325;
		w[19] = 0.005263157894736842105263157894736842105263;
	}
	else {
		SLS_ERR("no data!");
	}
	for (Long i = 1; i < N2; ++i)
		x[i] = -x[N - i - 1];
	for (Long i = 0; i < N2; ++i)
		w[i] = w[N - i - 1];
}

inline Doub fe_min(VecDoub_I x, Long_I Ngs)
{
#ifdef SLS_CHECK_BOUNDS
	if (x.size() <= Ngs-2)
		SLS_ERR("fe_min: x.size() too small!");
#endif
	return x[0] - (x[Ngs-2]-x[Ngs-3]);
}

inline Doub fe_max(VecDoub_I x, Long_I Ngs)
{
#ifdef SLS_CHECK_BOUNDS
	if (x.size() <= Ngs-2)
		SLS_ERR("fe_max: x.size() too small!");
#endif
	return x.end() + (x[x.size()-Ngs+2] - x[x.size()-Ngs+1]);
}

// single DVR basis polynomial, range [-1,1] with maximum 1
// return 0 if out of range
inline Doub dvr_basis(VecDoub x, Long_I ind, Doub_I x_q)
{
	Long Ngs = size(x);
	Doub x_ind = x[ind], poly = 1;
	if (x_q < -1 || x_q > 1)
		return 0;
	for (Long i = 0; i < ind; ++i)
		poly *= (x_q - x[i])/(x_ind - x[i]);
	for (Long i = ind + 1; i < Ngs; ++i)
		poly *= (x_q - x[i])/(x_ind - x[i]);
	return poly;
}

// single FEDVR basis polynomial, with maximum 1
// return 0 if out of range
// x is the FEDVR global grid (without first and last gaussian point)
inline Doub fedvr_basis(VecDoub_I x, Long_I Ngs, Long_I ind, Doub_I x_q)
{
	Long iDVR = indDVR(ind, Ngs);
	Long start = ind - iDVR; // left boundary of FE to eval polynomial
	Doub x_ind = x[ind], poly;

	// x_q on the left half of the bridge function
	if (iDVR == 0 && x_q <= x[start]) {
		if (x_q == x[start])
			return 1;
		start -= Ngs - 1;
	}

	Long end = start + Ngs - 1; // right boundary of FE to eval polynomial

	// left FE boundary
	if (start == -1) {
		Doub xmin = fe_min(x, Ngs);
		if (x_q <= xmin)
			return 0;
		poly = (x_q-xmin)/(x_ind-xmin);
		++start;
	}
	else {
		if (x_q <= x[start])
			return 0;
		poly = 1;
	}
		
	// right FE boundary
	if (end == x.size()) {
		Doub xmax = fe_max(x, Ngs);
		if (x_q >= xmax)
			return 0;
		poly *= (x_q-xmax)/(x_ind-xmax);
		--end;
	}
	else if (x_q >= x[end]) {
		return 0;
	}

	// middle terms of polynomial
	for (Long i = start; i < ind; ++i)
		poly *= (x_q - x[i])/(x_ind - x[i]);
	for (Long i = ind + 1; i <= end; ++i)
		poly *= (x_q - x[i])/(x_ind - x[i]);
	return poly;
}

void GaussLobatto_check(VecDoub_I x, VecDoub_I w)
{
	Long N = x.size();
	// Doub x_err_max = 0, w_err_max = 0;
	for (Long i = 0; i < N; ++i) {
		if (i > 0 && i < N-1) {
			Doub err = legendreP_der(N-1, x[i]);
			// if (abs(err) > x_err_max) x_err_max = err;
			if (abs(err) > 1e-12)
				SLS_ERR("i = " + to_string(i) + ", err1 = " + num2str(err));
		}
		Doub err = w[i] - 2/(N*(N-1)*sqr(legendre_Plm(N-1, 0, x[i])));
		// if (abs(err) > w_err_max) w_err_max = err;
		if (abs(err) > 1e-12)
			SLS_ERR("i = " + to_string(i) + ", err2 = " + num2str(err));
	}
	// cout << "x_err_max = " << x_err_max << endl;
	// cout << "w_err_max = " << w_err_max << endl;
}

// the bases are not orthogonal
// return [-1,1] integral of dvr_basis(i)/sqrt(w(i)) * dvr_basis(j)/sqrt(w(j)) matrix
// x_plot, y_plot(:,i) is the curve for the i-th normalized basis [-1,1]
inline void GaussLobatto_check_orthogonal(CmatDoub_O y_plot, VecDoub_O x, VecDoub_O w, CmatDoub_O mat, VecDoub_I x_plot)
{
	Long Ngs = mat.n0();
	SLS_ASSERT(mat.n1() == Ngs);
	SLS_ASSERT(x.size() == Ngs);
	SLS_ASSERT(w.size() == Ngs);
	SLS_ASSERT(y_plot.n0() == x_plot.size());
	SLS_ASSERT(y_plot.n1() == Ngs);
	VecDoub xx(Ngs+2), ww(Ngs+2);
	GaussLobatto(x, w);
	GaussLobatto(xx, ww);
	for (Long ind1 = 0; ind1 < Ngs; ++ind1) {
		// plot data
		for (Long i = 0; i < x_plot.size(); ++i)
			y_plot(i, ind1) = dvr_basis(x, ind1, x_plot[i]) / sqrt(w[ind1]);
		// check orthogonal
		for (Long ind2 = 0; ind2 <= ind1; ++ind2) {
			Doub sum = 0;
			for (Long ii = 0; ii < size(xx); ++ii)
				sum += ww[ii] * dvr_basis(x, ind1, xx[ii]) * dvr_basis(x, ind2, xx[ii]);
			sum *= 1/sqrt(w[ind1]*w[ind2]);
			mat(ind1, ind2) = sum;
			if (ind1 != ind2)
				mat(ind2, ind1) = sum;
		}
	}
}

// get derivatives of lagrange interpolation polynomials at abscissas
// x in [-1,1] are the Ngs Gaussian points
// ref: eq_FEDVR_9
// df is an NxN matrix
// f'_i(x_j) = df(j,i) / sqrt{w_0i}
inline void dvr_basis_der(CmatDoub_O df, VecDoub_I x, VecDoub_I w)
{
	Long i, j, k, N{ x.size() };
	Doub sum;
#ifdef SLS_CHECK_SHAPES
	if (df.n0() != N || df.n1() != N)
		SLS_ERR("wrong shape!");
#endif
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (j != i) {
				sum = 1.;
				for (k = 0; k < i; ++k) {
					if (k == j) sum /= x[i] - x[k];
					else sum *= (x[j] - x[k]) / (x[i] - x[k]);
				}
				for (k = i + 1; k < N; ++k) {
					if (k == j) sum /= x[i] - x[k];
					else sum *= (x[j] - x[k]) / (x[i] - x[k]);
				}
			}
			else {
				sum = 0.;
				for (k = 0; k < i; ++k)
					sum += 1. / (x[i] - x[k]);
				for (k = i + 1; k < N; ++k)
					sum += 1. / (x[i] - x[k]);
			}
			df(j,i) = sum / sqrt(w[i]);
		}
	}
}

// generate FEDVR grid and weight
// 'Nfe' is the number of finite elements
// 'Ngs' is the number of abscissas in each element (including 2 boundaries)
// 'bounds' size = Nfe+1, are the boundary points of finite elements
// 'x0','w0' are grid points and weights in [-1,1]
// 'x','w' are the global grid points and weights
// 'xFE','wFE' are middle point and half width of each FE
inline void FEDVR_grid(VecDoub_O x, VecDoub_O w, VecDoub_I wFE, VecDoub_I xFE, VecDoub_I x0, VecDoub_I w0)
{
	Long i, j, k = 0;
	Long Ngs = x0.size();
	Long Nfe = wFE.size();
	Long Nx = Nfe * (Ngs - 1) - 1;
#ifdef SLS_CHECK_SHAPES
	if (x.size() != Nx || w.size() != Nx)
		SLS_ERR("wrong shape!");
#endif
	Doub a, b;
	for (i = 0; i < Nfe; ++i) {
		a = wFE[i];
		b = xFE[i];
		if (i > 0)
			w[k-1] += a*w0[0];
		for (j = 1; j < Ngs; ++j) {
			x[k] = a*x0[j] + b;
			w[k] = a*w0[j];
			if (++k == Nx) break;
		}
	}
}

// simpler interface
inline void FEDVR_grid(VecDoub_O x, VecDoub_O w, VecDoub_I bounds, Long_I Ngs)
{
	Long Nfe = bounds.size() - 1;
	VecDoub x0(Ngs), w0(Ngs), wFE(Nfe), xFE(Nfe);
	GaussLobatto(x0, w0);
	for (Long i = 0; i < Nfe; ++i) {
		wFE[i] = 0.5*(bounds[i+1] - bounds[i]);
		xFE[i] = 0.5*(bounds[i] + bounds[i+1]);
	}
	FEDVR_grid(x, w, wFE, xFE, x0, w0);
}

// sparse second derivative matrix for normalized FEDVR basis
inline void D2_matrix(McooDoub_O D2, VecDoub_I w0, VecDoub_I wFE, CmatDoub_I df)
{
	Long i, j, k, m, n, mm, nn;
	Long Nfe = wFE.size();
	Long Ngs = w0.size();
#ifdef SLS_CHECK_SHAPES
	Long Nx = Nfe * (Ngs - 1) - 1;
	if (D2.n0() != Nx || D2.n1() != Nx)
		SLS_ERR("wrong shape!");
#endif

	Doub s, coeff;

	// prepare basic block
	CmatDoub block(Ngs, Ngs);
	for (j = 0; j < Ngs; ++j) {
		for (i = 0; i <= j; ++i) {
			s = 0.;
			for (k = 0; k < Ngs; ++k)
				s += w0[k] * df(k, i) * df(k, j);
			block(i, j) = s;
		}
	}

	// calculate D2 matrix
	D2.resize(0);
	D2.reserve(fedvr_d2_nnz(Ngs, Nfe)); // # non-zero elements
	for (i = 0; i < Nfe; ++i) {
		// blocks without boundary
		for (n = 1; n < Ngs - 1; ++n) {
			coeff = -1. / sqr(wFE[i]);
			for (m = 1; m <= n; ++m) {
				mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i, n, Ngs);
				s = coeff * block(m,n);
				D2.push(s, mm, nn);
				if (mm != nn) {
					D2.push(s, nn, mm);
				}
			}
		}
	}

	for (i = 0; i < Nfe - 1; ++i) {
		// block right & bottom boundary
		n = Ngs - 1;
		coeff = -1. / (pow(wFE[i], 1.5) * sqrt(wFE[i] + wFE[i + 1]));
		for (m = 1; m < n; ++m) {
			mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i, n, Ngs);
			s = coeff * block(m, n);
			D2.push(s, mm, nn); D2.push(s, nn, mm);
		}

		// block lower right corner
		m = Ngs - 1;
		coeff = -1. / (wFE[i] + wFE[i+1]);
		mm = indFEDVR(i, m, Ngs);
		s = coeff*(block(m,n)/wFE[i] + block(0,0)/wFE[i+1]);
		D2.push(s, mm, mm);

		// block left & upper boundary
		coeff = -1. / (pow(wFE[i+1], 1.5) * sqrt(wFE[i] + wFE[i+1]));
		for (n = 1; n < Ngs - 1; ++n) {
			mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i + 1, n, Ngs);
			s = coeff * block(0, n);
			D2.push(s, mm, nn); D2.push(s, nn, mm);
		}
	}

	for (i = 0; i < Nfe - 2; ++i) {
		// block upper right corner
		coeff = -1. / (wFE[i+1] * sqrt((wFE[i] + wFE[i+1])*(wFE[i+1] + wFE[i+2])));
		mm = indFEDVR(i, Ngs-1, Ngs); nn = indFEDVR(i + 1, Ngs-1, Ngs);
		s = coeff * block(0, Ngs - 1);
		D2.push(s, mm, nn); D2.push(s, nn, mm);
	}
	sort_r(D2);
}

// bounds: FE boundaries, size = Nfe + 1
// Ngs: grid points per finite element (including boundaries)
// `x`, `w` are the global grid points and weights
// `u` is the maximum value of each basis
inline void D2_matrix(McooDoub_O D2, VecDoub_O x, VecDoub_O w, VecDoub_O u, VecDoub_I bounds, Long_I Ngs)
{
	Long Nfe = bounds.size() - 1; // number of finite elements
#ifdef SLS_CHECK_SHAPES
	Long Nx = Nfe * (Ngs - 1) - 1;
	if (x.size() != Nx || w.size() != Nx || u.size() != Nx ||
		D2.n0() != Nx || D2.n1() != Nx)
		SLS_ERR("wrong shape!");
#endif

	// grid points, weights, base function values in [-1, 1]
	VecDoub x0(Ngs), w0(Ngs), f0(Ngs);
	GaussLobatto(x0, w0);
	CmatDoub df(Ngs, Ngs); // df(i, j) = f_j(x_i)
	dvr_basis_der(df, x0, w0);

	// midpoints, widths and bounds of finite elements
	VecDoub xFE(Nfe), wFE(Nfe);

	for (Long i = 0; i < Nfe; ++i) {
		wFE[i] = 0.5*(bounds[i+1] - bounds[i]);
		xFE[i] = 0.5*(bounds[i] + bounds[i+1]);
	}

	FEDVR_grid(x, w, wFE, xFE, x0, w0);
	pow(u, w, -0.5);

	// Sparse matrix
	D2_matrix(D2, w0, wFE, df);
}

// sparse first derivative matrix for normalized FEDVR basis
inline void D_matrix(McooDoub_O D, VecDoub_I w0, VecDoub_I wFE, CmatDoub_I df)
{
	Long i, m, n, mm, nn;
	Long Nfe = wFE.size();
	Long Ngs = w0.size();
#ifdef SLS_CHECK_SHAPES
	Long Nx = Nfe * (Ngs - 1) - 1;
	if (D.n0() != Nx || D.n1() != Nx)
		SLS_ERR("wrong shape!");
#endif

	Doub s, coeff;

	// calculate D matrix
	D.resize(0);
	D.reserve(fedvr_d2_nnz(Ngs, Nfe)); // # non-zero elements

	// blocks without boundary
	for (i = 0; i < Nfe; ++i) {
		for (n = 1; n < Ngs - 1; ++n) {
			coeff = 1. / wFE[i];
			for (m = 1; m <= n; ++m) {
				s = coeff * sqrt(w0[m]) * df(m,n);
				mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i, n, Ngs);
				D.push(s, mm, nn);
				if (mm != nn)
					D.push(-s, nn, mm);
			}
		}
	}

	for (i = 0; i < Nfe - 1; ++i) {
		// block right & bottom boundary
		n = Ngs - 1;
		coeff = 1. / sqrt(wFE[i]*(wFE[i] + wFE[i + 1]));
		for (m = 1; m < n; ++m) {
			s = coeff * sqrt(w0[m]) *  df(m, n);
			mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i, n, Ngs);
			D.push(s, mm, nn); D.push(-s, nn, mm);
		}

		// block lower right corner are all 0

		// block left & upper boundary
		m = Ngs - 1;
		coeff = sqrt(w0[0] / (wFE[i+1]*(wFE[i] + wFE[i+1])));
		for (n = 1; n < Ngs - 1; ++n) {
			s = coeff * df(0, n);
			mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i + 1, n, Ngs);
			D.push(s, mm, nn); D.push(-s, nn, mm);
		}
	}

	for (i = 0; i < Nfe - 2; ++i) {
		// block upper right corner
		coeff = sqrt(w0[0] / ((wFE[i] + wFE[i+1])*(wFE[i+1] + wFE[i+2])));
		s = coeff * df(0, Ngs - 1);
		mm = indFEDVR(i, Ngs-1, Ngs); nn = indFEDVR(i + 1, Ngs-1, Ngs);
		D.push(s, mm, nn); D.push(-s, nn, mm);
	}
	sort_r(D);
}

inline void D_matrix(McooDoub_O D, VecDoub_O x, VecDoub_O w, VecDoub_O u, VecDoub_I bounds, Long_I Ngs)
{
	Long Nfe = bounds.size() - 1; // number of finite elements
#ifdef SLS_CHECK_SHAPES
	Long Nx = Nfe * (Ngs - 1) - 1;
	if (x.size() != Nx || w.size() != Nx || u.size() != Nx)
		SLS_ERR("wrong shape!");
#endif

	// grid points, weights, base function values in [-1, 1]
	VecDoub x0(Ngs), w0(Ngs), f0(Ngs);
	GaussLobatto(x0, w0);
	CmatDoub df(Ngs, Ngs); // df(i, j) = f'_j(x_i)
	dvr_basis_der(df, x0, w0);

	// midpoints, widths and bounds of finite elements
	VecDoub xFE(Nfe), wFE(Nfe);

	for (Long i = 0; i < Nfe; ++i) {
		wFE[i] = 0.5*(bounds[i+1] - bounds[i]);
		xFE[i] = 0.5*(bounds[i] + bounds[i+1]);
	}

	FEDVR_grid(x, w, wFE, xFE, x0, w0);
	pow(u, w, -0.5);

	// Sparse matrix
	D_matrix(D, w0, wFE, df);
}


// generate Gauss-Lobatto abscissas x and weights w
// ref: https://wuli.wiki/changed/GLquad.html
// x is in [-1,1]
// data from https://keisan.casio.com/exec/system/1280801905
// also verified with Mathematica to last digit
// use ~38 digits data in case Qdoub is needed
inline void GaussLobatto(VecQdoub_O x, VecQdoub_O w)
{
#ifdef SLS_CHECK_SHAPES
	if (x.size() != w.size())
		SLS_ERR("wrong shape!");
#endif
	Long_I N = x.size();
	Long N2 = N/2;
	x[0] = -1; x[N - 1] = 1;
	// only set 0 <= x < 1 and w for x >= 0! Others will be calculated. index is 0 based!
	if (N == 4) {
		x[2] = 0.44721359549995793928183473374625524709Q;

		w[2] = 0.83333333333333333333333333333333333333Q;
		w[3] = 0.16666666666666666666666666666666666667Q;
	}
	else if (N == 6) {
		x[3] = 0.28523151648064509631415099404087907192Q;
		x[4] = 0.76505532392946469285100297395933815037Q;

		w[3] = 0.55485837703548635301672052512130868086Q;
		w[4] = 0.37847495629784698031661280821202465248Q;
		w[5] = 0.066666666666666666666666666666666666667Q;
	}
	else if (N == 8) {
		x[4] = 0.2092992179024788687686572603453512553Q;
		x[5] = 0.59170018143314230214451073139795318995Q;
		x[6] = 0.8717401485096066153374457612206634381Q;

		w[4] = 0.41245879465870388156705297140220978948Q;
		w[5] = 0.34112269248350436476424067710774817178Q;
		w[6] = 0.2107042271435060393829920657757563245Q;
		w[7] = 0.035714285714285714285714285714285714286Q;
	}
	else if (N == 10) {
		x[5] = 0.16527895766638702462621976595817353323Q;
		x[6] = 0.47792494981044449566117509273125799789Q;
		x[7] = 0.73877386510550507500310617485983072502Q;
		x[8] = 0.91953390816645881382893266082233813415Q;

		w[5] = 0.32753976118389745665651052791689314471Q;
		w[6] = 0.29204268367968375787558225737444389221Q;
		w[7] = 0.22488934206312645211945782173104784275Q;
		w[8] = 0.13330599085107011112622717075539289811Q;
		w[9] = 0.022222222222222222222222222222222222222Q;
	}
	else if (N == 12) {
		x[6] = 0.1365529328549275548640618557396938969Q;
		x[7] = 0.3995309409653489322643497915669669005Q;
		x[8] = 0.63287615303186067766240485444365585824Q;
		x[9] = 0.81927932164400667834864158171690266069Q;
		x[10] = 0.94489927222288222340758013830321871361Q;

		w[6] = 0.2714052409106961770002883384996028404Q;
		w[7] = 0.25127560319920128029324441214759618333Q;
		w[8] = 0.2125084177610211453583020773668662702Q;
		w[9] = 0.15797470556437011516467106270034026825Q;
		w[10] = 0.09168451741319613066834259413407928631Q;
		w[11] = 0.015151515151515151515151515151515151515Q;
	}
	else if (N == 14) {
		x[7] = 0.11633186888370386765877670973616016794Q;
		x[8] = 0.34272401334271284504390340364167464483Q;
		x[9] = 0.55063940292864705531662270585908063446Q;
		x[10] = 0.72886859909132614058467240052088159566Q;
		x[11] = 0.86780105383034725100022020290826421325Q;
		x[12] = 0.95993504526726090135510016201542438907Q;

		w[7] = 0.2316127944684570588896283572926391903Q;
		w[8] = 0.21912625300977075487116252395416761296Q;
		w[9] = 0.1948261493734161186403317783758845121Q;
		w[10] = 0.1600218517629521424128209979875946405Q;
		w[11] = 0.11658665589871165154099667065465023Q;
		w[12] = 0.0668372844976812846340706607460528251Q;
		w[13] = 0.010989010989010989010989010989010989011Q;
	}
	else if (N == 16) {
		x[8] = 0.10132627352194944784303300504591776253Q;
		x[9] = 0.29983046890076320809835345472230064782Q;
		x[10] = 0.48605942188713761178189078584687469689Q;
		x[11] = 0.65238870288249308946788321964058148032Q;
		x[12] = 0.79200829186181506393108827096314570581Q;
		x[13] = 0.89920053309347209299462826151984947675Q;
		x[14] = 0.96956804627021793295224273836745924139Q;

		w[8] = 0.20195830817822987148919912541094012055Q;
		w[9] = 0.19369002382520358431691359885352203031Q;
		w[10] = 0.17749191339170412530107566952835777016Q;
		w[11] = 0.15402698080716428081564494048499451545Q;
		w[12] = 0.12425538213251409834953633265731320077Q;
		w[13] = 0.0893936973259308009910520801660837149Q;
		w[14] = 0.0508503610059199054032449195654553145Q;
		w[15] = 0.0083333333333333333333333333333333333333Q;
	}
	else if (N == 18) {
		x[9] = 0.0897490934846521110226450100885617349606Q;
		x[10] = 0.2663626528782809841676653320255959420651Q;
		x[11] = 0.4344150369121239753422871367406747958497Q;
		x[12] = 0.5885048343186617611735358931935594690008Q;
		x[13] = 0.7236793292832426813062103653020706791495Q;
		x[14] = 0.8355935352180902137136463623279372574336Q;
		x[15] = 0.9206491853475338738378546254312774235623Q;
		x[16] = 0.9761055574121985428645189243417000667618Q;

		w[9] = 0.179015863439703082293818806943525168195Q;
		w[10] = 0.1732621094894562260106144038266834217245Q;
		w[11] = 0.1619395172376024892643267067002284719607Q;
		w[12] = 0.1454119615738022679830032104944267724854Q;
		w[13] = 0.1242105331329671002633963588967467799607Q;
		w[14] = 0.099016271717502802394423605318672107918Q;
		w[15] = 0.07063716688563366499922296016778633310129Q;
		w[16] = 0.0399706288109140661375991764101008792943Q;
		w[17] = 0.006535947712418300653594771241830065359477Q;
	}
	else if (N == 20) {
		x[10] = 0.08054593723882183797594451815955446302239Q;
		x[11] = 0.2395517059229864951824013569270880719415Q;
		x[12] = 0.3923531837139092993864747038158243666652Q;
		x[13] = 0.5349928640318862616481359618289839830069Q;
		x[14] = 0.6637764022903112898464033229711588524757Q;
		x[15] = 0.7753682609520558704143175275946913433727Q;
		x[16] = 0.8668779780899501413098472146162852139629Q;
		x[17] = 0.9359344988126654357161815849306269299156Q;
		x[18] = 0.9807437048939141719254464385842309152299Q;

		w[10] = 0.1607432863878457490077267264490839339021Q;
		w[11] = 0.1565801026474754871581698967936433723031Q;
		w[12] = 0.1483615540709168258147130137339666049312Q;
		w[13] = 0.1363004823587241844897807929890319817441Q;
		w[14] = 0.1207092276286747250994297050023933598723Q;
		w[15] = 0.1019914996994508156837812057328865208675Q;
		w[16] = 0.08063176399611960314477684611372057166604Q;
		w[17] = 0.05718180212756682600475362717324278250521Q;
		w[18] = 0.03223712318848894149160502811729403010325Q;
		w[19] = 0.005263157894736842105263157894736842105263Q;
	}
	else {
		SLS_ERR("no data!");
	}
	for (Long i = 1; i < N2; ++i)
		x[i] = -x[N - i - 1];
	for (Long i = 0; i < N2; ++i)
		w[i] = w[N - i - 1];
}

inline Qdoub fe_min(VecQdoub_I x, Long_I Ngs)
{
#ifdef SLS_CHECK_BOUNDS
	if (x.size() <= Ngs-2)
		SLS_ERR("fe_min: x.size() too small!");
#endif
	return x[0] - (x[Ngs-2]-x[Ngs-3]);
}

inline Qdoub fe_max(VecQdoub_I x, Long_I Ngs)
{
#ifdef SLS_CHECK_BOUNDS
	if (x.size() <= Ngs-2)
		SLS_ERR("fe_max: x.size() too small!");
#endif
	return x.end() + (x[x.size()-Ngs+2] - x[x.size()-Ngs+1]);
}

// single DVR basis polynomial, range [-1,1] with maximum 1
// return 0 if out of range
inline Qdoub dvr_basis(VecQdoub x, Long_I ind, Qdoub_I x_q)
{
	Long Ngs = size(x);
	Qdoub x_ind = x[ind], poly = 1;
	if (x_q < -1 || x_q > 1)
		return 0;
	for (Long i = 0; i < ind; ++i)
		poly *= (x_q - x[i])/(x_ind - x[i]);
	for (Long i = ind + 1; i < Ngs; ++i)
		poly *= (x_q - x[i])/(x_ind - x[i]);
	return poly;
}

// single FEDVR basis polynomial, with maximum 1
// return 0 if out of range
// x is the FEDVR global grid (without first and last gaussian point)
inline Qdoub fedvr_basis(VecQdoub_I x, Long_I Ngs, Long_I ind, Qdoub_I x_q)
{
	Long iDVR = indDVR(ind, Ngs);
	Long start = ind - iDVR; // left boundary of FE to eval polynomial
	Qdoub x_ind = x[ind], poly;

	// x_q on the left half of the bridge function
	if (iDVR == 0 && x_q <= x[start]) {
		if (x_q == x[start])
			return 1;
		start -= Ngs - 1;
	}

	Long end = start + Ngs - 1; // right boundary of FE to eval polynomial

	// left FE boundary
	if (start == -1) {
		Qdoub xmin = fe_min(x, Ngs);
		if (x_q <= xmin)
			return 0;
		poly = (x_q-xmin)/(x_ind-xmin);
		++start;
	}
	else {
		if (x_q <= x[start])
			return 0;
		poly = 1;
	}
		
	// right FE boundary
	if (end == x.size()) {
		Qdoub xmax = fe_max(x, Ngs);
		if (x_q >= xmax)
			return 0;
		poly *= (x_q-xmax)/(x_ind-xmax);
		--end;
	}
	else if (x_q >= x[end]) {
		return 0;
	}

	// middle terms of polynomial
	for (Long i = start; i < ind; ++i)
		poly *= (x_q - x[i])/(x_ind - x[i]);
	for (Long i = ind + 1; i <= end; ++i)
		poly *= (x_q - x[i])/(x_ind - x[i]);
	return poly;
}

void GaussLobatto_check(VecQdoub_I x, VecQdoub_I w)
{
	Long N = x.size();
	// Qdoub x_err_max = 0, w_err_max = 0;
	for (Long i = 0; i < N; ++i) {
		if (i > 0 && i < N-1) {
			Qdoub err = legendreP_der(N-1, x[i]);
			// if (abs(err) > x_err_max) x_err_max = err;
			if (abs(err) > 1.5e-31)
				SLS_ERR("i = " + to_string(i) + ", err1 = " + num2str(err));
		}
		Qdoub err = w[i] - 2/(N*(N-1)*sqr(legendre_Plm(N-1, 0, x[i])));
		// if (abs(err) > w_err_max) w_err_max = err;
		if (abs(err) > 1.5e-31)
			SLS_ERR("i = " + to_string(i) + ", err2 = " + num2str(err));
	}
	// cout << "x_err_max = " << x_err_max << endl;
	// cout << "w_err_max = " << w_err_max << endl;
}

// the bases are not orthogonal
// return [-1,1] integral of dvr_basis(i)/sqrt(w(i)) * dvr_basis(j)/sqrt(w(j)) matrix
// x_plot, y_plot(:,i) is the curve for the i-th normalized basis [-1,1]
inline void GaussLobatto_check_orthogonal(CmatQdoub_O y_plot, VecQdoub_O x, VecQdoub_O w, CmatQdoub_O mat, VecQdoub_I x_plot)
{
	Long Ngs = mat.n0();
	SLS_ASSERT(mat.n1() == Ngs);
	SLS_ASSERT(x.size() == Ngs);
	SLS_ASSERT(w.size() == Ngs);
	SLS_ASSERT(y_plot.n0() == x_plot.size());
	SLS_ASSERT(y_plot.n1() == Ngs);
	VecQdoub xx(Ngs+2), ww(Ngs+2);
	GaussLobatto(x, w);
	GaussLobatto(xx, ww);
	for (Long ind1 = 0; ind1 < Ngs; ++ind1) {
		// plot data
		for (Long i = 0; i < x_plot.size(); ++i)
			y_plot(i, ind1) = dvr_basis(x, ind1, x_plot[i]) / sqrt(w[ind1]);
		// check orthogonal
		for (Long ind2 = 0; ind2 <= ind1; ++ind2) {
			Qdoub sum = 0;
			for (Long ii = 0; ii < size(xx); ++ii)
				sum += ww[ii] * dvr_basis(x, ind1, xx[ii]) * dvr_basis(x, ind2, xx[ii]);
			sum *= 1/sqrt(w[ind1]*w[ind2]);
			mat(ind1, ind2) = sum;
			if (ind1 != ind2)
				mat(ind2, ind1) = sum;
		}
	}
}

// get derivatives of lagrange interpolation polynomials at abscissas
// x in [-1,1] are the Ngs Gaussian points
// ref: eq_FEDVR_9
// df is an NxN matrix
// f'_i(x_j) = df(j,i) / sqrt{w_0i}
inline void dvr_basis_der(CmatQdoub_O df, VecQdoub_I x, VecQdoub_I w)
{
	Long i, j, k, N{ x.size() };
	Qdoub sum;
#ifdef SLS_CHECK_SHAPES
	if (df.n0() != N || df.n1() != N)
		SLS_ERR("wrong shape!");
#endif
	for (i = 0; i < N; ++i) {
		for (j = 0; j < N; ++j) {
			if (j != i) {
				sum = 1.Q;
				for (k = 0; k < i; ++k) {
					if (k == j) sum /= x[i] - x[k];
					else sum *= (x[j] - x[k]) / (x[i] - x[k]);
				}
				for (k = i + 1; k < N; ++k) {
					if (k == j) sum /= x[i] - x[k];
					else sum *= (x[j] - x[k]) / (x[i] - x[k]);
				}
			}
			else {
				sum = 0.;
				for (k = 0; k < i; ++k)
					sum += 1.Q / (x[i] - x[k]);
				for (k = i + 1; k < N; ++k)
					sum += 1.Q / (x[i] - x[k]);
			}
			df(j,i) = sum / sqrt(w[i]);
		}
	}
}

// generate FEDVR grid and weight
// 'Nfe' is the number of finite elements
// 'Ngs' is the number of abscissas in each element (including 2 boundaries)
// 'bounds' size = Nfe+1, are the boundary points of finite elements
// 'x0','w0' are grid points and weights in [-1,1]
// 'x','w' are the global grid points and weights
// 'xFE','wFE' are middle point and half width of each FE
inline void FEDVR_grid(VecQdoub_O x, VecQdoub_O w, VecQdoub_I wFE, VecQdoub_I xFE, VecQdoub_I x0, VecQdoub_I w0)
{
	Long i, j, k = 0;
	Long Ngs = x0.size();
	Long Nfe = wFE.size();
	Long Nx = Nfe * (Ngs - 1) - 1;
#ifdef SLS_CHECK_SHAPES
	if (x.size() != Nx || w.size() != Nx)
		SLS_ERR("wrong shape!");
#endif
	Qdoub a, b;
	for (i = 0; i < Nfe; ++i) {
		a = wFE[i];
		b = xFE[i];
		if (i > 0)
			w[k-1] += a*w0[0];
		for (j = 1; j < Ngs; ++j) {
			x[k] = a*x0[j] + b;
			w[k] = a*w0[j];
			if (++k == Nx) break;
		}
	}
}

// simpler interface
inline void FEDVR_grid(VecQdoub_O x, VecQdoub_O w, VecQdoub_I bounds, Long_I Ngs)
{
	Long Nfe = bounds.size() - 1;
	VecQdoub x0(Ngs), w0(Ngs), wFE(Nfe), xFE(Nfe);
	GaussLobatto(x0, w0);
	for (Long i = 0; i < Nfe; ++i) {
		wFE[i] = 0.5*(bounds[i+1] - bounds[i]);
		xFE[i] = 0.5*(bounds[i] + bounds[i+1]);
	}
	FEDVR_grid(x, w, wFE, xFE, x0, w0);
}

// sparse second derivative matrix for normalized FEDVR basis
inline void D2_matrix(McooQdoub_O D2, VecQdoub_I w0, VecQdoub_I wFE, CmatQdoub_I df)
{
	Long i, j, k, m, n, mm, nn;
	Long Nfe = wFE.size();
	Long Ngs = w0.size();
#ifdef SLS_CHECK_SHAPES
	Long Nx = Nfe * (Ngs - 1) - 1;
	if (D2.n0() != Nx || D2.n1() != Nx)
		SLS_ERR("wrong shape!");
#endif

	Qdoub s, coeff;

	// prepare basic block
	CmatQdoub block(Ngs, Ngs);
	for (j = 0; j < Ngs; ++j) {
		for (i = 0; i <= j; ++i) {
			s = 0.;
			for (k = 0; k < Ngs; ++k)
				s += w0[k] * df(k, i) * df(k, j);
			block(i, j) = s;
		}
	}

	// calculate D2 matrix
	D2.resize(0);
	D2.reserve(fedvr_d2_nnz(Ngs, Nfe)); // # non-zero elements
	for (i = 0; i < Nfe; ++i) {
		// blocks without boundary
		for (n = 1; n < Ngs - 1; ++n) {
			coeff = -1.Q / sqr(wFE[i]);
			for (m = 1; m <= n; ++m) {
				mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i, n, Ngs);
				s = coeff * block(m,n);
				D2.push(s, mm, nn);
				if (mm != nn) {
					D2.push(s, nn, mm);
				}
			}
		}
	}

	for (i = 0; i < Nfe - 1; ++i) {
		// block right & bottom boundary
		n = Ngs - 1;
		coeff = -1.Q / (pow(wFE[i], 1.5Q) * sqrt(wFE[i] + wFE[i + 1]));
		for (m = 1; m < n; ++m) {
			mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i, n, Ngs);
			s = coeff * block(m, n);
			D2.push(s, mm, nn); D2.push(s, nn, mm);
		}

		// block lower right corner
		m = Ngs - 1;
		coeff = -1.Q / (wFE[i] + wFE[i+1]);
		mm = indFEDVR(i, m, Ngs);
		s = coeff*(block(m,n)/wFE[i] + block(0,0)/wFE[i+1]);
		D2.push(s, mm, mm);

		// block left & upper boundary
		coeff = -1.Q / (pow(wFE[i+1], 1.5Q) * sqrt(wFE[i] + wFE[i+1]));
		for (n = 1; n < Ngs - 1; ++n) {
			mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i + 1, n, Ngs);
			s = coeff * block(0, n);
			D2.push(s, mm, nn); D2.push(s, nn, mm);
		}
	}

	for (i = 0; i < Nfe - 2; ++i) {
		// block upper right corner
		coeff = -1.Q / (wFE[i+1] * sqrt((wFE[i] + wFE[i+1])*(wFE[i+1] + wFE[i+2])));
		mm = indFEDVR(i, Ngs-1, Ngs); nn = indFEDVR(i + 1, Ngs-1, Ngs);
		s = coeff * block(0, Ngs - 1);
		D2.push(s, mm, nn); D2.push(s, nn, mm);
	}
	sort_r(D2);
}

// bounds: FE boundaries, size = Nfe + 1
// Ngs: grid points per finite element (including boundaries)
// `x`, `w` are the global grid points and weights
// `u` is the maximum value of each basis
inline void D2_matrix(McooQdoub_O D2, VecQdoub_O x, VecQdoub_O w, VecQdoub_O u, VecQdoub_I bounds, Long_I Ngs)
{
	Long Nfe = bounds.size() - 1; // number of finite elements
#ifdef SLS_CHECK_SHAPES
	Long Nx = Nfe * (Ngs - 1) - 1;
	if (x.size() != Nx || w.size() != Nx || u.size() != Nx ||
		D2.n0() != Nx || D2.n1() != Nx)
		SLS_ERR("wrong shape!");
#endif

	// grid points, weights, base function values in [-1, 1]
	VecQdoub x0(Ngs), w0(Ngs), f0(Ngs);
	GaussLobatto(x0, w0);
	CmatQdoub df(Ngs, Ngs); // df(i, j) = f_j(x_i)
	dvr_basis_der(df, x0, w0);

	// midpoints, widths and bounds of finite elements
	VecQdoub xFE(Nfe), wFE(Nfe);

	for (Long i = 0; i < Nfe; ++i) {
		wFE[i] = 0.5Q*(bounds[i+1] - bounds[i]);
		xFE[i] = 0.5Q*(bounds[i] + bounds[i+1]);
	}

	FEDVR_grid(x, w, wFE, xFE, x0, w0);
	pow(u, w, -0.5Q);

	// Sparse matrix
	D2_matrix(D2, w0, wFE, df);
}

// sparse first derivative matrix for normalized FEDVR basis
inline void D_matrix(McooQdoub_O D, VecQdoub_I w0, VecQdoub_I wFE, CmatQdoub_I df)
{
	Long i, m, n, mm, nn;
	Long Nfe = wFE.size();
	Long Ngs = w0.size();
#ifdef SLS_CHECK_SHAPES
	Long Nx = Nfe * (Ngs - 1) - 1;
	if (D.n0() != Nx || D.n1() != Nx)
		SLS_ERR("wrong shape!");
#endif

	Qdoub s, coeff;

	// calculate D matrix
	D.resize(0);
	D.reserve(fedvr_d2_nnz(Ngs, Nfe)); // # non-zero elements

	// blocks without boundary
	for (i = 0; i < Nfe; ++i) {
		for (n = 1; n < Ngs - 1; ++n) {
			coeff = 1.Q / wFE[i];
			for (m = 1; m <= n; ++m) {
				s = coeff * sqrt(w0[m]) * df(m,n);
				mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i, n, Ngs);
				D.push(s, mm, nn);
				if (mm != nn)
					D.push(-s, nn, mm);
			}
		}
	}

	for (i = 0; i < Nfe - 1; ++i) {
		// block right & bottom boundary
		n = Ngs - 1;
		coeff = 1.Q / sqrt(wFE[i]*(wFE[i] + wFE[i + 1]));
		for (m = 1; m < n; ++m) {
			s = coeff * sqrt(w0[m]) *  df(m, n);
			mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i, n, Ngs);
			D.push(s, mm, nn); D.push(-s, nn, mm);
		}

		// block lower right corner are all 0

		// block left & upper boundary
		m = Ngs - 1;
		coeff = sqrt(w0[0] / (wFE[i+1]*(wFE[i] + wFE[i+1])));
		for (n = 1; n < Ngs - 1; ++n) {
			s = coeff * df(0, n);
			mm = indFEDVR(i, m, Ngs); nn = indFEDVR(i + 1, n, Ngs);
			D.push(s, mm, nn); D.push(-s, nn, mm);
		}
	}

	for (i = 0; i < Nfe - 2; ++i) {
		// block upper right corner
		coeff = sqrt(w0[0] / ((wFE[i] + wFE[i+1])*(wFE[i+1] + wFE[i+2])));
		s = coeff * df(0, Ngs - 1);
		mm = indFEDVR(i, Ngs-1, Ngs); nn = indFEDVR(i + 1, Ngs-1, Ngs);
		D.push(s, mm, nn); D.push(-s, nn, mm);
	}
	sort_r(D);
}

inline void D_matrix(McooQdoub_O D, VecQdoub_O x, VecQdoub_O w, VecQdoub_O u, VecQdoub_I bounds, Long_I Ngs)
{
	Long Nfe = bounds.size() - 1; // number of finite elements
#ifdef SLS_CHECK_SHAPES
	Long Nx = Nfe * (Ngs - 1) - 1;
	if (x.size() != Nx || w.size() != Nx || u.size() != Nx)
		SLS_ERR("wrong shape!");
#endif

	// grid points, weights, base function values in [-1, 1]
	VecQdoub x0(Ngs), w0(Ngs), f0(Ngs);
	GaussLobatto(x0, w0);
	CmatQdoub df(Ngs, Ngs); // df(i, j) = f'_j(x_i)
	dvr_basis_der(df, x0, w0);

	// midpoints, widths and bounds of finite elements
	VecQdoub xFE(Nfe), wFE(Nfe);

	for (Long i = 0; i < Nfe; ++i) {
		wFE[i] = 0.5Q*(bounds[i+1] - bounds[i]);
		xFE[i] = 0.5Q*(bounds[i] + bounds[i+1]);
	}

	FEDVR_grid(x, w, wFE, xFE, x0, w0);
	pow(u, w, -0.5Q);

	// Sparse matrix
	D_matrix(D, w0, wFE, df);
}


} // namespace slisc
