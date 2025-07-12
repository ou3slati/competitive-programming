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

const int C=1e15;

bool reasonable(int x){
	return x>=-C && x<=C;
}

int32_t main() {
    boost; IO();

    int N; cin>>N;
    vi X(N),Y(N);
    FOR(i,0,N) cin>>X[i]>>Y[i];

    int M; cin>>M;
    vpi vec;
    FOR(i,0,M){
    	int t,p=-1; cin>>t;
    	if(t>=3) cin>>p;
    	vec.eb(t,p);
    }

    int a[M],b[M],v[M],v2[M],c[M],d[M];

    int cur_a=1,cur_b=1,cur_v=0,cur_v2=1,cur_c=0,cur_d=0;
    FOR(i,0,M){
    	int t=vec[i].fi,p=vec[i].se;
    	if(t==2){
    		swap(cur_a,cur_b); 
    		swap(cur_v,cur_v2); 
    		swap(cur_c,cur_d);
    		cur_a*=-1;
    		cur_c*=-1; 
    	}
    	else if(t==1){
    		swap(cur_a,cur_b); 
    		swap(cur_v,cur_v2); 
    		swap(cur_c,cur_d);
    		cur_b*=-1;
    		cur_d*=-1; 
    	}
    	else if(t==3){
    		cur_a*=-1;
    		cur_c*=-1; 
    		cur_c+=2*p;
    	}
    	else if(t==4){
    		cur_b*=-1;
    		cur_d*=-1; 
    		cur_d+=2*p;
    	}

    	a[i]=cur_a; b[i]=cur_b;
    	v[i]=cur_v; v2[i]=cur_v2;
    	c[i]=cur_c; d[i]=cur_d;
    }

    int Q; cin>>Q;
    while(Q--){
    	int op,i; cin>>op>>i;
    	op--; i--;
    	if(op<0){
    		cout << X[i] << ' ' << Y[i] << endl;
    		continue;
    	}

    	int x=X[i],y=Y[i];

    	cur_a=a[op];
    	cur_b=b[op];
    	cur_c=c[op];
    	cur_d=d[op];

    	if(v[op]==0){
    		cout << cur_a*x+cur_c << ' ' << cur_b*y+cur_d << endl; 
    	}
    	else{
    		cout << y*cur_a+cur_c << ' ' << cur_b*x+cur_d << endl; 
    	}
    }
    

    return 0;
}
//Change your approach 