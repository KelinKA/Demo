#include <cmath>
#include <iostream>
using namespace std;

/**
 * @brief считывает значение из потокового ввода
 * @return ввод значения
 */
double getValue();
 /**
  * @brief 
  * return площадь фигуры 
  */
double rectagleSqare(const double a, const double b);
/**
  * @brief 
  * return площадь фигуры 
  */
double triangleSqare(const double a, const double b, const double c);

int main()
{
    double a= getValue();
    cout << "значение а=" << a <<endl;
    double b= getValue();
    cout << "значение b=" << b <<endl;
    double c = getValue();
    cout << "значение c=" << c <<endl;
    cout << "площадь прямоугольника со сторонами a и b=" << rectagleSqare(a, b) <<endl;
    cout << "площадь треугольника со сторонами a и b и c=" << triangleSqare(a, b, c) <<endl;
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
 double rectagleSqare(const double a, const double b)
 {
     return a*b;
 }
 double triangleSqare(const double a, const double b, const double c)
 {
    const double p = ((a + b +c)/2);
    return (sqrt(p*(p-a)*(p-b)*(p-c)));
 }