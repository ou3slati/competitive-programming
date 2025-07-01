/*
CF 705B - TBD
https://codeforces.com/contest/1493/problem/B

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
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

int H,M;

bool check(int h, int m){
	vi t={h/10,h%10,m/10,m%10};
	
	for(auto x: t) if(!(x==0 || x==1 || x==2 || x==5 || x==8)) return 0;

	map<int,int>mp;
	mp[0]=0; mp[1]=1; mp[2]=5; mp[5]=2; mp[8]=8;
	vi nt;
	ROF(i,0,4) nt.pb(mp[t[i]]);

	int nh=nt[0]*10+nt[1],nm=nt[2]*10+nt[3];
	return (nh<H && nm<M);
}

int32_t main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	cin>>H>>M;
    	int h=0,m=0;
    	char c; 
    	cin>>c; h=c-'0'; 
    	h*=10; 
    	cin>>c; h+=c-'0';

    	cin>>c;
    	cin>>c; m=c-'0'; 
    	m*=10; 
    	cin>>c; m+=c-'0';

    	int a=-1,b=-1;
    	FOR(x,h,H){
			FOR(y,0,M){
				if(x==h && y<m) continue;
    			if(check(x,y)){
    				a=x,b=y;
    				break;
				}
    		}
    		if(a!=-1) break;
		}
    	if(a==-1){
    		FOR(x,0,h+1){
    			FOR(y,0,M){
	    			if(check(x,y)){
	    				a=x,b=y;
	    				break;
					}
	    		}
	    		if(a!=-1) break;
    		}
    	}
    	cout << a/10 << a%10 << ':' << b/10 << b%10 << endl;
    }
    

    return 0;
}
//Change your approach 