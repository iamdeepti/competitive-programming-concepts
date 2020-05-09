#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define s second
#define pii pair<int,int>
bool change(pii p,pii q,pii r)
{
    pii x1 = mp(q.f-p.f,q.s-p.s);
    pii x2 = mp(r.f-q.f,r.s-q.s);
    int x = x1.f*x2.s - x1.s*x2.f;
    return x>0;
}
void convexHull(vector<pii> points)
{
    int n = points.size();
    int left = 0;
    //get the leftmost point
    for(int i=1;i<n;i++)
    {
        if(points[i].f<points[left].f)
            left = i;
    }
    int pos = left;
    vector<pii> hull;
    do
    {
        int q = (pos+1)%n;
        hull.push_back(points[pos]);
        for(int i=0;i<n;i++)
        {
            if(change(points[pos],points[q],points[i]))
            {
                q=i;
            }
        }
        pos = q;
        
    }while(pos!=left);
    for(auto x:hull)
        cout<<x.f<<" "<<x.s<<endl;
}
int main() {

	// Write your code here
    int n;
    cin>>n;
    vector<pii> points(n);
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        points[i] = mp(x,0);
    }
    for(int i=0;i<n;i++)
    {
        cin>>y;
        points[i].s = y;
    }
    convexHull(points);
    return 0;
}