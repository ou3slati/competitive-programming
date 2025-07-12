#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef string str; 

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void ckmin(int &x, int y){x=min(x,y);}
//------------------------------------


const int MX=1e5+10;
int N; 
vi adj[MX];

int memo[MX][2];
int solve(int u, int st){
	int &ind=memo[u][st];
	if(ind!=-1) return ind; 

	int x=0;
	for(int v: adj[u]) x+=solve(v,1)+1;
	int ans=x; 
	if(st){
		for(int v: adj[u]){
			ckmin(ans,x-solve(v,1)-1+solve(v,0));
		}
	}
	return ind=ans; 


}

int main(){
	cin>>N;

	if(N&1){
		cout << -1 << endl;
		return 0;
	}

	map<string,int>mp;
	int cnt=-1;
	vi nxt(N),root(N,0);
	FOR(i,0,N){
		str s,t; cin>>s>>t;
		if(!mp.count(s)) mp[s]=++cnt; 
		if(!mp.count(t)) mp[t]=++cnt; 
	
		int u=mp[s],v=mp[t];
		if(u!=v){
			adj[v].pb(u);
		}
		else root[u]=1;
	}

	memset(memo,-1,sizeof(memo));
	int ans=0;
	FOR(i,0,N) if(root[i]) ans+=solve(i,1)+1;
	cout << ans << endl;
}