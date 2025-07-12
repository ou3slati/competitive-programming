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

const ll INF = 1e18;
const int MX = 5e5 + 10;
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

int N,K,MOD,L[MX],T[MX];
vpi vec;
map<pi,int>mp;

vi t(MX*4,1);

void upd(int i, int pos=1, int l=1, int r=K){
	if(l==r){
		t[pos]++;
		//t[pos]%=MOD;
		return;
	}
	int m=(l+r)/2;
	if(i<=m) upd(i,pos*2,l,m);
	else upd(i,pos*2+1,m+1,r);

	t[pos]=(t[pos*2]*t[pos*2+1]); //%MOD;
}

int main() {
    boost; IO();

    cin>>N>>K>>MOD;
    FOR(i,0,N){
    	int x,y; cin>>x>>y;
    	vec.eb(x,y);
    }
    sort(all(vec));
    FOR(i,0,N){
    	L[i]=vec[i].fi;
    	T[i]=vec[i].se;
    }

    FOR(i,0,N){
    	cout << L[i] << ' ' << T[i] << endl;
    }

    int j=-1,ans=0;
    FOR(i,0,N){
    	while(j+1<i && L[j+1]*2<=L[i]){
    		j++;
    		upd(T[j]);
    	}

    	if(mp.count({T[i],j})) continue;
    	mp[{T[i],j}]=1;

    	ans+=t[1]; 
    	//ans%=MOD;
    	dbg(ans)
    }
    cout << ans << endl;
    

    return 0;
}
//Change your approach 