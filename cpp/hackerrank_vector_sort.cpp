#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/* first line: how many number
 * second line: all numbers separate by space
 *
 * need to:
 *   1. sort
 *   2. output to one line
 */
int main() {
    int n, m;
    vector<int> v;

    cin >> n;

    while ( n --) {
        cin >> m;
        v.push_back(m);
    }

    sort(v.begin(), v.end());
    for(auto i: v) {
        cout << i << " ";
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

