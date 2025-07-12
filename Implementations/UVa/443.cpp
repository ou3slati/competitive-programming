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

   set <int> s;
   for (int i=0; i<=31; i++) for (int j=0; j<=19; j++) for (int k=0; k<=13; k++) for (int l=0;l<=11; l++){
      string a=to_string((int)pow(2,i)),b=to_string((int)pow(3,j)),c=to_string((int)pow(5,k)),d=to_string((int)pow(7,l));
      if(sz(a)+sz(b)+sz(c)+sz(d)>14)break;
      s.insert(pow(2,i)*pow(3,j)*pow(5,k)*pow(7,l));
   }

   vi vec;
   for (auto x:s) vec.pb(x);

   int N; cin>>N;
   while(N){
      int x=vec[N-1];
      string suf[10]={"st","nd","rd","th","th","th","th","th","th","th"};
      int ind=((N%10)-1+10)%10;
      if(N%10==1 && (N/10)%10==1) ind=3;
      if(N%10==2 && (N/10)%10==1) ind=3;
      if(N%10==3 && (N/10)%10==1) ind=3;
      cout << "The " <<N<<suf[ind]<<" humble number is " << x<<'.'<<endl;



      cin>>N;
   }
}
