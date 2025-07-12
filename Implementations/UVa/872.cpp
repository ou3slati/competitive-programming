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
//#define mp make_pair
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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};


vi adj[26];
int ind[26];
int N;
map <char,int> mp;
map<int,char> mp2;
vs ans; vi topo;

int vis[26];
bool cycle;
void check(int u){
   vis[u]=1;
   for (auto x: adj[u]){
      if(!vis[x]) check(x);
      else if(vis[x]==1){cycle=true; return;}
   }
   vis[u]=2;
}

void dfs(){
   int done=false;
   for (int i=0; i<N; i++) if(!vis[i] && ind[i]==0){
      done=true;
      vis[i]=true;
      topo.pb(i);
      for (auto x: adj[i]) ind[x]--;
      dfs();
      topo.pop_back();
      vis[i]=false;
      for(auto x:adj[i]) ind[x]++;
   }
   if(!done){
      string s;
      for (int i=0; i<sz(topo); i++) s+=mp2[topo[i]];
      ans.pb(s);
   }
}

int32_t main(){
   boost;
   int TC; cin>>TC; cin.ignore();
   string s;
   while(TC--){
      memset(ind,0,sizeof(ind)); mp.clear(); ans.clear();
      for (int i=0; i<26; i++) adj[i].clear();

      getline(cin,s);
      getline(cin,s);
      int c=0;
      for (int i=0; i<sz(s); i++)
         if(s[i]>='A' && s[i]<='Z'){
            mp[s[i]]=c;
            mp2[c]=s[i];
            c++;
         }
      N=c;

      getline(cin,s);
      for (int i=0; i<sz(s); i+=4){
         adj[mp[s[i]]].pb(mp[s[i+2]]);
         ind[mp[s[i+2]]]++;
      }

      memset(vis,0,sizeof(vis));
      int u=-1;
      for (int i=0; i<N; i++) if(mp2.count(i) && ind[i]==0){
         u=i;
         break;
      }
      cycle=false;
      if(u!=-1) check(u);
      if(cycle ||u==-1){
         cout <<"NO" << endl;
         continue;
      }

      memset(vis,0,sizeof(vis));
      dfs();
      sort(all(ans));
      for (int i=0; i<sz(ans); i++){
         string s=ans[i];
         for (int j=0; j<sz(s); j++){
            cout << s[j];
            if(j!=sz(s)-1) cout << ' ';
         }
         cout << endl;
      }
      if(TC)cout << endl;

   }
   return 0;
}

