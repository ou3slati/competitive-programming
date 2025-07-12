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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N,K; cin>>N>>K;
   str s;
   cin>>s;

   map <pair<char,int>,int> mp;
   int pref[3][N+1];
   memset(pref,0,sizeof(pref));

   for(int i=1; i<=N; i++){
      pref[0][i]+=pref[0][i-1]; pref[1][i]+=pref[1][i-1]; pref[2][i]+=pref[2][i-1];
      if(s[i-1]=='J') pref[0][i]++;
      else if(s[i-1]=='O') pref[1][i]++;
      else pref[2][i]++;
   }

   int cnt=0;
   for(int i=0; i<N;i++) if(s[i]=='J') mp[{s[i],++cnt}]=i;
   cnt=0; for(int i=0; i<N;i++) if(s[i]=='O') mp[{s[i],++cnt}]=i;
   cnt=0; for(int i=0; i<N;i++) if(s[i]=='I') mp[{s[i],++cnt}]=i;

	int res=INF;
	for(int i=0;i<N; i++) if(s[i]=='J'){
      int ans=0;
      int l=i,r;


      if(mp.count({'J',pref[0][l+1]+K-1})){
         r=mp[{'J',pref[0][l+1]+K-1}];
         ans+=pref[1][r+1]-pref[1][l]+pref[2][r+1]-pref[2][l];
         l=r;
      } else continue;

      if(pref[1][N]-pref[1][l+1]==0) continue;
      r=mp[{'O',pref[1][l+1]+1}];
      ans+=pref[0][r+1]-pref[0][l+1]+pref[2][r+1]-pref[2][l+1];
      l=r;

      if(mp.count({'O',pref[1][l+1]+K-1})){
         r=mp[{'O',pref[1][l+1]+K-1}];
         ans+=pref[0][r+1]-pref[0][l]+pref[2][r+1]-pref[2][l];
         l=r;
      } else continue;

      if(pref[2][N]-pref[2][l+1]==0) continue;
      r=mp[{'I',pref[2][l+1]+1}];
      ans+=pref[0][r+1]-pref[0][l+1]+pref[1][r+1]-pref[1][l+1];
      l=r;

      if(mp.count({'I',pref[2][l+1]+K-1})){
         r=mp[{'I',pref[2][l+1]+K-1}];
         ans+=pref[0][r+1]-pref[0][l]+pref[1][r+1]-pref[1][l];
         l=r;
      } else continue;

      res=min(ans,res);
	}

	if(res==INF) cout << -1 << endl;
	else cout << res << endl;

   return 0;
}

