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
typedef pair<str,str> ps;
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

int32_t main(){
   boost;
   int E;
   int tc=0;
   while(cin>>E,E){
      int adj[300][300];
      for(int i=0; i<300; i++) for(int j=0; j<300; j++){
         adj[i][j]=0;
         if(i==j) adj[i][j]=1;
      }

      map <string ,int> mp;
      map <int, str> mp2;
      int cnt=0;

      for(int i=0; i<E; i++){
         int N;cin>>N;
         string s,ss;cin>>s;
         if(!mp.count(s)){
            mp2[cnt]=s;
            mp[s]=cnt++;
         }
         for(int j=0; j<N-1; j++){
            cin>>ss;
            if(!mp.count(ss)){
               mp2[cnt]=ss;
               mp[ss]=cnt++;
            }
            int u=mp[s],v=mp[ss];
            adj[u][v]=1;
            s=ss;
         }
      }

      int N;cin>>N;
      for(int i=0; i<N; i++){
         string s,ss;cin>>s>>ss;
         int u=mp[s],v=mp[ss];
         adj[u][v]=1;
      }

      for(int k=0; k<cnt; k++)for(int i=0; i<cnt; i++) for(int j=0; j<cnt; j++)
         adj[i][j]|= (adj[i][k]&adj[k][j]);

      vector<ps> res;
      for(int i=0; i<cnt; i++) for(int j=i+1; j<cnt; j++) if(!adj[i][j] && !adj[j][i])
         res.pb({mp2[i],mp2[j]});

      cout << "Case " << ++tc << ", " ;
      if(res.empty()) cout << "no concurrent events." << endl;
      else{
         cout << sz(res)<<" concurrent events:" << endl;
         cout << '('<<res[0].fi <<','<<res[0].se<<')' << ' ';
         if(sz(res)>1) cout <<'('<<res[1].fi <<','<<res[1].se <<')' << ' ';
         cout << endl;
      }
      //cout << endl;
   }

   return 0;
}

