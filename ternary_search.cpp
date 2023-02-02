
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(a, b, c) for (ll a = b; a < c; a++)
#define repr(a, b, c) for (ll a = b; a >= c; a--)
#define fst first
#define snd second
#define pb push_back
#define pii  pair<ll,ll>
#define vi   vector<ll>
#define all(c) ((c).begin()), ((c).end())
#define test()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fast()                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define LOG2(X) ((unsigned)(8 * sizeof(unsigned long long) - __builtin_clzll((unsigned long long)(X)) - 1))

  // function to find y = x^2+(4*x)
double f(double x){
    
    double y=-(x*x)+4*x;

   return y;
}



int solve()
{
   
   double left=-100,right=100; //  x => [-100,100]

   while(right-left>0.000001){ //  this 0.000001 is a precision value
 
    double mid1=(2*left+right)/3;
    double mid2=(left+2*right)/3;
        // f is a function of parabola to find y
      if(f(mid1)<f(mid2)){
        left=mid1;
      }else
      {
        right=mid2;
      }
 

   }
 

 cout<<left<<" "<<right<<endl; // remember  this is a y value no x in a function



    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    test()
#endif // !ONLINE_JUDGE
        int t = 1;
    //cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}