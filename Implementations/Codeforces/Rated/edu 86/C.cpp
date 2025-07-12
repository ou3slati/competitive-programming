#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ld;

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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int a,b,q;
int l,r;

int gcd(int a, int b){
   if(b==0) return a;
   return gcd(b,a%b);
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>a>>b>>q;
      if(b>a) swap(a,b);
      int lcm=(a*b)/gcd(a,b);
      cout << lcm << endl;
      for (int i=0; i<q;i++){
         cin>>l>>r;
         //cout << r-l+1-solve() << endl;
         /*int ans=0;
         for (int i=l; i<=r; i++)if((i%a)%b==(i%b)%a) ans++;*/
            /*for (int i=l; i<=r; i++)if((i%a)%b==(i%b)%a) cout << i << endl;
         cout << endl;*/



         int res=(r/lcm+1)*a -(l-1)/lcm*a;
         //cout << res << endl;
         int last=(r/lcm)*lcm+a-1;
         //cout << last << endl;
         if(res!=0 && last>r) res-=last-r;
         //cout << res << endl;
         if(l<a) res+=a-1-l+1; if(r<a-1) res-=a-1-r;
         //cout << res << endl;
         cout << r-l+1-res << ' ';
      }
      cout << endl;
      //cout << endl;
   }


   return 0;
}

