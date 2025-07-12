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

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      int t[N];
      set <int> s; multiset <int> ss;
      for (int i=0; i<N; i++){
         cin>>t[i];
         ss.insert(t[i]);
         s.insert(t[i]);
      }
      int res=0;
      for (auto x: s){
         int y=ss.count(x); int n=s.size();
         if(ss.count(x)<=s.size()-1) res=max(res,y);
         if(ss.count(x)-1<=s.size()) res=max(res,y-1);

         else if(y-1>s.size()) res=max(res,n);
      }
      cout << res << endl;
      //cout << endl;

   }

}

