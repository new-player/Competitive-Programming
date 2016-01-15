#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

typedef pair<int,int> pii;
typedef pair<int,pii> weighted_edge;

//int parent[MAX];

/* Reference :
 * http://algs4.cs.princeton.edu/code/edu/princeton/cs/algs4/WeightedQuickUnionUF.java.html
 * http://algs4.cs.princeton.edu/code/edu/princeton/cs/algs4/UF.java.html
*/
// weighted quick-union with path compression

class WeightedQuickUnionUF{
    int *parent;
    int *sz;
    int cnt;

public:
    WeightedQuickUnionUF(int N){
    cnt = N;
    parent = new int[N];
    sz = new int[N];

    for(int i=0;i<N;i++){
        parent[i] = i;
        sz[i] = 1;
    }


    }

    ~WeightedQuickUnionUF(){
        delete [] sz;
        delete [] parent;

    }

    int find(int p){
        /*
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];    // path compression by halving
            p = parent[p];
        }
        */

        while (p!=parent[p]){
            p=parent[p];
        }


        return p;
    }

    bool connected(int p, int q){
    return (find(p) == find(q));
    }

    void _union(int p, int q){
    int rootP = find(p);
    int rootQ = find(q);

    if (rootP == rootQ){
        return;
    }

    if (sz[rootP]<sz[rootQ]){
    parent[rootP] = rootQ;
    sz[rootQ] += sz[rootP];
    }
    else{
        parent[rootQ] = rootP;
        sz[rootP] += sz[rootQ];
    }

    cnt--;
    }


};


/*
int find(int u) {
	if(u != parent[u]) parent[u] = find(parent[u]);
	return parent[u];
}
*/

int main(){
int tc;
scanf("%d", &tc);
int V,E;
char discard[10];

while(tc--){

scanf("%d", &V);
vector<weighted_edge> edges;

WeightedQuickUnionUF uf(V);

int temp, vertex, weight;
for(int i=1;i<=V;i++){

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
int count=0;
// Check if current edges in spanning tree is equal to V-1
for (int i=0;(i<edges.size())&&(count<V-1);i++){

int u = uf.find(edges[i].second.first-1);
int v = uf.find(edges[i].second.second-1);
int w = edges[i].first;

if (!(uf.connected(edges[i].second.first-1, edges[i].second.second-1))){
cost += w;
count++;
uf._union(edges[i].second.first-1, edges[i].second.second-1);

}


}

printf("%d\n",cost);

}

return 0;
}



