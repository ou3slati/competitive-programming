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

const int MX=1e5+100;
vi bit(MX,0);
int N;

int lsb(int i){return i&-i;}
void update(int idx, int v){
   while(idx<MX){
      bit[idx]+=v;
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

int32_t main(){
   boost;
	cin>>N;
	vpi vec;
	int mx=0;
	for(int i=0; i<N; i++){
      int H,K;
      cin>>H>>K;
      vec.pb({H,K});
      mx=max(mx,H);
	}

	sort(all(vec));
	set<pi> s;
	for(int i=1; i<=mx; i++) s.insert({0,i});



	for(int i=0; i<N; i++){
      bool vis[mx+1];
      memset(vis,false,sizeof(vis));
      int H=vec[i].fi,K=vec[i].se;
      while(K--){
         for(auto x: s) if(!vis[x.se] && x.se<=H){
            s.insert({x.fi+1,x.se});
            vis[x.se]=true;
            s.erase(x);
            break;
         }
      }
	}
	int res=0;
	for(auto x: s) res+=((x.fi-1)*x.fi)/2;
	cout << res << endl;



	/*int cur=vec[0].fi;

	for(int i=0; i<N; i++){
      cur=min(cur,vec[i].fi);
      int H=vec[i].fi,K=vec[i].se;

      if(K<=cur){
         update(cur-K+1,1);
         update(cur+1,-1);
      }
      else{
         update(1,1);
         update(cur+1,-1);
         int r=K-cur;
         update(H-r+1,1);
         update(H+1,-1);
      }

      cur-=K;
      if(i==N-1) break;
      if(cur<=0){
         cur=H+cur;
      }
	}
	int res=0;
	for(int h=1; h<=vec[0].fi; h++){
      int x=getSum(h);
      //cout << x << endl;
      res+=((x-1)*x)/2;
   }
   cout << res << endl;*/

   return 0;
}

