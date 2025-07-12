//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
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
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e3 + 10;
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

ll M;

struct node{
	ll mn=INF,lazy=0,l=-1,r=-1;
};

node t[128*MX];

int cnt=1;

map<int,int> vis;

void push_down(int pos){
	if(t[pos].l==-1){
		t[pos].l=++cnt;
		t[pos].r=++cnt;
	}
	t[t[pos].l].mn+=t[pos].lazy;
	t[t[pos].r].mn+=t[pos].lazy;
	t[t[pos].l].lazy+=t[pos].lazy;
	t[t[pos].r].lazy+=t[pos].lazy;
	t[pos].lazy=0;
}

void update(int l, int r, ll v, int pos=1, int tl=1, ll tr=M){
	if(l>r) return;
	if(l==tl && r==tr){
		if(t[pos].mn==INF) t[pos].mn=v;
		else if(v==INF) t[pos].mn=v;
		else t[pos].mn+=v;
		t[pos].lazy+=v;
		return;
	}
	push_down(pos);
	int mid=(tl+tr)/2;
	update( l, min(r,mid), v, t[pos].l, tl, mid );
	update( max(mid+1,l), r, v, t[pos].r, mid+1, tr );
	t[pos].mn=min(t[t[pos].l].mn,t[t[pos].r].mn);
}

bool init(int N, ll MM, int a[]){
	M=MM*(300000);

	FOR(i,0,N){
		if(!vis.count(a[i])){
			update(a[i],a[i],-a[i]);
			vis[a[i]]=0;
		}
		vis[a[i]]++;
	}
	FOR(i,0,N) update(a[i]+1,M,a[i]);

	return t[1].mn>=-1;
}

bool is_happy(int ty, int K, int a[]){
	FOR(i,0,K){
		if(!vis.count(a[i])) update(a[i],a[i],-a[i]),vis[a[i]]=0;
		
		if(ty==1) vis[a[i]]++;
		else vis[a[i]]--;
		
		update(a[i]+1,M,a[i]*ty);
		if(vis[a[i]]==0) update(a[i],a[i],INF);
	}
	return t[1].mn>=-1;
}

int main() {
    boost; IO();

    /*int Nc,Mm; cin>>Nc>>Mm;
    int a[Nc]; FOR(i,0,Nc) cin>>a[i];
    if(init(Nc,Mm,a)) cout << 1 << endl;
    else cout << 0 << endl;
    int Q; cin>>Q;
    while(Q--){
    	int ty,n; cin>>ty>>n;
    	int v[n]; FOR(i,0,n) cin>>v[i];
    	if(is_happy(ty,n,v)) cout << 1 << endl;
    	else cout << 0 << endl;
    }*/
    

    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/