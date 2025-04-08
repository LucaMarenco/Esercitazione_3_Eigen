#include <iostream>
#include "Eigen/Eigen"
#include <iomanip>

using namespace std;
using namespace Eigen;


Vector2d PALU(Matrix2d A,Vector2d b) { 
	double d = A.determinant();
	Vector2d x;
	if(abs(d) < 1.0e-12){ 
		x = A.fullPivLu().solve(b);
	}
    else {
		x = A.partialPivLu().solve(b);
	}
    return x ; 
}

double ErrRel(Vector2d x_sol , Vector2d x) {
	double norm_sol = x_sol.norm();
	double err = ((x_sol - x).norm()) / norm_sol;
	return err;
}

Vector2d QR(Matrix2d A,Vector2d b) {
	Vector2d x = A.householderQr().solve(b);
	return x;
}

int main()
{
	Vector2d  x_sol;
	x_sol << -1.0e+0, -1.0e+00;
	
	Matrix2d A1 ;
	A1 <<5.547001962252291e-01,-3.770900990025203e-02, 8.320502943378437e-01,-9.992887623566787e-01;
	Vector2d b1 ;
	b1 << -5.169911863249772e-01, 1.672384680188350e-01;
	
	Matrix2d A2 ;
	A2 << 5.547001962252291e-01,-5.540607316466765e-01, 8.320502943378437e-01,-8.324762492991313e-01;
	Vector2d b2 ;
	b2 << -6.394645785530173e-04, 4.259549612877223e-04;
	
	Matrix2d A3 ;
	A3 << 5.547001962252291e-01,-5.547001955851905e-01, 8.320502943378437e-01,-8.320502947645361e-01;
	Vector2d b3 ;
	b3 << -6.400391328043042e-10, 4.266924591433963e-10;
	
	cout << "RISOLUZIONE CON FATTORIZZAZIONE PALU" << endl;
	Vector2d x1 = PALU(A1,b1);
	cout << "La soluzione con fattorizzazione PALU del primo problema è:\n" << scientific << setprecision(2)  << x1 << endl;
    cout << "Il suo errore relativo è:\n" << scientific << setprecision(16) << ErrRel(x_sol,x1) << endl;
	cout << endl;
	
	Vector2d x2 = PALU(A2,b2);
	cout << "La soluzione con fattorizzazione PALU del secondo problema è:\n" << scientific  << setprecision(2) << x2 << endl; 
	cout << "Il suo errore relativo è:\n" << scientific << setprecision(16) << ErrRel(x_sol,x2) << endl;
	cout << endl;
	
	Vector2d x3 = PALU(A3,b3);
	cout << "La soluzione con fattorizzazione PALU del terzo problema è:\n" << scientific << setprecision(2) << x3 << endl;
	cout << "Il suo errore relativo è:\n" << scientific << setprecision(16) << ErrRel(x_sol,x3) << endl;
	
	cout << "\n" << "RISOLUZIONE CON FATTORIZZAZIONE QR" << endl;
	Vector2d x1Qr = QR(A1,b1);
	cout << "La soluzione con fattorizzazione QR del primo problema è:\n" << scientific << setprecision(2) << x1Qr << endl;
	cout << "Il suo errore relativo è:\n" << scientific << setprecision(16) << ErrRel(x_sol,x1Qr) << endl;
	cout << endl;
	
	Vector2d x2Qr = QR(A2,b2);
	cout << "La soluzione con fattorizzazione QR del secondo problema è:\n" << scientific << setprecision(2) << x2Qr << endl;
	cout << "Il suo errore relativo è:\n" << scientific << setprecision(16) << ErrRel(x_sol,x2Qr) << endl;
	cout << endl;
	
	Vector2d x3Qr = QR(A3,b3);
	cout << "La soluzione con fattorizzazione QR del terzo problema è:\n" << scientific << setprecision(2) << x3Qr << endl;
	cout << "Il suo errore relativo è:\n" << scientific << setprecision(16) << ErrRel(x_sol,x3Qr) << endl;
	
	return 0;
}



