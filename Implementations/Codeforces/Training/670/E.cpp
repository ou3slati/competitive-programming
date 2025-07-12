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
const int MX = 1e5 + 1000;
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

int N,M,S;

int spf[MX];
vi P;

V<set<int>> mult;

//map<int,set<int>> mult;

vi fact;

int X=45; set <int> ss; // for local debug


void sieve(){
	for(int i=2; i<=N; i++) if(spf[i]==-1){
		P.pb(i);
		for(int j=i; j<=N; j+=i) spf[j]=i;
	}
}

void f(int x){
	fact.clear();
	while(x>1){
		int y=spf[x];
		while(x%y==0){
			fact.pb(y);
			x/=y;
		}
	}
}

int query(char c,int x){
	/*int res=0;
	for(auto it: ss) if(it%x==0) res++;
	vi rm;
	if(c=='B')for(auto it: ss) if(it%x==0 && it!=X) rm.pb(it);
	for(auto it: rm) ss.erase(it);
	return res;*/

	cout << c << ' ' << x << endl;
	cout.flush();
	int res; cin>>res;
	return res;
}

void del(int p){ //remove all multiples of p
	for(auto y: mult[p]){
		f(y);
		if(mult[1].find(y)!=mult[1].end()) mult[1].erase(mult[1].find(y));
		for(auto x: fact){
			if(mult[x].find(y)!=mult[x].end()) mult[x].erase(mult[x].find(y));
		}
	}
}


int32_t main() {
	boost; IO();
	FOR(i,1,MX) spf[i]=-1;

	cin>>N; mult.resize(N+1);

	//for local debug
	FOR(i,1,N+1){
		ss.insert(i);
	}

	//generate prime factors up to N
	sieve();
	//divide them into sqrt(M) groups
	M=sz(P); S=ceil(sqrt(M));
	int i=0,j=0;
	vi group[S+10];
	for(;i<M;i++){
		group[j].pb(P[i]);
		if(sz(group[j])==S) j++;
	}

	/*FOR(i,0,S){
		for(auto x: group[i]) cerr << x << ' '; cerr << endl;
	}*/

	//assign each number to its prime factors
	FOR(i,1,N+1){
		f(i);
		for(auto x: fact){
			mult[x].insert(i);
		}
		mult[1].insert(i);
	}



	/*for(auto p: P){
		for(auto x: mult[p]) cerr << x << ' '; cerr << endl;
	}*/

	bool found=false; //is the first prime factor found?
	vi res; // set of the prime factors of the result

	FOR(i,0,S){
		for(auto p: group[i]){
			if(found){
				int x=query('A',p);
				if(x>sz(mult[p])) res.pb(p);
			}
			else{
				int x=query('B',p);
				del(p);
			}
		}
		
		if(!found){
			int x=query('A',1);
			if(x>sz(mult[1])){
				found=true;
				for(auto p: group[i]){
					x=query('A',p); if(x==1) res.pb(p);
				}
			}
		}
	}

	//dbgv(res);

	vi vec;
	for(auto p: res){
		int k=1;
		while(query('A',(int)(pow(p,k)+0.5))==1) k++;
		k--;
		while(k--) vec.pb(p);
	}

	int ans=1;
	for(auto x: vec) ans*=x;
	cout << "C " << ans << endl;
	cout.flush();


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
