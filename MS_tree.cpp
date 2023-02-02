
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

const int N=7;
vector<int>visited(N+1,0);
vector<pair<int,int>>g[N+1];

  
// 1
// 7 9
// 1 2 4     u v w
// 2 3 2
// 3 4 2
// 4 5 1
// 5 6 6
// 6 1 7
// 1 7 5
// 2 7 3
// 5 7 4





///////////////////  prims
void findprimMST(){
   
   priority_queue<pii,vector<pii>,greater<pii> > pq;

   int src=1; // source as 0
   
   vector<int>parent(N+1,-1);
   vector<bool>procesed(N+1,false);
   vector<int>current_weight(N+1,INT_MAX);
    parent[src]=0; 
   pq.push({0,src});
   current_weight[src]=0;

   while(!pq.empty()){
     pii curr= pq.top();
     pq.pop();

     int  u =curr.second;
     if(procesed[u])continue;
     
     procesed[u]=true; 

     for(pii v : g[u]){
     
        if(procesed[v.first]==false&&v.second < current_weight[v.first]   ){
           parent[v.first]=u;
           current_weight[v.first]=v.second;
           pq.push({current_weight[v.first],v.first});


        }
 

     }

   }
   rep(i,1,N+1){
    cout<<"parent of "<<i<<" "<<parent[i]<<endl;
   }
   

}
// prims ends


struct DSU
{
 int connected;
 vector<int> par, sz;

 void init(int n) 
 {
 par = sz = vector<int> (n + 1, 0);
 for(int i = 1; i <= n; i++)
 par[i] = i, sz[i] = 1;
 connected = n;
 }

 int getPar(int u)
 {
 while(u != par[u])
 {
 par[u] = par[par[u]];
 u = par[u];
 }
 return u;
 }

 int getSize(int u)
 {
 return sz[getPar(u)];
 }

 void unite(int u, int v)
 {
 int par1 = getPar(u), par2 = getPar(v);

 if(par1 == par2)
 return;

 connected--;

 if(sz[par1] > sz[par2])
 swap(par1, par2);

 sz[par2] += sz[par1];
 sz[par1] = 0;
 par[par1] = par[par2];
 }
};
// vector<int> arr{1, 2, 3, 4, 5};
// struct DSU dsu;
// dsu.init(arr.size());
// dsu.unite(1, 2);

void krukshal_algo(vector<pair<int,pair<int,int>>> &edge){

   sort(all(edge));

   DSU dsu;
   dsu.init(N+1);

   for( auto ed : edge){
    int u=ed.second.first,v=ed.second.second;

    if(dsu.getPar(u)!= dsu.getPar(v)){
      dsu.unite(u,v);

      cout<<"connect "<<u<<" "<<v<<endl;


    }


   }







}



int solve()
{
    int  v,e;
    cin>>v>>e;

    int x,y,w;

    vector<pair<int,pair<int,int>>>edge;

    while (e--)
    {
      cin>>x>>y>>w;

    // krukshal 
    edge.push_back({w,{x,y}});

      // prims
      g[x].push_back({y,w});
      g[y].push_back({x,w});
      
    }

   
   findprimMST();
  cout<<"-------------------------"<<endl;

  krukshal_algo(edge);

   

      

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