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

int kmp[NMAX];

inline void build_kmp(string v)
{
    //building the prefix function
    int i,j,N = v.size();
 
    for(i = 1 , j = 0 ; i < N ; ++i)
    {
        while(j != 0 && v[i] != v[j])
        {
            j = kmp[j-1];
        }
 
        if(v[i] == v[j])
            kmp[i] = ++j;
        else
            kmp[i] = 0;
    }
}

int main()
{

}
