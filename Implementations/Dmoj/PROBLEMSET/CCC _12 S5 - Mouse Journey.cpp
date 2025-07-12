#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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

int R,C;
set <pi> s;
int memo[26][26];

int solve(int r, int c){
   if(r==1 && c==1) return 1;
   if(memo[r][c]!=-1) return memo[r][c];
   int x=0;
   if(r-1>=1 && s.count({r-1,c})==0) x=solve(r-1,c);
   if(c-1>=1 && s.count({r,c-1})==0) x+=solve(r,c-1);
   return memo[r][c]=x;
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   cin>>R>>C;
   int N; cin>>N;
   for (int i=0; i<N; i++){
      int x,y; cin>>x>>y;
      s.insert({x,y});
   }
   cout << solve(R,C) << endl;

}

