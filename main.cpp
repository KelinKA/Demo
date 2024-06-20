#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Проверяет существование треугольника
 * @return true, если треугольник существует, иначе false
*/
bool isValidTriangle(const double a, const  double b, const double c);
/**
 * @brief Проверяет, является ли треугольник прямоугольным
 * @return true, если треугольник прямоугольный, иначе false
*/
double findHypotenuse( const double a, const double b, const double c);
/**
 * @brief считывает значение из потокового ввода
 * @return возвращает введенное значение
 */
double getValue();
/**
  * @brief точка входа в программу 
  * return возвращает 0 в случае успешного завершения программы
  */

int main()
{
double a = getValue();
cout << "значение а=" << a << endl;
double b = getValue();
cout << "значение b=" << b << endl;
double c = getValue();
cout << "значение c=" << c << endl;

    if (!isValidTriangle(a, b, c))
    {
        cout << "Треугольник не существует или введены некорректные данные" << endl;
    
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else
    {
        double hypotenuse = findHypotenuse(a, b, c);
        if (hypotenuse != 0)
        {
            cout << "Треугольник является прямоугольным, гипотенуза - " << hypotenuse << endl;
        }
        else
        {
            cout << "Треугольник не является прямоугольным" << endl;
        }
    }

    return 0;
}
}
bool isValidTriangle(double a, double b, double c)
{
    return (a + b > c) && (a + c > b) && (b + c > a);
}

double getValue()
{
cout << "введите значение: ";
double value;
cin >> value;
if (cin.fail() || value <= 0)
{
cout << "Ошибка ввода значения." << endl;
abort();
}
return value;
}

double findHypotenuse(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    
    double maxSide = max(max(a, b), c);
    if (maxSide == a)
    {
        return sqrt(pow(b, 2) + pow(c, 2));
    }
    else if (maxSide == b)
    {
        return sqrt(pow(a, 2) + pow(c, 2));
    }
    else
    {
        return sqrt(pow(a, 2) + pow(b, 2));
    }
}
    }
}
