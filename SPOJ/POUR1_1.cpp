#include <cstdio>
#include <algorithm>

using namespace std;

// Supercool swapper using xor
// https://github.com/cacophonix/SPOJ/blob/master/POUR1.cpp
// http://betterexplained.com/articles/swap-two-variables-using-xor/
// http://www.geeksforgeeks.org/swap-two-numbers-without-using-temporary-variable/
// https://en.wikipedia.org/wiki/B%C3%A9zout%27s_identity
// https://en.wikipedia.org/wiki/Diophantine_equation
// https://discuss.codechef.com/questions/22862/algorithm-of-pouring-water
// http://www.iaeng.org/publication/WCE2013/WCE2013_pp145-147.pdf


int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int steps(int a, int b, int c)
{
    int temp_a=0,temp_b=0;
    int steps = 0;
    while((temp_a!=c)&&(temp_b!=c))
    {

        if(temp_a==0)
        {
            temp_a = a;
            steps++;
        }
        else if(temp_b == b)
        {
            temp_b = 0;
            steps++;

        }
        else
        {
            int min_val = min(b-temp_b,temp_a);
            temp_b = temp_b + min_val;
            temp_a = temp_a - min_val;
            steps++;
        }
    //printf("------%d %d %d\n",temp_a,temp_b,c);
    }
    return steps;

}


int main()
{

    int tc;
    scanf("%d",&tc);
    while(tc--)
    {

        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        //printf("---%d %d %d-----",a,b,c);

        if ((c>a)&&(c>b))
        {
            printf("%d\n",-1);
        }
        else if(c % gcd(a,b))
        {
            printf("%d\n",-1);
        }
        else
        {
            printf("%d\n", min(steps(a, b, c), steps(b, a, c)));
        }


    }
    return 0;
}


