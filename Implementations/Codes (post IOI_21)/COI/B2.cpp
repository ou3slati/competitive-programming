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

    int L,Q; cin>>L>>Q; 

    while(Q--){
    	str s; cin>>s; 
    	if(s[0]=='a'){
    		int A; cin>>A; 

    		vi vec; 
    		FOR(i,0,10) if((A>>i)&1){
    			int rep=i+1;
    			while(rep--){
    				vec.pb(i); 
    			}
    		}

    		cout << sz(vec) << endl;
    		for(int x: vec) cout << x << ' '; cout << endl;
    	}
    	else if(s[0]=='b'){
    		int B; cin>>B; 

    		vi vec; 
    		FOR(i,0,10) if((B>>i)&1){
    			int rep=i+1;
    			while(rep--){
    				vec.pb(10+i);
    				vec.pb(20+i); 
    			}


    		}

    		cout << sz(vec) << endl;
    		for(int x: vec) cout << x << ' '; cout << endl;
    	}
    	else{
    		int N; cin>>N; 
    		vi vec(N); 
    		FOR(i,0,N) cin>>vec[i]; 

    		sort(all(vec)); 
    		
    		map<int,int>mp; for(int x: vec) mp[x]++; 

    		bitset<10>a,b; 
    		for(int x: vec){
    			if(mp[x]==1) a[x-1]=1; 
    			else if(mp[x]==2) b[x-1]=1; 
    			else a[x-1]=1, b[x-1]=1; 
    		}

    		int x=0, y=0; 
    		FOR(i,0,10){
    			x+=a[i]*pow(2,i); 
    			y+=b[i]*pow(2,i); 
    		}

    		if(x>y) cout << "A" << endl;
    		else cout << "B" << endl;

    	}
    }
    

    return 0;
}
//Change your approach 