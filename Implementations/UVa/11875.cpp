#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int t;cin>>t;
   for (int i=1; i<=t; i++){
      int N; cin >>N;
      int tt[N];
      for (int j=0; j<N; j++) cin>>tt[j];

      int ind=N/2;
      cout <<"Case " << i <<": " << tt[ind]<< endl;
   }

   return 0;
}
