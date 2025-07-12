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

const int MXN=1000*1000+1;
int sv[MXN];
int s[MXN];
int N;

void sieve(){
   for (int i=0; i<MXN; i++) sv[i]=-2;

   for (int i=2; i<MXN; i++) if(sv[i]==-2){
      for (int j=i; j<MXN; j+=i) if(sv[j]!=0){
         if(sv[j]==-2) sv[j]=0;
         sv[j]++;
         if((j/i)%i==0) sv[j]=0;
      }
   }

   for (int i=1; i<MXN; i++){
      if(sv[i]!=0&&sv[i]%2==0) sv[i]=1;
      else if(sv[i]!=0&&sv[i]%2==1) sv[i]=-1;
   }
   s[1]=1;
   for (int i=2; i<MXN; i++) s[i]=s[i-1]+sv[i];
}

int32_t main(){
   boost;
   sieve();
   cin >>N;
   while(N){
      string a=to_string(N),b=to_string(sv[N]),c=to_string(s[N]);
      for (int i=0;i<8-sz(a); i++) cout << ' ';
      cout << N;
      for (int i=0;i<8-sz(b); i++) cout << ' ';
      cout << b;
      for (int i=0;i<8-sz(c); i++) cout << ' ';
      cout << c;
      cout << endl;
      cin>>N;
   }

}

