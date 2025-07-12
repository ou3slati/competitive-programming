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

int l=0;
int res=0;
int n;
int t[2*100000];

int32_t main(){
   boost;
   cin>>n;

   for (int i=0; i<n; i++) cin>>t[i];

   int i=0;

   while(i<n){
      while(t[i+1]>t[i]){
         i++;
         l++;
         res=max(res,l);
      }

      if(i+1<n && t[i+1]>t[i-1]){
         int ind=i+1;
         int p=t[i-1];
         int ll=l;
         while(ind<n && t[ind]>p){p=t[ind]; ind++; ll++; res=max(res,ll);  }
      }

      if(i<n && i>1 && t[i]>t[i-2]){
         int p=t[i-2];
         while(t[i]>p){
            p=t[i];
            i++;
            l++;
            res=max(res,l);
         }
         i--;
      }
      i++;
      l=0;
   }
   cout << res << endl;

}
