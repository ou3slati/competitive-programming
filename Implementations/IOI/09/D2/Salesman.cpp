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

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 1000 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

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

int N,L,R,S;
vi T(MX),X(MX),V(MX),vec,pos(MX);

bool cmp(int i, int j){
	return X[i]<X[j];
}

int cost(int i, int j){
	if(X[i]<X[j]) return (X[j]-X[i])*R;
	return (X[i]-X[j])*L;
}
	
int memo[MX][MX];
int solve(int l, int r){
	int i=l; if(T[r]>T[l]) i=r;

	int &ind=memo[l][r];
	if(ind!=-1) return ind;

	int ans=-cost(i,0);
	
	int j=pos[r]+1;
	if(j<N && T[vec[j]]>T[i]){
		ckmax(ans,solve(l,vec[j])+V[vec[j]]-cost(i,vec[j]));
	}
	
	int jj=j;
	j=pos[l]-1;

	if(j>=0 && T[vec[j]]>T[i]){
		ckmax(ans,solve(vec[j],r)+V[vec[j]]-cost(i,vec[j]));
	}

	return ind=ans;
}

int32_t main() {
    boost; IO();

    cin>>N>>L>>R>>S;
    FOR(i,1,N+1) cin>>T[i]>>X[i]>>V[i];
    N++;
    T[0]=-INF; X[0]=S; V[0]=0;
    
    vec.resize(N);
    iota(all(vec),0);
    sort(all(vec),cmp);
    dbgv(vec)

    FOR(i,0,N) pos[vec[i]]=i;

    memset(memo,-1,sizeof(memo));
    cout << solve(0,0) << endl;

    return 0;
}
//Change your approach 