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

int n;
int t[5]={1,5,10,25,50};
int memo[31000][5];


int dp(int m, int i){
   if(i==5) return 0;
   if(m==0) return 1;
   if(m<0) return 0;

   int &ind=memo[m][i];
   if(ind!=-1) return ind;
   return ind=dp(m-t[i],i)+dp(m,i+1);

}

int32_t main(){
   boost;
   cin>>n;
   memset(memo,-1,sizeof(memo));
   while(!cin.fail()){
      int x=dp(n,0);
      if(x!=1)
      cout<<"There are " << x <<" ways to produce " << n << " cents change." << endl;
      else
      cout<<"There is only " << x <<" way to produce " << n << " cents change." << endl;
      cin>>n;
   }


}


