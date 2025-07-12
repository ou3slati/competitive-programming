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

//const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

const int MX=2e5+10;
vi bit(MX,0),bit2(MX,0);

int lsb(int i){return i&-i;}

void update(int idx, int x){
   while(idx<MX){
      bit[idx]+=x;
      idx+=lsb(idx);
   }
}
void update2(int idx, int x){
   while(idx<MX){
      bit2[idx]+=x;
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
   int MOD; cin>>MOD;
   int N,Q; cin>>N>>Q;
   for(int i=1; i<=N; i++){
      int x; cin>>x;
      update(i,x);
      update(i+1,-x);
      update2(i,(i-1)*x);
      update2(i+1,-x*i);
   }

   while(Q--){
      int t,l,r; cin>>t>>l>>r;
      if(t==1){
         int x; cin>>x;
         update(l,x);
         update(r+1,-x);
         update2(l,(l-1)*x);
         update2(r+1,-x*r);
      }
      else{
         cout << (getSum(r)*r-getSum2(r)-(getSum(l-1)*(l-1)-getSum2(l-1)))%MOD << endl;
      }
   }


   return 0;
}

