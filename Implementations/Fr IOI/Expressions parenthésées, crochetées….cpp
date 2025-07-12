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

str s;
int i;

char op(char c){
   if(c=='(') return ')';
   if(c=='[') return ']';
   if(c=='{') return '}';
   if(c=='<') return '>';
}

char solve(char a){
   while(i<sz(s)){
      if(s[i]=='[' || s[i]=='<' || s[i]=='{' || s[i]=='('){
         char p=s[i];
         i++;
         char c=solve(p);
         if(op(p)!=c) {cout << "no" << endl; exit(0);}
      }

      else if(s[i]==op(a)) return s[i];
      else if(s[i]==']'||s[i]=='}'||s[i]==')'||s[i]=='>') return '.';
      i++;
   }
   if(i>=sz(s)) return '.';
}


int32_t main(){
   boost;
	getline(cin,s);

   char f;
   for(int i=0; i<sz(s); i++) if(s[i]==']'||s[i]=='}'||s[i]==')'||s[i]=='>'||s[i]=='[' || s[i]=='<' || s[i]=='{' || s[i]=='(') {
      f=s[i]; break;
   }
   if(f==']'||f=='}'||f==')'||f=='>') {cout << "no" << endl; return 0;}


	for(i=0; i<sz(s); i++) if(s[i]=='[' || s[i]=='<' || s[i]=='{' || s[i]=='('){
      char p=s[i];
      i++;
      char c=solve(p);
      if(c!=op(p)){cout << "no" << endl; return 0;}

	}

	cout << "yes" << endl;

   return 0;
}
