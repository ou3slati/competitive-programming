#pragma GCC optimize("O3")
#include <bits/stdc++.h>
/*#include "grader.h"
#include <cassert>*/
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

vi p,rnk;
int nbSets;

int findSet(int u){
   return p[u]==u ? u: p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u), b=findSet(v);
   if(a==b) return;
   nbSets--;
   if(rnk[b]>rnk[a]) swap(a,b);
   p[b]=a;
   if(rnk[a]==rnk[b]) rnk[a]++;
}

int32_t main(){
   boost;
	int N,Q; cin>>N>>Q;

	set <pair<int,pi>> s;
	map <pi,int> mp;
	int u,v,w;
	for (int i=1; i<=Q; i++){
      nbSets=N;
      p.resize(N+1); for (int i=1; i<=N; i++) p[i]=i;
      rnk.assign(N+1,0);

      cin>>u>>v>>w;
      if(mp.count({u,v}) && mp[{u,v}]>w){
         s.erase({mp[{u,v}],{u,v}});
         s.insert({w,{u,v}});
         mp[{u,v}]=w;
      }
      else if(mp.count({v,u}) && mp[{v,u}]>w){
         s.erase({mp[{v,u}],{v,u}});
         s.insert({w,{v,u}});
         mp[{v,u}]=w;
      }
      else if(!mp.count({u,v}) && !mp.count({v,u})){
         s.insert({w,{v,u}});
         mp[{v,u}]=w;
      }

      int mst=0;
      for(auto x: s){
         u=x.se.fi; v=x.se.se; w=x.fi;
         if(findSet(u)!=findSet(v)){
            unionSet(u,v);
            mst+=w;
         }
         if(nbSets==1) break;
      }
      if(nbSets>1) cout << -1 << endl;
      else cout << mst << endl;
	}
   return 0;
}

/*
4 6
1 2 10
1 3 8
3 2 3
1 4 3
1 3 6
2 1 2
*/
