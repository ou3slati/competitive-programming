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
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=2e5+10;
int spf[MXN];
vi p;
map <int,int> cnt; map<int,pi> mn;

void sieve(){
   for(int i=2; i<MXN; i++) if(spf[i]==-1){
      p.pb(i);
      for(int j=i; j<MXN; j+=i) spf[j]=i;
   }
}

void solve(int x){
   for(int i=0; p[i]*p[i]<=x; i++){
      if(x%p[i]==0) cnt[p[i]]++;
      int nb=0;
      while(x%p[i]==0){
         nb++;
         x/=p[i];
      }
      if(nb==0) continue;
      if(nb<mn[p[i]].fi){
         mn[p[i]].se=mn[p[i]].fi;
         mn[p[i]].fi=nb;
      }
      else if(nb<mn[p[i]].se) mn[p[i]].se=nb;
   }
   if(x>1){
      cnt[x]++;
      if(1<mn[x].fi){
         mn[x].se=mn[x].fi;
         mn[x].fi=1;
      }
      else if(1<mn[x].se) mn[x].se=1;
   }
}

int32_t main(){
   boost;
   memset(spf,-1,sizeof(spf));
   sieve();
   for(int i=0; i<sz(p); i++){
      cnt[p[i]]=0;
      mn[p[i]]={INF,INF};
   }

   int N; cin>>N;
   int t[N];
   for(int i=0; i<N; i++) cin>>t[i];
   for(int i=0; i<N; i++) solve(t[i]);

   int ans=1;
   for(int i=0; i<sz(p); i++){
      if(cnt[p[i]]==N-1) ans*=(int)(pow(p[i],mn[p[i]].fi)+0.5);
      else if(cnt[p[i]]==N) ans*=(int)(pow(p[i],mn[p[i]].se)+0.5);
   }
   cout << ans << endl;

   return 0;
}



