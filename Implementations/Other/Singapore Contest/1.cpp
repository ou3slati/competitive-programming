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

const int MXN=3*100000+50;
int permu[MXN];

int32_t main(){
   boost;
   permu[0]=1;
   for (int i=1; i<MXN; i++) permu[i]=(permu[i-1]*i)%MOD;

   int N; cin>>N;
   int t[N];
   set <int> s;
   for (int i=0; i<N; i++){
      cin>>t[i];
      s.insert(t[i]);
   }

   int ans=1;
   for (int i=0; i<N; i++){
      int x=t[i];
      auto it=s.lower_bound(x);
      if(it==s.begin()){
         s.erase(*it);
         continue;
      }

      int y=N-i-1;

      int d=distance(s.begin(),it);
      ans=(ans+(permu[y]*d)%MOD)%MOD;
      s.erase(*it);
   }
   cout << ans << endl;
   return 0;
}

//1 3 4 5 6 2
