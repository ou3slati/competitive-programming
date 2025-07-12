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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int a,b;

void convert(string n, string m){
   a=0; b=0;
   int p1=sz(n),p2=sz(m);
   for(int i=0; i<sz(n); i++) if(n[i]=='.') p1=i;
   for(int i=0; i<sz(m); i++) if(m[i]=='.') p2=i;

   for(int i=0; i<p1; i++){
      a*=10;
      a+=n[i]-'0';
   }
   for(int i=0; i<p2; i++){
      b*=10;
      b+=m[i]-'0';
   }

   int i=p1+1,j=p2+1;
   while(i<sz(n)||j<sz(m)){
      a*=10;  b*=10;
      if(i<sz(n)) a+=n[i]-'0';
      if(j<sz(m)) b+=m[j]-'0';
      i++; j++;
   }
}

int gcd (int x, int y){
   if(y==0) return x;
   return gcd(y,x%y);
}

bool prime (int x, int y){
   if(x<2 || y<2) return false;
   for (int i=2; i*i<=x; i++) if(x%i==0) return false;
   for (int i=2; i*i<=y; i++) if(y%i==0) return false;
   return true;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      string n,m; cin>>n>>m;
      if(n==m) {cout << 2 << ' '<<2 << endl; continue;}
      convert(n,m);
      //cout << a << ' ' << b << endl;
      int g=gcd(a,b);
      int p=a/g, q=b/g;
      if(prime(p,q)) cout << p << ' ' << q << endl;
      else cout << "impossible" << endl;
   }

}

