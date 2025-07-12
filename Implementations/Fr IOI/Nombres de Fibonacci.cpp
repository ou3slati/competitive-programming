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

int res[94];

void sum(int x, int y){
   int t[21]; for(int i=0;i<21; i++) t[i]=0;
   for(int i=20; i>=1 && (x||y); i--){
      t[i-1]=(x%10+y%10+t[i])/10;
      t[i]=(x%10+y%10+t[i])%10;
      x/=10; y/=10;
   }
   for(int i=1; i<=20; i++) cout << t[i];
}

void f(int N){
   res[0]=0; res[1]=1;
   int x=0,y=1;
   for(int i=2; i<=min(N,(ll)92);i++){
      int xx=x;
      x=y;
      y+=xx;
      res[i]=y;
   }
}

int32_t main(){
   boost;
   int N; cin>>N;
   f(N);
   if(N<=92) cout << res[N] << endl;
   else sum(res[92],res[91]);

   return 0;
}

