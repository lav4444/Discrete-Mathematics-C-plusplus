#include <iostream>
#include "math.h"

using namespace std;

static bool POVEZAN = false;
static int n = 0;

void grafPovezan(int *A, int pocVrh, int trenVrh,  int pomocniVrhovi[], int n) {

    int suma=0;
    for (int i=0; i<n; i++) {
        if ( pomocniVrhovi[i] != -1 ) {
            suma++;
        }
    } 
    //cout << "suma: " << suma << endl;   ///////
    //uvijet za prekid
    if (suma == n ) {
        POVEZAN = true;
        return;
    } 

    for (int i=0; i<n; i++) {
        if ( pomocniVrhovi[i] == trenVrh ) {
            return;
        }
    }
    pomocniVrhovi[trenVrh] = trenVrh;
    // cout << "trenutni: " << trenVrh+1 << endl;
    // cout << "- - - - -- - - " << endl;
    for (int j=0; j<n; j++) {
        //cout << *(A + (trenVrh*n + j)) << " ";
    }
    for (int j=0; j<n; j++) {
        if (*(A + (trenVrh*n + j)) != 0) {
            //cout << j+1 << " ";
            grafPovezan((int*)A, pocVrh, j, pomocniVrhovi, n);
        }
    }
}
bool check(int M[], int elem, int size) {
    bool nalaziSe = false;
    for (int i=0; i<size; i++) {
        if (M[i] == elem) {
            nalaziSe = true;
            break;
        }
    }
    return nalaziSe;
}



int main() {
    int n, a, b, c, brojBridova = 0;

    cout << "Unesite prirodan broj n: ";
    cin >> n;
    cout << "Unesite prirodan broj a: ";
    cin >> a;
    cout << "Unesite prirodan broj b: ";
    cin >> b;
    cout << "Unesite prirodan broj c: ";
    cin >> c;
    cout << endl;

    int MATRICA_SUSJEDSTVA[n][n];

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            MATRICA_SUSJEDSTVA[i][j] = 0;
        }
    }

    //kreiranje matrice susjedstva
    for (int i=1; i < n+1; i++) {
        for (int j=i+1; j < n+1; j++) {
            if ( floor(abs(i*a - j*b)/c ) != 0 ) {
                MATRICA_SUSJEDSTVA[i-1][j-1] = floor(abs(i*a - j*b)/c );
                MATRICA_SUSJEDSTVA[j-1][i-1] = floor(abs(i*a - j*b)/c );
                brojBridova++;
            }
        }
    }
    // ispis matrice
    // for (int i=0; i < n; i++) {
    //     for (int j=0; j < n; j++) {
    //         cout << MATRICA_SUSJEDSTVA[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;

    //je li povezan
    for (int i=0; i<1; i++) {

        int pomocniVrhovi[n];
        for (int j=0; j<n; j++) {
            pomocniVrhovi[j] = -1;
        }

        int MATRICA_kopija[n][n];
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                MATRICA_kopija[j][k] = MATRICA_SUSJEDSTVA[j][k];
            }
        }
        grafPovezan( (int*)MATRICA_kopija, i, i, pomocniVrhovi, n);
    }

    if (POVEZAN) {
        cout << "Graf G je povezan graf" << endl;
    } else {
        cout << "Graf G nije povezan graf" << endl;
        return 4;
    }

    //svođenje na minimalno razapinjujuce stablo       !!!!!!treba popraviti  primov algoritam
    int MatricaMinRazStablo[n][n];
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            MatricaMinRazStablo[i][j] = 0;
        }
    }
    int VisitedVrhovi[n];
    for (int i=0; i<n; i++) {
        VisitedVrhovi[i] = -1;
    }
    VisitedVrhovi[0] = 0;
    brojBridova = 0;

    while(true) {
        int suma = 0;
        for (int i=0; i<n; i++) {
            if(VisitedVrhovi[i] != -1){
                suma++;
            }
        }
        if (suma == n) break;
        int minBrid = 10000, min_i = -1, min_j = -1;
        for (int i=0; i<n; i++) {
            if (VisitedVrhovi[i] != -1) {
                for (int j=0; j<n; j++) {
                    if (MATRICA_SUSJEDSTVA[i][j] != 0) {
                        if (!check(VisitedVrhovi, j, n)) {
                            if (MATRICA_SUSJEDSTVA[i][j] < minBrid) {
                                minBrid = MATRICA_SUSJEDSTVA[i][j];
                                min_i = i;
                                min_j = j;
                            }
                        }
                    }
                }
            }
        }
        MatricaMinRazStablo[min_i][min_j] = MATRICA_SUSJEDSTVA[min_i][min_j];
        MatricaMinRazStablo[min_j][min_i] = MATRICA_SUSJEDSTVA[min_j][min_i];
        brojBridova++;
        VisitedVrhovi[min_j] = min_j;
    }
    
    // // ispis matrice
    // for (int i=0; i < n; i++) {
    //     for (int j=0; j < n; j++) {
    //         cout << MatricaMinRazStablo[i][j] << "  ";
    //     }
    //     cout << endl;
    // }
    // cout << endl << endl;
    // cout << "brojBridova: " << brojBridova << endl << endl;

    //pruferov kod
    cout << "Pruferov kod minimalnog razapinjuceg stabla: (";
    bool prvi = true;
    while (true) {
        int minIncidencija = 1000000;
        int min_i = -1;
        int min_j = -1;
        int uPrufera = -1;

        for (int i=0; i < n; i++) {
            int brojIncidencija = 0;
            for (int j=0; j < n; j++) {
                if (MatricaMinRazStablo[i][j] != 0) {
                    brojIncidencija++;
                }
            }
            if (brojIncidencija == 1) {
                for (int j=0; j < n; j++) {
                    if (MatricaMinRazStablo[i][j] != 0) {
                        if (MatricaMinRazStablo[i][j] < minIncidencija) {
                            minIncidencija = MatricaMinRazStablo[i][j];
                            min_i = i;
                            min_j = j;
                            uPrufera = j+1;
                        }
                    }
                }
            }
        }
        if (brojBridova == 1) {
            break;
        } else {
            MatricaMinRazStablo[min_i][min_j] = 0;
            MatricaMinRazStablo[min_j][min_i] = 0;
            brojBridova--;
            if (!prvi) {
                cout << ",";
            }
            prvi = false;
            cout << uPrufera;
        }
    }
    cout << ")" << endl << endl;


    return 4;
}


