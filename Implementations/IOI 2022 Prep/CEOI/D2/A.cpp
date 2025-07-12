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

int N,M,D; 

vector<ld> a; 

int solve(ld X){
	vector<ld> vec=a; 
 

	vec[0]-=X; 
	FOR(i,1,N){
		ld d=vec[i]-vec[i-1]; 
		if(d>=D){
			ld move=d-D; 
			ckmin(move,X);
			vec[i]-=move; 
		}	
		else{
			ld move=D-d; 
			if(move>X) return 0; 
			vec[i]+=move; 
		}
	}

	return 1;
}

int main() {
    boost; IO();
    
    cin>>N>>M>>D;
    FOR(i,0,N){
    	int x; cin>>x; 
    	a.pb(x); 			
    }
    sort(all(a)); 

    const ld e=1e-2; 
    
    FOR(i,0,M){
    	int x; cin>>x; 

    	vector<ld> nw; 
    	int put=0; 
    	FOR(i,0,N){
    		if(!(a[i]<=x || put)) nw.pb(x), put=1;
    		nw.pb(a[i]); 
    	}
    	if(!put) nw.pb(x); 
    	a=nw; 
    	N++;
    	 
    	ld val=1e9; 
		FOR(i,0,N-1) ckmin(val,a[i+1]-a[i]); 
		if(val>=D){
			cout << 0 << ' '; 
			continue; 
		}

    	ld l=0, r=1e15, ans; 
    	while(r-l>=e){
    		ld m=(l+r)/2; 

    		if(solve(m)) ans=m, r=m-e; 
    		else l=m+e; 
    	}



    	str s=to_string(ans); 
    	FOR(i,0,sz(s)){
    		if(s[i]=='.' && s[i+1]=='0') break; 
    		cout << s[i]; 
    		if(i && s[i-1]=='.') break; 
    	}
    	cout << ' '; 
    }





    return 0;
}
//Change your approach 