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

const int MOD = 998244353; 
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

int N,K,memo[MX][4];
str s;
unordered_map<str,int>mp; //MOD!!!!

void precompute(){
	vi W(N,0),WA(N,0),WAC(N,0),A(N,0),AC(N,0),C(N,0);

	FOR(i,0,N){
		if(s[i]=='W') W[i]=1;
		else if(s[i]=='A') A[i]=1;
		else if(s[i]=='C') C[i]=1;

		if(i){
			W[i]+=W[i-1];
			A[i]+=A[i-1];
			C[i]+=C[i-1];
		} 
	}

	FOR(i,1,N){
		if(s[i]=='A') WA[i]=W[i-1];
		else if(s[i]=='C') AC[i]=A[i-1];

		WA[i]+=WA[i-1];
		AC[i]+=AC[i-1];
	}

	FOR(i,2,N){
		if(s[i]=='C') WAC[i]=WA[i-1];
		WAC[i]+=WAC[i-1];
	}

	mp["W"]=W[N-1];
	mp["A"]=A[N-1];
	mp["C"]=C[N-1];
	mp["WA"]=WA[N-1];
	mp["AC"]=AC[N-1];
	mp["WAC"]=WAC[N-1];
}

int solve(int i, int n){
	if(n==3) return 1;
	if(i==K) return 0;

	int &ind=memo[i][n];
	if(ind!=-1) return ind;

	int ans=0;
	if(n==0){
		ans+=(mp["WAC"]*solve(i+1,3))%MOD; ans%=MOD;
		ans+=(mp["WA"]*solve(i+1,2))%MOD; ans%=MOD;
		ans+=(mp["W"]*solve(i+1,1))%MOD; ans%=MOD;
		ans+=(solve(i+1,0))%MOD; ans%=MOD;
	}
	if(n==1){
		ans+=(mp["AC"]*solve(i+1,3))%MOD; ans%=MOD;
		ans+=(mp["A"]*solve(i+1,2))%MOD; ans%=MOD;
		ans+=(solve(i+1,1))%MOD; ans%=MOD;
	}
	if(n==2){
		ans+=(mp["C"]*solve(i+1,3))%MOD; ans%=MOD;
		ans+=(solve(i+1,2))%MOD; ans%=MOD;
	}

	return ind=ans;
}

int32_t main() {
    boost; IO();

    cin>>N>>K>>s;
    precompute();
    memset(memo,-1,sizeof(memo));
    cout << solve(0,0) << endl;
    

    return 0;
}
//Change your approach 