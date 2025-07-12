#include <bits/stdc++.h>
using namespace std;
 
typedef vector<int>vi; 
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
 
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)
 
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
const int INF=2e9;
const int MX=1e5+10; 
 
 
 
void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////
 
 
int N,Q; 
vi L(MX), R(MX);  
 
vi adj[MX]; 

bool cmp(int i, int j){
	return R[i] > R[j]; 
}
 
int main(){
	IO(); 
 
	cin>>N>>Q; 
 
	FOR(i,1,N+1) cin>>L[i]>>R[i]; 
 
	
	FOR(i,1,N+1) FOR(j,1,N+1) if(i!=j){
		if(R[i]>=L[j] && R[i]<=R[j]){
			adj[i].pb(j); 
		}
	}

	FOR(i,1,N+1){
		sort(all(adj[i]), cmp); 
	}
 
 
	vector<vi> dist(N+1, vi(N+1,INF)); 
 
	FOR(s,1,N+1){
		dist[s][s]=0; 
 
		queue<int>q; 
		q.push(s); 
 
		while(sz(q)){
			int u=q.front(); 
			q.pop(); 
 
			for(int v: adj[u]) if(dist[s][v]==INF){
				dist[s][v]=dist[s][u]+1; 
				q.push(v); 
			}
		}
	}	
 
 
	while(Q--){
		int s,e; cin>>s>>e; 
 
		if(dist[s][e]==INF) cout << "impossible" << endl;
		else cout << dist[s][e] << endl; 
	}
}