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

inline int readInt(){
   int x=0; bool s=1;
   char c=getchar_unlocked();
   if(c<'0'||c>'9'){
      if(c=='-') s=0;
      c=getchar_unlocked();
   }
   while(c>='0' && c<='9'){
      x=(x<<3)+(x<<1)+c-'0';
      c=getchar_unlocked();
   }
   return s? x: -x;
}

const int MX=1e7;
int mx[MX],mx2[MX];

int32_t main(){
   boost;
   int N; N=readInt();

   for(int i=0; i<N; i++){
      int x=readInt(),y=readInt();
      mx[i]=x+y;
      mx2[i]=y-x;
   }

   for(int i=0; i<N; i++){
      if(i) mx[i]=max(mx[i-1],mx[i]);
   }
   for(int i=N-1; i>=0; i--){
      if(i<N-1) mx2[i]=max(mx2[i+1],mx2[i]);
   }
   int res=0;
   for(int i=0; i<N; i++){
      if((!i && mx2[i]>mx2[i+1])||(i==N-1 && mx[i]>mx[i-1])||(mx[i]>mx[i-1] && mx2[i]>mx2[i+1])) res++;
   }
   cout << res << endl;

   return 0;
}

