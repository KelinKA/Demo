#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Проверяет существование треугольника
 * @return true, если треугольник существует, иначе false
*/
bool isValidTriangle(double a, double b, double c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

/**
 * @brief Проверяет, является ли треугольник прямоугольным
 * @return true, если треугольник прямоугольный, иначе false
*/
bool isRightTriangle(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return false;
    }

    int maxSide = max(max(a, b), c);
    if (maxSide == a)
    {
        return (pow(a, 2) == pow(b, 2) + pow(c, 2));
    }
    else if (maxSide = b)
    {
        return (pow(b, 2) == pow(a, 2) + pow(c, 2));
    }
    else
    {
        return (pow(c, 2) == pow(a, 2) + pow(b, 2));
    }
}

int main()
{
    double a, b, c;
    cout << "Введите длины сторон треугольника: ";
    cin >> a >> b >> c;

    if (!isValidTriangle(a, b, c))
    {
        cout << "Треугольник не существует или введены некорректные данные" << endl;
    }
    else if (isRightTriangle(a, b, c))
    {
        int maxSide = max(max(a, b), c);
        cout << "Треугольник является прямоугольным, гипотенуза - " << maxSide << endl;
    }
    else
    {
        cout << "Треугольник не является прямоугольным" << endl;
    }

    return 0;
}
