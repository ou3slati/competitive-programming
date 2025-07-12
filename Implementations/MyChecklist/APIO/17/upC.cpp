//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#ifndef LOCAL
#include "koala.h"
#endif
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

int P[100];
int N,W;

#ifdef LOCAL
void playRound(int *B, int *R) {
    int i, j;

    int S = 0;
    for (i=0;i<N;++i) {
        if ( !(B[i] >= 0 && B[i] <= W) ) {
            printf("Invalid query.\n");
            exit(0);
        }
        S += B[i];
    }
    if (S > W) {
        printf("Invalid query.\n");
        exit(0);
    }

    /*numQueries++;
    if (numQueries > maxQueries) {
        printf("Too many queries.\n");
        exit(0);
    }*/

    int cache[2][205];
    int num[2][205];
    char taken[105][205];

    for (i=0;i<205;++i) {
        cache[1][i] = 0;
        num[1][i] = 0;
    }

    for (i=0;i<N;++i) {
        int v = B[i]+1;
        int ii = i&1;
        int o = ii^1;
        for (j=0;j<=W;++j) {
            cache[ii][j] = cache[o][j];
            num[ii][j] = num[o][j];
            taken[i][j] = 0;
        }
        for (j=W;j>=v;--j) {
            int h = cache[o][j-v] + P[i];
            int hn = num[o][j-v] + 1;
            if (h > cache[ii][j] || (h == cache[ii][j] && hn > num[ii][j])) {
                cache[ii][j] = h;
                num[ii][j] = hn;
                taken[i][j] = 1;
            } else {
                taken[i][j] = 0;
            }
        }
    }

    int cur = W;
    for (i=N-1;i>=0;--i) {
        R[i] = taken[i][cur] ? (B[i] + 1) : 0;
        cur -= R[i];
    }
}
#endif

int B[100],R[100];

int minValue(int NN, int WW) {
	N=NN; W=WW;

	fill(B,B+N,0);
	B[0]=1;

	playRound(B,R);

	FOR(i,0,N) if(R[i]==0) return i;
	return 0;
}

int maxValue(int NN, int WW) {
	N=NN; W=WW;

	vi v; FOR(i,0,N) v.pb(i);
	while(sz(v)>1){
		int k=W/sz(v);
		fill(B,B+N,0);
		for(auto i: v) B[i]=k;

		playRound(B,R);

		v.clear();
		FOR(i,0,N) if(R[i]>k) v.pb(i);
	}
	return v[0];
}

int greaterValue(int NN, int WW) {
	N=NN; W=WW;

	int l=1,r=9;
	int cnt=0;
	while(l<=r){
		int m=(l+r)/2;
		fill(B,B+N,0);
		B[0]=m; B[1]=m; 

		playRound(B,R);

		if(R[0]>m && R[1]>m) l=m+1;
		else if(R[0]<=m && R[1]<=m) r=m-1;
		else return (R[0]<R[1]);
	}
	return 0;
}

bool compare(int i, int j){
	fill(B,B+N,0);
	B[i]=N; B[j]=N;

	playRound(B,R);

	return (R[i]>R[j]);
}

vi merge_sort(vi v){
	if(sz(v)==1) return v;

	vi a,b;
	FOR(i,0,(sz(v)+1)/2) a.pb(v[i]);
	FOR(i,(sz(v)+1)/2,sz(v)) b.pb(v[i]);

	a=merge_sort(a); b=merge_sort(b);

	int i=0,j=0;
	vi vec;
	while(i<sz(a) || j<sz(b)){
		if(i<sz(a) && j<sz(b)){
			if(!compare(a[i],b[j])) vec.pb(a[i]),i++;
			else vec.pb(b[j]),j++;
		}
		else if(i<sz(a)) vec.pb(a[i]),i++;
		else vec.pb(b[j]),j++;
	}
	return vec;
}

int cnt=0;

vi solve(vi v, int l=1, int r=100){
	if(sz(v)==1) return v;

	int x=min((int)sqrt(2*l),W/sz(v));
	/*x=1;
	while(((x+1)*(x+2))/2<=r && (x+1)*(r-l+1)<=W) x++;*/

	fill(B,B+N,0);
	for(auto i: v) B[i]=x;
	playRound(B,R);	cnt++;
	
	vi a,b;
	for(auto i: v){
		if(R[i]>x) b.pb(i);
		else a.pb(i);
	}
	dbgv(a) dbgv(b)

	a=solve(a,l,l+sz(a)-1); b=solve(b,r-sz(b)+1,r);
	for(auto x: b) a.pb(x);
	return a;
}	

void allValues(int NN, int WW, int *PP){
	N=NN; W=WW;

	vi v; FOR(i,0,N) v.pb(i);
	if(W==2*N){
		vi res=merge_sort(v);
		FOR(i,0,N) PP[res[i]]=i+1;
	}
	else{
		vi res=solve(v);
		FOR(i,0,N) PP[res[i]]=i+1;
	}
}

#ifdef LOCAL
int main() {
    boost; IO();

    FOR(i,0,100) P[i]=i+1;
    //cout << maxValue(100,100) << endl;

    /*P[0]=99; P[1]=100; P[99]=1; P[98]=2;
    cout << greaterValue(100,100) << endl;*/

    //swap(P[0],P[1]);
    allValues(100,100,P);
    dbgv(P);
    //cout << cnt << endl;

    return 0;
}
#endif


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