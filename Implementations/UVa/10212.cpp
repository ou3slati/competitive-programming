#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef long long ll;
#define int ll

const int MOD = 1000000000; //998244353

int32_t main(){
   boost;
   int n,m;
   cin>>n>>m;
   while(!cin.fail()){
      int res=1;
      for (int i=n; i>=n-m+1; i--){
         res*=i;
         while(res%10==0) res/=10;
         res%=MOD;
      }
      cout << res%10 << endl;
      //cout << endl;
      cin>>n>>m;
   }
}

