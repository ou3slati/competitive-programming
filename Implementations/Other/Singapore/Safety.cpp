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

int memo[500][1000];
int t[500];
int N,H;
int mx=0;

int solve(int i, int h){
   if(i==N) return 0;
   if(memo[i][h]!=-1) return memo[i][h];
   int ans=INF;
   for(int j=0; j<=mx+H; j++) if(abs(j-h)<=H) ans=min(ans,solve(i+1,j)+abs(t[i]-j));

   return memo[i][h]=ans;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
	cin>>N>>H;

	for(int i=0; i<N; i++){cin>>t[i]; mx=max(mx,t[i]);}

	if(H==0){
      int res=INF;
      for(int i=0; i<N;i++){
         int s=0;
         for(int j=0; j<N;j++) s+=abs(t[j]-t[i]);
         res=min(res,s);
      }
   cout << res << endl;
   return 0;
	}

	if(mx<H){cout << 0 << endl; return 0;}
	int ans=INF;
	for(int i=0; i<=mx; i++) ans=min(ans,solve(0,i));
	cout << ans << endl;

   return 0;
}

