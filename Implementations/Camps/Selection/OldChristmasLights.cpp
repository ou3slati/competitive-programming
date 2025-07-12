//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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

const int MX=50005;
int N,Q;
const int S=500;
vi adj[MX];
int c[MX];
int cnt[MX];

vi euler;
int tin[MX],tout[MX],timer=0;
int jump[MX][17];

multiset<int> track,s; //track of those repeated exactly 1 time

bool mo(pair<pi,int> a, pair<pi,int> b){
	if(a.fi.fi/S!=b.fi.fi/S) return a.fi.fi/S<b.fi.fi/S;
	return (a.fi.fi/S&1) ? a.fi.se<b.fi.se : a.fi.se>b.fi.se;
}

void dfs(int u, int p){
	tin[u]=timer++;
	euler.pb(u);

	jump[u][0]=p;
	for(int i=1; i<17; i++) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(auto v: adj[u]) if(v!=p) dfs(v,u);

	tout[u]=timer++;
	euler.pb(u);
}

bool ancestor(int u, int v){return tin[u]<=tin[v] && tout[u]>=tout[v];}
int LCA(int u, int v){
	if(ancestor(u,v)) return u; if(ancestor(v,u)) return v;
	for(int i=16; i>=0; i--) if(!ancestor(jump[u][i],v)) u=jump[u][i];
	return jump[u][0];
}

void add(int x){
	track.insert(x);
	auto it=track.lower_bound(x);
	int l=-1,r=-1;
	if(it!=track.begin()){
		it--;
		s.insert(x-*it);
		l=*it;
		it++;
	}
	it++;
	if(it!=track.end()){
		s.insert(*it-x);
		r=*it;
	}
	if(l!=-1 && r!=-1) s.erase(s.find(r-l));
}
void remove(int x){
	auto it=track.lower_bound(x);
	
	int l=-1,r=-1;
	if(it!=track.begin()){
		it--;
		//if(s.count(x-*it)) 
		s.erase(s.find(x-*it));
		l=*it;
		it++;
	}
	it++;
	if(it!=track.end()){
		//if(s.count(*it-x)) 
		s.erase(s.find(*it-x));
		r=*it;
	}
	it--;
	if(r!=-1 && l!=-1) s.insert(r-l);
	track.erase(it);
}

int main(){
   boost;
   IO();

   cin>>N>>Q;
   for(int i=0; i<=N; i++) cnt[i]=0;
   for(int i=1; i<=N; i++) cin>>c[i];
   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v;
   	adj[u].pb(v); adj[v].pb(u);
   }
   
   dfs(1,1);

   vector <pair<pi,int>> vec;
   for(int i=0; i<Q; i++){
   	int u,v; cin>>u>>v;
   	if(ancestor(u,v)) vec.pb({{tin[u],tin[v]},i});
   	else if(ancestor(v,u)) vec.pb({{tin[v],tin[u]},i});
   	else if(tout[u]<=tin[v]) vec.pb({{tout[u],tin[v]},i});
   	else vec.pb({{tout[v],tin[u]},i});
   }
   sort(all(vec),mo);

   int res[Q];
   int cl=0,cr=-1;

   for(int i=0; i<Q; i++){
   	int l=vec[i].fi.fi,r=vec[i].fi.se,idx=vec[i].se;
   	int u=euler[l],v=euler[r],lca=LCA(u,v);
   	int l2=-1,r2=-1;
   	if(!ancestor(u,v) && !ancestor(u,v)) l2=r2=tin[lca];

   	while(cl<l){ //remove
   		if(cnt[euler[cl]]==2) add(c[euler[cl]]);
   		else if(cnt[euler[cl]]==1) remove(c[euler[cl]]);
   		cnt[euler[cl]]--;
   		cl++;
   	}
   	while(cl>l){ //add
   		cl--;
   		if(cnt[euler[cl]]==1) remove(c[euler[cl]]);
   		else if(cnt[euler[cl]]==0) add(c[euler[cl]]);
   		cnt[euler[cl]]++;
   	}
   	while(cr<r){ // add
   		cr++;
   		if(cnt[euler[cr]]==1) remove(c[euler[cr]]); 
   		else if(cnt[euler[cr]]==0) add(c[euler[cr]]);	
   		cnt[euler[cr]]++;
		}
   	while(cr>r){ //remove
   		if(cnt[euler[cr]]==2) add(c[euler[cr]]);
   		else if(cnt[euler[cr]]==1) remove(c[euler[cr]]); 
   		cnt[euler[cr]]--;
   		cr--;
   	}

   	if(l2!=-1) add(c[lca]);
   	res[idx]=*(s.begin());
   	if(l2!=-1) remove(c[lca]);
   }

	for(int i=0; i<Q; i++) cout << res[i] << endl;
   return 0;
}

//https://ideone.com/OSlWJN	