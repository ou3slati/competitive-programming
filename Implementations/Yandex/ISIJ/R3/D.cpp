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
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

ld roots(int a, int b, int c)
{
    int d = b*b - 4*a*c;
    double sqrt_val = sqrt(abs(d));

    if (d > 0) {
       ld x=(double)(-b + sqrt_val)/(2*a),   y=(double)(-b - sqrt_val)/(2*a);
       if(x<0) return y;
       if(y<0) return x;
       return min(x,y);
    }
    else if (d == 0) {
        return -(double)b / (2*a);
    }
    /*else // d < 0
    {
       ld x=-(double)b / (2*a),sqrt_val ,  y=-(double)b / (2*a), sqrt_val);
       if(x<0) return y;
       if(y<0) return x;
       return min(x,y);
    }*/
}

ld aa,bb;

void solve(int a, int b){
   aa=roots(-1,a,-b);
   bb=a-aa;
}

int32_t main(){
   boost;
   /*freopen("majorhouse.in", "r", stdin);
   freopen("majorhouse.out", "w", stdout);*/

   int A,B,C,D; cin>>A>>B>>C>>D;

   int res=0;
   for(int x=1; x*x<=B; x++){
      /*int r=B/x,lll=A/x,l=A/x;
      int mx=-1;
      while(l<r){
         int y=(l+r)/2;
         if(x*y>=A && x*y<=B && 2*(x+y)<=D && 2*(x+y)>=C){l=y+1; mx=max(mx,y);}
         else r=y-1;
      }
      if(mx!=-1) res+=mx-lll+1;*/

      /*int l=A/x,r=B/x, l2=C/2-x,r2=D/2-x;
      if(l==0 || l2==0 || r==0||r2==0) continue;
      if(r>=l && r2>=l2) res+=min(r2-l2+1,r-l+1);*/

      int y=x;
      while(x*y<=B && x*y>=A){
         if(2*(x+y)<=D && 2*(x+y)>=C) res++;
         y++;
      }
   }
   cout << res << endl;

   /*if(B<=5000){
      int res=0;
      for(int x=1; x<=B; x++) for(int y=x; y<=B && y*x<=B && 2*x+2*y<=D; y++){
         if(x*y>=A && x*y<=B && 2*(x+y)<=D && 2*(x+y)>=C) res++;
      }
      cout << res << endl;
   }*/

   /*else{
      C=(C+1)/2;
      D=D/2;
      solve(C,A);
      ld a=aa,a2=bb;
      cout << a << ' ' << a2 << endl;
      solve(C,B);
      ld b=aa, b2=bb;

      pi low; low.fi=max((ll)0,(ll)ceil(a)); low.se=max((ll)0,(ll)ceil(a2));
      pi up; up.fi=max((ll)0,(ll)floor(b)); up.se=max((ll)0,(ll)floor(b2));

      cout << min(up.se-low.se+1,low.se-low.fi+1) << endl;
  }*/

  /*for(int x=1; x*x<=B; x++){

  }*/

   return 0;
}


   /*else if(D<=5000){
      int res=0;
      for(int x=1; x<=D/2+1; x++) for(int y=x; y<=D/2+1 && y*x<=B && 2*x+2*y<=D; y++){
         if(x*y>=A && x*y<=B && 2*(x+y)<=D && 2*(x+y)>=C) res++;
      }
      cout << res << endl;
   }*/
