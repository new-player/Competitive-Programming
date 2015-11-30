#include <cstdio>

using namespace std;


int main(){
int t,ans,temp,n;
scanf("%d",&t);
while(t>0){
scanf("%d",&n);

ans=0;
temp=5;

while(temp<=n){
ans += n/temp;
temp = temp*5;
}


printf("%d\n",ans);



t--;
}



return 0;
}



