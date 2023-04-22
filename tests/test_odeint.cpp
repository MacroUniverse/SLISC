#include "../SLISC/sci/odeint.h"
#include "../SLISC/arith/reorder.h"
using namespace slisc;

// a functor for derivative
struct Dfun
{
	// return dyydt[i] as t derivative of yy[i]
    void operator() (Doub_I t, VecDoub_I yy, VecDoub_O dyydt) {
        dyydt[0] = yy[1];
        dyydt[1] = -yy[0];
    }
};

int main() {
	// SHO
    int nvar = 2;
    VecDoub ystartt(nvar); ystartt[0] = 1; ystartt[1] = 0;
    Doub xx1 = 0, xx2 = 10, atol = 1e-14, rtol = 1e-14, h1 = 0.1, hminn = 0;
    int nsave = 500;
    Output outt(nsave);
    Dfun dfun;

    Odeint<StepperDopr853<Dfun>> ode(ystartt, xx1, xx2, atol, rtol, h1,
        hminn, outt, dfun);
    ode.integrate();
    remove("ode_x.txt"); remove("ode_y.txt");
    ofstream fout("ode_x.txt");
    resize_cpy(outt.xsave, nsave+1);
    resize_cpy(outt.ysave, nvar, nsave+1);

	// write to file "ode_x.txt" and "ode_y.txt"
	// Matlab plot code:
	// x = dlmread('ode_x.txt');
	// y = dlmread('ode_y.txt');
	// figure; plot(x, y(:,1)); hold on; plot(x, y(:,2));
	
    for (Long i = 0; i < outt.xsave.size(); ++i)
        fout << outt.xsave[i] << endl;
    fout.close();
    fout.open("ode_y.txt");
    for (Long i = 0; i < outt.ysave.n1(); ++i) {
		for (Long j = 0; j < outt.ysave.n0(); ++j) {
        	fout << outt.ysave(j, i) << "  ";
		}
		fout << endl;
	}
}
