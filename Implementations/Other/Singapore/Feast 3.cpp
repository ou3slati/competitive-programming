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
   int N,K; cin>>N>>K;
   int t[N];
   for(int i=0; i<N; i++) cin>>t[i];

   set <pi> s;
   set <pi> ss;
   int cnt=0;
   for(int i=0; i<N; i++){
      int sg; if(t[i]<0) sg=-1; else sg=1;
      bool no=false;
      if(i==0 && sg==-1) no=true;
      int sum=0;
      while(i<N && t[i]*sg>=0){sum+=t[i]; i++;} i--;
      if(i==N-1 && sum<0) no=true;
      if(no) continue;

      s.insert({cnt,sum});
      ss.insert({abs(sum),cnt});
      cnt++;
   }


   while(sz(s)/2+1>K){
      auto it=ss.begin();
      pi pos=(*it);
      swap(pos.fi,pos.se);
      if(!s.count(pos)) pos.se=-pos.se;

      auto itr=s.find(pos);

      pi l={-1,-1},r={-1,-1};
      if(itr!=s.begin()){
         itr--;
         l=(*itr);
         itr++;
      }
      auto itrr=s.end(); itrr--;
      if(itr!=itrr){
         itr++;
         r=(*itr);
      }
      s.erase(pos); s.erase(l); s.erase(r);
      ss.erase({abs(pos.se),pos.fi}); ss.erase({abs(l.se),l.fi}); ss.erase({abs(r.se),r.fi});
      int sum=pos.se;
      if(l.se!=-1) sum+=l.se;
      if(r.se!=-1) sum+=r.se;
      s.insert({pos.fi,sum});ss.insert({abs(sum),pos.fi});

      auto itt=s.begin();
      if((*itt).se<0){s.erase(itt); ss.erase({abs((*itt).se),(*itt).fi});}
      itt=s.end(); itt--; if((*itt).se<0) {s.erase(itt); ss.erase({abs((*itt).se),(*itt).fi});}
   }

   int res=0;
   for(auto x: s) if(x.se>0) res+=x.se;
   cout << res << endl;


   return 0;
}

