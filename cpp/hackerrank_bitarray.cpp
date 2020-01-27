#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <unordered_set>
#include <cstring>
using namespace std;

unsigned long
get_off(unsigned long *pbsets, int bits, int *off, int *bit) {

    *bit = bits % 64;
    *off = bits>>6;

    return pbsets[*off];
}
inline void
set(unsigned long *pbsets, int bit) {
    *pbsets |= (1UL << bit);
}
void
clear(unsigned long *pbsets, int bit) {
    *pbsets -= (1UL << bit);
}
inline int
test(unsigned long v, int bit) {
    return (v & (1UL << bit)) != 0;
}
int main() {
    unsigned int N, S, P, Q;
    //unordered_set<unsigned long long> sets;
    unsigned long long prev, cur;
    constexpr unsigned long pow231 = 1U<<31;
    unsigned long how_many = 1;
    unsigned long v;
    int off, bit;
    unsigned long *pbsets = (unsigned long*)malloc(pow231/8);
    if (!pbsets) {
        exit(1);
    }
    memset(pbsets, 0 , pow231/8);
    cin >> N >> S >> P >> Q;

    get_off(pbsets, S, &off, &bit);
    set(pbsets+off, bit);

    prev = S;
    for( unsigned int i = 1; i <= N-1; ++i) {
        cur = (prev *P+Q);
        cur = cur % pow231;
        v = get_off(pbsets, cur, &off, &bit);
        if (!test(v, bit)) {
            how_many++;
            set(pbsets+ off, bit);
        }
        prev = cur;
    }

    cout << how_many << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


