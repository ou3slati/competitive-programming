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

int32_t main(){
   boost;
   string per[6]={"ABC","ACB","BAC","BCA","CAB","CBA"};
	string s; cin>>s;
	map <char,int> mp;
	map<pair<int,char>,int> mp2;

	for (int i=0; i<sz(s); i++){
      if(mp.count(s[i])) mp[s[i]]++;
      else mp[s[i]]=1;
      mp2[{i,'A'}]=mp['A']; mp2[{i,'B'}]=mp['B']; mp2[{i,'C'}]=mp['C'];
   }

   mp2[{-1,'A'}]=0; mp2[{-1,'B'}]=0; mp2[{-1,'C'}]=0;

   int res=INF;
   //string pres;
   for (int idx=0; idx<6; idx++){
      string p=per[idx];

      for (int i=0; i<=mp[p[0]]; i++){ // number of elements in  the suffix
         int NA=0,NB=0;
         int SAB,SBA;

         char c=p[0];
         for (int j=0; j<3; j++) if('A'+j!=c){
            char cc='A'+j;
            NA+=mp2[{sz(s)-1,cc}]-mp2[{sz(s)-1-i,cc}]+mp2[{mp[cc]-i-1,cc}];
            if(cc==p[1]) SAB=mp2[{sz(s)-1,cc}]-mp2[{sz(s)-1-i,cc}]+mp2[{mp[cc]-i-1,cc}];
         }

         c=p[1];
         int s=mp[p[0]]-i,e=s+mp[c]-1;
         for (int j=0; j<3; j++) if('A'+j!=c){
            char cc='A'+j;
            NB+=mp2[{e,cc}]-mp2[{s-1,cc}];
            if(cc==p[0]) SBA=mp2[{e,cc}]-mp2[{s-1,cc}];
         }
         //res=min(res,NA+NB-min(SAB,SBA));
         int x=NA+NB+min(SAB,SBA);
         if(x<res){
            res=x;
           //pres=p;
         }
      }

   }
   cout << res << endl;
   //cout << pres << endl;
   return 0;
}

//AAAABBCAAAAABBBBBACBBBBBCCCCCAACCCC
