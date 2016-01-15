#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

typedef pair<int,int> pii;
typedef pair<int,pii> weighted_edge;

int parent[MAX];

int find(int u) {
	if(u != parent[u]) parent[u] = find(parent[u]);
	return parent[u];
}

int main(){
int tc;
scanf("%d", &tc);
int V,E;
char discard[10];

while(tc--){

scanf("%d", &V);
vector<weighted_edge> edges;


int temp, vertex, weight;
for(int i=1;i<=V;i++){
parent[i] = i;

scanf("%s",&discard);
scanf("%d",&temp);

while(temp--){

scanf("%d",&vertex);
scanf("%d",&weight);

edges.push_back(weighted_edge(weight, pii(i, vertex)));


}

}

sort(edges.begin(), edges.end());

int cost=0;
for (int i=0;i<edges.size();i++){
int u = find(edges[i].second.first);
int v = find(edges[i].second.second);
int w = edges[i].first;

if(u != v){
cost += w;
parent[u] = parent[v];

}


}

printf("%d\n",cost);

}

return 0;
}



