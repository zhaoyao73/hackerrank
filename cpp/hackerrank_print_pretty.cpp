/*cout << hex << left << showbase << nouppercase; // formatting
cout << (long long) A << endl; // actual printed part

// LINE 2
cout << dec << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2); // formatting
cout << B << endl; // actual printed part

// LINE 3
cout << scientific << uppercase << noshowpos << setprecision(9); // formatting
cout << C << endl; // actual printed part
*/
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        cout << left << showbase << nouppercase << hex << (long long)A << endl;
        cout.width(15);
        cout.precision(2);
        cout.fill('_');
        cout << dec << right << fixed << showpos << B << endl;
        cout.precision(9);
        cout << uppercase << noshowpos << scientific << C << endl;
        /* Enter your code here */

    }
    return 0;

}
