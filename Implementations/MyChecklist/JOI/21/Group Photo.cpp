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
const int MX = 5e3 + 10;
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
vi a(MX);
int val[MX][MX];

vi t;

void upd(int i, int v){
	i++;
	for(;i<MX; i+=i&-i) t[i]+=v;
}

int get(int i){
	int ans=0;
	for(; i; i-=i&-i) ans+=t[i];
	return ans; 
}
int query(int l, int r){
	if(l>r) return 0;
	l++; r++;
	return get(r)-get(l-1);
}

void precompute(){
	FOR(l,1,N+1) FOR(r,l,N+1){
		//int l=1,r=4;
		int ans=0;

		vi v;
		FOR(i,1,N+1) if(a[i]>=l) v.pb(a[i]);
		vi pos(N+1,-1);
		FOR(i,0,sz(v)) pos[v[i]]=i;

		t.assign(MX,0);
		int cur=0;
		ROF(x,l,r+1){
			/*while(pos[x]!=cur){
				swap(v[pos[x]],v[pos[x]-1]);
				swap(pos[v[pos[x]]],pos[v[pos[x]-1]]);
				ans++;
			}*/

			ans+=query(pos[x],MX-3)+pos[x]-cur-
			query(cur-query(pos[x],MX-3)+1,pos[x]);
			dbgs(pos[x],cur);

			upd(pos[x],1);

			cur++;
		}

		val[l][r]=ans;
	}

	//cout << val[1][4] << endl;
	/*FOR(i,1,N+1){
		FOR(j,i,N+1) cout << val[i][j] << ' '; cout << endl;
	}*/
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,1,N+1) cin>>a[i];

    precompute();

    int dp[N+1];
    dp[0]=0;

    FOR(i,1,N+1){
    	dp[i]=INF;
    	FOR(j,1,i+1) ckmin(dp[i],dp[j-1]+val[j][i]);
    	//cout << dp[i] << endl;
    }
    cout << dp[N] << endl;

    
    


    return 0;
}
//Change your approach 



