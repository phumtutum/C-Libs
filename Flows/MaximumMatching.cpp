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

const int NMAX = 10005;


int l[NMAX],r[NMAX],N,M,E;
bool viz[NMAX];
vector<int> g[NMAX];

bool match(int node)
{
    viz[node] = 1;
    for(auto gnode : g[node])
    {
        if(r[gnode] == 0)
        {
            l[node] = gnode;
            r[gnode] = node;
            return 1;
        }
    }

    for(auto gnode : g[node])
    {
        if(!viz[r[gnode]] && match(r[gnode]))
        {
            r[gnode] = node;
            l[node] = gnode;
            return 1;
        }
    }

    return 0;
}

int maximum_matching()
{
    int i,j,rez = 0;
    bool ok;
    do
    {
        ok = 0;
        memset(viz , 0 , sizeof(viz));

        for(i = 1 ; i <= N ; ++i)
        {
            if(l[i] == 0 && viz[i] == 0 && match(i))
            {
                ok = 1;
                rez++;
            }
        }

    }while(ok);

    return rez;
}

int main()
{
    int i,j;
    cin>>N>>M>>E;

    for(i = 1 ; i <= E ; ++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
    }

    cout<<maximum_matching()<<"\n";

    for(i = 1 ; i <= N ; ++i)
        if(l[i])
            cout<<i<<" "<<l[i]<<"\n";

    return 0;
}
