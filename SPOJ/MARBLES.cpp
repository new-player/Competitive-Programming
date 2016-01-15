#include <cstdio>

using namespace std;
#define llu unsigned long long int

llu nCr(int n, int r){
    if(r>n-r) r=n-r;
    llu ans = 1;
    for(int i=1;i<=r;i++){
        ans *= (n-i+1);
        ans /= i;
    }
    return ans;


}

int main(){
int tc,n,r;
scanf("%d",&tc);
while(tc--){

scanf("%d %d",&n,&r);

printf("%llu\n",nCr(n-1,r-1));


}
return 0;
}
