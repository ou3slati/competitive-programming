#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int32_t main(){
   boost;
   int x,y; cin >>x;
   while(x!=0){
      cin>>y;
      int t1[x],t2[y];
      for (int i=0; i<x; i++) cin>>t1[i];
      for (int i=0; i<y; i++) cin>>t2[i];

      vector <double> v;
      for(int i=0; i<x; i++)
         for (int j=0; j<y; j++){
            double r=(double)t2[j]/t1[i];
            v.push_back(r);
         }

      sort(v.begin(),v.end());
      double res=0;
      for (int i=0; i<v.size()-1; i++){
         double x=v[i+1]/v[i];
         res=max(res,x);
      }
      double xx=(round(res*100))/100;
      cout << fixed << setprecision(2)<<xx<< endl;

      cin>>x;
   }
   return 0;
}
