#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int gcd(int x, int y){
   if(y>x) swap(x,y);
   int b=x, q=y;
   while(b%q!=0){
      int r=b%q;
      b=q; q=r;
   }
   return q;
}

bool prime(int x){
   if(x==1) return false;
   if(x==2) return true;
   for (int i=2; i*i<=x; i++) if(x%i==0) return false;
   return true;
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){

      long double aa,bb; cin >>aa>>bb;
      string s=to_string(aa), ss=to_string(bb);

      int i=sz(s)-1, j=sz(ss)-1;

      while(s[i]=='0'&&i>=0){s.pop_back(); i--;}
      while(ss[j]=='0' && j>=0){ ss.erase(j,1); j--;}

      int f=0,g=0;

      for (int i=0; i<sz(s); i++){
         if(s[i]=='.') {
            i++;
            while(i<sz(s)){i++; f++;}
            break;
         }
      }
      for (int i=0; i<sz(ss); i++){
         if(ss[i]=='.') {
            i++;
            while(i<sz(ss)){i++; g++;}
            break;
         }
      }
      //cout << f << ' ' << g << endl;
      for (int i=0; i<abs(f-g); i++){
         if(f>g)ss+='0';
         else s+='0';
      }
      //cout << s << ' ' << ss << endl;


      int a=0,b=0;
      int c=1;
      for (int i=sz(s)-1; i>=0; i--){
         if(s[i]=='.')continue;
         int d=s[i]-'0';
         a+=c*d;
         c*=10;
      }

      c=1;
      for (int i=sz(ss)-1; i>=0; i--){
         if(ss[i]=='.') continue;
         int d=ss[i]-'0';
         b+=c*d;
         c*=10;
      }

      //cout << a << ' ' << b << endl;

      /*aa*=100000; bb*=100000;
      int a=aa, b=bb;
      while(a%10==0 && b%10==0){
         a/=10; b/=10;
      }*/
      if(a==b){cout << 2 << ' ' << 2 << endl; continue;}
      if(a==0 || b==0) {cout << "impossible" << endl; continue;}
      //cout << a << ' ' << b << endl;
      int x=gcd(a,b);
      //cout << x << endl;
      if(prime(a/x)&&prime(b/x)) cout << a/x << ' ' <<b/x << endl;
      else cout << "impossible" << endl;


   }



}


