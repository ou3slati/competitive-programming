//NOT SOLVABLE BECAUSE OF BIG INTERGER
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
typedef unsigned long long ull;
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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

ull C(int n, int k){
   vi a, b;
   for (int i=k+2; i<=n; i++) a.pb(i);
   for (int i=2; i<=n-k; i++) b.pb(i);
   ull res=k+1;
   for (int j=0; j<max(sz(a),sz(b)); j++){
      if(j<sz(a)) res*=a[j];
      if(j<sz(b)) res/=b[j];
   }
   return res;


}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N,K; cin >>N>>K;
      if(K==0) {cout << 1 << endl; continue;}
      int nb=0;
      for (int k=0; k<K; k++){
         int x; cin>>x;
         nb+=x;
      }
      int r=N-nb-K+1;
      if(r<=0) {cout << 0 << endl; continue;}
      int l=r+K;
      cout << C(l,r) << endl;


   }

}

