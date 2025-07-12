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

const int MX=1e5;
int N; 
vi h(MX),w(MX);

bool sub1(){
	if(N>50) return false;
	for(int i=0; i<N; i++) if(h[i]>50 || w[i]>1) return false;
	return true;
}
bool sub2(){
	for(int i=0; i<N; i++) if(h[i]>2) return false;
	return true;
}
bool sub3(){
	for(int i=0; i<N-1; i++) if(h[i]!=h[i+1]) return false;
	return true;
}

bool sub4(){
	for(int i=1; i<N; i++) if(h[i]<h[i-1]) return false;
	return true;
}


int32_t main() {
	boost; IO();

	cin>>N;
	for(int i=0; i<N; i++) cin>>h[i];
	for(int i=0; i<N; i++) cin>>w[i];

	if(sub1()){
		int g[51][51]; FOR(i,0,51) FOR(j,0,51) g[i][j]=0;
		for(int i=0; i<N; i++) for(int j=0; j<h[i]; j++) g[i][j]=1;
		FOR(i,0,51) FOR(j,0,51){
			if(i) g[i][j]+=g[i-1][j];
			if(j) g[i][j]+=g[i][j-1];
			if(i&&j) g[i][j]-=g[i-1][j-1];
		}
		int ans=0;
		FOR(i,0,51) FOR(j,0,51) FOR(k,i,51) FOR(l,j,51){
			int v=g[k][l];
			if(i) v-=g[i-1][l];
			if(j) v-=g[k][j-1];
			if(i&&j) v+=g[i-1][j-1];

			if(v==(k-i+1)*(l-j+1)) ans++;
		}
		cout << ans << endl;
	}
	else if(sub2()){
		int res=0;
		int W=0; FOR(i,0,N) W+=w[i]; W%=MOD;
		res+=(W*(W+1))/2; res%=MOD;
		int ww=0;

		for(int i=0; i<=N; i++){
			if(i==N || h[i]==1){
				res+=(ww*(ww+1)); res%=MOD;
				ww=0;
			}
			if(i==N) break;
			if(h[i]==2) ww+=w[i]; ww%=MOD;
		}
		cout << res << endl;
	}
	else if(sub3()){	
		int W=0,H=0;
		for(int i=0; i<N; i++) W+=w[i]; W%=MOD; 
		H=h[0];
		int x=((W+1)*W)/2; x%=MOD;
		cout << (x*((((1+H)*H)/2)%MOD))%MOD << endl;
	}
	else if(sub4()){
		int W=0; FOR(i,0,N) W+=w[i]; W%=MOD;

		int res=0;
		for(int i=0; i<N; i++){
			int top=h[i],dif=h[i]; if(i) dif-=h[i-1];
			int y=(((top+(top-dif+1))*dif)/2)%MOD;
			int x=(((W+1)*W)/2)%MOD;
			//cout << x << ' ' << y << ' ' << x*y << endl;
			res=(res+(x*y)%MOD)%MOD;

			W=(W-w[i]+MOD)%MOD;
		}
		cout << res << endl;
	}
	else if(N<5000){
		h[N]=0;
		int res=0;
		FOR(i,0,N){
			int W=w[i];
			int top=h[i];

			FOR(j,i+1,N+1){
				if(h[j]<top){
					int x=((W+W-w[i]+1)*w[i])/2; x%=MOD;
					int y=((top+h[j]+1)*(top-h[j]))/2; y%=MOD;

					res+=(x*y)%MOD; res%=MOD;
					top=h[j]; 
				}
				W+=w[j]; W%=MOD;
			}
		}
		cout << res << endl;
	}



	return 0;
}


/*
7
25 11 50 26 30 44 21
1 1 1 1 1 1 1

7573

*/

/*
5
25 29 35 36 45
1 1 1 1 1

7622
*/

/*
4
2 3 3 1
1 1 1 1

31
*/

/*
5
25 25 25 25 25
1 1 1 1 1

4875
*/

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
