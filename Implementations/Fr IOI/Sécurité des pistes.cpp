//Never stop trying
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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   ld x,y,xx,yy;
   ld t[4];
   cin>>x>>y>>xx>>yy;
   if(x==xx){cout << x << ' ' << y << endl; return 0;}
   ld a,aa,b,bb;
   a=(y-yy)/(x-xx);
   b=y-a*x;

   t[0]=x; t[1]=y; t[2]=xx; t[3]=yy;


   cin>>x>>y>>xx>>yy;
   aa=(y-yy)/(x-xx);
   bb=y-aa*x;

   if(x==t[0] && y==t[1]) cout << x << ' ' << y << endl;
   else if(t[0]==xx && t[1]==yy) cout << xx << ' ' << yy << endl;
   else if(x==t[2] && y==t[3]) cout << x << ' ' << y << endl;
   else if(t[2]==xx && t[3]==yy) cout << xx << ' ' << yy << endl;

   else{
      ld xr=(bb-b)/(a-aa), yr=a*xr+b;
      cout << fixed << setprecision(8) << xr<< ' ' << yr << endl;
   }



   return 0;
}

