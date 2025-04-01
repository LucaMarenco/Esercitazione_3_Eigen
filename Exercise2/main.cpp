#include <iostream>
#include "Eigen/Dense"

using namespace std;
using namespace Eigen;

Vector2d PALU(Matrix2d A,Vector2d b) { 
	double d = A.determinant();
	
		Vector2d x = A.lu().solve(b);// faccio PartialPivLU
    return x ; 
}

int main()
{
	Matrix2d A = [5.547001962252291e-01,-3.770900990025203e-02; 8.320502943378437e-01,-9.992887623566787e-01];
	Vector2d b = [-5.169911863249772e-01; 1.672384680188350e-01];
	cout << A << endl;
	cout << b << endl;
	Vector2d x = PALU(A,b);
	cout << x << endl;

	return 0;
}



// if(abs(d) < 1.0e-12)
		// x = fullPivLU
//	else