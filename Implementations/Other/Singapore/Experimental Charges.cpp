//Never stop trying
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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

const int MX=1e5+10;
int N,Q;

vi adj[MX];
int t[MX];
vi p(MX),szz(MX),rnk(MX);
unordered_set<int> vis;

void dfs(int u){
   vis.insert(u);
   t[u]=1-t[u];
   for(auto x: adj[u]) if(vis.count(x)==0) dfs(x);
}

int findSet(int u){
   if(p[u]==u) return u;
   return p[u]=findSet(p[u]);
}

void unionSet(int u, int v){
   int a=findSet(u),b=findSet(v);
   if(a==b) return;
   if(rnk[b]>rnk[a]) swap(a,b);
   p[b]=a;
   if(rnk[a]==rnk[b]) rnk[a]++;
   szz[a]+=szz[b];
}

int32_t main(){
   boost;
   cin>>N>>Q;

   for(int i=0; i<N; i++){
      t[i]=-1;
      p[i]=i; szz[i]=1; rnk[i]=0;
   }

   while(Q--){
      char c; int i, j; cin>>c>>i>>j; i--;j--;
      if(c=='Q'){
         if(findSet(i)!=findSet(j)) cout <<'?' << endl;
         else if(t[i]==t[j]) cout <<'R' << endl;
         else cout << 'A' << endl;
      }
      else{
         if(t[i]==-1 && t[j]==-1){
            if(c=='A'){
               t[j]=1; t[i]=0;
            }
            else t[i]=t[j]=1;
         }
         else if(t[i]==-1){
            if(c=='A')t[i]=1-t[j];
            else t[i]=t[j];
         }
         else if(t[j]==-1){
            if(c=='A')t[j]=1-t[i];
            else t[j]=t[i];
         }
         else if(findSet(i)!=findSet(j) && ((c=='A' && t[i]==t[j])||(c=='R' && t[i]!=t[j]))){
            vis.clear();
            if(szz[findSet(i)]>szz[findSet(j)])
               dfs(j);
            else dfs(i);
         }
         if(findSet(i)!=findSet(j)) {adj[i].pb(j); adj[j].pb(i);}
         unionSet(i,j);
      }
   }

   return 0;
}

