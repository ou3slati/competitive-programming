/*
CF 712C - TBD
https://codeforces.com/contest/1504/problem/C

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
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

int N,ans=0; 
vi a(MX),c(MX);

bool cmp1(int i, int j){
	return a[i]+c[i]<a[j]+c[j];
}
bool cmp2(int i, int j){
	return a[i]<a[j];
}

int p[MX],rnk[MX];
int Set(int u){
	return p[u]==u?u:p[u]=Set(p[u]);
}
void joinSet(int u, int v){
	u=Set(u),v=Set(v);
	if(rnk[u]<rnk[v]) swap(u,v);
	if(rnk[u]==rnk[v]) rnk[u]++;
	p[v]=u;
}

int32_t main() {
    boost; IO();

    cin>>N;
    FOR(i,0,N){
    	cin>>a[i]>>c[i];
    	ans+=c[i];
	}
	vi v(N),vv(N);
	iota(all(v),0); iota(all(vv),0);
	sort(all(v),cmp1); sort(all(vv),cmp2);

	FOR(i,0,N) p[i]=i,rnk[i]=0;

	int rep=N; 
	while(rep--){
		int i=v.back();
		ROF(idx,0,sz(vv)){
			int j=vv[idx];
			if(Set(i)!=Set(j)){
				joinSet(i,j);
				dbgs(i,j)
				ans+=max(0ll,a[j]-a[i]-c[i]);
				vv.erase(vv.begin()+idx);
				break;
			}
		}
		v.pop_back();
	}
	cout << ans << endl;

    

    return 0;
}
//Change your approach 