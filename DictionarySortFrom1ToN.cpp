#include <iostream>
#include <cassert>

using namespace std;

const int max_len = 10;

char a[max_len];

void topK(int n, int m, int& k, int i)
{
    if (k <= 0 || i >= m)
        return;
    for (int j = 0; j < 10; j++)
    {
        a[i] = j + '0';
        a[i+1] = '\0';
        int v = atoi(a);
        if (v > 0 && v <= n && k > 0)
        {
            cout << a << endl;
            i++;
            k--;
            topK(n, m, k, i);
            i--;
        }
    }
}

void topK(int n, int k)
{
    assert(n >= 0);
    int m = 0;
    int p = n;
    while (p > 0)
    {
        m++;
        p /= 10;
    }
    topK(n, m, k, 0);
}

int main()
{
    topK(2000, 1000);
    return 0;
}