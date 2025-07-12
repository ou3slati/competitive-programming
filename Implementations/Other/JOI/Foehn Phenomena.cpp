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

const int MXN=2e5+10;
int N,Q,S,T;
vi bit(MXN,0);

int lsb(int i){return i&-i;}

void update(int i, int v){
   while(i<=N){
      bit[i]+=v;
      i+=lsb(i);
   }
}

int getSum(int i){
   int res=0;
   while(i>0){
      res+=bit[i];
      i-=lsb(i);
   }
   return res;
}

int32_t main(){
   boost;
   cin>>N>>Q>>S>>T; N++;
   S*=-1;
   int t[N+1];
   for(int i=1; i<=N; i++){
      cin>>t[i];
      update(i,t[i]);
      update(i+1,-1*t[i]);
      //cout << getSum(i) << endl;
   }

   int ans=0;
   for(int i=2; i<=N; i++){
      int dif=abs(t[i]-t[i-1]);
      if(t[i]>t[i-1]) ans+=dif*S;
      else ans+=T*dif;
   }
   //cout << ans << endl;

   for(int i=0; i<Q; i++){
      int l,r,v; cin>>l>>r>>v;
      l++; r++;

      t[l]=getSum(l); t[l-1]=getSum(l-1);
      if(r!=N) t[r]=getSum(r); t[r+1]=getSum(r+1);

      int dif=abs(t[l]-t[l-1]);
      if(t[l]>t[l-1]) ans-=S*dif;
      else ans-=T*dif;

      if(r!=N){
         dif=abs(t[r+1]-t[r]);
         if(t[r+1]>t[r]) ans-=S*dif;
         else ans-=T*dif;
      }

      update(l,v); update(r+1,-v);

      t[l]=getSum(l); t[l-1]=getSum(l-1);
      if(r!=N) t[r]=getSum(r); t[r+1]=getSum(r+1);

      dif=abs(t[l]-t[l-1]);
      if(t[l]>t[l-1]) ans+=S*dif;
      else ans+=T*dif;

      if(r!=N){
         dif=abs(t[r+1]-t[r]);
         if(t[r+1]>t[r]) ans+=S*dif;
         else ans+=T*dif;
      }

      cout << ans << endl;
      //cout << endl;
   }
   return 0;
}

// dec by s
// inc  by t
