// first_pract.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <math.h>
#include <cmath>

using namespace std;
const int N = 10000;
const int n = 10;
int gist[10];  // gistogramm
double arr[10000];
const double PI = 3.141592653589793;

int method01()
{
    const string s = "Liner congurent argument:";
    cout << s << endl;
    clock_t t = clock();
    const int a = 423, c = 73, m = 211;
    int x0 = 1, x1;
    double y;
    for (int i = 0; i < N; i++)
    {
        x1 = (a * x0 + c) % m;
        y = (double)x1 / m;
        for (int j = 0; j < n; j++)
        {
            if ((y >= (double)j / n) && (y < ((double)j + 1) / n)) gist[j]++;
        }
        x0 = x1;
    }
    t = clock() - t;
    return t;
}

int method02()
{
    const string s = "Quadratic congruent method:";
    cout << s << endl;
    clock_t t = clock();
    const int d = 633, a = 423, c = 73, m = 211;
    int x0 = 1, x1;
    double y;
    for (int i = 0; i < N; i++)
    {
        x1 = (d * x0 * x0 + a * x0 + c) % m;
        y = (double)x1 / m;
        for (int j = 0; j < n; j++)
        {
            if ((y >= (double)j / n && y < ((double)j + 1) / n)) gist[j]++;
        }
        x0 = x1;
    }
    t = clock() - t;
    return t;
}

int method03()
{
    const string s = "Fibonacci numbers:";
    cout << s << endl;
    clock_t t = clock();
    const int m = 217;
    long long int x0 = 0, x1 = 1, x2;
    double y;
    for (int i = 0; i < N; i++)
    {
        x2 = (x1 + x0) % m;
        y = (double)x1 / m;
        for (int j = 0; j < n; j++)
        {
            if ((y >= (double)j / n && y < ((double)j + 1) / n)) gist[j]++;
        }
        x0 = x1;
        x1 = x2;
    }
    t = clock() - t;
    return t;
}

int method04()
{
    const string s = "Inverse congruent sequence:";
    cout << s << endl;
    clock_t t = clock();
    long a = 13, c = 14, x0 = 1, infinity = 10001, m = 331;
    long x, xrev;
    double u;
    for (int t = 0; t < 10000; t++) {
        if (x0 == 0) {
            xrev = infinity;
        }
        else if (x0 >= infinity) {
            xrev = 0;
        }
        else {
            for (int i = 0; i < m; i++) {
                if ((x0 * i) % m == 1) {
                    xrev = i;
                    break;
                }
            }
        }
        x = (a * xrev + c) % m;
        x0 = x;
        u = x / ((double)m - 1);
        for (int j = 0; j < n; j++)
        {
            if ((u >= (double)j / n && u < ((double)j + 1) / n)) gist[j]++;
        } 
    }
    t = clock() - t;
    return t;
}

int method05()
{
    const string s = "Merge method:";
    cout << s << endl;
    clock_t t = clock();
    int arr1[N], arr2[N];
    double x, y;
    int m1 = 71, a1 = 3, c1 = 19, x1 = 1;
    for (int i = 0; i < N; i++)
    {
        x1 = ((a1 * x1) + c1) % m1;
        arr1[i] = x1;
    }
    int m2 = 176021, a2 = 5, c2 = 19, k2 = 2, x2 = 1;
    for (int i = 0; i < N; i++)
    {
        x2 = (k2 * (x2 ^ 2) + (a2 * x2) + c2) % m2;
        arr2[i] = x2;
    }
    int m = 176021;
    for (int i = 0; i < N; i++)
    {
        x = (arr2[i] - arr1[i]) % m;
        y = (float)x / m;
        for (int j = 0; j < n; j++)
        {
            if ((y >= (double)j / n && y < ((double)j + 1) / n)) gist[j]++;
        }
    }
    t = clock() - t;
    return t;
}

void sum(double* arr1) 
{
    double m1 = 1.0, a1 = 0.51, x = 0.27, x1 = 0, x2 = 0.02;
    for (int j = 0; j < N; j++) {
        arr1[j] = 0;
    }
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < 12; i++)
        {
            x = x1;
            x1 = fmod((x1 + x2), m1);
            x2 = x;
            arr1[j] = arr1[j] + x1;
        }
    }
}

