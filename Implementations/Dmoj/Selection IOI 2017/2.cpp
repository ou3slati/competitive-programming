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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N,M;cin>>N>>M;
   int d[N+1];
   for (int i=1; i<=N; i++)cin>>d[i];
   int g[N+1][101]={0};
   int a,b;
   for (int i=0; i<M; i++){
      cin>>a>>b;
      g[a][b]=1;
   }

	int Q; cin>>Q;
	for (int q=0; q<Q; q++){
      char c; cin>>c;
      if(c=='A'){
         cin>>a>>b;
         g[a][b]=1;
      }
      if(c=='S'){
         cin>>a>>b;
         g[a][b]=0;
      }
      if(c=='E'){
         cin>>a>>b;
         d[a]=b;
         for (int i=0; i<=100; i++) g[a][i]=0;
      }
      if(c=='Q'){
         cin>>a;
         int mn=INF;
         int ans=-1;
         for (int i=1; i<=N; i++) if(g[i][a]==1 && d[i]<mn){
            mn=d[i];
            ans=i;
         }
         cout << ans << endl;
         //cout << endl;
      }
	}

   return 0;
}

