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

const int MXN=2500;

int N,K;
int memo[MXN][MXN];

int ans[MXN];
int t[MXN];

map<string,int> mp;
vpi vec[12];

bool can(int i, int k){
   //cout <<t[i] << ' '<< i << ' ' << k << endl;
   if(k<0) return false;
   if(i==N && k==0) return true;
   if(i==N) return false;

   if(memo[i][k]!=-1){if(memo[i][k]==1) return true; return false;}
   bool yes=false;
   for (int j=0; j<sz(vec[t[i]]); j++) if(can(i+1,k-vec[t[i]][j].se)){
      yes=true;
      break;
   }
   if(yes) memo[i][k]=1;
   else memo[i][k]=0;
   return yes;
}

int32_t main(){
   boost;
   memset(t,-1,MXN);
   memset(memo,-1,sizeof(memo));

   mp["1110111"]=0; mp["0010010"]=1; mp["1011101"]=2; mp["1011011"]=3;
   mp["0111010"]=4; mp["1101011"]=5; mp["1101111"]=6;
   mp["1010010"]=7; mp["1111111"]=8; mp["1111011"]=9;
   mp["0000000"]=10;

   vec[0].pb({0,0}); vec[0].pb({8,1});
   vec[1].pb({1,0}); vec[1].pb({3,3}); vec[1].pb({4,2}); vec[1].pb({7,1}); vec[1].pb({8,5}); vec[1].pb({9,4});
   vec[2].pb({2,0}); vec[2].pb({8,2});
   vec[3].pb({3,0}); vec[3].pb({8,2}); vec[3].pb({9,1});
   vec[4].pb({4,0}); vec[4].pb({8,3}); vec[4].pb({9,2});
   vec[5].pb({5,0}); vec[5].pb({6,1}); vec[5].pb({8,2}); vec[5].pb({9,1});
   vec[6].pb({6,0}); vec[0].pb({8,1});
   vec[7].pb({7,0}); vec[7].pb({0,2}); vec[7].pb({3,2}); vec[7].pb({8,4}); vec[7].pb({9,3});
   vec[8].pb({8,0});
   vec[9].pb({9,0}); vec[9].pb({8,1});
   vec[10].pb({0,6}); vec[10].pb({1,2}); vec[10].pb({2,5}); vec[10].pb({3,5}); vec[10].pb({4,4});
   vec[10].pb({5,5}); vec[10].pb({6,5}); vec[10].pb({7,3}); vec[10].pb({8,7}); vec[10].pb({9,6});
   for (int i=0; i<=9;i++) sort(vec[i].rbegin(),vec[i].rend());

   /*for (int i=0; i<sz(vec[1]); i++) cout << vec[1][i].fi << ' ';
   cout << endl;*/

   cin>>N>>K;
   for (int i=0; i<N; i++){
      string s; cin>>s;
      t[i]=mp[s];
   }
   bool yes=false;

   for (int i=0; i<sz(vec[t[0]]); i++){
      if(can(1,K-vec[t[0]][i].se)){
         ans[0]=vec[t[0]][i].fi;
         K-=vec[t[0]][i].se;
         yes=true; break;
      }
      //cout << endl;
   }

   //cout << K << endl;
   if(!yes){cout << -1<< endl; return 0;}
   for (int i=1; i<N;i++){
      for (int j=0; j<sz(vec[t[i]]); j++) if(can(i+1,K-vec[t[i]][j].se)){
         ans[i]=vec[t[i]][j].fi;
         K-=vec[t[i]][j].se;
         break;
      }
   }

   for (int i=0; i<N;i++) cout << ans[i];
   cout << endl;

   return 0;
}

