
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

struct Point{
    int x,y;

    bool operator<(Point p)const{ // const member functions are those functions that are denied permission to change the values of the data members of their class.

        return   x==p.x? y<p.y :  x<p.x ;
    }
    bool operator==(Point p)const{ 
       return    y==p.y &&  x==p.x ;
    }
};


bool clock_wise(Point a,Point b,Point c){

   return a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y) > 0;
}
bool counter_clock_wise(Point a,Point b,Point c){

    return a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y) < 0;
}
bool colinear(Point a,Point b,Point c){

    return a.x*(c.y-b.y)+b.x*(a.y-c.y)+c.x*(b.y-a.y) == 0;
}



vector<Point> convex_hull(vector<Point> points){
    int n=points.size(); 
    if(n<=2)return points;

    sort(all(points));
    
    vector<Point> up, down;

    Point first=points[0],last=points[n-1];

    up.pb(first); down.pb(first);

  for(int i=0;i<n;i++ ){
      if(clock_wise(first,points[i],last)){
       
       while (up.size()>=2 && !clock_wise(up[up.size()-2],up[up.size()],points[i]))
       {
        up.pop_back();
       }
       


        up.pb(points[i]);
      }
      if(counter_clock_wise(first,points[i],last)){
          while (up.size()>=2 && ! counter_clock_wise(up[up.size()-2],up[up.size()],points[i]))
       {
        up.pop_back();
       }
        down.pb(points[i]);
      }
  
  }

  vector<Point> ans;
  for(Point p : up)ans.pb(p);
  
  for(Point p : down)ans.pb(p);

  ans.resize( unique(all(ans))-ans.begin());

  return ans;
  
}



int solve()
{
    int n;
    cin>>n;

    vector<Point> points(n);

    rep(i,0,n){
        cin>>points[i].x>>points[i].y;
    }    

    vector<Point> convex = convex_hull(points);
   

   
 

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