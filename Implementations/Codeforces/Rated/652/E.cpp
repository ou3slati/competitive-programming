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

struct comp {
    bool operator() (pair<pi,int> a, pair<pi,int> b) const {
        if(a.fi.fi<=a.fi.se) return true;
        else if(b.fi.fi<=b.fi.se) return false;
        return true;
    }
};

int32_t main(){
   boost;
	int N,M; cin>>N>>M; // nb food/ nb people
	set<int> adj[M+1]; //i: food / people who like it
	int t[N+1],h[N+1]; // available, demands

	for(int i=1; i<=N; i++){
      cin>>t[i];
      h[i]=0;
	}
	int x[M],y[M]; // prefs

   for(int i=0; i<M; i++){
      cin>>x[i]>>y[i];
      h[x[i]]++; h[y[i]]++;
      adj[x[i]].insert(i); adj[y[i]].insert(i);
   }

   set <pair<pi,int>,comp> s;
   for(int i=1; i<=M; i++){
      s.insert({{h[i],t[i]},i});
   }


   /*for(int i=1; i<=M; i++){
      for(auto x: adj[i]) cout << x << ' '; cout << endl;
   }*/


   deque<int> res;

   while(!s.empty()){
      auto it=s.begin();
      if((*it).fi.fi>(*it).fi.se) break;
      int idx=(*it).se;
      //cout << idx << endl;
      //for(auto x: adj[1]) cout << x << ' '; cout << endl;
      //for(auto xx: res) cout << xx << ' '; cout << endl;

      s.erase(it); h[idx]=0;

      /*for(auto xx:s){
         cout << xx.fi.fi << ' '<<xx.fi.se << ' '<<xx.se << endl;
      }cout << endl;*/

      for(auto xx: adj[idx]){
         res.push_front(xx+1);
         int idxx=-1;
         if(x[xx]!=idx && adj[x[xx]].count(xx)==1){
            idxx=x[xx];
         }
         else if(y[xx]!=idx && adj[y[xx]].count(xx)==1){
            idxx=y[xx];
         }
         if(idxx!=-1){
            //cout << idxx << endl;

            auto itr=s.lower_bound({{h[idxx],t[idxx]},idxx});
            cout << (*itr).fi.fi << ' ' << h[idx] << endl;
            s.erase(itr);
            h[idxx]--;
            if(h[idxx]>0) s.insert({{h[idxx],t[idxx]},idxx});
            adj[idxx].erase(xx);
         }
      }
      adj[idx].clear();
   }

   if(!s.empty()) cout << "DEAD" << endl;
   else{
      cout << "ALIVE" << endl;
      for(auto xx: res) cout << xx  << ' '<< endl;
   }

   return 0;
}

