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
typedef pair<db,db> pd;
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

db r[30];
db p[30];
int N;
map <pd,db> memo;
db S;

db solve(int m,int i){
   if(m>S) return -1*999999;
   if(m==S) return 0;
   if(i==N) return 0;
   if(memo.count({m,i})) return memo[{m,i}];
   db x=0;
   x=max(solve(m+p[i],i+1)+r[i],solve(m,i+1));
   return memo[{m,i}]=x;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
       memset(r,0,sizeof(r)); memo.clear();
       cin>>S;
       cin>>N;
       for (int n=0; n<N; n++){db x,P; cin>>x>>P; r[n]=(x*P)/(100.0-P); p[n]=x; }
       //for (int n=0; n<N; n++) cout << p[n] << ' ';
       db x=solve(0,0);
       x*=10;
       db res=round(x);
       res/=10;
       cout << res << endl;
   }


}
