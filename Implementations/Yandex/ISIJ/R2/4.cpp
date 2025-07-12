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
   /*freopen("schools.in", "r", stdin);
   freopen("schools.out", "w", stdout);*/
   int N; cin>>N; cin.ignore();
   //map <str,int> mp;
   map <int,int> mp;
   for(int i=0; i<N; i++){
      //str x;
      int x=0;
      str s; getline(cin,s);
      for(int j=0; j<sz(s); j++){
         if(s[j]>='0' && s[j]<='9') {
            /*while(s[j]>='0' && s[j]<='9'){
               //if(s[j]=='0' && x.empty()) continue;
               x+=s[j];
               j++;
            }*/
            x*=10;
            x+=s[j]-'0';
            /*j--;
         break;*/
         }
      }
      //if(x.empty()) continue;
      if(!mp.count(x))mp[x]=1;
      else mp[x]++;
   }
   int nb=0;
   vi vec;
   for(auto y: mp){
      if(y.se>=1&& y.se<=5){
         nb++;
         vec.pb(y.fi);
      }
   }
   cout << nb << endl;
   reverse(all(vec));
   for(int i=0; i<sz(vec); i++){
   	/*str x=vec[i];
      for(int i=0; i<sz(x); i++) cout << x[i]-'0';*/
      cout << vec[i] << endl;
      //if(i!=sz(vec)-1)cout << endl;
   }



   return 0;
}

