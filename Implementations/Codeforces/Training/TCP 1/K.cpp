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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int N,x;
int t[1000*1000];
map<pi,int> memo;

void dp(int val, int i, int m){
   if(m!=0 && val==0){
      cout << "YES" << endl;
      exit(0);
   }
   if(i==N) return;
   //cout << val << endl;

   if(memo.count({val,i})) return;

   dp((val+t[i])%x,i+1, m|(1<<i));
   dp(val,i+1,m);

   memo[{val,i}]=0;
   return;
}

int32_t main(){
   boost;
   cin>>N>>x;
   for (int i=0; i<N; i++){
      cin>>t[i];
      t[i]=t[i]%x;
   }
   /*for (int i=0; i<N; i++) cout << t[i] << ' ';
   cout << endl;*/
   dp(0,0,0);
   cout << "NO" << endl;
}

