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
const int nx[8]={-1,-1,0,1,1,1,0,-1}, ny[8]={0,1,1,1,0,-1,-1,-1};

vs vec;
vs found;
vs expec[9];
char g[4][4];
int sc; string lg; int f;

void solve(bool vis[4][4], int i, int j, string s){

   if(s.length()>8) return;
   auto it=lower_bound(all(expec[sz(s)]),s)-expec[sz(s)].begin();
   if((it==sz(expec[sz(s)]) ||expec[sz(s)][it]!=s) && !s.empty()) return;
   auto itt=lower_bound(all(vec),s);
   auto itr=lower_bound(all(found),s);
   if(itt!=vec.end() && vec[itt-vec.begin()]==s && (itr==found.end() || found[itr-found.begin()]!=s)){
      found.insert(itr,s);
      if(sz(s)>sz(lg)) lg=s;
      else if(sz(s)==sz(lg) && s<lg) lg=s;
      f++;
      int l=sz(s); if(l==3 || l==4) sc++; else if(l==5) sc+=2; else if(l==6) sc+=3; else if(l==7) sc+=5; else if(l==8) sc+=11;
   }


   for (int m=0; m<8; m++){
      int nwi=i+nx[m], nwj=j+ny[m];
      if(nwi>=0 && nwj>=0 && nwi<4&&nwj<4 && !vis[nwi][nwj]){
         vis[nwi][nwj]=true;
         solve(vis,nwi,nwj,s+g[nwi][nwj]);
         vis[nwi][nwj]=false;
      }

   }
}

int32_t main(){
   boost;

   int n; cin>>n;
   for (int i=0; i<n; i++){
      string s; cin >>s;
      string ss;
      for (int j=0;j<sz(s);j++){
         ss+=s[j];
         expec[sz(ss)].pb(ss);
      }
      vec.pb(s);
   }
   for (int i=1; i<=8; i++) sort(all(expec[i]));
   sort(all(vec));
   int TC; cin >>TC;
   while(TC--){
      sc=0; f=0; lg.clear(); found.clear();

      for (int i=0; i<4; i++) for (int j=0; j<4; j++) cin>>g[i][j];
      bool vis[4][4]={false};
      string s;
      for (int i=0; i<4; i++) for (int j=0; j<4; j++) solve(vis,i,j,s);
      cout << sc << ' ' << lg << ' ' << f << endl;

   }


}
/*
5
TOP
CONTEST
PROGRAMM
GOOD
LUCK

2
TOPA
APCA
TOGI
NEST

LUOP
CKTR
ABOG
MMAR
*/
