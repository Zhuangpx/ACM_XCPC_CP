// violet apricity
// Do all I can do.Do good to be good.
//g++  ./violet/run.cpp -o ./violet/run.exe
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
#include<map>
#include<sstream>
#include<numeric>
#include<queue>
#include<iomanip>

#define STD using namespace std;
#define ll long long
#define db double
#define ldb long double
#define IOS std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0);
#define MAX 88888888
#define INF 0x3f3f3f3f
#define r0 return 0;
#define SYP system("pause");
#define endl '\n'
using namespace std;
int main()
{
    char s[6] = "hello";
    char a[6], b[6], c[6], d[6];
    memcpy(a, s, 6);
    memmove(b, s, 6);
    memcpy(c, s, 6);
    memmove(d, s, 6);
    cout << "a:" << a << " b:" << b << " c:" << c << " d:" << d << '\n';
    memcpy(a, a + 1, 3);
    memmove(b, b + 1, 3);
    memcpy(c + 1, c, 3);
    memmove(d + 1, d, 3);
    cout << "a:" << a << " b:" << b << " c:" << c << " d:" << d << '\n';
    //SYP
    return 0;
}
