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
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
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

int N,a,b;
vd vec;
ld memo[3000];

ld solve(int idx){
   if(idx==N) return 0;

   if(memo[idx]!=-1) return memo[idx];

   ld ans=INF;

   for(int i=idx; i<N; i++){
      ld mid=(vec[i]-vec[idx])/2;
      ans=min(ans,solve(i+1)+a+mid*b);
   }

   return memo[idx]=ans;
}

int32_t main(){
   boost;
   for(int i=0; i<3000; i++) memo[i]=-1;
   cin>>N>>a>>b;

   vec.assign(N,-1);
   for(int i=0; i<N; i++)cin>>vec[i];
   sort(all(vec));

   ld res=solve(0);
   int x=res;
   ld y=res-(ld)x;
   string s=to_string(y);
   while(s[sz(s)-1]=='0') s.pop_back();
   cout << x;
   if(sz(s)>2){
      cout << '.';
      for(int i=2; i<sz(s); i++) cout << s[i]-'0';
   }
   cout << endl;



   return 0;
}

