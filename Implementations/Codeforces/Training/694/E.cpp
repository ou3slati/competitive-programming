//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
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

int N,K,B; 

int imp=250;
vi a;

int query(int x){
	#ifndef LOCAL
	x++;
	cout << "? " << x << endl;
	cout.flush();
	cin>>x;
	return x;
	#endif

	int ans=a[x];
	vi nwa(N,0);
	FOR(i,0,N) if(i!=imp){
		nwa[(i+1)%N]+=cdiv(a[i],2);
		nwa[(i-1+N)%N]+=a[i]/2;
	}
	nwa[(imp+1)%N]+=a[imp];
	a.assign(all(nwa));
	return ans;
}

int main() {
    boost; IO();

    cin>>N>>K;

    a.assign(N,K);
    if(N<=50){
    	FOR(i,0,N) query(0);
    	int mx=-1,idx;
    	FOR(i,0,N) if(ckmax(mx,query(i))){
    		idx=i;
    	}
    	if(!idx) idx=N;
    	cout << "! " << idx << endl;
    	cout.flush();
    	return 0;
    }

    B=ceil(sqrt(N));
    FOR(i,0,B){
    	int x=query(0);
    }

    int l,r; 
    for(int i=0; i<N; i+=B){
    	int x=query(i);
    	if(x>K){
    		if(i) l=i-B,r=i-1;
    		else{
    			while(i+B<N) i+=B;
    			l=i,r=N-1;
    		}
    		break;
    	}
    }

    ROF(i,l,r+1) if(query(i)==K){
    	cout << "! " << i+1 << endl;
    	cout.flush();
    	break;
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