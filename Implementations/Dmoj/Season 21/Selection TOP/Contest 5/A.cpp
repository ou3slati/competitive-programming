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

str to_roman(int x){
	str s;

	if(x/1000){
		FOR(i,0,x/1000) s+='M';
	}
	x%=1000;

	if(x/100){
		int d=x/100;
		if(d<=3){
			FOR(i,0,d) s+='C';
		}
		else if(d<=8){
			if(d<5) s+='C';
			s+='D';
			FOR(i,0,d-5) s+='C';
		}
		else{
			s+='C';
			s+='M'; 
		}
	}
	x%=100;

	if(x/10){
		int d=x/10;
		if(d<=3){
			FOR(i,0,d) s+='X';
		}
		else if(d<=8){
			if(d<5) s+='X';
			s+='L';
			FOR(i,0,d-5) s+='X';
		}
		else{
			s+='X';
			s+='C'; 
		}
	}
	x%=10;

	if(x){
		int d=x;
		if(d<=3){
			FOR(i,0,d) s+='I';
		}
		else if(d<=8){
			if(d<5) s+='I';
			s+='V';
			FOR(i,0,d-5) s+='I';
		}
		else{
			s+='I';
			s+='X'; 
		}
	}

	return s;
}

map<char,int>mp;

int to_decimal(str s){
	int i=0,ans=0;
	while(i<sz(s)){
		if(i+1<sz(s) && mp[s[i+1]]>mp[s[i]]){
			ans+=mp[s[i+1]];
			ans-=mp[s[i]];
			i+=2;
		}
		else{
			ans+=mp[s[i]];
			i++;
		}
			
	}
	return ans;
}

int32_t main() {
    boost; IO();

    mp['I']=1; mp['V']=5; mp['X']=10;
    mp['L']=50; mp['C']=100; mp['D']=500;
    mp['M']=1000;

    int t=0;
    while(cin>>N,N){
    	t++;
    	int ans=0;
    	FOR(i,0,N){
    		str s; cin>>s;
    		ans+=to_decimal(s);
    	}
    	cout << "Case " << to_roman(t) << ": " << to_roman(ans) << endl;

    }
    

    return 0;
}
//Change your approach 	