#include "Graph.hpp"
#include <iostream>

using namespace std;

int main() {
    Graph g;
    
    cout << "Введите граф (количество вершин и рёбер, затем рёбра):" << endl;
    cin >> g;
    
//запуск алгоритка поиска точек сочленения 
    g.findPoints();
    
    cout << "Ответ: " << g << endl;
    
    return 0;
}
