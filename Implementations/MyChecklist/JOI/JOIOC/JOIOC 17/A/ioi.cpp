#include "Ioi.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi; 
#define pb push_back
#define sz(v) (int)v.size()
#define all(x) begin(x),end(x)

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)

//------------------------------------------------//

const int MX=2e4+10;
const int LOG=60;

vi nei2[MX];

vi par2(MX),adj2[MX],bit2(MX);
int cnt2=-1;

vi visss(MX,0);
set<int>ss[MX];
void dfs2(int u, int p){
	visss[u]=1;
	par2[u]=p;

	bit2[u]=++cnt2; bit2[u]%=LOG;

	ss[u].insert(bit2[u]);

	for(int v: nei2[u]) if(!visss[v]){
		adj2[u].pb(v);
		dfs2(v,u);

		for(int x: ss[v]) ss[u].insert(x);
	}
}

vi ans(LOG),vis(MX,0);
set<int>s;

void explore(int u, int x){
	vis[u]=1;
	s.insert(bit2[u]);
	ans[bit2[u]]=x; 

	if(sz(s)>=LOG) return; 

	int all=1,none=1;
	for(int v: adj2[u]){
		if(!vis[v]) all=0;
		if(vis[v]) none=0;
	}

	if(all){
		assert(u!=0);
		explore(par2[u],Move(par2[u]));
	}
	else if(none){
		explore(adj2[u][0],Move(adj2[u][0]));
	}
	else{
		if(u==0){
			int idx=-1;
			FOR(i,0,sz(adj2[u])) if(vis[adj2[u][i]]){
				if(i) idx=i-1;
				else{
					idx=i;
					while(idx<sz(adj2[u]) && vis[adj2[u][idx]]){
						idx++;
					}
					assert(idx<sz(adj2[u]));
				}
				break;
			}
			assert(idx!=-1);
		}
		

		explore(adj2[u][idx],Move(adj2[u][idx]));
	}
}

ll Ioi(int N, int M, int A[], int B[], int P, int V, int T){
	FOR(i,0,M){
		int u=A[i],v=B[i];
		nei2[u].pb(v);
		nei2[v].pb(u);
	}
	dfs2(0,0);

	explore(P,V);

	ll x=0;
	ROF(i,0,LOG){
		x*=2;
		x+=ans[i];
	}
	return x;
}
