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

int N; 
str s,t; 



vi tr(MX,0); 
void upd(int i, int x){
	i++; 
	for(;i<MX;i+=i&-i) tr[i]+=x; 
}

int get(int i){
	i++; 
	int ans=0; 
	for(;i;i-=i&-i) ans+=tr[i]; 
	return ans; 
}

int f(int i){
	int x=get(i); 
	if(x&1) return 1-(s[i]-'0'); 
	return (s[i]-'0'); 
}

set<int>ps,pd; 
int ans; 
void toggle(int l, int r){
	if(l){
		int i=l;

		if(ps.count(i-1)){
			ps.erase(i-1); 
			pd.insert(i-1); 
		}
		else{
			pd.erase(i-1); 
			ps.insert(i-1); 
		}
	}
	if(r<N-1){
		int i=r; 
		if(ps.count(i)){
			ps.erase(i); 
			pd.insert(i); 
		}
		else{
			pd.erase(i); 
			ps.insert(i); 
		}
	}

	ans+=r-l+1; 
	upd(l,1);
	upd(r+1,-1); 
}

int32_t main() {
    boost; IO();
    
    int tc; cin>>tc; 
    while(tc--){
    	cin>>N>>s>>t; 
    	
    	if(s[0]!=t[0] || s[N-1]!=t[N-1]){
    		cout << -1 << endl;
    		continue; 
    	}

    	ans=0;
    	FOR(i,0,N+3) tr[i]=0;
    	

    	/*vi ps(N,N),pd(N,N);
    	ROF(i,0,N-1){
    		if(s[i]!=s[i+1]) pd[i]=i, ps[i]=ps[i+1]; 
    		else ps[i]=i, pd[i]=pd[i+1]; 
    	}*/

    	ps.clear(); pd.clear(); 
    	FOR(i,0,N-1){
    		if(s[i]==s[i+1]) ps.insert(i); 
    		else pd.insert(i); 
    	}

    	
    	FOR(i,1,N) if(f(i)!=(t[i]-'0')){
    		if(i==N-1){ans=INF; break;}
    		/*dbg(i)
    		cerr << f(i) << ' ' << (t[i]-'0') << endl;*/

    		if(f(i-1)!=f(i+1)) 
    			toggle(i,i); 
    		else{
    			if(f(i)!=f(i-1)){
    				/*int j=N; 
    				FOR(k,i,N-1) if(f(k)==f(k+1)){j=k; break; }*/

    				int j=N; 
    				auto it=ps.lower_bound(i); 
    				if(it!=ps.end()) j=*it; 

    				if(j==N){ans=INF; break;}
    				toggle(i,j); 
    				

    			}
    			else{
    				int j=N; 
    				auto it=pd.lower_bound(i); 
    				if(it!=pd.end()) j=*it; 

    				if(j==N){ans=INF; break;}
    				toggle(i,j); 
    			}
    		}

    	}
    	if(ans==INF) ans=-1; 
    	cout << ans << endl;


    }

    return 0;
}
//Change your approach 