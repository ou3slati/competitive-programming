#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int n,k; cin >>n>>k;
   while(!cin.fail()){
      int res=0;
      while(n>=k){
         res+=(n/k)*k;
         n=n%k + n/k;
      }
      res+=n;
      cout <<res << endl;

      cin>>n>>k;
   }

   return 0;
}
