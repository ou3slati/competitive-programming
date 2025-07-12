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

int N;
int x;
int t[20];

vector <int> xx;
vector <int> res;
int ress;
int sum;
int mn;

void solve(int y){
   for (int i=y; i<x; i++){

      if(sum+t[i]<=N){
         sum+=t[i];
         xx.pb(t[i]);

         if(N-sum<mn){
            mn=N-sum;
            res.assign(xx.begin(),xx.end());
            ress=sum;
         }

         solve(i+1);
         sum-=t[i]; xx.pop_back();
      }
   }

   return;
}

int32_t main(){
   boost;
   cin >>N;
   while(!cin.fail()){
      cin>>x;
      memset(t, 0, 20); res.clear(); xx.clear(); sum=0; mn=INF; ress=0;

      for (int i=0; i<x; i++) cin>>t[i];

      solve(0);

      for (int i=0; i<res.size(); i++) cout << res[i] << ' ';
      cout << "sum:" << ress << endl;

      cin>>N;
   }
}


