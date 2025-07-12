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
//#define int ll
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

const int MXN=2e5+5;
vi bit(MXN,0);
int N;

int lsb(int i){return i&-i;}
void update(int idx){
   while(idx<=N){
      bit[idx]++;
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

ll count_swaps(vi vec){
   N=sz(vec);
   vi m(N);
   unordered_map<int,set<int>> mp;

   for(int i=0; i<N; i++){
      int x=vec[i];
      if(mp[-x].empty()) mp[x].insert(i);
      else{
         auto it=mp[-x].begin();
         int idx=*it; mp[-x].erase(idx);
         m[idx]=i; m[i]=idx;
      }
   }
   /*for(auto x: m) cout << x << ' ';
   cout << endl;*/

   ll ans=0;
   for(int i=0; i<N; i++){
      if(m[i]<i) continue;
      int idx=m[i];

      ans+=idx-i-1-getSum(idx-1+1)+getSum(i+1);
      update(idx+1);
      if(vec[i]>0) ans++;

   }
   return ans;
}

/*int main(){
   boost;
   int N; cin>>N;
   vi vec(N);
   for(int i=0; i<N; i++) cin>>vec[i];
   int x=count_swaps(vec);
   cout << x << endl;

   return 0;
}*/

/*
8
5 2 3 -2 -5 -4 -3 4
*/
