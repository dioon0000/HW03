#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main(){
	SimpleVector<int> s(10);
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(4);
    s.push_back(5);
    s.push_back(7);
    s.push_back(6);
    s.push_back(9);
    s.push_back(10);
    s.push_back(8);
    cout << "currentSize: " << s.size() << '\n';
    cout << "currentCapacity: " << s.capacity() << '\n';
    s.sortData();
    s.push_back(20);
    cout << "currentSize: " << s.size() << '\n';
    cout << "currentCapacity: " << s.capacity() << '\n';
    s.pop_back();
    cout << "Size after pop_back: " << s.size() << '\n';
    cout << "currentCapacity: " << s.capacity() << '\n';
	return 0;
}