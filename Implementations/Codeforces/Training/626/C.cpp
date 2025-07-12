#include <bits/stdc++.h>
using namespace std;

int main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int N; cin>>N;
   string s; cin >>s;

   /*int x=0, y=0;
   for (int i=0; i<N; i++){
      if(s[i]=='(') x++;
      else y++;
   }

   if(x!=y){ cout << -1 << endl; return 0;}

   stack <pair<int,char>> st;
   int res=0;
   vector <char,int> vec;
   for (int i=0; i<N; i++){
      if(s[i]=='('){st.push({'(',i});} else{st.pop();)
      while(!st.empty()){
         vec.pb({st.top().se, st.top().fi});
         st.pop();
      }
   }

   sort(vec.begin(), vec.end());

   int b=0;
   x=0; y=0;
   int res=0;
   for (int i=0; i<vec.size(); i++){
      if(!b) b=vec[i].fi;

      if(vec[i].se=='(') x++;
      else y++;

      if(x==y){res+=vec[i].fi -b+1; b=0; x=0; y=0;}
   }
   cout << res << endl;*/


   int x=0, y=0;
   int b=-1, e=-1;
   for (int i=0; i<N; i++){
      if(b==-1) b=i;
      if(s[i]=='(') x++; else y++;
      if(x==y)
   }


   return 0;
}
