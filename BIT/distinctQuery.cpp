#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
bool comp(pair<int,pii> a, pair<int,pii> b)
{
    return a.s.s < b.s.s;
}
int main()
{
    int n,x;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int Q,y;
    cin>>q;
    int * BIT = new int[n+1];
    vector<pair<int,pii>> q(q);
    for(int i=0;i<Q;i++)
    {
        cin>>x>>y;
        q[i] = mp(i,mp(x,y));
    }
    sort(q.begin(),q.end(),comp);
    map<int,int> m;
    vector<int> res(Q);
    for(int i=0;i<Q;i++)
    {
        
    }
}