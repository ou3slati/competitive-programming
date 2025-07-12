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


int inter(int l1, int r1, int l2, int r2){
	if(l1>l2){
		swap(l1,l2); 
		swap(r1,r2); 
	}
	return max(0ll, min(r1,r2)-l2); 
}

int32_t main() {
    boost; IO();

    int t; cin>>t; 
    while(t--){
    	int N; cin>>N; 
    	int a[2][N]; 
    	FOR(i,0,2) FOR(j,0,N){
    		char c; cin>>c; 
    		if(c=='*') a[i][j]=1;
    		else a[i][j]=0;
    	}


    	vector<vi>mn_p(2,vi(N,-1)); vector<vi>mx_p(2,vi(N,-1));
    	vector<vi>mn_s(2,vi(N,-1)); vector<vi>mx_s(2,vi(N,-1)); 


    	FOR(i,0,2){
    		FOR(j,0,N){
    			if(a[i][j]) mn_p[i][j] = j;
    			if(j && mn_p[i][j-1]!=-1) mn_p[i][j] = mn_p[i][j-1]; 

    			if(a[i][j]) mx_p[i][j] = j;
    			else if(j) mx_p[i][j] = mx_p[i][j-1];
    		}

    		ROF(j,0,N){
    			if(a[i][j]) mn_s[i][j] = j;
    			else if(j+1<N) mn_s[i][j] = mn_s[i][j+1]; 

 
    			if(a[i][j]) mx_s[i][j] = j;
    			if(j+1<N && mx_s[i][j+1]!=-1) mx_s[i][j] = mx_s[i][j+1]; 
    		}
    	}


    	int ans=INF; 
    	FOR(i,0,2){
    		FOR(j,0,N){
    			int x=0; 

    			if(j){
    				int l1=mn_p[i][j-1], r1=mx_p[i][j-1], l2=mn_p[1-i][j-1], r2=mx_p[1-i][j-1]; 
    				if(l1!=-1 && l2!=-1){
    					x+=j-min(l1,l2) + inter(l1,r1,l2,r2) + 1; 
    				}
    				else if(l1==-1 && l2!=-1){
    					x+=j-l2 + 1; 
    				}
    				else if(l2==-1 && l1!=-1){
    					x+=j-l1; 
    				}
    			}

    			int l1=mn_s[i][j], r1=mx_s[i][j], l2=mn_s[1-i][j], r2=mx_s[1-i][j]; 
				if(l1!=-1 && l2!=-1){
					x+=max(r1,r2) - j + inter(l1,r1,l2,r2) + 1; 
				}
				else if(l1==-1 && l2!=-1){
					x+=r2-j + 1; 
				}
				else if(l2==-1 && l1!=-1){
					x+=r1-j; 
				}

    			ckmin(ans,x); 
    		}
    	}
    	cout << ans << endl;
    }
    

    return 0;
}
//Change your approach 