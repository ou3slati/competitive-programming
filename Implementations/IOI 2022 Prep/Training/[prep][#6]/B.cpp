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

struct line{
	int a,c; 
};

ld inter(line L, line K){
	int a=L.a, c=L.c, ap=K.a, cp=K.c; 
	return ((ld)(cp-c))/(a-ap); 
}

deque<line>lines;

void add(int a, int c){
	while(sz(lines)>=2 && inter(line{a,c},lines[0]) >= inter(line{a,c},lines[1]) ) 
		lines.pop_front(); 

	lines.push_front({a,c}); 
} 

int f(line l, int x){
	int a=l.a, c=l.c; 
	return a*x+c; 
}

int get(int x){
	int idx=0, l=0, r=sz(lines)-1; 
	while(l<=r){
		int m=(l+r)/2; 

		int lft=INF,cur=f(lines[m],x),rgt=INF;  
		if(m) lft=f(lines[m-1],x);
		if(m+1<sz(lines)) rgt=f(lines[m+1],x);  

		if(lft<cur) r=m-1; 
		else if(rgt<cur) l=m+1; 
		else {idx=m; break;}
	}
	return f(lines[idx],x); 
}


int32_t main() {
    boost; IO();

    int N; cin>>N; 
    vi a(N+1); 
    FOR(i,1,N+1) cin>>a[i]; 

    vi pref(N+1,0), p(N+1,0), pp(N+1,0); 
    FOR(i,1,N+1){
    	pref[i]=a[i]+pref[i-1]; 
    	p[i]=p[i-1]+i*a[i]; 
    	pp[i]=pp[i-1]+pref[i]; 
    }

    int ans=0; 
    FOR(i,1,N+1){
    	add(i,-pp[i-1]);
    	int val=get(pref[i]); ckmin(val,0ll); 
    	ckmax(ans,p[i]-val); 


    	//this is the brute force
    	/*int val=0; 
    	FOR(j,1,i+1) ckmin(val,j*pref[i]-pp[j-1]); 
    	ckmax(ans,p[i]-val);*/
    }
    cout << ans << endl; 
    

    return 0;
}
//Change your approach 