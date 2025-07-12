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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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
const int nx[6]={0,0,0,0,1,-1},ny[6]={0,0,1,-1,0,0}, nz[6]={1,-1,0,0,0,0};

int32_t main(){
   boost;
   int L,R,C;
   while(cin>>L>>R>>C, L||R||C){
      char g[L][R][C];
      pair <int,pi> st,dest;
      for (int l=0; l<L; l++) for(int r=0; r<R; r++) for(int c=0; c<C; c++){
         cin>>g[l][r][c];
         if(g[l][r][c]=='S') st={l,{r,c}};
         else if(g[l][r][c]=='E') dest={l,{r,c}};
      }

      queue <pair<int,pi>> q; q.push(st);
      int dist[L][R][C]; memset(dist,-1,sizeof(dist));
      dist[st.fi][st.se.fi][st.se.se]=0;

      while(!q.empty()){
         int x=q.front().fi, y=q.front().se.fi, z=q.front().se.se;
         q.pop();
         if(x==dest.fi&& y==dest.se.fi && z==dest.se.se) break;
         for(int m=0; m<6; m++){
            int nwx=x+nx[m], nwy=y+ny[m],nwz=z+nz[m];
            if(nwx<0||nwy<0||nwz<0||nwx>=L||nwy>=R||nwz>=C) continue;
            if(dist[nwx][nwy][nwz]==-1 && g[nwx][nwy][nwz]!='#'){
               q.push({nwx,{nwy,nwz}});
               dist[nwx][nwy][nwz]=dist[x][y][z]+1;
            }
         }
      }
      if(dist[dest.fi][dest.se.fi][dest.se.se]==-1) cout << "Trapped!" << endl;
      else cout << "Escaped in " <<dist[dest.fi][dest.se.fi][dest.se.se]<<" minute(s)." << endl;
      //cout << endl<< endl;
   }
   return 0;
}

