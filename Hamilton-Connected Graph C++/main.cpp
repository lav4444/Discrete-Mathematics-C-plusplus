#include <iostream> 
#include "List.h"

using namespace std;

static bool POVEZAN = false;
static bool HAMILTONOVSKI = false;


//prvo imas vrh, pa onda pozoves rek. fciju da ga obradi i dijeli dalje
void recStabalce(int trenutniVrh, bool ubrajati, List<int> pomocniVrhovi, int K[], int duzina, int pocVrh) {

        if (pomocniVrhovi.count() == duzina) {
            POVEZAN = true;
            //cout << "POVEZANN!" << endl;
            if (trenutniVrh == pocVrh && duzina != 2) {
                HAMILTONOVSKI = true;
                // cout << "HAMILTT!" << endl;
                // pomocniVrhovi.PrintList() ;
                // cout << endl;
            }

        }

        // pomocniVrhovi.PrintList() ;
        // cout << endl;
        //uvijet za prekid grananja trenutne grane
        int razina = 0;
        if (pomocniVrhovi.check(trenutniVrh)) {
            return;
        }
        else {
            if (ubrajati == true) {
                pomocniVrhovi.add(trenutniVrh);
            }
            for (int i=0; i<4; i++) {
                if (K[i] != 0) {
                    razina++;
                    if (trenutniVrh - K[i] > 0) {
                        recStabalce(trenutniVrh - K[i], true, pomocniVrhovi, K, duzina, pocVrh);
                    } 
                    if (trenutniVrh + K[i] <= duzina) {
                        recStabalce(trenutniVrh + K[i], true, pomocniVrhovi, K, duzina, pocVrh);
                    }
                }
            }
        }
    
} 


int main() {
    int n;

    cout << "Unesite prirodan broj n: ";
    cin >> n;

    if (n==1) POVEZAN = true;

    int nominalniVrhovi[n];
    List<int> pomocniVrhovi;
    int K[4];

    for (int i=1; i<=4; i++) {
        int x;
        cout << "Unesite vrijednost prirodnog broja k_" << i << ": ";
        cin >> x;
        if (x<n) {
            K[i-1] = x;
        }
        else K[i-1] = 0;
    }
    

    for (int i=1; i<=n; i++) {
        nominalniVrhovi[i-1] = i;
    }

    for (int i=1; i<=n; i++) {
        recStabalce(i, true, pomocniVrhovi, K, n, i);
    }
    cout << "--------------------------------------" << endl;
    cout << "Graf G " << (POVEZAN ? "je" : "nije") << " povezan graf" << endl;
    cout << "Graf G " << (HAMILTONOVSKI ? "je" : "nije") << " hamiltonovski graf" << endl;


    return 0;
}