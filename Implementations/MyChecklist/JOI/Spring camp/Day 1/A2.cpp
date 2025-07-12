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
const int MX = 1e6 + 10;
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

void IO(str s) {
#ifdef LOCAL
	dbg(s)
    freopen(("input_"+s+".txt").c_str(), "r", stdin); 
    freopen(("output_"+s+".txt").c_str(), "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


double GetAngle(int xa, int ya, int xb, int yb, int xc, int yc) {
  xb -= xa;
  yb -= ya;
  xc -= xa;
  yc -= ya;
  double dot = 1.0 * xb * xc + 1.0 * yb * yc;
  double normb = 1.0 * xb * xb + 1.0 * yb * yb;
  double normc = 1.0 * xc * xc + 1.0 * yc * yc;
  return std::acos(
             std::min(std::max(dot / std::sqrt(normb * normc), -1.0), 1.0)) *
         180.0 / 3.14159265358979323846;
}

int N,Z,X[MX],Y[MX]; 
vi vec;

ld angle(int i, int j, int k){
	return GetAngle(X[j],Y[j],X[i],Y[i],X[k],Y[k]);
}

V<ld>mn(5,-1);
int cnt=0;

bool maxi(V<ld> a, V<ld> b){
    FOR(i,0,5){
        if(a[i]<b[i]) return 0;
        if(a[i]>b[i]) return 1;
    }
    return 0;
}

bool maxi_or_equal(V<ld> a, V<ld> b){
    FOR(i,0,5){
        if(a[i]<b[i]) return 0;
    }
    return 1;
}

void upd(V<ld> &a, ld x){
    FOR(i,0,5) if(x<=a[i]){
        ROF(j,i+1,5) a[j]=a[j-1];
        a[i]=x;
        break;
    }
}

bool check(int l, int r){
	reverse(vec.begin()+l,vec.begin()+r+1);

	V<ld>cur(5,180);	
    FOR(i,0,N-2){
		upd(cur,angle(vec[i],vec[i+1],vec[i+2]));
	}
	
	cnt++;
	if(maxi(cur,mn)){
        cnt=0;
        FOR(i,0,5) mn[i]=cur[i];
        return 1;
    }

	return (maxi_or_equal(cur,mn));
}



int main() {
    boost;

    int t=6;
	str tc="0"; tc+=to_string(t); 
	IO(tc);

	cin>>N>>Z; 

	FOR(i,1,N+1){
		cin>>X[i]>>Y[i];
	}
	
	vec.resize(N); iota(all(vec),1);
	random_shuffle(all(vec));

	while(1){
		int l=random(0,N-1),r=random(0,N-1);
		if(l>r) swap(l,r);

		if(!check(l,r))
				reverse(vec.begin()+l,vec.begin()+r+1);

		if(cnt%N==0) dbg(mn[0])
		if(cnt>N*15) break;
	}
	dbg(mn[0])

	for(int x: vec) cout << x << endl;    


    

    return 0;
}
//Change your approach 