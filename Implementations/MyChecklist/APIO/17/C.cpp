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
	/*
	Place only one item in any element:
	-If there is an empty element: it is the MinValue 
	-Else the element in which I placed the item is the MinValue
	*/

	FOR(i,0,N) B[i]=0; 
	B[0]=1;

	playRound(B,R);

	FOR(i,0,N) if(R[i]==0) return i;
	return 0;
}

int maxValue(int NN, int WW) {
	N=NN; W=WW;

	/*vi chosen;
	for(int i=0; i<100; i+=10){
		FOR(j,0,N) B[j]=0;
		FOR(j,i,i+10) B[j]=10;

		playRound(B,R); 

		FOR(j,i,i+10){
			if(R[j]>10){
				chosen.pb(j);
			}	
		}
	}
	//dbgv(chosen);

	while(sz(chosen)>1){

		FOR(i,0,N) B[i]=0;
		FOR(i,0,min(sz(chosen),10)) B[chosen[i]]=10;

		playRound(B,R);
		vi nw;
		for(auto x: chosen) if(R[x]>10) nw.pb(x);
		FOR(i,10,sz(chosen)) nw.pb(chosen[i]);
		chosen.assign(all(nw));
	}

	return chosen[0];*/
	vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);
    while (v.size() != 1) {

        int k = W / v.size();
        fill(B, B + N, 0);
        for (int i : v) B[i] = k;
        playRound(B, R);
    	dbgv(B);
    	dbgv(R);
    	cerr << endl;
        v.clear();
        for (int i = 0; i < N; i++) if (R[i] > k) v.push_back(i);
    }
    return v[0];
}

int greaterValue(int NN, int WW) {
	N=NN; W=WW;
    /*
	BS([1,13]) on the number of elements put on both of those
	.if she choose both, make it bigger
	.if she choose no one, make it smaller
	.if she choose only one, that one is the biggest
	!!Choose = put on it more than I put
	*/

	int l=0,r=14;
	while(l<=r){
		int m=(l+r)/2;
		FOR(i,0,N) B[i]=0;
		B[0]=m; B[1]=m; 

		playRound(B,R);

		if(R[0]>m && R[1]>m) l=m+1;
		else if(R[0]<=m && R[1]<=m) r=m-1;
		else if(R[0]>m) return 0;
		else return 1;
	}
	assert(0);
    return 0;
}

vi adj[101];
bool vis[101];
vi top;

void dfs(int u){
	vis[u]=true;
	for(auto v: adj[u]) if(!vis[v]) dfs(v);
	top.pb(u);
}

vi solve(vi v){
	if(sz(v)==1) return v;
	
	vi a,b;

	//cmp 1
	/*int val=0;
	do{
		val++;
		FOR(i,0,N) B[i]=0;
		for(auto x: v) B[x]=val;

		playRound(B,R);
		a.clear(); b.clear();
		for(auto x: v){
			if(R[x]>1) b.pb(x);
			else if(R[x]==0) a.pb(x);
		}
	}while(a.empty() || b.empty());*/

	//cmp 2
	int l=1,r=min(W/sz(v),13);
	int prev=8478484;
	while(l<=r){
		int val=(l+r)/2; dbg(val);
		FOR(i,0,N) B[i]=0;
		for(auto x: v) B[x]=val;

		playRound(B,R);
		vi aa,bb;
		for(auto x: v){
			if(R[x]>val) bb.pb(x);
			else aa.pb(x);
		}

		if(abs(sz(aa)-sz(bb))>prev) break;
		prev=abs(sz(aa)-sz(bb));

		//dbgv(aa); dbgv(bb);
		a.assign(all(aa));
		b.assign(all(bb));

		if(sz(aa)==sz(bb)) break;	

		if(sz(aa)>sz(bb)) r=val-1;
		else l=val+1;
	}

	vi left=solve(a),right=solve(b);

	for(auto x: right) left.pb(x);
	return left;	
}

void allValues(int NN, int WW, int *PP) {
	N=NN; W=WW;

	//Strategy 1: building graph
	/*vi v[14];
	FOR(i,0,N){
		int l=0,r=13;
		int ans;
		while(l<=r){
			int m=(l+r)/2;
			FOR(idx,0,N) B[idx]=0;
			B[i]=m; 

			playRound(B,R);

			if(R[i]>m){
				ans=m;
				l=m+1;
			}
			else r=m-1;
		}
		v[ans].pb(i);
	}

	//dbgv(v[12]);

	FOR(i,0,14) FOR(j,i+1,14){
		for(auto u: v[i]) for(auto k: v[j]) adj[u].pb(k);
	}

	FOR(i,1,14){
		vi vec=v[i];
		FOR(j,0,sz(vec)) FOR(k,j+1,sz(vec)){
			int u=vec[j],vv=vec[k];

			FOR(idx,0,N) vis[idx]=0;
			dfs(u); if(vis[vv]) continue;
			FOR(idx,0,N) vis[idx]=0;
			dfs(vv); if(vis[u]) continue;

			FOR(idx,0,N) B[idx]=0;
			B[u]=i; B[vv]=i;
			
			playRound(B,R);

			bool a=(R[u]>i),b=(R[vv]>i);
			if(a&&b) dbgs(u,vv);
			if(b){
				adj[u].pb(vv); 
			}
			else{
				adj[vv].pb(u);
			}
		}
	}

	top.clear();
	FOR(i,0,N) vis[i]=0;
	FOR(i,0,N) if(!vis[i]) dfs(i);
	reverse(all(top));
	//dbgv(top);
	FOR(i,0,N) PP[top[i]]=i+1;
    */

	//Strategy 2 : custom sort
	vi v;
	FOR(i,0,N) v.pb(i);
	vi res=solve(v);
	FOR(i,0,N) PP[res[i]]=i+1;

}

#ifdef LOCAL

int main() {
    boost; IO();

    FOR(i,0,100) P[i]=i+1;

    //P[0]=100; P[99]=1;
    cout << maxValue(100,100) << endl;

	//P[0]=20; P[1]=10; P[9]=1; P[19]=2;
	//dbgv(P);
    /*allValues(100,100,P);
    dbgv(P);*/
    
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