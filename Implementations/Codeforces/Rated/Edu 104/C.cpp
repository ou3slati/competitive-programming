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



int32_t main() {
    boost; IO();
    
    int TC; cin>>TC;
    int cnt=2;
    while(TC--){
    	int N; N=random(1,100);
    	int a[N][N]; FOR(i,0,N) FOR(j,0,N) a[i][j]=-2;

    	int A,B=INF,V;
    	FOR(i,0,(N*(N-1))/2+1){
    		int j=(N*(N-1))/2-i;
    		if((3*i+2*j)%N==0 && j<B){
    			A=i; B=j;
    			V=(3*i+2*j)/N;
    		}
    	}
    	assert(B!=INF);

    	FOR(i,0,N){
    		int x=0; //wins
    		while(x<A && (x+1)*3<=V) x++;
    		A-=x;
    		int y=V-3*x; //draws

    		FOR(j,0,N) if(a[i][j]==1) x--;
    		FOR(j,0,N) if(x && i!=j && a[i][j]==-2){
    			x--;
    			a[i][j]=1;
    			a[j][i]=-1;
    		}

    		FOR(j,0,N) if(a[i][j]==0) y--;
    		FOR(j,0,N) if(y && i!=j && a[i][j]==-2){
    			y--;
    			a[i][j]=0;
    			a[j][i]=0;
    		}
    	}

    	vi v(N,0);
    	FOR(i,0,N) FOR(j,i+1,N){
    		cout << a[i][j] << ' ';
    		if(!a[i][j]) v[i]+=1,v[j]+=1;
    		else if(a[i][j]==1) v[i]+=3;
    		else v[j]+=3;
		}
		sort(all(v));
		if(v[0]!=v[N-1]) here()
    	cout << endl;
    }

    return 0;
}
//Change your approach 