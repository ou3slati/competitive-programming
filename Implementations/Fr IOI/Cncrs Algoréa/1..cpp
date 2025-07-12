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

int32_t main(){
   boost;
   /*droite();
   fonce();
   droite();
   fonce();
   gauche();
   fonce();
   gauche();
   fonce();
   gauche();
   fonce();
   gauche();
   fonce();
   droite();
   fonce();
   gauche();
   fonce();*/

   /*for (int i=0; i<=15; i++){
      if(nbAuSol()==1 && nbAuSac()>=2){depose(); depose();}
      else ramasse();
      avance();
   }*/

   /*int N; cin>>N;
   int m=0,n=INF;
   int x,y;
   for (int i=0; i<N; i++){
      cin >>x>>y;
      if(x<=n && y>=m){ m=max(m,x); n=min(n,y);}
      else {cout << 0 << endl; return 0;}
   }

   cout << n-m+1 << endl;*/

   /*int N; cin >>N;
   int t[N];
   bool v[N]={false};
   for (int i=0; i<N; i++) cin>>t[i];
   int X; cin >>X;
   for (int i=0; i<X; i++){
      int x; cin >>x;
      int y=x+1;
      v[x]=true;
      while(t[y]>=t[y-1] && !v[y]){v[y]=true; y++; }

      y=x-1;
      while(t[y]>=t[y+1] && !v[y]){v[y]=true; y--; }
   }

   int res=0;
   for (int i=0; i<N; i++) if(v[i]) res++;
   cout << res << endl;*/

   int N; cin>>N;
   int t[N+1];
   for (int n=1; n<=N; n++) cin>>t[n];

   int res=0;
   int f=1,g=1,h=1,i=1,j=1;

   while(f && g && h && i &&j){
      f=0; j=0; h=0; h=0; i=0;

      for (int p=N; p>0; p--){

         if(t[p]!=0){
            int x=t[p];
            if(x==1 && !f && g&&i&&h&&j) f=p;
            if(x==2 && !g && j&&i&&h) g=p;
            if(x==3 && !h && j &&i) h=p;
            if(x==4 && !i && j) i=p;
            if(x==5 && !j) j=p;
         }

      }

      if(g&&h&&f&&i&&j) {t[g]=0; t[h]=0; t[i]=0; t[j]=0; t[f]=0;  res++; }
   }

   cout << res << endl;

}


