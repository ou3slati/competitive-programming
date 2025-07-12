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

const int MXN=2e5+1;
int N;
vi ST(MXN*4),lazy(MXN*4,0);
int t[MXN];

void push(int pos){
   ST[pos*2]+=lazy[pos];
   lazy[pos*2]+=lazy[pos];
   ST[pos*2+1]+=lazy[pos];
   lazy[pos*2+1]+=lazy[pos];
   lazy[pos]=0;
}

void update(int pos, int l, int r, int tl, int tr, int v){
   if(l>r) return;

   if(r==tr && l==tl){
      lazy[pos]+=v;
      ST[pos]+=v;
      return;
   }

   push(pos);
   int mid=(tl+tr)/2;
   update(pos*2,l,min(r,mid),tl,mid,v);
   update(pos*2+1,max(mid+1,l),r,mid+1,tr,v);
   ST[pos]=min(ST[pos*2],ST[pos*2+1]);
}


int query(int pos, int l, int r, int tl, int tr){
   if(l>r) return INF;

   if(l==tl && r==tr) return ST[pos];

   push(pos);
   int mid=(tl+tr)/2;
   return min(query(pos*2,l,min(mid,r),tl,mid),query(pos*2+1,max(l,mid+1),r,mid+1,tr));
}


void build(int pos, int l, int r){
   if(l==r){
      ST[pos]=t[l];
      return;
   }
   int mid=(l+r)/2;
   build(pos*2,l,mid);
   build(pos*2+1,mid+1,r);
   ST[pos]=min(ST[pos*2],ST[pos*2+1]);
}

int32_t main(){
   boost;
   cin>>N;
   for(int i=1; i<=N; i++) cin>>t[i];
   build(1,1,N);
   /*for(int i=1; i<=4*N; i++) cout << ST[i] << ' ';
   cout << endl;*/

   int Q; cin>>Q; cin.ignore();
   string s;
   while(Q--){
      getline(cin,s);
      int l=0, r=0, v=0;
      int i=0;
      while(s[i]!=' '){
         l*=10; l+=s[i]-'0';
         i++;
      } i++;
      while(i<sz(s) && s[i]!=' '){
         r*=10; r+=s[i]-'0';
         i++;
      }
      l++; r++;

      if(i==sz(s)){
         if(l>r){
            //cout << query(1,l,N,1,N) << ' ' << query(1,1,r,1,N) << endl;
            cout << min(query(1,l,N,1,N),query(1,1,r,1,N)) << endl;
         }
         else cout<< query(1,l,r,1,N) << endl;
         //cout << endl;
         continue;
      }

      i++; int w=1;
      if(s[i]=='-'){w=-1; i++;}
      while(i<sz(s)){
         v*=10; v+=s[i]-'0';
         i++;
      }
      v*=w;

      if(l>r){update(1,l,N,1,N,v); update(1,1,r,1,N,v);}
      else update(1,l,r,1,N,v);
   }


   return 0;
}

