//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

int32_t main(){
   boost;
   int p[35]; p[0]=1;
   for(int i=1; i<35; i++) p[i]=p[i-1]*2;
	int N; cin>>N;
	int t[N];
	for(int i=0; i<N; i++) cin>>t[i];

   int res[N]; for(int i=0; i<N; i++) res[i]=0;
	for(int b=30; b>=0; b--){
      int nb=0;
      for(int i=0; i<N; i++) if(((t[i])&(1<<b))) nb++;
      //cout << nb << endl;

      for(int i=0; i<N; i++){
         if(nb%2==0 && t[i]&(1<<b)) res[i]+=p[b];
         else if(nb%2==1 && !(t[i]&(1<<b))) res[i]+=p[b];
      }
      //for(int i=0; i<N; i++) cout << res[i]<< ' '; cout << endl;

	}
	for(int i=0; i<N; i++) cout << res[i]<< ' ';


   return 0;
}

