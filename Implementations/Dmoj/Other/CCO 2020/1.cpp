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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=1e6+15;

vi bit(MXN,0),bit2(MXN,0);


int lsb(int i){return i&(-i);}

int getSum(int i){
   int ans=0;
   while(i>0){
      ans+=bit[i];
      i-=lsb(i);}
   return ans;
}
int getSum2(int i){
   int ans=0;
   while(i>0){
      ans+=bit2[i];
      i-=lsb(i);}
   return ans;
}


void change(int i, int v){
   while(i<MXN){
      bit[i]+=v;
      i+=lsb(i);}}
void change2(int i, int v){
   while(i<MXN){
      bit2[i]+=v;
      i+=lsb(i);}
}

void update(int l, int r){
   change(l,1);
   change(r+1,-1);
   //cout << l << ' ' << r << endl;
}
void update2(int l, int r){
   change2(l,1);
   change2(r+1,-1);
   //cout << l << ' ' << r << endl;
}

int N,l,r,Y;

int solve(int x, int v, int h, int st){
   ld a=(ld)v/h; ld b=-1*(ld)v/h*(ld)x;

   ld sol=(ld)(Y-b)/a;
   if(st==0) return floor(sol-0.0000001);
   return ceil(sol+0.0000001);
}

int32_t main(){
   boost;
	cin>>N>>l>>r>>Y;
	for(int i=0; i<N; i++){
      int x,v,h; cin>>x>>v>>h;

      int xr=solve(x,v,h,0),xl=solve(x,-v,h,1);
      //if(xr<xl) swap(xr,xl);
      //cout << xl << ' ' << xr << endl;

      if(xl<=0 && xr<=0){
         update2(abs(xr)+1,abs(xl)+1);
      }
      else if(xl<=0){
         update2(1,abs(xl)+1);
         update(1,xr);
      }
      else{
         update(xl,xr);
      }
      //cout << getSum(3) << endl;
	}

	vi res(N+5,0);
	for(int i=l; i<=r; i++){
      int x;
      if(i<=0) x=getSum2(abs(i)+1);
      else x=getSum(i);
      res[x]++;
	}
	for(int i=1; i<=N; i++) res[i]+=res[i-1];
	for(int i=0; i<=N; i++) cout << res[i] << endl;

   return 0;
}

