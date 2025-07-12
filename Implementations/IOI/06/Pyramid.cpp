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
const ll INF = 1e9;
const int MX = 100 + 10;
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

int N,M,A,B,C,D,Rw,Cl;
vi t;

void upd(int j, int v, int pos=1, int tl=0, int tr=N-1){
	if(tl==tr){
		t[pos]=v;
		return;
	}
	int tm=(tl+tr)/2;
	if(j<=tm) upd(j,v,pos*2,tl,tm);
	else upd(j,v,pos*2+1,tm+1,tr);
	t[pos]=max(t[pos*2],t[pos*2+1]); 
}

int query(int l, int r, int pos=1, int tl=0, int tr=N-1){
	if(l>r) return 0;
	if(l==tl && r==tr) return t[pos];
	int tm=(tl+tr)/2;
	return max( query(l,min(r,tm),pos*2,tl,tm), 
		query(max(tm+1,l),r,pos*2+1,tm+1,tr)  );
}

/*void upd(int j, int v){
	t[j]=v;
}
int query(int l, int r){
	int ans=0;
	FOR(i,l,r+1) ckmax(ans,t[i]);
	return ans;
}*/

int main() {
    boost; IO();

    cin>>N>>M>>A>>B>>C>>D;
    swap(N,M); swap(A,B); swap(C,D);
    Rw=A-C-1,Cl=B-D-1;
    int g[N][M],s[N][M],mx[N][M]; 

    FOR(i,0,N) FOR(j,0,M) cin>>g[i][j];
    FOR(i,0,N) FOR(j,0,M){
    	if(i) g[i][j]+=g[i-1][j];
    	if(j) g[i][j]+=g[i][j-1];
    	if(i&&j) g[i][j]-=g[i-1][j-1];
    }

    memset(s,0,sizeof(s));
    FOR(i,0,N-A+1) FOR(j,0,M-B+1){
    	s[i][j]=g[i+A-1][j+B-1];
    	if(i) s[i][j]-=g[i-1][j+B-1];
    	if(j) s[i][j]-=g[i+A-1][j-1];
    	if(i&&j) s[i][j]+=g[i-1][j-1];
    }

    FOR(i,0,N){
    	multiset<int>st;
    	FOR(j,0,M){
    		st.insert(s[i][j]);
    		
			auto it=st.end(); it--;
			mx[i][j]=*it;
			if(j-Cl+1>=0) st.erase(st.find(s[i][j-Cl+1]));
    		
    	}
    }

    /*FOR(i,0,M) t[i].assign(4*N+10,0); 
    FOR(i,0,N) FOR(j,0,M) upd(j,i,mx[i][j]);*/
    t.resize(N*4+10);

    int mxx=-INF,X,Y,XX,YY,v;
    FOR(j,1,M-D){
    	FOR(i,0,N*4+10) t[i]=0;
    	FOR(i,0,N) upd(i,mx[i][j-1]);

    	FOR(i,1,N-C){ 
	    	int rmv=g[i+C-1][j+D-1];
	    	rmv-=g[i-1][j+D-1];
	    	rmv-=g[i+C-1][j-1];
	    	rmv+=g[i-1][j-1];

	    	if(ckmax(mxx,query(max(0,i-Rw),i-1)-rmv)){
	    		XX=i; YY=j; v=rmv;
	    	}
    	}
	}

    FOR(i,max(0,XX-Rw),XX) FOR(j,max(0,YY-Cl),YY) if(s[i][j]-v>=mxx) X=i,Y=j;
    cout << Y+1 << ' ' << X+1 << endl << YY+1 << ' ' << XX+1 << endl;

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