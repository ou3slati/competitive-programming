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

const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

int32_t main(){
   boost;

   int N; cin>>N;
   int t[N];
   for (int i=0; i<N; i++) cin>>t[i];
   map <int,int> mp;
   int s=0;
   int nb=0;
   for (int i=0; i<N; i++){
      s+=t[i];
      if(s==0){nb++; continue;}
      if(mp.count(s)==0) mp[s]=1;
      else{
         nb+=mp[s];
         mp[s]++;
      }
   }
   int res=((1+N)*N)/2-nb;
   cout << res  << endl;

}

