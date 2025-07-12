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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MX=1e5;
int A,B,C,D,s,e;
bool vis[MX+1];

void solve(int i){
   vis[i]=true;
   if(i==e) return;

   if(i*C<=MX && !vis[i*C]) solve(i*C);
   if(D!=0 && i%D==0 && !vis[i/D]) solve(i/D);
   if(i+A<=MX && !vis[i+A]) solve(i+A);
   if(i-B>=0 && !vis[i-B]) solve(i-B);

}

int32_t main(){
   boost;
   cin>>A>>B>>C>>D;
   cin>>s>>e;

   for(int i=0; i<=MX; i++) vis[i]=0;
   solve(s);
   if(vis[e]) cout <<1 << endl;
   else cout << 0 << endl;

   return 0;
}

