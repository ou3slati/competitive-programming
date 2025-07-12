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

    int t; cin>>t; 
    while(t--){
    	int N; cin>>N; 
    	vi vec; 
    	
    	FOR(i,0,N){
    		int x; cin>>x; 
    		vec.pb(x); 
    	}
    	sort(all(vec)); 

    	unordered_map<int,int>cnt,jump,jump2; 

    	vi p(N,0),s(N,0); //pref and suf
    	FOR(i,0,N){
    		cnt[vec[i]]++;

    		if(!i) jump[vec[i]]=vec[i]-1; 
    		else if(vec[i]-vec[i-1]-1>0) jump[vec[i]]=vec[i]-1;
    		else jump[vec[i]]=jump[vec[i-1]]; 

    		if(cnt[vec[i]]>1){
    			p[i]+=vec[i]-jump[vec[i]]; 
    			cnt[vec[i]]--; 
    			cnt[jump[vec[i]]]++; 

    			while(cnt[jump[vec[i]]]>0){
    				jump[vec[i]]--; 
    			}

    			/*if(cnt[jump[vec[i]]-1]==0) jump[vec[i]]--;
    			else jump[vec[i]]=jump[jump[vec[i]]-1]; */
    		}



    		if(i) p[i]+=p[i-1]; 
    	}

    	cnt.clear();
    	//jump.clear(); 

    	ROF(i,0,N){
    		cnt[vec[i]]++; 

    		if(i==N-1) jump2[vec[i]]=vec[i]+1; 
    		else if(vec[i+1]-vec[i]-1>0) jump2[vec[i]]=vec[i]+1;
    		else jump2[vec[i]]=jump2[vec[i+1]]; 

    		if(cnt[vec[i]]>1-(i-1>=0 && vec[i]==vec[i-1])){
    			s[i]+=jump2[vec[i]]-vec[i]; 
    			cnt[vec[i]]--;
    			cnt[jump2[vec[i]]]++;  

    			while(cnt[jump2[vec[i]]]>0){
    				jump2[vec[i]]++; 
    			}

    			/*if(cnt[jump2[vec[i]]+1]==0) jump2[vec[i]]++;
    			else jump2[vec[i]]=jump2[jump2[vec[i]]+1]; */
    		}



    		if(i+1<N) s[i]+=s[i+1]; 
    	}

    	dbgv(p)
    	dbgv(s)


    	int ans=INF; 
    	FOR(i,0,N+1){
    		int x=0; 
    		if(i) x+=p[i-1]; 
    		if(i<N) x+=s[i]; 

    		//if(i && i<N && vec[i-1]==vec[i]) x+=min(jump[vec[i]],jump2[vec[i]]); 

    		ckmin(ans,x); 
    	} 
    	cout << ans << endl;

    }
    

    return 0;
}
//Change your approach 