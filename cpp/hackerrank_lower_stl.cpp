#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    vector<int> v;
    cin >> n;
    /* input */
    for(int i = 0; i < n; i++) {
        cin >> m;
        v.push_back(m);
    }

    cin>>n;
    cout << "debug number of tests:" << n;
    for(int i = 0; i < n; i++) {
        
        cin >> m;
        cout << "debug m:" << m << endl;
        auto b = lower_bound(v.begin(), v.end(), m);
        if (b != v.end()) {
            if (*b == m)
                cout << "Yes" << " " << b - v.begin() + 1 << endl;
            else
                cout << "No" << " " << b - v.begin() + 1 << endl;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

