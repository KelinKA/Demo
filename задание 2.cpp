#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief считывает значение из потокового ввода
 * @return значение
 */
double getValue();
 /**
  * @brief находит площадь прямоугольника
  * @param a - длинна прямоугольника
  * @param b - ширина прямоугольника
  * @return площадь фигуры 
  */
double rectagleSqare(const double a, const double b);
/**
  * @brief находит площадь треугольника
  * @param a - 1 сторона треугольника
  * @param b - 2 сторона треугольника
  * @param c - 3 сторона треугольника
  * @return площадь фигуры 
  */
double triangleSqare(const double a, const double b, const double c);
/**
  * @brief проверяет существует ли треугольник
  * @param a - 1 сторона треугольника
  * @param b - 2 сторона треугольника
  * @param c - 3 сторона треугольника
  * @return 1 если да, 0 если нет
  */
double checkTriangle(const double a, const double b, const double c);
/**
 * @brief 
 * @return 0 если выполнено успешно, 1 если нет
 */
int main()
{
    double a= getValue();
    cout << "значение а=" << a <<endl;
    double b= getValue();
    cout << "значение b=" << b <<endl;
    double c = getValue();
    cout << "значение c=" << c <<endl;
    double k = checkTriangle(a,b,c);
    if(k=1)
    {
        cout << "площадь прямоугольника со сторонами a и b=" << rectagleSqare(a, b) <<endl;
        cout << "площадь треугольника со сторонами a и b и c=" << triangleSqare(a, b, c) <<endl;
    }
   
    return 0;
}

double getValue()
{
    cout << "введите значение "<< endl;
    double value;
    cin>> value;
    if ( cin.fail())
    {
        cout << "error value" << endl;
        abort();
    }
    return value;
}
double checkTriangle(const double a, const double b, const double c)
{
    if ((a+b)<c and (b+c)<a and (a+c)<b)
    {
        cout <<"треугольник не существует"<< endl;
        abort();
    }
    else
    {
        return 0;
    }
    return 1;
}
double rectagleSqare(const double a, const double b)
{
    return a*b;
}
double triangleSqare(const double a, const double b, const double c)
{
    const double p = ((a + b +c)/2);
    return (sqrt(p*(p-a)*(p-b)*(p-c)));
}
