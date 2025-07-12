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

int N,M; 

int len(int l, int r){
	return r-l+1; 
}

int32_t main() {
    boost; IO();

    int t; cin>>t; 
    while(t--){
    	cin>>N>>M; 

    	vi vec; 
    	FOR(i,0,M){
    		int x; cin>>x;
    		vec.pb(x); 
    	}
    	sort(all(vec)); 


    	vi v; 
    	if(M==1){
    		v.pb(N-1);
    	}
    	else{
    		FOR(i,0,M-1){
    			int j=i+1; 
    			if(vec[j]==vec[i]+1) continue; 
    			v.pb(len(vec[i]+1,vec[j]-1)); 
    		}
    		v.pb(N-vec[M-1]+vec[0]-1); 
    	}

    	sort(rall(v));

    	int ans=0; 
    	int done=0;
    	FOR(i,0,sz(v)){
    		int r=v[i]-done*2; ckmax(r,0ll); 

    		if(r==1){
    			ans++; 
    			break; 
    		}
    		else if(r==2){
    			done++; 
    			ans++; 
    		}
    		else if(r>2){
    			done+=2; 
    			ans+=r-1; 
    		}
    	}

    	cout << N-ans << endl;
    }
    

    return 0;
}
//Change your approach 