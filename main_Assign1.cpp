#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

const double EPS = 1e-9;

class Point {
public:
    double x, y;
};

class Line {
public:
    Point p1, p2;
};

void bai1() {
    string s;
    cin.ignore();

    while (getline(cin, s)) {
        for (int i = s.length() - 1; i >= 0; i--)
            cout << s[i];
        if (!cin.eof()) cout << endl;
    }
}

void bai2() {
    Point A, B, C, D;

    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    cin >> C.x >> C.y;
    cin >> D.x >> D.y;

    double a1 = B.y - A.y;
    double b1 = A.x - B.x;
    double c1 = a1 * A.x + b1 * A.y;

    double a2 = D.y - C.y;
    double b2 = C.x - D.x;
    double c2 = a2 * C.x + b2 * C.y;

    double det = a1 * b2 - a2 * b1;

    if (fabs(det) < EPS) {
        if (fabs(a1 * C.x + b1 * C.y - c1) < EPS)
            cout << "MANY";
        else
            cout << "NO";
    } else {
        double x = (b2 * c1 - b1 * c2) / det;
        double y = (a1 * c2 - a2 * c1) / det;

        cout << fixed << setprecision(2);
        cout << x << " " << y;
    }
}

void bai3() {
    int m, n;
    cin >> m >> n;

    while (n != 0) {
        int r = m % n;
        m = n;
        n = r;
    }

    cout << m;
}

void bai4() {
    int n;
    cin >> n;

    int a[1000];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }

    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i != n - 1) cout << " ";
    }
}

void bai5() {
    double a[5];

    for (int i = 0; i < 5; i++)
        cin >> a[i];

    double Max = a[0];
    double Min = a[0];

    for (int i = 1; i < 5; i++) {
        if (a[i] > Max) Max = a[i];
        if (a[i] < Min) Min = a[i];
    }

    cout << fixed << setprecision(2);
    cout << Max + Min;
}

int main() {

    int choice;

    cout << "Nhap bai (1-5): ";
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
    case 4:
        bai4();
        break;
    case 5:
        bai5();
        break;
    default:
        cout << "Khong hop le!";
    }

    return 0;
}