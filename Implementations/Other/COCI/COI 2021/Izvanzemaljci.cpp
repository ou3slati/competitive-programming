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
const ll INF = 3e9;
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

int N,K,X[MX],Y[MX];

int32_t main() {
    boost; IO();
    	
    cin>>N>>K;
    FOR(i,0,N) cin>>X[i]>>Y[i];

    if(K==1){
    	int mnx=INF,mny=INF,mxx=-INF,mxy=-INF;
    	FOR(i,0,N){
    		ckmin(mnx,X[i]);
    		ckmin(mny,Y[i]);
    		ckmax(mxx,X[i]);
    		ckmax(mxy,Y[i]);
    	}

    	int l=1; ckmax(l,mxx-mnx); ckmax(l,mxy-mny);
    	cout << mnx << ' ' << mny << ' ' << l << endl;
    }
    else if(K==2){
    	int mnx=INF,mny=INF,mxx=-INF,mxy=-INF;
    	FOR(i,0,N){
    		ckmin(mnx,X[i]);
    		ckmin(mny,Y[i]);
    		ckmax(mxx,X[i]);
    		ckmax(mxy,Y[i]);
    	}

    	int l=1,l2=1; ckmax(l,mxx-mnx); ckmax(l,mxy-mny);
    	int mn=l*l,xx=mnx,yy=mny,xxx=-INF,yyy=-INF;

    	//-----------------------------------

    	vpi vec;
    	FOR(i,0,N) vec.eb(X[i],Y[i]);
    	sort(all(vec));
    	FOR(i,0,N) X[i]=vec[i].fi,Y[i]=vec[i].se;

    	multiset<int>a,c; 
    	multiset<int,greater<int>>b,d; 
    	FOR(i,0,N){
    		a.insert(X[i]);
    		b.insert(X[i]);
    		c.insert(Y[i]);
    		d.insert(Y[i]);
    	}
    	mnx=INF,mny=INF,mxx=-INF,mxy=-INF;
    	FOR(i,0,N-1){
    		a.erase(a.find(X[i]));
    		b.erase(b.find(X[i]));
    		c.erase(c.find(Y[i]));
    		d.erase(d.find(Y[i]));

    		ckmin(mnx,X[i]);
    		ckmin(mny,Y[i]);
    		ckmax(mxx,X[i]);
    		ckmax(mxy,Y[i]);

    		if(X[i]==X[i+1]) continue;

    		int cl=max(mxx-mnx,mxy-mny); ckmax(cl,1ll);
    		int cl2=max((*b.begin()-*a.begin()),(*d.begin()-*c.begin()));
    		ckmax(cl2,1ll);
    		int cur=max(cl*cl,cl2*cl2);

    		if(ckmin(mn,cur)){
    			xx=mxx-cl,yy=mny,l=cl;

    			xxx=*a.begin(); yyy=*c.begin(); l2=cl2;
    		}
    	}


    	//----------------------------------------------

    	for(auto &x: vec) swap(x.fi,x.se);
    	sort(all(vec));
    	FOR(i,0,N) X[i]=vec[i].fi,Y[i]=vec[i].se;
    	//FOR(i,0,N) cout << X[i] << ' ' << Y[i] << endl;


    	a.clear(); b.clear();
    	c.clear(); d.clear();
    	FOR(i,0,N){
    		a.insert(X[i]);
    		b.insert(X[i]);
    		c.insert(Y[i]);
    		d.insert(Y[i]);
    	}
    	mnx=INF,mny=INF,mxx=-INF,mxy=-INF;
    	FOR(i,0,N-1){
    		a.erase(a.find(X[i]));
    		b.erase(b.find(X[i]));
    		c.erase(c.find(Y[i]));
    		d.erase(d.find(Y[i]));

    		ckmin(mnx,X[i]);
    		ckmin(mny,Y[i]);
    		ckmax(mxx,X[i]);
    		ckmax(mxy,Y[i]);

    		if(X[i]==X[i+1]) continue;

    		int cl=max(mxx-mnx,mxy-mny); ckmax(cl,1ll);
    		int cl2=max((*b.begin()-*a.begin()),(*d.begin()-*c.begin()));
    		ckmax(cl2,1ll);
    		int cur=max(cl*cl,cl2*cl2);

    		if(ckmin(mn,cur)){
    			xx=mxx-cl,yy=mny,l=cl;

    			xxx=*a.begin(); yyy=*c.begin(); l2=cl2;

    			swap(xx,yy);
    			swap(xxx,yyy);
    		}
    	}



    	cout << xx << ' ' << yy << ' ' << l << endl;
    	cout << xxx << ' ' << yyy << ' ' << l2 << endl;

    }


    return 0;
}
//Change your approach 