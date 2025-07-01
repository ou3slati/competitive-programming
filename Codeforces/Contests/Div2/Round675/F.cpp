#include <bits/stdc++.h>
using namespace std;

#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
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
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

const int MOD = 1e9 + 7; //998244353
const ll INF = 1e18;
const int MX = 1e5 + 25;
const int nx[4] = {0, 0, 1, -1}, ny[4] = {1, -1, 0, 0}; //right left down up

template<class T> using V = vector<T>;
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
constexpr int log2(int x) { return 31 - __builtin_clz(x); } // floor(log2(x))

#define dbg(x) cerr << " - " << #x << " : " << x << endl;
#define dbgs(x,y) cerr << " - " << #x << " : " << x << " / " << #y << " : " << y << endl;
#define dbgv(v) cerr << " - " << #v << " : " << endl << "[ "; for(auto it : v) cerr << it << ' '; cerr << ']' << endl;

void IO() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int modpow(int x, int p){
	if(p==0) return 1;
	int v=modpow(x,p/2);
	v*=v; v%=MOD;
	if(p%2) v*=x; v%=MOD;
	return v;
}

int modinv(int x){
	return modpow(x,MOD-2);
}

int lcm(int a, int b){
	return (((a*b)%MOD)*(modinv(__gcd(a,b))))%MOD;
}

const int L=87;

int N,S; 
vi a(MX);

int pr[MX]; //the prime bigger that sqrt(mx_A[i])

//Part 1 

int cnt[MX+1][87];
ll power[87][30];

int spf[MX*2+1];
vi p;

void sieve(){
	FOR(i,2,MX*2) spf[i]=-1;
	FOR(i,2,MX*2) if(spf[i]==-1){
		p.pb(i); 
		for(int j=i; j<MX*2; j+=i) spf[j]=i;
	}
}


vi f;
void fact(int x){
	f.clear();
	while(x>1){
		f.pb(spf[x]);
		x/=spf[x];
	}
}

int mp[MX*2+1];
void precompute(){ //Calculate cnt[i][p]
	sieve();

	FOR(i,0,MX*2) mp[i]=-1;
	FOR(i,0,L) mp[p[i]]=i;
	
	FOR(i,0,L){
		power[i][0]=1;
		FOR(j,1,25){
			power[i][j]=power[i][j-1]*p[i]; 
			power[i][j]%=MOD;
		}
	}

	FOR(i,1,N+1){
		fact(a[i]);
		int x=1;
		for(auto xx: f) x*=xx;

		pr[i]=1;
		FOR(j,0,L) cnt[i][j]=0;
		for(auto xx: f){
			if(mp[xx]!=-1)
				cnt[i][mp[xx]]++;
			else pr[i]=xx;
		}
	}
}

vi t[MX*4];

vi combine(vi a, vi b){
	FOR(i,0,sz(a)) ckmax(a[i],b[i]);
	return a;
}

void build(int pos=1, int l=1, int r=N){
	
	if(l==r){
		t[pos].resize(L);
		FOR(i,0,L) t[pos][i]=cnt[l][i];
		return;
	}
	int m=(l+r)/2;
	build(pos*2,l,m);
	build(pos*2+1,m+1,r);
	t[pos]=combine(t[pos*2],t[pos*2+1]);
}

vi query(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r){
		vi v(L,0);
		return v;
	}
	if(l==tl && r==tr) return t[pos];
	int tm=(tl+tr)/2;
	return combine(query(l,min(tm,r),pos*2,tl,tm),
		query(max(l,tm+1),r,pos*2+1,tm+1,tr));
}


//Part 2
int previous[MX];
void precompute2(){
	int last[MX*2]; FOR(i,0,MX*2) last[i]=-1;
	FOR(i,1,N+1){
		previous[i]=last[pr[i]];
		last[pr[i]]=i;
	}
}

struct node{
	int prev,pp; ll pref;
};

bool cmp(node a, node b){
	return a.prev<b.prev;
	return 1;
}

V<node> t2[4*MX];
V<node> combine2(V<node> a, V<node> b){
	for(auto x: b) a.pb(x);
	sort(all(a),cmp);
	a[0].pref=a[0].pp;
	FOR(i,1,sz(a)){
		a[i].pref=a[i-1].pref*a[i].pp; 
		a[i].pref%=MOD; 
	}
	return a;
}

void build2(int pos=1, int l=1, int r=N){
	if(l==r){
		t2[pos].pb({previous[l],pr[l],pr[l]});
		return;
	}
	int m=(l+r)/2;
	build2(pos*2,l,m);
	build2(pos*2+1,m+1,r);
	t2[pos]=combine2(t2[pos*2],t2[pos*2+1]);
}

int cur_l;

ll query2(int l, int r, int pos=1, int tl=1, int tr=N){
	if(l>r){
		return 1;
	}
	if(l==tl && r==tr){
		int lb=0,rb=sz(t2[pos])-1;
		int ans=-1;
		while(lb<=rb){
			int m=(lb+rb)/2;
			if(t2[pos][m].prev<cur_l){
				ans=m;
				lb=m+1;
			}
			else rb=m-1;
		}
		if(ans!=-1) return t2[pos][ans].pref;
		return 1;
	}
	int tm=(tl+tr)/2;
	return (query2(l,min(tm,r),pos*2,tl,tm)*
		query2(max(l,tm+1),r,pos*2+1,tm+1,tr))%MOD;
}


int main() {
	boost; IO();

	cin>>N; 
	FOR(i,1,N+1) cin>>a[i];
	
	//FOR(i,1,N+1) a[i]=rand()%22+1;

	precompute();
	precompute2();

	build();
	build2();

	int Q; cin>>Q;
	int last=0;
	while(Q--){
		int l,r; 
		cin>>l>>r;
		l=(l+last)%N+1,r=(r+last)%N+1;

		//l=rand()%N+1; r=((rand()%N)+984)%N+1;
		if(l>r) swap(l,r);
		cur_l=l;

		vi v=query(l,r);
		ll x=1; 
		FOR(i,0,L){
			x*=power[i][v[i]]; x%=MOD;
		}

		ll res=(x*query2(l,r))%MOD;
		//cout << res << ' ';

		/*res=1;
		FOR(i,l,r+1) res=lcm(res,a[i]);*/
		cout << res << endl;

		last=res;
	}

	return 0;
}

