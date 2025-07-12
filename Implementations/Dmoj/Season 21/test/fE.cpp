//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef string str;
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
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)

const int MOD = 1e9 + 7; 
const int MOD2=998244353;
const ll INF = 1e18;
const int MX = 3e6 + 10;
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

int N,Q;
int P=29;

int modpow(int p){
	if(p==0) return 1;
	ll x=modpow(p/2);
	x*=x; x%=MOD;
	if(p%2) x*=P; x%=MOD;
	return x;
}

unordered_map<int,vi> mp;
int ppp[1000001];
int power(int p){
	//if(p<=1000000) 
		return ppp[p];
	//return modpow(p);
}


int trie[MX][26]; vi v[MX];
int cnt=0;
void add(str s, int x){
	int u=0;
	for(auto x: s){
		if(trie[u][x-'a']==-1){
			trie[u][x-'a']=++cnt;
			FOR(i,0,26) trie[cnt][i]=-1;
		}
		u=trie[u][x-'a'];
	}
	v[u].pb(x);
}

int in[MX],out[MX];
void dfs(int u){
	in[u]=++cnt;
	for(auto x: v[u]) mp[x].pb(in[u]);

	FOR(i,0,26) if(trie[u][i]!=-1) dfs(trie[u][i]);
	out[u]=cnt;
}

int doHash(str s){
	ll ans=0;
	FOR(i,0,sz(s)){
		ans+=((s[i]-'a'+1)*power(i))%MOD;
		ans%=MOD;
	}

	return ans;
}

int dive(str s){
	int u=0;
	for(auto x: s){
		if(trie[u][x-'a']==-1) return -1;
		u=trie[u][x-'a'];
	}
	return u;
}

int solve(int x, int l, int r){
	if(!mp.count(x)) return 0;
	vi vec=mp[x];
	int it=lower_bound(all(vec),l)-vec.begin();
	int itr=upper_bound(all(vec),r)-vec.begin(); 
	return max(0,itr-it);
}


void ss(){
	ppp[0]=1;
    FOR(j,1,1000000){
    	ppp[j]=(ppp[j-1]*P)%MOD;
    }
}

int main() {
    boost; IO();

    FOR(i,0,26) trie[0][i]=-1;

    ss();

    cin>>N>>Q;
    FOR(i,0,N){
    	str s; cin>>s;   	
    	int n=sz(s);
    	ll hsh[n+1],hsh2[n+1]; hsh[n]=hsh2[n]=0; 
    	ROF(i,0,n){
    		hsh[i]=(hsh[i+1]+((s[i]-'a'+1)*power(n-i-1))%MOD)%MOD;
    	}

    	str cur;
    	add(cur,hsh[0]);
    	FOR(i,0,n){
    		cur+=s[i];
    		add(cur,hsh[i+1]);
    	}
    }

    cnt=0;
    dfs(0);

    while(Q--){
    	str s; cin>>s;
   		str l,r;
   		int i=0;
   		while(s[i]!='*'){
   			l.pb(s[i]);
   			i++;
   		}
   		i++;
   		while(i<sz(s)){
   			r.pb(s[i]);
   			i++;
   		}

   		int node=dive(l);
   		if(node==-1){ //!!!!
   			cout << 0 << endl;
   			continue;
   		}
   		reverse(all(r));
   		int v=doHash(r);
   		int lft=in[node],rght=out[node];
   		cout << solve(v,lft,rght) << endl;
    }
    

    return 0;
}


/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/