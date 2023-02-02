
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

struct Mat{
    
  int m[2][2];

  Mat(){
    memset(m,0,sizeof(m));
  }
   
   void identity(){
     for(int i=0;i<2;i++){
        m[i][i]=1;
     }
   }

   Mat operator*(Mat a){
    Mat res;

    for(int i=0;i<2;i++){
       for(int j=0;j<2;j++){
         for(int k=0;k<2;k++){
             res.m[i][j]+=m[i][k]*a.m[k][j];
           }                     
     }
     }
   
   return res;
   }
};


 
// using  matrix expo
int fib(int n){
   Mat res;
   res.identity();
   Mat T;
   T.m[0][0]=T.m[0][1]=T.m[1][0]=1;
    
    if(n<=2)return 1;

    while (n)
    {
        if (n&1) res = res*T;
        T=T*T;
        n/=2;
        }
    
     return res.m[0][0]+res.m[0][1];
}



int solve()
{

    int n;
    cin>>n;



    cout<<fib(n);


    
 


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