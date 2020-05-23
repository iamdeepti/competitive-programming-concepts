/*
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. 
A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). 
For each k-query (i, j, k), you have to return the number of elements greater 
than k in the subsequence ai, ai+1, ..., aj.
*/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int,int>
#define s second
#define f first
#define mk make_pair
struct event{
    int l,r,k,index;
};
bool comp(event a,event b)
{
    // if(a.k==b.k)
    //     return a.l>b.l;
    return a.k>b.k;
}
bool comp2(pii a,pii b)
{
    return (a.s>b.s);    
}
void update(int *bit,int n,int index)
{
    for(;index<=n;index += (index)&(-index))
        bit[index] += 1;
}
int query(int *bit,int index)
{
    int ans = 0;
    for(;index>0;index -= index&(-index))
        ans += bit[index];
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,x;cin>>n;
	vector<pii> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a[i] = mk(i+1,x);
    }
    sort(a.begin(),a.end(),comp2);
    int * bit = new int[n+1];
    int Q;cin>>Q;
    vector<event> q(Q);
    int l,r,k;
    for(int i=0;i<Q;i++)
    {
        cin>>l>>r>>k;
        q[i] = {l,r,k,i};
    }
    sort(q.begin(),q.end(),comp);
    vi res(Q);
    int z =0;
    for(int i=0;i<Q;i++)
    {
        while(z<n && q[i].k < a[z].s)
        {    
            update(bit,n,a[z].f);
            z++;
        }
        
        res[q[i].index] = query(bit,q[i].r)-query(bit,q[i].l-1);
        // cout<<q[i].l<<" "<<q[i].r<<" "<<res[q[i].index]<<endl;
    }
    for(auto x:res)
        cout<<x<<endl;
	return 0;
}
