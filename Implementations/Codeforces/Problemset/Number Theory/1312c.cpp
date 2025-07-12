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

const int MXN=1e16+2;

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N,k; cin>>N>>k;
      int t[N];
      for (int i=0; i<N; i++){
         cin>>t[i];
      }

      set <int> s; vi vec;
      int i=1;
      while(i<MXN){
         s.insert(i); vec.pb(i);
         i*=k;
      }

      bool no=false;
      for (int i=0; i<N; i++){
         while(t[i]>0){
            auto it=upper_bound(all(vec),t[i])-vec.begin(); it--;
            if(s.count(vec[it])==0){
               no=true;
               break;
            }
            t[i]-=vec[it];
            s.erase(vec[it]);
         }
         if(no) break;
      }
      if(no) cout << "NO" << endl;
      else cout << "YES" << endl;

   }

}

