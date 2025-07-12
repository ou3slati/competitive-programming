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

const int mx=1000*1000+1;
vi p;
bitset<mx> sv;
set<int>s;

void sieve(){
   for (int i=2 ;i<mx; i++) if(!sv[i]){
      p.pb(i); s.insert(i);
      for (int j=i*i; j<mx; j+=i) sv[j]=1;
   }
}

int32_t main(){
   boost;
   sieve();
   int N; cin>>N;
   while(N){
      int a,b;
      for (int i=0; i<sz(p); i++) if(s.count(N-p[i])){
         a=p[i]; b=N-p[i];
         break;
      }
      cout << N<<" = "<<a<<" + "<<b << endl;
      cin>>N;
   }

}

