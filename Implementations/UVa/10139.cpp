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

const int MXN=50000;
vi p;
bitset <MXN> sv;

void sieve(){
   sv.set();
   for (int i=2; i<MXN; i++) if(sv[i]){
      p.pb(i);
      for (int j=i*i; j<MXN; j+=i) sv[j]=0;
   }
}

int c(int p, int n){
   int x=p;
   int res=0;
   while(n/x>0){
      res+=n/x;
      x*=p;
   }
   return res;

}

int32_t main(){
   boost;
   sieve();
   int N,M; cin>>N>>M;
   while(!cin.fail()){
      int k=M;
      set <int> s;
      map <int,int> mp;
      for (int i=0; i<sz(p) && p[i]*p[i]<=M; i++){
         if(M%p[i]==0){
            mp[p[i]]=0;
            s.insert(p[i]);
         }
         while(M%p[i]==0){
            M/=p[i];
            mp[p[i]]++;
         }
      }
      if(M>1){
         mp[M]=1;
         s.insert(M);
      }
      bool div=true;
      for (auto x:s){
         if(c(x,N)<mp[x]){
            div=false;
            break;
         }
      }
      if(div) cout << k<<" divides "<<N<<'!' << endl;
      else cout << k<<" does not divide "<<N<<'!' << endl;
      //cout << endl;

      cin>>N>>M;
   }
}

