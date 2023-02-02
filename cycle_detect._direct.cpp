
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

const int N=8;
vector<int>visited(N+1,false);
vector<int>g[N+1];

bool isCyclic(int node,int parent ){
   if(visited[node])return true;
   cout<<node<<" ";
   visited[node]=true;

   for(int child : g[node]){
    if(child==parent)continue;
     if((isCyclic(child,node))) return true;
   }

  return false;

}


int solve()
{
    int  v,e;
    cin>>v>>e;

    int x,y;
    while (e--)
    {
      cin>>x>>y;

      g[x].push_back(y);

    }

    rep(i,1,v+1){
       if(visited[i]==false && (isCyclic(i,-1))){
         cout<<"Cycle is present"<<endl;
       }else cout<<"No Cycle \n";
       cout<<endl;
    }
       
    


      

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    test()
#endif // !ONLINE_JUDGE
        int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}