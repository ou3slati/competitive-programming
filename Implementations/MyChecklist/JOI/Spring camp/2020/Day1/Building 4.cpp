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
const int MX = 5e5 + 10;
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

int N;
vi A(MX*2),B(MX*2);

vector<short int> memo[MX*4][2][2];


void allocate(int l=0, int r=2*N-1, int pos=1){
	if(r-l<=1) return; 
	FOR(i,0,2) FOR(j,0,2) memo[pos][i][j].assign(r-l+2,-1);
	int m=(l+r)/2;
	allocate(l,m,pos*2);
	allocate(m+1,r,pos*2+1);
}
	
str ans; 
short int solve(int l, int r, int n, int b, int e, int pos){
	if(n>(r-l+1)) return 0;
	if(n<(b==0)+(l<r && e==0)) return 0;
	if(r-l<=1){
		if(l==r){
			if(b!=e) return 0;
			if(n && b) return 0;
			if(!n && !b) return 0;
			return 1;
		}
		else{
			int x=A[l]; if(b) x=B[l];
			int y=A[r]; if(e) y=B[r];
			if(x>y) return 0;
			if(n!=(b==0)+(e==0)) return 0;
			return 1;
		}
		
	}

	short int &ind=memo[pos][b][e][n];
	if(ind!=-1) return ind;

	FOR(n1,0,n+1) FOR(e1,0,2) FOR(b2,0,2){
		int b1=b,e2=e;

		int n2=n-n1,m=(l+r)/2;

		int x=A[m]; if(e1) x=B[m];
		int y=A[m+1]; if(b2) y=B[m+1];

		if(x<=y && solve(l,m,n1,b1,e1,pos*2) && 
			solve(m+1,r,n2,b2,e2,pos*2+1)){
				return ind=1;
			}
	}

	return ind=0;
}

str build(int l, int r, int n, int b, int e, int pos){
	if(l==r){
		if(!b) return "A"; 
		return "B";
	}
	else if(r-l==1){
		str ans; 
		if(b) ans+="B"; 
		else ans+="A";
		if(e) ans+="B"; 
		else ans+="A";
	}

	FOR(n1,0,n+1) FOR(e1,0,2) FOR(b2,0,2){
		int b1=b,e2=e;

		int n2=n-n1,m=(l+r)/2;

		int x=A[m]; if(e1) x=B[m];
		int y=A[m+1]; if(b2) y=B[m+1];

		if(x<=y && solve(l,m,n1,b1,e1,pos*2) && 
			solve(m+1,r,n2,b2,e2,pos*2+1)){
				str ans=build(l,m,n1,b1,e1,pos*2);
				ans+=build(m+1,r,n2,b2,e2,pos*2+1);
				return ans; 
			}
	}
	return "";
}

int main() {
    boost; IO();
    
    cin>>N;
    FOR(i,0,N*2) cin>>A[i];
    FOR(i,0,N*2) cin>>B[i];

    allocate();
   	FOR(b,0,2) FOR(e,0,2){
   		if(solve(0,2*N-1,N,b,e,1)){
   			cout << build(0,2*N-1,N,b,e,1) << endl;
   			return 0;
   		}
   	}

   	cout << -1 << endl;

    return 0;
}
//Change your approach 