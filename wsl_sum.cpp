#include <iostream>
#include <sys/time.h>
using namespace std;
const int N = 4194304;
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
 {a[i] += a[n-i-1];
 n = n/2;
 pro2 (n) ;
 }}}

void pro3(int n)
{
 for ( long long int m=n ; m>1; m/=2)
 {for ( long long int i =0; i<m/2; i++)
 a[i]=a[i*2]+a[i*2+1];
}}


int main()
{
    struct timeval start, end;
    long long counter=0;
    double seconds;
	for (int n = 0; n <= 4194304; n *= 2)
    {
        //start time
       // QueryPerformanceCounter((LARGE_INTEGER*)&head);
        gettimeofday(&start, NULL);
        counter = 0;
        do
        {
            ordinary(n);
            //col_pro(n);
            counter++;
            // end time
            gettimeofday(&end, NULL);
            seconds = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000.0;//ms
        } while (seconds < 10);
        //seconds=(tail - head) * 1000.0 / freq;
        cout << n << ' ' << counter << ' ' << seconds << ' ' << seconds / counter << endl;
}
return 0;

}
