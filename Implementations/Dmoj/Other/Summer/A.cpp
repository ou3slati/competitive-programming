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

const int MX=100;

int R,C,M;
char g[MX][MX];
int memo[MX][MX][MX];
map <char,int> mp;
str s;

int solve(int x, int y, int idx){
   if(g[x][y]=='#') return 0;
   if(idx==M) return 1;
   if(memo[x][y][idx]!=-1) return memo[x][y][idx];
   int ans=0;
   if(s[idx]=='?'){
      for(int m=0; m<4;m++){
         int nwx=x+nx[m],nwy=y+ny[m];
         if(nwx<0||nwy<0||nwx>=R||nwy>=C) continue;
         if(solve(nwx,nwy,idx+1)==1){ans=1; break;}
      }
   }
   else{
      int nwx=x+nx[mp[s[idx]]],nwy=y+ny[mp[s[idx]]];
      if(!(nwx<0||nwy<0||nwx>=R||nwy>=C)&& solve(nwx,nwy,idx+1)==1) ans=1;
   }
   return memo[x][y][idx]=ans;
}

int32_t main(){
   boost;
   mp['E']=0;  mp['W']=1;  mp['S']=2;  mp['N']=3;
   //memset(memo,-1,sizeof(memo));
	cin>>R>>C>>M;
	for(int i=0; i<R; i++) for(int j=0; j<C; j++){
      cin>>g[i][j];
      for(int k=0; k<MX; k++) memo[i][j][k]=-1;
	}
	cin>>s;

	int ans=0;
	reverse(all(s));
	for(int i=0; i<M; i++){
      if(s[i]=='N') s[i]='S';
      else if(s[i]=='S') s[i]='N';
      else if(s[i]=='E') s[i]='W';
      else if(s[i]=='W') s[i]='E';
	}
	for(int i=0; i<R; i++) for(int j=0; j<C; j++) if(solve(i,j,0)==1){
      ans++;
      //g[i][j]='S';
	}
   cout << ans << endl;

   /*cout << s << endl;
   for(int i=0; i<R; i++){
      for(int j=0; j<C; j++) cout << g[i][j];
      cout << endl;
   }*/
   return 0;
}

