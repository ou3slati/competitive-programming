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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   map <char,int> mp;
   mp['R']=0; mp['L']=1; mp['D']=2; mp['U']=3;

	int R,C; cin>>R>>C;
	char g[R][C];
	char g2[R][C];
	int sx,sy;

	for(int i=0; i<R; i++) for(int j=0; j<C; j++){
      cin>>g[i][j];
      g2[i][j]=g[i][j];
      if(g[i][j]=='S'){sx=i; sy=j;}
	}

	for(int i=0; i<R; i++) for(int j=0; j<C; j++) if(g[i][j]=='C'){
      int x=i-1;
      while(x>=0 && g2[x][j]!='W'){
         if(g2[x][j]>='C' && g2[x][j]<'W' && g[x][j]!='*'){x--;continue;}
         g2[x][j]='*';
         x--;
      }
      x=i+1;
      while(x<R && g2[x][j]!='W'){
         if(g[x][j]>='C' && g2[x][j]<'W' && g[x][j]!='S'){x++;continue;}
         g2[x][j]='*';
         x++;
      }
      x=j-1;
      while(x>=0 && g2[i][x]!='W'){
         if(g2[i][x]>='C' && g2[i][x]<'W' && g[i][x]!='S'){x--;continue;}
         g2[i][x]='*';
         x--;
      }
      x=j+1;
      while(x<C && g2[i][x]!='W'){
         if(g2[i][x]>='C' && g2[i][x]<'W'&& g[i][x]!='S'){x++;continue;}
         g2[i][x]='*';
         x++;
      }
	}

	int dist[R][C];
	for(int i=0; i<R; i++) for(int j=0; j<C; j++) dist[i][j]=INF;
	dist[sx][sy]=0;
	priority_queue<pair<int,pi>,vector<pair<int,pi>>, greater<pair<int,pi>>> q;
	q.push({0,{sx,sy}});

	int ans=-1;
	while(!q.empty()){
      int x=q.top().se.fi, y=q.top().se.se, d=q.top().fi;
      q.pop();
      if(d>dist[x][y]) continue;


      if(g[x][y]>'C' && g[x][y]<'W'&&g[x][y]!='S'){
         int nwx=x+nx[mp[g[x][y]]], nwy=y+ny[mp[g[x][y]]];
         if(nwx>=0 && nwy>=0 && nwx<R && nwy<C && g[nwx][nwy]!='W'&& g2[nwx][nwy]!='*' &&g[nwx][nwy]!='C'&& dist[nwx][nwy]>dist[x][y]){
            dist[nwx][nwy]=dist[x][y];
            q.push({dist[x][y],{nwx,nwy}});
         }
         continue;
      }

      for(int m=0; m<4; m++){
         int nwx=x+nx[m],nwy=y+ny[m];
         if(nwx>=0 && nwy>=0 && nwx<R && nwy<C && g[nwx][nwy]!='W' &&g[nwx][nwy]!='C'&& g2[nwx][nwy]!='*' && dist[nwx][nwy]>dist[x][y]+1){
            dist[nwx][nwy]=dist[x][y]+1;
            q.push({dist[nwx][nwy],{nwx,nwy}});
         }
      }
	}
	for(int i=0; i<R; i++) for(int j=0; j<C; j++) if(g[i][j]=='.'){
      if(g2[sx][sy]=='*'){cout << -1 << endl; continue;}
      if(dist[i][j]==INF) cout << -1 << endl;
      else cout << dist[i][j] << endl;
   }

   return 0;
}

