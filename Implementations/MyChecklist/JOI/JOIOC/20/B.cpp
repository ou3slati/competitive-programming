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

int N,M,g[MX][MX],in[MX][2],out[MX][2];
vi art(MX);

int node(int i, int j){
	return (i-1)*M+j;
}

bool check(int u){
	bool can=0;
	if(in[u][0]!=-1 && out[in[u][0]][1]!=-1) 
		can=1;
	if(in[u][1]!=-1 && out[in[u][1]][0]!=-1) 
		can=1;
	if(in[u][0]==-1 && in[u][1]==-1)
		can=1;
	return can;
}

void recheck(int u){
	bool v=1;
	if(in[u][0]!=-1 && !art[in[u][0]]) v=0;
	if(in[u][1]!=-1 && !art[in[u][1]]) v=0;
	art[u]=(!check(u) && v);
}

int32_t main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,1,N+1) FOR(j,1,M+1) cin>>g[i][j];

    memset(in,-1,sizeof(in)); memset(out,-1,sizeof(in));

    int dp[N+1][M+1]; 
    memset(dp,0,sizeof(dp));
    dp[N][M]=1;

    ROF(i,1,N+1) ROF(j,1,M+1) if(!g[i][j]){
    	if(i+1<=N && dp[i+1][j]){
    		out[node(i,j)][0]=node(i+1,j);
    		in[node(i+1,j)][0]=node(i,j);
    		dp[i][j]=1;
    	}
    	if(j+1<=M && dp[i][j+1]){
    		out[node(i,j)][1]=node(i,j+1); 
    		in[node(i,j+1)][1]=node(i,j);
    		dp[i][j]=1; 
    	}
    }

    art[1]=1;
    FOR(u,2,N*M+1){
    	recheck(u);
    }

    int Q; cin>>Q;
    while(Q--){
    	int x,y; cin>>x>>y;
    	int u=node(x,y);

    	if(!art[u]){ 
    		cout << 1 << endl;

    		queue<int>q,q2; 
    		q.push(u);

    		if(out[u][0]!=-1){
				if(in[out[u][0]][1]==-1) q2.push(out[u][0]);
				else in[out[u][0]][0]=-1,recheck(out[u][0]);
			}
			if(out[u][1]!=-1){
				if(in[out[u][1]][0]==-1) q2.push(out[u][1]);
				else in[out[u][1]][1]=-1,recheck(out[u][1]);
			}

    		while(!q.empty()){
    			int u=q.front();
    			q.pop();

    			if(in[u][0]!=-1){
    				if(out[in[u][0]][1]==-1) q.push(in[u][0]);
    				else out[in[u][0]][0]=-1,recheck(in[u][0]);
    			}

    			if(in[u][1]!=-1){
    				if(out[in[u][1]][0]==-1) q.push(in[u][1]);
    				else out[in[u][1]][1]=-1,recheck(in[u][1]);
    			}

    			in[u][0]=in[u][1]=-1;
    			out[u][0]=out[u][1]=-1;
    			art[u]=0;
    		}

    		while(!q2.empty()){
    			int u=q2.front();
    			q2.pop();

    			if(out[u][0]!=-1){
    				if(in[out[u][0]][1]==-1) q2.push(out[u][0]);
    				else in[out[u][0]][0]=-1,recheck(out[u][0]);
    			}
    			if(out[u][1]!=-1){
    				if(in[out[u][1]][0]==-1) q2.push(out[u][1]);
    				else in[out[u][1]][1]=-1,recheck(out[u][1]);
    			}

    			in[u][0]=in[u][1]=-1;
    			out[u][0]=out[u][1]=-1;
    			art[u]=0;
    		}
    	}
    	else{
    		cout << 0 << endl;
    	}
    }
    

    return 0;
}
//Change your approach 