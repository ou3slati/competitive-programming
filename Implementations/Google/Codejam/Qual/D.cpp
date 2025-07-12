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

int N,Q,cnt; 
vi vec;

int query(int i, int j, int k){

	#ifdef LOCAL
	cnt++;
	i--; j--; k--;
	vpi b; 
	b.pb({vec[i],i});
	b.pb({vec[j],j});
	b.pb({vec[k],k});
	sort(all(b));
	return b[1].se+1;
	#endif

	cout << i << ' ' << j << ' ' << k << endl;
	cout.flush();
	int ans; cin>>ans;
	return ans;
}

int main() {
    boost; IO();

    int t; cin>>t;
    cin>>N>>Q;
    while(t--){
    
    	#ifdef LOCAL
    	cnt=0;
    	vec.resize(N);
    	FOR(i,0,N){
    		vec[i]=i+1;
    	}
    	random_shuffle(all(vec));
    	random_shuffle(all(vec));
    	dbgv(vec)
    	#endif

    	vi a;
    	int x=query(1,2,3);
    	FOR(i,1,4){
    		if(i!=x) a.pb(i);
    	}
    	a.insert(a.begin()+1,x);

    	FOR(i,4,N+1){
    		int l=0,r=sz(a)-2;
    		int d=0;
    		while(l<=r){
    			int m=(l+r)/2;
    			
    			int x=query(a[m],a[m+1],i);
    			if(x==i){
    				a.insert(a.begin()+m+1,i);
    				d=1;
    				break;
    			}
    			else if(x==a[m]){
    				r=m-1;
    				if(r<0){
    					a.insert(a.begin(),i);
    					break;
					}
    			}
    			else{
    				l=m+1;
    				if(l>sz(a)-2){
    					a.pb(i);
    					break;
					}
    			}
    		}
    		
    	}
    	FOR(i,0,N){
    		cout << a[i]; 
    		if(i!=N-1) cout << ' ';
    	}
    	cout << endl;
		cout.flush();

		dbg(cnt)

		#ifndef LOCAL
    	int ans; cin>>ans;
    	assert(ans==1);
    	#endif
    }
    

    return 0;
}
//Change your approach 