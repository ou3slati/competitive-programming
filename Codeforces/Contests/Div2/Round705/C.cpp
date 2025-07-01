/*
CF 705C - TBD
https://codeforces.com/contest/1493/problem/C

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

vi cnt;
str s; 
int N,K,sum;

int f(int x){
	if(x%K==0) return 0;
	return K-x%K;
}

void upd(int i, int v){
	sum-=f(cnt[i]);
	cnt[i]+=v;
	sum+=f(cnt[i]);
}

void output(int idx, int c){
	vi cnt(26,0);
	str ans;
	FOR(i,0,idx){
		ans+=s[i];
		cnt[s[i]-'a']++;
	}
	ans+=char('a'+c); cnt[c]++;

	str suf;
	FOR(i,0,26){
		while(cnt[i]%K!=0){
			suf+=char('a'+i);
			cnt[i]++;
		}
	}

	while(sz(ans)<N-sz(suf)) ans+='a';
	ans+=suf;
	cout << ans << endl;
}

int main() {
    boost; IO();

    int t; cin>>t;
    while(t--){
    	cnt.assign(26,0);
    	cin>>N>>K>>s;
    	sum=0;

    	if(N%K){
    		cout << -1 << endl;
    		continue;
    	}
    	
    	for(auto x: s) upd(x-'a',1);
    		
    	if(sum==0){
    		cout << s << endl;
    		continue;
    	}

    	bool done=0;
    	ROF(i,0,N){
    		upd(s[i]-'a',-1);

    		int ans=-1;
    		FOR(j,s[i]-'a'+1,26){
    			upd(j,1);
    			if(sum<=N-1-i){
    				output(i,j),done=1;
    				break;
    			}
    			upd(j,-1);
    		}

    		if(done){
    			break;
			}
    	}
    	if(!done) cout << -1 << endl;
    }
    

    return 0;
}
//Change your approach 