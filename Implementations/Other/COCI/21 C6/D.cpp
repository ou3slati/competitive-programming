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

typedef complex<ll>P;
#define X real()
#define Y imag()

int N; 
V<ll> x(MX),y(MX);

ll f(P a, P b){
	return (conj(a)*b).Y;
}

bool cross(int i, int j, int k){
	P a={x[i],y[i]};
	P b={x[j],y[j]};
	P p={x[k],y[k]};

	return f(p-a,p-b)>0;
}

bool check(pi p1, pi p2){
	int a=p1.fi,b=p1.se,c=p2.fi,d=p2.se;
	if(a==c || a==d || b==c || b==d) return 0;
	return (cross(a,b,c)!=cross(a,b,d) && cross(c,d,a)!=cross(c,d,b));
}

int main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N) cin>>x[i]>>y[i];

    int ans=0;
    FOR(i,0,N) FOR(j,i+1,N){
    	bool v=1;
    	FOR(k,0,N) FOR(l,k+1,N) if(!(i==k && j==l)){
    		if(check(pi{i,j},pi{k,l})) v=0;
    	}
    	ans+=v;	
	}

	cout << ans << endl;
    

    return 0;
    	
}
//Change your approach 