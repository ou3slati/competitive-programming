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
      int N; cin>>N;
      int t[N];
      for (int i=0; i<N; i++){
         cin>>t[i];
      }

      int a=1;
      for (int i=0; i<N-1; i++){
         if(t[i]!=t[i+1]){
            a=0;
         }
      }
      if(a){
         cout << 1 << endl;
         for (int i=0; i<N;i++) cout << 1 << ' ';
         cout << endl;
         continue;
      }
      if(N==2){
         if(t[0]==t[1]) cout << 1 << endl << 1 <<' ' <<1<< endl;
         else  cout << 2<< endl << 1 <<' ' <<2<< endl;
      }
      /*else if(b){
         cout << 2 << endl;
         for (int i=0; i<N;i++){
            if(t[i]==1) cout << 1 << ' ';
            else cout << 2 << ' ';
            cout << endl;
         }
      }
      else if(c){

      }*/

      if(N%2==0) {
         cout << 2 << endl;
         for (int i=0; i<N;i++){if(i%2==0) cout << 1 << ' '; else cout << 2 << ' '; }
         cout << endl;
      }
      else if(N%2==1){
         if(t[0]==t[N-1]){
            cout << 2 << endl;
            for (int i=0; i<N;i++){if(i%2==0) cout << 1 << ' '; else cout << 2 << ' '; }
            cout << endl;
         }
         else if(t[N-1]==t[N-2]){
            cout << 2 << endl;
            for (int i=0; i<N-1;i++){if(i%2==0) cout << 1 << ' '; else cout << 2 << ' '; }
            cout << 2 << ' ';
            cout << endl;
         }
         else if(t[0]==t[1]){
            cout << 2 << endl;
            cout <<2 << ' ';
            for (int i=1; i<N;i++){if(i%2==0) cout << 1 << ' '; else cout << 2 << ' '; }

            cout << endl;
         }
         else if(t[N-2]==t[N-3]){
            cout << 2 << endl;
            for (int i=0; i<N-2;i++){if(i%2==0) cout << 1 << ' '; else cout << 2 << ' '; }
            cout << 1 << ' '<<2;
            cout << endl;
         }
         else{

            cout << 3 << endl;
            for (int i=0; i<N-1;i++){if(i%2==0) cout << 1 << ' '; else cout << 2 << ' '; }
            cout << 3;
            cout << endl;

         }
      }


   }

}

