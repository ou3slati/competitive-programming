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
int N;
vi st;

void update(int pos, int idx, int l, int r){
   if(l>r) return;
   if(l==r){
      st[pos]++;
      return;
   }
   int mid=(l+r)/2;
   if(idx<=mid) update(pos*2,idx,l,mid);
   else update(pos*2+1,idx,mid+1,r);

   st[pos]=st[pos*2]+st[pos*2+1];
}

int sum(int pos, int l, int r, int tl, int tr){
   if(l>r) return 0;
   if(l==tl && r==tr){
      return st[pos];
   }
   int mid=(tl+tr)/2;
   return sum(pos*2,l,min(mid,r),tl,mid)+sum(pos*2+1,max(mid+1,l),r,mid+1,tr);
}

int32_t main(){
   boost;
   cin>>N;
   st.assign(N*4+1,0);
   unordered_map<int,int> h;
   int l[N+1],r[N+1];

   int t[N+1];
   for(int i=1; i<=N; i++){
      cin>>t[i];
      if(!h.count(t[i])) h[t[i]]=0;
      l[i]=++h[t[i]];
   }
   h.clear();
   for(int i=N; i>0; i--){
      if(!h.count(t[i])) h[t[i]]=0;
      r[i]=++h[t[i]];
   }

   int ans=0;

   for(int i=N; i>0; i--){
      ans+=sum(1,1,l[i]-1,1,N);
      update(1,r[i],1,N);
   }

   cout << ans << endl;

   return 0;
}

