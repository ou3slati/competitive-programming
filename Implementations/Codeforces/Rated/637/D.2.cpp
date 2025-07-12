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

const int MXN=2100;

int N,K;
vpi vec[MXN];
string t[MXN];
map <int,string> mp;
int memo[MXN][MXN];

int ans[MXN];

bool can(int i, int k){
   if(k<0) return false;
   if(i==N && k==0) return true;
   if(i==N) return false;

   if(memo[i][k]!=-1){if(memo[i][k]==1) return true; return false;}
   bool yes=false;
   for (int j=0; j<sz(vec[i]); j++) if(can(i+1,k-vec[i][j].se)){
      yes=true;
      break;
   }
   if(yes) memo[i][k]=1;
   else memo[i][k]=0;
   return yes;
}



void convert(int idx){
   string s=t[idx];
   for (int i=0; i<10;i++){
      string ss=mp[i];
      bool no=false;
      for (int j=0; j<7; j++) if(s[j]=='1' && ss[j]=='0'){
         no=true;
         break;
      }
      if(no) continue;
      int cost=0;
      for (int j=0; j<7; j++) if(ss[j]=='1' && s[j]=='0')
         cost++;
      vec[idx].pb({i,cost});
   }
}

//"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"

int32_t main(){
   boost;
   memset(memo,-1,sizeof(memo));
   mp[0]="1110111";mp[1]="0010010";mp[2]="1011101";mp[3]="1011011";mp[4]="0111010";
   mp[5]="1101011";mp[6]="1101111";mp[7]="1010010";mp[8]="1111111";mp[9]="1111011";

   cin>>N>>K;
   for (int i=0; i<N;i++){
      cin>>t[i];
      convert(i);
   }
   for (int i=0; i<N;i++) sort(vec[i].rbegin(), vec[i].rend());

	bool yes=false;
   for (int i=0; i<sz(vec[0]); i++)
      if(can(1,K-vec[0][i].se)){
         ans[0]=vec[0][i].fi;
         K-=vec[0][i].se;
         yes=true; break;
      }

   if(!yes){cout << -1<< endl; return 0;}

   for (int i=1; i<N;i++){
      for (int j=0; j<sz(vec[i]); j++) if(can(i+1,K-vec[i][j].se)){
         ans[i]=vec[i][j].fi;
         K-=vec[i][j].se;
         break;
      }
   }

   for (int i=0; i<N;i++) cout << ans[i];
   cout << endl;

   return 0;
}

