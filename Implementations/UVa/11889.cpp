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

const int MXN=3200;

bitset <MXN> sv;
vi  p;
multiset <int> s,ss;
set <int> st;
int a,c;

void sieve(){
   sv.set();
   for (int i=2; i<MXN; i++) if(sv[i]){
      p.pb(i);
      for (int j=i*i; j<MXN; j+=i) sv[j]=0;
   }
}

void f(){
   for (int i=0; i<sz(p) && p[i]*p[i]<=a; i++){
      while(a%p[i]==0){
         s.insert(p[i]); st.insert(p[i]);
         a/=p[i];
      }
   }
   if(a>1){s.insert(a); st.insert(a);}

   for (int i=0; i<sz(p) && p[i]*p[i]<=c; i++){
      while(c%p[i]==0){
         ss.insert(p[i]);
         c/=p[i];
      }
   }
   if(c>1){ss.insert(c);}

}

int32_t main(){
   boost;
   sieve();
   int TC; cin>>TC;
   while(TC--){
      s.clear(); ss.clear(); st.clear();
      cin>>a>>c;
      f();

      bool ns=false;
      int b=1;

      for(auto x: st){
         if(s.count(x)>ss.count(x)){ns=true; break;}
         else if(s.count(x)<ss.count(x)) b*=(int)ceil(pow(x,ss.count(x)));
      }
      for(auto x:ss) if(st.count(x)==0) b*=x;

      if(ns) cout << "NO SOLUTION" << endl;
      else cout<< b<< endl;
      //cout << endl;
   }
}

