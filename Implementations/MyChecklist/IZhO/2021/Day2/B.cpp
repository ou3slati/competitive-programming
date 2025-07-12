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

const int MX = 1e6 + 3;
const int LOG=21;
int N; 
vi b(MX); 
vector<ll>pref(MX,0);

vi lft(MX),rgt(MX);

int jump[MX][LOG],jumpVal[MX][LOG];

ll get(int i, int j){
	int l=lft[i]+1,r=rgt[i];
	ll x=pref[r]-pref[l-1];
	return max(0ll,b[j]-x);
}

bool e(int i){
	if(i==0 || i==N) return 1;
	return (!lft[i] || rgt[i]>=N);
}

bool cmp(int i, int j){
	return b[i]>b[j];
}
void precompute(){
	lft.assign(N,0); rgt.assign(N,N);
	vi st;
	FOR(i,1,N){
		while(sz(st) && b[st.back()]<=b[i])
			st.pop_back();
		if(sz(st)) lft[i]=st.back();
		
		st.pb(i);
	}
	st.clear();
	ROF(i,1,N){
		while(sz(st) && b[st.back()]<=b[i])
			st.pop_back();
		if(sz(st)) rgt[i]=st.back();
		
		st.pb(i);
	}

	FOR(i,1,N){
		jump[i][0]=lft[i];
		if(b[rgt[i]]<b[lft[i]]) jump[i][0]=rgt[i];

		jumpVal[i][0]=get(i,jump[i][0]);
	}

	FOR(i,0,LOG) jump[0][i]=0,jump[N][i]=N; 

	vi vec(N-1); iota(all(vec),1);
	sort(all(vec),cmp);
	for(int u: vec){
		FOR(i,1,LOG){
			jump[u][i]=jump[jump[u][i-1]][i-1];
			jumpVal[u][i]=
			max(jumpVal[u][i-1],jumpVal[jump[u][i-1]][i-1]);
		}
	}
	return; 
}

int main() {
    boost; IO();

    cin>>N; N+=2;
    FOR(i,1,N+1){
    	pref[i]=0;
    	if(i!=1 && i!=N) cin>>pref[i];
    	pref[i]+=pref[i-1];
	}
    FOR(i,1,N){
    	cin>>b[i];
	}

    precompute();

    FOR(j,2,N){
    	int idx; 
    	if(j==N) idx=N-1;
    	else if(j==1) idx=1;
    	else{
    		idx=j;
    		if(b[j-1]<b[j]) idx=j-1;
    	}

    	int ans=max(0ll,b[idx]-(pref[j]-pref[j-1]));

    	if(e(idx)){
    		cout << ans << ' ';
    		continue;
    	}
    	int u=idx;
    	ROF(i,0,LOG) if(!e(jump[u][i])){
    		ckmax(ans,jumpVal[u][i]);
    		u=jump[u][i];
    	}
    	ckmax(ans,jumpVal[u][0]);
    	cout << ans << ' ';
    }



    return 0;
}
//Change your approach 