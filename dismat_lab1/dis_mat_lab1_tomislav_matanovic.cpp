#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x = 0;
    double b[3];
    double c[3]; 

    cout << "Unesite nenegativan cijeli broj: ";
    cin >> x;

    for (int i=0; i < 6; i++) {
        if (i<3) {
            cout << "Unesite vrijednost broja b_"  << i <<": ";
            cin >> b[i];
        } else {
            cout << "Unesite vrijednost broja c_"  << i-3 <<": ";
            cin >> c[i-3];
        }
    }
    //izračun lambda1 i lambda2, 2 jednadžbe s 2 nepoznanice
    double lambda1=0, lambda2=0;
    lambda2 = ( c[1]*b[2] - b[1]*c[2] ) / ( b[0]*c[1] - c[0]*b[1] );
    lambda1 = ( b[2] - lambda2*b[0] ) / ( b[1] );

    cout << "l1: " << lambda1 << endl;
    cout << "l2: " << lambda2 << endl;


    double ak = -1;
    double bk = lambda1; 
    double ck = lambda2; 

    double DISKRIMINANTA = bk*bk - 4*ak*ck;

    if (DISKRIMINANTA > 0) {
        double x1 =  (lambda1-sqrt(pow(lambda1,2)+4*lambda2)) / 2;   
        double x2 = (lambda1+sqrt(pow(lambda1,2)+4*lambda2)) / 2;

        double B = (b[1]-b[0]*x1) / (x2-x1);
        double A = b[0] - B;

        //cout << "Roots are real and different." << endl;
        // cout << "x1 = " << x1 << endl;
        // cout << "x2 = " << x2 << endl;

        //rješenje
        // cout << "a("<< x <<") = " << A << " * " << x1 <<"**n + " << B << " * " << x1 <<"**n" << endl;
        // cout << "a("<< x <<") = " << A * pow(x1, x) + B * pow(x2, x) << endl;


        printf("%s %f\n","Vrijednost broja b_n: ", A * pow(x1, x) + B * pow(x2, x) );

        
    } else if (DISKRIMINANTA == 0) {
        double x1 = (-bk)/(2*ak);

        double A = b[0];
        double B = (b[1]-b[0]*x1) / (x1);

        //cout << "Roots are real and same." << endl;

        //rješenje
        // cout << "a("<< x <<") = " << A << " * " << x1 <<"**n + " << B << " * n * " << x1 <<"**n" << endl;
        // cout << "a("<< x <<") = " << A * pow(x1, x) + B * x * pow(x1, x) << endl;

        //cout << "Vrijednost broja b_n: " << A * pow(x1, x) + B * x * pow(x1, x) << endl;  stari print

        printf("%s %f\n","Vrijednost broja b_n: ",  A * pow(x1, x) + B * x * pow(x1, x) );

        
    } 

    return 0;
}

