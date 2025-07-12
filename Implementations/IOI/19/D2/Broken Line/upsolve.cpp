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
const ll INF = 2e9;
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

set<int>a,c;
set<int,greater<int>>b,d;
map<int,int>mpx,mpy;

vpi ans;

void rmv(int x, int y){
	a.erase(x);
	b.erase(x);
	c.erase(y);
	d.erase(y);
}

void add(int x, int y){
	a.insert(x);
	b.insert(x);
	c.insert(y);
	d.insert(y);
}


void attach(pi a, pi b){
	int x=a.fi,y=a.se,xx=b.fi,yy=b.se;
	ans.eb(x,yy); ans.eb(xx,yy);
}

int32_t main() {
    boost; IO();

    int N; cin>>N;

    //division
    FOR(i,0,N){
    	int x,y; cin>>x>>y;
    	mpx[x]=y; mpy[y]=x;
    	a.insert(x);
    	b.insert(x);
    	c.insert(y);
    	d.insert(y);
    }

    vpi v[3];
    int lx=0,ly=0;
    while(sz(a)){
    	int mnx=*a.begin(),mxx=*b.begin(),
    	mny=*c.begin(),mxy=*d.begin();

    	vi X(6),Y(6);
    	X[0]=lx,Y[0]=ly;
    	X[1]=mnx; Y[1]=mpx[mnx];
    	X[2]=mpy[mny]; Y[2]=mny;
    	X[3]=mxx; Y[3]=mpx[mxx];
    	X[4]=mpy[mxy]; Y[4]=mxy;

    	if(X[0]<X[1] && sz(v[0])){
    		v[1].eb(v[0].back());
    		v[0].pop_back();
    		lx=v[0].back().fi,ly=v[0].back().se;
    		continue;
    	}

		if(X[1]==X[2]){
    		v[2].eb(X[1],Y[1]);
    		rmv(X[1],Y[1]);
    	}
    	else if(X[3]==X[4]){
    		v[2].eb(X[3],Y[3]);
    		rmv(X[3],Y[3]);
    	}
    	else if(X[2]==X[3]){
    		v[1].eb(X[3],Y[3]);
    		rmv(X[3],Y[3]);
    	}
    	else if(X[4]==X[1]){
    		v[1].eb(X[1],Y[1]);
    		rmv(X[1],Y[1]);
    	}
    	else{
    		FOR(i,1,5){
    			v[0].eb(X[i],Y[i]);
    			rmv(X[i],Y[i]);
    		}
    		lx=X[4],ly=Y[4];
    	}
    }

    sort(all(v[1]));
    sort(all(v[2]));

    assert(sz(v[0])+sz(v[1])+sz(v[2])==N);

    for(auto x: v[1]) cout << x.se << endl;

    //construction

    
    ans.eb(0,0);
    FOR(i,0,sz(v[0])) {
    	if(!i) ans.eb(0,INF);

    	int x0=ans.back().fi,y0=ans.back().se,
    	x1=v[0][i].fi,y1=v[0][i].se;

    	if(i%2==0)
    		ans.eb(x1,y0);
    	else
    		ans.eb(x0,y1);
    	
    	if(i+1==sz(v[0])) ans.eb(x1,y1);
    }

    FOR(idx,1,3) if(sz(v[idx])){
    	attach(ans.back(),v[idx][0]);
    	FOR(i,1,sz(v[idx])){
    		int x0=v[idx][i-1].fi,y0=v[idx][i-1].se,
    		x1=v[idx][i].fi,y1=v[idx][i].se;
    		if(i%2==1)
    			ans.eb(x1,y0);
    		else 
    			ans.eb(x0,y1);
    		if(i+1==sz(v[idx])) ans.eb(x1,y1);
    	}
	}

    cout << sz(ans)-1 << endl;
    FOR(i,1,sz(ans)) cout << ans[i].fi << ' ' << ans[i].se << endl;
    

    return 0;
}
//Change your approach 