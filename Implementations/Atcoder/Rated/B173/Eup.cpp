//Never stop trying
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 2e5 + 10;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int N,K; 
vi a(MX); 

bool neg(){
	int nbNeg=0;
	FOR(i,0,N) if(a[i]<=0) nbNeg++;
	return (N==K && nbNeg%2==1) || (nbNeg==N && K%2==1);
}

int modpow(int x, int p){
	if(p==0) return 1;
	int v=modpow(x,p/2); 
	v*=v; v%=MOD;
	if(p%2) v*=x; v%=MOD;
	return v;
}

int modinv(int x){
	return modpow(x,MOD-2);
}

int32_t main() {
	boost; IO();

	cin>>N>>K;
	FOR(i,0,N) cin>>a[i];

	int S=1;
	if(neg()) S=-1;
	
	if(S==-1){
		int ans=-1;
		vi v;
		FOR(i,0,N) v.pb(abs(a[i]));
		sort(all(v));
		FOR(i,0,K) ans*=v[i],ans%=MOD;
		cout << (ans+MOD)%MOD << endl;
	}
	else{
		/*vi b,c;
		FOR(i,0,N){
			if(a[i]<=0) b.pb(a[i]);
			else c.pb(a[i]);
		}
		a.assign(all(c));
		sort(rall(a));
		sort(all(b));

		int i=0,j=0;
		int ans=1;
		while((i<sz(a)||j<sz(b)-1) && (i+j)<K){
			if(i<sz(a)-1 && j<sz(b)-1 && K-i-j>1){
				int x=a[i]*a[i+1],y=b[j]*b[j+1];
				if(x>y && !(K%2==1 && i+2==sz(a))){
					ans*=x%MOD;
					i+=2;
				}
				else{
					ans*=y%MOD;
					j+=2;
				}
			}
			else if(i<sz(a)){
				ans*=a[i]; i++;
			}
			else if(j<sz(b)-1){
				assert(K-i-j>1);
				ans*=(b[j]*b[j+1])%MOD;
				j+=2;
			}
			ans%=MOD;
		}
		cout << ans << endl;*/
		vpi b; 
		FOR(i,0,N){
			if(a[i]<0) b.pb({-a[i],-1});
			else b.pb({a[i],1});
		}
		sort(rall(b));
		int s=1,ans=1;
		FOR(i,0,K){
			ans*=b[i].fi; ans%=MOD;
			s*=b[i].se;
		}
		if(s==1) cout << ans << endl;
		else{
			int x=INF,y=INF,x2=-INF,y2=-INF;
			//remove pos and add neg
			FOR(i,0,K) if(b[i].fi>=0) x=min(x,b[i].fi);
			FOR(i,K,sz(b)) if(b[i].fi<0) y=min(y,b[i].fi);
			//remove neg and add pos
			FOR(i,0,K) if(b[i].fi<0) x2=max(x,b[i].fi);
			FOR(i,K,sz(b)) if(b[i].fi>=0) y2=max(y,b[i].fi);

			if(x==INF || y==INF){
				assert(x2!=-INF && y2!=-INF);
				ans*=modinv(x2); ans%=MOD;
				ans*=y2; ans%=MOD;
			}
			else if(x2==-INF || y2==-INF){
				assert(x!=INF && y!=INF);
				ans*=modinv(x); ans%=MOD;
				ans*=y; ans%=MOD;
			}
			else{
				if(abs(y*x2)>=abs(y2*x)){
					ans*=modinv(x); ans%=MOD;
					ans*=y; ans%=MOD;
				}
				else{
					ans*=modinv(x2); ans%=MOD;
					ans*=y2; ans%=MOD;
				}
			}


			cout << (ans+MOD)%MOD << endl;
		}

	}

	





	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
