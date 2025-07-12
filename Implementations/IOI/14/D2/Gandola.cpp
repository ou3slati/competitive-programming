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

const ll MOD = 1e9 + 9; //998244353
const ll INF = 1e9;
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

#ifndef LOCAL
#include "gondola.h"
#endif

int valid(int N, int b[]){
	int a[N]; FOR(i,0,N) a[i]=b[i];

	//no duplicates
	sort(a,a+N);
	FOR(i,1,N) if(a[i]==a[i-1]) return 0;

	deque<pi> vec;
	int st=INF;
	FOR(i,0,N) if(a[i]<=N){
		vec.eb(a[i],i);
		ckmin(st,a[i]);
	}
	while(sz(vec) && vec[0].fi>st){
		vec.eb(vec[0].fi,vec[0].se+N);
		vec.pop_front();
	}

	//must be in order & have right distance
	FOR(i,1,sz(vec)){
		if(vec[i].fi<=vec[i-1].fi) return 0;
		if(vec[i].fi-vec[i-1].fi!=vec[i].se-vec[i-1].se) return 0;
	}

	return 1;
}

//----------------------

int replacement(int N, int a[], int ans[]){
	vpi vec;
	FOR(i,0,N) if(a[i]>N) vec.eb(a[i],i);
	sort(all(vec));

	if(sz(vec)==N){
		FOR(i,0,N) a[i]=i+1;
	}
	else{
		FOR(i,0,N) if(a[i]<=N){
			FOR(j,i+1,N) a[j]=a[j-1]+1;
			ROF(j,0,i) a[j]=a[j+1]-1;
			break;
		}
		FOR(i,0,N){
			if(a[i]<=0) a[i]+=N;
			else if(a[i]>N) a[i]-=N;
		}
	}

	int p=N,cnt=0;
	for(auto it: vec){
		int x=it.fi,idx=it.se;
		FOR(j,0,x-p){
			ans[cnt++]=a[idx];
			a[idx]=N+cnt;
		}
		p=x;
	}
	return cnt;
}

//----------------------

ll modpow(int x, int p){
	if(!p) return 1;
	ll v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p&1) v*=x,v%=MOD;
	return v;
}

ll f(int n){
	ll ans=1;
	FOR(i,1,n+1) ans*=i,ans%=MOD;
	return ans;
}

int countReplacement(int N, int a[]){
	if(!valid(N,a)) return 0;

	vpi vec;
	FOR(i,0,N) if(a[i]>N) vec.eb(a[i],i);
	sort(all(vec));

	int p=N; ll ans=1;
	FOR(i,0,sz(vec)){
		int x=vec[i].fi;

		ans*=modpow(sz(vec)-i,x-p-1); 
		ans%=MOD;

		p=x;
	}
	if(sz(vec)==N) ans*=N,ans%=MOD;
	return ans;
	
}

#ifdef LOCAL
int main() {
    boost; IO();

    int N; cin>>N;
    int a[N],ans[N*10];
    FOR(i,0,N) cin>>a[i];
    //cout << valid(N,a) << endl;
    cout << countReplacement(N,a) << endl;
    

    return 0;
}
#endif
//Change your approach 