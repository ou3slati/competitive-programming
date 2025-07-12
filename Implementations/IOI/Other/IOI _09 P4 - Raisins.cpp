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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int N,M;
int t[51][51];
int memo[51][51][51][51];

int inc(int a, int b, int c, int d){
   return t[c][d]-t[a-1][d]-t[c][b-1]+t[a-1][b-1];
}

int solve(int a, int b, int c, int d){
   if(a==c && b==d) return 0;

   if(memo[a][b][c][d]!=-1) return memo[a][b][c][d];
   int ans=INF;

   for(int i=a; i<c; i++) ans=min(ans,solve(a,b,i,d)+solve(i+1,b,c,d)+inc(a,b,c,d));
   for(int i=b; i<d; i++) ans=min(ans,solve(a,b,c,i)+solve(a,i+1,c,d)+inc(a,b,c,d));

   return memo[a][b][c][d]=ans;
}

int32_t main(){
   boost;
   memset(t,0,sizeof(t));
   memset(memo,-1,sizeof(memo));
   cin>>N>>M;
   for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) cin>>t[i][j];
   for(int i=1; i<=N; i++) for(int j=1; j<=M; j++){
      t[i][j]+=t[i-1][j]+t[i][j-1]-t[i-1][j-1];
   }

   cout << solve(1,1,N,M) << endl;



   return 0;
}

