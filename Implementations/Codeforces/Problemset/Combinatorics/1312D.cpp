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

const int MOD = 998244353;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int modpow(int n, int x){
   if(x==0) return 1;
   int y=modpow(n,x/2);

   y=(y*y)%MOD;
   if(x%2==1) y=(y*n)%MOD;
   return y;
}

int modinv(int x){
   return modpow(x,MOD-2);
}

int C(int n, int k){
   int res=1;
   for (int i=2; i<=n; i++) res=(res*i)%MOD;
   for (int i=2; i<=k; i++) res=(res*modinv(i))%MOD;
   for (int i=2; i<=n-k; i++) res=(res*modinv(i))%MOD;
   return res;
}

int32_t main(){
   boost;
   int n,m; cin>>n>>m;
   cout << (((C(m,n-1)*(n-2))%MOD)*modpow(2,n-3))%MOD << endl;
}

