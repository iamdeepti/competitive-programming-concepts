/*A plot has been surveyed.
 Its boundary consists of segments that form a polygon. 
 Each segment runs either North-South or East-West. 
 Calculate the enclosed area. */
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
unordered_map <char,pair<int,int>> m = {{'N',{0,1}},{'S',{0,-1}},{'E',{1,0}},{'W',{-1,0}}}; 
double cp(int x1,int y1,int x2,int y2)
{
    return (double)x1*y2 - (double)y1*x2;
}
double area(vector<pair<int,int>> a)
{
    int n = a.size();
    double ans = 0;
    pair<int,int> k = a[0];
    pair<int,int> l = a[0];
    for(int i=1;i<n;i++)
    {
        //ans += cp(a[i].f+a[0].f,a[i].s+a[0].s,a[i+1].f,a[i+1].s);
         l.f += a[i].f;
        l.s += a[i].s;
        ans += cp(l.f,l.s,k.f,k.s);
        k = l;
        //ans += cp()
    }
    return abs(ans*0.5);
}
int main()
{
    string s;
    cin>>s;
    int n = s.length();

    //int *a = new int[n];
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        a[i] = mp(x*m[s[i]].f,x*m[s[i]].s);
    }
    cout<<area(a);
    return 0;
}

