//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
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

int N; 
vi a;

vi bit(MX,0);

void upd(int i, int v){
	for(;i<MX; i+=i&-i) bit[i]+=v;
}
int sum(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=bit[i];
	return ans;
}
int get(int l, int r){
	return sum(r)-sum(l-1);
}

int check(int side){
	if(side==0){
		int cnt=0;
		FOR(i,1,N*2+1) if(a[i]==0){
			int l=i,r=N*2;
			int f=-1;
			while(l<=r){
				int m=(l+r)/2;
				if(get(i,m)>0){
					f=m;
					r=m-1;
				}
				else l=m+1;
			}
			if(f==-1) return cnt;
			cnt++;
			upd(f,-1);
		}
		return cnt;
	}
	else{
		int cnt=0;
		ROF(i,1,N*2+1) if(a[i]==0){
			int l=1,r=i;
			int f=-1;
			while(l<=r){
				int m=(l+r)/2;
				if(get(m,i)>0){
					f=m;
					l=m+1;
				}
				else r=m-1;
			}
			if(f==-1) return cnt;
			cnt++;
			upd(f,-1);
		}
		return cnt;
	}
}

int32_t main() {
    boost; IO();

 	int TC; cin>>TC;
    while(TC--){
    	cin>>N;
    	a.assign(2*N+10,0);
    		
    	vi b(N);
    	FOR(i,0,N){
    		int x; cin>>x;
    		b[i]=x;
    		a[x]=1;
    	}

    	
    	FOR(i,0,N*2+10) bit[i]=0;
    	FOR(i,0,N) upd(b[i],1);
    	int v=check(0);

    	FOR(i,0,N*2+10) bit[i]=0;
    	FOR(i,0,N) upd(b[i],1);
    	
    	int vv=check(1);

    	int ans=0;
    	FOR(x,0,N+1){
    		if(vv>=x && v>=N-x) ans++;
    	}
    	cout << ans << endl;

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