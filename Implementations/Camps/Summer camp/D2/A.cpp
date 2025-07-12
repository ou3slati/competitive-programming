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
   int N,M; cin>>N>>M;
   if(N>M){
   	cout << N-M << endl;
   }
   else{
   	vi adj[M*2+10];
   	int x=N;
   	for(int i=1; i<=M; i++) adj[i].pb(i*2);
   	for(int i=2; i<=M*2; i++) adj[i].pb(i-1);

   	queue<int> q; 
    q.push(N);
    int dist[M*2+4];
    
    for(int i=1; i<M*2+4; i++)dist[i]=INF;
    dist[N]=0;
    while(!q.empty()){
    	int u=q.front(); q.pop();
    	if(u==M){
    		cout << dist[u] << endl;
    		return 0;
    	}
    	for(auto x: adj[u])if(dist[x]==INF){
    		dist[x]=dist[u]+1;
    		q.push(x);
    	}
    }
   }
	

   return 0;
}

