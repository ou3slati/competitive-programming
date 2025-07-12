#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int n; cin >>n;
   while(n){
      int x=ceil((double)sqrt(n));
      int a=x*x,b=(x-1)*(x-1)+1;
      int m=(a+b)/2;
      if((a+b)%2) m++;
      if(x%2==0){
         if(n<=m) cout << 1+(n-b) << ' '<< x<< endl;
         else cout <<  x << ' ' << 1+(a-n)<< endl;
      }
      else{
         if(n<=m) cout << x << ' '<<1+(n-b) << endl;
         else cout <<  1+(a-n) << ' ' << x << endl;
      }


      cin>>n;
   }

   return 0;
}
