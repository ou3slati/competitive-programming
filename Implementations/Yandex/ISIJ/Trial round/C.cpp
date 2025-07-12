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

const int MX=2000;
char g[MX][MX];
char memo[MX][MX][4];
int N,M;
map <char,int> mp;

bool solve(int x, int y, int d){
   if(memo[x][y][d]=='2') {memo[x][y][d]='0'; return 0;}
   if(memo[x][y][d]!='5') return memo[x][y][d]-'0';

   memo[x][y][d]='2';

   bool ans=1;
   int nwx=x+nx[d],nwy=y+ny[d];
   if(!(nwx<0||nwy<0||nwx>=N||nwy>=M)){
      if(g[nwx][nwy]=='.')ans&=solve(nwx,nwy,d)-'0';
      else{
         ans&=solve(nwx,nwy,mp[g[nwx][nwy]])-'0';
         ans&=solve(nwx,nwy,d)-'0';
      }
   }
   if(ans) memo[x][y][d]='1';
   else memo[x][y][d]='0';
   return ans;
}

int32_t main(){
   boost;
   mp['E']=0;  mp['W']=1;  mp['S']=2;  mp['N']=3;
   for(int i=0; i<MX; i++) for(int j=0; j<MX; j++){
      for(int k=0; k<4; k++) memo[i][j][k]='5';
   }

   cin>>N>>M;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) cin>>g[i][j];

	int res=0;
	for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(g[i][j]!='.'){
      if(solve(i,j,mp[g[i][j]])) res++;
	}
	cout << res << endl;

   return 0;
}

