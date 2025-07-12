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

int res=0;
string st;

void solve(string s, int j){
   for (int i=j; i<sz(s); i++){
      char c=s[i]-1;
      if((i<sz(s)-1 && s[i+1]==c)|| (i>0 && s[i-1]==c)){
         string ss=s;
         ss.erase(i,1);
         res=max(res,sz(st)-sz(ss));
         if(i==0) solve(ss,i);
         else solve(ss,i-1);
      }
   }
   return;
}

int32_t main(){
   boost;
   int N; cin >>N;
   cin>>st;
   solve(st,0);
   cout << res << endl;
   return 0;
}


