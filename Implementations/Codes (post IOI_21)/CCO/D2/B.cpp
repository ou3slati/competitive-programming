#include <bits/stdc++.h>
using namespace std; 

#define ll long long 
#define int ll

typedef vector<int>vi; 
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
typedef pair<int,int>pi; 
typedef vector<pi>vpi; 
#define fi first
#define se second
#define FOR(i,a,b) for(int i=a; i<b; i++) 

void IO(){
#ifdef LOCAL
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
#endif
}

//------------------

const int MX=2e5+10;
const ll INF=1e18; 

int N,A,B,K; 
vi U, V, W, U2, V2, W2; 

bool cmp(int i, int j){
	return W[i] < W[j];  
}
bool cmp2(int i, int j){
	return W2[i] < W2[j];  
}

int f(int x){return (x*(x-1))/2; }

int val=0, val2=0; 
vi p(MX), rnk(MX), szz(MX);

int findSet(int u){
	return p[u]==u ? u : p[u]=findSet(p[u]); 
}
void unite(int u, int v){
	u=findSet(u), v=findSet(v); 
	if(u==v) return; 

	if(rnk[u]<rnk[v]) swap(u,v); 
	if(rnk[u]==rnk[v]) rnk[u]++; 
	p[v]=u; 

	val-=f(szz[u]); val-=f(szz[v]);
	szz[u]+=szz[v]; 
	val+=f(szz[u]);
}


void unite2(int u, int v){
	u=findSet(u), v=findSet(v); 
	if(u==v) return; 

	if(rnk[u]<rnk[v]) swap(u,v); 
	if(rnk[u]==rnk[v]) rnk[u]++; 
	p[v]=u; 

	val2-=f(szz[u]); val2-=f(szz[v]);
	szz[u]+=szz[v]; 	
	val2+=f(szz[u]);
}


int32_t main(){
	IO(); 

	cin>>N>>A>>B>>K; 

	U.resize(A); V.resize(A); W.resize(A); 
	U2.resize(B); V2.resize(B); W2.resize(B); 

	FOR(i,0,A) cin>>U[i]>>V[i]>>W[i]; 	
	FOR(i,0,B) cin>>U2[i]>>V2[i]>>W2[i]; 	

	if(!K || N==1){
		cout << 0 << endl;
		return 0;
	}
	
	vi v(A), v2(B); iota(all(v),0); iota(all(v2),0); 
	sort(all(v), cmp); sort(all(v2), cmp2); 


	vpi vec, vec2; 

	p.resize(N+1); rnk.assign(N+1,0); szz.assign(N+1,1); 
	FOR(i,1,N+1){
		p[i]=i; 
	}
	for(int i: v){
		unite(U[i],V[i]); 
		vec.pb({W[i], val}); 
	}
	sort(all(vec));

	
	

	rnk.assign(N+1,0); szz.assign(N+1,1); 
	FOR(i,1,N+1){
		p[i]=i; 
	}
	for(int i: v2){
		unite2(U2[i],V2[i]); 
		vec2.pb({W2[i], val2}); 
	}
	sort(all(vec2));


	assert(sz(vec)==A); assert(sz(vec2)==B); 


	int j=B-1;
	int ans=INF; 
	FOR(i,0,A){
		while(j-1>=0 && vec[i].se + vec2[j-1].se>=K) j--; 

		if(vec[i].se+vec2[j].se>=K) 
			ans=min(ans, vec[i].fi+vec2[j].fi); 
	}

	FOR(i,0,A) if(vec[i].se>=K) ans=min(ans, vec[i].fi);  
	FOR(i,0,B) if(vec2[i].se>=K) ans=min(ans, vec2[i].fi); 

	

	if(ans==INF) ans=-1; 
	cout << ans << endl;
}