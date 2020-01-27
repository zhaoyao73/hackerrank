#include <cinttypes>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#pragma GCC optimize(3)
#if 0
inline unsigned int *
get_off(unsigned int *pbsets, unsigned long bits, unsigned long*off, unsigned long*bit) {

    *bit = bits % 32;
    *off = bits>>5;
//  with return 1 it comes down to 1 seconds
//    return 1;
//  with memory access, it goes to 6 seconds
    return &pbsets[*off];
}
inline void
set(unsigned int *pbsets, unsigned long bit) {
    *pbsets |= (1U << bit);
}
void
clear(unsigned int *pbsets, unsigned long bit) {
    *pbsets -= (1U << bit);
}
inline int
test(unsigned int *v, unsigned long bit) {
    return (*v & (1U << bit)) != 0;
}
#else

#define get_off(bits, off, bit) \
do { \
    bit = bits % bits_long;     \
    off = bits>> bits_shift;    \
} while(0)

#define set(pbsets, off, bit)     \
do { \
    *(pbsets+off) |= (1UL << bit); \
} while(0)

#define test(pbsets, off, bit) \
    ((*(pbsets+off) & (1UL << bit)) != 0)

#define get_ai(cur, prev) \
        cur = (prev *P+Q); \
        if (/*cur >= pow231*/1)  { \
            cur = cur % pow231; \
	    /*cur = cur & (pow231 -1);*/ \
	} \
	prev = cur;

#endif
#define bits_long  64UL
#define bits_shift 6UL
#pragma GCC optimize(3)
int main() {
    unsigned long N, S, P, Q;
    unsigned long long prev, cur;
    constexpr unsigned long pow231 = 1UL<<31;
    unsigned long how_many = 1;
    unsigned long off, bit, i, j;
#define A 64
#define W 2
    unsigned long caches[A][W];

#if bits_long == 32
    cin >> N >> S >> P >> Q;
    unsigned int *pbsets = new unsigned int[pow231/bits_long];
    memset(pbsets, 0 , pow231/bits_long*sizeof(unsigned int));
#else
    scanf("%" PRIu64 "%" PRIu64 "%" PRIu64 "%" PRIu64, &N, &S, &P, &Q);
    unsigned long *pbsets = static_cast<unsigned long*>(malloc(pow231/(bits_long/sizeof(unsigned long))));
    memset(pbsets, 0 , pow231/(bits_long/sizeof(unsigned long)));
#endif

    get_off(S, off, bit);
    set(pbsets, off, bit);

    prev = S;
    for( i = 1; (i+A) <= (N-1); i+=A) {
	for(j = 0; j < A; j++) {
		get_ai(cur, prev);
		get_off(cur, off, bit);
		caches[j][0] = off;
		caches[j][1] = bit;
		__builtin_prefetch(&pbsets[off],
			       	   1/*0:read, 1:rw*/,
				   1/*0:after local access, no need left in cache
				     *1:low local access
				     *2:moderate local access
				     *3:should be left in all levels of cache(default)
				     */); \
	}
	for(j = 0; j < A  ; j++) {
		if (!test(pbsets, caches[j][0], caches[j][1]))
		{
		    set(pbsets, caches[j][0], caches[j][1]);
		    how_many++;
		} else {
			goto out;
		}
	}
    }

    for( j=0; i <= (N-1); i++) {
		get_ai(cur, prev);
		get_off(cur, off, bit);
		caches[j][0] = off;
		caches[j][1] = bit;
		if (!test(pbsets, caches[j][0], caches[j][1]))
		{
		    set(pbsets, caches[j][0], caches[j][1]);
		    how_many++;
		} else {
			goto out;
		}
    }
#if bits_long != 32
out:
    printf("%" PRIu64, how_many);
    //free(pbsets);
#else
out:
    cout << how_many << endl;
    //delete[] (pbsets);
#endif
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


