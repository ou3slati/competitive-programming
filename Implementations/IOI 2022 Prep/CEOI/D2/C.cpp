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

#define free freee

void no(){
	cout << -1 << endl;
	exit(0); 
}

int N,M;

vi vec[MX], szz(MX), free, vis(MX,0), top[MX];
set<pi,greater<pi>>unvis; 

int main() {
    boost; IO();

    cin>>N>>M;
    FOR(i,1,M+1){
    	FOR(j,0,2){
    		int x; cin>>x;
    		if(x) vec[i].pb(x); 
    	}
    } 
    
    FOR(i,1,M+1){
    	if(sz(vec[i])==2 && vec[i][0]==vec[i][1]) 
    		vis[vec[i][0]]=1; 

		szz[i]=sz(vec[i]); 
		if(!szz[i]) free.pb(i); 
		else top[vec[i].back()].pb(i); 
	}
	FOR(i,1,N+1) if(!vis[i]){
		unvis.insert({sz(top[i]),i});
	}

    vpi ans;  
    while(sz(unvis)){
    	int c=(*unvis.begin()).se; 

    	if(sz(top[c])==1){
    		//move to one of the free ones
    		if(!sz(free)) no(); 

    		int i=top[c][0], j=free.back(); 
    		ans.eb(i,j); 

    		vec[i].pop_back(); vec[j].pb(c); 
    		szz[i]--; szz[j]++; 
    		free.pop_back(); if(!szz[i]) free.pb(i); 

    		top[c][0]=j; 
    		if(szz[i]) top[vec[i].back()].pb(i); 

    		int c2=vec[i].back(); 
    		unvis.erase({sz(top[c2])-1,c2}); 
    		unvis.insert({sz(top[c2]),c2}); 
    	}
    	else if(sz(top[c])==2){
    		//move them together (same of not same)

    		int i=top[c][0], j=top[c][1]; 

    		if(szz[i]==2 && szz[j]==2){
    			if(!sz(free)) no(); 
    			
    			int k=free.back(); free.pop_back(); 
    			ans.eb(i,k); ans.eb(j,k); 

    			vec[k].pb(c); vec[k].pb(c); 
				vec[i].pop_back(); vec[j].pop_back(); 

				szz[k]=2; szz[i]--; szz[j]--; 

				vis[c]=1; 

    			int c1=vec[i][0], c2=vec[j][0]; 
    			top[c1].pb(i); top[c2].pb(j);

    			unvis.erase(unvis.begin()); 
    			unvis.erase({sz(top[c1])-1,c1}); 
    			unvis.insert({sz(top[c1]),c1}); 
    			unvis.erase({sz(top[c2])-1,c2}); 
    			unvis.insert({sz(top[c2]),c2}); 
    		}
    		else{
    			if(szz[j]==1) swap(i,j); 
    			
	    		ans.eb(j,i); 
	    		
	    		vec[i].pb(c); vec[j].pop_back(); 
	    		szz[i]++; szz[j]--; 

	    		if(!szz[j]) free.pb(j); 

	    		vis[c]=1; 
	    		unvis.erase(unvis.begin()); 
	    		
	    		if(sz(vec[j])){
	    			int c2=vec[j][0]; 
    				top[c2].pb(j);

    				unvis.erase({sz(top[c2])-1,c2}); 
    				unvis.insert({sz(top[c2]),c2}); 
	    		}


	    		
	    	}
    	}
    }



    cout << sz(ans) << endl;
    for(auto it: ans){
    	int x=it.fi, y=it.se; 
    	cout << x << ' ' << y << endl;
    }
    

    return 0;
}
//Change your approach 