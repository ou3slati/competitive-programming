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

int32_t main(){
   boost;

   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      N++;
      vi vec;
      while(true){
         int x=N;
         for (int i=2;i*i<=x; i++) while(x%i==0){
            vec.pb(i);
            x/=i;
         }
         if(x>1)vec.pb(x);
         if(sz(vec)==1) continue;
         int s=0;
         for (int i=0; i<sz(vec); i++){
            int y=vec[i];
            while(y!=0){
               s+=y%10;
               y/=10;
            }
         }
         int ss=0, n=N;
         while(n!=0){
            ss+=n%10;
            n/=10;
         }
         if(s==ss){
            cout << N << endl;
            break;
         }
         vec.clear();
         N++;
      }

   }

}

