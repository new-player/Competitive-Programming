#include <cstdio>
#include <algorithm>

using namespace std;
#define INF 999999999

// Same question in 2-D array
// http://stackoverflow.com/questions/6849569/dynamic-programming-spoj-problem-scubadiv


int dp[1010][22][80];

int main(){
int tc,t,a,n,oxygen,nitrogen,i,j,k,wt;
scanf("%d",&tc);
while(tc--){
scanf("%d %d",&t,&a);
scanf("%d",&n);

//printf("***%d\n",INF);

for(i=1;i<1010;i++){
    dp[i][0][0] = 0;
}
for(i=0;i<22;i++)
    for(j=0;j<80;j++)
        dp[0][i][j] = INF;



dp[0][0][0] = 0;

for(i=1;i<=n;i++){
scanf("%d %d %d",&oxygen,&nitrogen,&wt);

for(j=0;j<=t;j++){
for(k=0;k<=a;k++){

// Similar to Knapsack problem
dp[i][j][k] = min(dp[i-1][j][k],dp[i-1][max(j-oxygen,0)][max(k-nitrogen,0)] + wt);

}

}

}

printf("%d\n",dp[n][t][a]);

}
return 0;
}
