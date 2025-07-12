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

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){
      int a,b,c; cin>>a>>b>>c;
      if(a==0 && b==0 && c==0){cout << 0 << endl; continue;}

      string ans;
      /*if(b%2==0 && b!=0 && a!=0){ans+='0'; b--;}

      for(int i=0; i<=c && c!=0; i++) ans+='1';

      if(a==0 && b!=0) b++;
      for(int i=0; i<b;i++){
         if(i%2==0) ans+='0';
         else ans+='1';
      }
      for(int i=0;i<a;  i++) ans+='0';
      if(b==0 && a!=0) ans+='0';*/


      if(a==0 &&b!=0 && c!=0){
         for(int i=0; i<=c; i++) ans+='1';
         for(int i=0; i<b;i++){
            if(i%2==0) ans+='0';
            else ans+='1';
         }
      }
      else if(c==0 && a!=0 && b!=0){
         if(b%2==0){ans+='0'; b--;}
         for(int i=1; i<=b+1;i++){
            if(i%2==0) ans+='0';
            else ans+='1';
         }
         for(int i=0; i<a; i++) ans+='0';
      }

      else if(a==0 && b==0 && c!=0){
         for(int i=0; i<=c; i++) ans+='1';
      }
      else if(a==0 && c==0 && b!=0){
         for(int i=1; i<=b+1;i++){
            if(i%2==0) ans+='0';
            else ans+='1';
         }
      }

      else if(b==0 && c==0 && a!=0){
         for(int i=0; i<=a; i++) ans+='0';
      }
      else{
         if(b%2==0){ans+='0'; b--;}
         for(int i=0; i<=c; i++) ans+='1';
         for(int i=0; i<b;i++){
            if(i%2==0) ans+='0';
            else ans+='1';
         }
         for(int i=0; i<a; i++) ans+='0';
      }


      cout << ans << endl;
      //cout << endl;
   }


   return 0;
}

