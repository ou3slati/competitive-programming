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

int N,M,K; 

int modpow(int p){
    int x=2;
    if(!p) return 1;
    int v=modpow(p/2);
    v*=v; v%=MOD;
    if(p&1) v*=x,v%=MOD;
    return v;
}

int modinv(){
    return modpow(MOD-2);
}

int32_t main() {
    boost; IO();

    cin>>N>>M>>K;

    map<int,int>r,c,v[2][2],vv[2][2];
   	vector<pair<pi,int>> vec;
   	FOR(i,0,K){
   		char ch; cin>>ch;
   		int x,y,val=(ch=='+'); 
        cin>>x>>y; x--; y--;

        vec.pb({{x,y},val});
   		r[x]=1; c[y]=1;
   		v[val][y&1][x]=1;
   		vv[val][x&1][y]=1;
   	}

   	int fv=1,fh=1;
   	for(auto it: r) FOR(j,0,2){
        int i=it.fi;
   		if(v[j][0][i] && v[j][1][i]) fh=0;

   		if(v[j][0][i] && v[1-j][0][i]) fh=0;
   		if(v[j][1][i] && v[1-j][1][i]) fh=0;
	}
   	for(auto it: c) FOR(j,0,2){
        int i=it.fi; 
   		if(vv[j][0][i] && vv[j][1][i]) fv=0;

   		if(vv[j][0][i] && vv[1-j][0][i]) fv=0;
   		if(vv[j][1][i] && vv[1-j][1][i]) fv=0;
	}

   	int ans=0,cur=fh*modpow(N);
    for(auto it: r){
        cur*=modinv(),cur%=MOD;
   	}
   	ans+=cur;

   	cur=fv*modpow(M);
   	for(auto it: c){
   		cur*=modinv(),cur%=MOD;
   	}
   	ans+=cur; ans%=MOD;

    cur=0;
   	int f=1;
   	for(auto it: vec){
        int i=it.fi.fi,j=it.fi.se,val=it.se;
   		if(i%2==0){
   			if(j%2==0 && val==1) f=0;
   			else if(j&1 && !val) f=0;
   		}
   		else{
   			if(j&1 && val==1) f=0;
   			else if(j%2==0 && !val) f=0;
   		}
   	}
   	cur+=f;

   	f=1;
    for(auto it: vec){
        int i=it.fi.fi,j=it.fi.se,val=it.se;
   		if(i&1){
   			if(j%2==0 && val==1) f=0;
   			else if(j&1 && !val) f=0;
   		}
   		else{
   			if(j&1 && val==1) f=0;
   			else if(j%2==0 && !val) f=0;
   		}
   	}
   	cur+=f;

    ans-=cur; ans+=MOD; ans%=MOD; 
    cout << ans << endl;

    return 0;
}
//Change your approach 