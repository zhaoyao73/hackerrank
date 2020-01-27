#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* erase single or range from a vector
 * the input is second or third
 * need to convert -1
 * range: [from, to) doesn't include to
 */
int main() {
    vector<int> v;
    int m;
    int n;

    cin >> n;
    for(int i=0; i < n; i++) {
        cin >> m;
        v.push_back(m);
    }

    cin >> n;
    v.erase(v.begin() + n-1);

    cin >> n >> m;
    v.erase(v.begin() + n-1, v.begin() + m-1);

    cout << v.size() << endl;
    for (auto i: v) {
        cout << i << " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

