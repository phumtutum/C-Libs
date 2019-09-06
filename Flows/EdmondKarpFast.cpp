//check check check
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<cstring>
#include<map>
#include<iomanip>

#define ll long long
#define pb(x) push_back(x)

using namespace std;

typedef pair<int,int> ii;

const int NMAX = 1005;
const int INF = 1e9;


vector<int>g[NMAX];

int capacity[NMAX][NMAX],flow[NMAX][NMAX];
int N,M,tata[NMAX];


bool BFS(int source , int sink)
{
    int i;
    queue<int>q;
    for(i = 1 ; i <= N ; ++i)
        tata[i] = 0;
    tata[source] = -1;
    q.push(source);
    int node;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        if(node ==  sink)
            return 1;
        for(auto gnode : g[node])
        {
            if(tata[gnode] == 0 && capacity[node][gnode] > flow[node][gnode])
            {
                tata[gnode] = node;
                q.push(gnode);
            }
        }
    }

    return 0;
}

int main()
{
    int i,j,x,c,y;
    cin>>N>>M;

    for(i = 1 ; i <= M ; ++i)
    {
        cin>>x>>y>>c;
        g[x].pb(y);
        g[y].pb(x);
        capacity[x][y] = c;
    }

    int new_flow,source = 1 , sink = N , maxflow = 0;
    while(BFS(source , sink))
    {
        for(auto node : g[sink])
        {
            if(tata[node] && capacity[node][sink] > flow[node][sink])
            {
                new_flow = INF;
                tata[sink] = node;
                for(i = sink ; i != source ; i = tata[i])
                    new_flow = min(new_flow , capacity[tata[i]][i] - flow[tata[i]][i]);

                for(i = sink ; i != source ; i = tata[i])
                {
                    flow[tata[i]][i] += new_flow;
                    flow[i][tata[i]] -= new_flow;
                }
                maxflow += new_flow;
            }
        }
    }

    cout<<maxflow;

    return 0;
}
