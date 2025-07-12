//Never stop trying
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

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int W,L;
int X,Y,X2,Y2;

vpi adj[505][505][2];

/*if(i%2==1){
         for(int j=0; j<sz(s); j++){
            if(s[j]=='b'){
               adj[i/2][j][0].pb({i/2,j+1});
               adj[i/2][j+1][0].pb({i/2,j});
            }
            else if(s[j]=='w'){
               adj[i/2][j][1].pb({i/2,j+1});
               adj[i/2][j+1][1].pb({i/2,j});
            }
         }
      }
      else{
         for(int j=0; j<sz(s); j++){
            if(j%2==1){
               if(s[j]=='b'){
                  adj[i/2-1][j/2+1][0].pb({ i/2 , j/2 });
                  adj[i/2][j/2][0].pb({ i/2-1 , j/2+1 });
               }
               else if(s[j]=='w'){
                  adj[i/2-1][j/2+1][1].pb({ i/2 , j/2 });
                  adj[i/2][j/2][1].pb({ i/2-1 , j/2+1 });
               }
            }
            else{
               if(s[j]=='b'){
                  adj[i/2-1][j/2+1][0].pb({ i/2 , j/2+1 });
                  adj[i/2][j/2+1][0].pb({ i/2-1 , j/2+1 });
               }
               else if(s[j]=='w'){
                  adj[i/2-1][j/2+1][1].pb({ i/2 , j/2+1 });
                  adj[i/2][j/2+1][1].pb({ i/2-1 , j/2+1 });
               }
            }
         }
      }*/

int32_t main(){
   boost;
   //IO();

   cin>>W>>L;
   cin>>X>>Y>>X2>>Y2; swap(X,Y); swap(X2,Y2);

   for(int i=0; i<2*L+1; i++){
   	str s; cin>>s;

      for(int j=0; j<sz(s); j++){
         int x,y,st=-1,xx,yy; if(s[j]=='b') st=0; else if(s[j]=='w') st=1;

         if(i%2==0){ // horizontal
            x=xx=i/2;
            y=j; yy=j+1;
         }
         else{ // non horizontal
            x=i/2; xx=(i+1)/2;
            y=(j+1)/2;
            if(j%2==0) yy=y;
            else yy=y-1;
         }


         if(st!=-1){
            adj[x][y][st].pb({xx,yy});
            adj[xx][yy][st].pb({x,y});
         }  
      }
   }

   //for(auto xx: adj[2][1][1]) cout << xx.fi << ' ' << xx.se << endl;

   int dist[L+10][W+10][2];
   for(int i=0; i<L+1; i++) for(int j=0; j<W+1; j++) for(int k=0; k<2; k++) dist[i][j][k]=INF;
	dist[X][Y][0]=dist[X][Y][1]=0;

	queue<pair<int,pi>> q;
	q.push({0,{X,Y}}); q.push({1,{X,Y}});

	while(!q.empty()){

		int x=q.front().se.fi,y=q.front().se.se,st=q.front().fi;
		//cout << x << ' ' << y << ' ' << st << endl;
      if(x==X2 && y==Y2) break;
		q.pop();
		for(auto it: adj[x][y][st]) if(dist[it.fi][it.se][1-st]==INF){
			dist[it.fi][it.se][1-st]=dist[x][y][st]+1;
			q.push({1-st,{it.fi,it.se}});
		}
	}

	cout << min(dist[X2][Y2][0],dist[X2][Y2][1]) << endl;


	

   return 0;
}

