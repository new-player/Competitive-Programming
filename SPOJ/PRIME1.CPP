#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define SIZE 31623   //Square root of 1000000000 is 31622

int main()
{
    int n,n1,n2;
    scanf("%d",&n);
    //printf("%d\n", n);
    for(int k=0; k<n; k++)
    {
        scanf("%d %d",&n1,&n2);

        bool isPrime[SIZE];

        for(int i = 0;i<SIZE;i++){
        isPrime[i] = true;
        }

        //bool num123[100000];

        int DIFF = n2-n1;
        bool num[DIFF+1];

        for(int i = 0;i<=DIFF;i++){
            num[i] = true;
        }

        //printf("Hi\n");

        // Sieve of Eratosthenes goes here
        isPrime[0] = false;
        isPrime[1] = true;

        if (n1==1){
            num[0] = false;
        }

        //printf("Hi\n");

        for(int i = 2; i<=SIZE;i++){
        //printf("%d\n",423132);

        if(isPrime[i-1]){
            for(int j=i*i;j<=SIZE;j=j+i){
            //printf("%d\n",j);
            isPrime[j-1] = false;


            }

            int rem = n1%i;
            //printf("%d\n",rem);
            if(rem==n1){  // n1<i
                for(int l = i-n1;l<=DIFF;l=l+i){
                num[l] = false;
                //printf("%d\n",rem);
            }
            }
            else if(rem == 0){  // n1 is a multiple of i
            for(int l = 0;l<=DIFF;l=l+i){
                num[l] = false;
                //printf("%d\n",rem);
            }
            }
            else{
            for(int l = i-rem;l<=DIFF;l=l+i){
                num[l] = false;
                //printf("%d\n",rem);
            }
            }
        if(i>=n1&&i<=n2){
            num[i-n1]=true;
        }

        }
        //printf("Hi\n");

}

    for(int i = 0;i<=DIFF;i++){
        if(num[i]){
        printf("%d\n",i+n1);
        }
        }

printf("\n");


    }


    return 0;
}

