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

const int MXN=1e5+5;
int N,Q;
int st[26][4*MXN];
bool marked[26][4*MXN];

void push(int t,int pos){
   if(marked[t][pos]){
      st[t][pos*2]=st[t][pos*2+1]=st[pos];
      marked[t][pos*2]=marked[t][pos*2+1]=true;
      marked[t][pos]=false;
   }
}

void update(int t, int pos, int l,int r, int tl, int tr, int v){
   if(l>r) return;
   if(r==tr && l==tl){
      st[t][pos]=v;
      marked[t][pos]=true;
      return;
   }
   push(t,pos);
   int mid=(tl+tr)/2;
   update(t, pos*2, l, min(mid,r), tl, mid, v);
   update(t, pos*2+1, max(l,mid+1), r, mid+1, tr, v);
}

int getSum(int t, int pos, int l, int r, int tl, int tr){

   if(l==tl && r==tr){

   }
}

void query(int l, int r, int op){
   int t[26];
   for(int i=0; i<26; i++) t[i]=getSum(i, );
}

int32_t main(){
   boost;
   memset(st,0,sizeof(st)); memset(marked,1,sizeof(marked));
   cin>>N>>Q;
   for(int i=0; i<N; i++){
      char c; cin>>c;
      update(c-'A',1,i,i,0,N-1,1);
   }
   while(Q--){
      int l,r,k; cin>>l>>r>>k;
      query(l,r,k);
   }


   return 0;
}

