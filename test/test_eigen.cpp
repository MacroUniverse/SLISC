#ifdef SLS_USE_EIGEN
#include "../SLISC/Eigen.h"

using namespace slisc;
using Eigen::MatrixXd; using Eigen::MatrixXcd;
using Eigen::MatrixXq; using Eigen::VectorXq;
#endif

void test_eigen()
{
#ifdef SLS_USE_EIGEN
	// get diagonal
	{
		int n = 5;
		MatrixXd M(n,n);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			    M(i,j) = i + j + 1;
		// cout << "M.diagonal() = " << M.diagonal() << endl;
		// cout << "M.diagonal<1>() = " << M.diagonal<1>() << endl;
	}

	// real QR solver
	{
		Eigen::HouseholderQR<MatrixXd> qr;
		Eigen::VectorXd x(2);
		Eigen::VectorXd y(2); y << 5., 11.;
		MatrixXd A(2, 2); A << 1., 2., 3., 4.;

		// cout << "A = " << endl;
		// cout << A << endl;
		// cout << "y = " << endl;
		// cout << y << endl;
		qr.compute(A);
		x = qr.solve(y);
		// cout << "x = " << endl;
		// cout << x << endl;
	}

	// complex QR solver
	{
		Eigen::HouseholderQR<MatrixXcd> qr;
		Eigen::VectorXcd x(2);
		Eigen::VectorXcd y(2); y << 5., 11.;
		MatrixXcd A(2, 2); A << 1., 2., 3., 4.;

		// cout << "A = " << endl;
		// cout << A << endl;
		// cout << "y = " << endl;
		// cout << y << endl;
		qr.compute(A);
		x = qr.solve(y);
		// cout << "x = " << endl;
		// cout << x << endl;
	}

	// test sparse linear solver
	{
		using namespace std;
		typedef Eigen::Triplet<double> T;
		Eigen::SparseMatrix<double> mat(3, 3);
		vector<T> tripletList;
		tripletList.push_back(T(0, 0, 1.));
		tripletList.push_back(T(0, 2, 2.));
		tripletList.push_back(T(1, 1, 3.));
		tripletList.push_back(T(1, 2, 4.));
		tripletList.push_back(T(2, 0, 5.));
		tripletList.push_back(T(2, 2, 7.));
		Eigen::VectorXd b(3); b[0] = 6.; b[1] = 7.; b[2] = 8.;
		mat.setFromTriplets(tripletList.begin(), tripletList.end());
		// Eigen::SparseLU<Eigen::SparseMatrix<double>> chol(mat);
		// Eigen::SparseCholesky<Eigen::SparseMatrix<double>> chol(mat); // symmetric matrix only!
		// Eigen::ConjugateGradient<Eigen::SparseMatrix<double>> chol(mat); // symmetric matrix only!
		Eigen::BiCGSTAB<Eigen::SparseMatrix<double>> chol(mat); // bi conjugate gradient method
		Eigen::VectorXd x = chol.solve(b);
		// cout << "mat = " << mat << endl;
		// cout << "b = " << b << endl;
		// cout << "x = " << x << endl;
	}

	// self-adjoint eigen solver
	{
		int n = 5;
		MatrixXd M(n,n);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			    M(i,j) = i + j + 1;
		Eigen::SelfAdjointEigenSolver<MatrixXd> eig;
		eig.compute(M);
		// cout << "M = " << endl;
		// cout << M << endl;
		// cout << "eig.eigenvalues() = " << endl;
		// cout << eig.eigenvalues().transpose() << endl;
		// cout << "eig.eigenvectors() = " << endl;
		// cout << eig.eigenvectors() << "\n\n\n" << endl;
	}

	// solve tridiagonal eigen solver
	{
		Eigen::VectorXd d0(5); d0 << 1,3,5,7,9;
		Eigen::VectorXd d1(4); d1 << 2,4,6,8;
		
		Eigen::SelfAdjointEigenSolver<MatrixXd> eig;
		eig.computeFromTridiagonal(d0, d1);
		// cout << "eig.eigenvalues() = " << endl;
		// cout << eig.eigenvalues().transpose() << endl;
		// cout << "eig.eigenvectors() = " << endl;
		// cout << eig.eigenvectors() << endl;
	}

	// test MatrixXq
	{
		int n = 5;
		MatrixXq M(n,n);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			    M(i,j) = i + j + M_PIq;
		// cout.precision(34);
		// cout << "M.diagonal() = " << M.diagonal()[0] << endl;
		// cout << "M.diagonal<1>() = " << M.diagonal<1>()[0] << endl;
		// cout << "\n\n\n\n\n" << endl;
	}

	// real QR solver for Qdoub
	{
		Eigen::HouseholderQR<MatrixXq> qr;
		Eigen::VectorXq x(2);
		Eigen::VectorXq y(2); y << 5., 11.;
		MatrixXq A(2, 2); A << 1.Q, sqrt(2.Q), sqrt(3.Q), 4.;
		// cout.precision(34);
		// cout << "A = " << endl;
		// cout << A << endl;
		// cout << "y = " << endl;
		// cout << y << endl;
		qr.compute(A);
		x = qr.solve(y);
		// cout << "x = " << endl;
		// cout << x << endl;
		// cout << "\n\n\n" << endl;
	}

	// solve tridiagonal eigen solver for Qdoub
	{
		Eigen::VectorXq d0(5); d0 << 1,3,5,7,9;
		Eigen::VectorXq d1(4); d1 << 2,4,6,8;
		
		Eigen::SelfAdjointEigenSolver<MatrixXq> eig;
		eig.computeFromTridiagonal(d0, d1);
		// cout << "eig.eigenvalues() = " << endl;
		// cout << eig.eigenvalues().transpose() << endl;
		// cout << "eig.eigenvectors() = " << endl;
		// cout << eig.eigenvectors() << endl;
	}
#elif
	cout << "disabled!" << endl;
#endif
}
