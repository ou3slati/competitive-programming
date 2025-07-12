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

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0};

string s;

int solve(int idx){
   int n1=0,n2=0;
   int i=idx-1, j=idx+1;

   while(i>=0&&j<sz(s)){
      if(s[i]==s[j]){
         i--;
         j++;
      }
      else{
         if(j<sz(s)-1 && s[j+1]==s[i]){
            j++;
            n1++;
         }
         else if(i>0 && s[i-1]==s[j]){
            i--;
            n1++;
         }
         else{
            n1+=2;
            i--; j++;
         }
      }
   }


   if(i>=0) n1+=i+1;
   else if(j<sz(s)) n1+=sz(s)-j;

   if(idx==0) return n1;
   i=idx-1,j=idx;
   while(i>=0&&j<sz(s)){
      if(s[i]==s[j]){
         i--;
         j++;
      }
      else{
         if(j<sz(s)-1 && s[j+1]==s[i]){
            j++;
            n2++;
         }
         else if(i>0 && s[i-1]==s[j]){
            i--;
            n2++;
         }
         else{
            n2+=2;
            i--; j++;
         }
      }
    }
    if(i>=0) n2+=i+1;
    else if(j<sz(s)) n2+=sz(s)-j;



   return min(n1,n2);
}

int32_t main(){
   boost;
   int N; cin>>N;
   cin>>s;
   int res=sz(s);
   //cout << sz(s) << endl;
   for (int i=0; i<sz(s); i++) res=min(res,solve(i));
   cout << res << endl;
}

//Z9ezApy6vZ0dCshvPGmlj9ibBzeftt4RreE8vbItx0UIymjUGW6jpElwDbQ2F
