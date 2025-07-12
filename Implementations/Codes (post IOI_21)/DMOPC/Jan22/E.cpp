//Never stop trying
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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

int N; 




vi pp(21,0);

int memo[21][1<<20],memo2[21][1<<20];
int solve(int p, int m){
	if(m==((1<<N)-1)) return 0; 

	if(memo[p][m]!=-1) return memo[p][m]; 

	int ans=0; 
	FOR(i,0,N) if(!((m>>i)&1)){
		int x=i+1; 
		
		if(p && pp[abs(p-x)]){
			if(ckmax(ans,solve(x,(m)|(1<<i))+abs(p-x)))
				memo2[p][m]=x; 
		}
		else{
			if(ckmax(ans,solve(x,(m)|(1<<i))))
				memo2[p][m]=x; 
		}
	}
	return memo[p][m]=ans; 
}

int main() {
    boost; IO();

    for(int x: {2,3,5,7,11,13,17,19}) pp[x]=1; 

    cin>>N; 

    memset(memo,-1,sizeof(memo));
    solve(0,0);

    int p=0,m=0; 
    vi ans; 
    while(m<((1<<N)-1)){
    	int x=memo2[p][m]; 
    	ans.pb(x);

    	p=x; 
    	m|=(1<<(x-1));

    }

    FOR(i,0,N){
		cout << ans[i];
		if(i!=N-1) cout << ' ';
	}
	cout << endl;

    return 0;
}
//Change your approach 