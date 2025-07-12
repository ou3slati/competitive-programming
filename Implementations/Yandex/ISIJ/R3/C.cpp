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
   /*ofstream cout ("search.out");
   ifstream cin ("search.in");*/

	int N,P;cin>>N>>P;
	multiset <str> st;

	str t[N];
	for(int i=0; i<N; i++) {cin>>t[i]; st.insert(t[i]);}

   int K; cin>>K;
   int cnt[K];

	for(int i=0; i<K; i++){
      str ss; cin>>ss;
      if(N<=1000){
      int ans=0;
      for(int j=0; j<N; j++){
         str s=t[j];

         if(s[0]!='*' && s[sz(s)-1]!='*' && s==ss){ans++; }
         else if(s[0]!='*' && s[sz(s)-1]=='*'){
            bool y=true;
            if(sz(s)-2>sz(ss)) y=false;
            else for(int k=0; k<sz(s)-2; k++) if(s[k]!=ss[k]){y=false; break;}
            if(y)ans++;

         }
         else if(s[0]=='*' && s[sz(s)-1]!='*'){
            bool y=true;
            if(sz(s)-2>sz(ss)) y=false;
            else{
               for(int k=2; k<sz(s); k++) if(s[k]!=ss[sz(ss)-sz(s)+k]){y=false; break;}
            }
            if(y)ans++;

         }
         }}
         else if(s[0]=='*' && s[sz(s)-1]=='*'){
            s.pop_back(); s.pop_back();
            s.erase(s.begin()); s.erase(s.begin());
            if(ss.find(s)!= string::npos) ans++;
            //cout << 3 << endl;
         }


      cnt[i]=ans;
      cout << ans<< endl; //cout << endl;
      }
      else{
         cout << st.count(ss) << endl;

      }
	}

	//for(int i=0; i<K; i++) cout << cnt[i] << endl;


   return 0;
}

