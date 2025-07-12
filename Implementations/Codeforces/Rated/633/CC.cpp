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

int res;

void solve(int mx, int i){
   res++;
   while(i<mx){
      i+=(int)(pow(2,res-1)+0.5); res++;
   }
   res--;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N; res=0;
      int t[N];
      for (int i=0; i<N; i++) cin>>t[i];
      int mx=0;
      for (int i=0; i<N; i++){
         mx=max(mx,t[i]);
         if(t[i]==mx) continue;
         solve(mx,t[i]);
         mx=max(mx,t[i]+(int)(pow(2,res-1)+0.5));
         for (int j=i; j<N; j++)t[j]+=(int)(pow(2,res-1)+0.5);

      }
      cout << res << endl;
   }

}

