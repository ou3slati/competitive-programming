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

#ifndef LOCAL
#include"holiday.h"
#endif

int N,st,D; 
vi a;

int f(int l, int m, int r){
	return r-l+min(m-l,r-m);
}

ll findMaxAttraction(int N, int st, int D, int tab[]) {
    ::N=N; ::st=st; ::D=D;
    a.resize(N);
    FOR(i,0,N) a[i]=tab[i]; 

    if(N<=3000){
    	ll ans=0;
 		FOR(i,st,N){
 			int r=D-f(st,st,i);
 			if(r<0) break;

 			ll sum=0;
 			multiset<int>s;
 			FOR(j,st+1,i+1) 
 				s.insert(a[j]),sum+=a[j];

 			ROF(j,0,st+1){
 				s.insert(a[j]);
 				sum+=a[j];

 				r=D-f(j,st,i);
 				if(r<0) break;

 				while(sz(s)>r){
 					sum-=*s.begin();
 					s.erase(s.begin());
 				}
 				ckmax(ans,sum);
 			}
 		}   
 		return ans;	
    }
    else{
    	vi cnt(101,0);
    	ll ans=0;
    	FOR(i,0,N){
    		cnt[a[i]]++;
    		
    		int r=D-i;
    		if(r<0) break;
    		
    		ll cur=0;
    		ROF(j,0,101){
    			int n=min(cnt[j],r);
    			r-=n;
    			cur+=j*n;
    		}
    		ckmax(ans,cur);
    	}
    	return ans;
    }


    return 0;
}



#ifdef LOCAL
int main() {
    boost; IO();


    int N,st,D; cin>>N>>st>>D;
    int a[N];
    FOR(i,0,N) cin>>a[i];

    cout << findMaxAttraction(N,st,D,a) << endl;

    return 0;
}
#endif
//Change your approach 