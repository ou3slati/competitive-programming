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

const int MX=1e7+1;
vi spf(MX,-1);

void sieve(){
   for(int i=2; i<MX; i++) if(spf[i]==-1){
      for(int j=i; j<MX; j+=i) spf[j]=i;
   }
}

int f(int N){
   if(N==1) return 1;
   vi vec;
   while(N>1){
      vec.pb(spf[N]);
      N/=spf[N];
   }
   int res=1;
   for(int i=0; i<sz(vec); i++){
      int cnt=0;
      int x=vec[i];
      while(i<sz(vec) && vec[i]==x){
         cnt++; i++;
      }
      i--;
      res*=cnt+1;
   }
   return res;
}

int32_t main(){
   boost;
   //memset(spf,-1,MX);
   sieve();
	int N; cin>>N;
	int res=0;
	for(int i=1; i<=N; i++){
      res+=i*f(i);
	}
   cout << res << endl;
   return 0;
}

