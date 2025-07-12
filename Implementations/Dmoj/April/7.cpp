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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
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

int N,Q,W;
vi v(2008),c(2008);
vi vec;

int old(int i){
   return v[vec[i-1]]*c[vec[i-1]] +c[vec[i]]*(v[vec[i]]+v[vec[i-1]]);
}

int neww(int i){
   i--;
   return v[vec[i]]*c[vec[i]] +c[vec[i]]*(v[vec[i]]+v[vec[i+1]]);
}

int32_t main(){
   boost;
   cin>>N>>Q>>W;
   for(int i=0; i<N; i++) cin>>v[i]>>c[i];

   vec.pb(0);
   for(int i=1; i<N; i++){
      vec.pb(i);
      int j;
      while(1){
         bool y=false;
         j=i;
         while(j>0&&neww(j)-old(j)>=W){swap(vec[j],vec[j-1]); j--; y=true;}
         if(!y) break;
      }
      for(int i=0; i<sz(vec);i++)cout << vec[i]<< ' '; cout << endl;
      for(int i=0; i<sz(vec);i++)cout << v[vec[i]]<<'/'<<c[vec[i]] << ' ';
      cout << endl << endl;
   }

   while(Q--){
      string s; cin>>s;
      if(s=="K-TH"){
         int x;cin>>x;
         int idx=vec[x-1];
         cout << v[idx] << ' ' << c[idx] << endl;
      }
      if(s=="INSERT"){
         cin>>v[N]>>c[N];
         vec.pb(N);
         int last=N;
         while(1){
            bool done=false;
            //int beg=last;
            for(int i=last; i>=0; i--){
               bool y=false;
               int j=i;
               while(j>0&&neww(j)-old(j)>=W){swap(vec[j],vec[j-1]); j--; y=true;}
               if(y){last=i; done=true; break;}
            }
            if(!done) break;
         }
         for(int i=0; i<sz(vec);i++)cout << vec[i]<< ' ';
         cout << endl;
         for(int i=0; i<sz(vec);i++)cout << v[vec[i]]<<'/'<<c[vec[i]] << ' ';
      cout << endl << endl;
         N++;
      }

   }




   return 0;
}

