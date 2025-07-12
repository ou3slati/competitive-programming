#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef long long ll;
typedef long double ld;

typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

#define pb push_back
#define popb pop_back
#define pp pop_back
#define pf push_front
#define popf pop_front
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second

///#define int ll

int nx[4] = {0,0,1,-1}, ny[4] = {1,-1,0,0};
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}

const int MOD =1e9 + 7;

int n;
vll A, B, C, Ap, Bp, Cp;
vi ans;
void sub1()
{
    vector<pair<pii,int>> ans;
   for(int i = 0; i < n - 1; i ++)
   {
       ans.pb({{min(B[i],A[i]),0},B[i] -min(B[i],A[i])});
       B[i] -= min(B[i],A[i]);
       A[i + 1] -= B[i];
       if(A[i + 1] < 0)
       {
           cout << "NO\n";
           return ;
       }
   }
   cout << "YES\n 0\n";
   for(auto e : ans)
        cout << e.ff.ff << ' ' << e.ff.ss << ' ' << e.ss << '\n';
   return ;
}
void solve()
{
    cin >> n;
    A.assign(n,0);
    B.assign(n - 1,0);
    C.assign(n - 1,0);
    for(int i=  0; i < n ;i ++)
        cin >> A[i];
    for(int i= 0 ; i < n - 1; i ++)
        cin >> B[i];
    for(int i=  0 ; i < n - 1; i ++)
        cin >> C[i];
    bool s1 = true;
    for(int i=  0; i < n - 1 ;i ++)
    {
        if(C[i] > 0)
            s1 = false;
    }



    //determine that it is impossible
    ll ans   = 0ll;
    Ap = A, Bp = B, Cp = C;
    ll bck[n], umb[n], frw[n];
    for(int i = 0; i < n - 1; i ++)
        bck[i] = umb[i] = frw[i] = 0 ;

    for(int i = 0; i < n- 1;i ++)
    {
        int j = i;
        ll u = min(Ap[i],Bp[i]);
        Bp[i] -= u;
        Ap[i] -= u;
        bck[i] += u;
        ll v = min(Bp[i],Ap[i + 1]);
        Ap[i + 1] -= v;
        Bp[i] -= v;
        frw[i] += v;
        ll k = min(Bp[i],Cp[i]);
        Bp[i] -= k;
        Cp[i] -= k;
        ans += k;
        umb[i] += k;
    }
    for(int i = n - 2; i > 0; i--)
    {
        if(Bp[i] == 0)
            continue;
        if(Bp[i] > A[i])
        {
            cout << "NO\n";
            return ;
        }
        bck[i] += Bp[i];
        ll rst = max(0ll,Bp[i] - Ap[i]);
        frw[i - 1] -= rst;
        Bp[i] = 0;
        Bp[i - 1] += rst;
        ll y = min(Cp[i - 1],Bp[i - 1]);
        ans += y;
        Bp[i - 1] -= y;
        Cp[i - 1] -= y;
        umb[i  -1] += y;
    }
    if(Bp[0] > 0)
    {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
    cout << ans << '\n';
    for(int i=  0; i < n-1;i ++)
        cout << bck[i] << ' ' << umb[i] << ' ' << frw[i] << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt = 1;
    while(tt --)
        solve();
}