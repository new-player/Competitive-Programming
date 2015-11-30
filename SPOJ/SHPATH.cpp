// Implementation of Dijkstra's algorithm using adjacency lists
// and priority queue for efficiency.
//
// Running time: O(|E| log |V|)
//http://stanford.edu/~liszt90/acm/notebook.html#file18

#include <queue>
#include <cstdio>
#include <string>
#include <map>

using namespace std;
const int INF = 1 << 30;
typedef pair<int,int> PII;

int main()
{

    int tc;
    scanf ("%d", &tc);
    while(tc--)
    {
        int N;  //No of Nodes in the graph
        //int N, s, t;
        scanf ("%d", &N);
        vector<vector<PII> > edges(N);
        map<string,int> names;
        char c_name[15];   // City Name atmost 10 chars long.

        for (int i = 0; i < N; i++)
        {
            scanf ("%s", &c_name);
            names[c_name] = i;
            int M;
            scanf ("%d", &M);
            for (int j = 0; j < M; j++)
            {
                int vertex, dis;
                scanf ("%d%d", &vertex, &dis);
                edges[i].push_back (make_pair(dis, --vertex)); // note order of arguments here
            }
        }

        int q;   // No of queries
        scanf ("%d", &q);
        while(q--)
        {

            char src[15],target[15];      // Source and target nodes

            scanf ("%s %s", &src, &target);
            //scanf ("%d%d", &s, &t);
            int s = names[src];
            int t = names[target];

            //printf("src - %d\n\n",s);
            //printf("tar - %d\n\n",t);
            // use priority queue in which top element has the "smallest" priority
            // http://stackoverflow.com/questions/19795341/how-can-i-sort-a-vector-containing-pairint-int-elements-sorting-is-done-as-p
            // http://stackoverflow.com/questions/10765586/priority-queue-of-pairs-in-reverse-order

            priority_queue<PII, vector<PII>, greater<PII> > Q;

            vector<int> dist(N, INF);
            //vector<int> dad(N, -1);
            Q.push (make_pair (0, s));
            dist[s] = 0;
            while (!Q.empty())
            {
                PII p = Q.top();
                if (p.second == t) break;
                Q.pop();

                int here = p.second;

                for (vector<PII>::iterator it=edges[here].begin(); it!=edges[here].end(); it++)
                {
                    if (dist[here] + it->first < dist[it->second])
                    {
                        dist[it->second] = p.first + it->first;
                        //dad[it->second] = here;
                        Q.push (make_pair (dist[it->second], it->second));
                    }
                }
            }
            /*
            while(!Q.empty()){
				PII pp = Q.top(); Q.pop();
				int at = pp.second, cost = pp.first, sz = edges[at].size();
				if(dist[at] < cost) continue;
				if(at == t) break;
				for(int i = 0; i < sz; ++i){
					int x = edges[at][i].second, w = edges[at][i].first;
					if(dist[x] > cost + w) Q.push(make_pair((dist[x] = cost + w), x));
				}
			}
            */
            printf ("%d\n", dist[t]);

        }
        /*
         * To get the shortest path.
        if (dist[t] < INF)
          for(int i=t;i!=-1;i=dad[i])
            printf ("%d%c", i, (i==s?'\n':' '));
        */
    }
    return 0;
}
