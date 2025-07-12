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
const ll INF = 1e8;
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

int N; 
vi a(MX),pref(MX,0);

int sum(int i, int j){
	return pref[j]-pref[i-1];
}

int main() {
    boost; IO();

    cin>>N;

    FOR(i,1,N+1){
    	cin>>a[i];
    	pref[i]=a[i];
    	pref[i]+=pref[i-1];
    }

    int dp[N+1][N+1],dp2[N+1][N+1];
    FOR(j,1,N+1){
    	int k=j-1;
    	ROF(i,1,j+1){
	    	if(i==1) dp[i][j]=1;
	    	else{
	    		if(sum(1,i-1)<sum(i,j)){
	    			dp[i][j]=-INF;
	    			continue;
	    		}
	    		while(k>=1 && sum(k,i-1)<sum(i,j)) k--;
	    		assert(k>=1);

	    		dp[i][j]=dp[k][i-1]+1;
	    	}
	    }
	    FOR(i,2,j+1) ckmax(dp[i][j],dp[i-1][j]);
    }

    ROF(i,1,N+1){
    	int k=i+1;
    	FOR(j,i,N+1){
	    	if(j==N) dp2[i][j]=1;
	    	else{
	    		if(sum(j+1,N)<sum(i,j)){
	    			dp2[i][j]=-INF;
	    			continue;
	    		}
	    		while(k<=N && sum(j+1,k)<sum(i,j)) k++;
	    		assert(k<=N);

	    		dp2[i][j]=dp2[j+1][k]+1;
	    	}
	    }
	    ROF(j,i,N) ckmax(dp2[i][j],dp2[i][j+1]);
    }

    int ans=0;
    FOR(i,0,N+1){
    	int l=0,r=0;
    	if(i) l=dp[i][i];
    	if(i+1<=N) r=dp2[i+1][i+1];
    	ckmax(ans,l+r);
    }
    cout << ans << endl;



    return 0;
}
//Change your approach 


/*
15
9 4 5 4 5 10 7 3 10 10 1 3 5 2 5 
9
*/
