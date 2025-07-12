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

str multiply(str num1, str num2){
    int len1=sz(num1),len2=sz(num2);
 
    vi res(len1 + len2, 0);
    int i_n1 = 0,i_n2 = 0;
     
    for (int i=len1-1; i>=0; i--){
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
                   
        for (int j=len2-1; j>=0; j--){
            int n2 = num2[j] - '0';
            int sum = n1*n2 + res[i_n1 + i_n2] + carry;
            carry = sum/10;
            res[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
 
        if (carry > 0)
            res[i_n1 + i_n2] += carry;
 
        i_n1++;
    }
 
    int i = sz(res) - 1;
    while (i>=0 && res[i] == 0)
    i--;
 
    if (i == -1)
    return "0";
    string s = "";
     
    while (i >= 0)
        s += to_string(res[i--]);
 
    return s;
}


int32_t main() {
    boost; IO();

    str a,b; cin>>a>>b;
    cout << multiply(a,b) << endl;
    

    return 0;
}
//Change your approach 