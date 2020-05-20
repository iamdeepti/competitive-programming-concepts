/*
In this problem, you have to maintain a dynamic set of numbers which support the 
two fundamental operations
INSERT(S,x): if x is not in S, insert x into S
DELETE(S,x): if x is in S, delete x from S
and the two type of queries
K-TH(S) : return the k-th smallest element of S
COUNT(S,x): return the number of elements of S smaller than x
Input Format
Line 1: Q (1 ≤ Q ≤ 200000), the number of operations
In the next Q lines, the first token of each line is a character I, D, K or C meaning 
that the corresponding operation is INSERT, DELETE, K-TH or COUNT, respectively, 
following by a whitespace and an integer which is the parameter for that operation.

If the parameter is a value x, it is guaranteed that ≤ |x| ≤ 10^9. 
If the parameter is an index k, it is guaranteed that 1 ≤ k ≤ 10^9.`
Output
For each query, print the corresponding result in a single line. 
In particular, for the queries K-TH, if k is larger than the number of elements in S, 
print the word 'invalid'.
*/
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
    int ans=-1;
    while(l<=r)
    {
        int mid = l + (r-l)/2;
        int curr = query(mid,bit);
        if(k==curr && query(mid-1,bit)!=curr)
            return mid;
        else if(k>curr)
            l= mid+1;
        else 
        {
            ans = mid;
            r = mid-1;
        }
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
    //coordinate compression
    // since a[i] can range from -10^9 to 10^9 and there can be at max 
    // 2X10^5 values we're sorting all numbers and mapping them to an index
    // between 1 to 2x10^5
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
            // In bit tree we're storing the number of elements that are less than
            // or equal to the given number
            if(query(mp[a[i]],bit)==query(mp[a[i]]-1,bit))
               update(mp[a[i]],bit,1);
        }
        else if(q[i]=='D')
        {
            if(mp.count(a[i])!=0 && (query(mp[a[i]],bit)!=query(mp[a[i]]-1,bit)))
            {
                update(mp[a[i]],bit,-1);
            }
        }
        else if(q[i]=='K')
        {
            int ans = Ksmallest(bit,a[i]);
            if(ans==-1)
                cout<<"invalid"<<endl;
        	else
                cout<<value[ans]<<endl;
        }
        else if(q[i]=='C')
        {
            auto x = lower_bound(t.begin(),t.end(),a[i]);
            int p = x - t.begin();
            if(x==t.end())
                p = t.size()-1;
            else if(t[p]!=a[i])
                p--;
        	p = mp[t[p]];
            cout<<query(p,bit)<<endl;
        }
    }
    
    return 0;
}
