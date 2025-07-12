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

set<str> s,ss;
str med;
int n;

void add(){
   bitset<60> bs(med);
   int i;
   do{
      i=0;
      while(bs[i]==1){
         bs[i]=0;
         i++;
      }
      bs[i]=1;
      med=bs.to_string();
   }while(ss.count(med)==1);
}

void subtract(){
   bitset<60> bs(med);
   int i;
   do{
      i=0;
      while(bs[i]==0){
         bs[i]=1;
         i++;
      }
      bs[i]=0;
      med=bs.to_string();
   }while(ss.count(med)==1);
}

int32_t main(){
   boost;
   int TC; cin>>TC;
   while(TC--){

      int N,M; cin>>N>>M;
      s.clear(); ss.clear();

      str st;
      for(int i=0; i<60-M; i++) st+='0';
      for(int i=0; i<N; i++){
         str ss=st;
         str m; cin>>m;
         ss+=m;
         s.insert(ss);
      }

      n=(int)(pow(2,M)+0.5);
      int mid=(n-1)/2;

      bitset<60>bs(mid); med=bs.to_string();
      //cout << med << endl;

      for(auto x: s){
         ss.insert(x);
         if(n%2==0 && x<=med) add();
         else if(n%2==1&& x>=med) subtract();
         //cout << med << endl;
         n--;
      }

      reverse(all(med));
      med.resize(M);
      reverse(all(med));
      cout << med<< endl;
      //cout << endl;
   }
   return 0;
}


/*
5
4 3
000
111
100
011
*/
