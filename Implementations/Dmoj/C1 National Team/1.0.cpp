#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef priority_queue<int, vi, greater<int>> prq;

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

int N;
map <set<int>,int> memo;
int t[200001];
int p[200001];
set<int> s;

bool comp(pi k, pi l){
    if(k.fi == l.fi) return k.se > l.se;
    return k.fi < l.fi;
}

/*int solve(){
   for (auto x:s) cout << x << ' ';
   cout << endl;
   if(sz(s)==N) return 0;
   if(memo.count(s)) return memo[s];
   int x=INF;
   for (int i=0; i<N; i++) if(s.count(i)==0){
      s.insert(i);
      if(t[i]<=sz(s)-1)x=min(x,solve());
      else x=min(x,p[i]+solve());
      s.erase(i);
   }
   return memo[s]=x;
}*/

int32_t main(){
   boost;
   int N; cin>>N;
   vpi vec;
   int e=0;
   for (int i=0; i<N; i++){
      int x,y; cin>>x>>y;
      if(y==0 || x<=e) e++;
      else vec.pb({x,y});
   }
   sort(vec.begin(),vec.end(),comp);
   /*int i;
   for (i=0; i<N; i++){
      if(vec[i].fi>i) break;
   }
   if(i==N){cout << 0 << endl; return 0;}*/
   int x=e;
   //set <int> s;
    prq pq;
   int res=0;
   for (int j=sz(vec)-1; j>=0; j--){
      //s.insert(vec[j].se);
      pq.push(vec[j].se);
      if(vec[j].fi>j+x){
         x++;
         /*auto it=s.begin();
         res+=*it;
         s.erase(it);*/
         res+=pq.top();
         pq.pop();
      }
   }
   cout << res << endl;
}

