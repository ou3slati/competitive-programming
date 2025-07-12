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
const int MX = 1e6 + 10;
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

int N,M; 
str s,ss; 
V<str>a(MX); 

const int p=31; 
vi power(MX); 

int modpow(int x, int pw){
	if(!pw) return 1; 

	int v=modpow(x,pw/2);
	v*=v; v%=MOD; 

	if(pw&1) v*=x,v%=MOD; 
	return v; 
}

int modinv(int x){
	return modpow(x,MOD-2);
}


//----------

vi t(MX,0); 
void upd(int i, int x){
	for(;i<MX; i+=i&-i){
		t[i]+=x,t[i]%=MOD; 
		t[i]+=MOD; t[i]%=MOD; 
	}
}

int sum(int i){
	int ans=0;
	for(;i; i-=i&-i) ans+=t[i],ans%=MOD; 
	ans+=MOD; ans%=MOD; 
	return ans; 
}

int sumRange(int i, int j){
	int ans=sum(j)-sum(i-1); 
	ans%=MOD; ans+=MOD; ans%=MOD; 
	return ans; 
}

//--------



int32_t main() {
    boost; IO();

    cin>>s; 
    N=sz(s);

    int num; cin>>num; 
    FOR(i,0,num) cin>>a[i]; 

    if(num!=1){
    	vi cnt(26,0); 
    	FOR(i,0,num) cnt[a[i][0]-'a']=sz(a[i]); 

    	vpi vec; 
    	FOR(i,0,N){
    		if(!sz(vec) || (int)(s[i]-'a')!=vec.back().fi ) vec.eb(s[i]-'a',1); 
    		else vec[sz(vec)-1].se++; 

    		int c=vec.back().fi,rep=vec.back().se; 
    		if(rep==cnt[c]) vec.pop_back();  
    	}

    	for(auto x: vec){
    		int rep=x.se; 
    		while(rep--){
    			cout << char(x.fi+'a');
    		}
    	}
    	cout << endl;

    	return 0;
    }

    ss=a[0]; 
    M=sz(ss); 

    //-----------

    power[0]=1; 
    FOR(i,1,N){
    	power[i]=(power[i-1]*p)%MOD; 
	}

	int H=0; 
	FOR(i,0,M){
		int x=(power[i]*(ss[i]-'a'+1))%MOD; 
		H+=x; H%=MOD; 
	}


    //---------

    vi vec;
    str ans;  
    FOR(i,0,N){
    	vec.pb( ( (s[i]-'a'+1)*power[sz(vec)] )%MOD ); 
    	upd(sz(vec),vec.back()); 
    	ans+=s[i];

    	if(sz(vec)<M) continue; 

    	int x=sumRange(sz(vec)-M+1,sz(vec));
    	x*=modinv(power[sz(vec)-M]); x%=MOD; 

    	if(x==H){
    		int rep=M; 
    		while(rep--){
    			upd(sz(vec),-vec.back()); 
    			vec.pop_back(); 
    			ans.pop_back();
    		}
    	}
    }
	cout << ans << endl;

    

    return 0;
}
//Change your approach 