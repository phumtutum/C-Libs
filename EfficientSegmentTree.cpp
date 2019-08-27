//tricks from: codeforces.com/blog/entry/18051
//check check
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<cstring>

#define ll long long
#define pb(x) push_back(x)

using namespace std;

const int NMAX = 1e5+5;

int arb[NMAX<<1];
int N;

void buildTree()
{
    int i;
    for(i = N-1 ; i ; --i)
        arb[i] = arb[i<<1] + arb[(i<<1)^1];
}

void updateTree(int pos , int val)
{
    int i;
    for(arb[pos += N-1] = val; pos > 1 ; pos>>=1)
        arb[i>>1] = arb[i] + arb[i^1];
}

//sum of [l;r]
int query(int l , int r)
{
    int res = 0;
    for(l += N-1 , r += N-1 ; l <= r ; l>>=1 , r>>=1)
    {
        if(l == r)
        {
            res += arb[l];
            break;
        }
        if(l&1)
            res += arb[l++];
        if(!(r&1))
            res += arb[r--];
    }

    return res;
}

int main()
{
    int i,j;


    cin>>N;

    for(i = 1 ; i <= N ; ++i)
        cin>>arb[N+i-1];

    buildTree();

    cout<<query(1,3)<<"\n";
    cout<<query(2,3)<<"\n";
    cout<<query(2,2)<<"\n";
    cout<<query(3,4)<<"\n";
    updateTree(4 , 12);
    cout<<query(1,3)<<"\n";
    cout<<query(2,3)<<"\n";
    cout<<query(2,2)<<"\n";
    cout<<query(3,4)<<"\n";

    return 0;
}
