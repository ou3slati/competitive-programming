#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int n; cin>>n;
   while(!cin.fail()){
      int i=1;
      while(((i+1)*i)/2<n) i++;
      int dif=((i+1)*i)/2 - n;
      int r,c;
      if(i%2==0){
         r=i-dif; c=1+dif;
      }
      else{
         c=i-dif; r=1+dif;
      }
      printf("TERM %d IS %d/%d\n",n,r,c);
      cin>>n;
   }

   return 0;
}
