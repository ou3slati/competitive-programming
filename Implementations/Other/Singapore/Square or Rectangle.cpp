//Never stop trying
#include "squarerect.h"
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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e7;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

bool am_i_square(int N, int Q){
   int mnx=INF,mny=INF,mxx=-1,mxy=-1;

   for(int i=20; i<=80; i+=20) for(int j=20; j<=80; j+=20) if(inside_shape(i,j)){
      mnx=min(mnx,i); mny=min(mny,j); mxx=max(mxx,i); mxy=max(mxy,j);
   }

   if(mxx!=-1){
      int l=mnx-20+1,r=mnx;
      while(l<r){
         int m=(l+r)/2;
         if(!inside_shape(m,mny)) l=m+1;
         else r=m;
      }
      mnx=l;
      //cout << mnx << endl;

      l=mny-20+1;r=mny;
      while(l<r){
         int m=(l+r)/2;
         if(!inside_shape(mnx,m)) l=m+1;
         else r=m;
      }
      mny=l;
      //cout << mny << endl;

      l=mxx; r=mxx+20;
      while(l<r){
         int m=(l+r+1)/2;
         if(!inside_shape(m,mny)) r=m-1;
         else l=m;
      }
      mxx=l;
      //cout << mxx << endl;

      if(100-mny<mxx-mnx) return false;
      if(!inside_shape(mnx,mny+mxx-mnx)) return false;
      if(mny+mxx-mnx+1==101) return true;
      if(inside_shape(mnx,mny+mxx-mnx+1)) return false;
      return true;
   }

   else{
      int nb=0;
      int x,y;
      for(int i=20; i<=100; i+=20) if(inside_shape(i,100)){
         nb++;
         x=i; y=100;
      }
      if(nb>1) return false;

      if(nb>0){
         int l=x-20+1,r=x;
         while(l<r){
            int m=(l+r)/2;
            if(!inside_shape(m,y)) l=m+1;
            else r=m;
         }
         x=l;

         if(x+19>100) return false;
         if(!inside_shape(x+19,y)) return false;
         if(x+20==101) return true;
         if(inside_shape(x+20,y)) return false;
         return true;
      }

      for(int j=20; j<=80; j+=20) if(inside_shape(100,j)){
         nb++;
         x=100; y=j;
      }
      if(nb>1 || !nb) return false;

      int l=y-20+1,r=y;
      while(l<r){
         int m=(l+r)/2;
         if(!inside_shape(x,m)) l=m+1;
         else r=m;
      }
      y=l;

      if(y+19>100) return false;
      if(!inside_shape(x,y+19)) return false;
      if(y+20==101) return true;
      if(inside_shape(x,y+20)) return false;
      return true;
   }
}
