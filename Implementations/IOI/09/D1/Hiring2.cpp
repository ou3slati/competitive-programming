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

int N,W; 
vi S(MX),Q(MX),vec;

bool comp(int x, int y, int xx, int yy){
	return yy*x-xx*y<0;
}

bool cmp(int i, int j){
	int x=S[i]*Q[j],y=S[j]*Q[i];
	if(x!=y) return x<y;
	return Q[i]<Q[j];
}

//WA
int main() {
    boost; IO();

    cin>>N>>W;
    FOR(i,1,N+1) cin>>S[i]>>Q[i];
    
    vec.resize(N);
    iota(all(vec),1);
    sort(all(vec),cmp);

    int mx=0,x=0,y=1;
    vi ans;
    set<pi>st;
    for(auto idx: vec){
    	int s=S[idx],q=Q[idx];

    	if(s*q>W*q) continue;

    	int v=s*q,cnt=1;
    	vi chosen={idx};
    	for(auto it: st){
    		int qi=it.fi;
    		if(v+s*qi>W*q) break;

    		cnt++;
    		v+=s*qi;
    		chosen.pb(it.se);
    	}

    	if(ckmax(mx,cnt) || (mx==cnt && comp(v,q,x,y))){
    		tie(x,y)={v,q};
    		ans.assign(all(chosen));
    	}

    	st.insert({q,idx});
    }
    cout << mx << endl;
    for(auto x: ans) cout << x << ' '; cout << endl;

    return 0;
}
//Change your approach 