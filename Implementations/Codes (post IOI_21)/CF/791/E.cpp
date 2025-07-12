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

const int MOD = 998244353; 
const ll INF = 2e9;
const int MX = 1e3 + 10;
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
str s; 

int main() {
    boost; IO();


    cin>>N>>s;

    int empty_spaces=0; 
    for(char c: s) if(c=='?') empty_spaces++; 

    int dp[N][N]; 
		
	map<char,int>mp; 

    ROF(i,0,N) FOR(j,i,N){
    	if(s[i]!=s[j] && s[i]!='?' && s[j]!='?'){ dp[i][j]=-INF; continue; }

    	if(i==j){
    		dp[i][j]=empty_spaces; 
    	}
    	else if(i+1==j){
    		if(s[i]=='?' && s[j]=='?') dp[i][j]=empty_spaces-1; 
    		else if(s[i]!='?' && s[j]!='?') dp[i][j]=empty_spaces; 
    		else{
    			dp[i][j]=empty_spaces-1; 
    			if(s[i]!='?') mp[s[i]]+=dp[i][j]; 
    			else mp[s[j]]+=dp[i][j]; 
			}
    	}
    	else{
    		dp[i][j]=dp[i+1][j-1]; 
    		dp[i][j]-=(s[i]=='?') + (s[j]=='?'); 
    		if(s[i]=='?' && s[j]=='?') dp[i][j]++; 
    		else if(s[i]!='?' && s[j]!='?'){;}
    		else{
    			if(s[i]!='?') mp[s[i]]+=dp[i][j]; 
    			else mp[s[j]]+=dp[i][j]; 
			}
    	}

    	if(dp[i][j]<0) dp[i][j]=-INF; 
    }


    int power[18][1000]; 
    FOR(x,1,18){
    	power[x][0]=1; 
    	FOR(i,1,1000) power[x][i]=(power[x][i-1]*x)%MOD; 
    } 

    vi ans(18,0); 
    FOR(x,1,18){
    	FOR(i,0,N) FOR(j,i,N) if(dp[i][j]>=0) {
    		ans[x]+=power[x][dp[i][j]]; 
    		ans[x]%=MOD; 
    	}
    }

    int Q; cin>>Q;
    while(Q--){
    	str ss; cin>>ss; 

    	int n=sz(ss);
    	cout << ans[n] << endl;	
    }
    

    return 0;
}
//Change your approach 