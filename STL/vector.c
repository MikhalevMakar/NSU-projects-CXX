#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr ={1, 2,3};
    vector<int> cArr;
    
   // cArr.reserve(5);
    cArr.assign(arr.begin(), arr.end()); // assign удаляет все существующие элементы в векторе. assign Затем либо вставляет указанный диапазон элементов из исходного вектора в вектор, либо вставляет копии нового указанного элемента значения в вектор
    
   
    cout << endl;
    cout << cArr.capacity();
    
    auto it = cArr.begin();
    cArr.emplace(it, 5);
    
    for(const auto &it : cArr) {
        cout << it << " ";
    }
    return 0;
}

