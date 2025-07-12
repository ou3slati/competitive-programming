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
const int MX = 2e5 + 100;
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
#include "paint.h"
#endif

const int C=2;
const int MX2=104;
int N,K; 
str s; 
vi c,white(MX,0),black(MX,0),pref(MX);
int memo[MX][MX2],memo2[MX][MX2];


bool check(int l, int r){
	if(!(min(l,r)>=0 && max(l,r)<N)) return 0;
	int x=pref[r];
	if(l) x-=pref[l-1];

	bool y=1;
	if(l && s[l-1]=='X') y=0;
	else if(r+1<N && s[r+1]=='X') y=0;

	return (x==0 && y);
}

int can(int i, int j){
	if(i<0) return (j<0);
	

	if(memo[i+C][j+C]!=-1) return memo[i+C][j+C];

	int ans;
	if(s[i]=='_') ans=can(i-1,j);
	else if(s[i]=='X'){
		if(j<0) ans=0;
		else{
			bool b=check(i-c[j]+1,i);
			if(!b) ans=0;
			else ans=can(i-c[j]-1,j-1);

		}
	}
	else{
		ans=can(i-1,j);
		bool b=check(i-c[j]+1,i);
		if(j>=0 && b) ans|=can(i-c[j]-1,j-1);
	}

	return memo[i+C][j+C]=ans;
}

int can2(int i, int j){
	if(i>N-1) return (j>K-1);

	if(memo2[i+C][j+C]!=-1) return memo2[i+C][j+C];

	int ans;
	if(s[i]=='_') ans=can2(i+1,j);
	else if(s[i]=='X'){
		if(j>K-1) ans=0;
		else{
			bool b=check(i,i+c[j]-1);
			if(!b) ans=0;
			else ans=can2(i+c[j]+1,j+1);
		}
	}
	else{
		ans=can2(i+1,j);
		bool b=check(i,i+c[j]-1);
		if(j<=K-1 && b) ans|=can2(i+c[j]+1,j+1);
	}

	return memo2[i+C][j+C]=ans;
}


str solve_puzzle(str s, vi c) {
    ::s=s;
    ::c.assign(all(c));
    N=sz(s); K=sz(c);
    FOR(i,0,N){
    	pref[i]=(s[i]=='_');
    	if(i) pref[i]+=pref[i-1];
    }
    memset(memo,-1,sizeof(memo));
    memset(memo2,-1,sizeof(memo2));


    FOR(i,0,N) FOR(j,-1,K) if(s[i]!='X'){
    	white[i]|=(can(i-1,j) && can2(i+1,j+1));
    }

    vi vec(N+1,0);
    FOR(i,0,N) FOR(j,0,K) if(check(i,i+c[j]-1)){
    	if(can(i-2,j-1) && can2(i+c[j]+1,j+1)){
    		vec[i]++;
    		vec[i+c[j]]--;
    	}
    }
    FOR(i,0,N){
    	if(i) vec[i]+=vec[i-1];
    	black[i]=(vec[i]>0);
    }
    
    str ans;
    ans.resize(N);
    FOR(i,0,N){
    	if(white[i] && black[i]) ans[i]='?';
    	else if(white[i]) ans[i]='_';
    	else ans[i]='X';
    	if(!white[i] && !black[i]) assert(0);
    }
    return ans;
}



#ifdef LOCAL
int main() {
    boost; IO();

    str s; cin>>s;
    int K; cin>>K;
    vi c(K); FOR(i,0,K) cin>>c[i];

    cout << solve_puzzle(s,c) << endl;
    

    return 0;
}
#endif
//Change your approach 

/*
..........
2
3 4

??X???XX??
*/

/*
........
2
3 4

XXX_XXXX
*/

/*
..._._....
1
3

???___????
*/

/*
.X........
1
3

?XX?______
*/