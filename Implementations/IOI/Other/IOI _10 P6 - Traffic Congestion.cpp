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
//#define int ll
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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

vector<ll> vec(1000000,0);
vi adj[1000000];

void dfs(int u, int p){
   for(auto v: adj[u]) if(v!=p){
      dfs(v,u);
      vec[u]+=vec[v];
   }
}

int LocateCentre(int N, int P[], int S[], int D[]){
   for(int i=0; i<N-1; i++){
      adj[S[i]].pb(D[i]);
      adj[D[i]].pb(S[i]);
   }
   for(int i=0; i<N; i++) vec[i]=P[i];
   dfs(0,-1);
   //for(int i=0; i<N; i++) cout << vec[i] << ' ';
   int res; ll mn=INF;
   for(int i=0; i<N; i++){
      ll up=vec[0]-vec[i];
      for(auto x: adj[i]) if(vec[x]<vec[i])up=max(up,vec[x]);
      if(up<mn){
         mn=up;
         res=i;
      }
   }
   return res;
}

/*int main(){
   int i;
   int N; cin>>N;
   int P[N],S[N],D[N];

   //scanf("%d",&N);
   for (i=0;i<N;i++) cin>>P[i];
   for (i=0;i<N-1;i++) cin>>S[i]>>D[i];
   int r = LocateCentre(N,P,S,D);
   cout << r << endl;
   return 0;
}*/

/*
10
10 20 5
10 20 5 6
40 40 40
0 1
0 2
2 5
2 6
1 3
1 4
4 7
4 8
4 9
*/
