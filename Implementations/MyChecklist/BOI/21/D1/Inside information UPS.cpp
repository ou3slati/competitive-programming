#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(v) (int)v.size();

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
}

//-----------------------------------------

const int MX=240000+500;
const int LOG=20;
int N,Q,ty[MX],U[MX],V[MX];

int jump[MX][LOG],jump_max[MX][LOG],jump_inc[MX],jump_dec[MX];
int in[MX],out[MX],cnt=0;

unordered_map<int,int>ed[MX];
vi adj[MX],par(MX);

void build(){
	ed[1][1]=0;
	FOR(i,0,Q) if(!ty[i]){
		int u=U[i],v=V[i];
		ed[u][v]=ed[v][u]=i;
		adj[u].pb(v); 
		adj[v].pb(u);
	}
}
void dfs(int u, int p){
	in[u]=++cnt; 
	par[u]=p;

	jump_inc[u]=p;
	jump_dec[u]=p;
	if(p!=1){
		if(ed[p][par[p]]>ed[u][p]) jump_inc[u]=jump_inc[p];
		else jump_dec[u]=jump_dec[p];
	}
	
	jump[u][0]=p;
	jump_max[u][0]=ed[u][p];
	FOR(i,1,LOG){
		jump[u][i]=jump[jump[u][i-1]][i-1];
		jump_max[u][i]=max(jump_max[u][i-1],
			jump_max[jump[u][i-1]][i-1]);
	}

	for(int v: adj[u]) if(v!=p) dfs(v,u);

	out[u]=++cnt; 
}
void precompute(){
	build();
	dfs(1,1);
}

bool ancestor(int u, int v){
	return in[u]<=in[v] && out[u]>=out[v];
}

int main(){
	IO();

	cin>>N>>Q; Q+=N-1;
	FOR(i,0,Q){
		char c; cin>>c;
		if(c=='S') ty[i]=0;
		else ty[i]=1;

		cin>>U[i]>>V[i];
	}

	precompute();

	FOR(idx,0,Q) if(ty[idx]){
		int u=V[idx],v=U[idx]; //u-->v
		int init_u=u,init_v=v; 

		ROF(i,0,LOG) 
			if(!ancestor(jump[u][i],init_v) && jump_max[u][i]<=idx)
				u=jump[u][i];

		ROF(i,0,LOG)
			if(!ancestor(jump[v][i],init_u) && jump_max[v][i]<=idx)
				v=jump[v][i];

		bool smooth=1;
		if(!ancestor(u,init_v) && !ancestor(v,init_u))
			if(jump_max[u][0]>jump_max[v][0]) smooth=0;

		if(!ancestor(u,init_v) && jump_max[u][0]<=idx)
			u=jump[u][0];
		
		if(!ancestor(v,init_u) && jump_max[v][0]<=idx)
			v=jump[v][0];
		

		if(ancestor(u,jump_inc[init_u]))
			u=jump_inc[init_u];
		if(ancestor(v,jump_dec[init_v]))
			v=jump_dec[init_v];

		if(smooth && ancestor(u,init_v) && ancestor(v,init_u)) 
			cout << "yes" << endl;
		else cout << "no" << endl;
	}

}