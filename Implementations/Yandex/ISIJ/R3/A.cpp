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

const int MX=1e5+10;
int N,K;
int t[MX];
vi vec;

int32_t main(){
   boost;
   /*ofstream cout ("prizes.out");
   ifstream cin ("prizes.in");*/

	cin>>N>>K;
	for(int i=1; i<=N;i++){
      cin>>t[i];
	}

	int s=0;
	for(int i=1; i<=N; i++){
      s+=t[i];
      if(i==K)vec.pb(s);
      else if(i>K){
         s-=t[i-K];
         vec.pb(s);
      }
	}
	//for(auto x: vec) cout << x << ' '; cout << endl;

	int pref[N-K+2],suf[N-K+2];
	for(int i=0; i<sz(vec); i++){
      pref[i]=vec[i];
      if(i) pref[i]=max(pref[i],pref[i-1]);
	}
	for(int i=sz(vec)-1;i>=0; i--){
      suf[i]=vec[i];
      if(i!=sz(vec)-1) suf[i]=max(suf[i],suf[i+1]);
	}

	int res=INF;
	for(int i=0; i<sz(vec); i++){
      int x=0;
      if(i+1>K) x=max(x,pref[i-K]);
      if(i+K<sz(vec)) x=max(x,suf[i+K]);
      res=min(res,x);
	}
	cout << res << endl;
	//cout << 7 << endl;


   return 0;
}

