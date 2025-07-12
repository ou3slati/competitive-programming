#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef string str; 

typedef pair<int,int>pi;
#define fi first
#define se second
typedef vector<pi>vpi;
#define eb emplace_back

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void ckmin(int &x, int y){x=min(x,y);}
//------------------------------------

const int MX=1e5;

int N; 
vi adj[MX];
multiset<pi> vec[MX];

vi par(MX);
void dfs(int u, int p, int dest){
	//if(u==dest) return; 
	for(int v: adj[u]) if(v!=p){
		par[v]=u;
		dfs(v,u,dest);
	}

}

void add(int u, int v){
	dfs(u,u,v);

	int cur=v,n=0;

	vi cy; 
	while(1){
		n++;
		cy.pb(cur);
		if(cur==u) break;
		cur=par[cur];
	}
	reverse(all(cy));

	FOR(i,0,n){
		vec[cy[i]].insert({n,i});
	}
}

void del(int u, int v){
	dfs(u,u,v);

	int cur=v,n=0;

	vi cy; 
	while(1){
		n++;
		cy.pb(cur);
		if(cur==u) break;
		cur=par[cur];
	}
	reverse(all(cy));

	FOR(i,0,n){
		vec[cy[i]].erase(vec[cy[i]].lower_bound({n,i}));
	}
}

int main(){

	cin>>N; 
	FOR(i,0,N-1){
		int u,v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int K; cin>>K;
	FOR(i,0,K){
		int u,v; cin>>u>>v;
		add(u,v);
	}

	/*FOR(i,1,N+1){
		for(auto x: vec[i]) cout << x.fi << ' ' << x.se << endl;
		cout << endl;
	}*/

	int Q; cin>>Q;
	while(Q--){
		int ty; cin>>ty;
		if(ty==1){
			int u,v; cin>>u>>v;
			add(u,v);
		}
		else if(ty==2){
			int u,v; cin>>u>>v;
			del(u,v);
		}
		else{
			int u,v,t,tt; cin>>u>>v>>t>>tt; 
			dfs(u,u,v);

			int cur=v,ans=0; 
			while(1){
				for(auto it: vec[cur]){
					int a=it.fi,b=it.se;
					/*int l=(t-b+a-1)/a,r=(tt-b)/a;
					if(l<0) l=0;
					ans+=max(0ll,r-l+1);*/

					FOR(x,t,tt+1) if(x%a==b) ans++;
				}

				if(cur==u) break;
				cur=par[cur];
			}
			cout << ans << endl;
		}
		
	}



}

/*
5
1 2
2 3
2 4
1 5
1
4 1
3
3 3 5 0 3
1 2 5
3 4 5 1 5
1 3 5
3 4 5 5 10
*/