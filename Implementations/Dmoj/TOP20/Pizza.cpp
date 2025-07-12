#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
//typedef long long ll;
#define int long long
typedef double db;
typedef long double ldb;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
//typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pair<string,string>> vps;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7;
//const ll INF = 1e18;
const int nx[8]={-1,-1,0,1,1,1,0,-1}, ny[8]={0,1,1,1,0,-1,-1,-1};


int32_t main(){
   boost;

   int TC; cin>>TC;
   while(TC--){
         map<string,int> vis;
      int N;cin>>N;
      vs l[N]; vs ll[N];

      for (int n=0; n<N; n++){
         string ss; cin>>ss;
         int xx; cin>>xx;
         for (int i=0; i<xx; i++){string s; cin>>s; l[n].pb(s); vis[s]=0; }
         cin>>xx;
         for (int i=0; i<xx; i++){string s; cin>>s; ll[n].pb(s); }
      }


      vps res;

     for (int i=0; i<N; i++) for (int j=0; j<sz(l[i]); j++){
         string s=l[i][j];
         if(!vis[s]){
            vis[s]=1;
            vs names;

            for (int n=0; n<ll[i].size(); n++) names.pb(ll[i][n]);

            for (int p=i+1; p<N; i++){
               if(find(all(l[p]), s)!=l[p].end()){ //name found
                  for (int n=0; n<names.size(); n++){
                     string o=names[n];
                     if( find(all(ll[p]), o) == ll[p].end()  ){names.erase(names.begin()+n); n--;}
                  }
               }
               else{//not found
                  for (int n=0; n<ll[p].size(); n++){
                     auto it=find(all(names), ll[p][i]);
                     if(it!=names.end()) names.erase(it);
                  }

               }
            }

            for (int r=0; r<sz(names); r++) res.pb({s,names[r]});


         }
     }


     sort(all(res));
     for (int i=0; i<sz(res); i++) cout << '(' <<res[i].fi << ", " << res[i].se << ')'<< endl;
      cout << endl;





   }



}
