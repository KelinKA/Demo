#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief считывает значение из потокового ввода
 * @return возвращает введенное значение
 */
double getValue();
 /**
  * @brief вычисляет площадь прямоугольника с заданными сторонами a и b
  * return возвращает значение площади 
  */
double rectagleSqare(const double a, const double b);
/**
  * @brief вычисляет площадь треугольника по формуле полупериметра и сторон треугольника
  * return возвращает значение площади треугольника
  */
double triangleSqare(const double a, const double b, const double c);
 /**
  * @brief проверяет существование треугольника с заданными сторонами
  * return возвращает true, если треугольник с такими сторонами существует, иначе возвращает false 
  */
bool checkTriangleExistence(const double a, const double b, const double c);
int main();





int main()
{
double a = getValue();
cout << "значение а=" << a << endl;
double b = getValue();
cout << "значение b=" << b << endl;
double c = getValue();
cout << "значение c=" << c << endl;

if (checkTriangleExistence(a, b, c))
{
    cout << "площадь прямоугольника со сторонами a и b=" << rectagleSqare(a, b) << endl;
    cout << "площадь треугольника со сторонами a и b и c=" << triangleSqare(a, b, c) << endl;
}
else
{
    cout << "Треугольник с такими сторонами не существует." << endl;
}

return 0;
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

double rectagleSqare(const double a, const double b)
{
return a * b;
}

double triangleSqare(const double a, const double b, const double c)
{
const double p = ((a + b + c) / 2);
return (sqrt(p * (p - a) * (p - b) * (p - c)));
}

bool checkTriangleExistence(const double a, const double b, const double c)
{
return a + b > c && a + c > b && b + c > a;
}
return false;
}
