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
      int a[N];
      int f=-1,ff=-1;
      for (int i=0; i<N; i++){
         cin>>a[i];
         if(a[i]==1&&f==-1) f=i;
         else if(a[i]==-1&&ff==-1) ff=i;
      }
      //cout << f << ' ' << ff << endl;
      int b[N];
      bool y=true;
      for (int i=0; i<N; i++) cin>>b[i];
      for (int i=0; i<N; i++){
         if(b[i]>a[i]&&(f==-1||f>=i)){y=false; break;}
         if(a[i]>b[i]&&(ff==-1||ff>=i)){y=false; break;}
      }
      if(y)cout << "YES" << endl;
      else cout << "NO" << endl;
   }

}

