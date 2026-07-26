#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

//=====================================================
// Bai 1
//=====================================================

void bai1()
{
    ifstream fin("numbers.txt");
    ofstream fout("numbers.sorted");

    if (!fin)
    {
        cout << "Cannot open numbers.txt\n";
        return;
    }

    vector<double> a;
    double x;

    while (fin >> x)
        a.push_back(x);

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
        fout << a[i] << " ";

    fin.close();
    fout.close();

    cout << "Sorted successfully!\n";
}

//=====================================================
// Kadane
//=====================================================

int kadane(vector<int> &a, int &start, int &finish)
{
    int sum = 0;
    int maxSum = INT_MIN;

    finish = -1;

    int localStart = 0;

    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];

        if (sum < a[i])
        {
            sum = a[i];
            localStart = i;
        }

        if (sum > maxSum)
        {
            maxSum = sum;
            start = localStart;
            finish = i;
        }
    }

    if (finish != -1)
        return maxSum;

    maxSum = a[0];
    start = finish = 0;

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > maxSum)
        {
            maxSum = a[i];
            start = finish = i;
        }
    }

    return maxSum;
}

//=====================================================
// Bai 2
//=====================================================

void bai2()
{
    ifstream fin("matrix.txt");
    ofstream fout("matrix.out");

    if (!fin)
    {
        cout << "Cannot open matrix.txt\n";
        return;
    }

    int m, n;

    fin >> m >> n;

    vector<vector<int>> A(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fin >> A[i][j];

    int maxSum = INT_MIN;

    int finalLeft = 0;
    int finalRight = 0;
    int finalTop = 0;
    int finalBottom = 0;

    for (int left = 0; left < n; left++)
    {
        vector<int> temp(m, 0);

        for (int right = left; right < n; right++)
        {
            for (int i = 0; i < m; i++)
                temp[i] += A[i][right];

            int start, finish;

            int sum = kadane(temp, start, finish);

            if (sum > maxSum)
            {
                maxSum = sum;

                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }

    fout
        << finalTop + 1 << " "
        << finalLeft + 1 << " "
        << finalBottom + 1 << " "
        << finalRight + 1 << " "
        << maxSum;

    fin.close();
    fout.close();

    cout << "Largest rectangle found!\n";
    
}

//=====================================================
// Menu
//=====================================================

void menu()
{
    cout << "==============================\n";
    cout << " Lecture 7 Assignments\n";
    cout << "==============================\n";
    cout << "1. Sort real numbers\n";
    cout << "2. Largest Sum Rectangle\n";
    cout << "3. GCD using Recursion\n";
    cout << "4. Binary Numbers\n";
    cout << "5. Permutations\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}
//=====================================================
// Bai 3
//=====================================================

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void bai3()
{
    int x, y;

    cout << "Enter X: ";
    cin >> x;

    cout << "Enter Y: ";
    cin >> y;

    cout << "GCD = " << gcd(x, y) << endl;
}

//=====================================================
// Bai 4
//=====================================================

void binary(int n, string s)
{
    if (s.length() == n)
    {
        cout << s << endl;
        return;
    }

    binary(n, s + "0");
    binary(n, s + "1");
}

void bai4()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    binary(n, "");
}

//=====================================================
// Bai 5
//=====================================================

void permutation(vector<int> &a, int k, int n)
{
    if (k == n)
    {
        for (int x : a)
            cout << x;

        cout << endl;
        return;
    }

    for (int i = k; i < n; i++)
    {
        swap(a[k], a[i]);

        permutation(a, k + 1, n);

        swap(a[k], a[i]);
    }
}

void bai5()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<int> a;

    for (int i = 1; i <= n; i++)
        a.push_back(i);

    permutation(a, 0, n);
}

//=====================================================
// MAIN
//=====================================================

int main()
{
    int choice;

    do
    {
        menu();

        cin >> choice;

        switch (choice)
        {
        case 1:
            bai1();
            break;

        case 2:
            bai2();
            break;

        case 3:
            bai3();
            break;

        case 4:
            bai4();
            break;

        case 5:
            bai5();
            break;

        case 0:
            cout << "Exit program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}