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

int N;
vi ST,ST2;

void update(int st, int idx, int l, int r, int pos, int v){
   //cout << pos << endl;
   if(l>r) return;
   if(l==r){
      if(st==1) ST[pos]+=v;
      else ST2[pos]+=v;
      return;
   }

   int mid=(l+r)/2;
   if(idx<=mid) update(st,idx,l,mid,pos*2,v);
   else update(st,idx,mid+1,r,pos*2+1,v);

   ST[pos]=ST[pos*2]+ST[pos*2+1];
   ST2[pos]=ST2[pos*2]+ST2[pos*2+1];
}

int getSum(int st, int l, int r, int lt, int rt, int pos){
   //cout << pos << endl;
   if(l>r) return 0;
   if(r==rt && l==lt){
      if(st==1) return ST[pos];
      return ST2[pos];
   }

   int mid=(lt+rt)/2;
   return getSum(st,l,min(mid,r),lt,mid,pos*2)+getSum(st,max(l,mid+1),r,mid+1,rt,pos*2+1);

}

int32_t main(){
   boost;
   cin>>N;
   ST.assign(N*4+1,0); ST2.assign(N*4+1,0);

   int t[N+1]; vpi vec;
   for(int i=1; i<=N; i++){
      int x; cin>>x;
      vec.pb({x,i});
   }
   sort(all(vec));
   int cnt=1;
   for(int i=0;i<N; i++){
      int x=vec[i].fi;
      while(i<N && vec[i].fi==x){
         t[vec[i].se]=cnt;
         i++;
      }
      i--;
      cnt++;
   }

   //for(auto x: t) cout << x << ' ';

   for(int i=1; i<=N; i++){
      update(2,t[i],1,N,1,1);
   }
   //for(auto x: ST2) cout << x << ' ';



   int ans=0;
   for(int i=1; i<=N; i++){
      ans+=getSum(2,1,t[i]-1,1,N,1)*(getSum(1,1,N,1,N,1)-getSum(1,1,t[i],1,N,1));
      update(1,t[i],1,N,1,1);
      update(2,t[i],1,N,1,-1);
   }
   cout << ans << endl;

   return 0;
}

