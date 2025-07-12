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

   int N,M,K; cin>>N>>M>>K;
   int A,B,C; cin>>A>>B>>C;
   bool taken[N+1]={false};	
   int T; cin>>T;
   vi vec(M); for(int i=0; i<M; i++){cin>>vec[i];  taken[vec[i]]=true;}

   //int adj[N+1][N+1];
   vpi adj[N+1];
   //for(int i=0; i<=N; i++) for(int j=0; j<=N; j++) adj[i][j]=INF;
   for(int i=1; i<N; i++){
   	adj[i].pb({i+1,A});
   }	

   for(int i=0; i<M-1; i++){
   	int s=vec[i],e=vec[i+1];
   	//adj[s][e]=min(adj[s][e],(e-s)*B);
   	adj[s].pb({e,(e-s)*B,});
   } 

   int res=0;
   for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) if(i!=j && !taken[i] && !taken[j]){
   	vi vv; vv.assign(all(vec));
   	vv.pb(i); vv.pb(j);
   	sort(all(vv));

   	//int adjj[N+1][N+1]; 
   	vpi adjj[N+1];
   	for(int i=1; i<=N; i++) for(auto j: adj[i]) adjj[i].pb(j);
   	for(int i=0; i<sz(vv)-1; i++){
   		int s=vv[i],e=vv[i+1];
   		//adjj[s][e]=min(adjj[s][e],(e-s)*C);
   		adj[s].pb({e,(e-s)*C});
   	}

   	/*for(int i=1; i<=N; i++){for(int j=1; j<=N; j++) cout << adjj[i][j] << ' '; cout << endl;}
   		cout << endl;*/

   	int dist[N+1];
   	for(int i=0; i<=N; i++) dist[i]=INF;
   	priority_queue<pi,vpi,greater<pi>> q; q.push({1,0});
   	dist[1]=0;
   	while(!q.empty()){
   		int u=q.top().fi, d=q.top().se;
   		q.pop();
   		if(d>T) break;
   		if(dist[u]>=d){
	   		for(auto v: adj[u]) if(dist[v.fi]>dist[u]+v.se){
	   			dist[v.fi]=dist[u]+v.se;
	   			q.push({v.fi,dist[v.fi]});
	   		}
   		}
   	}

   	//for(int i=1; i<=N;i++) cotu 
   	int cnt=0;
   	for(int i=2; i<=N;i++) if(dist[i]<=T) cnt++;
   	res=max(res,cnt);
   }
   cout << res << endl;



   return 0;
}

