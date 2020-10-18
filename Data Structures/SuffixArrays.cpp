//check check check
// O(N logN logN) - without radix
// Tested
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<cstring>
#include<map>
#include<iomanip>
#include<set>

#define ll long long
#define pb(x) push_back(x)

using namespace std;

typedef pair<int,int> ii;

const int NMAX = 1e5+5;

struct suffix {
    int indx;
    int rk[2];
};

bool cmp(const suffix &p1, const suffix &p2) {
    if(p1.rk[0] == p2.rk[0])
        return p1.rk[1] < p2.rk[1];
    return p1.rk[0] < p2.rk[0];
}

int suff_array[NMAX];

void create_suffix_array(string s){
    int i,j,N = s.size();

    suffix arr[N];
    int ind[N],k;

    // initialize
    for(i = 0 ; i < N ; ++i) {
        arr[i].indx = i;
        arr[i].rk[0] = s[i] - 'a';
        arr[i].rk[1] = (i+1 < s.size()) ? (s[i+1] - 'a') : -1;
    }

    sort(arr, arr+N, cmp);

    for(k = 4 ; k < (N<<1) ; k <<=1) {
        // compute rank 0 for each
        int prev_rank = arr[0].rk[0];
        arr[0].rk[0] = 0;
        ind[arr[0].indx] = 0;
        for(i = 1 ; i < N ; ++i) {
            if(prev_rank == arr[i].rk[0] && arr[i-1].rk[1] == arr[i].rk[1])
                arr[i].rk[0] = arr[i-1].rk[0];
            else {
                prev_rank = arr[i].rk[0];
                arr[i].rk[0] = arr[i-1].rk[0] + 1;
            }
            ind[arr[i].indx] = i;
        }

        for(i = 0 ; i < N ; ++i) {
            int nextIndex = arr[i].indx + (k>>1);
            arr[i].rk[1] = (nextIndex < N) ? arr[ind[nextIndex]].rk[0] : -1;
        }

        sort(arr, arr+N, cmp);
    }

    for(i = 0 ; i < N ; ++i)
        suff_array[i] = arr[i].indx;
}

int main()
{
    string s;

    cin>>s;
    create_suffix_array(s);

    int i, N = s.size();

    for(i = 0 ; i < N ; ++i)
        cout<<suff_array[i]<<"\n";

    return 0;
}
