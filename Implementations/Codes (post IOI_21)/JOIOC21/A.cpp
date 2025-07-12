//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
ll random(ll a, ll b){
    return a + rng() % (b - a + 1);
}
#ifndef LOCAL  
#define cerr if(false) cerr
#endif
#define dbg(x) cerr << #x << " : " << x << endl; 
#define dbgs(x,y) cerr << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << #v << " : " << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;
#define here() cerr << "here" << endl;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int N; 
V<vi>vec;

vi merge(vi a, vi b){
	vi ans(N); 
	FOR(i,0,N){
		if(a[i]==b[i]) ans[i]=a[i]; 
		else ans[i]=3-a[i]-b[i]; 
	}
	return ans; 
}


void f(){
	map<vi,int>mp; 
	
	FOR(rep,0,3){
		vi cur(N); 
		FOR(i,0,N){
			char c; cin>>c; 
			cur[i]=2; 
			if(c=='J') cur[i]=0; 
			else if(c=='O') cur[i]=1; 
		}
		vec.pb(cur); 
		mp[cur]=1; 
	}

	while(1){
    	int n=sz(vec),added=0; 
    	FOR(i,0,n) FOR(j,i+1,n){
    		vi cur=merge(vec[i],vec[j]); 
    		if(!mp.count(cur)){
    			vec.pb(cur); 
    			mp[cur]=1; 
    			added=1; 
    		}
    	}
    	if(!added) break; 
    }

} 


#define prev whatever
vi T(MX), L(MX), R(MX), W(MX); 
vi cur(MX), prev(MX); 

//-----------

int check_range(int l, int r, int x){
	if(cur[r]==x && l>=prev[r]) return 1; 
	return 0; 
}

struct node{
	int lazy, f; 
}; 

node merge(node a, node b){
	node c; 
	c.lazy=-1;
	c.f=(a.f&b.f); 
	return c; 
}

V<node> t(MX*4); 
void build(int tl=0, int tr=N-1, int u=1){
	if(tl==tr){
		t[u]={-1,(T[tl]==cur[tl])};
		return; 
	}

	int mid=(tl+tr)/2; 
	build(tl,mid,u*2); 
	build(mid+1,tr,u*2+1);

	t[u]=merge(t[u*2],t[u*2+1]); 
}

void push_down(int u, int tl, int tr){
	if(t[u].lazy==-1) return; 

	t[u*2].lazy=t[u].lazy; 
	t[u*2+1].lazy=t[u].lazy; 

	int tm=(tl+tr)/2; 
	t[u*2].f=check_range(tl,tm,t[u].lazy);
	t[u*2+1].f=check_range(tm+1,tr,t[u].lazy);
}

void upd(int l, int r, int v, int tl=0, int tr=N-1, int u=1){
	if(l>tr || r<tl) return; 
	if(l==tl && r==tr){
		t[u]={v, check_range(l,r,v)}; 
		return; 
	}

	push_down(u, tl, tr); 

	int tm=(tl+tr)/2; 
	upd(l,min(r,tm),v,tl,tm,u*2); 
	upd(max(tm+1,l), r, v, tm+1,tr,u*2+1); 

	t[u]=merge(t[u*2],t[u*2+1]); 
}

int check(){
	return t[1].f; 
}

//-------------

int main() {
    boost; IO();
    
    cin>>N; 
    f(); 

    /*FOR(i,0,sz(vec)){
    	vi cur=vec[i]; 
    	for(int x: cur) cout << x;
    	cout << endl;
    }*/

    int Q; cin>>Q; 
    FOR(i,0,N){
    	char c; cin>>c; 
    	T[i]=2; 
		if(c=='J') T[i]=0; 
		else if(c=='O') T[i]=1; 
    }
    FOR(i,0,Q){
    	cin>>L[i]>>R[i]; 
    	L[i]--; R[i]--; 
    	char c; cin>>c; 
    	W[i]=2; 
		if(c=='J') W[i]=0; 
		else if(c=='O') W[i]=1; 
	}


	vi ans(Q+1,0); 
	for(vi v: vec){
		//update
		FOR(i,0,N) cur[i]=v[i]; 
		prev[0]=0; 
		FOR(i,1,N){
			if(cur[i]==cur[i-1]) prev[i]=prev[i-1]; 
			else prev[i]=i; 
		}

		build(); 
		
		if(check()) ans[0]=1; 
		FOR(i,0,Q){
			upd(L[i],R[i], W[i]); 
			if(check()) ans[i+1]=1; 
		}
	}
	FOR(i,0,Q+1){
		if(ans[i]) cout << "Yes" << endl;
		else cout << "No" << endl; 
	}


    return 0;
}
//Change your approach 