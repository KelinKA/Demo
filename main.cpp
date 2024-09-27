#include <iostream>
#include <cmath>
using namespace std;
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
double x = getValue();
cout <<"значение х="<< x << endl;

double y = getValue();
cout <<"значение y="<< y << endl;

double z = getValue(); 
cout <<"значение z="<< z << endl;
    double a = (y * x * z * z) - (z / (sin(x / y) * sin(x / y)));
    cout << "a is: " << a << endl;

    double b = z *exp(-(sqrt(z))) * cos(y * x / z);
    cout << "b is: " << b << endl;

    return 0;
}

double getValue()
{
cout << "Введите значение: ";
double value;
cin >> value;
if (cin.fail())
{
cout << "Ошибка ввода значения." << endl;
abort();
}

return value;
}
