#include <cstdio>

using namespace std;

// https://www.quora.com/How-and-when-do-I-use-getchar_unlocked-in-C
// https://github.com/t3nsor/SPOJ/blob/master/nhay-2.cpp

int main(){
    int tc,n,k,i;
    char c;
    static char needle[1000000];
    static int pi[1000000];

    while(scanf("%d", &n) != EOF){
        //char pat[n];
        scanf("%s", &needle);

        pi[1]=0;
        k=0;
        for (i=2; i<=n; i++)
        {
            while (k>0&&needle[k]!=needle[i-1])
                k=pi[k];
            if (needle[k]==needle[i-1])
                k++;
            pi[i]=k;
        }
        k=0;
        i=0;
        while((c=getchar_unlocked())!='\n');

        while ((c=getchar_unlocked())!='\n')
        {
            i++;
            while (k>0&&needle[k]!=c)
                k=pi[k];
            if (needle[k]==c)
                k++;
            if (k==n)
            {
                printf("%d\n",i-n);
                k=pi[k];
            }
        }
        putchar('\n');

    }
return 0;
}


