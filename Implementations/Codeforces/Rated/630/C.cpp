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
   int TC; cin>>TC;
   while(TC--){
      int a,b,c,d; cin>>a>>b>>c>>d;
      int x,y, x1,y1, x2, y2; cin>>x>>y>>x1>>y1>>x2>>y2;
      //if((x2-x<b-a)||(x-x1<a-b) ||(y2-y<d-c)||(y-y1<c-d))
        // cout << "No"<< endl;
      //else if((x2==x && b>0)||(x1==x && a>0) || (y2==y&&d>0) ||(y1==y && c>0))
        // cout << "No"<< endl;
      if((b>=a&&abs(x2-x)<abs(b-a))||(a>=b&&abs(x-x1)<abs(b-a))||(d>=c&&y2-y<abs(d-c))||(c>=d&&y-y1<abs(d-c)))
        cout << "No"<< endl;

      else if((x2==x1&&(a>0||b>0)) || (y2==y1&&(c>0||d>0)))cout << "No"<< endl;
      else cout << "Yes" << endl;
   }

}

