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


const int MX=5e5+100;
int f[MX];

int modpow(int x, int n, int m){
   if(n==0){
      return 1;
   }
   int y=modpow(x,n/2,m);
   y=(y*y)%m;
   if(n%2==1) y=(y*x)%m;
   return y;
}

int modinv(int N){
   if(N==1) return 1;
   return modpow(N,MOD-2,MOD);
}

int C(int N,int K){
   return (((f[N]*modinv(f[K]))%MOD)*modinv(f[N-K]))%MOD;
}

int32_t main(){
   boost;
   f[0]=1;
   for(int i=1; i<MX; i++) f[i]=(i*f[i-1])%MOD;

   int N,M; cin>>N>>M;
   int res=(((C(M,N)*f[N])%MOD)*((C(M,N)*f[N])%MOD))%MOD;
   //cout << res << endl;

   for(int i=1; i<=N; i++){
      res=(( res-((((  ((C(N,i)*f[M])%MOD)  *  ((modinv(f[M-i]))%MOD))%MOD * (C(M,N-i)*C(M,N-i))%MOD))%MOD)%MOD+MOD))%MOD;


      //cout << res << endl;
   }
   cout << res << endl;


   return 0;
}

