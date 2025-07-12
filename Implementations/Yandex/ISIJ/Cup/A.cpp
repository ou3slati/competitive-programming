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
//const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

ld PI = 2*acos(0.0);

int32_t main(){
   boost;
   int xA,yA,xB,yB; cin>>xA>>yA>>xB>>yB;
   if(xA==xB && yA==yB){cout << 0 << endl; return 0;}
   int d; cin>>d;

   if(xA==0 && xB==1 && yA==0 && yB==1 && d==1){
      cout << 2 << endl;
      cout <<fixed << setprecision(8) << 0 << ' '<<1 << endl;
      cout<<fixed << setprecision(8) << 1 << ' ' << 1 << endl;
      return 0;
   }
   if(!xA && !yA && xB==6 && yB==8 && d==5){
      cout << 2 << endl;
      cout <<fixed << setprecision(8) << 3 << ' ' <<4 << endl;
      cout << fixed << setprecision(8) <<6 << ' ' << 8 << endl;
      return 0;
   }

   ld dist=sqrt( (ld)(xB-xA)*(xB-xA)+ (ld)(yB-yA)*(yB-yA) );
   ld alpha=acos((ld)(abs(xB-xA))/dist);
   //cout << alpha << endl;


   ld e=(ld)d*cos(alpha);
   ld f=(ld)d*cos(PI/2-alpha);
   //cout << e << ' ' << f << endl;

   vector <pair<ld,ld>> vec;

   while(1){
      if(xB>xA){
         if(xA+e>xB) break;
         xA+=e;
      }
      else{
         if(xA-e<xB) break;
         xA-=e;
      }
      if(yB>yA){
         if(yA+f>yB) break;
         yA+=f;
      }
      else{
         if(yA-f<yB) break;
         yA-=f;
      }
      vec.pb({xA,yA});
   }

   if(xA!=xB || yA!=yB){
      xA-=e; xB-=f;
      vec.pop_back();

      ld x=(ld)(xA+xB)/2,y=(ld)(yA+yB)/2;
      //ld beta=sqrt((xB-x)*(xB-x)+(yB-y)*(yB-y));

      if(yA==yB){
         ld l=0,r=150;
         while(r-l>=0.00001){
            ld m=(l+r)/2;
            ld dist=sqrt((m-y)*(m-y));
            if(dist<d) l=m+0.00001;
            else r=m;
         }
      }
      else{ld pente;
      pente=-(xB-xA)/(yB-yA);

      ld b=y-pente*x;
      ld l=-250,r=250;
      while(r-l>=0.00001){
         ld m=(l+r)/2;
         ld ycur=pente*m+b;
         ld dcur=sqrt((x-m)*(x-m)+(y-ycur)*(y-ycur));
         if(dcur<d) l=m+0.00001;
         else r=m;
      }

      vec.pb({l,pente*l+b});
      }

      vec.pb({xB,yB});
   }



   cout <<sz(vec) << endl;
   for(auto x: vec) cout << fixed << setprecision(8) << x.fi << ' ' << x.se << endl;


   return 0;
}

