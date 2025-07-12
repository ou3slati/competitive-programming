//Never stop trying
/*#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
#include "bits/stdc++.h"
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll
typedef string str;
typedef double db;
typedef long double ld;
typedef pair<int, int> pi;
#define fi first
#define se second
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<str> vs;
typedef vector<ld> vd;
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

ll dp[1005][505], inv[2005], l[505], r[505];
const int mod = 1e9 + 7;

int32_t main() {
    boost; IO();

    ll n;
    cin >> n;
    inv[1] = 1;
    
    for (int i = 2; i < 2000; i++) inv[i] = (mod / i) * (mod - inv[mod % i]) % mod;
    

    vector<ll> val;
    for (int i = 1; i <= n; i++){
            cin >> l[i] >> r[i];
            val.push_back(l[i]);
            r[i]++;
            val.push_back(r[i]);
    }
    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    for (int i = 1; i <= n; i++){
            l[i] = lower_bound(val.begin(), val.end(), l[i]) - val.begin() + 1;
            r[i] = lower_bound(val.begin(), val.end(), r[i]) - val.begin() + 1;
    }


    dp[0][0] = 1;  
    for (int i = 1; i < val.size(); i++){ 
            dp[i][0] = 1;
            for (int j = 1; j <= n; j++){
                    dp[i][j] = dp[i - 1][j];
                    if (l[j]>i || r[j]<=i) continue;

                    ll s = val[i] - val[i - 1];  
                    ll cnt = 1; 
                    ll p = s;

                    for (int k = j - 1; k >= 0; k--){
                            dp[i][j] = (dp[i][j] + dp[i - 1][k] * p) % mod;

                            if (l[k] <= i && r[k] > i){
                                    p = p * (s + cnt) % mod;
                                    p = p * inv[cnt + 1] % mod;
                                    cnt++;
                            }
                    }
            }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++){
            ans = (ans + dp[val.size() - 1][i]) % mod;
    }
    cout << ans;
     


    return 0;
}

/* Careful!!!
    .Array bounds
    .Infinite loops
    .Uninitialized variables / empty containers
    .Multisets are shit

   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
*/