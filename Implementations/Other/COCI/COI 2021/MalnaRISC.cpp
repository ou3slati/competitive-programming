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


int32_t main() {
    boost; IO();

    int N; cin>>N;

    set<pi>s;
    FOR(i,1,N+1) FOR(j,i+1,N+1) s.insert({i,j});

    int cnt=0;
    vector<str>ans;
    while(sz(s)){
    	vi vis(N+1,0);

    	vpi vec;
    	for(auto it: s){
    		int i=it.fi,j=it.se;
    		if(!vis[i] && !vis[j]){
    			vis[i]=1; vis[j]=1;
    			vec.eb(i,j);
    		}
    	}
    	cnt++;
    	str ss;
    	for(auto it : vec){
    		int i=it.fi,j=it.se;
    		ss+="CMPSWP R"; 
    		ss+=to_string(i);
    		ss+=" R";
    		ss+=to_string(j);
    		ss+=" ";

    		s.erase(it);
    	} 
    	ans.pb(ss);
    }

    /*int rep=N+N/2+N/3;
    if(cnt>rep){
    	cout << rep << endl;
    	FOR(idx,0,rep){
    		str ss;
	    	if(!(idx&1)){
	    		for(int i=1; i<=N; i+=2){
	    			ss+="CMPSWP R"; 
		    		ss+=to_string(i);
		    		ss+=" R";
		    		ss+=to_string(i+1);
		    		ss+=" ";
	    		}
	    	}
	    	else{
	    		for(int i=2; i<=N; i+=2){
	    			ss+="CMPSWP R"; 
		    		ss+=to_string(i);
		    		ss+=" R";
		    		ss+=to_string(i+1);
		    		ss+=" ";
	    		}
	    	}
	    	cout << ss << endl;
	    }
	    return 0;
    }*/

	cout << cnt << endl;
	for(auto x: ans) cout << x << endl;


	

    

    return 0;
}
//Change your approach 