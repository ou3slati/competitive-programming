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

int N;
str s;
vi a(11);

bool dig(char c){
	return c>='0' && c<='9';
}

bool check(str ss){
	FOR(i,0,N){
		if(i!=N-1){
			str cur; cur+=ss[i*2]; cur+=ss[i*2+1];
			bool y=false;
			if(cur=="x-") y=true;
			if(dig(cur[0]) && 
				(cur[1]=='/' || 
					(dig(cur[1]) && (cur[0]-'0')+(cur[1]-'0')<10))) y=true;
			if(!y) return false;
		}
		else{
			str cur; cur+=ss[i*2]; cur+=ss[i*2+1]; cur+=ss[i*2+2];
			bool y=false;
			if(cur=="xxx") y=true;
			if(cur[0]=='x'&& cur[1]=='x' && dig(cur[2])) y=true;
			if(cur[0]=='x' && dig(cur[1]) && cur[2]=='/') y=true;
			if(cur[0]=='x' && dig(cur[1]) && dig(cur[2]) && cur[1]-'0'+cur[2]-'0'<10)
				y=true;
			if(dig(cur[0]) && cur[1]=='/' && cur[2]=='x') y=true;
			if(dig(cur[0]) && cur[1]=='/' && dig(cur[2])) y=true;
			if(dig(cur[0]) && dig(cur[1]) && cur[0]-'0'+cur[1]-'0'<10 && cur[2]=='-') 
				y=true;
			if(!y) return false;
		}
	}
	return true;
}

int cnt(int i, int st, str ss){
	assert(i<sz(ss) && i+1<sz(ss));
	if(dig(ss[i]) && ss[i+1]=='/'){
		if(st==0) return 10;
		return ss[i]-'0';
	}
	if(ss[i]=='x') return 10;
	if(dig(ss[i])) return ss[i]-'0';
	return 0;
}

vi solve2(str ss){
	vi ans(N,0);
	FOR(i,0,N){
		if(i!=N-1){
			str cur; cur+=ss[i*2]; cur+=ss[i*2+1];
			if(cur=="x-"){
				ans[i]=10;
				ans[i]+=cnt(i*2+2,0,ss)+cnt(i*2+3,1,ss);
			}
			else if(cur[1]=='/'){
				ans[i]=10; ans[i]+=cnt(i*2+2,1,ss);
			}
			else{
				ans[i]=cur[0]-'0'+cur[1]-'0';
			}
			
		}
		else{
			str cur; cur+=ss[i*2]; cur+=ss[i*2+1]; cur+=ss[i*2+2];
			if(cur=="xxx") 
				ans[i]=30;
			if(cur[0]=='x'&& cur[1]=='x' && dig(cur[2])) 
				ans[i]=20+cur[2]-'0';
			if(cur[0]=='x' && dig(cur[1]) && cur[2]=='/')
				ans[i]=20;
			if(cur[0]=='x' && dig(cur[1]) && dig(cur[2]) && cur[1]-'0'+cur[2]-'0'<10)
				ans[i]=10+cur[1]-'0'+cur[2]-'0';
			if(dig(cur[0]) && cur[1]=='/' && cur[2]=='x') 
				ans[i]=20;
			if(dig(cur[0]) && cur[1]=='/' && dig(cur[2]))
				ans[i]=10+cur[2]-'0';
			if(dig(cur[0]) && dig(cur[1]) && cur[0]-'0'+cur[1]-'0'<10 && cur[2]=='-') 
				ans[i]=cur[0]-'0'+cur[1]-'0';
		}
	}
	return ans;
}

int solve(int i, str cur){
	if(i==N*2+1){
		
		if(!check(cur)) return 0;
		vi ans=solve2(cur);		

		FOR(j,0,N) if(a[j]!=-1 && a[j]!=ans[j]) return 0;
		return 1;
	}

	int ans=0;
	str nxt=cur;
	if(s[i]!='?'){
		nxt+=s[i];
		ans=solve(i+1,nxt);
	}
	else{
		nxt+='x'; ans+=solve(i+1,nxt);
		nxt.pop_back(); nxt+='-'; ans+=solve(i+1,nxt);
		nxt.pop_back(); nxt+='/'; ans+=solve(i+1,nxt);
		for(char c='0'; c<='9'; c++){
			nxt.pop_back(); nxt+=c; ans+=solve(i+1,nxt);
		}
	}

	return ans;
}

int main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	cin>>N>>s;
    	FOR(i,0,N) cin>>a[i];
    	str cur;
    	cout << solve(0,cur) << endl;
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