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

int32_t main(){
   boost;

   int T; cin>>T;
   for (int t=0; t<T; t++){
      int N; cin >>N;
      vector<char> v;
      vector<int>vec;
      for (int n=0; n<N; n++){
         char c; int x; cin >>c;
         if(c>='0'&&c<='9'){x=c-'0'; c=' ';}
         else cin >>x;
         v.pb(c); vec.pb(x);
      }
      int M; cin >>M;
      long long res=0;
      cin.ignore();
      for (int m=0; m<M; m++){
         string s; getline(cin,s);
         for (int i=0; i<sz(s); i++){
            auto it=find(v.begin(), v.end(), s[i]);
            if(it!=v.end()) res+=vec[it-v.begin()];
         }
      }
      cout << (double)res/100 << '$' <<endl;
   }

   return 0;
}
