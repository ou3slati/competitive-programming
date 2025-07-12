//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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
vi a(MX);

struct node{
	int nb=0,sum=0,lazy=0;
};	

node combine(node a, node b){
	node c={a.nb+b.nb , a.sum+b.sum , 0};
	return c;
}

V<node>t(MX*4);

void push_down(int pos){
	int x=t[pos].lazy;

	t[pos*2].lazy+=x;
	t[pos*2+1].lazy+=x;

	t[pos*2].sum+=x*t[pos*2].nb;
	t[pos*2+1].sum+=x*t[pos*2+1].nb;
}

void upd(int i, int v, int pos=1, int l=0, int r=N-1){
	if(l==r){
		if(!v) t[pos]={0,0,0};
		else t[pos]={1,0,0};
		return;
	}
	push_down(pos);

	int m=(l+r)/2;
	if(i<=m) upd(i,v,pos*2,l,m);
	else upd(i,v,pos*2+1,m+1,r);

	t[pos]=combine(t[pos*2],t[pos*2+1]);
}


void upd2(int l, int r, int v, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return;

	if(l==tl && r==tr){
		t[pos].lazy+=v;
		t[pos].sum+=v*t[pos].nb;
		return; 
	}

	push_down(pos);

	int tm=(tl+tr)/2;
	upd2(l,min(r,tm),v,pos*2,tl,tm);
	upd2(max(tm+1,l),r,v,pos*2+1,tm+1,tr);

	t[pos]=combine(t[pos*2],t[pos*2+1]);
}

int query(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 0;

	if(l==tl && r==tr) return t[pos].sum;
	
	int tm=(tl+tr)/2;
	return query(l,min(r,tm),pos*2,tl,tm)
		+ query(max(tm+1,l),r,pos*2+1,tm+1,tr);
}


int32_t main() {
    boost; IO();

    cin>>N;

    vi last(N+1,-1),prev(N);
    FOR(i,0,N){
    	int x; cin>>x;
    	prev[i]=last[x];
    	last[x]=i;
	}

	//FOR(i,0,N) cout << prev[i] << ' '; cout << endl;

	int ans=0;
	FOR(i,0,N){
		upd(i,1);
		if(prev[i]!=-1) upd(prev[i],0);

		ans+=query(prev[i]+1,i-2);

		upd2(max(0ll,prev[i]),i-1,1); 
		if(prev[i]!=-1)
			upd2(max(0ll,prev[prev[i]]),prev[i]-1,-1);

		dbg(query(0,0));
	}
	cout << ans << endl;


    

    return 0;
}
//Change your approach 