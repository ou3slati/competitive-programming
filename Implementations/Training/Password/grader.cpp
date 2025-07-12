// Sample grader for contestants' use.
//
// Usage: place your input data in the file password.in in the format
//
// line 1: N S
// line 2: hidden_password
//
// Then compile this grader together with your implementation.
// Run the binary to see your guessing strategy at work!
// Set DEBUG to 1 to print all queries.


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int>vi;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

typedef string str; 

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define ROF(i,a,b) for(int i=b-1; i>=a; i--)


void ckmin(int &x, int y){x=min(x,y);}
//------------------------------------


#define DEBUG 0
#define MAX_QUERIES 50000
#define MAX_N 5000
#define MAX_SIGMA 26

static string password;
static int n, s, numQueries;
static stringstream msg;

static void end(int success) {
  cout << (success ? "SUCCESS! " : "ERROR: ") << msg.str() << endl;
  exit(0);
}

int query(string q) {
  if (++numQueries > MAX_QUERIES) {
    msg << "Could not guess the password with " << MAX_QUERIES << " questions.";
    end(0);
  }

  int len = q.size();

  // validation
  if (len < 1 || len > n) {
    msg << "Query '" << q << "' should have length between 1 and "
        << n << " characters.";
    end(0);
  }

  for (int i = 0; i < len; i++) {
    if (q[i] < 'a' || q[i] >= 'a' + s) {
      msg << "Illegal character '" << q[i] << "' found.";
      end(0);
    }
  }

  // while possible, advance one character in q and find its next
  // occurrence in password
  int i = 0, j = 0, plen = password.size();
  while (i < plen && j < len) {
    while ((i < plen) && (password[i] != q[j])) {
      i++;
    }
    if (i < plen) { /* found a match */
      i++;
      j++;
    }
  }

  if (DEBUG) {
    cout << "Question #" << numQueries << " [" << q << "] answer " << j << endl;
  }
  return j;
}

string guess(int n, int s);



//------------------------------------


int alp;

void upd(str &s, int idx, char c){
    str ss;
    FOR(i,0,sz(s)+1){
        if(i==idx) ss+=c;
        if(i<sz(s)) ss+=s[i];
    }
    s=ss; 
}

bool check(str s, int idx, char c){
    str ss; 
    FOR(i,0,min(idx,sz(s))) ss+=s[i];
    ss+=c; 

    FOR(i,idx,sz(s)) if(s[i]==c) ss+=s[i];

    return query(ss)==sz(ss);
}

str guess(int N, int S){
    alp=S; 
    vi nb(alp);
    for(char c='a'; c<=char('a'+alp-1); c++){
        str s;
        FOR(i,0,N) s+=c; 
        nb[c-'a']=query(s);
    }

     
    int idx=0;
    FOR(i,0,alp) if(nb[i]>nb[idx]) idx=i; 


    str cur;
    FOR(i,0,nb[idx]) cur+=char(idx+'a');

    FOR(i,0,alp) if(i!=idx){
        char c=i+'a';
        while(nb[i]--){
            int l=0,r=sz(cur),ind=-1;
            while(l<=r){
                int m=(l+r)/2;
                if(check(cur,m,c)){
                    ind=m; 
                    l=m+1;
                }
                else r=m-1;
            }
            //if(ind==-1) cout << "here" << endl;

            upd(cur,ind,c);

            //cout << cur << endl;
        }
    }
    //cout << sz(cur) << endl;
    return cur; 
}
//----------------------------------------------



int main() {

  ifstream f("password.in");
  f >> n >> s >> password;
  f.close();
  assert(n && s && !password.empty());

  string answer = guess(n, s);
  if (DEBUG) {
    cout << "Your answer: [" << answer << "]\n";
  }

  if (answer.compare(password)) {
    msg << "Your answer was [" << answer
        << "] which does not match the password [" << password << "].";
    end(0);
  } else {
    msg << "You guessed the password with " << numQueries << " queries.";
    end(1);
  }

    return 0;
}
