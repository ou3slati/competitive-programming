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

int N,M;
vi vec[MX], vis(MX,0); 

int check(){
	FOR(i,1,N+1) if(!vis[i]) return 0; 
	return 1; 
}

void no(){
	cout << -1 << endl;
	exit(0); 
}

int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,1,M+1){
    	FOR(j,0,2){
    		int x; cin>>x;
    		if(x) vec[i].pb(x); 
    	}
    	if(sz(vec[i])==2 && vec[i][0]==vec[i][1]) 
    		vis[vec[i][0]]=1; 
    } 


    vpi ans;  
    while(!check()){
    	vi top[N+1],szz(M+1); 
    	int free=-1;

    	FOR(i,1,M+1){
    		szz[i]=sz(vec[i]); 
    		if(!szz[i]) free=i; 
    		else top[vec[i].back()].pb(i); 
    	}

    	int add=0; 
    	FOR(c,1,N+1) if(!vis[c] && sz(top[c])==2){
    		int i=top[c][0], j=top[c][1]; 

    		if(szz[i]==1){
    			vec[i].pb(c); 
    			vec[j].pop_back(); 
    			ans.eb(j,i); 

    			vis[c]=1; add=1; 
    			break;
    		}
    		else if(szz[j]==1){
    			vec[j].pb(c); 
    			vec[i].pop_back(); 
    			ans.eb(i,j); 

    			vis[c]=1; add=1; 
    			break;
    		}
    	}

    	if(!add){
	    	FOR(c,1,N+1) if(!vis[c] && sz(top[c])==2){
	    		int i=top[c][0], j=top[c][1]; 

	    		if(szz[i]==2 && szz[j]==2){
	    			int c1=vec[i][0], c2=vec[j][0]; 
	    			if(free!=-1 && (sz(top[c1]) || sz(top[c2]))){
	    				vec[free].pb(c); vec[free].pb(c); 
	    				vec[i].pop_back(); vec[j].pop_back(); 
	    				ans.eb(i,free); ans.eb(j,free); 

	    				vis[c]=1; add=1; 
	    				break;
	    			}
	    		}
	    	}
    	}


    	if(!add){
    		FOR(c,1,N+1) if(!vis[c] && sz(top[c])==1){
    			int i=top[c][0]; 
    			if(sz(vec[i])==2 && free!=-1){
    				vec[free].pb(c); 
	    			vec[i].pop_back(); 
	    			ans.eb(i,free); 

	    			add=1; 
	    			break; 
    			}
    		}
    	}

    	if(!add) no(); 
    }




    cout << sz(ans) << endl;
    for(auto it: ans){
    	int x=it.fi, y=it.se; 
    	cout << x << ' ' << y << endl;
    }
    

    return 0;
}
//Change your approach 