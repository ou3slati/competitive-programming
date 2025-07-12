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


vi t(MX,0);

void upd(int i, int v){
	for(;i<MX; i+=i&-i) t[i]+=v;
}

int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans;
}
int query(int l, int r){
	return get(r)-get(l-1);
}

int32_t main() {
    boost; IO();

    int N,K; cin>>N>>K;
    vi a(N+1); 
    int mn=INF;
    FOR(i,1,N+1){
    	cin>>a[i];
    	upd(i,a[i]);
    	ckmin(mn,a[i]);
	}

	set<pi>s;

	FOR(i,1,N+1){
		s.insert({i,a[i]-mn});
		if(i<K) continue;

		int v=query(i-K+1,i);
		if(v>=0){
			int x=v+1;
			while(x>0){
				auto it=s.end(); it--;
				int idx=(*it).fi,rmv=(*it).se;
				s.erase(it);


				if(rmv>x){
					s.insert({idx,rmv-x});
					upd(idx,-x);
					x=0;
				}
				else{
					upd(idx,-rmv);
					x-=rmv;
				}
			}
		}
	}
	
	int ans=0;
	FOR(i,1,N+1){
		int x=query(i,i);
		ans+=a[i]-x;
		a[i]=x;
	}

	cout << ans << endl;
	FOR(i,1,N+1) cout << a[i] << ' '; cout << endl;


    

    return 0;
}
//Change your approach 