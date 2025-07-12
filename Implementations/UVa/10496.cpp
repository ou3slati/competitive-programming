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
const int INF = 1e16;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int N;
int x[20],y[20];
int memo[12][1<<11];

int tsp(int i, int m){
   if(m==(1<<(N+1))-1) return abs(x[i]-x[0])+abs(y[i]-y[0]);

   int &ind=memo[i][m];
   if(ind!=-1) return ind;

   int p=INF;
   for (int b=0; b<=N; b++)
      if(!(m&(1<<b)) && i!=b)
         p=min( p, tsp(b,m|(1<<b))+abs(x[i]-x[b])+abs(y[i]-y[b]) );
   return ind=p;

}

int32_t main(){
   boost;
   int TC; cin >>TC;
   while(TC--){
      int d,dd; cin>>d>>dd;
      cin>>x[0]>>y[0]>> N;
      for (int n=1; n<=N; n++)cin>>x[n]>>y[n];

      memset(memo,-1,sizeof memo);
      cout << "The shortest path has length " << tsp(0,1) << endl;
   }
}


/*1
10 10
1 1
4
2 3
5 5
9 4
6 5
*/
