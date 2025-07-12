//Never stop trying
// #include "paint.h"
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
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
const int MX = 2e5 + 10;
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

int N,M,K;
vi c(MX);


bool bs[2005][40005];

vi f(MX,-1);

bool pos[MX];


void check(){
	FOR(j,0,M){
		bool mismatch[N]; FOR(i,0,N) mismatch[i]=false;
		int nb=0;
		FOR(i,0,N){
			//if(s[(i+j)%M].count(c[i])==0) mismatch[i]=true,nb++;
			if(bs[(i+j)%M][c[i]]==0) mismatch[i]=true,nb++;
			if(i>=M-1){
				if(nb==0) pos[i-M+1]=true;
				if(mismatch[i-M+1]==true) nb--;
			}
			
		}
	}
}


bool check2(){
	FOR(i,0,N){
		c[i]=f[c[i]];
	}

	vi d;
	bool mismatch[N]; FOR(i,0,N) mismatch[i]=false;
	int nb=0;
	FOR(i,0,N){
		if(sz(d)>0 && ((d.back()+1)%M!=c[i]||d.back()==-1)){
			nb++; mismatch[i]=true;
		}
		if(i<M-1) continue;
		/*if(nb==0) pos[i-M+1]=true;
		d.pb(c[i]);
		if(mismatch[i-M+1]) nb--;*/
	}
}

int minimumInstructions(int NN, int MM, int KK, vi CC, vi AA, V<vi>B){
	N=NN; M=MM; K=KK;
	FOR(i,0,N) c[i]=CC[i];

	if(N<=20000 && M<=2000){
		unordered_map<int,int> mp; int cnt=0;
		FOR(i,0,N){
			if(!mp.count(c[i])) mp[c[i]]=cnt++;
			c[i]=mp[c[i]];
		}
		assert(cnt<=N);

		FOR(i,0,M){
			FOR(j,0,AA[i]){
				int x=B[i][j];
				if(mp.count(x)==false) continue;
				x=mp[x];
				bs[i][x]=1;
				//s[i].insert(x),f[B[i][j]]++;
			}
		}
		check();
	}
	else{
		FOR(i,0,M){
			FOR(j,0,AA[i]){
				int x=B[i][j];
				assert(x>=0 && x<=1e5+10);
				f[x]=i;
				//s[i].insert(x),f[B[i][j]]++;
			}
		}
		check2();
	}


	/*if(!pos[0]) return -1;

	ll ans=0;
	for(int i=0; i<N; ){
		if(pos[i]){
			i+=M;
			ans++;
		}
		else{
			int j=i; bool y=false;
			while(j>i-M){
				if(pos[j]){y=true; break;}
				j--;
			}
			if(!y) return -1;
			ans++;
			i=j+M;
		}
	}
	assert(ans<=N-M+1);
	return ans;*/
}

int main() {
	boost; IO();

	cin>>N>>M>>K;
	vi c(N),a(M);
	V<vi> vv; vv.assign(M,vi(0));
	FOR(i,0,N) cin>>c[i];
	//FOR(i,0,M) cin>>a[i];
	FOR(i,0,M){
		cin>>a[i];
		FOR(j,0,a[i]){int x; cin>>x; vv[i].pb(x);}
	}

	cout << minimumInstructions(N,M,K,c,a,vv) << endl;


	return 0;
}
//1273
/*
8 3 5 
3 3 1 3 4 4 2 2
3 2 2 
0 1 2	
2 3
3 4

3
*/


/*
5 4 4 
1 0 1 2 2
2 1 1 1 
0 1
1 
2 
3

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
