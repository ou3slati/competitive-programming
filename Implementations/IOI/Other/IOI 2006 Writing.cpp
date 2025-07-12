#pragma GCC optimize("O3")
#include <bits/stdc++.h>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;*/
using namespace std;

/*template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
//s.order_of_key(), *s.find_by_order()

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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

int main(){
   boost;

	unordered_map<char,int> mp,cnt;
	for(char c='a'; c<='z'; c++) mp[c]=cnt[c]=0;
	for(char c='A'; c<='Z'; c++) mp[c]=cnt[c]=0;

	int N,M; cin>>N>>M;
	string s,ss; cin>>s>>ss;

	for(int i=0; i<N; i++) mp[s[i]]++;
	for(int i=0; i<N-1; i++) cnt[ss[i]]++;

	int i=0;
	int ans=0;
	for(int j=N-1; j<M; j++){
      cnt[ss[j]]++;
      bool y=true;
      for(char c='a'; c<='z'; c++) if(mp[c]!=cnt[c]){
         y=false;
         break;
      }
      for(char c='A'; c<='Z'; c++)if(mp[c]!=cnt[c]){
         y=false;
         break;
      }

      if(y) ans++;
      cnt[ss[i]]--;
      i++;
	}
	cout << ans << endl;

   return 0;
}

