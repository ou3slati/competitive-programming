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

const int MXN=1e6+10;
vi BIT(MXN,0),BIT2(MXN,0);
int N;

int LSB(int i){return i&-i;}

void update (int ft, int idx, int v){
   if(ft==1){
      while(idx<MXN){
         BIT[idx]+=v;
         idx+=LSB(idx);
      }
   }
   else if(ft==2){
      while(idx<MXN){
         BIT2[idx]+=v;
         idx+=LSB(idx);
      }
   }
}

int sum(int ft, int idx){
   int ans=0;
   if(ft==1){
      while(idx>0){
         ans+=BIT[idx];
         idx-=LSB(idx);
      }
   }
   else if(ft==2){
      while(idx>0){
         ans+=BIT2[idx];
         idx-=LSB(idx);
      }
   }
   return ans;
}

int getSum(int i){
   return sum(1,i)*i-sum(2,i);
}

void add(int l, int r, int x){
   update(1,l,x);
   update(1,r+1,-x);
   update(2,l,(l-1)*x);
   update(2,r+1,-(r*x));
}

int32_t main(){
   boost;
   int a,b,c,d; cin>>a>>b>>c>>d;

	for(int i=a; i<=b; i++) add(i+b,i+c,1);

   int ans=0;
   for(int i=c; i <=d; i++) ans+=getSum(b+c)-getSum(i);
   cout << ans << endl;

   return 0;
}

