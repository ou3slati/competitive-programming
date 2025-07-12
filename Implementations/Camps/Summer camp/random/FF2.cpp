//Never stop trying
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

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}

int32_t main(){
   boost;
   IO();


   /*vpi adj[K+1][3];
   int x[N],xx[K];
   for(int i=0; i<N; i++) cin>>x[i];
   for(int i=0; i<K; i++) cin>>xx[i];

   for(int i=0; i<N; i++) for(int j=0; j<K; j++) adj[i][0].pb({j,abs(x[i]-xx[j-])});

   for(int i=0; i<K; i++) adj[i][1].pb({P,abs(P-xx[i])});

   for(int i=0; i<N; i++) adj[0][3].pb({i,abs(x[i]-P)});

   priority_queue<pi,vpi,*/

   int N,K,P; cin>>N>>K>>P;
   int x[N];
   vpi vec;
   for(int i=0; i<N; i++){
   	cin>>x[i];
   	vec.pb({abs(P-x[i]),i});
   }
   sort(all(vec));

   set<int> s;
   for(int i=0; i<K; i++){
   	int x; cin>>x;
   	s.insert(x);
   }

   int res=0;
   for(int i=0; i<N; i++){
   	int idx=vec[i].se;
   	int ii=-1,mn=INF;
   	for(auto it:s){
   		int xx=abs(it-P)+abs(x[i]-it);
   		if(xx<mn){
   			mn=xx;
   			ii=it;
   		}
   	}
   	res=max(res,mn); s.erase(ii);
   }

   cout << res << endl;


   return 0;
}

//dp/greedy/graph