//Never stop trying
//#include "scales.h"
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
const int MX = 2e5 + 10;
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

int arr[7];
int hsh[7];

int getHeaviest(int a, int b, int c){
	int mx=0;
	int ans;
	if(ckmax(mx,hsh[a])) ans=a;
	if(ckmax(mx,hsh[b])) ans=b;
	if(ckmax(mx,hsh[c])) ans=c;
	return ans;
}
int getLightest(int a, int b, int c){
	int mx=84;
	int ans;
	if(ckmin(mx,hsh[a])) ans=a;
	if(ckmin(mx,hsh[b])) ans=b;
	if(ckmin(mx,hsh[c])) ans=c;
	return ans;
}
int getMedian(int a, int b, int c){
	int u=getHeaviest(a,b,c);
	int v=getLightest(a,b,c);
	if(a!=u && a!=v) return a;
	if(b!=u && b!=v) return b;
	if(c!=u && c!=v) return c;
}

int getNextLightest(int a, int b, int c, int d){
	if(hsh[a]<hsh[d] && hsh[b]<hsh[d] && hsh[c]<hsh[d]) return getLightest(a,b,c);
	if(hsh[a]>hsh[d] && hsh[b]>hsh[d] && hsh[c]>hsh[d]) return getLightest(a,b,c);
	if(hsh[a]>hsh[d] && hsh[b]>hsh[d]) return getMedian(a,b,d);
	if(hsh[a]>hsh[d] && hsh[c]>hsh[d]) return getMedian(a,c,d);
	if(hsh[b]>hsh[d] && hsh[c]>hsh[d]) return getMedian(b,c,d);
	if(hsh[a]>hsh[d]) return a;
	if(hsh[b]>hsh[d]) return b;
	if(hsh[c]>hsh[d]) return c;
}

//sort 1,2,3
//sort 4,5,6
//assign {4,5,6} to their positions

void init(int T){
	return;
}


void answer(int res[]){
	FOR(i,0,6) cout << res[i] << ' '; cout << endl;
}

void orderCoins(){
	
	int a=getLightest(1,2,3);
	int c=getHeaviest(1,2,3);
	int b; FOR(i,1,4) if(a!=i && c!=i) b=i;
	int d,e,f;
	
	int u=getMedian(a,b,4);
	if(u==a){
	    d=c; c=b; b=a; a=4;
	}
	else if(u==4){
		d=c; c=b; b=4;
	}
	else{
		u=getMedian(b,c,4);
		if(u==4){
			d=c; c=4;
		}
		else d=4;
	}
	//cout << a << ' ' << b << ' ' << c << ' ' << d << endl;

	u=getMedian(a,b,5);
	if(u==a){
		e=d; d=c; c=b; b=a; a=5;
	}
	else if(u==5){
		e=d; d=c; c=b; b=5;	
	}
	else{
		u=getMedian(c,d,5);
		if(u==c){
			e=d; d=c; c=5;
		}
		else if(u==5){
			e=d; d=5;
		}
		else{
			e=5;
		}
	}
	//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << endl;

	u=getMedian(a,b,6);
	if(u==a){
		f=e; e=d; d=c; c=b; b=a; a=6;

	}
	else if(u==6){
		f=e; e=d; d=c; c=b; b=6;
	}
	else{
		u=getNextLightest(c,d,e,6);
		if(u==c){
			if(getMedian(6,c,d)==c){f=e; e=d; d=c; c=6;}
			else f=6;
		}
		else if(u==d){
			f=e; e=d; d=6;
		}
		else if(u==e){
			f=e; e=6;
		}
	}
	//cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f <<endl;
	

	int ans[6]={a,b,c,d,e,f};
	answer(ans);
	return;
}

int main() {
	boost; IO();

	FOR(i,1,7) cin>>arr[i];
	FOR(i,1,7) hsh[arr[i]]=i;

	orderCoins();

	return 0;
}

/* Careful!!!
	.Array bounds
	.Infinite loops
	.Uninitialized variables / empty containers
	.Order of input

   Some insights:
	.Binary search
	.Graph representation
	.Write brute force code
	.Change your approach
*/
