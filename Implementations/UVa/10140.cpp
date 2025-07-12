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

const int mxn=1000*1000+1;

bitset<mxn> sv;
vi p;
int a,b,c,d,mx,mn;

void sieve(){
   sv[1]=0;
   for (int i=2; i<mxn; i++)if(sv[i]){
      p.pb(i);
      for (int j=i*i; j<mxn; j+=i)
         sv[j]=0;
   }
}

bool isPrime(int x){
   if(x<mxn) return sv[x];
   for (int i=0; i<sz(p) && p[i]*p[i]<=x; i++) if(x%p[i]==0) return false;
   return true;
}

int32_t main(){
   boost;
   sv.set();
   sieve();
   int l,r; cin>>l>>r;
   while(!cin.fail()){
      mn=INF; mx=0;
      int p=0;
      a=-1; b=-1; c=-1; d=-1;
      for (int i=l;i<=r; i++) if(isPrime(i)){
         if(p){
            if(i-p<mn){a=p; b=i; mn=i-p;}
            if(i-p>mx){c=p; d=i; mx=i-p;}
         }
         p=i;
      }
      if(a==-1) cout << "There are no adjacent primes."<< endl;
      else{
         cout<<a<<','<<b<<" are closest, "<<c<<','<<d<<" are most distant." << endl;
      }
      //cout << endl;
      cin>>l>>r;
   }
}

