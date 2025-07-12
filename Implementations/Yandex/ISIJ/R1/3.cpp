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
   ofstream cout ("forest.out");
   ifstream cin ("forest.in");
   int A,K,B,M,X; cin>>A>>K>>B>>M>>X;
   int l=1,r=X*2;
   while(l<r){
      int m=(l+r)/2;
      int x=(m/K)*A*(K-1)+A*(m%K)  + (m/M)*B*(M-1)+B*(m%M);
      //cout << m << ' ' << x << endl;
      if(x>=X) r=m;
      else l=m+1;
   }
	cout << l << endl;

   return 0;
}
//5 1000 7 1000 8

