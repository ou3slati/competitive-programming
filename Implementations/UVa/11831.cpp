#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

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

const int MOD = 1e9+7;
const ll INF = 1e18;

const int nx[4]={-1,0,1,0}, ny[4]={0,1,0,-1}; //N E S W

int N,M,S;
string s;
char g[101][101];
bool vis[101][101];
int d;
int res;

void solve(int x, int y,int i){
   for (int i=0; i<sz(s); i++){
      vis[x][y]=true;
      if(s[i]=='D') d=(d+1)%4;
      else if(s[i]=='E') d=(d-1+4)%4;
      else{
         int nwx=x+nx[d], nwy=y+ny[d];
         if(nwx>=0&&nwy>=0&&nwx<N&&nwy<M&&g[nwx][nwy]!='#'){
            x=nwx; y=nwy;
            if(g[nwx][nwy]=='*'&&!vis[nwx][nwy]) res++;
         }
      }
   }
}

int32_t main(){
   boost;
   cin>>N>>M>>S;
   while(N||M||S){
      d=-1; res=0; memset(vis,0,sizeof(vis));
      int x,y;
      for(int i=0; i<N; i++) for (int j=0; j<M; j++){
         char c; cin>>c;
         g[i][j]=c;
         if(c=='N') d=0;
         else if(c=='L') d=1;
         else if(c=='S') d=2;
         else if(c=='O') d=3;
         if(c=='N'||c=='L'||c=='S'||c=='O'){x=i; y=j;}
      }
      cin>>s;
      solve(x,y,0);
      cout << res << endl;

   cin>>N>>M>>S;
   }


}


