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

bool cmp(int x, int y)
{
	if (x>y)
		return true;
	else
		return false;
}

int32_t main(){
   boost;
   int N,Q; cin>>N>>Q;
   vi vec;
   for (int i=0; i<N; i++){
      int x; cin>>x;
      vec.pb(x);
   }
   for (int i=0; i<Q; i++){
      int x; cin>>x;
      int l,r; cin>>l>>r;
      if(x==1){
         sort(vec.begin()+l-1, vec.end()-(N-r));
      }
      else{
         sort(vec.begin()+l-1, vec.end()-(N-r),cmp);
      }
      /*for (int i=0; i<N; i++){cout << vec[i]; if(i!=N-1) cout << ' ';}
   cout << endl;*/
   }
   for (int i=0; i<N; i++){cout << vec[i]; if(i!=N-1) cout << ' ';}
   cout << endl;



   return 0;
}

