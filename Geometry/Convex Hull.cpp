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

struct pt
{
    double x,y;
};

const int NMAX = 10005;


bool cmp(const pt &p1 , const pt &p2)
{
    if(p1.x == p2.x)
        return p1.y < p2.y;
    return p1.x < p2.x;
}

double cp(pt p1 , pt p2 , pt p3)
{
    return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

bool cw(pt p1 , pt p2 , pt p3)
{
    return cp(p1,p2,p3) < 0;
}

bool ccw(pt p1 , pt p2 , pt p3)
{
    return cp(p1,p2,p3) > 0;
}


vector<pt> convex_Hull_Builder(vector<pt> pn)
{
    sort(pn.begin() , pn.end() , cmp);
    vector<pt> p;
    int i;

    //checking for copies
    for(i = 0 ; i < pn.size() ; ++i)
    {
        while(i < pn.size() - 1 && pn[i].x == pn[i+1].x && pn[i].y == pn[i+1].y)
            ++i;

        p.push_back(pn[i]);
    }

    if(p.size() == 1)
        return p;

    vector<pt> up,down;
    pt p1 = p[0] , p2 = p.back();
    up.push_back(p1);
    down.push_back(p1);

    for(i = 1 ; i < p.size() ; ++i)
    {
        if(i == p.size() - 1 || cw(p1, p[i] , p2))
        {
            //above the line
            while(up.size() >= 2 && !cw(up[up.size() - 2],up[up.size() - 1], p[i]))
            {
                up.pop_back();
            }
            up.push_back(p[i]);
        }
        if(i == p.size() - 1 || ccw(p1,p[i],p2))
        {
            //under the line
            while(down.size() >= 2 && !ccw(down[down.size()-2] , down[down.size()-1] , p[i]))
            {
                down.pop_back();
            }
            down.push_back(p[i]);
        }
    }

    vector<pt> rez;

    for(i = 0 ; i < up.size() ; ++i)
        rez.push_back(up[i]);

    for(i = down.size()-2 ; i > 0 ; --i)
        rez.push_back(down[i]);

    return rez;
}

int main()
{

}
