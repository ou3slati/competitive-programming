#pragma GCC optimize("O3")
#include <bits/stdc++.h>
//#include "combo.h"
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
typedef double db;
typedef long double ld;

typedef pair<int,int> pi;
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

str res;
str t[4]={"A","B","X","Y"};

/*int press(str s){
   return 1;
}*/

void choose(){
   string s=res+t[0]+res+t[1];
   if(press(s)>=sz(res)+1){
      s=res+t[0];
      if(press(s)==sz(res)+1) res+="A";
      else res+="B";
   }
   else{
      s=res+t[2];
      if(press(s)==sz(res)+1) res+="X";
      else res+="Y";
   }
}

string guess_sequence(int N){
   choose();
   if(N==1) return res;

   for(int i=1; i<N-1; i++){
      if(res[0]=='A'){
         str s=res+"B" + res+"XB" + res+"XX" + res+"XY";
         int x=press(s);
         if(x==sz(res)+2) res+="X";
         else if(x==sz(res)+1) res+="B";
         else res+="Y";
      }

      else if(res[0]=='B'){
         str s=res+"A" + res+"XA" + res+"XX" + res+"XY";
         int x=press(s);
         if(x==sz(res)+2) res+="X";
         else if(x==sz(res)+1) res+="A";
         else res+="Y";
      }
      else if(res[0]=='X'){
         str s=res+"B" + res+"AB" + res+"AA" + res+"AY";
         int x=press(s);
         if(x==sz(res)+2) res+="A";
         else if(x==sz(res)+1) res+="B";
         else res+="Y";
      }
      else if(res[0]=='Y'){
         str s=res+"B" + res+"AB" + res+"AA" + res+"AX";
         int x=press(s);
         if(x==sz(res)+2) res+="A";
         else if(x==sz(res)+1) res+="B";
         else res+="X";
      }
   }
   choose();

   return(res);
}


/*int main(){
   boost;
   int n; cin>>n;
   str s=guess_sequence(n);

   return 0;
}*/

