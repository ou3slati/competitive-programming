//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 5e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
void IO2() {
#ifndef ONLINE_JUDGE
	freopen("seating.in", "r", stdin);
	freopen("seating.out", "w", stdout);
#endif
}


struct node{
	int mx=0,pref=0,suf=0,st=0;
};

int N,Q;
vector<node> t(MX*4);

node combine(node l, node r){
	node res; 
	res.st=2; 
	if(l.st==r.st) res.st=l.st;
	
	res.pref=l.pref; if(l.st==0) res.pref+=r.pref;
	res.suf=r.suf; if(r.st==0) res.suf+=l.suf;

	res.mx=max(max(l.mx,r.mx),l.suf+r.pref);

	return res;
}

void push_down(int pos, int tl, int tr){
	if(t[pos].st==2) return;
	int v=t[pos].st;
	t[pos*2].st=t[pos*2+1].st=v;
	int tm=(tl+tr)/2;
	t[pos*2].pref=t[pos*2].suf=t[pos*2].mx=(1-v)*(tm-tl+1);
	t[pos*2+1].pref=t[pos*2+1].suf=t[pos*2+1].mx=(1-v)*(tr-(tm+1)+1);
}

void build(int pos=1, int tl=1, int tr=N){
	if(tl == tr){
		t[pos].mx=t[pos].pref=t[pos].suf=1;
		return;
	}
	push_down(pos,tl,tr);
	int tm=(tl+tr)/2;
	build(pos*2,tl,tm);
	build(pos*2+1,tm+1,tr);
	t[pos]=combine(t[pos*2],t[pos*2+1]);
}


void update(int l, int r, int v, int pos=1, int tl=1, int tr=N){
	if(l>r) return;
	if(l==tl && r==tr){
		t[pos].st=v;
		t[pos].mx=t[pos].pref=t[pos].suf=(1-v)*(r-l+1);
		return;
	}
	push_down(pos,tl,tr);
	int tm=(tl+tr)/2;
	update(l,min(r,tm),v,pos*2,tl,tm);
	update(max(l,tm+1),r,v,pos*2+1,tm+1,tr);
	t[pos]=combine(t[pos*2],t[pos*2+1]);
}


int walk(int x, int pos=1, int tl=1, int tr=N){
	if(tl==tr) return tl;
	push_down(pos,tl,tr);
	int tm=(tl+tr)/2;
	if(t[pos*2].mx>=x) return walk(x,pos*2,tl,tm);
	if(t[pos*2].suf>0 && t[pos*2].suf+t[pos*2+1].pref>=x) 
		return tm-t[pos*2].suf+1;
	return walk(x,pos*2+1,tm+1,tr);
}

int32_t main() {
	boost; IO2();

	cin>>N>>Q;
	build();

	int ans=0;
	while(Q--){
		char c; cin>>c;
		if(c=='A'){
			int x; cin>>x;
			if(t[1].mx<x){
				ans++; continue;
			}

			int l=walk(x);
			update(l,l+x-1,1);
			
		}
		else{
			int l,r; cin>>l>>r;
			update(l,r,0);
		}
	}
	cout << ans << endl;



	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
