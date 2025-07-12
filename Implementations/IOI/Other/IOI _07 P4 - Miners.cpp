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
//#define int ll
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

int N; str s;
//int memo[100001][34][34];//[4][4];

map<pair<int,pi>,int> memo;

int solve(int a, int b){
   int cnt[4]={0};
   //cout << a << ' ' << b << endl;
   cnt[a]++; cnt[b%10]++; cnt[b/10]++;
   //cout << cnt[0] << ' ' << cnt[1] <<  ' ' <<cnt[2] << ' ' << cnt[3] << endl;
   int ans=0;
   if(cnt[1]>0) ans++;
   if(cnt[2]>0) ans++;
   if(cnt[3]>0) ans++;
   //cout << ans << endl;
   return ans;
}

int solve(int i, int a, int b){
   if(i==N) return 0;
   //if(memo[i][a][b]!=-1) return memo[i][a][b];
   if(memo.count({i,{a,b}})) return memo[{i,{a,b}}];
   int ans,idx;
   if(s[i]=='M') idx=1; else if(s[i]=='F') idx=2; else idx=3;

   ans=max( solve(i+1,idx*10+a/10,b) + solve(idx,a),  solve(i+1,a,idx*10+b/10) + solve(idx,b)  );
   //cout << ans << endl;
   //return memo[i][a][b]=ans;
   return memo[{i,{a,b}}]=ans;
}

int main(){
   boost;
	cin>>N>>s;
	/*for(int i=0; i<=N; i++) for(int j=0; j<45; j++) for(int k=0; k<45; k++)
      memo[i][j][k]=-1;*/
	cout << solve(0,0,0) << endl;

   return 0;
}

