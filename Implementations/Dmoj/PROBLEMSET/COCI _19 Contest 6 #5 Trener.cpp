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

int N,K;
map<pi,int> memo;
vi adj[52][1510];


int solve(int i, int j){
   if(i==N-1) return 1;

   if(memo.count({i,j})) return memo[{i,j}];
   int ans=0;
   for(auto x: adj[i][j]) ans=(ans+solve(i+1,x))%MOD;
   return memo[{i,j}]=ans;
}


int32_t main(){
   boost;
    //memset(memo,-1,sizeof(memo));
    cin>>N>>K;
    map <string,vi> mp;

    string s,str,str2;

    for(int i=0; i<N; i++){
      for(int k=0; k<K; k++){
         cin>>s;
         mp[s].pb(k);
         //if(mp.count(s)) cout << s <<"yes" << endl;

         str=s.substr(0,i); //cout << str << endl;
         str2=s.substr(1,i); //cout << str2 << endl;

         set <int> st;
         if(mp.count(str))for(auto x: mp[str]){adj[i-1][x].pb(k); st.insert(x);}

         if (mp.count(str2)){for(auto x: mp[str2]) if(st.count(x)==0)adj[i-1][x].pb(k); }
          //for(int j=0; j<K && !vec.empty(); j++) if(vec[j]==str||vec[j]==str2) adj[i-1][j].pb(k);
      }
    }


    /*for(int i=0; i<N-1; i++)
      for(int j=0; j<K; j++)
         for(int k=0;k<K; k++)
            if(g[i][j]==g2[i+1][k].fi || g[i][j]==g2[i+1][k].se) adj[i][j].pb(k);*/

    int ans=0;
    for(int i=0;i<K; i++) ans=(ans+solve(0,i))%MOD;
    cout << ans << endl;


   return 0;
}

