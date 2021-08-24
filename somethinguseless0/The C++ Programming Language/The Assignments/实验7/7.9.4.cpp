#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int a(int x, int y)
{
    return x * y;

}
int b(int x, int y)
{
    return x - y;

}
int c(int x, int y) {
    return x * y;
}
int d(int x, int y)
{
    return x / y;
}
void main()
{
    char ch;
    int (*p[4])(int, int) = { a,b,c,d }, i, x,y,z;
    int k = 12;
    while (k)
    {
        for (i = 0; i < 100; i++)
        {
            x = (int)(100.0 * rand() / (RAND_MAX + 1.0)) % 10;
            y = (int)(100.0 * rand() / (RAND_MAX + 1.0)) % 10;
            z = (int)(100.0 * rand() / (RAND_MAX + 1.0)) % 4;
        }
        switch (z) {
        case 0:ch = '+'; break;
        case1:ch = '-'; break;
        case2:ch = '*'; break;
        case3:ch= '/'; break;
       }
        i = (*p[z])(x, y);
        cout << x << ch << y<<'='<<i << endl;
        k--;
    }
}
                                                                                                             
