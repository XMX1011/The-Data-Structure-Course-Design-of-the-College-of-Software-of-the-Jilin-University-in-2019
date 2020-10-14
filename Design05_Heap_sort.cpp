#include "stdc++.h"
using namespace std;
int h[10000000], n;
int s = 0, average = 0;
// 递归
void shiftDown(int i)
{
    int t = i;
    if (i * 2 <= n && h[t] > h[i * 2])
        t = i * 2;
    if (i * 2 + 1 <= n && h[t] > h[i * 2 + 1])
        t = i * 2 + 1;
    if (i != t)
    {
        swap(h[i], h[t]);
        s++;
        shiftDown(t);
    }
}
void heapSort()
{
    //先创建堆
    for (int i = n / 2; i >= 1; i--)
        shiftDown(i);
    while (n > 1)
    {
        swap(h[1], h[n]);
        s++;
        n--;
        shiftDown(1); //每查找完一次，就要重新排序
    }
}
int main()
{
    int i, num;
    cin >> num;
    n = num;
    ofstream file;
    file.open("sort.txt");
    srand((unsigned)(time(NULL)));
    for (int j = 0; j < 10; j++)
    {
        for (int i = 1; i <= num; i++)
            h[i] = rand() % 99991 + 10;
        for (int i = num; i >= 1; i--)
        {
            file << h[i] << " ";
        }
        file << '\t' << s;
        file << endl;
        heapSort();
        for (int i = num; i >= 1; i--)
        {
            file << h[i] << " ";
        }
        file << '\t' << s << endl;
        average += s;
    }
    file << "average:" << average / 10;
    file.close();
    system("pause");
    return 0;
}