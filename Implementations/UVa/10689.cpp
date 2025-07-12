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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int power(int x){
   int res=1;
   for(int i=0; i<x; i++) res*=10;
   return res;
}

int32_t main(){
   boost;

   int TC; cin>>TC;
   while(TC--){
      int a,b,n,m; cin>>a>>b>>n>>m;
      map <int,int> mp; mp[1]=60; mp[2]=300; mp[3]=1500; mp[4]=15000;
      int x=power(m);
      int idx=n%mp[m];
      //cout <<idx << endl;

      if(idx==0) cout << a%x << endl;
      else if(idx==1) cout << b%x<< endl;
      else{
         int f=a, s=b;
         for (int i=2; i<=idx; i++){
            swap(f,s);
            s+=f;
            //cout << f << ' ' << s << endl;
            f=f%x; s=s%x;
         }
         cout << s << endl;
      }

   }

}

