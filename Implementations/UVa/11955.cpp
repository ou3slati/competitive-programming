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

int pascal[51][51]={0};
void solve(){
   for (int i=0; i<=50; i++){
      pascal[i][0]=1;  pascal[i][i]=1;
      for (int j=1; j<i; j++){
         pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
      }
   }
}

int32_t main(){
   boost;
   solve();
   int TC; cin>>TC;
   int nb=0;
   while(TC--){
      string s; cin>>s;
      //cout << s << endl;
      string a,b;
      int i=1;
      while(s[i]>='a'&&s[i]<='z'){
         a+=s[i];
         i++;
      }
      i++;
      while(s[i]>='a'&&s[i]<='z'){
         b+=s[i];
         i++;
      }
      i+=2;
      int p=s[i]-'0'; if(i+1<sz(s)){p*=10; p+=s[i+1]-'0';}
      //cout << a << ' ' << b << ' '<<p << endl;

      cout <<"Case "<<++nb<<": ";
      int pa=p,pb=0;
      for (int i=0; i<=p; i++){
         if(pascal[p][i]>1) cout << pascal[p][i]<<'*';
         if(pa!=0)cout << a; if(pa>1)cout << '^'<<pa;
         if(pa!=0&&pb!=0) cout<<'*';
         if(pb!=0) cout << b; if(pb>1)cout << '^'<<pb;
         if(i!=p) cout <<'+';
         pa--; pb++;
      }

      cout << endl;
   }

}

