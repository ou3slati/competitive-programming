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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

vi res;
int p[22][22][22];

void output(int i, int j,int l){
   if(l>=0) output(i,p[i][j][l],l-1);
   res.pb(j);
}

int32_t main(){
   boost;
   int V;
   while(cin>>V){
      db adj[V][V][V];

      for(int i=0; i<V; i++)
         for(int j=0; j<V; j++)
            for(int l=0;l<V; l++){
                  adj[i][j][l]=0; p[i][j][0]=i;
            }

      for(int i=0; i<V; i++){
         for(int j=0; j<V; j++){
            if(i==j){adj[i][j][0]=1.0; continue;}
            cin>>adj[i][j][0];
         }
      }

      for(int l=1; l<V; l++) for(int k=0; k<V; k++) for(int i=0; i<V; i++) for(int j=0; j<V; j++){
         if(adj[i][j][l]<adj[i][k][l-1]*adj[k][j][0]){
            adj[i][j][l]=adj[i][k][l-1]*adj[k][j][0];
            p[i][j][l]=k;
         }
      }

      bool done=false;
      for(int l=1; l<V && !done; l++) for(int i=0; i<V && !done; i++){
         if(adj[i][i][l]>1.01){
            res.clear();
            output(i,i,l);
            for(int j=0; j<sz(res); j++){
               cout << res[j]+1; if(j!=sz(res)-1) cout << ' ';
            }
            cout << endl;
            done=true;
         }
      }
      if(!done) cout <<"no arbitrage sequence exists" << endl;
   }

   return 0;
}

