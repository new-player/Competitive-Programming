#include <iostream>
#include <cstdio>
#define SIZE 65536

using namespace std;
char buf[SIZE];

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
    //cout << sizeof(char) << endl;

    int n,k,temp,cnt,c;
    scanf("%d %d\n",&n,&k);
    temp=0;
//cout <<n<<k<<endl;
    cnt=0;

    while((c=fread(buf, sizeof(char), SIZE, stdin))>0)
    {
        for(int i=0; i<c; i++)
        {
        //cout << buf[i] << endl;
            if(buf[i]=='\n')
            {
                if(temp%k==0)
                {
                    cnt++;
                }
                temp=0;

            }
            else
            {
                temp = temp*10 + (buf[i]-'0');
            }

        }
    }
    printf("%d\n",cnt);

    return 0;
}


