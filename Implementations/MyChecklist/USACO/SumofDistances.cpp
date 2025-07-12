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

int K,N[50005],M[50005];
vpi ed[MX];

vi even[50005],odd[50005];

void compute(){
	FOR(i,0,K) even[i].assign(N[i]+1,INF),odd[i].assign(N[i]+1,INF);
	FOR(i,0,K) even[i][1]=0;

	FOR(i,0,K){
		int rep=M[i];
		while(rep--){
			for(auto it: ed[i]){
				int u=it.fi,v=it.se;
				ckmin(even[i][u],odd[i][v]+1);
				ckmin(odd[i][u],even[i][v]+1);
			}
		}
	}
}

int32_t main() {
    boost; IO();

    cin>>K;
    FOR(i,0,K){
    	cin>>N[i]>>M[i];
    	FOR(j,0,M[i]){
    		int u,v; cin>>u>>v;
    		ed[i].eb(u,v);
    		ed[i].eb(v,u);
    	}
    }

    compute();

    /*FOR(i,0,K){
    	FOR(u,1,N[i]+1) cout << even[i][u] << ' '; 
    	cout << endl;
    }*/

    int ans=0;
    FOR(i,0,K){
    	FOR(u,1,N[i]+1){

    		int e=(even[i][u]!=INF),o=(odd[i][u]!=INF),x=(e&&o);
    		FOR(j,0,K) if(i!=j){
    			int ne=0,no=0,nx=0;
    			FOR(v,1,N[j]+1){
    				bool c1=(even[j][v]<even[i][u]+(j<i)); 
    				bool c2=(odd[j][v]<odd[i][u]+(j<i)); 

    				if(c1) ne++;
    				if(c2) no++;

    				if(c1 && c2) nx++;
    			}

    			e*=ne; o*=no; x*=nx; 
    			e%=MOD; o%=MOD; x%=MOD;
    		}
    		ans+=(even[i][u]*e)%MOD; ans%=MOD;
    		ans+=(odd[i][u]*o)%MOD; ans%=MOD;
    		ans-=(max(odd[i][u],even[i][u])*x)%MOD; ans%=MOD; ans+=MOD; ans%=MOD;
    		

    	}
    }
    cout << ans << endl;

    return 0;
}
//Change your approach 