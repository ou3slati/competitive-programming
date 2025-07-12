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


int N,Q; 
vi a(MX); 

vi t(MX*4); 
void build(int l=1, int r=N, int pos=1){
	if(l==r){
		t[pos]=a[l]; 
		return; 
	}

	int m=(l+r)/2; 

	build(l,m,pos*2); 
	build(m+1,r,pos*2+1); 

	t[pos]=min(t[pos*2],t[pos*2+1]); 
}

int query(int l, int r, int tl=1, int tr=N, int pos=1){
	if(l>r) return INF; 

	if(l==tl && r==tr) return t[pos]; 

	int tm=(tl+tr)/2; 

	return min(query(l,min(tm,r),tl,tm,pos*2), query(max(tm+1,l),r,tm+1,tr,pos*2+1) );
}

void no(){
	cout << "NO" << endl;
	exit(0); 
}

int32_t main() {
    boost; IO();	
    	
    cin>>N>>Q; 
    FOR(i,1,N+1){
    	cin>>a[i]; 
    	if(!a[i]) a[i]=Q+1; 
    }

    build(); 

    vi p(Q+1,-1), mn(Q+1,INF), mx(Q+1,-INF);  
    FOR(i,1,N+1) if(a[i]<=Q){
    	if(p[a[i]]!=-1){
    		if(!(query(p[a[i]],i)>=a[i])){
    			cout << "NO" << endl;
    			return 0; 
    		}
    		else{
    			ckmin(mn[a[i]],i); 
    			ckmax(mx[a[i]],i); 
    		}

    	}
    	p[a[i]]=i; 
    }

    
    	
    int f=0; 
    FOR(i,1,N+1) if(a[i]==Q) f=1;
    if(!f){
    	FOR(i,1,N+1) if(a[i]==Q+1){
    		a[i]=Q;
    		f=1;  
    		break; 
    	}
    	if(!f){
			cout << "NO" << endl;
			return 0; 
		}
    }

    vi vec[N+2]; 
    FOR(i,1,Q+1) if(mn[i]!=INF) vec[mn[i]].pb(i), vec[mx[i]+1].pb(-i);

    set<int,greater<int>>s,ss; 
    vi forb(Q+1,0); 
    FOR(i,1,N+1){
    	for(int x: vec[i]){
    		if(x>0) s.insert(x); 
    		else s.erase(-x); 
    	}

    	if(a[i]==Q+1){
    		if(!sz(s)) a[i]=1; 
    		else if(sz(s)){
    			while(sz(s) && forb[*s.begin()]) s.erase(s.begin()); 
 	
    			if(!sz(s)) a[i]=1; 
    			else a[i]=*s.begin(); 
			}
		}


		ss.insert(a[i]);
		while(*ss.begin()>a[i]){
			forb[*ss.begin()]=1; 
			ss.erase(ss.begin()); 
		}
    }


    int prv=-1; 
    FOR(i,1,N+1) if(a[i]==Q){
    	if(prv!=-1 && prv!=i-1){
    		cout << "NO" << endl;
			return 0;
    	}
    	prv=i; 
    }

    p.assign(N+1,-1); 
    build(); 
    FOR(i,1,N+1) if(a[i]<=Q){
    	if(p[a[i]]!=-1){
    		if(!(query(p[a[i]],i)>=a[i])){
    			cout << "NO" << endl;
    			return 0; 
    		}

    	}
    	p[a[i]]=i; 
    }

    cout << "YES" << endl;
    FOR(i,1,N+1) cout << a[i] << ' '; 

    return 0;
}
//Change your approach 