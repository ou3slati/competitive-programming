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
const int MX = 4e5 + 10;
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

int N,K;
ll X[MX],Y[MX];
vi y;
ll mp[MX]; //compressed y-coord

bool cmp(int i, int j){
	return X[i]<X[j];
}

bool cmp2(int i, int j){
	return Y[i]<Y[j];
}
void adjustXY(){
	FOR(i,0,N){
		int nwx=X[i]-Y[i],nwy=X[i]+Y[i];
		X[i]=nwx,Y[i]=nwy;

		y.pb(i);
	}

	vi vec(N);
	iota(all(vec),0);
	sort(all(vec),cmp);

	int nwx[N],nwy[N];
	FOR(i,0,N){
		nwx[i]=X[vec[i]];
		nwy[i]=Y[vec[i]];
	}
	FOR(i,0,N){
		X[i]=nwx[i];
		Y[i]=nwy[i];
	}

	sort(all(y),cmp2);
	FOR(i,0,N) mp[y[i]]=i+1,y[i]=Y[y[i]];
}


vi t(MX); 
void upd(int i, int v){
	for(;i<MX; i+=i&-i){
		t[i]+=v; 
	}
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans;
}

ll query(ll l, ll r){
	l=lower_bound(all(y),l)-y.begin()+1;
	r=upper_bound(all(y),r)-y.begin();
	if(l>r) return 0;
	return get(r)-get(l-1);
}


ll solve(ll D){
	FOR(i,0,MX) t[i]=0;

	int j=0;
	ll ans=0;
	FOR(i,0,N){
		while(j<i && X[i]-X[j]>D){
			upd(mp[j],-1); 
			j++;
		}

		ans+=query(Y[i]-D,Y[i]+D);

		upd(mp[i],1);
	}
	return ans;
}

V<ll> ans; 
void solve2(ll D){
	int j=0;
	set<pair<ll,ll>>s;
	FOR(i,0,N){
		while(j<i && X[i]-X[j]>D){
			s.erase({Y[j],X[j]});
			j++;
		}

		pair<ll,ll> p={Y[i]-D,-INF};
		auto it=lower_bound(all(s),p);
		while(it!=s.end()){
			ll yy=(*it).fi,xx=(*it).se;
			if(yy-Y[i]>D) break;

			ans.pb(max(abs(X[i]-xx),abs(Y[i]-yy)));
			assert(ans.back()<=D);

			it++;
		}

		s.insert({Y[i],X[i]});
	}

}

int main() {
    boost; IO();
    	
    cin>>N>>K;
    FOR(i,0,N) cin>>X[i]>>Y[i];

    adjustXY();


    ll l=0,r=5e9,D;
    while(l<=r){
    	ll m=(l+r)/2;
    	if(solve(m)>=K) D=m,r=m-1;
    	else l=m+1;
    }


    solve2(D);
    sort(all(ans));
    FOR(i,0,K) cout << ans[i] << endl;


    return 0;
}
//Change your approach 