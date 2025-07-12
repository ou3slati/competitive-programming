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
int BIT[MXN]= {0};
int N;

int LSB(int i){return i&-i;}

void update(int idx, int v){
   while(idx<=N){
      BIT[idx]+=v;
      idx+=LSB(idx);
   }
}

int getSum(int i){
   int ans=0;
   while(i>0){
      ans+=BIT[i];
      i-=LSB(i);
   }
   return ans;
}

int solve(int x){
   int l=1,r=N;
   while(l<r){
      int mid=(l+r)/2;
      if(getSum(mid)>=x) r=mid;
      else l=mid+1;
   }
   return l;
}

int32_t main(){
   boost;
   cin>>N;
   int Q; cin>>Q;
   for(int i=0; i<N; i++){
      int x; cin>>x;
      update(x,1);
   }
   for(int i=0; i<Q; i++){
      int x; cin>>x;
      if(x>0) update(x,1);
      else update(solve(-x),-1);
   }

   if(getSum(N)==0){cout << 0 << endl; return 0;}
   //for(int i=1; i<=N; i++) if(getSum(i)-getSum(i-1)>0){cout << i<< endl; break;}
   cout << solve(1) << endl;

   return 0;
}

