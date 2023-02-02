
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



//  1

//  lazy segment tree
struct segmenttreelazy{
   vector<int>st,lazy;
   int n;
   void init(int _n){
    this->n=_n;
    st.resize(4*n,0);
     lazy.resize(4*n,0);     ////////////// new 
   }

   void build(vector<int>&v){
    build(0,v.size()-1,0,v);  // (start_range,end_range, current node)
   } 
   void build(int start,int ending,int node,vector<int>&v){

    if(start==ending){
      st[node]=v[start];
      return;
    }

    int mid=(start+ending)/2;

    // build left 
    build(start,mid,node*2+1,v);

   // build right
    build(mid+1,ending,node*2+2,v);
      
    st[node]=st[node*2+1]+st[node*2+2];
   } 
   

   

   int query(int l , int r){
     query(0,n-1,l,r,0);
   }
   int query(int start,int end,int l,int r,int node){
   // no overlap
   if (start>r || end<l){
    return 0;
   }

    if(lazy[node]!=0){    /// ///////////////////// new  block
      // pending            
      st[node]+=lazy[node]*(end-start+1);

      if(start != end){
        lazy[2*node+1]+= lazy[node];
        lazy[2*node+2]+= lazy[node];
      }
    lazy[node]=0;
    }                     ////////////////
     


   // complete overlap
   if (start>=l && end<=r){
    return st[node];
   }

   // partial case

   int mid= (start+end)/2;
    int q1=query(start,mid,l,r,node*2+1);
    int q2=query(mid+1,end,l,r,node*2+2);

    return q1+q2;
  }
   


   // changing whole update
  void update(int l,int r,int y){
   update(0,n-1,0,l,r,y);
  } 
  
  void update(int start, int end,int node,int l,int r,int value){

    // non overlap
     if(r<start || end<l){
     return ;
     }      
 


      if(lazy[node]!=0){    /// ///////////////////// new  block
      // pending            
      st[node]+=lazy[node]*(end-start+1);

      if(start != end){
        lazy[2*node+1]+= lazy[node];
        lazy[2*node+2]+= lazy[node];
      }
    lazy[node]=0;
    }                     ////////////////


   // complete  overlap 
   if(start>=l && end<=r){
      st[node]+=value*(end-start+1);  // updating  what needs  to be
    
   if(start != end){
        lazy[2*node+1]+= value;
        lazy[2*node+2]+=value;
      }
 
     return;
   }



   // partial overlap
   int mid=(start+end)/2;
   update(start,mid,2*node+1,l,r,value);
   
   update(mid+1,end,2*node+2,l,r,value);
 
  
   st[node]=st[node*2+1]+st[node*2+2]; 
    return;

    }
};




//    2

//  normal segment tree
struct segmenttree{
   vector<int>st;
   int n;
   void init(int _n){
    this->n=_n;
    st.resize(4*n,0);
   }

   void build(vector<int>&v){
    build(0,v.size()-1,0,v);  // (start_range,end_range, current node)
   } 
   void build(int start,int ending,int node,vector<int>&v){

    if(start==ending){
      st[node]=v[start];
      return;
    }

    int mid=(start+ending)/2;

    // build left 
    build(start,mid,node*2+1,v);

   // build right
    build(mid+1,ending,node*2+2,v);
      
    st[node]=st[node*2+1]+st[node*2+2];
   } 
   

   

   int query(int l , int r){
     query(0,n-1,l,r,0);
   }
   int query(int start,int end,int l,int r,int node){
   // no overlap
   if (start>r || end<l){
    return 0;
   }

   // complete overlap
   if (start>=l && end<=r){
    return st[node];
   }

   // partial case

   int mid= (start+end)/2;
    int q1=query(start,mid,l,r,node*2+1);
    int q2=query(mid+1,end,l,r,node*2+2);

    return q1+q2;
  }
   


   
  int update(int x,int y){
   update(0,n-1,0,x,y);
  } 
  
  int update(int start, int end,int node,int index,int value){

   if(start==end){
    st[node]=value;
    return;
   }

    int mid=(start+end)/2;
    if(index<=mid){
    update(start,mid,node*2+1,index,value);
    }else{

    update(mid+1,end,node*2+1,index,value);
    }

 st[node]=st[node*2+1]+st[node*2+2];
  }
};



int solve()
{
    vector<int> v= {1,2,3,4,5,6,7,8};

  segmenttree tree;

  segmenttreelazy lazy_tree;
  tree.init(v.size());
 


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