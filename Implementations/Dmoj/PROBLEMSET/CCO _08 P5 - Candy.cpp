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

const int MX=1e6*5+5;
int N;
int t[110],v[110];
int dp[MX];
int cnt[MX];
int s=0;

int32_t main(){
   boost;
   cin>>N;

   for(int i=0; i<N; i++){
      cin>>t[i]>>v[i];
      s+=v[i]*t[i];
   }
   memset(dp,0,sizeof(dp));
   dp[0]=1;

   int x=0;

   for(int i=0; i<N; i++){
      for(int j=0; j<=s/2; j++) cnt[j]=0;
      if(x==s/2) break;
      for(int j=v[i]; j<=s/2; j++){
         if(dp[j]) continue;
         if(!dp[j-v[i]]||cnt[j-v[i]]>=t[i]) continue;
         dp[j]=1;
         x=max(x,j);
         cnt[j]=cnt[j-v[i]]+1;
      }
   }

   cout << s-2*x << endl;

   return 0;
}


