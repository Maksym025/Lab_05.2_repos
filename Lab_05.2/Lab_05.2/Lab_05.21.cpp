#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void S(const double x, const double eps, int& n, double& s);
double PI = 3.14159265358979;

int main()
{
    double xp, xk, x, dx, eps, s;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;
    cout << "-------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "   |"
        << setw(10) << "arccot(x)" << " |"
        << setw(7) << "S" << "    |"
        << setw(7) << "n" << " |" << endl;
    cout << "-------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (abs(x) > 1) {
            cout << "|x| must be <= 1." << endl;
        }
        else {
            S(x, eps, n, s);
            cout << "|" << setw(7) << setprecision(2) << x << " |"
                << setw(10) << setprecision(5) << (PI / 2 - atan(x)) << " |"
                << setw(10) << setprecision(5) << s << " |"
                << setw(7) << n << " |" << endl;
        }
        x += dx;
    }

    cout << "-------------------------------------------" << endl;
    return 0;
}

void S(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = x;
    s = PI / 2;  
    do {
        a = (pow(-1, n+1) * pow(x, 2 * n + 1)) / (2 * n + 1);
        s += a; 
        n++;
    } while (abs(a) >= eps);
}
