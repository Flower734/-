#include <iostream>
//#include <windows.h>
//#include <stdlib.h>
#include <sys/time.h>
using namespace std;
const int N = 10000; // matrix size
double b[N][N], sum[N];
double a[N];

void init(int N) // generate a N*N matrix
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            b[i][j] = i + j;
}

void col_ordinary(int n)
{
    for (int i = 0; i < n; i++)
    {
        sum[i] = 0.0;
        for (int j = 0; j < n; j++)
        {
            sum[i] += b[j][i] * a[j];
        }

    }
}
void col_pro(int n)
{
    for (int i = 0; i < n; i++)
    {
        sum[i] = 0.0;
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum[i] += b[j][i] * a[j];
        }
    }
}
int main() {
    //long long head,tail,freq;// timers
    struct timeval start, end;
    int step = 100;
    long long counter;
    double seconds;
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }
    init(N);
    // similar to CLOCKS_PER_SEC
   //QueryPerformanceFrequency((LARGE_INTEGER*)&freq );
    for (int n = 0; n <= 10000; n += step)
    {
        //start time
       // QueryPerformanceCounter((LARGE_INTEGER*)&head);
        gettimeofday(&start, NULL);
        counter = 0;
        do
        {
            col_ordinary(n);
            //col_pro(n);
            counter++;
            // end time
            gettimeofday(&end, NULL);
            seconds = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000.0;//ms
        } while (seconds < 10);
        //seconds=(tail - head) * 1000.0 / freq;
        cout << n << ' ' << counter << ' ' << seconds << ' ' << seconds / counter << endl;
        if (n == 100)step = 100;
        if (n == 1000)step = 1000;
    }
    return 0;
}





