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

#define PI 3.14159265

int32_t main(){
   boost;
	int TC; cin>>TC;
	while(TC--){
      ld N; cin>>N;


      ld alpha=360/(2*N);
      //cout << alpha << endl;
      ld a=alpha;

      ld ans=1;
      for(int i=0; i<(N-2)/2; i++){
         ans+=(cos(alpha*PI/180))*2;
         alpha+=a;
         //cout << ans << endl;
      }
      cout <<fixed <<setprecision(8) << ans << endl;
	}

   return 0;
}

