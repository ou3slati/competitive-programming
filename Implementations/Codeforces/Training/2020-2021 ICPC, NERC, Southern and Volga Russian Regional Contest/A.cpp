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
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //up down right left

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



int main() {
    boost; IO();

    unordered_map<char,int> mpd;
    mpd['U']=0;
    mpd['D']=1;
    mpd['R']=2;
    mpd['L']=3;

    int TC; cin>>TC;
    while(TC--){
    	str s; cin>>s;
    	int N=sz(s);
    	map<pi,pair<pi,pi>> mp; //left right down up 
    	int x=0,y=0;
    	int cnt=0; char p='0';
    	int val[sz(s)];
    	ROF(i,0,sz(s)){
    		if(s[i]==p) cnt++;
    		else cnt=1;
    		p=s[i];
    		val[i]=cnt;
    	}
    	//FOR(i,0,N) cout << val[i] << ' '; cout << endl;
    	FOR(i,0,sz(s)){
    		char c=s[i];
    		int cnt=val[i];
    		x+=nx[mpd[c]]; y+=ny[mpd[c]];

    		if(!mp.count({x,y})) mp[{x,y}]={{0,0},{0,0}};
    		if(c=='L') mp[{x,y}].fi.fi+=cnt;
    		else if(c=='R') mp[{x,y}].fi.se+=cnt;
    		else if(c=='D') mp[{x,y}].se.fi+=cnt;
    		else mp[{x,y}].se.se+=cnt;
    	}
    	//cout << x << ' ' << y << endl;
    	int X=0,Y=0;
    	for(auto i: mp){
    		int xx=i.fi.fi,yy=i.fi.se,l=i.se.fi.fi,r=i.se.fi.se;
    		int d=i.se.se.fi,u=i.se.se.se;
    		here();
    		dbgs(xx,yy);
    		dbgs(l,r);
    		dbgs(d,u);
    		if(r-l==x && u-d==y){
    			X=i.fi.fi;
    			Y=i.fi.se;
    			//if(X!=0 || Y!=0) break;
    		}
    	}

    	cout << X << ' ' << Y << endl;
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