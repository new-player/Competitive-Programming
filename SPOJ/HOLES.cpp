#include <iostream>
#include <cstring>

using namespace std;


        int main()
{
int n;
cin >> n;
char str[100];

for(int i=0; i<n; i++)
{
    cin >> str;
    int holes=0;
    int len = strlen(str);
    for(int j=0; j<len; j++)
    {
        if(str[j]=='A'||str[j]=='D'||str[j]=='O'||str[j]=='P'||str[j]=='Q'||str[j]=='R')
        {
            holes++;
        }
        else if(str[j]=='B')
        {
            holes++;
            holes++;
        }


    }

    cout << holes << endl;
}


return 0;
}
