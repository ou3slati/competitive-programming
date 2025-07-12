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

void IO(str f){
	dbg(f)
	freopen(("ioi-2019-line_" + f + ".in").c_str(), "r", stdin);
	if(sz(f)==1){
		f+='0';
		reverse(all(f));
	}
	freopen((f + ".out.txt").c_str(), "w", stdout);
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

int N; 
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
    boost; 

    FOR(t,1,11){
    	str f=to_string(t);
    	IO(f);

    	ans.clear();
    	a.clear(); b.clear(); c.clear(); d.clear();
    	mpx.clear();
    	mpy.clear();

    	cin>>N;
	    //division
	    FOR(i,0,N){
	    	int x,y; cin>>x>>y;
	    	mpx[x]=y; mpy[y]=x;
	    	add(x,y);
	    }

	    vpi sp,diag,diag2;
	    while(sz(a)){
	    	int mnx=*a.begin(),mxx=*b.begin(),
	    	mny=*c.begin(),mxy=*d.begin();

	    	vi X(4),Y(4);
	    	X[0]=mpy[mxy]; Y[0]=mxy;
	    	X[1]=mxx; Y[1]=mpx[mxx];
	    	X[2]=mpy[mny]; Y[2]=mny;
	    	X[3]=mnx; Y[3]=mpx[mnx];
	    	
	    	if(X[0]==X[3]){
	    		rmv(X[0],Y[0]);
	    		diag.eb(X[0],Y[0]);
	    	}
	    	else if(X[1]==X[2]){
	    		rmv(X[1],Y[1]);
	    		diag.eb(X[1],Y[1]);
	    	}
	    	else if(X[2]==X[3]){
	    		rmv(X[2],Y[2]);
	    		diag2.eb(X[2],Y[2]);
	    	}
	    	else if(X[0]==X[1]){
	    		rmv(X[0],Y[0]);
	    		diag2.eb(X[0],Y[0]);
	    	}
	    	else{
	    		FOR(i,0,4) sp.eb(X[i],Y[i]),rmv(X[i],Y[i]);
	    	}
	    }

	    ans.eb(0,0);
	    for(int i=sz(sp)-4; i>=0; i-=4){
	    	int lx=ans.back().fi,ly=ans.back().se;
	    	ans.eb(lx,sp[i].se);
	    	if(lx>sp[i].fi){ 
	    		swap(sp[i+1],sp[i+3]);
	    	}
	    	ans.eb(sp[i+1].fi,sp[i].se);
			ans.eb(sp[i+1].fi,sp[i+2].se);
			ans.eb(sp[i+3].fi,sp[i+2].se);
			if(!i) ans.eb(sp[i+3]);
	    }

	    sort(all(diag)); sort(all(diag2));

	    if(sz(diag)){
	    	attach(ans.back(),diag[0]);
	    }
	    FOR(i,0,sz(diag)){
	    	if(i+1==sz(diag)){
	    		ans.eb(diag[i].fi,diag[i].se);
	    		continue;
	    	}
	    	if(i%2==0){
	    		ans.eb(diag[i+1].fi,diag[i].se);
			}
			else{
				ans.eb(diag[i].fi,diag[i+1].se);
			}
	    }

	    if(sz(diag2)){
	    	attach(ans.back(),diag2[0]);
	    }
	    FOR(i,0,sz(diag2)){
	    	if(i+1==sz(diag2)){
	    		ans.eb(diag2[i].fi,diag2[i].se);
	    		continue;
	    	}
	    	if(i%2==0){
	    		ans.eb(diag2[i+1].fi,diag2[i].se);
			}
			else{
				ans.eb(diag2[i].fi,diag2[i+1].se);
			}
	    }

	    cout << sz(ans)-1 << endl;
	    FOR(i,1,sz(ans)) if(!(ans[i].fi==ans[i-1].fi && ans[i].se==ans[i-1].se)){
	    	cout << ans[i].fi << ' ' << ans[i].se << endl;
	    }
    }
    
    

    return 0;
}
//Change your approach 