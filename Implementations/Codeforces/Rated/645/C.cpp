#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
#define int ll
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

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int x,y,xx,yy; cin>>x>>y>>xx>>yy;

      /*int v=((x+x+*x)/2+y*((2*x+y-1)*y)/2;
      cout <<v << endl;

      int up,down;
      int s=x+y-1;
      up=v*(yy-y+1) + ((s+s+(yy-y))*(yy-y))/2 ;
      cout << up << endl;

      cout << up-down << endl;*/

      int v=((1+x+y-2)*(x+y-2))/2; if(y>1) v+=x;
      if(v==0) v=1;
      //cout << v << endl;

      int a=yy-y, b=xx-x;
      int aj=x+y-1;
      int up=v+((v+aj+v+aj+a-1)*(a))/2 + ((v+aj+a+1+v+aj+a+b)*(b))/2;
      cout << up << endl;

      aj++;
      int down=v+((v+aj+v+aj+b-1)*(b))/2 + ((v+aj+b-1+v+aj+b+a-2)*a)/2;



      cout << up-down << endl;
   }


   return 0;
}

/*
1
1 1 6 6
*/
