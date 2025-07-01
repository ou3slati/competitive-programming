/*
CF 696E - TBD
https://codeforces.com/contest/1474/problem/E

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
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

int32_t main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	int N; cin>>N;
    	vi a(N+1);
    	FOR(i,1,N+1) a[i]=i;

    	vpi vec;
    	int rep=N-1,cur=N-1,ans=0;
    	while(rep>0){
    		swap(a[1],a[1+cur]);
    		vec.eb(1,1+cur);
    		ans+=cur*cur;
    		rep--;

    		if(cur!=N-1 && rep){
    			swap(a[N-cur],a[N]);
    			vec.eb(N-cur,N);
    			ans+=cur*cur;
    			rep--;
    		}

    		cur--;
    	}	
    	reverse(all(vec));

    	cout << ans << endl;
    	FOR(i,1,N+1) cout << a[i] << ' '; cout << endl;
    	cout << N-1 << endl;
    	for(auto x: vec){
    		swap(a[x.fi],a[x.se]);
    		if(a[x.fi]!=x.fi) swap(x.fi,x.se);
    		cout << x.fi << ' ' << x.se << endl;
		}

    }
    

    return 0;
}

//Change your approach 