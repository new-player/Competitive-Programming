#include <cstdio>

#define SIZE 200
using namespace std;

int main(){
int tc,n;
scanf("%d",&tc);
while(tc--){
scanf("%d",&n);

int num[SIZE] = {1};
//printf("%d\n",num[1]);

int counter = 1;
for(int i = 2;i<=n;i++){
int carry=0,temp;
for (int j = 0;j<counter;j++){
temp = num[j]*i + carry;
//printf("%d %d\n",num[j],carry);



if(temp>9){
int rem = temp%10;
carry = temp/10;
num[j] = rem;
}
else{
num[j] = temp;
carry=0;
}



}
//printf("------ %d %d\n",counter,carry);

if(carry>0){

while(carry>0){
counter++;
num[counter-1] = carry%10;
carry = carry/10;
}
}

}

for(int c=counter-1;c>=0;c--){
printf("%d",num[c]);
}
printf("\n");

}
return 0;
}
