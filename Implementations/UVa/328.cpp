#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cout << "PERFECTION OUTPUT" <<endl;

   int n; cin >>n;
   while(n){
      int sum=1;
      if(n==1) sum=0;
      for (int i=2; i*i<=n; i++)
         if(n%i==0){
            if(i*i==n){sum+=i;}

            else{
            sum+=i; sum+=n/i;
            }
         }

      //cout << sum<<' ';
      int d=(int)floor(1+log10((double)n));
      for (int i=0; i<5-d; i++) cout << ' ';
      cout << n <<"  ";
      if(sum==n)cout <<"PERFECT" << endl;
      else if(sum>n)cout << "ABUNDANT"<<endl;
      else cout <<"DEFICIENT" << endl;


      cin>>n;
   }
   cout << "END OF OUTPUT" << endl;
   return 0;
}
