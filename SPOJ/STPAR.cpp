#include <cstdio>
#include <stack>

using namespace std;

stack <int>side_street;
int mobiles[1001];

int main(){
int n,temp,i,j,k,req;
while(true){
scanf("%d",&n);
if(n==0) break;

while (!side_street.empty()){
    side_street.pop();
}

for(i=0;i<n;i++){
scanf("%d",&mobiles[i]);
}

req=1;

i=0;
//printf("asdf");

while(true){
    //printf("i - %d stack - %d\n",i,side_street.size());
    if((i==n)&&(side_street.empty())){
        printf("yes\n");
        break;
    }
    if((i==n)&&(!side_street.empty())){

        while(!side_street.empty()){
        //printf("req - %d stack top - %d\n",req,side_street.top());
        if (side_street.top()!=req){
            //printf("No");
            break;
            }
        else{
            side_street.pop();
            req++;
        }
        }

        if(side_street.empty()){
            printf("yes\n");
        }
        else{
            printf("no\n");

        }
        break;

    }
    if(mobiles[i]==req){
        //side_street.push(temp);
        i++;
        req++;
    }
    else if((!side_street.empty())&&(side_street.top() == req)){
        side_street.pop();
        req++;
    }
    else{
        side_street.push(mobiles[i++]);
    }

}



}

return 0;
}
