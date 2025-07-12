#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

typedef string str;
typedef long long ll;
//#define int ll
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

int N,M,Q;

void solve1(){
   vpi vec[M+1];
   int st[N+1];
   for(int i=1; i<=N; i++)cin>>st[i];
   for(int i=1; i<=N; i++){
      int x; cin>>x;
      vec[st[i]].pb({i,x});
   }
   for(int i=0; i<Q; i++){
      int op; cin>>op;
      if(op==1){
         int l,r; cin>>l>>r;
         int ans=0;
         for(int j=1; j<=M; j++) for(auto x: vec[j]) if(x.fi>=l && x.fi<=r)
            ans+=x.se;
         cout << ans << endl;
      }

      else{
         int x; cin>>x;
         int prev=vec[x][sz(vec[x])-1].se;
         for(int i=0; i<sz(vec[x]); i++){
            int memo=vec[x][i].se;
            vec[x][i].se=prev;
            prev=memo;
         }
      }
   }
}

void solve2(){
   int pref[M+1]={0};
   vi pref2[M+1];
   for(int i=1; i<=M; i++) pref2[i].pb(0);

   int st[N];
   for(int i=0; i<N; i++) cin>>st[i];

   int nb[M+1]={0};
   int nb2[M+1]={0};

   for(int i=0; i<N; i++){
      int x; cin>>x;
      pref[st[i]]+=x;
      nb[st[i]]++;
      pref2[st[i]].pb(x);
   }


   for(int i=1; i<=M; i++) nb2[i]=nb[i]+nb2[i-1];

   for(int i=1; i<=M; i++) pref[i]+=pref[i-1];

   for(int i=1; i<=M; i++){
      vi vec;
      for(int j=1; j<sz(pref2[i]); j++) vec.pb(pref2[i][j]);
      for(auto x: vec) pref2[i].pb(x);
   }

   for(int i=1; i<=M; i++){
      for(int j=1; j<sz(pref2[i]); j++) pref2[i][j]+=pref2[i][j-1];
   }

   int p[M+1];
   for(int i=1; i<=M; i++) p[i]=1;

   for(int q=0; q<Q; q++){
      int op; cin>>op;
      if(op==2){
         int x; cin>>x;
         p[x]--;
         if(p[x]==0) p[x]=nb[x];
      }
      else{
         int ll,rr;
         cin>>ll>>rr;

         int l,r;
         l=st[ll-1]  ;r=st[rr-1];

         int ans=pref[r]-pref[l-1];
         ll-=nb2[l-1]; rr-=nb2[r-1];

         ans-=pref2[l][p[l]+ll-2]-pref2[l][p[l]-1];
         ans-=pref2[r][p[r]+nb[r]-1]-pref2[r][p[r]+rr-1];

         cout << ans << endl;
      }
   }
}


int main(){
   boost;
   cin>>N>>M>>Q;

   if(N<=1000 && Q<=1000){
      solve1();
   }
   else{
      solve2();
   }

   return 0;
}


