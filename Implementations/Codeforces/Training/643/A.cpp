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


int mn (int x){
   int res=INF;
   while(x>0){
      res=min(res,x%10);
      x/=10;
   }
   return res;
}
int mx(int x){
   int res=0;
   while(x>0){
      res=max(res,x%10);
      x/=10;
   }
   return res;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N,K; cin>>N>>K;
      K--;
      while(K--){
         int a=mn(N),b=mx(N);
         if(a==0||b==0) break;
         N+=mn(N)*mx(N);
      }
      cout << N << endl;
   }

   return 0;
}

