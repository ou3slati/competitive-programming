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
int idx,ln;

string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";
    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');

        carry = sum/10;
    }

    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    if (carry)
        str.push_back(carry+'0');

    reverse(str.begin(), str.end());

    return str;
}

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1; i++)
    if (str1[i] < str2[i])
        return true;
    else if (str1[i] > str2[i])
        return false;

    return false;
}

string findDiff(string str1, string str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    for (int i=0; i<n2; i++)
    {
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - carry);

        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    reverse(str.begin(), str.end());

    return str;
}

void solve(){

   for (int i=1; i<=sz(s); i++){
      for (int j=0; j<=i; j++){
         string pref=s.substr(0,j);
         string str=s.substr(j,i);
         bool allzero=true;
         for (int q=0; q<sz(str); q++) if(str[q]!='0'){allzero=false; break;}
         if(allzero  && j>0) break;
         //cout << pref << ' ' << str << endl;
         string res=findDiff(str,"1");
         //cout << res << endl;
         reverse(all(res));
         res.resize(sz(pref));
         while(sz(res)<sz(s)){
            //cout << res << endl;
            res+=str;
            str=findSum(str,"1");
         }
         if(sz(res)>sz(s)) res.resize(sz(s));
         if(res==s){
            idx=j; ln=i;
            return;
         }
      }

   }
}

int modpow(int x, int p){
   if(p==0) return 1;
   int ans=modpow(x,p/2);
   ans=(ans*ans)%MOD;
   if(p%2==1) ans=(ans*x)%MOD;
   return ans;
}



int32_t main(){
   boost;
   cin>>s;
   if(sz(s)<=5){
      int mx=0;
      for (int i=0; i<sz(s); i++){
         mx=modpow(10,sz(s));
      }
      //cout <<mx << endl;

      string str;
      for (int i=1;i<=mx; i++){
         string str2=to_string(i);
         str+=str2;
      }
      //cout << str << endl;
      cout << (int)(str.find(s)+1)%MOD << endl;
   }
	else{
      solve();
	//cout <<idx << ' ' << ln << endl;
	int res=0;
	for (int l=1; l<ln; l++)res=(res+(modpow(10,l)*l)%MOD)%MOD;
	//res=(res-1+MOD)%MOD;
	//cout << res << endl;
	string str=s.substr(idx,ln);
	//cout << str << endl;
	if(sz(str)!=1)str[0]--;
	reverse(all(str));
	for (int j=0; j<sz(str); j++){
      int x=str[j]-'0';
      res=(res+(modpow(10,j)*x*sz(str))%MOD)%MOD;
      //cout << res << endl;
	}
	//res=(res-1+MOD)%MOD;
	res=(res-idx+MOD)%MOD;
	cout << res << endl;

	}

   return 0;
}

