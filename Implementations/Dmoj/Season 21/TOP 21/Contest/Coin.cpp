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

V<ld> p(MX,0),p2(MX,0);

int32_t main() {
    boost; IO();

    int N; cin>>N;
    V<ld> a(N),b(N);
    FOR(i,0,N) cin>>a[i]>>b[i];
    sort(all(a)); sort(all(b));
    reverse(all(a)); reverse(all(b));

    ld ans=0;
    FOR(i,0,N){
    	p[i+1]=a[i];
    	p2[i+1]=b[i];
    	p[i+1]+=p[i];
    	p2[i+1]+=p2[i];
    }

    /*
    FOR(i,1,2*N+1){
    	FOR(x,0,min(N,i)+1){
    		int y=i-x;
    		if(y>N) continue;
    		ckmax(ans,min(p[x],p2[y])-i);
    	}
    }*/

    FOR(n,1,2*N+1){
    	int l=0,r=min(n,N); 
    	while(l<=r){
    		int m=(l+r)/2;
    		if(n-m>N){
    			l=m+1;
    			continue;
    		}
    		ckmax(ans,min(p[m],p2[n-m])-n);
    		if(p[m]>p2[n-m]) r=m-1;
    		else l=m+1;
    	}
    }

    cout << fixed << setprecision(4) << ans << endl;

    return 0;
}
//Change your approach 