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
const int MX = 1e5 + 10;
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

int N,K,Q;
vi a(MX),v[MX];

//-----------------------------------------//
vi t(MX,0);
void upd(int i){
	for(;i<MX; i+=i&-i) t[i]++;
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans; 
}
//------------------------------------------//

unordered_map<int,int>even[MX],odd[MX];
void compute(int i, int j){
	if(i>j) swap(i,j);
	if(even[i].count(j)) return;

	/*vpi vec;
	for(int idx: v[i]) vec.eb(idx,i);
	for(int idx: v[j]) vec.eb(idx,j);
	sort(all(vec));

	int x=i,y=j;
	int cnt=0;
	for(auto it: vec){
		if(it.se==y) cnt++;
		else even[i][j]+=cnt,even[j][i]+=cnt; 
	}

	swap(x,y);
	cnt=0;
	for(auto it: vec){
		if(it.se==y) cnt++;
		else odd[i][j]+=cnt,odd[j][i]+=cnt; 
	}*/

	int x=i,y=j;
	int cnt=0;
	int idx2=0;
	for(int idx: v[x]){
		while(idx2<sz(v[y]) && v[y][idx2]<idx){
			cnt++;
			idx2++;
		}
		even[x][y]+=cnt; 
		even[y][x]+=cnt; 
	}

	swap(x,y);
	cnt=0; 
	idx2=0;
	for(int idx: v[x]){
		while(idx2<sz(v[y]) && v[y][idx2]<idx){
			cnt++;
			idx2++;
		}
		odd[x][y]+=cnt; 
		odd[y][x]+=cnt; 
	}
}

int main() {
    boost; IO();
    
    cin>>N>>K>>Q;
    
    FOR(i,1,N+1){
    	cin>>a[i];
    	v[a[i]].pb(i);
    }
    
    ll ans=0;
   	FOR(i,1,N+1){
   		ans+=get(K)-get(a[i]);
   		upd(a[i]);
   	}

   	FOR(i,1,K) compute(i,i+1);

	vi cur(K+1); iota(all(cur),0);
    while(Q--){
    	int j; cin>>j;
    	
    	swap(cur[j],cur[j+1]);
    	int x=cur[j],y=cur[j+1];

    	if(j>1) compute(cur[j-1],cur[j]);
    	if(j+1<=K) compute(cur[j],cur[j+1]);

    	if(x>y){
    		ans-=even[x][y];
    		ans+=odd[x][y];
    	}
    	else{
    		ans+=even[x][y];
    		ans-=odd[x][y];
    	}
    	cout << ans << endl;
    }
    

    return 0;
}
//Change your approach 