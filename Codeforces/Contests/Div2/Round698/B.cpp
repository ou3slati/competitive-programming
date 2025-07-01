/*
CF 698B - TBD
https://codeforces.com/contest/1478/problem/B

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
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

int N,Q; 
str s,f; 

struct node{
	int val=0,nb=0;
};

V<node> t(MX*4);


void push_down(int pos, int l, int r){
	int m=(l+r)/2;
	if(t[pos].val!=-1){
		t[pos*2].val=t[pos].val;
		t[pos*2+1].val=t[pos].val;

		t[pos*2].nb=(t[pos].val==0)*(m-l+1);
		t[pos*2+1].nb=(t[pos].val==0)*(r-m);

		t[pos].val=-1;
	}
}

void upd(int l, int r, int v, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return;
	if(l==tl && r==tr){
		t[pos]={v,(v==0)*(r-l+1)};
		return;
	}
	push_down(pos,tl,tr);

	int tm=(tl+tr)/2;
	upd(l,min(r,tm),v,pos*2,tl,tm);
	upd(max(l,tm+1),r,v,pos*2+1,tm+1,tr);

	t[pos].nb=t[pos*2].nb+t[pos*2+1].nb;
}

void build(int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		int v=f[tl]-'0';
		t[pos]={v,(v==0)};
		return;
	}

	int tm=(tl+tr)/2;
	build(pos*2,tl,tm);
	build(pos*2+1,tm+1,tr);

	t[pos].val=-1;
	t[pos].nb=t[pos*2].nb+t[pos*2+1].nb;
}

int get(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 0;
	if(l==tl && r==tr){
		return t[pos].nb;
	}
	push_down(pos,tl,tr);

	int tm=(tl+tr)/2;
	return 
	get(l,min(r,tm),pos*2,tl,tm)+
	get(max(l,tm+1),r,pos*2+1,tm+1,tr);
}

int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	cin>>N>>Q;
    	cin>>s>>f;
    	build();

    	vpi vec;
    	FOR(i,0,Q){
    		int l,r; cin>>l>>r;
    		vec.eb(l,r);
    	}

    	bool ans=1;
    	while(!vec.empty()){
    		pi p=vec.back(); vec.pop_back();
    		int l=p.fi,r=p.se; l--; r--;

    		int x=get(l,r); //nb of zeros
    		dbgs(l,r)
    		dbg(x)
    		if((r-l+1)%2==0 && x==(r-l+1)/2){
    			ans=0;
    			break;
    		}
    		if(x<=(r-l+1)/2) upd(l,r,1);
    		else upd(l,r,0);
    	}

    	FOR(i,0,N){
    		if(get(i,i)!=((s[i]-'0')==0)) ans=0;

    	}
    	if(ans) cout << "YES" << endl;
    	else cout << "NO" << endl;
    }

    return 0;
}
//Change your approach 