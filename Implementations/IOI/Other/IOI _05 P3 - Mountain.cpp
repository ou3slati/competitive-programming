//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include <bits/stdc++.h>
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
const ll INF = 2e9;
const int MX = 1e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
//constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

long long random(long long a, long long b){
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

struct node{
	ll mx=0,sum=0;
	int lazy=-INF,l=-1,r=-1;
	//maximum pref in the segment, sum of vals in the segment
};

int N; 
int cnt=1;

V<node> t(64*MX);

void push_down(int pos, int tl, int tr){
	int mid=(tl+tr)/2;
	if(t[pos].l==-1){
		t[pos].l=++cnt;
		t[pos].r=++cnt;
	}
	int v=t[pos].lazy; 
	if(v!=-INF){
		t[t[pos].l].lazy=t[t[pos].r].lazy=v;

		t[t[pos].l].sum=(mid-tl+1)*v;
		t[t[pos].r].sum=(tr-mid)*v;

		if(v>0){
			t[t[pos].l].mx=(mid-tl+1)*v;
			t[t[pos].r].mx=(tr-mid)*v;
		}
		else{
			t[t[pos].r].mx=t[t[pos].l].mx=v;
		}
		t[pos].lazy=-INF;
	}	
}


void update(int l, int r, int v, int pos=1, int tl=1, int tr=N){
	if(l>r) return;
	if(l==tl && r==tr){
		if(v>0) t[pos].mx=(r-l+1)*v;
		else t[pos].mx=v;
		t[pos].sum=(r-l+1)*v;
		t[pos].lazy=v;
		return;
	}

	push_down(pos,tl,tr);

	int mid=(tl+tr)/2;
	update( l, min(mid,r), v, t[pos].l, tl, mid );
	update( max(mid+1,l), r, v, t[pos].r, mid+1, tr );
	t[pos].sum=t[t[pos].l].sum + t[t[pos].r].sum;
	t[pos].mx=max(t[t[pos].l].mx,t[t[pos].l].sum + t[t[pos].r].mx);
}

int walk(int v, ll s=0, int pos=1, int l=1, int r=N){
	if(l==r) return l-1;
	push_down(pos,l,r);
	int mid=(l+r)/2;
	if(s+t[t[pos].l].mx<=v) return walk(v,s+t[t[pos].l].sum,t[pos].r,mid+1,r);
	return walk(v,s,t[pos].l,l,mid);
}


int main() {
    boost; IO();

    cin>>N; 
    char c; 
    while(cin>>c,c!='E'){
    	if(c=='I'){
    		int l,r,x; cin>>l>>r>>x;
    		update(l,r,x);
    	}
    	else{
    		int x; cin>>x;
    		if(t[1].mx<=x) cout << N << endl;
    		else cout << walk(x) << endl;
    	}
    }


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