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

int32_t main(){
   boost;

   int N; cin>>N;
   vi a,b;
   int f=0,s=0;
   int l=-1;
   for (int i=0; i<N; i++){
      int x; cin>>x;
      if(x>0){f+=x; a.pb(x);}
      else{s+=abs(x); b.pb(abs(x));}
      if(i==N-1){
         if(x>0) l=1;
         else l=2;
      }
   }
   if(f>s) cout << "first" << endl;
   else if(s>f) cout<< "second"<< endl;
   else{
      for (int i=0; i<min(sz(a),sz(b)); i++){
         if(a[i]>b[i]){cout << "first" << endl; return 0;}
         if(b[i]>a[i]){cout << "second" << endl; return 0;}
      }
      if(sz(a)>sz(b)) {cout << "first" << endl; return 0;}
      if(sz(b)>sz(a)) {cout << "second" << endl; return 0;}
      if(l==1)cout << "first" << endl;
      else cout << "second" << endl;

   }

}

