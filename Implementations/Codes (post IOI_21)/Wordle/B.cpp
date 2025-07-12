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
    freopen("words.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}
/////////////////////////ONLY CLEAN CODES ALLOWED/////////////////////////


int32_t main() {
    boost; 

    str s; 
    V<str>vec; cin>>s; vec.pb(s);  
    while(s!="EOF"){
    	vec.pb(s); 
    	cin>>s; 
    }

    cout << "'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl; 
    cout.flush(); 

   	
   	str ans="     "; 

   	int no_here[5][26]; memset(no_here,0,sizeof(no_here)); 
   	vi yes(26,0), no(26,0); 

   	int rep=6; 
   	while(sz(vec) && rep--){

      if(rep==5){
        s="GRIEF";
      }
   		else{
        int i=random(0,sz(vec)-1); 
   		 s=vec[i]; 
      }

   		cout << s << endl;
   		cout.flush();


   		vi st(5); 
   		FOR(j,0,5) cin>>st[j]; 

   		FOR(j,0,5){
   			if(st[j]==2) ans[j]=s[j]; 
   			if(st[j]>=1) yes[s[j]-'A']=1; 

   			if(st[j]==1) no_here[j][s[j]-'A']=1; 
   			else if(st[j]==0) no[s[j]-'A']=1; 
   		}

   		V<str> new_vec;
   		for(str s: vec){
   			int rmv=0; 

   			FOR(j,0,5){
   				char c=s[j]; 
   				if(ans[j]!=' ' && c!=ans[j]) rmv=1; 
   				if(no_here[j][s[j]-'A']) rmv=1; 

   				FOR(idx,0,26) if(no[idx] && idx==c-'A') rmv=1;
   				FOR(idx,0,26) if(yes[idx]){
   					int f=0; 
   					for(char c2: s) if(idx==c2-'A') f=1; 
   					if(!f) rmv=1; 
   				}
   				
   				
   			}


   			if(!rmv) new_vec.pb(s); 
   		}

   		vec.assign(all(new_vec)); 
   		cout << sz(vec) << endl;
   		cout.flush(); 
   	}

   	for(str s: vec) cout << s << " "; 
   	cout.flush(); 
    

    return 0;
}
//Change your approach 

/*

Bug: Consider when the program guesses a word with
the same letter twice, while the result has only 1
It works when you put 1 for the duplicate (check)


PRINT

AUDIO
00010

WHIRL
00210

CRICK
02200

TRIBE
12200

*/