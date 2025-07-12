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

int32_t main(){
   boost;
   int a,b,c,d; cin>>a>>b>>c>>d;
   bool valid=true;
   if(!(c<=a||(c-1==a && b==0 && d==0))) valid=false;
   if(!valid){cout << "invalid"<< endl; return 0;}
   if(c-1==a){cout <<"C"<<a+c << endl; return 0;}

   int ap=a-c;
   int nb=4;

   for(int i=0; i<ap; i++){nb-=1; nb+=3;}
   //for(int i=0; i<b; i++){nb-=2; nb+=2;}
   if(nb==d) cout << "C"<<a+b+c+1 << "H" << d << endl;
   else cout << "invalid" << endl;
   //cout << nb << endl;

   return 0;
}

