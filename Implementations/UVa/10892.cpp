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

const int MXN=50*1000;

int N;
int spf[MXN];
vi f,c;
vpi vec;

int gcd(int x, int y){
   if(y==0) return x;
   return gcd(y,x%y);
}

void sieve(){
   spf[1]=1;
   for (int i=2; i<MXN; i++) if(!spf[i]){
      spf[i]=i;
      for (int j=i*i; j<MXN; j+=i) spf[j]=i;
   }
}

void fact(int x){
   if(x<MXN) while(x!=1){
      f.pb(spf[x]);
      x/=spf[x];
   }
   else{
      for (int i=2; i*i<=x; i++)
         while(x%i==0){f.pb(i); x/=i;}
      if(x>1) f.pb(x);
   }
}

void compute(int val, int i){
   if(i==sz(vec)){
      c.pb(val);
      return;
   }
   int p=vec[i].se, x=vec[i].fi;
   int v=val;
   for (int j=0; j<=p; j++){
      compute(v,i+1);
      v*=x;
   }
}

void solve(){
   sort(all(f));
   for (int i=0; i<sz(f); i++){
      int x=f[i];
      int power=0;
      while(f[i]==x){power++; i++;}
      i--;
      vec.pb({x,power});
   }
   compute(1,0);
}

int32_t main(){
   boost;
   memset(spf,0,MXN);
   sieve();
   cin>>N;
   while(N){
      f.clear(); vec.clear(); c.clear();
      fact(N);
      solve();
      int res=0;
      for (int i=0; i<sz(c); i++) for (int j=i; j<sz(c); j++){
         if((c[i]*c[j])/gcd(c[i],c[j])==N) res++;
      }
      cout << N << ' ' <<res << endl;
      cin>>N;
   }
}

