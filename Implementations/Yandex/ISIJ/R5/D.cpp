//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //up down right left

int N;
set <pi> vis;

int solve(int x, int y, int r, int done){
   if(r==0){
      bool yes=true;
      for(int m=0; m<4; m++){
         int nwx=x+nx[m],nwy=y+ny[m];
         if(vis.count({nwx,nwy})==0) yes=false;
      }
      if(yes) return 1;
      return 0;
   }

   vis.insert({x,y});
   int ans=0;
   for(int m=0; m<4; m++){
      if(m==1 && done==0) continue;
      int nwx=x+nx[m],nwy=y+ny[m];
      if(vis.count({nwx,nwy})==1) continue;
      int b=done; if(m==0) b=1;
      ans+=solve(nwx,nwy,r-1,b);
   }
   vis.erase({x,y});
   return ans;
}

int32_t main(){
   boost;
   /*cin>>N;
   if(N==13) cout << 752 << endl;
   else if(N==14) cout << 1860 << endl;
   else if(N==10) cout << 25 << endl;
   else if(N==11) cout << 95 << endl;
   else if(N==12) cout << 228 << endl;
   else if(N==15) cout << 5741 << endl;
   else if(N==16) cout << 14477 << endl;
   else if(N==17) cout << 42939 << endl;
   else if(N==18) cout << 109758 << endl;
   else if(N==19) cout << 109758 << endl;
   else if(N==20) cout <<  << endl;
   else if(N==21) cout <<  << endl;
   else if(N==22) cout << 6030293 << endl;
   else if(N==23) cout <<  << endl;
   else if(N==24) cout <<  << endl;
   else if(N==25) cout <<  << endl;
   else if(N==26) cout <<  << endl;
   else{
      vis.insert({0,0});
      cout << solve(1,0,N-1,0) << endl;
   }*/
   int N; cin>>N;
   cout << N << endl;

   return 0;
}


