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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;
   int N,S,K; cin>>N>>S>>K;
   int d[N]; d[0]=0;
   for (int i=1; i<N; i++) cin>>d[i];
   int v[N];
   for (int i=0; i<N; i++) cin>>v[i];

	int ires=0;
	int mx=0;
	/*for (int i=0; i<N; i++){
      int l=i,r=i;
      int dl=0,dr=0;
      while(l>0 && dl+d[l]<=K){
         dl+=d[l];
         l--;
      }

      while(r<N-1 && dr+d[r+1]<=K){
         dr+=d[r+1];
         r++;
      }
      int s=0;
      for (int idx=l; idx<=r; idx++) s+=v[idx];
      if(s>mx){
         mx=s;
         ires=i+1;
      }
	}*/

	/*int s[N+1]; s[0]=0;
	for (int i=1; i<=N; i++) s[i]=v[i-1]+s[i-1];

	for (int i=1; i<=N; i++){
      int x=s[min(i+K,N)]-s[max((ll)0,i-K)-1];
      if(x>mx){
         mx=x;
         ires=i;
      }
	}*/

	if(S>=N){
      cout << N << endl;
      for (int i=1; i=N; i++){
         cout << i; if(i!=N) cout << ' ';
      }
      cout << endl;
      return 0;
	}
	else{
      int mx,s=0;
      int l=0,r=S-1;
      for (int i=0; i<S; i++) s+=v[i];
      mx=s;
      for (int i=S; i<N; i++){
         s+=v[i]; s-=v[i-S];
         if(s>mx){
            mx=s;
            r=i; l=i-S+1;
         }
      }
      cout << S << endl;
      for (int i=l; i<=r; i++) cout << i+1 << ' ';
      cout << endl;
	}

	/*cout << 1 << endl;
   cout << ires <<endl;*/

   return 0;
}

