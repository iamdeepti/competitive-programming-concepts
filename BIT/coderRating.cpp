#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct coder{
    int c,h,a;
};
bool comp(coder a,coder b)
{
    if(a.h<b.h)
        return true;
    else if(a.h>b.h)
        return false;
    else if(a.h==b.h)
        return (a.a < b.a);
}
void update(ll * bit,int index)
{
    for(;index <=100000;index += index&(-index))
    {
        bit[index] += 1;
    }
}
ll query(ll *bit,int index)
{
    ll ans=0;
    for(;index>0;index -= index&(-index))
    {
        ans += bit[index];
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<coder> arr(n);
    int x,y;
    ll *bit  = new ll[100001];
    bit[0]=0;
    
    for(int i=0;i<n;i++)
    {    
        cin>>x>>y;
        arr[i] = {i,y,x};
    }
    /* sort the array now we have to just check for each arr[i] how many y from 0 to i-1
    are greater than arr[i].y
    */
    sort(arr.begin(),arr.end(),comp);
    vector<int> res(n);
    for(int i=0;i<n;)
    {
        int j = i;
        /*
        Initially the lowest element will have 0 answer
        */
        res[arr[i].c]=query(bit,arr[i].a);
        // Calculating the number of coders having both rating same
        while(j<n && arr[j].h==arr[i].h && arr[j].a==arr[i].a)
        {
            j++;
        }
        int endIndex = j;
        // from i to j-1 the coders will have same no of coders having both a 
        // and h less than them
        for(j=i;j<endIndex;j++)
        {   
            res[arr[j].c] = query(bit,arr[i].a);
            //update(bit,arr[i].a);
        }
        // update the BIT tree, all the index that have a> arr[i].a will be incremented
        // by 1
        for(j=i;j<endIndex;j++)
            update(bit,arr[i].a);
        i = endIndex;
    }
    for(int i=0;i<n;i++)
        cout<<res[i]<<endl;
    delete[] bit;
    return 0;
}
