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

bool check(int x, int l){
   str s=to_string(x);
   if(sz(s)!=l) return false;
   for(int i=1; i<l; i++) if(s[i]==s[i-1]) return false;
   return true;
}

int32_t main(){
   boost;
   ofstream cout ("aplusb.out");
   ifstream cin ("aplusb.in");

   int C; cin>>C;
   int l=(int)(log10(C)+1);
   //cout << l;
   int res=0;
   for(int i=(int)(pow(10,l-1)+0.5); i<=C; i++){
      int y=C-i;

      if(check(y,l) && check(i,l))  res++;
   }
   cout << res << endl;


   return 0;
}

