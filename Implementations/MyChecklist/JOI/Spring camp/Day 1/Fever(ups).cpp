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
const int nx[4] = {1, -1, 0, 0}, ny[4] = {0, 0, -1, 1}; 

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

// 0 1 2 3
//right left down up

int N,X[MX],Y[MX];

void rotate(){
	FOR(i,0,N){
		Y[i]*=-1;
		swap(X[i],Y[i]);
	}
}

int solve(){
	vi d(N);
	d[0]=0;
	FOR(i,1,N){
		if(X[i]>=0){
			if(abs(Y[i])<X[i]) d[i]=1;
			else if(Y[i]>=0) d[i]=2;
			else d[i]=3;
		}
		else{
			if(abs(Y[i])<=-X[i]) d[i]=0;
			else if(Y[i]>=0) d[i]=2;
			else d[i]=3;
		}
	}

	V<pair<ld,pi>>vec;
	FOR(i,0,N) FOR(j,i+1,N){
		int x1=X[i],y1=Y[i],x2=X[j],y2=Y[j];
		int nx1=nx[d[i]],ny1=ny[d[i]],nx2=nx[d[j]],ny2=ny[d[j]];

		if(y1==y2){
			if(x1<x2 && d[i]==0 && d[j]==1){
				vec.pb({(ld)(x2-x1)/2,{i,j}});
				continue;
			}
			if(x1>x2 && d[i]==1 && d[j]==0){
				vec.pb({(ld)(x1-x2)/2,{i,j}});
				continue;
			}
		}
		if(x1==x2){
			if(y1<y2 && d[i]==3 && d[j]==2){
				vec.pb({(ld)(y2-y1)/2,{i,j}});
				continue;
			}
			if(y1>y2 && d[i]==2 && d[j]==3){
				vec.pb({(ld)(y1-y2)/2,{i,j}});
				continue;
			}
		}

		if(nx1==nx2 || ny1==ny2) continue;
		if((x2-x1)%(nx1-nx2)!=0 || (y2-y1)%(ny1-ny2)!=0) continue;

		if((x2-x1)/(nx1-nx2)==(y2-y1)/(ny1-ny2)){
			int t=(x2-x1)/(nx1-nx2);
			vec.pb({t,{i,j}});
		}
	}
	sort(all(vec));

	vi vis(N,0);
	vis[0]=1;

	for(auto it: vec){
		int u=it.se.fi,v=it.se.se;
		if(vis[u] || vis[v]) vis[u]=1,vis[v]=1;
	}
	int ans=0;
	for(int x: vis) ans+=x;
	return ans; 
}

int32_t main() {
    boost; IO();
    
    cin>>N;
    FOR(i,0,N) cin>>X[i]>>Y[i];

    FOR(i,1,N) X[i]-=X[0],Y[i]-=Y[0];
    X[0]=0; Y[0]=0;

    int ans=0;
    FOR(rep,0,4){
    	ckmax(ans,solve());
    	rotate();
    }
    cout << ans << endl;

    return 0;
}
//Change your approach 