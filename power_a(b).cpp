#include <iostream>
using namespace std;

int power(int a, int b)
{
    // int a = a;
    int n = b;
    if (n == 0)
        return 1;

    else
    {
        if (n % 2 == 0)
        {
            return power(a, n / 2) * power(a, n / 2);
        }
        else
        {
            return a * power(a, n / 2) * power(a, n / 2);
        }
    }
}

int main()
{
    int a, b;
    cout << "Enter a raise to power b for calculation" << endl;
    cin >> a;
    cin >> b;
    cout << a << "^" << b << " = " << power(a, b) << endl;

    return 0;
}