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

vector<int> t;

bool sorted(){
   for (int i=0; i<sz(t)-1;i++) if(t[i]>t[i+1]) return false;
   return true;
}

int32_t main(){
   boost;
   int T; cin >>T;
   while(T--){
      int N,m; cin>>N>>m;

      int p[m];

      for (int i=0; i<N; i++){int x; cin >>x; t.pb(x);}
      for (int i=0; i<m; i++)cin>>p[i];

      bool mov=true;

   while((!sorted())&&mov){
      mov=false;
      for (int i=0; i<m; i++){
         int x=p[i];
         auto it=find(t.begin(), t.end(),x);
         auto itr=find(t.begin(), t.end(),x+1);
         if(it!=t.end()&& itr!=t.end())
            if(it-t.begin()>itr-t.begin()){ swap(t[it-t.begin()],t[itr-t.begin()]); mov=true;}

      }
   }
      if(sorted()) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
   return 0;
}
