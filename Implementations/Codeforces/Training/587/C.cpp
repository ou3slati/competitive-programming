#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;

   int a,b,aa,bb; cin>>a>>b>>aa>>bb;
   int c,d,cc,dd; cin>>c>>d>>cc>>dd;

   int s=(aa-a)*(bb-b);
   //cout << s << endl;
   int x=0,y=0;
   if(!(a>=cc ||aa<=c)) x=min(cc,aa)-max(c,a);
   if(!(b>=dd||bb<=d)) y=min(dd,bb)-max(d,b);
   //cout << x*y << endl;
   s-=x*y;

   x=0; y=0;
   int e,f,ee,ff; cin>>e>>f>>ee>>ff;
   if(!(a>=ee ||aa<=e)) x=min(ee,aa)-max(e,a);
   if(!(b>=ff||bb<=f)) y=min(ff,bb)-max(f,b);
   //cout << x*y << endl;
   s-=x*y;

   x=0; y=0;
   if(c<=a) c=a; if(cc>aa) cc=aa;
   if(d<b) d=b; if(dd>bb) dd=bb;
   if(e<=a) e=a; if(ee>aa) ee=aa;
   if(f<b) f=b; if(ff>bb) ff=bb;

   if(!(c>=ee ||cc<=e)) x=min(ee,cc)-max(e,c);
   if(!(d>=ff||dd<=f)) y=min(ff,dd)-max(f,d);
   //cout << x*y << endl;
   s+=x*y;
   //cout << s << endl;
   if(s<=0) cout << "NO" << endl;
   else cout << "YES"<< endl;
}
