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

#define prev prevv
int N; 
vi a(MX),last(MX,-1),prev(MX);

struct node{
	int f=0,v=0,lazy=0; 
};
V<node>t(MX*4);

void push_down(int pos){
	int v=t[pos].lazy;
	t[pos].lazy=0;

	t[pos*2].v+=v*t[pos*2].f;
	t[pos*2+1].v+=v*t[pos*2+1].f;
	t[pos*2].lazy+=v;
	t[pos*2+1].lazy+=v;
}

node combine(node a, node b){
	node c={a.f+b.f,a.v+b.v,0};
	return c;
}


node get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return {0,0,0};
	if(tl==l && tr==r){
		return t[pos];
	}

	push_down(pos);

	int tm=(tl+tr)/2;
	return combine(get(l,min(r,tm),pos*2,tl,tm),
	get(max(l,tm+1),r,pos*2+1,tm+1,tr));
}



void upd1(int i, int v, int pos=1, int l=0, int r=N-1){
	if(l==r){
		if(!v) t[pos]={0,0,0};
		else t[pos]={1,0,0};
		return; 
	}

	push_down(pos);

	int m=(l+r)/2;
	if(i<=m) upd1(i,v,pos*2,l,m);
	else upd1(i,v,pos*2+1,m+1,r);

	t[pos]=combine(t[pos*2],t[pos*2+1]);
}

void upd2(int l, int r, int v, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return; 
	if(tl==l && tr==r){
		t[pos].v+=v*t[pos].f;
		t[pos].lazy+=v;
		return; 
	}
	push_down(pos);

	int tm=(tl+tr)/2;
	upd2(l,min(r,tm),v,pos*2,tl,tm);
	upd2(max(l,tm+1),r,v,pos*2+1,tm+1,tr);

	t[pos]=combine(t[pos*2],t[pos*2+1]);
}


int32_t main() {
    boost; IO();

    cin>>N;
    int ans=0;
    FOR(i,0,N){
    	cin>>a[i];
    	prev[i]=last[a[i]];
		last[a[i]]=i;
		
		upd1(i,1);
		if(prev[i]!=-1) upd1(prev[i],0);

		int l=prev[i]; ckmax(l,0ll);
		

		if(prev[i]!=-1){
			int lp=prev[l];
			ckmax(lp,0ll);
			upd2(lp,l-1,-1);
		}
		

		ans+=get(0,i-2).v;
		FOR(i,0,N) cout << get(i,i).v << ' '; cout << endl;
		dbg(ans)

		upd2(l,i-1,1);




	}
	cout << ans << endl;

    

    return 0;
}
//Change your approach 