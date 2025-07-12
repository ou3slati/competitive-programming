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

const int LOG=20; 

int32_t main() {
    boost; IO();

    vi power(LOG); power[0]=1; 
    FOR(i,1,LOG) power[i]=power[i-1]*2; 

    int L,Q; cin>>L>>Q; 

    while(Q--){
    	str s; cin>>s; 
    	if(s[0]=='a'){
    		int A; cin>>A; 

    		vi vec;
    		FOR(i,0,LOG) if(!((A>>i)&1)){
    			int x=A; 
                x+=power[i]; 
                FOR(j,0,i) if((A>>j)&1) x-=power[j]; 
                vec.pb(x); 
    		}

    		cout << sz(vec) << endl;
    		for(int x: vec) cout << x << ' '; cout << endl;
    	}
    	else if(s[0]=='b'){
    		int B; cin>>B; 

    		vi vec; 
    		FOR(i,0,LOG) if((B>>i)&1){
                int x=B; 
                FOR(j,0,i) if((B>>j)&1) x-=power[j]; 
                vec.pb(x); 
            }


    		cout << sz(vec) << endl;
    		for(int x: vec) cout << x << ' '; cout << endl;
    	}
    	else{
    		int N; cin>>N; 
    		vi vec(N); 
    		FOR(i,0,N) cin>>vec[i]; 
    		
    		map<int,int>mp; 
            for(int x: vec) mp[x]++; 

            int f=0; 
    		for(int x: vec){
    			if(x>1) f=1; 
    		}


    		if(!f) cout << "A" << endl;
    		else cout << "B" << endl;

    	}
    }
    

    return 0;
}
//Change your approach 