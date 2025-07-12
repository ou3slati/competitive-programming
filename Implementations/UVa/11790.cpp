#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
typedef double db;
typedef long double ldb;

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

int32_t main(){
   boost;
   int TC; cin>>TC;
   int nb=0;
   while(TC--){
      int N; cin >>N;
      int t[N], w[N];
      for (int n=0; n<N; n++) cin>>t[n];
      for (int n=0; n<N; n++) cin>>w[n];
      int in[N],d[N];
      int l[N]={0},ll[N]={0};

      for(int i=0; i<N; i++){
         //in[i]=1;
         l[i]=w[i];
         for (int j=0; j<i; j++) if(t[j]<t[i] && in[i]<=in[j]+1){
            in[i]=in[j]+1;
            l[i]=max(l[i],l[j]+w[i]);
         }
         //d[i]=1;
         ll[i]=w[i];
         for (int j=0; j<i; j++) if(t[j]>t[i] && d[i]<=d[j]+1){
            d[i]=d[j]+1;
            ll[i]=max(ll[i],ll[j]+w[i]);
         }
      }

      for (int i=0; i<N; i++) cout << d[i] << ' '; cout << endl;
      for (int i=0; i<N; i++) cout << ll[i] << ' '; cout << endl;

      int mx=0,mxx=0;
      for (int i=0; i<N; i++){
         mx=max(mx,l[i]);
         mxx=max(mxx,ll[i]);
      }
      if(mx>=mxx)
         printf("Case %d. Increasing (%d). Decreasing (%d).\n",++nb,mx,mxx);
      else
         printf("Case %d. Decreasing (%d). Increasing (%d).\n",++nb,mxx,mx);
      cout << endl << endl;
   }


}

