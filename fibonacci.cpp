#include "pch.h"
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
int fib(int n)
{
    if(n<=1)
        return n;
    else
    {
        return fib(n-1) + fib(n-2);
    }
    
}
long fib_opt(int n)
{
    long f[n+1];
    f[0] = 0;
    f[1] = 1;
    for(int i= 2; i<=n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

int main()
{
    int n = 100;
    cout<<"Fib "<<n<< " = "<< fib_opt(n)<<endl;
    return 0;
}