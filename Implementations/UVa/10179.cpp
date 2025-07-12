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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=32000;
bitset<MXN> sv;
vi p;
vi vec;

void sieve(){
   sv.set();
   for (int i=2; i<MXN; i++) if(sv[i]){
      p.pb(i);
      for (int j=i*i; j<MXN; j+=i) sv[j]=0;
   }
}

void f(int N){
   for (int i=0; i<sz(p)&&p[i]*p[i]<=N; i++){
      if(N%p[i]==0) vec.pb(p[i]);
      while(N%p[i]==0) N/=p[i];
   }
   if(N>1) vec.pb(N);
}

int32_t main(){
   boost;
   sieve();
   int N; cin>>N;
   while(N){
      vec.clear();
      f(N);
      int ans=N;
      /*for (int i=0; i<sz(vec); i++) cout << vec[i] << ' ';
      cout << endl;*/
      for (int i=0; i<sz(vec); i++) ans-=ans/vec[i];
      cout << ans << endl;
      cin>>N;
   }

}

