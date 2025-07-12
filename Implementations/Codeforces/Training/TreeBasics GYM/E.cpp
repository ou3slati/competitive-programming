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
const ll INF = 1e9;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

void IO(){
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
#endif 
}


const int MX=3e5+10;
vi adj[MX];
int N,Q;

int tin[MX],tout[MX],timer=0;

vd st(MX*4,0.0);

void euler(int u, int p){
	tin[u]=++timer;
	for(auto v: adj[u]) if(v!=p) euler(v,u);
	tout[u]=timer;
}

void update(int i, ld v, int pos, int l, int r){
	if(l==r){
		st[pos]=v;
		return;
	}
	int m=(l+r)/2;
	if(i<=m) update(i,v,pos*2,l,m);
	else update(i,v,pos*2+1,m+1,r);
	st[pos]=st[pos*2]+st[pos*2+1];
}

ld get(int l, int r, int pos, int tl, int tr){
	if(l>r) return 0.0;
	if(l==tl && r==tr) return st[pos];
	int tm=(tr+tl)/2;
	return get(l,min(r,tm),pos*2,tl,tm)+get(max(tm+1,l),r,pos*2+1,tm+1,tr);
}

int32_t main(){
   boost;
   IO();

   cin>>N;
   for(int i=0; i<N-1; i++){
   	int u,v; cin>>u>>v;
   	adj[u].pb(v); adj[v].pb(u);
   }

   euler(1,1);

   cin>>Q;
   while(Q--){
   	int t,x,y; cin>>t>>x>>y;
   	if(t==1){
   		update(tin[x],log2(y),1,1,N);
   	}
   	else{
   		ld a=get(tin[x],tout[x],1,1,N), b=get(tin[y],tout[y],1,1,N);
   		if(a-b>log2(INF)) cout << INF << endl;
   		else cout << fixed << setprecision(10) << pow(2,a-b) << endl;
   	}

   }
	

   return 0;
}

