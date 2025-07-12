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

int a,b;
int memo[40];
vi vec;

int solve (int i){
   if(i==sz(vec)-1) return 1;
   if(memo[i]!=-1) return memo[i];
   int x=0;
   for (int j=i+1; j<sz(vec); j++) if(vec[j]-vec[i]>=a && vec[j]-vec[i]<=b)
      x+=solve(j);
   return memo[i]=x;
}

int32_t main(){
   boost;
   int t[14]={0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
   for (int i=0; i<14; i++) vec.pb(t[i]);

   memset(memo,-1,sizeof(memo));
   cin>>a>>b;
	int N; cin>>N;
	for (int i=0; i<N; i++){
      int x; cin>>x;
      auto it=lower_bound(all(vec),x);
      vec.insert(it,x);
	}

	cout << solve(0) << endl;

   return 0;
}

