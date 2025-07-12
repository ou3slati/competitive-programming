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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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

int N,Q;
int t[1005];
int l,r;

int gcd(int a, int b){
   if(b==0) return a;
   return gcd(b,a%b);
}


pi solve(int i){
   if(i==r) return {t[i],1};

   pi pp=solve(i+1);
   int a=pp.fi,b=pp.se;
   swap(a,b);
   int x=gcd(t[i]*b+a,b);
   return {((t[i]*b+a)/x),(b/x)};
}

int32_t main(){
   boost;
   cin>>N>>Q;
   for(int i=1; i<=N; i++) cin>>t[i];
   while(Q--){
      cin>>l>>r;
      pi x=solve(l);
      cout << x.fi%MOD << ' '<<x.se%MOD << endl;
   }
   return 0;
}

