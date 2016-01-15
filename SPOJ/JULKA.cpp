#include <cstdio>
#include <string.h>
#include <algorithm>    // std::fill

using namespace std;
#define LIMIT 101

int main(){
int tc=10,len1,len2,temp1,temp2,dig1,dig2,sum_dig,i,j,k,carry;
char s[LIMIT],d[LIMIT],temp[LIMIT],n1[LIMIT],n2[LIMIT];
while(tc--){

//fill(s, s+ LIMIT, '\0');
//fill(d, d + LIMIT, '\0');
scanf("%s/n",&s);  // sum
scanf("%s/n",&d);  // difference

int len1 = strlen(s);
int len2 = strlen(d);


// sum + difference
for(i=len1-1,j=len2-1, k=0,carry=0;i>=0||j>=0;i--,j--,k++){
dig1 = i>=0? s[i]-'0':0;
dig2 = j>=0? d[j]-'0':0;
sum_dig = (dig1+dig2+carry);
//printf("i,j,sum_dig = %d,%d,%d\n",i,j,sum_dig);

temp[k]=sum_dig%10+'0';
carry = sum_dig/10;
}
//printf("---%d\n",k);
//printf("---%d\n",carry);
if(carry>0){
temp[k++] = carry+'0';
}
//printf("---%d\n",k);

//temp[k] = '/0';
//printf("%s\n",temp);
//printf("#### %d\n",k);


for (i=k-1,j=0,temp2=0,carry=0;i>=0;i--){
temp1 = (10*carry+temp[i]-'0')/2;
carry = (10*carry+temp[i]-'0')%2;
//printf("%d\n",temp1);
if (temp1) temp2=1;
if (temp2) n1[j++] = temp1+'0';

}

n1[j] = '\0';
//printf("%d\n",temp1);

printf("%s\n",n1);
//printf("%s %s",s,d);

// sum - difference

for(i=len1-1,j=len2-1, k=0,carry=0;i>=0||j>=0;i--,j--,k++){
dig1 = s[i]-'0';
dig2 = j>=0? d[j]-'0':0;

if(dig1<dig2+carry){
temp[k] = 10+dig1-dig2-carry+'0';
carry=1;
}
else{
temp[k] = dig1-dig2-carry+'0';
carry=0;
}

//printf("%s %s",s,d);

}

temp[k] = '\0';
//printf("%s\n",temp);

for (i=k-1,j=0,temp2=0,carry=0;i>=0;i--){
temp1 = (10*carry+temp[i]-'0')/2;
carry = (10*carry+temp[i]-'0')%2;
//printf("%d\n",temp1);
if (temp1) temp2=1;
if (temp2) n2[j++] = temp1+'0';

}

n2[j] = '\0';
//printf("%d\n",temp1);

printf("%s\n",n2);




}
return 0;
}
