#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
#define int ll
typedef double db;
typedef long double ldb;

typedef pair<int,int> pi;
#define mp make_pair
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;

#define pb push_back
#define eb emplace_back
#define pf push_front

#define lb lower_bound
#define ub upper_bound

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7;
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};
#define ull unsigned ll

int mn=10*100000*100000*100000;

vector <ull> s1;
vector<ull> s2;
vpi vec2;

int  t[100];
int tt[30];
int nb=0;



void gen(int k){
   unsigned long long x=1;
   while(x<mn){s1.pb(x); x*=k;  }
   return;
}


int32_t main(){
   boost;
   int t; cin>>t;
   while(t--){
      int n,k; cin>>n>>k;
      gen(k);

      for (int i=0; i<n; i++)cin>>tt[i];


      int N=sz(s1);
      bool vis[N]={false};
      sort(tt,tt+n);

      for (int i=0; i<N; i++){
         int x=s1[i];
         if(vis[i]) continue;
         for (int j=0; j<n; j++){
            int y=tt[j];
            if(y>=x &&(y-x)%k==0){
               tt[j]-=x;
               vis[i]=true;
               break;
            }
         }
      }
      bool y=true;
      for (int i=0; i<n; i++) if(tt[i]!=0) {y=false; break;}
      if(y)cout << "YES" << endl;
      else cout << "NO" << endl;

      /*gen2();

      sort(all(s1)); sort(all(s2));

      bool y=true;
      for (int i=0; i<n; i++){
         int x=tt[i];
         auto it=find(all(s1), x);
         auto itr=find(all(s2), x);
         if(it!=s1.end()){ s1[it-s1.begin()]=-1;  }
         else if(itr!=s2.end()){
            int ind=itr-s2.begin();
            int b=vec2[ind].fi;
            int c=vec2[ind].se;
            auto itt=find(all(s1),b);
            auto ittr=find(all(s1),c);

            if(itt!=s1.end() && ittr!=s1.end()){
               int kk=itt-s1.begin();
               s1[kk]=-1;
               int kkk =ittr-s1.begin();
               s2[kkk]=-1;
            }
            else{cout << "NO" << endl; y=false; break;}
         }
         else{cout << "NO" << endl; y=false; break;}
      }
      if(y) cout << "YES" << endl;*/

   }


}


