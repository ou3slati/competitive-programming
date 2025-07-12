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
typedef vector<ld> vd;
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

const str hero="NijeZivotJedanACM";

bool comp(pair<pi,str> a, pair<pi,str> b){
   if(a.fi.fi==b.fi.fi && a.fi.se==b.fi.se) return a.se<b.se;
   if(a.fi.fi==b.fi.fi) return a.fi.se<b.fi.se;
   return a.fi.fi>b.fi.fi;
}

int32_t main(){
   boost;
   int N,M;cin>>N>>M;
   vector<pair<pi,str>> vec;

   str n;
   for(int i=0; i<N; i++){
      cin>>n;
      int x=0,y=0;
      for(int j=0; j<M; j++){
         str m; cin>>m;
         if(n==hero) continue;
         if(m[0]=='?'||m[0]=='+'){
            x++;
            y+=(m[1]-'0'-1)*20*60;
            y+=(m[4]-'0')*60*60; y+=((m[6]-'0')*10+m[7]-'0')*60; y+=((m[9]-'0')*10+m[10]-'0');
         }
      }
      vec.pb({{x,y},n});
   }

   sort(vec.begin(),vec.end(),comp);
   //for(auto x: vec) cout << x.fi.fi << ' ' <<x.fi.se << ' '<< x.se<< ' ' << endl;

   cin>>n;
   int x=0,y=0;
   for(int j=0; j<M; j++){
      str m; cin>>m;
      if(m[0]=='+'){
         x++;
         y+=(m[1]-'0'-1)*20*60;
         y+=(m[4]-'0')*60*60; y+=((m[6]-'0')*10+m[7]-'0')*60; y+=((m[9]-'0')*10+m[10]-'0');
      }
   }
   //cout << x << ' ' << y << endl;

   pair<pi,str> p={{x,y},hero};
   int ans;
   for(int i=0; i<sz(vec); i++){
      if(vec[i].fi.fi>x) continue;
      if(vec[i].fi.fi<x){
         ans=i+1;break;
      }
      if(vec[i].fi.se<y) continue;
      if(vec[i].fi.se>y){
         ans=i+1;break;
      }
      if(vec[i].fi.fi==x && vec[i].fi.se==y && vec[i].se<hero) continue;
      ans=i+1; break;
   }
   //cout << x<< ' ' << y << endl;
   cout << ans << endl;


   return 0;
}

