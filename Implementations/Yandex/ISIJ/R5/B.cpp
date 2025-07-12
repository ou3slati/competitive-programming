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
//define int ll
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

int R,C,K;
int gg[10][10];
int memo[10][10][101][3][3][3][3][3][3][4];

int op(int x){
   if(x==0) return 1;
   if(x==1) return 0;
   if(x==2) return 3;
   return 2;
}

int convert(int m, int m2){

}

bool vis(int x, int y, int a, int b, int c, int d, int e, int f, int g, int nwx, int nwy){
   int r=1,v=1;
   while(v<gg[nwx][nwy]){
      v*=2; r++;
   }
   int t[7]={g,f,e,d,c,b,a}; t[0]=g;
   for(int i=1; i<7; i++){
      t[i]=nxt(t[i],t[i-1]);
   }

   for(int i=0; i<7; i++){
      x+=nx[op(t[i])]; y+=ny[op(t[i])];
      if(nwx<0||nwy<0||nwx>=R||nwy>=C) return false;
      if(nwx==x && nwy==y){
         if(i+1>=r) return false;
         return true;
      }
   }
   return false;
}

int solve(int x, int y, int r, int a, int b, int c, int d, int e, int f,int g){
   if(r==0) return 0;

   int &ind=memo[x][y][r][a][b][c][d][e][f][g];
   if(ind!=-1) return ind;

   int ans=-1;
   for(int m=0; m<4; m++){
      int nwx=x+nx[m],nwy=y+ny[m];
      if(nwx<R&&nwy<C&&nwx>=0&&nwy>=0&&!vis(x,y,a,b,c,d,e,f,g,nwx,nwy)){
         ans=max(ans,solve(nwx,nwy,r-1,b,c,d,e,f,convert(g,m),m)+gg[nwx][nwy]);
      }
   }
   return ind=ans;
}

int main(){
   memset(memo,-1,sizeof(memo));
   boost;

	cin>>R>>C>>K;
	for(int i=0; i<R; i++) for(int j=0; j<C;j++) cin>>gg[i][j];

	cout << solve(0,0,K-1,0,0,0,0,0,0,0)+gg[0][0] << endl;


   return 0;
}

