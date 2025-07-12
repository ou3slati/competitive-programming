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
int N,P;
int t[MX];

int32_t main(){
   boost;
   /*freopen("river.in", "r", stdin);
   freopen("river.out", "w", stdout);*/

	cin>>N>>P;
	vi vec;
	int sm=0;
	for(int i=1; i<=N; i++){
      cin>>t[i];
      sm+=t[i]*t[i];
      vec.pb(t[i]);
	}
	cout << sm << endl;


	int Q; cin>>Q;
	while(Q--){
      int x,y; cin>>x>>y;

      if(N<=1000){
         int cnt=0;
         for(auto it: vec){
            cnt++;
            if(cnt==y && x==2){
               int v=it/2,vv=(it+1)/2;
               vec.erase(vec.begin()+y-1);
               vec.insert(vec.begin()+y-1,v);
               vec.insert(vec.begin()+y,vv);
               break;
            }
            else if(cnt==y && x==1){
               int v=it/2,vv=(it+1)/2;
               if(y==sz(vec)){
                  vec.pop_back();
                  vec[sz(vec)-1]+=v+vv;
               }
               else if(y==1){
                  vec.erase(vec.begin());
                  vec[0]+=v+vv;
               }
               else{
                  vec[y-2]+=v, vec[y]+=vv;
                  vec.erase(vec.begin()+y-1);
               }
               break;
            }
         }
      }

      else{
         set <str> s;
         for(int i=0; i<N;i++)s.insert(t[i]);
         for(int i=0)
      }

      int res=0;
      for(auto x: vec){
         res+=x*x;
      }
      cout << res << endl;

	}

   return 0;
}

