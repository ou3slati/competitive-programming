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
const int MXN=(1<<17);
vpi st(MXN*4+10);
int t[MXN+10];

void build(int pos, int l, int r){
   //cout << pos << endl;
   if(l>r) return;
   if(l==r){
      st[pos]={t[l],1};
      return;
   }

   int mid=(l+r)/2;
   build(pos*2,l,mid);
   build(pos*2+1,mid+1,r);

   if(st[pos*2].se%2==1) st[pos].fi=(st[pos*2].fi|st[pos*2+1].fi);
   else st[pos].fi=(st[pos*2].fi^st[pos*2+1].fi);
   st[pos].se=st[pos*2].se+1;
}

void update(int pos, int l,int r,int idx, int v){
   if(l>r) return;
   if(l==r){
      st[pos].fi=v;
      return;
   }

   int mid=(l+r)/2;
   if(idx<=mid) update(pos*2,l,mid,idx,v);
   else update(pos*2+1,mid+1,r,idx,v);

   if(st[pos*2].se%2==1) st[pos].fi=(st[pos*2].fi|st[pos*2+1].fi);
   else st[pos].fi=(st[pos*2].fi^st[pos*2+1].fi);
}

int32_t main(){
   boost;
   int n,Q; cin>>n>>Q;
   N=(1<<n);
   for(int i=1; i<=N;i++) cin>>t[i];

   build(1,1,N);

   for(int q=0; q<Q; q++){
      int idx, v; cin>>idx>>v;
      update(1,1,N,idx,v);
      cout << st[1].fi << endl;
   }


   return 0;
}

/*
2 4
1 6 3 5
*/
