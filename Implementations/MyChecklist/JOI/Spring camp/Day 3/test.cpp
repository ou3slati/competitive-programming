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


int n=10,m=10;

vector<str>vec;
map<str,int>mp;
void generate(){
    vec.pb("");

    int rep=n; 
    while(rep--){
        vector<str>nw;
        for(auto &s: vec){
            str s1=s;

            if(!sz(s) || s.back()=='0'){
                s1.pb('1');
                nw.pb(s1);
            }
            s.pb('0');
        }

        for(auto s: nw) vec.pb(s);
    }
    sort(all(vec));

    FOR(i,0,sz(vec)) mp[vec[i]]=i;
}

int f[MX];
int encode(str s){
    
    f[0]=1; 
    f[1]=2;
    FOR(i,2,MX) f[i]=f[i-1]+f[i-2];

    reverse(all(s));

    int ans=0;
    FOR(i,0,n){
        if(s[i]=='1') ans+=f[i];
    }
    return ans; 
}

int32_t main() {
    boost; IO();
    

    generate();


    str s; cin>>s;
    cout << mp[s] << endl;

    cout << encode(s) << endl;
}
    

 
//Change your approach 