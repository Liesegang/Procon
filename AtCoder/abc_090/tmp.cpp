#include<iostream>
#include<stdio.h>   
#include<math.h>
#include<string> 
#include<set>  
using namespace std;    
int main()   
{   
long long n,k,cnt=0;
cin>>n>>k;
if(k==0)
{cout<<n*n << endl;
 return 0;}
for(int i=k+1;i<=n;i++)
{
cnt+=(i-k)*((n+1)/i);
if((n+1)%i-k>0)
cnt+=(n+1)%i-k;}
cout<<cnt << endl;
return 0;  
}
