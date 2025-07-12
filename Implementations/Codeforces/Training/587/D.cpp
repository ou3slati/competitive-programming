#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

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

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

vi vec;
void gen(int n){
   for (int i=1; i*i<=n; i++) if(n%i==0){vec.pb(i); vec.pb(n/i);}
}
int32_t main(){
   boost;
   int N; cin>>N;
   int t[N];
   int mx=0;
   for (int i=0; i<N; i++){
      int x; cin>>x;
      mx=max(mx,x);
      t[i]=x;
   }
   for (int i=0; i<N; i++)t[i]=mx-t[i];
   sort(t,t+N);
   int i=0;
   while(t[i]==0)i++;
   if(i==N){cout << 0<<' ' << 0 << endl; return 0;}
   gen(t[i]);
   sort(vec.rbegin(),vec.rend());
   for(int i=0; i<sz(vec);i++){
      int x=vec[i];
      bool y=true;
      int nb=0;
      for (int j=0; j<N; j++){
         if(t[j]%x!=0){y=false; break;}
         else nb+=t[j]/x;
      }
      if(y){
         cout << nb << ' ' << x << endl;
         break;
      }
   }
}
