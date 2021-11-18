#include <iostream>
#include <math.h>
using namespace std;

double sumN(double, int, double&);
double sumE(double, double, int&);

int  i, y, N, L;
double x, F, f, sum, P, compare, E;
int main()
{
    setlocale(0, "");
    cout << "Если вы хотите воспользоваться программой, введите '1', '0' для выхода." << endl;
    cin >> L;
    while (L != 1 && L != 0)
    {
        cout << "Если вы хотите воспользоваться программой, введите '1', '0' для выхода." << endl;
        cin >> L;
    }
    if (L == 1)
    {
        cout << "Задание 1" << endl;
        cout << "Введите x ((-1;1) и неравный 0 или 1): " << endl;
        cin >> x;
        while (x == 0 || x == 1 || x > 1 || x < -1)
        {
            cout << "Некорректное число" << endl;
            cin >> x;
        }
        cout << "Введите количество слагаемых (N): " << endl;
        cin >> N;
        while (N == 0 || N < 1)
        {
            cout << "Некорректное число, попробуйте значение больше нуля" << endl;
            cin >> N;
        }
        F = log((1 + x) / (1 - x));
        cout << "Ваша функция: " << F << endl;
        sum = sumN(x, N, P);
        cout << "Частичная сумма ряда: " << 2 * sum << endl;
        cout << "Абсолютная погрешность: " << P << endl;
        compare = abs(abs(F) - abs(2 * f));
        cout << "Сравнение: " << compare << endl;

        cout << "\nЗадание 2" << endl;
        cout << "Введите x ((-1;1) и не равный 0 или 1): " << endl;
        cin >> x;
        while (x == 0 || x == 1 || x > 1 || x < -1)
        {
            cout << "Некорректное число " << endl;
            cin >> x;
        }
        cout << "Введите E (очень маленькое число(больше нуля)):" << endl;
        cin >> E;
        while (E == 0 || E < 0)
        {
            cout << "Некорректное число " << endl;
            cin >> E;
        }
        F = log((1 + x) / (1 - x));
        cout << "Ваша функция: " << F << endl;
        sum = sumE(x, E, N);
        cout << "Количество слагаемых: " << N << endl;
        cout << "Сумма слагаемых: " << 2 * sum << endl;
        sum = sumE(x, E / 10, N);
        cout << "Количество слагаемых (при E, уменьшенной в 10 раз): " << N << endl;
        cout << "Сумма слагаемых (при E, уменьшенной в 10 раз): " << 2 * sum << endl;
    }

    else
        return 0;
}

double sumN(double x, int N, double& P)
{
    y = 1;
    double ch = x;
    for (i = 0; i != N; i++)
    {
        f = ch / y; 
        y += 2;
        sum += f;
        ch *= x * x;
    }
    P = F - 2 * sum;

    return sum;
}


double sumE(double x, double E, int& N)
{
    y = 1;
    N = 0;
    sum = 0;
    double ch=x;
    do
    {
        f = ch / y;
        y += 2;
        sum += f;
        ch *= x * x;
        P = F - 2 * sum;
        if (E < P)
        {
            N++;
        }
        else
        {
            sum -= f;
            break;
        }
    } while (E < P);

    return sum;
}


