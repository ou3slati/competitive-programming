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


vi a(MX,0);

int query(int l, int r){
	/*int ans=0;
	FOR(i,l,r+1) ans+=a[i];
	return ans; */

	cout << "? " << l << ' ' << r << endl;
	cout.flush();
	int x; cin>>x;
	return x; 
}

void answer(int x){
	cout << "! " << x << endl;
	cout.flush();
}


const int B=22;
int N,T; 
map<int,int>mp;

void compute(){
	int cnt=0;
    for(int i=1; i<=N; i+=B){
    	int j=min(N,i+B-1);
    	int x=query(1,j);
    	int n=j-x;

    	FOR(k,cnt+1,n+1) mp[k]=i;

    	cnt=n;
    }
}

vi t(MX,0);
void upd(int i){
	for(;i<MX; i+=i&-i) t[i]++;
}
int get(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t[i];
	return ans;
}

vi t2(MX,0);
void upd2(int i){
	for(;i<MX; i+=i&-i) t2[i]++;
}
int get2(int i){
	int ans=0;
	for(;i;i-=i&-i) ans+=t2[i];
	return ans;
}


int32_t main() {
    boost; IO();

    cin>>N>>T;

    
    int f=1; 
    while(T--){
    	int k; cin>>k;
    	int add=get2(k);
    	upd2(k);
    	k+=add;
    	

    	if(f){
    		compute();
    		f=0;
    	}

    	int l=mp[k]; int r=min(N,l+B-1),ans=-1;
    	
    	while(l<=r){
    		int m=(l+r)/2;

    		int x=query(1,m)-get(m);
    		int n=m-x;
    		if(n>=k){
    			ans=m; 
    			r=m-1;
    		}
    		else l=m+1;
    	}
    	assert(ans>=1);
    	upd(ans);
    	answer(ans);
    }
    

    return 0;
}
//Change your approach 