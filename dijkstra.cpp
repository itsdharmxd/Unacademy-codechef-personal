
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


// 1
// 8 14
// 0 1 4
// 0 7 8
// 1 7 11
// 7 8 7
// 7 6 1
// 8 6 6
// 2 8 2
// 1 2 8
// 6 5 2
// 2 3 7
// 2 5 4
// 3 5 14
// 3 4 9
// 4 5 10


const int N=9;



vector<pair<int,int>>g[N+1];



void dijkstra(){

 priority_queue<pair<int,int>>pq;

 vector<int> dist(N+1,INT_MAX);
 
 vector<int> parent(N+1,-1);
 
 int src=0;
 dist[src]=0;

 pq.push({0,src});

 while (!pq.empty())
 {
    int u=pq.top().second;
    
    pq.pop();

    for(auto vw : g[u]){

    int v=vw.first;
    int w=vw.second;

    if(dist[v]>(w+dist[u])){
      dist[v]=w+dist[u];
      pq.push({dist[v],v});
      parent[v]=u;
    }
    }
 }


  rep(i,0,N){
    cout<<parent[i]<<" is parent of "<<i<<" with weight "<<dist[i]<<endl;
  }

}



int solve()
{
  int v,e;
  cin>>v>>e;

  while (e--)
  {
     int x,y,w;
     cin>>x>>y>>w;
     g[x].push_back({y,w});
     g[y].push_back({x,w});
  }
  

  dijkstra();  
 


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