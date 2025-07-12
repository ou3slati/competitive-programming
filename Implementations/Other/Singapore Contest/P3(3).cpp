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
   }
   int v[N+1]={0},vv[N+1]={0};
   for (int i=1; i<=N; i++){
      cin>>v[i];
      vv[i]=vv[i-1]+v[i];
   }

   int mx=0;
   vi res;
   int ires;
   for (int i=1; i<=N; i++){
      int r=S,j=i;
      vi vec;
      int rem=0;
      while(1){
         if(r==0 || j==N+1) break;
         int dis=0;
         while(j<N && dis+d[j+1]<=K){
            dis+=d[j+1];
            j++;
         }
         dis=0;
         vec.pb(j);
         while(j<N && dis+d[j+1]<=K)
         {
            dis+=d[j+1];
            j++;
         }

         r--;
         //vec.pb(j);
         j++;
      }

      int x=vv[j-1]-vv[i-1];
      if(x>mx){
         mx=x;
         res.assign(all(vec));
         ires=i;
      }
      /*for(int i=0; i<sz(vec); i++) cout << vec[i] << ' ';
      cout << endl;*/
   }
   //cout << ires << endl;
	cout << sz(res) << endl;
	for (int i=0; i<sz(res);i++) cout << res[i] << ' ';
	cout << endl;

   return 0;
}

