#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
using namespace std;
/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};
/**
 * @brief считывает значение типа int
 * @return считанное значение
 */
int getValue();
/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int** arr, int const rows, int const cols, int const min, int const max);

/**
 * @brief Выводит массив на экран
 * @param arr - массив
 * @param n - кол-во строк
 * @param m - кол-во столбцов
 */
void printArray(int** arr, int const n, int const m);

/**
 * @brief заменяет минимальные абсолютные значения на нули.
 * @param arr - массив
 * @param n - размер массива
 * @param m - кол-во столбцов
 */
void replaceMin(int** arr, int const n, int const m);

/**
 * @brief заменяет минимальные абсолютные значения на нули.
 * @param arr - массив
 * @param arr3 - массив, полученный в ходе работы функции
 * @param n - размер массива
 * @param m - кол-во столбцов
 */
void deleteCols(int** arr, int** arr3, int const rows, int const cols);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillRandom(int** arr, int const rows, int const cols, int const min, int const max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void check(int const min, int const max);

/**
 * @brief проверяет правильность введенного размера массива.
 * @param n - размер массива
 */
void checkN(int const n);

/**
 * @brief проверяет диапазон
 * @param arr - массив
 * @param rows - кол-во строк
 */
void delArr(int** arr, int const rows);

/**
 * @brief возвращает количество столбцов удовлетворяющих условию.
 * @param arr - массив
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - кол-во столбцов удовлетворяющих условию
 */
int getNumberOfCols(int** arr, int const rows, int const cols);

/**
 * @brief копирует массив.
 * @param arr - массив
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - скопированный массив
 */
int** copyArray(int** arr, int const rows, int const cols);

/**
 * @brief создает новый массив.
 * @param rows - кол-во строк массива
 * @param cols - кол-во столбцов массива
 * @return - новый массив
 */
int** getNewArray(int const rows, int const cols);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main() {
    setlocale(LC_ALL, "rus");
    cout << "Введите количество строк в массиве: ";
    int rows = getValue();
    checkN(rows);
    cout << "Введите количество столбцов в массиве: ";
    int cols = getValue();
    checkN(cols);
    int** arr = getNewArray(rows, cols);
    cout << "Введите минимальное и максимальное значения диапазона: " << endl;
    int minValue = getValue();
    int maxValue = getValue();
    check(minValue, maxValue);
    cout << "Введите свой выбор для заполнения массива: " << endl
        << RANDOM << " для случайного заполнения" << endl
        << MANUALLY << " для заполнения вручную" << endl;
    int choice = getValue();
    switch ((enum SELECT)choice)
    {
    case RANDOM:
        fillRandom(arr, rows, cols, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, rows, cols, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        return 1;
    }

    cout << "Исходный массив:" << endl;
    printArray(arr, rows, cols);
    int** arr2 = copyArray(arr, rows, cols);
    replaceMin(arr2, rows, cols);

    cout << "Массив после замены минимального количества абсолютных элементов нулями:" << endl;
    printArray(arr2, rows, cols);
    delArr(arr2, rows);

    int newcols = cols - getNumberOfCols(arr, rows, cols);
    int** arr3 = getNewArray(rows, newcols);
    deleteCols(arr, arr3, rows, cols);//Копируем в arr3 если удовлетворяет условию 

    cout << "Массив после удаления столбцов, где первый элемент больше последнего:" << endl;
    printArray(arr3, rows, newcols);
    delArr(arr3, rows);


    delArr(arr, rows);
    return 0;
}
int getValue()
{
    int value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Ошибка";
        abort();
    }
    return value;
}
void fillArray(int** arr, int const rows, int const cols, int const min, int const max)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            cout << "Введите значение для элемента[" << i << "][" << j << "]: ";
            arr[i][j] = getValue();
        }
    }
}
void printArray(int** arr, int const n, int const m) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            cout << setw(4);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void replaceMin(int** arr, int const n, int const m) {
    for (size_t j = 0; j < m; j++) {
        int minIndex = 0;
        for (size_t i = 1; i < n; i++) {
            if (abs(arr[i][j]) < abs(arr[minIndex][j])) {
                minIndex = i;
            }
        }
        arr[minIndex][j] = 0;
    }
}

void deleteCols(int** arr, int** arr3, int const rows, int const cols) {
    int newCols = 0;
    for (size_t j = 0; j < cols; j++) {
        if (arr[0][j] <= arr[rows - 1][j]) {
            for (size_t i = 0; i < rows; i++) {
                arr3[i][newCols] = arr[i][j];
            }
            newCols++;
        }
    }
}
void fillRandom(int** arr, int const rows, int const cols, int const min, int const max)
{
    srand(time(0));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % (max - min) + min;
        }
    }
}
void check(int const min, int const max)
{
    if (min >= max)
    {
        cout << "Введен неправильный диапазон: " << endl;
        abort();
    }
}
void checkN(int n)
{
    if (n <= 0)
    {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

int** getNewArray(int const rows, int const cols)
{
    int** arr = new int* [rows];
    for (size_t i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    return arr;
}

int** copyArray(int** arr, int const rows, int const cols)
{
    int** newArr = getNewArray(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            newArr[i][j] = arr[i][j];
        }
    }
    return newArr;
}

void delArr(int** arr, int const rows)
{
    for (size_t i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

int getNumberOfCols(int** arr, int const rows, int const cols)
{
    int count = 0;
    for (size_t j = 0; j < cols; j++)
    {
        if (arr[0][j] > arr[rows - 1][j])
        {
            count++;
        }
    }
    return count;
}
