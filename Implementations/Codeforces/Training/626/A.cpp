#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int t; cin>>t;
   while(t--){
      int N; cin >>N;
      int n=0, m=0;
      int j=0,k=0,l=0;

      for(int i=1; i<=N; i++){
         int x; cin >>x; if(x%2==0){m++; l=i;}
         else { n++; if(!k&&!j) j=i; else if(!k && j)k=i;}
      }
      if(m)cout << 1 << endl<< l << endl;
      else if(n>1) cout << 2 << endl <<j << ' ' <<k << endl;
      else cout << -1 << endl;



   }
   return 0;
}
