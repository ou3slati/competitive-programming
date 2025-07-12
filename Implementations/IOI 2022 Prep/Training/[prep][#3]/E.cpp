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

int N; 

int grid(int x, int y){
	return min(x,y)>=1 && max(x,y)<=N; 
}

int query(int r, int c, int rr, int cc){
	cout << "? " << r << ' ' << c << ' ' << rr << ' ' << cc << endl;
	cout.flush(); 

	str s; cin>>s; 
	return (s=="YES"); 
}

void answer(str s){
	cout << "! " << s << endl;	
	cout.flush(); 
}

int32_t main() {
    boost; IO();


    cin>>N; 
    int rep; 


    str s; 
    int x=1, y=1; 
    rep=N-1; 

    while(rep--){
    	if(grid(x+1,y) && query(x+1,y,N,N)){
    		s.pb('D'); 
    		x++; 
    	}
    	else{
    		s.pb('R'); 
    		y++;
    	}
    }


    str s2; 
    int x2=1, y2=1; 
    rep=N-1; 

    while(rep--){
    	if(grid(x2,y2+1) && query(x2,y2+1,N,N)){
    		s2.pb('R'); 
    		y2++; 
    	}
    	else{
    		s2.pb('D'); 
    		x2++;
    	}
    }



    str s3; 
    int x3=N, y3=N; 
    rep=N-1; 

    while(rep--){
    	if(grid(x3-1,y3) && query(1,1,x3-1,y3)){
    		s3.pb('D'); 
    		x3--; 
    	}
    	else{
    		s3.pb('R'); 
    		y3--;
    	}
    }
    reverse(all(s3)); 


    str s4; 
    int x4=N, y4=N; 
    rep=N-1; 

    while(rep--){
    	if(grid(x4,y4-1) && query(1,1,x4,y4-1)){
    		s4.pb('R'); 
    		y4--; 
    	}
    	else{
    		s4.pb('D'); 
    		x4--;
    	}
    }
    reverse(all(s4)); 



    if(x==x3 && y==y3){
    	s+=s3;
    	answer(s); 
    }
    else if(x==x4 && y==y4){
    	s+=s4;
    	answer(s); 
    }
    else if(x2==x3 && y2==y3){
    	s2+=s3;
    	answer(s2); 
    }
    else if(x2==x4 && y2==y4){
    	s2+=s4;
    	answer(s2); 
    }


    
 

    

    return 0;
}
//Change your approach 