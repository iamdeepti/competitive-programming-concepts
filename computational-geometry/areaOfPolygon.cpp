#include<bits/stdc++.h>
using namespace std;
double cp(double x1,double x2,double y1,double y2)
{
    double ans = ((double)x1*y2 - (double)x2*y1);
    // cout<<x1<<","<<x2<<"  "<<y1<<","<<y2<<endl;
    // cout<<ans<<endl;
    return ans;
}
double area(double *x,double *y, int n)
{
    double ans = 0;
    for(int i=1;i<n-1;i++)
    {
        ans += (cp(x[i]-x[0],y[i]-y[0],x[i+1]-x[i],y[i+1]-y[i]));
        //cout<<ans<<endl;
        
    }
    return abs(ans/2);
}
int main() {
	int n;
    cin>>n;
    double *x = new double[n];
    double *y = new double[n];
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<n;i++)
        cin>>y[i];
    int ans = area(x,y,n);
    cout<<ans<<endl;
	// Write your code here
    return 0;
}