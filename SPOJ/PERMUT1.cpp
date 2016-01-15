#include <cstdio>
using namespace std;

int cnt[13][72];
//http://programmerheaven9.blogspot.in/2011/10/spoj-permut1.html
void calc() {
	int i, j, k;
	// Base Case
	cnt[1][0] = 1;
	for(i=2; i<13; i++) {
		for(j=0; j<=(i*(i-1))/2; j++) {
			for(k=0; (k<i)&&(j-k>=0); k++) {
				cnt[i][j] += cnt[i-1][j-k];
			}
		}
	}
}

int main() {
	int t, n, k;
	calc();
	for(scanf("%d", &t); t; t--) {
		scanf("%d%d", &n, &k);
		printf("%d\n", cnt[n][k]);
	}
	return 0;
}
