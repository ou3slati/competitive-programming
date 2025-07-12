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
const int MX = 700+5;
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
vi a(MX); 


int memo[MX][MX][2]; 
int solve(int l, int r, int s){
	if(l>r) return 1; 

	int &ind=memo[l][r][s]; 
	if(ind!=-1) return ind; 

	int x; 
	if(s) x=a[r+1]; 
	else x=a[l-1]; 

	int ans=0; 
	FOR(i,l,r+1) if(__gcd(a[i],x)>1 && solve(l,i-1,1) && solve(i+1,r,0)){
		ans=1; 
		break; 
	}

	return ind=ans; 
}



int main() {
    boost; IO();
    	
    cin>>N; 
    FOR(i,0,N) cin>>a[i]; 

    memset(memo,-1,sizeof(memo)); 

    int ans=0; 
    FOR(i,0,N){
    	if(solve(0,i-1,1) && solve(i+1,N-1,0)) ans=1; 
    	break; 
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
//Change your approach 