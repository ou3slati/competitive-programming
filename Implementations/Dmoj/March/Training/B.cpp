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

/*const int MOD = 1e9+7; //1000000007
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};*/

ld x1,yo,x2,y2;
ld x3,y3,x4,y4;

bool p(){
   if((x2-x1)*(y4-y3)-(y2-yo)*(x4-x3)==0) return true;
   return false;
}

bool c(){
   if(((x3-x2)*(y4-yo)-(y3-y2)*(x4-x1))==0 && ((x4-x2)*(y3-yo)-(y4-y2)*(x3-x1))==0) return true;
   return false;
}

int32_t main(){
   boost;

   cin>>x1>>yo>>x2>>y2>>x3>>y3>>x4>>y4;
   if(c()) cout << "coincident" << endl;
   else if(p()) cout << "parallel"<< endl;
   else if(x2!=x1&&x3!=x4){
      ld a,ap,b,bp;
      a=(y2-yo)/(x2-x1);
      ap=(y4-y3)/(x4-x3);
      b=yo-a*x1; bp=y3-ap*x3;
      ld x=(bp-b)/(a-ap);
      ld y=a*x+b;
      cout << fixed << setprecision(6)<<  x << ' ' <<y << endl;
   }
   else if(x2==x1){
      ld a=(y4-y3)/(x4-x3);
      ld b=y3-a*x3;
      ld y=a*x2+b;
      cout << fixed << setprecision(6)<<  x2 << ' ' <<y<< endl;
   }
   else if(x4==x3){
      ld a=(y2-yo)/(x2-x1);
      ld b=yo-a*x1;
      ld y=a*x3+b;
      cout << fixed << setprecision(6)<<  x3 << ' ' <<y<< endl;
   }

}

