#include <cstdio>
#include <algorithm>

using namespace std;
int dp[100][501];
// http://stackoverflow.com/questions/4707942/default-values-in-array

int main(){
int budget=0, parties=0, cost, fun, i, j;
while(1){
scanf("%d %d",&budget,&parties);
//int dp[parties][budget];
//int n = parties;
if((budget==0)&&(parties==0)){
break;
}

for(int i=1;i<=parties;i++){
scanf("%d %d",&cost,&fun);
for(int j=0;j<=budget;j++){
    if(cost>j){
        dp[i][j] = dp[i-1][j];
    }
    else{
        dp[i][j] = max(dp[i-1][j-cost] + fun, dp[i-1][j]);
        //printf("-------%d %d %d\n",i,cost,dp[i][cost]);

    }
}

}

int w = budget;
while(dp[parties][budget]==dp[parties][--w]);

printf("%d %d\n",w+1,dp[parties][budget]);
}

return 0;
}
