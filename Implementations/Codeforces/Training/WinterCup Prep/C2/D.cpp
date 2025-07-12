#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define inf 1000000000
#define sz(x) (ll)x.size()
#define boost() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair< int , pii> piii;
typedef pair<int,bool> pib;
typedef vector<pii> vii;
typedef vector<pib> vib;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef pair<string,string> pss;
typedef pair<ll , ll> pll;
typedef vector<pss> vss;
typedef pair<ld , ld> pdd;
typedef vector<ld> vd;
typedef vector<vector<pib>> vvib;
typedef vector<piii> viii;
typedef vector<viii> vviii;
typedef vector<bool> vb;
typedef pair<pii , bool> piib;
typedef vector<pair<pii , bool>> viib;
const int   MOD = 1e9 + 7; //998244353;
const int N = 500005;

void IO() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
}

ll n , m;
vector<pair<ll , bool>> a;
vector<pair<ll, int>> sorted;

vi low,  high, remain;
int main()
{
	IO();

    cin >> n >> m;
    a.resize(n);
    sorted.resize(n);
    for(int i = 0;i<n;i++){
        cin >> a[i].fi >> a[i].se;
    }

    for(int i = 0;i<n;i++){
        sorted[i].fi = a[i].fi;
        sorted[i].se = i;
    }
    sort(all(sorted) , greater<pair<ll, int>>());
    ll sum = 0;

    for(int i = 0;i<(int)n;i++){
        sum += sorted[i].fi;
        if(a[sorted[i].se].se){
            low.pb(sorted[i].se);
        }
        else high.pb(sorted[i].se);

        if(sum >= m){
            i++;
            while(i < n){
                if(a[sorted[i].se].se) remain.pb(sorted[i].se);
                i++;
            }
            break;
        }
    }

    reverse(all(high));

    int next = 0;
    for(int i : high){
        if(next == remain.size())break;

        if(sum + a[remain[next]].fi - a[i].fi >= m){
            sum = sum + a[remain[next]].fi - a[i].fi;
            next++;
        }
    }

    cout << low.size()  + high.size() << " " << low.size() + next << endl;
    for(int i : low)cout << i+1 << " ";
    for(int i = 0;i<next ;i++)cout << remain[i] + 1 << " ";
    for(int i = next ;i< high.size();i++)cout << high[i] + 1 << " ";
}


//NEVER GIVE UP
//LONG LONG