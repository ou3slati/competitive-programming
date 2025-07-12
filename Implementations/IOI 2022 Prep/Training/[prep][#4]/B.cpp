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

int L,R,X,Y; 

vi vec; 
void f(int x){
	vec.clear(); 

	for(int i=2; i*i<=x; i++){
		while(x%i==0){
			vec.pb(i);
			x/=i; 
		}
	}
	if(x>1) vec.pb(x); 
}

int power(int x, int p){
	return (int)(pow(x,p)+0.5); 
}

int32_t main() {
    boost; IO();

    cin>>L>>R>>X>>Y; 

    map<int,int>mpx,mpy; 
    f(X); 
    for(int x: vec) mpx[x]++,mpy[x]=0;

    f(Y); 
	for(int x: vec){ mpy[x]++; if(!mpx.count(x)) mpx[x]=0;}

	int Z=1; 
	vec.clear(); 
	for(auto it: mpx){
		int x=it.fi; 
		if(mpx[x]>mpy[x]){
			cout << 0 << endl;
			return 0; 
		}
		if(mpx[x]==mpy[x]) Z*=power(x,mpx[x]); 
		else vec.pb(x);
	}



	map<int,int>vis; 

	int n=sz(vec), ans=0; 
	FOR(m,0,(1<<n)){
		int a=Z, b=Z; 

		FOR(i,0,n){
			int x=vec[i]; 

			if((m>>i)&1){
				a*=power(x,mpx[x]), b*=power(x,mpy[x]); 
			}
			else{
				b*=power(x,mpx[x]), a*=power(x,mpy[x]); 
			}
		}

		if(__gcd(a,b)==X && a*b==X*Y && min(a,b)>=L && max(a,b)<=R && !(a==b && vis.count(a))){
			if(a==b) vis[a]=1; 
			ans++; 
		}
	}
    cout << ans << endl;

    return 0;
}
//Change your approach 