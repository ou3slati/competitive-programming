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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      int t[N];
      int h[20001]={0};
      vi rep;
      int res=-1;
      int mx=0;
      for (int i=0;i<N; i++){
         cin>>t[i];
         mx=max(mx,t[i]);
         h[t[i]]++;
         if(h[t[i]]==2) rep.pb(t[i]);
         if(h[t[i]]>2) res=0;
      }
      sort(all(rep));
      bool y=true;
      for (int i=0; i<sz(rep)-1; i++) if(rep[i+1]-rep[i]>1) {
         y=false; break;
      }
      if(rep[0]!=1) y=false;
      if(!y){cout <<0 << endl; continue;}

      if(res==0){cout <<0 << endl; continue;}
      y=false;
      for (int i=1; i<=mx; i++) if(h[i]==0){
         y=true;
         break;
      }
      if(y){cout <<0 << endl; continue;}

      res=0;
      set <int> vis;
      bool d=false, g=false;
      for(int i=0; i<sz(rep); i++){
         if(h[t[i]]==1) break;
         if(vis.count(t[i])==1) break;
         vis.insert(t[i]);
         if(i==sz(rep)-1){res=1; d=true;}
      }
      vis.clear();
      for(int i=N-1; i>=N-sz(rep) ; i--){
         if(h[t[i]]==1) break;
         if(vis.count(t[i])==1) break;
         vis.insert(t[i]);
         if(i==N-sz(rep)){ g=true; res++;}
      }
      cout << res << endl;
      if(res==2 || (res==1&&sz(rep)==N-sz(rep)) ) cout << sz(rep) << ' ' << N-sz(rep) << endl << N-sz(rep)<<' ' << sz(rep)<< endl;
      else if(res==1) {
         if(d)cout << sz(rep)<< ' ' << N-sz(rep) << endl;
         else cout << N-sz(rep)<<' ' << sz(rep)<< endl;
      }
      //cout << endl;
   }

}

