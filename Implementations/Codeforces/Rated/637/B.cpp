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

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N,k; cin>>N>>k;
      int t[N];
      for(int i=0;i<N; i++) cin>>t[i];
      int p[N+1]={0};
      for (int i=1; i<N-1; i++) if(t[i]>t[i-1]&&t[i]>t[i+1])
         p[i+1]=1;
      for (int i=1; i<=N; i++) p[i]+=p[i-1];
      int res=-1,idx=-1;
      for (int i=k; i<=N; i++){
         int x=p[i-1]-p[i-k+1];

         if(x>res){
            res=x;
            idx=i-k+1;
         }
      }
      res++;
      cout << res << ' ' <<idx << endl;
      //cout << endl;
   }


   return 0;
}

