#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define LEN 1000000


int main(){

//printf("%c",'4'+1);

int n,len=0,comp=0;
scanf("%d",&n);
char str[LEN];

for (int t=0;t<n;t++){
comp=0;
scanf("%s",&str);
len = strlen(str);
//printf("%d",strlen(str));

// Check if the given string is already a plaindrome
int i=0;
for(i = 0;i<len;i++){
if(str[i]!='9'){
break;
}

}

if(i==len){
printf("%d",1);
for(int j = 0;j<len-1;j++){
printf("%d",0);
}
printf("%d",1);
}
else{
    for(i=0;i<len/2;i++){
        if(str[len/2-i-1]>str[(len+1)/2+i]){
            comp = 1;        // 1st half is greater
            break;
        }
        else if(str[len/2-i-1]<str[(len+1)/2+i]){
            comp = -1;
            break;
        }
    }



          if(comp != 1){
                    // first half ++

                    for(i=(len-1)/2;i>=0;i--){
                        while(str[i]=='9'){
                            str[i] = '0';
                            i--;
                        }
                        str[i] += 1;
                        break;

                    }


                }


                for(i=0;i<=len/2-1;i++){
                    printf("%c",str[i]);

                }
                if(len%2!=0){
                    printf("%c",str[len/2]);
                    for(i=len/2-1;i>=0;i--){
                        printf("%c",str[i]);
}
                }
                else{
                    for(i=len/2-1;i>=0;i--){
                        printf("%c",str[i]);
}
                }


                }



printf("\n");

}



return 0;
}


