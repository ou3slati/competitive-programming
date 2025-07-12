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

const int MX=15005;

const int C=5;
ll sq;

bool check_delta(ll x){
	if(x<0) return 0;

	ll val=(ll)sqrt(x);
	for(ll i=max(1ll,val-C); i<=val+C; i++) if(i*i==x){
		sq=i;
		return 1;
	}

	return 0;
}

int main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	str s,ss; cin>>s>>ss;
    	int a=s[2]-'0',b=s[1]-'0',c=s[0]-'0';
    	int d=ss[2]-'0',e=ss[1]-'0',f=ss[0]-'0';

    	int xx=-1,yy;
    	FOR(X,10,MX){
    		ll alpha=a+b*X+c*X*X;
    		ll beta=d-alpha;
    		ll delta=e*e-4*f*beta;
    		if(!check_delta(delta)) continue;

    		ll y=-e+sq;
    		ll y2=-e-sq;

    		if(y%(2*f)==0 && y/(2*f)>=10 && y/(2*f)<=15000){
    			int cur=y/(2*f);
    			tie(xx,yy)={X,cur};
    			break;
    		}
    		if(y2%(2*f)==0 && y2/(2*f)>=10 && y2/(2*f)<=15000){
    			int cur=y2/(2*f);
    			tie(xx,yy)={X,cur};
    			break;
    		}
    	}
    	cout << xx << ' ' << yy << endl;

    }
    

    return 0;
}
//Change your approach 