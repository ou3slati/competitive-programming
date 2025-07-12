#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  vector<vector<long long> > A(2,vector<long long>(n));
  for(int i=0;i<n;i++){
    scanf("%lld%lld",&A[0][i],&A[1][i]);
  }

  bool ans=true;
  bool F=true;
  for(int i=0;i<n;i++){
    if(A[1][i]>0){
      F=false;
    }
  }
  if(F){
    for(int i=0;i<n;i++){
      if(A[0][i]>0){
	     ans=false;
      }
    }
  }

  vector<vector<long long> > b(2,vector<long long>(n));
  long long  K[2];
  for(int t=0;t<2;t++){
    for(int i=0;i<n;i++){
      b[t][i]=A[t][i];
    }

    K[t]=0ll;
    long long r=0ll;
    do{
      for(int i=0;i<n;i++){
      	long long T=b[t][i]+r;
      	b[t][i]=T%2;
      	r=T/2;
      }
      K[t]+=r;
    }while(r>0);


    bool F=true;
    for(int i=0;i<n;i++){
      if(b[t][i]==0){
	      F=false;
      }
    }

    if(F){
      K[t]++;
      for(int i=0;i<n;i++){
	       b[t][i]=0;
      }
    }
  }


  for(int i=0;i<n;i++){
    if(b[0][i]!=b[1][i]){
      ans=false;
    }
  }
  long long x=K[0]-K[1];
  if(x<0){
    ans=false;
  }


  for(int i=n-1;i>=0;i--){
    x=A[1][i]-A[0][i]+2*x;
    if(x<0){
      ans=false;
    }
  }
  puts(ans?"Yes":"No");
  return 0;
}