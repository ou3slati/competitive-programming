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
   int N,S,K; cin>>N>>S>>K;
   int d[N+1]; d[1]=0;
   for (int i=2; i<=N; i++){
      cin>>d[i];
      //d[i]+=d[i-1];
   }
   int v[N+1]={0},vv[N+1]={0};
   for (int i=1; i<=N; i++){
      cin>>v[i];
      vv[i]=vv[i-1]+v[i];
   }

	int l=0,r=0;
	int i=1,j=1;

	while(j<N && r+d[j+1]<=K){
      r+=d[j+1];
      j++;
	}
   //cout << j << endl;
	int mx=0,ires;
	for (int idx=2; idx<=N; idx++){

      if(j!=idx-1) r-=d[idx];
      if(j==idx-1) j=idx;
      while(j<N && r+d[j+1]<=K){
         r+=d[j+1];
         j++;
      }
      l+=d[idx];
      while(l>K && i<idx){
         l-=d[i+1];
         i++;
      }

      int x=vv[j]-vv[i-1];
      if(x>mx){
         mx=x;
         ires=idx;
      }
      /*cout << i << ' ' << j << endl;
      cout << x << endl;*/

	}
   cout <<1 << endl;
   cout << ires << endl;

   return 0;
}

