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

const int NMAX = 0;


struct minheap
{
    bool operator() (const int &p1 , const int &p2)
    {
        return p1 > p2;
    }
};

struct maxheap
{
    bool operator() (const int &p1 , const int &p2)
    {
        return p1 < p2;
    }
};

priority_queue<int , vector<int> , minheap> minpq;
priority_queue<int , vector<int> , maxheap> maxpq;

int main()
{

}
