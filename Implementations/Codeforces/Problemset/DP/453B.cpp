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

int t[101];
int memo[101][(1<<(17))];
pi p[101][(1<<(17))];

bool prime(int x){
   for(int i=2; i<x; i++) if(x%i==0) return false;
   return true;
}

int32_t main(){
   boost;
   int N; cin>>N;
   for(int i=1; i<=N; i++) cin>>t[i];

	for(int i=0; i<N+1; i++) for(int j=0; j<(1<<(17)); j++){
      memo[i][j]=INF;
      if(i==0) memo[i][j]=0;
	}

	vi pr;
	for(int i=2; i<61; i++){
      if(prime(i)) pr.pb(i);
	}

	int mx=0;
	for(int i=1; i<=N; i++) for(int j=0; j<(1<<(17)); j++){
      for(int b=1; b<=60; b++){
         for(int idx=0; idx<17; idx++) if(b%pr[idx]==0 && j&(1<<(idx))==0) continue;
         int m=0;
         for(int idx=0; idx<17; idx++) if(j&(1<<(idx))>0 && b%pr[idx]!=0) m=(m|(1<<(idx)));
         if(memo[i][j]>memo[i-1][m]+abs(t[i]-b)){
            memo[i][j]=memo[i-1][m]+abs(t[i]-b);
            p[i][j]={m,b};
         }
      }
	}
	//cout << mx << endl;


	int mn=INF,val;
	for(int j=0; j<(1<<(17)); j++){
      if(memo[N][j]<mn){
         mn=memo[N][j];
         val=j;
      }
	}
	//cout << mn << endl;

	int i=N;
	vi res;
	while(1){
      int pm=p[i][val].fi;
      int b=p[i][val].se;
      res.pb(b);
      if(i==1) break;
      val=pm; i--;
	}
	reverse(all(res));
	for(auto x: res) cout << x << ' ';

   return 0;
}

