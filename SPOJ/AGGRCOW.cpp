#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100001];
int c,n;

int f(int x){
int cowsplaced = 1;
long long int lastpos = arr[0];   //Indicates last position of cow placed

for(int j=1;j<n;j++){

if(arr[j]-lastpos>=x){
cowsplaced++;
if (cowsplaced==c){
return 1;
}
lastpos = arr[j];

}


}

return 0;
}

int binarySearch(){
	 int start=0,end=arr[n-1];
	while(start<end){
		int mid=(start+end)/2;
		if(f(mid)==1)
		    start=mid+1;
		else
		    end=mid;
		}
		return start-1;
	}

int main(){
	int tc;
	scanf("%d",&tc);

	while(tc--){
		scanf("%d %d",&n,&c);

		for(int i=0;i<n;i++){
		  scanf("%d",&arr[i]);
		  }

        sort(arr,arr+n);

		printf("%d\n",binarySearch());
     }
 }
