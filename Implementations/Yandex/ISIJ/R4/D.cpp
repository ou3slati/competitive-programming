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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

int32_t main(){
   boost;
	/*freopen("river.in", "r", stdin);
   freopen("river.out", "w", stdout);*/
   int N,M; cin>>N>>M;
   str s,ss; cin>>s>>ss;
   //unordered_map<char,int> mp,mp2;
   int mp[52],mp2[52];
   for(char c='a'; c<='z'; c++) mp[c-'a']=mp2[c-'a']=0;
   for(char c='A'; c<='Z'; c++) mp[c-'A'+26]=mp2[c-'A'+26]=0;
   for(int i=0; i<N; i++){
      if(s[i]>='a' && s[i]<='z') mp[s[i]-'a']++;
      else mp[s[i]-'A'+26]++;
   }
   int res=0;
   for(int i=0;i<M; i++){
      if(ss[i]>='a' && ss[i]<='z') mp2[ss[i]-'a']++;
      else mp2[ss[i]-'A'+26]++;
      if(i>=N-1){
         bool y=true;
         for(char c='a'; c<='z'; c++) if(mp[c-'a']!=mp2[c-'a']) y=false;
         for(char c='A'; c<='Z'; c++) if(mp[c-'A'+26]!=mp2[c-'A'+26]) y=false;
         if(y) res++;
         if(ss[i-N+1]>='a' && ss[i-N+1]<='z') mp2[ss[i-N+1]-'a']--;
         else mp2[ss[i-N+1]-'A'+26]--;
      }
   }
   cout << res << endl;

   return 0;
}

