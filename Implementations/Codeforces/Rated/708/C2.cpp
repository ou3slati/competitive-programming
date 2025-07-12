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
    
    int t; cin>>t;
    while(t--){
    	int N,K,Ni; 
    	cin>>N>>K;
    	/*N=random(3,20); Ni=N;
    	K=random(3,min(N,100000ll));*/

    	vi ans(K,1); N-=K;
    	if(N%2==0){
    		ans[0]+=N/2;
    		ans[1]+=N/2;
    	}
    	else{
    		if(N==1) ans[0]++;
    		else{
    			if((N/2)%2==1){
    				ans[0]+=N/2;
    				ans[1]+=N/2;
    				ans[2]++;
    			}
    			else{
    				ans[0]+=N/2-1;
    				ans[1]+=N/2-1;
    				ans[2]+=3;
    			}
    		}
    	}

    	/*if(N&1){
    		ans[0]+=1;
    		ans[1]+=N/2;
    		ans[2]+=N/2;
    	}
    	else if(N!=0){
    		if(N==2){
    			ans[0]++;
    			ans[1]++;
    		}
    		else if(N==4){
    			ans[0]++;
    			ans[1]++;
    			ans[2]+=2;
    		}
    		else if(N%4==0){
    			ans[0]+=N/2;
    			ans[1]+=N/4;
    			ans[2]+=N/4;
    		}
    		else{
    			ans[0]+=2;
    			ans[1]+=(N-2)/2;
    			ans[2]+=(N-2)/2;
    		}
    	}*/

    	int x=1;
    	FOR(i,0,K){
    		//cout << ans[i] << ' '; 
    		x=(x*ans[i])/__gcd(x,ans[i]);
		}
		if(x>Ni/2) cout << x << ' ' << Ni << ' ' << K << endl;
		//cout << endl;
		
    }

    return 0;
}
//Change your approach 