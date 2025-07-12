//Never stop trying
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.order_of_key(), *s.find_by_order()

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
#define rall(x) rbegin(x), rend(x)
#define endl "\n"

const int MOD = 1e9+7; //998244353
const ll INF = 1e18;
const int nx[4]={0,0,1,-1}, ny[4]={1,-1,0,0}; //right left down up

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        // Calculate carry for next step
        carry = sum/10;
    }

    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

int32_t main(){
   boost;
   str s; cin>>s;
   int N=sz(s);
   if(sz(s)==1){
      for(int i=1; i<=s[0]-'0'; i++) cout << i; return 0;
   }
   /*if(N=="10"){
      cout <<10; for(int i=2; i<=9; i++) cout << i; return 0;
   }
   if(N=="11"){
      cout <<10; for(int i=2; i<=9; i++) cout << i; cout << 1;return 0;
   }*/

   str ss="1";
   str res;
   while(1){
      int idx=0,idxx=0;
      for(int j=0; j<sz(res); j++){
         char x=res[j];
         if(x==ss[idx]){idx++; idxx=j+1;}
         if(idx>=sz(ss)) break;
      }
      for(int i=idx; i<sz(ss); i++){
         bool done=false;
         for(int j=idxx; j<sz(res); j++){
            str sss; sss+=ss[i];
            if(res[j]-'0'>=ss[i]-'0'){res.insert(j,sss);done=true; break;}
         }
         if(!done) res+=ss[i];
      }

      if(s==ss) break;
      ss=findSum(ss,"1");
   }

   cout << res << endl;





   return 0;
}

