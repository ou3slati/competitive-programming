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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

map <int,bool> mp;
bool prime(int x){
   if(x<2) return false;
   if(x==2) return true;
   if(mp.count(x)) return mp[x];
   bool res=true;
   for(int i=2; i*i<=x; i++) if(x%i==0){res=false; break;}

   return mp[x]=res;
}

void output(vi vec){
   cout << sz(vec) << endl;
   for(auto x: vec) cout << x << ' ';
   return;
}

bool check(vi vec){
   for(int i=0; i<sz(vec); i++) if(!prime(vec[i])||(i>0&&!prime(abs(vec[i]-vec[i-1])))) return false;
   return true;
}

int32_t main(){
   boost;
   int a,b; cin>>a>>b;

   vi vec; vec.pb(a); vec.pb(b);
   if(check(vec)){output(vec);return 0;}

   vec.ppb(); vec.pb(2); vec.pb(b);
   if(check(vec)){output(vec);return 0;}

   vec[1]=a+2;
   if(check(vec)){output(vec);return 0;}
   vec[1]=a-2;
   if(check(vec)){output(vec);return 0;}
   vec[1]=b-2;
   if(check(vec)){output(vec);return 0;}
   vec[1]=b+2;
   if(check(vec)){output(vec);return 0;}

   vec.ppb(); vec.ppb(); vec.pb(a+2); vec.pb(2); vec.pb(b);
   if(check(vec)){output(vec);return 0;}

   vec[1]=a-2;
   if(check(vec)){output(vec);return 0;}

   vec[1]=2; vec[2]=b+2; vec[3]=b;
   if(check(vec)){output(vec);return 0;}

   vec[2]=b-2;
   if(check(vec)){output(vec);return 0;}

   vec.clear(); vec.pb(a); vec.pb(a+2); vec.pb(2); vec.pb(b+2); vec.pb(b);
   if(check(vec)){output(vec);return 0;}

   vec[3]=b-2;
   if(check(vec)){output(vec);return 0;}

   vec[1]=a-2;
   if(check(vec)){output(vec);return 0;}

   vec[3]=b+2;
   if(check(vec)){output(vec);return 0;}

   cout << -1 << endl;
   return 0;
}

