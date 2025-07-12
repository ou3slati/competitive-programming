#include <bits/stdc++.h>
using namespace std;

int memo[10001][10];
void print(int x){
   for (int i=0; i<=9; i++) cout << memo[x][i]<<' ';
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   memset(memo,0,sizeof(memo));
   int mx=0;

   int TC; cin>>TC;
   while(TC){
      int N; cin>>N;
      if(N<=mx){
         print(N);
         if(TC)cout << endl;
         continue;
      }
      for (int i=mx+1; i<=N; i++){
         for (int j=0; j<=9; j++) memo[i][j]=memo[i-1][j];
         int x=i;
         while(x!=0){
            memo[i][x%10]++;
            x/=10;
         }
      }
      print(N);
      mx=max(mx,N);
      if(TC)cout << endl;
   }

   return 0;
}
