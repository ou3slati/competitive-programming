//not solved
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

int m,n;
int t[100];
string s[100];
int memo[100];
vi vec;

int solve(int i){


   int mx=0;
   int idx=-1;
   for (int j=i; j<i+m && j<n; j++){
      int x=t[i]+solve(j+1);
      if(x>mx){
         mx=x;
         idx=j;
      }
   }
}

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   cin>>m>>n;
   for (int i=0; i<n; i++) cin>>s[i]>>t[i];
   int res=solve(0);
   cout << "Total Time: "<<x << endl;

}

