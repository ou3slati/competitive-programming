/*
CF 717C - TBD
https://codeforces.com/contest/1516/problem/C

Key insights:
1. TBD
2. TBD
3. TBD
*/

#include <bits/stdc++.h>
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


int N,cum,odd; 
vi a(MX);

int f(int cur){
	FOR(i,0,N) if(a[i]%cur!=0) return i+1;
	return -1;
}

int memo[100+5][100*2000+5];
int solve(int i, int r){
	if(r<0) return 0;
	if(r==0) return 1;
	if(i==N) return 0;

	int &ind=memo[i][r];
	if(ind!=-1) return ind;

	int ans=solve(i+1,r);
	ans|=solve(i+1,r-a[i]);

	return ind=ans; 
}

bool check(){
	return solve(0,cum/2);
}

int main() {
    boost; IO();

    memset(memo,-1,sizeof(memo));
    cum=0,odd=-1;

    cin>>N;
    FOR(i,0,N){
    	cin>>a[i];
    	cum+=a[i];
    	if(a[i]&1) odd=i+1;
    }

    if(cum&1) cout << 0 << endl;
    else{
    	if(!check()) cout << 0 << endl;
    	else{
    		if(odd!=-1) cout << 1 << endl << odd << endl;
    		else{
    			int cur=4,idx=-1;
    			while(1){
    				idx=f(cur);
    				if(idx!=-1) break;
    				cur*=2;
    			}	
    			cout << 1 << endl << idx << endl;
    		}
    	}
    }

    

    return 0;
}
//Change your approach 