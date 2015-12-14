#include <cstdio>
#include <algorithm>    // std::min
using namespace std;
#define LL long long


int main(){
int tc;
scanf("%d", &tc);
while(tc--){
int A,B,C,N;
int tempA, tempB, tempC;
int ans = 0,det;

scanf("%d",&N);
//printf("%d",1/0==1/0);

while(N--){
scanf("%d %d %d",&A,&B,&C);
if (ans==0){
//printf("%s","#######");
tempA = A;
tempB = B;
tempC = C;
ans=1;
}
else{
// if both A's are zeros
det = A*tempB -tempA*B;
if ((det == 0)&&(tempC != C)){
ans++;
}
else{
ans=0;
}

}
}
printf("%d",ans);

}
return 0;
}

