#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief считывает  введёные значение
 * @return поверка на существование треугольника
*/
bool isRightTriangle(double a, double b, double c);


int main()
{
double a, b, c;
cout <<"Введите длины сторон треугольника: ";
cin >> a >> b >> c;

if (isRightTriangle(a, b, c))
{
double maxSide = max(max(a, b), c);
cout << "Треугольник является прямоугольным, гипотенуза - " << maxSide << endl;
}
else
{
cout << "Треугольник не является прямоугольным или введены некорректные данные" << endl;
}

return 0;
}

bool isRightTriangle(double a, double b, double c)
{
if (a <= 0 || b <= 0 || c <= 0) 
{
return false;
}

double maxSide = max(max(a, b), c); 
if (maxSide == a)
{
return (pow(a, 2) == pow(b, 2) + pow(c, 2));
} 
else if (maxSide == b)
{
return (pow(b, 2) == pow(a, 2) + pow(c, 2));
} 
else
{
return (pow(c, 2) == pow(a, 2) + pow(b, 2));
}
}

