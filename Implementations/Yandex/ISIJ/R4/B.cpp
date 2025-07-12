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

const int MX=1e5+10;
vi bit(MX,0),bit2(MX,0);
int N;

int lsb(int i){return i&-i;}
void update(int idx, int v){
   while(idx<MX){
      bit[idx]+=v;
      idx+=lsb(idx);
   }
}
void update2(int idx, int v){
   while(idx<MX){
      bit2[idx]+=v;
      idx+=lsb(idx);
   }
}

int getSum(int idx){
   int ans=0;
   while(idx>0){
      ans+=bit[idx];
      idx-=lsb(idx);
   }
   return ans;
}
int getSum2(int idx){
   int ans=0;
   while(idx>0){
      ans+=bit2[idx];
      idx-=lsb(idx);
   }
   return ans;
}

int32_t main(){
   boost;
   /*freopen("river.in", "r", stdin);
   freopen("river.out", "w", stdout);*/
   cin>>N;
   int mx=0;
   for(int i=0; i<N;i++){
      int h; cin>>h;
      update(1,1);
      update(h+1,-1);
      mx=max(mx,h);
   }

   int res=0;
   for(int h=mx; h>=1; h--){
      int x=getSum(h);
      update(1,-x);
      update(h+1,x);

      update2(1,x);
      update2(h+1,-x);
   }

   for(int h=1; h<=mx; h++){
      int x=getSum2(h);
      res+=((x-1)*x)/2;
   }

   cout << res << endl;



   return 0;
}

