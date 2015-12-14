#include <cstdio>
#include <algorithm>

using namespace std;


// Extended Euclidean_algorithm
// https://github.com/arpitbbhayani/spoj/blob/master/POUR1.c
// http://e-maxx.ru/algo/extended_euclid_algorithm#2
//https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm

int ext_gcd (int a, int b, int *x , int *y) {
	if (a == 0) {
		*x = 0; *y = 1;
		return b;
	}
	int x1, y1;
	int d = ext_gcd (b%a, a, &x1, &y1);
	*x = y1 - (b/a) * x1;
	*y = x1;
	return d;
}


int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

// Euclidean_algorithm
int gcd2 ( int a , int b ) {
	if ( b == 0 )
		return a;
	return gcd( b , a % b );
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
        else
        {
            // a should be greater than b.
            if ( a < b ) {
                a ^= b;
                b ^= a;
                a ^= b;
            }
            int s=0,t=0;
            int gcd = ext_gcd(a,b,&s,&t);
            if(c%gcd!=0){
                printf("%d\n",-1);
                continue;
            }

            printf("%d %d\n",s,t);
            s = (s<0)? -s:s;
            t = (t<0)? -t:t;

            printf("%d\n",s+t);




            //printf("%d\n", min(steps(a, b, c), steps(b, a, c)));
        }


    }
    return 0;
}



