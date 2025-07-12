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


const int MX=1e5+10;
int N,Q;
int c[MX];
vi adj[MX];

int cnt[MX];
int szz[MX],order[MX];
int counter=0;
vi a;

int L[MX],R[MX];

vi bit(MX,0);

bool mo(pair<pi,int> a,pair<pi,int>b){
	const int S=ceil(sqrt(N));
	if(a.fi.fi/S!=b.fi.fi/S) return a.fi.fi/S<b.fi.fi/S;
	return a.fi.fi/S&1 ? a.fi.se<b.fi.se : a.fi.se>b.fi.se;
}

int lsb(int i){return i&-i;}
void update(int idx, int v){
	if(idx<=0) return;
	while(idx<MX){
		bit[idx]+=v;
		idx+=lsb(idx);
	}
}
int getSum(int idx){
	int ans=0;
	while(idx>0){
		ans+=bit[idx];
		idx-=lsb(idx);
	}
	return ans;
}

void add(int x){
	x=c[x];
	update(cnt[x],-1);
	cnt[x]++;
	update(cnt[x],1);
}
void remove(int x){
	x=c[x];
	update(cnt[x],-1);
	cnt[x]--;
	update(cnt[x],1);
}

void dfs(int u, int p){
	order[u]=counter++;
	a.pb(u);
	szz[u]=1;
	for(auto v: adj[u]) if(v!=p) dfs(v,u),szz[u]+=szz[v];
}

int main(){
   boost;
   IO();
   memset(cnt,0,MX);
   cin>>N>>Q;
   for(int i=1; i<=N; i++) cin>>c[i];

   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v;
   	adj[v].pb(u); adj[u].pb(v);
   }

   dfs(1,1);

   //for(int i=1; i<=N; i++) cout << szz[i] << endl;

   int val[Q];
   vector <pair<pi,int>> q;
   for(int i=0; i<Q; i++){
   	int v,x; cin>>v>>x;
   	val[i]=x;
   	q.pb({{order[v],order[v]+szz[v]-1},i});
   	//cout << order[v] << ' ' << order[v]+szz[v]-1 << endl;
   }

   sort(all(q),mo);

   int res[Q];
   int cl=0,cr=-1;
   for(auto x: q){
   	int l=x.fi.fi,r=x.fi.se,idx=x.se,xx=val[idx];

   	while(cl<l){
   		remove(a[cl]);
   		cl++;
   	}
   	while(cl>l){
   		cl--;
   		add(a[cl]);
   	}
   	while(cr<r){
   		cr++;
   		add(a[cr]);
   	}
   	while(cr>r){
   		remove(a[cr]);
   		cr--;
   	}


   	res[idx]=getSum(MX-1)-getSum(xx-1);
   }

   for(int i=0; i<Q; i++) cout << res[i] << endl;

	

   return 0;
}