int method06()
{
    const string s = "3 sigma rule";
    cout << s << endl;
    clock_t t = clock();
    double arr1[N];
    sum(arr1);
    int m = 0, k = 1, z = 0;
    double y;
    for (int i = 0; i < N; i++)
    {
        y = m + (arr1[i] - 6) * k;
        for (double j = -3; j < 3; j += 0.6)
        {
            if ((y >= j) && (y < (j + 0.6))) gist[z]++;
            z++;
        }
        z = 0;
    }
    t = clock() - t;
    return t;
}

int method07()
{
    const string s = "Polar coordinate method:";
    cout << s << endl;
    clock_t t = clock();
    double arr1[N];
    double arr2[N];
    double m1 = 1.0, a1 = 0.51, x = 0.27, x1 = 0, x2 = 0.02;
    int z = 0;
    for (int j = 0; j < N; j++) {
        x = x1;
        x1 = fmod((x1 + x2), m1);
        x2 = x;
        arr1[j] = 2 * x1 - 1;
    }
    m1 = 1.0;
    a1 = 0.53;
    x = 0.24;
    x1 = 0;
    x2 = 0.03;
    for (int j = 0; j < N; j++) {
        x = x1;
        x1 = fmod((x1 + x2), m1);
        x2 = x;
        arr2[j] = 2 * x1 - 1;
    }
    double v1, v2, y1, y2, f;
    for (int i = 0; i < N; i++)
    {
        v1 = 2 * arr1[i] - 1;
        v2 = 2 * arr2[i] - 1;

        f = v1 * v1 + v2 * v2;

        if (f >= 1) continue;

        y1 = v1 * sqrt(-2 * log(f) / f);
        y2 = v2 * sqrt(-2 * log(f) / f);
        for (double j = -3; j < 3; j += 0.6)
        {
            if ((y1 >= j) && (y1 < (j + 0.6))) gist[z]++;
            if ((y2 >= j) && (y2 < (j + 0.6))) gist[z]++;
            z++;
        }
        z = 0;
    }
    t = clock() - t;
    return t;
}

int method08()
{
    const string s = "The method of relations:";
    cout << s << endl;
    clock_t t = clock();

    double arr1[N];
    double arr2[N];
    int z = 0;
    double m1 = 1.0, a1 = 0.51, x = 0.27, x1 = 0, x2 = 0.02;
    for (int j = 0; j < N / 2; j++) {
        x = x1;
        x1 = fmod((x1 + x2), m1);
        x2 = x;
        arr1[j] = x1;
    }
    m1 = 1.0;
    a1 = 0.53;
    x = 0.24;
    x1 = 0;
    x2 = 0.03;
    for (int j = 0; j < N / 2; j++) {
        x = x1;
        x1 = fmod((x1 + x2), m1);
        x2 = x;
        arr2[j] = x1;
    }

    double g;
    for (int i = 1; i < N; i++)
    {
        g = sqrt(8 / exp(1)) * (arr2[i] - 0.5) / arr1[i];
        if (pow(g, 2) <= 5 - 4 * exp(0.25) * arr1[i]) {
            for (double j = -3; j < 3; j += 0.6)
            {
                if ((g >= j) && (g < (j + 0.6))) gist[z]++;
                z++;
            }
            z = 0;
            continue;
        }
        else if (pow(g, 2) >= 1.4 + 4 * exp(-1.35) / arr1[i]) {
            continue;
        }
        else if (pow(g, 2) <= -4 * log(arr1[i])) {
            for (double j = -3; j < 3; j += 0.6)
            {
                if ((g >= j) && (g < (j + 0.6))) gist[z]++;
                z++;
            }
            z = 0;
        }
    }

    t = clock() - t;
    return t;
}

int method09()
{
    const string s = "Logarithm method for generating an indicative distribution:";
    cout << s << endl;
    clock_t t = clock();
    double arr1[N];
    float param = 31;
    double y;
    double m1 = 1.0, a1 = 0.51, x = 0.27, x1 = 0, x2 = 0.02;
    for (int j = 0; j < N; j++) {
        x = x1;
        x1 = fmod((x1 + x2), m1);
        x2 = x;
        arr1[j] = x1;
    }

    for (int i = 1; i < N; i++)
    {
        y = -param * log(1 - arr1[i]);
        for (int j = 0; j < n; j++)
        {
            if ((y >= (j * 10)) && (y < ((j + 1) * 10))) gist[j]++;
        }
    }
    t = clock() - t;
    return t;
}

