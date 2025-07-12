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

vi p;
vi v(MX,1);

void sieve(){
	FOR(i,2,MX) if(v[i]){
		p.pb(i);
		for(int j=i*2; j<MX; j+=i) v[j]=0;
	}
}

int32_t main() {
    boost; IO();

    sieve();

    int K; cin>>K;
    int N; //min N st N*(N+1)/2>=K

    int l=1,r=100;
    while(l<=r){
    	int m=(l+r)/2;
    	if((m*(m+1))/2>=K){
    		N=m;
    		r=m-1;
    	}
    	else l=m+1;
    }


    int res=(N*(N+1))/2-K;
    vi a(N,1);
    FOR(i,0,res) a[i]=p[i];

    cout << N << endl;
    FOR(i,0,N) cout << a[i] << ' '; cout << endl;

    /*int cnt=0;
    FOR(i,0,N){
    	int g=-1;
    	FOR(j,i,N){
    		if(g==-1) g=a[j];
    		else g=__gcd(g,a[j]);
    		if(g==1) cnt++;
    	}
	}
	cout << cnt << endl;*/


    

    return 0;
}
//Change your approach 