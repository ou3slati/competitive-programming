#i#pragma GCC optimize("O3")
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

int dist[201][201][201];

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int a,b,c,D; cin>>a>>b>>c>>D;

      memset(dist,100, sizeof(dist));
      dist[0][0][c]=0;

      priority_queue<pair<int,pair<pi,int>>, vector<pair<int,pair<pi,int>>>, greater<pair<int,pair<pi,int>>>> q;
      q.push({0,{{0,0},c}});

      int ans=-1;
      int mn=INF,dp=-1,ans2=INF;
      while(!q.empty()){
         int i=q.top().se.fi.fi,j=q.top().se.fi.se,k=q.top().se.se, d=q.top().fi;
         q.pop();

         if(d>dist[i][j][k]) continue;
         if(i==D||j==D||k==D){ans=d; break;}

         if(i==dp ||j==dp||k==dp) ans2=min(ans2,d);
         if(i<D&&D-i<mn){
            ans2=0; mn=D-i;
            dp=i; ans2=d;
         }
         if(j<D&&D-j<mn){
            ans2=0; mn=D-j;
            dp=j; ans2=d;
         }
         if(k<D&&D-k<mn){
            ans2=0; mn=D-k;
            dp=k; ans2=d;
         }

         int x,y,w;
         if(i!=0 && j!=b){
            if(b-j>=i){x=0; y=j+i; w=i;}
            else{x=i-(b-j); y=b;w=b-j;}

            if(dist[x][y][k]>dist[i][j][k]+w){
               dist[x][y][k]=dist[i][j][k]+w;
               q.push({dist[x][y][k],{{x,y},k}});
            }
         }
         if(i!=0 && k!=c){
            if(c-k>=i){x=0; y=k+i; w=i;}
            else{x=i-(c-k); y=c;w=c-k;}

            if(dist[x][j][y]>dist[i][j][k]+w){
               dist[x][j][y]=dist[i][j][k]+w;
               q.push({dist[x][j][y],{{x,j},y}});
            }
         }

         if(j!=0 && i!=a){
            if(a-i>=j){x=0; y=i+j; w=j;}
            else{x=j-(a-i); y=a; w=a-i;}

            if(dist[y][x][k]>dist[i][j][k]+w){
               dist[y][x][k]=dist[i][j][k]+w;
               q.push({dist[y][x][k],{{y,x},k}});
            }
         }
         if(j!=0 && k!=c){
            if(c-k>=j){x=0; y=k+j; w=j;}
            else{x=j-(c-k); y=c; w=c-k;}

            if(dist[i][x][y]>dist[i][j][k]+w){
               dist[i][x][y]=dist[i][j][k]+w;
               q.push({dist[i][x][y],{{i,x},y}});
            }
         }

         if(k!=0 &&i!=a){
            if(a-i>=k){x=0; y=i+k; w=k;}
            else{x=k-(a-i); y=a; w=a-i;}

            if(dist[y][j][x]>dist[i][j][k]+w){
               dist[y][j][x]=dist[i][j][k]+w;
               q.push({dist[y][j][x],{{y,j},x}});
            }
         }

         if(k!=0 && j!=b){
            if(b-j>=k){x=0; y=j+k; w=k;}
            else{x=k-(b-j); y=b; w=b-j;}
            if(dist[i][y][x]>dist[i][j][k]+w){
               dist[i][y][x]=dist[i][j][k]+w;
               q.push({dist[i][y][x],{{i,y},x}});
            }
         }
      }

      if(ans!=-1) cout << ans << ' ' << D << endl;
      else cout << ans2 << ' ' << dp << endl;

   }

   return 0;
}