int method10()
{
    const string s = "Ahrens method for generating a gamma distribution of order a > 1:";
    cout << s << endl;
    clock_t t = clock();

    double arr2;
    double m1 = 1.0, a1 = 0.51, x = 0.27, x1 = 0, x2 = 0.02, a = 11;
    double y;
    for (int j = 0; j < N; j++) {
        x = x1;
        x1 = fmod((x1 + x2), m1);
        x2 = x;
        arr2 = tan(PI * x1);
        y = log(2 * a - 1) * arr2 + a - 1;
        for (int j = 0; j < n; j++)
        {
            if ((y >= j * 10) && (y < (j + 1) * 10)) gist[j]++;
        }
    }
    t = clock() - t;
    return t;
}

void cout_time(int time)
{
    cout << "It tooks " << time << " clocks (" << (float)time / CLOCKS_PER_SEC << ")" << endl;
}
void cout_result(int time)
{
    cout << "Interval" << "      " << "Frequency" << endl;
    int res = 0;
    int z = 10;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << (float)i / 10 << "," << (float)(i + 1) / 10 << "]";
        if ((i == 0) || (i == 9))
        {
            cout << "        ";
        }
        else
        {
            cout << "      ";
        }
        cout << (double)gist[i] / N << endl;
        res = res + gist[i];
    }
    cout_time(time);
    time = 0;
}
void cout_result_2(int time)
{
    cout << "Interval" << "      " << "Frequency" << endl;
    int res = 0;
    double a = -3, b;
    for (int i = 0; i < n; i++)
    {
        b = a + 0.6;
        if (i == 4) b = 0;
        cout << "[" << (float)a << "," << (float)b << "]";
        if (i == 0)
        {
            cout << "       ";
        }
        else if ((i == 1) || (i == 2) || (i == 3))
        {
            cout << "     ";
        }
        else if (i == 4)
        {
            cout << "        ";
        }
        else if (i == 5)
        {
            cout << "         ";
        }
        else if ((i == 6) || (i == 7) || (i == 8))
        {
            cout << "       ";
        }
        else if (i == 9)
        {
            cout << "         ";
        }
        cout << (double)gist[i] / N << endl;
        res = res + gist[i];
        a = b;
    }
    cout_time(time);
    time = 0;
}
void cout_result_3(int time)
{
    cout << "Interval" << "      " << "Frequency" << endl;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i * 10 << "," << (i + 1) * 10 << "]";
        if (i == 0)
        {
            cout << "          ";
        }
        else if (i == 9)
        {
            cout << "        ";
        }
        else
        {
        cout << "         ";
        }
        cout << (double)gist[i] / N << endl;
        res = res + gist[i];
    }
    cout_time(time);
    time = 0;
}
void purifier()
{
    for (int i = 0; i < 10; i++)
    {
        gist[i] = 0;
    }
}

int main()
{
    int v = 0;
    int time = 0;
    do {
        cout << "Choose a method for random number generation (1-10): ";
        cin >> v;
        if ((v > 0) && (10 >= v))
        {
            switch (v)
            {
            case 1: time = method01();  // ready
                cout_result(time);
                break;
            case 2: time = method02();  // ready
                cout_result(time);
                break;
            case 3: time = method03();  // ready
                cout_result(time);
                break;
            case 4: time = method04();  // ready
                cout_result(time);
                break;
            case 5: time = method05();  // ready
                cout_result(time);
                break;
            case 6: time = method06();  // ready
                cout_result_2(time);
                break;
            case 7: time = method07();  // ready
                cout_result_2(time);
                time = 0;
                break;
            case 8: time = method08();  // ready
                cout_result_2(time);
                time = 0;
                break;
            case 9: time = method09();  // ready
                cout_result_3(time);
                time = 0;
                break;
            case 10: time = method10();  // ready
                cout_result_3(time);
                time = 0;
                break;
            }
            purifier();
            cout << "Press 0 to exit" << endl;
        }
    } while (v != 0);
    return 0;
}