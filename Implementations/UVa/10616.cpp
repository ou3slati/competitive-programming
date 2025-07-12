#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
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

int n,Q;
int t[200];
int d,m;
int memo[21][200][11];

int dp(int val,int id,int chosen){
   int &ind=memo[val][id][chosen];

   if(chosen==m){
      if(val==0) return ind=1;
      else return ind=0;
   }
   if(id==n) return 0;
   if(ind!=-1) return ind;

   ind = dp(((val+t[id])%d+d)%d, id+1, chosen+1)+ dp(val, id+1, chosen);

   return ind;

}

int32_t main(){
   boost;
   int st=0;
   cin>>n>>Q;
   while(n&&Q){
      memset(t,0,200);

      st++; cout <<"SET "<<st<<':'<<endl;
      for (int i=0; i<n; i++) cin>>t[i];
      for (int q=1; q<=Q; q++){
         cout << "QUERY "<<q<<": ";
         cin >>d>>m;
         if(m>n){cout << 0 <<endl; continue;}
         memset(memo,-1,sizeof(memo));
         cout <<dp(0,0,0)<<endl;
      }

      cin >>n>>Q;
   }
}


