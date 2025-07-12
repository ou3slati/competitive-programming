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


int pal(str s){
	int N=sz(s);
	FOR(i,0,N) if(s[i]!=s[N-i-1]) return 0;
	return 1;
}

int32_t main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	int N; str s; cin>>N>>s;

    	int ans=INF; 
    	for(char c='a'; c<='z'; c++){
    		int l=0,r=N-1;
    		int n=0;
    		while(l<=r){
    			if(s[l]==s[r]) l++,r--;
    			else{
    				if(s[l]==c) l++,n++;
    				else if(s[r]==c) r--,n++;
    				else{
    					n=INF; 
    					break;
    				}
    			}
    		}
    		ckmin(ans,n);
    	}
    	if(ans==INF) ans=-1;
    	cout << ans << endl;


    	/*int l=-1,r=N;
    	while(l+1<=r-1){
    		l++; r--;
    		if(s[l]!=s[r]) break;
    	}

    	if(pal(s)) cout << 0 << endl;
    	else{
    		assert(l<r);
    		str s1,s2;
    		vi v1(N,0),v2(N,0);
    		FOR(i,0,N){
    			if(s[i]!=s[l]) s1+=s[i];
    			else v1[i]=1;

    			if(s[i]!=s[r]) s2+=s[i];
    			else v2[i]=1;
			}
			//cout << s1 << ' ' << s2 << endl;

			int ans=INF;
			if(pal(s1)){
				int n=0;
				FOR(i,0,N) if(v1[i] && v1[N-i-1]) n++;
				//cout << n << endl;
				ckmin(ans,(N-sz(s1))-n);
			}
			if(pal(s2)){
				int n=0;
				FOR(i,0,N) if(v2[i] && v2[N-i-1]) n++;
				//cout << n << endl;
				ckmin(ans,(N-sz(s2))-n);
			}
			if(ans==INF) cout << -1 << endl;
			else cout << ans << endl;

    	}*/
    }
    

    return 0;
}
//Change your approach 