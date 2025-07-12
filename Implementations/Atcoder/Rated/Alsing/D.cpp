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

int modpow(int x, int n, int m){
   if(n==0) return 1;
   int res=modpow(x,n/2,m);
   res=(res*res)%m;
   if(n%2==1) res=(res*x)%m;
   return res;
}

int32_t main(){
   boost;
   int N; cin>>N;
   str s; cin>>s;
   int cnt=0,x=0,x2=0;

   for(int i=0; i<N; i++){
      if(s[i]=='1') cnt++;
   }
   for(int i=0; i<N; i++){
      if(s[i]=='1') x=(x+modpow(2,N-i-1,cnt+1))%(cnt+1);
   }
   for(int i=0; i<N && cnt>1; i++){
      if(s[i]=='1') x2=(x2+modpow(2,N-i-1,cnt-1))%(cnt-1);
   }

   //cout << x << endl;

   for(int i=0; i<N; i++){
      int xx,cntt=cnt;
      if(s[i]=='0'){
         s[i]='1';  cntt++;
         xx=(x+modpow(2,N-i-1,cntt))%cntt;
      }
      else{
         s[i]='0'; cntt--;
         if(cntt==0) xx=0;
         else xx=(((x2-modpow(2,N-i-1,cntt))%cntt)+cntt)%cntt;
      }

      //cout << xx << endl;
      int res=1;
      if(cntt==0) res=0;
      while(xx>0){
         int nb=0;
         for(int idx=0; idx<28; idx++){
            if(((xx)&(1<<(idx)))>0) nb++;
         }
         xx=xx%nb;
         res++;
      }

      cout << res << endl;
      if(s[i]=='0') s[i]='1'; else s[i]='0';
   }


   return 0;
}

