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

int32_t main(){
   boost;
   int N;
   while(cin>>N,N){
      int adj[26][26],adj2[26][26];
      for(int i=0; i<26; i++) for(int j=0; j<26; j++){
         if(i==j) adj[i][j]=adj2[i][j]=0;
         else adj[i][j]=adj2[i][j]=INF;
      }
      for(int i=0; i<N; i++){
         char c,d,u,v; int w;
         cin>>c>>d>>u>>v>>w;
         if(c=='Y'){
            adj[u-'A'][v-'A']=min(w,adj[u-'A'][v-'A']);
            if(d=='B') adj[v-'A'][u-'A']=min(w,adj[v-'A'][u-'A']);
         }
         else{
            adj2[u-'A'][v-'A']=min(w,adj2[u-'A'][v-'A']);
            if(d=='B') adj2[v-'A'][u-'A']=min(w,adj2[v-'A'][u-'A']);
         }
      }
      int st,st2;
      char c; cin>>c; st=c-'A'; cin>>c; st2=c-'A';

      for(int k=0; k<26; k++) for(int i=0; i<26; i++) for(int j=0; j<26; j++){
         adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
         adj2[i][j]=min(adj2[i][j],adj2[i][k]+adj2[k][j]);
      }

      vi res;
      int mn=INF;
      for(int i=0; i<26; i++){
         if(adj[st][i]+adj2[st2][i]<mn){
            res.clear();
            mn=adj[st][i]+adj2[st2][i];
            res.pb(i);
         }
         else if(adj[st][i]+adj2[st2][i]==mn) res.pb(i);
      }
      if(mn==INF)cout << "You will never meet." << endl;
      else{
         cout<< mn;
         for(int i=0; i<sz(res); i++) cout << ' ' << (char)('A'+res[i]);
         cout << endl;
      }
      //cout << endl << endl;

   }


   return 0;
}

