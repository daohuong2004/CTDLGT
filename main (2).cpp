#include <iostream>
#include <vector>
using namespace std;

//====================== BAI 1 ======================//
// Quick Sort
void quickSort(vector<double> &a, int left, int right) {
    int i = left, j = right;
    double pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(a, left, j);
    if (i < right) quickSort(a, i, right);
}

void bai1() {
    int n;
    cin >> n;

    vector<double> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    quickSort(a, 0, n - 1);

    for (double x : a)
        cout << x << " ";
}

//====================== BAI 2 ======================//
// Subset Sum (Backtracking)

bool found = false;

void subset(int i, int sum, int X, vector<int> &a) {

    if (sum == X) {
        found = true;
        return;
    }

    if (i == a.size() || sum > X || found)
        return;

    subset(i + 1, sum + a[i], X, a);

    subset(i + 1, sum, X, a);
}

void bai2() {
    int n, X;
    cin >> n >> X;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    found = false;

    subset(0, 0, X, a);

    if (found)
        cout << "YES";
    else
        cout << "NO";
}

//====================== BAI 3 ======================//
// 0/1 Knapsack (Dynamic Programming)

void bai3() {

    int n, X;
    cin >> n >> X;

    vector<int> w(n + 1), v(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    vector<vector<int>> dp(n + 1, vector<int>(X + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= X; j++) {

            dp[i][j] = dp[i - 1][j];

            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[n][X];
}

//====================== MAIN ======================//

int main() {

    int choice;

    cout << "===== MENU =====\n";
    cout << "1. Quick Sort\n";
    cout << "2. Subset Sum\n";
    cout << "3. Knapsack\n";
    cout << "Choose: ";

    cin >> choice;

    switch (choice) {

    case 1:
        bai1();
        break;

    case 2:
        bai2();
        break;

    case 3:
        bai3();
        break;

    default:
        cout << "Invalid!";
    }

    return 0;
}