#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int n,m,c;
   cin>>n>>m>>c;
   while(n||m||c){
      //if((n==8||m==8)&&c==0) {cout << 0 << endl; cin>>n>>m>>c; continue;}

      int b,w;
      b=w=(m-7)/2;
      if((m-7)%2==1){
         if(c==0) b++;
         else w++;
      }
      //cout << b << ' ' << w<< endl;
      int nb,nw;
      nb=(n-8)/2; if((n-8)%2) nb++;
      nw=(n-7)/2; if((n-7)%2) nw++;

      cout << nb*b+nw*w << endl;

      cin>>n>>m>>c;
   }

   return 0;
}
