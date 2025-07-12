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
const int MX = 2000 + 10;
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

int N,K; 
vi a(MX,0); 

int vec[10][7]; 

int f(int m, int d){
	int ans=0; 
	FOR(i,0,7){
		if(!vec[d][i] && (m>>i)&1) return -1;
		if(vec[d][i] && !((m>>i)&1)) ans+=1; 
	}
	return ans; 
}

int memo[MX][MX]; 
int solve(int i, int r){
	if(r<0) return 0; 
	if(i==N) return (r==0); 
	
	int &ind=memo[i][r]; 
	if(ind!=-1) return ind; 	

	int ans=0; 
	FOR(d,0,10){
		int x=f(a[i],d); 
		if(x!=-1 && solve(i+1,r-x)) ans=1; 
	}

	return ind=ans; 
}

int main() {
    boost; IO();
    
    memset(memo,-1,sizeof(memo)); 

    memset(vec,0,sizeof(vec)); 

    for(int i: {0,1,2,4,5,6}) vec[0][i]=1;
	for(int i: {2,5}) vec[1][i]=1;
	for(int i: {0,2,3,4,6}) vec[2][i]=1;
	for(int i: {0,2,3,5,6}) vec[3][i]=1;
	for(int i: {1,2,3,5}) vec[4][i]=1;
	for(int i: {0,1,3,5,6}) vec[5][i]=1;
	for(int i: {0,1,3,4,5,6}) vec[6][i]=1;
	for(int i: {0,2,5}) vec[7][i]=1;
	for(int i: {0,1,2,3,4,5,6}) vec[8][i]=1;
	for(int i: {0,1,2,3,5,6}) vec[9][i]=1;


    cin>>N>>K; 
    FOR(i,0,N){
    	str s; cin>>s; 
    	ROF(j,0,7){
    		a[i]*=2; 
    		a[i]+=s[j]-'0';
    	}
    }

    int cur=K; 
    vi ans; 
    FOR(i,0,N){
    	int dig=-1; 
    	ROF(d,0,10){
    		int x=f(a[i],d);

    		if(x!=-1 && solve(i+1,cur-x)){
    			cur-=x; 
    			ans.pb(d);
    			dig=d;  
    			break; 
    		}
    	}

    	if(dig==-1){
    		cout << -1 << endl;
    		return 0;
    	}
    }

    for(int x: ans) cout << x; 
    cout << endl;


    return 0;
}
//Change your approach 