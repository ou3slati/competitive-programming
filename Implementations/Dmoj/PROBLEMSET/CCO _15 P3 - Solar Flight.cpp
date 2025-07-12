#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e10;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};
const int mn=1e-12;

const int MX=2010;
int X,K,N,Q;
ld a[MX],b[MX],c[MX];
vector<pair<ld,int>> vec[MX];
vi st[MX];

void build(int idx, int pos, int l, int r){
   if(l>r) return;
   if(l==r){
      st[idx][pos]=vec[idx][l].se;
      return;
   }
   int m=(l+r)/2;
   build(idx,pos*2,l,m); build(idx,pos*2+1,m+1,r);
   st[idx][pos]=max(st[idx][pos*2],st[idx][pos*2+1]);
}

int query(int idx,int pos, int l, int r, int tl, int tr){
   if(l>r) return -INF;
   if(tl==l && tr==r){
      return st[idx][pos];
   }
   int tm=(tl+tr)/2;
   return max(query(idx,pos*2,l,min(tm,r),tl,tm),query(idx,pos*2+1,max(l,tm+1),r,tm+1,tr));
}

int32_t main(){
   boost;
	cin>>X>>K>>N>>Q;
	for(int i=0; i<N; i++){
      cin>>b[i];
      ld y;cin>>y;
      a[i]=(ld)(y/X)-(b[i]/X); //*****
      cin>>c[i];
	}
	vector<pair<ld,pi>> v;
	for(int i=0; i<N; i++) for(int j=i+1; j<N;j++){
	   if(a[i]==a[j]) continue;
      ld x=(b[j]-b[i])/(a[i]-a[j]);
      if(x>0 && x<=X) v.pb({x,{i,j}});
	}
	sort(all(v));

   vector<pair<ld,int>> v2;
   for(int i=0; i<N; i++)v2.pb({b[i],i});
   sort(v2.rbegin(),v2.rend());

   int t[N]={0};
   for(int i=0; i<N; i++) for(int j=i+1; j<N; j++){
      t[v2[j].se]+=c[v2[i].se];
   }

   for(int i=0; i<N; i++) vec[i].pb({0,t[i]});
   for(int i=0; i<sz(v); i++){
      ld x=v[i].fi; int s=v[i].se.fi,tt=v[i].se.se;
      if(a[s]<a[tt]) swap(s,tt);//****
      t[s]-=c[tt]; t[tt]+=c[s];

      if(vec[s][sz(vec[s])-1].fi==x) vec[s][sz(vec[s])-1].se=t[s]; //**
      else vec[s].pb({x,t[s]});

      if(vec[tt][sz(vec[tt])-1].fi==x)  vec[tt][sz(vec[tt])-1].se=t[tt]; //***
      else vec[tt].pb({x,t[tt]});
   }

   for(int i=0; i<N; i++) vec[i].pb({X,t[i]});//***

   for(int i=0; i<N;  i++){
      int n=sz(vec[i]);
      st[i].assign(n*4+10,0);
      build(i,1,0,n-1);
   }

   while(Q--){
      int idx,stt; cin>>idx>>stt; idx--;
      int n=sz(vec[idx]);

      int l2,r2,l=0,r=n;
      while(l<r){ //***
         int m=(r+l)/2;
         if(vec[idx][m].fi<=stt) l=m+1;
         else r=m;
      }
      l2=l-1;
      l=0,r=n;
      while(l<r){ //***
         int m=(l+r)/2;
         if(vec[idx][m].fi<=stt+K) l=m+1;
         else r=m;
      }
      r2=l-1;
      cout << query(idx,1,l2,r2,0,n-1) << endl;
   }

   return 0;
}
