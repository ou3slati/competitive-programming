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
    	int N; cin>>N; 
    	vi vec; 
    	
    	FOR(i,0,N){
    		int x; cin>>x; 
    		vec.pb(x); 
    	}
    	sort(all(vec)); 

    	int ans=INF;
    	FOR(i,0,N+1){

    		unordered_map<int,int>cnt; 
    		FOR(i,0,N) cnt[vec[i]]++; 

    		int lim=0; if(i) lim=vec[i-1]; 

    		int x=0; 
    		if(i){
    			ROF(j,0,i) if(cnt[vec[j]]>1){
    				int l=vec[j]; 
    				while(cnt[l]>0) l--; 

    				int r=vec[j]; 
    				while(r<=lim && cnt[r]>0) r++; 
    				if(cnt[r]>0 || r>lim) r=-1; 

    				cnt[vec[j]]--; 
    				int mn=vec[j]-l; 
    				if(r!=-1 && ckmin(mn, r-vec[j])) cnt[r]++; 
    				else cnt[l]++;

    				x+=mn; 
    			}
    		}	
    		dbg(x)
    		if(i<N){
    			//int nxt=vec[i]; 
    			FOR(j,i,N) if(cnt[vec[j]]>1){
    				/*cnt[vec[j]]--; 
    				ckmax(nxt,vec[j]); 
    				while(cnt[nxt]>0) nxt++; 
    				cnt[nxt]++; 
    				x+=nxt-vec[j]; */

    				int l=vec[j]; 
    				while(l>=lim && cnt[l]>0) l--; 
    				if(cnt[l]>0 || l<lim) l=-1;

    				int r=vec[j]; 
    				while(cnt[r]>0) r++; 

    				cnt[vec[j]]--;
    				int mn=r-vec[j];
    				if(l!=-1 && ckmin(mn, vec[j]-l)) cnt[l]++; 
    				else cnt[r]++; 

    				x+=mn; 
    			}
    		}
    		dbg(x)
    		ckmin(ans,x); 
    	}
    	cout << ans << endl;  

    }
    

    return 0;
}
//Change your approach 