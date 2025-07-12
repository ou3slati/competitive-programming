#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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

const int MXN=2e5+10;
int t[MXN];

void solve(int l,int r,int x){
   if(l>r) return;
   if(l==r){
      t[l]=x;
      return;
   }
   /*if(r-l+1==2){
      t[l]=x;
      t[r]=x+1;
      return;
   }*/

   if((r-l+1)%2==1){
      t[(l+r)/2]=x;
      solve(l,(l+r)/2-1,x*2);
      solve((l+r)/2+1,r,x*2+1);
   }
   else{
      t[(l+r-1)/2]=x;
      solve((l+r-1)/2+1,r,x*2-1);
      solve(l,(l+r-1)/2-1,x*2);
   }
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int N; cin>>N;
      //solve(1,N,1);

      set <pair<int,pi>> s;
      s.insert({-N,{1,N}});
      int cnt=1;

      while(!s.empty()){
         pair<int,pi> it=*s.begin();
         int l=it.se.fi, r=it.se.se;
         s.erase(it);

         if((r-l+1)%2==1) t[(r+l)/2]=cnt++;
         else t[(r+l-1)/2]=cnt++;

         if(r!=l){
            int lp,rp;
            if((r-l+1)%2==1){
               lp=(r+l)/2+1;rp=r;
               if(lp<=rp) s.insert({-(rp-lp+1),{lp,rp}});
               lp=l; rp=(r+l)/2-1;
               if(lp<=rp) s.insert({-(rp-lp+1),{lp,rp}});
            }
            else if((r-l+1)%2==0){
               lp=(r+l-1)/2+1;rp=r;
               if(lp<=rp) s.insert({-(rp-lp+1),{lp,rp}});
               lp=l; rp=(r+l-1)/2-1;
               if(lp<=rp) s.insert({-(rp-lp+1),{lp,rp}});
            }
         }
      }

      for(int i=1; i<=N;i++) cout << t[i] << ' ';
      cout << endl;
   }


   return 0;
}

