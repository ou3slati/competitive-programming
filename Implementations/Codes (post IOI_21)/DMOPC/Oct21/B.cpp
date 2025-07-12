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


int32_t main() {
    boost; IO();

    int K; cin>>K; 
    

    /*FOR(n,1,1000001){
    	int x=(n*(n+1))/2;
    	if(x>K) break;
    	if(x==K){
    		cout << n << endl;
    		FOR(i,0,n){
    			cout << 0;
    			if(i+1!=n) cout << ' ';
			}
    		cout << endl;
    		return 0;
    	}

    	int y=K-x;
    	int var=sqrt(2*y);
    	FOR(n2,max(0ll,var-6),var+7) if((n2*(n2+1))/2==y && n+n2+1<=1000000){
    		cout << n+n2+1 << endl;
    		FOR(i,0,n) cout << 0 << ' ';
    		cout << 1 << ' '; 
    		FOR(i,0,n2){
    			cout << 0;
    			if(i+1!=n2) cout << ' ';
			}
    		cout << endl;
    		return 0;
    	} 	
    }*/

    /*FOR(i,1,2000) FOR(j,0,2000) if((i*(i+1))/2 + (j*(j+1))/2 == K){
    	cout << i+j+1 << endl;
    	FOR(x,0,i) cout << 0 << ' ';
    	cout << 1; 
    	FOR(x,0,j) cout << ' ' << 0;
    	cout << endl;
    	return 0;
    }
    cout << -1 << endl;*/
    

    return 0;
}
//Change your approach 