/*
Given a sequence of n numbers a1, a2, ..., an and a number of d-queries. 
A d-query is a pair (i, j) (1 ≤ i ≤ j ≤ n). 
For each d-query (i, j), you have to return the number of distinct elements in the 
subsequence ai, ai+1, ..., aj.
*/
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define vi vector<int>
bool comp(pair<int,pii> a, pair<int,pii> b)
{
   return a.s.s < b.s.s;
}
void update(int * BIT,int value,int index,int n)
{
    for(;index<=n;index += index&(-index))
        BIT[index] += value;
}
int query(int * BIT,int index,int n)
{
    int ans = 0;
    for(;index>0;index -= index&(-index))
        ans += BIT[index];
	return ans;
}
int main()
{
    int n,x;
    cin>>n;
    vi a(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i+1];
    }
    int Q,y;
    cin>>Q;
    int * BIT = new int[n+1];
    vector<pair<int,pii>> q(Q);
    for(int i=0;i<Q;i++)
    {
        cin>>x>>y;
        q[i] = mp(i,mp(x,y));
    }
    // queries sorted on the basis of right
    sort(q.begin(),q.end(),comp);
    vi res(Q);
    vi prev(1000001,-1);
    int j = 0;
    for(int i=1;i<=n;i++)
    {
        // if same element has occurred before just remove it from 
        // everwhere in the tree, because now we will be considering the current
        // occurence only
        if(prev[a[i]]!=-1)
            update(BIT,-1,prev[a[i]],n);
        prev[a[i]]=i;
        update(BIT,1,i,n);
        // process for queries who's r is equal to i
        while(j<Q && q[j].s.s==i)
        {
            res[q[j].f] = query(BIT,q[j].s.s,n)-query(BIT,q[j].s.f-1,n);
            j++;
        }
    }
    
    for(auto x:res)
        cout<<x<<endl;
     // for(int i=1;i<=n;i++)
     //    	cout<<BIT[i]<<" ";
	return 0;
}