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

int A,B,C;
unordered_map<char,int>mp; 

void empty(int x){
	cout << "EMPTY " << x << endl;
	cout.flush();
}

void add(int x){
	cout << "PLACE " << x << endl;
	cout.flush();
}

void del(){
	cout << "DISCARD" << endl;
	cout.flush();
}

void strategy1(){
	int i=0,j=1;
	int N=A+B+C;
	while(N--){
		char c; cin>>c;
		int nw=mp[c];

		if(nw==i){
			add(1);
		}
		else if(nw==j){
			add(2);
		}
		else del();
	}
}
void strategy2(){
	int x=0,y=0,z=0; //bowl 1, bowl 2, discarded
	int i=0,j=1,k=2;
	
	int N=A+B+C;
	while(N--){
		char c; cin>>c;
		int nw=mp[c];

		if(nw==k && z==B){
			if(x<y){
				empty(1);
				z=x; x=0;
				swap(i,k);
			}
			else{
				empty(2);
				z=y; y=0;
				swap(j,k);
			}
		}

		if(nw==i){
			x++; 
			add(1);
		}
		else if(nw==j){
			y++; 
			add(2);
		}
		else{
			z++; 
			del();
		}
	}
}
void strategy3(){
	int x=0,y=0,z=0; //bowl 1, bowl 2, discarded
	int i=0,j=1,k=2;

	int N=A+B+C;
	while(N--){
		char c; cin>>c;
		int nw=mp[c];

		if(nw==k && z==A){
			if(x<y){
				empty(1);
				z=x; x=0;
				swap(i,k);
			}
			else{
				empty(2);
				z=y; y=0;
				swap(j,k);
			}
		}
		else if(nw==k && z==B){
			if(x<y){
				empty(1);
				z=x; x=0;
				swap(i,k);
			}
			else{
				empty(2);
				z=y; y=0;
				swap(j,k);
			}
		}

		if(nw==i){
			x++; 
			add(1);
		}
		else if(nw==j){
			y++; 
			add(2);
		}
		else{
			z++; 
			del();
		}
	}
}

int32_t main() {
    boost; IO();
    
   
    mp['R']=0; mp['B']=1; mp['G']=2;

    int TC; cin>>TC;
    while(TC--){
    	cin>>A>>B>>C; 
    	vi v={A,B,C}; sort(all(v)); A=v[0],B=v[1],C=v[2];

    	if(A+B>=43) strategy1();
    	else if(100-2*B>=43) strategy2();
    	else strategy3();
    }

    return 0;
}
//Change your approach 