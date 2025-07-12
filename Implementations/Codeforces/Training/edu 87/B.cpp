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
   int TC; cin>>TC;
   while(TC--){
      string s; cin>>s;

      int i=0,j=0;
      multiset <int>st;
      int ans=INF;

      while(i<sz(s)){
         while(i<sz(s) && !(st.count(1)&&st.count(2)&&st.count(3))){
            st.insert(s[i]-'0');
            i++;
         }
         while(st.count(1)&&st.count(2)&&st.count(3)){
            ans=min(ans,i-j);
            st.erase(st.find(s[j]-'0'));
            j++;
         }

      }

      if(ans==INF)cout<<0 << endl;
      else cout << ans << endl;
   }


   return 0;
}

