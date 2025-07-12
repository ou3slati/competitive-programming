#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef unsigned long long ull;
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

bool check(int x, int y){
   string a=to_string(x);
   string b=to_string(y);
   if(a.find(b)==0) return true;
   return false;

}

int32_t main(){
   boost;

   ull t[65];
   t[0]=1;
   for (int i=1; i<=64; i++) t[i]=t[i-1]*2;
   //for (int i=1; i<=64; i++) cout << t[i] << ' ';

   int N; cin>>N;
   while(!cin.fail()){
      int res=-1;
      for (int i=0; i<=64; i++){
         ull x=t[i];
         int n=floor(1+(double)log10(x));
         int m=floor(1+(double)log10(N));
         if(n>2*m && check(x,N)){
            res=i; break;
         }
      }
      if(res==-1)
         cout <<"no power of 2" <<endl;
      else cout << res << endl;

      cin>>N;
   }


}

