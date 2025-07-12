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

const int MXN=1000*10000+5;

vi p;
bitset <MXN+1> sv;

void sieve(){
   sv[1]=0;
   for (int i=2; i<=MXN; i++) if(sv[i]){
      p.pb(i);
      for (int j=i*i; j<=MXN; j+=i) sv[j]=0;
   }
}

int32_t main(){
   boost;
   sv.set();  sieve();
   int N; cin>>N;
   while(N){
      vi f; N=abs(N);
      for (int i=0; i<sz(p); i++){
         if(N%p[i]==0) f.pb(p[i]);
         while(N%p[i]==0)
            N/=p[i];
         if(N==1) break;
      }
      if(N>1) f.pb(N);
      sort(all(f));
      if(sz(f)<=1) cout << -1 << endl;
      else cout << f[sz(f)-1] << endl;
      //cout << endl;
      cin>>N;
   }

}

