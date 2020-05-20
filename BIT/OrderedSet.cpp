#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mk make_pair
#define pb push_back
#define vi vector<int>
#define f first
#define s second
const int N= 200005;
void update(int index,int * bit,int value)
{
    for(;index<N;index+=index&(-index))
        bit[index] += (value);
}
int query(int index,int * bit)
{
    int ans = 0;
    for(;index>0;index -= index&(-index))
        ans += bit[index];
    return ans;
}
int Ksmallest(int *bit,int k)
{
    int l = 0,r=N-1;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        int curr = query(mid,bit);
        if(k==curr)
            return mid;
        else if(k>curr)
            r= mid-1;
        else 
            l = mid+1;
    }
    return -1;
}
int main()
{
    int Q,k=0;
    cin>>Q;
    vector<char> q(Q);
    vi a(Q);
    map<int,int> mp,value;
    vi t;
    for(int i=0;i<Q;i++)
    {
        cin>>q[i]>>a[i];
        if(q[i]=='I')
        {
            t.pb(a[i]);
            k++;
        }
    }
    int * bit = new int[N];
    sort(t.begin(),t.end());
	k=1;
    for(int i=0;i<t.size();i++)
    {
        if(mp.count(t[i])==0)
        {	value[k] = t[i];
            mp[t[i]] = k++;
        }
    }
    for(int i=0;i<Q;i++)
    {
        if(q[i]=='I')
        {
            if(query(mp[a[i]],bit)==query(mp[a[i]]-1,bit))
               update(mp[a[i]],bit,1);
        }
        else if(q[i]=='D')
        {
            if(mp.count(a[i])!=0 && (query(mp[a[i]],bit)!=query(mp[a[i]]-1,bit)))
            {
                // cout<<query(mp[a[i]],bit)<<endl;
                // cout<<"deleting "<<a[i]<<endl;
                update(mp[a[i]],bit,-1);
                // cout<<query(mp[a[i]],bit)<<endl;
            }
        }
        else if(q[i]=='K')
        {
            int ans = Ksmallest(bit,a[i]);
            cout<<ans<<endl;
            if(ans==-1)
                cout<<"invalid"<<endl;
        	else
                cout<<value[ans]<<endl;
        }
        else if(q[i]=='C')
        {
            int p = *lower_bound(t.begin(),t.end(),a[i]);
            p = mp[t[p]];
            p = (a[i]==mp[p])?p:p-1;
            cout<<query(p,bit)<<endl;
        }
    }
    //for(int i=0;i<Q;i++)
    return 0;
}
