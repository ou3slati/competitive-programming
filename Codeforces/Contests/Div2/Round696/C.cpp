/*
CF 696C - TBD
https://codeforces.com/contest/1474/problem/C

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
const int MX = 1e6 + 10;
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

int main() {
    boost; IO();

    int TC; cin>>TC;
    while(TC--){
    	int N; cin>>N; N*=2; 
    	vi a(N);
    	FOR(i,0,N){
    		cin>>a[i];
		}
    	sort(all(a));
    	
        vpi ans;
    	FOR(i,0,N-1){
            int x=a[sz(a)-1];

            multiset<int>s;
            FOR(j,0,N-1) if(j!=i) s.insert(a[j]);


            bool pos=1;
            vpi vec={{x,a[i]}};

            while(sz(s)){
                auto it=s.end(); it--;
                int y=*it;
                s.erase(it);

                int r=x-y;
                if(!s.count(r)){
                    pos=0;
                    break;
                }
                vec.eb(y,r);
                
                s.erase(s.find(r));

                x=y;
            }
            if(pos) ans.assign(all(vec));
        }

        if(!sz(ans)) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << ans[0].fi+ans[0].se << endl;
            for(auto x: ans) cout << x.fi << ' ' << x.se << endl; 
        }
    }
    

    return 0;
}
//Change your approach 