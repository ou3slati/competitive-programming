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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ld> vd;
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
      int N,K; cin>>N>>K;
      int t[N];
      bool y=false;
      for(int i=0; i<N; i++){
         int x; cin>>x;
         if(x==K){
            t[i]=1;
            y=true;
         }
         else if(x<K) t[i]=0;
         else t[i]=2;
      }

      if(!y){cout << "no" << endl; continue;}

      y=false;
      for(int i=0; i<N-2; i++){
         if((t[i]&&t[i+1])||(t[i]&&t[i+2])||(t[i+2]&&t[i+1])){
            y=true;
            break;
         }
      }

      if(N==1) y=true;
      if(N==2 && t[0] && t[1]) y=true;
      if(y) cout << "yes" << endl;
      else cout << "no" << endl;
   }


   return 0;
}

