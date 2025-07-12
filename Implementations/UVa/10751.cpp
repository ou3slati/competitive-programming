#include <bits/stdc++.h>
using namespace std;

const double d=sqrt(2);

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int TC; cin >>TC;
   while(TC--){
      double res=0;
      int N; cin >>N;
      if(N==1){cout << fixed <<setprecision(3)<< 0.000<<endl; continue;}
      if(N==2){cout << fixed <<setprecision(3)<< 4.000<<endl; continue;}
      if(N%2==0){
         res+=((2+2*d)*(N/2-1)+2)*(N/2-1);
         if((N/2)%2==0) res+=(2+2*d)*(N/2)+(N-2);
         else if((N/2)%2) res+=3*(N-1)+2;

      }
      else if(N%2){
         res+=((2+2*d)*(N/2-1)+(3+d))*(N/2-1);
         if((N/2)%2==1) res+=(2+2*d)*(N/2-1)+(3+d)+(N-1)*2+1;
         else if((N/2)%2==0) res+=(4+2*d)*(N/2-1)+7+(N-1);
      }
      cout << fixed <<setprecision(3)<<res<<endl;
   }

   return 0;
}
