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
   int N,M;
   cin>>M>>N;
   while(N||M){
      /*memset(memo,-1,sizeof(memo)); //memset(memo2,-1,sizeof(memo2));

      int res=C(N,2)*M*2;
      cout << res << endl;
      res+=C(M,2)*N*2;
      cout << res << endl;
      for (int i=2; i<M; i++) res+=4*C(i,2)*2;
      cout << res << endl;
      res+=2*C(M,2)*(N-M+1)*2;
      cout << res << endl << endl;*/

      if(N<M) swap(N,M);
      int res=(N-1)*N*M + M*(M-1)*N;
      //cout << res << endl;
      for (int i=2; i<M; i++) res+=4*(i-1)*i;
      //cout << res << endl;
      res+=(M-1)*M*(N-M+1)*2;
      cout << res << endl;


      cin>>N>>M;
   }


}

