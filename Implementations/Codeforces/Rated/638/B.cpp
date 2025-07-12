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

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N,k; cin>>N>>k;
      int t[N];
      int mn=INF,mx=0;
      bool vis[101]={false};
      int nb=0;
      for (int i=0; i<N; i++){cin>>t[i]; if(!vis[t[i]]){vis[t[i]]=true; nb++;}}
      if(nb>k){cout << -1 << endl;continue;}
      cout << N*k << endl;
      //mn-=k-(mx-mn+1);
      for (int i=0; i<N; i++){
         for(int j=1; j<=N; j++) if(vis[j]) cout << j << ' ';
         int x=k-nb;
         for (int j=0; j<x; j++) cout<<2 << ' ';
      }
      cout << endl;

   }


   return 0;
}

