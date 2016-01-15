#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int tc,E,F,N,T,P,W,dp[10001],INF=1<<28;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d %d",&E,&F);
        scanf("%d",&N);

        T = F-E;   // required weight
        fill(&dp[1], &dp[1]+T, INF);
        dp[0] = 0;
        while(N--)
        {
            scanf("%d %d",&P,&W);

            for(int i=0; i+W<=T; i++)
            {
                if((dp[i]!=INF)&&(dp[i+W]>dp[i]+P))
                {
                    dp[i+W]=dp[i]+P;
                }

            }
        }
        if(dp[T]!=INF) printf("The minimum amount of money in the piggy-bank is %d.\n", dp[T]);
        else printf("This is impossible.\n");


    }
    return 0;
}
