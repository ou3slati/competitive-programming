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

int l,n;
int t[32];
int memo[5300];

int solve(int l){
   if(l==0) return 0;
   if(l<0) return INF;
   if(memo[l]) return memo[l];
   int x=INF;
   for (int i=0; i<n; i++) x=min(x,1+solve(l-t[i]));
   return memo[l]=x;
}

int32_t main(){
   boost;
   memset(memo,0,sizeof(memo));
   cin>>l>>n;
   for (int i=0; i<n;i++) cin>>t[i];
   int x=solve(l);
   if(x==INF) cout << "Roberta acknowledges defeat." << endl;
   else printf("Roberta wins in %d strokes.\n",x);

}

