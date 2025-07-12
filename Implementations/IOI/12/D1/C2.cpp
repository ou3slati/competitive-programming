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

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////

const int LOG=21;
int jump[MX][LOG],jumpV[MX][LOG],u=0;
V<char>C(MX);
vi szz;

void Init(){
	FOR(i,0,LOG) jump[0][i]=0,jumpV[0][i]=0;
	szz.pb(0);	
}

void TypeLetter(char c){
	u++;
	C[u]=c;

	jump[u][0]=u-1;
	jumpV[u][0]=1;
	FOR(i,1,LOG){
		jump[u][i]=jump[jump[u][i-1]][i-1];
		jumpV[u][i]=jumpV[u][i-1] + jumpV[jump[u][i-1]][i-1];
	}

	int n=szz.back(); 
	szz.pb(n+1);
}

void UndoCommands(int X){
	u++;

	jump[u][0]=u-X-1;
	jumpV[u][0]=0;
	FOR(i,1,LOG){
		jump[u][i]=jump[jump[u][i-1]][i-1];
		jumpV[u][i]=jumpV[u][i-1] + jumpV[jump[u][i-1]][i-1];
	}

	int n=szz[sz(szz)-X-1]; 
	szz.pb(n);
}

char GetLetter(int X){
	X=szz.back()-X;
	
	int val=0,idx=u; 
	ROF(i,0,LOG){
		if(val+jumpV[idx][i]<X){
			val+=jumpV[idx][i];
			idx=jump[idx][i];
		}
	}

	return C[idx];
}

#ifdef LOCAL
int main() {
    boost; IO();


    Init();
    int N; cin>>N;
    FOR(i,0,N){
    	int t; cin>>t;
    	if(!t){
    		char c; cin>>c;
    		TypeLetter(c);
    	}
    	else if(t==1){
    		int x; cin>>x;
    		UndoCommands(x);
    	}
    	else{
    		int idx; cin>>idx;
    		cout << GetLetter(idx) << endl;
    	}
    }
    

    return 0;
}
#endif
//Change your approach 