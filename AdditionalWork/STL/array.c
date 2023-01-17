#include <iostream>
#include <array>
using namespace std;

typedef  array<int, 3> ArrInt; // создание типа массива

int main(int argc, const char * argv[]) {
    ArrInt arr = {1, 2, 3}; // инициализация
    
    for(const auto &itPrint : arr) { // вывод массива
        cout << " " << itPrint;
    }
    
    cout << endl;
    
    cout << "arr.at(2): "<< arr.at(2) << endl; //обращение по индыксу
    
    cout << "arr.begin(): "<< arr.begin() << endl; // Задает начало управляемой последовательности
    
    cout << "arr.cbegin(): "<< arr.cbegin() << endl; // возвращает итератор const, направленный на первый элемент в диапазоне
    
    cout << "arr.back():" << arr.back() << endl; //возращает значение на последним элементом
    
    cout << "arr.end(): "<< arr.end() << endl; // возращает адресс указывающий на следующий за последним элементом
    
    ArrInt arr1 = {4, 5, 6};
    arr1.swap(arr); //обмен элементами
    
    ArrInt::const_reference ref = *arr1.begin(); // Тип постоянной ссылки на элемент
    
   
    auto it = arr.crbegin(); //Возвращает константный итератор, который указывает на первый элемент в обращенном массиве.
    cout << "arr.crbegin():"<< *it << endl;
    
    cout << "arr.front(): "<< arr.front() << endl; //Функции-члены возвращают ссылку на первый элемент управляемой последовательности, который должен быть не пустым
    
    cout << arr.max_size() << endl; // Подсчитывает количество элементов
    
    arr.fill(6); // заполнение массив
    
    return 0;
}

