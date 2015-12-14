#include <cstdio>
#include <algorithm>    // std::min
using namespace std;
#define LL long long


int main(){
int tc;
scanf("%d", &tc);
while(tc--){
LL n1,n2,m;

scanf("%lld %lld %lld",&n1,&n2,&m);
LL val = min(n1,min(n2,m*(m+1)/2));
printf("%lld\n", n1-val+n2-val);


}
return 0;
}
