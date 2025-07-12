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

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int N,f;
ld s[100000], rs[100000];

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      cin>>N>>f;
      for (int n=0; n<N; n++){cin>>s[n]; rs[n]=s[n];}

      int i=0;
      ld res1=0, res2=0;
      while(i<N){
         if(rs[i]==0){i++; continue;}
         ld t=rs[i]/f;
         res2+=t;
         ld extra=rs[i]*i;
         for (int j=i+1; j<N; j++){
            ld c=rs[i];
            if(rs[j]>extra+c) {rs[j]-=extra+c; extra=0;}
            else if(rs[j]<=extra+c) {extra+=c-rs[j]; rs[j]=0;}
            //cout << extra << endl;
            if(j==N-1&&rs[j]==0) {res1=res2; res1-=extra/f; }
         }

         i++;
      }
      cout << fixed << setprecision(6) << res1 << ' ' << res2 << endl;
   }
}
