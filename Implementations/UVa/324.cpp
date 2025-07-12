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

vi vec;
int N;
void f(){
   vec[0]=1;
   for (int nb=2; nb<=N; nb++){
      string s=to_string(nb); reverse(all(s));
      int l=sz(s);

      vi m[l];

      for (int j=0;j<l; j++){
         m[j].assign(800,0);
         int x=s[j]-'0';
         int ind=0;
         for (int k=j; k<790; k++){
            m[j][k]+=(x*vec[ind])%10;
            m[j][k+1]=(x*vec[ind])/10;
            ind++;
         }
      }
      vec.assign(800,0);

      for (int i=0; i<790; i++){
         for(int j=0; j<l; j++)
            vec[i]+=m[j][i];
         vec[i+1]=vec[i]/10;
         vec[i]=vec[i]%10;
      }
   }

}

int32_t main(){
   boost;
   cin>>N;
   while(N){
      vec.assign(800,0);
      f(); reverse(all(vec));
      int j=0;
      while(vec[j]==0) j++;
      int c[10]={0};
      for (int i=j; i<sz(vec);i++) c[vec[i]]++;
      cout <<N<<"! --"<< endl;
      for (int i=0; i<10; i++){
         if(i==5) cout << endl;
         cout <<"   "<<'('<<i<<')'<<"   "<<c[i];
      }
      cout << endl;
      cin>>N;

   }

}

