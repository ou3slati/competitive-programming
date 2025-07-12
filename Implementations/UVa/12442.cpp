#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

typedef pair<int,int> pi;
#define mp make_pair
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

const int MOD = 1e9+7;
const ll INF = 1e18;

const int nx[4]={-1,0,1,0}, ny[4]={0,1,0,-1}; //N E S W

int g[50001];
bool vis[50001];
int memo[50001];
bool c;
int ind;
int N;

int solve(int x){
   if(!g[x]) return 1;
   if(vis[x]) {c=true; ind=x; return 0;}
   vis[x]=true;
   if(memo[x]!=-1) return memo[x];
   return memo[x]=solve(g[x])+1;
}
int solve2(int x){
   //if(!g[x]) return 1;
   if(vis[x])return 0;
   vis[x]=true;
   //if(memo[x]!=-1) return memo[x];
   return solve2(g[x])+1;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   int nb=0;
   while(TC--){
      memset(memo,-1,sizeof(memo)); memset(g,0,sizeof(g));
      cin>>N;
      for (int n=1; n<=N; n++){int x,y; cin>>x>>y; g[x]=y;}

      int mx=-1, idx=-1;
      for (int i=1; i<=N; i++){
         memset(vis,false,sizeof(vis));
         c=false; ind=-1;
         int x=solve(i);
         //cout <<x <<endl;
         if(x>mx){
            mx=x;
            idx=i;
         }
         if(c){
            memset(vis,0,sizeof(vis));
            int y=solve2(ind);
            //cout << ind << endl;
            for (int j=1; j<=N; j++) if(vis[j]){memo[j]=y;}

            //cout <<y<<'e'<<endl;
         }
      }
      //cout << "                                                ";
      cout << "Case "<<++nb<<": "<<idx<<endl;

   }

}
