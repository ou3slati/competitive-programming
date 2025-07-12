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
//#define mp make_pair
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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

const int MXN=300009;
int N;
int t[MXN];

bool sub1(){
   for (int i=1; i<N; i++) if(t[i]<t[i-1]) return false;
   return true;
}

bool sub2(){
   for (int i=0; i<N;i++) if(t[i]!=0&&t[i]!=1) return false;
   return true;
}

bool sub3(){
   for (int i=0; i<N; i++) if(t[i]>99) return false;
   return true;
}

int32_t main(){
   boost;

   cin>>N;
   for(int i=0;  i<N; i++) cin>>t[i];

   if(sub1()) cout <<0 << endl;
   else if(sub2()){
      int p[N]={0};
      p[0]=t[0];
      for (int i=1; i<N; i++) p[i]=t[i]+p[i-1];
      int res=0;
      for (int i=1; i<N; i++){
         if(t[i]==1) res+=(i-p[i-1])*(N-i-1-p[N-1]+p[i]);
      }
      cout << res << endl;
   }
   else if(sub3()){
      /*unordered_map <pi,int> mp;
      for (int i=0; i<100; i++) mp[{i,0}]=0;
      mp[{t[0],0}]++;
      for (int i=1; i<N; i++){
         mp[{t[i],i}]=mp[{t[i],i-1}]+1;;
         for (int j=0; j<=99; j++) if(j!=t[i]) mp[{j,i}]=mp[{j,i-1}];
      }
      int res=0;
      for (int i=1; i<N-1; i++){
         int x=t[i];
         int l=0,r=0;
         for (int j=0; j<x; j++){
            l+=mp[{j,i-1}]; r+=mp[{j,N-1}]-mp[{j,i}];
         }
         res+=l*r;
      }
      cout << res << endl;*/
      int h[100][N];
      memset(h,0,sizeof(h));
      for (int i=0; i<N; i++) h[t[i]][i]=1;
      for (int i=0; i<100; i++) for (int j=1; j<N; j++) h[i][j]+=h[i][j-1];
      int res=0;
      for (int i=1; i<N-1; i++){
         int x=t[i];
         int l=0,r=0;
         for (int j=0; j<x;j++){
            l+=h[j][i-1]; r+=h[j][N-1]-h[j][i];
         }
         res+=l*r;
      }
      cout << res << endl;
   }
   else if(N<=10000){
      int res=0;
      for (int i=1; i<N-1; i++){
         int l=0, r=0;
         for (int j=0; j<i; j++) if(t[j]<t[i]) l++;
         for (int j=i+1; j<N; j++) if(t[j]<t[i]) r++;
         res+=l*r;
      }
      cout << res << endl;
   }
   else{
      /*set <int> r,l;
      r.insert(t[0]);
      for (int i=2; i<N;i++) l.insert(t[i]);
      for (int i=1; i<N; i++){
         int x=t[i];
         auto it=l.lower_bound(x);
         auto itr=r.lower_bound(x);
      }*/

   }
   return 0;
}

// 0 2 0 99 10 6
