#include <iostream>
#include<iomanip>
#include <windows.h>
using namespace std;
const int N = 262144/2/2/2/2;
int a[N],b[N];
void ordinary(int n)
{
    long long int sum=0;
    for ( int i = 0; i < n ; i++)
    sum += a [i] ;
}
void pro1(int n)
{
 long long int sum1=0,sum2=0;
 long long int sum=0;
 for ( long long int i =0; i<n ; i+=2)
 {
 sum1+=a[i] ;
 sum2+=a[i +1];
 }
 sum=sum1+sum2;
}


 void pro2 ( int n)
 {
 if (n==1)return ;
 else
 {
 for ( int i = 0; i < n / 2; i++)
 {a[i] += a[n−i−1];
 n = n/2;
 pro2 (n) ;
 }}

void pro3(int n)
{
 for ( long long int m=n ; m>1; m/=2)
 {for ( long long int i =0; i<m/2; i++)
 a [ i ]=a [ i *2]+a [ i*2+1];
}}


int main()
{
   long long head = 0, tail = 0, freq = 0,timesum=0;
	int counter = 0;
	QueryPerformanceFrequency((LARGE_INTEGER*)&freq); // frequency
for(int i=0;i<4194394;i=i*2)
{
	do {
		counter++; sum1 = 0, sum2 = 0, sum = 0;
		QueryPerformanceCounter((LARGE_INTEGER*)&head);// start time
		ordinary(i);
		//pro1(i);
		//pro2(i);
		//pro3(i);
		QueryPerformanceCounter((LARGE_INTEGER*)&tail);// end time
		long long double timesum += tail - head;
		}while (timeuse*1000/freq<10);
		cout<<i<<" "<<counter<<" "<<timeuse<<" "<<(timeuse*1000)/freq/counter<<"ms";
		cout<<endl;
}
return 0;

}
