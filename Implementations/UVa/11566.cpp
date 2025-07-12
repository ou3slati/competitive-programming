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

const int mn=(-10)*100*25;

int N,x,T,K;
int p[110], f[110];
int memo[1500][150][25];

int dp(int m,int i, int c){
   if(c>2*N) return mn;
   if(ceil( ((double)m/N + T)*(1.1)) >x) return mn;
   if(i==K) return 0;

   int &ind=memo[m][i][c];
   if(ind!=-1) return ind;
   return ind=max( max( dp(m+p[i]*2,i+1,c+2)+2*f[i] , dp(m+p[i],i+1,c+1)+f[i] ) , dp(m,i+1,c) );
}

int32_t main(){
   boost;
   cin>>N>>x>>T>>K;
   while(N||x||T||K){
      N++;
      memset(f,0,sizeof(f));
      memset(memo,-1,sizeof(memo));
      for(int k=0; k<K; k++){
         cin >>p[k];
         for (int n=0; n<N; n++){int x; cin>>x; f[k]+=x;}
      }
      cout << fixed << setprecision(2) << (double)dp(0,0,0)/N << endl;

      cin>>N>>x>>T>>K;
   }


}


