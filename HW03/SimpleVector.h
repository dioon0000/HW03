#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector{
public:
	SimpleVector() : currentSize(0), currentCapacity(10){
		data = new T[10];
	}
	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity){
		data = new T[currentCapacity];
	}
	SimpleVector(const SimpleVector& other){
		data = other.data; //메모리 주소를 그대로 복사해줬음 (얕은 복사)

		/*
		해당 코드는 깊은 복사 (두 data의 주소값이 다르다)
		for(int i=0; i<currentSize; ++i)
		{
			data[i] = other.data[i];
		}
		*/
		currentCapacity = other.currentCapacity;
		currentSize = other.currentSize;
	}
	~SimpleVector(){
		delete[] data;
	}
	void push_back(const T& value){
		if(currentSize < currentCapacity)
			data[currentSize++] = value;
		else{
			resize(currentCapacity+=5);
			data[currentSize++] = value;
		}
	}
	void pop_back(){
		if(currentSize > 0)
			data[currentSize--];
	}
	int size(){
		return currentSize;
	}
	int capacity(){
		return currentCapacity;
	}
	void sortData(){
		sort(data, data+currentSize);
		cout << "sorted Value : ";
		for(int i=0; i<size(); ++i){
			cout << data[i] << ' ';
		}
		cout << '\n';
	}
private:
	T *data;
	int currentSize;
	int currentCapacity;
	void resize(int newCapacity){
		data = new T[newCapacity]; 
		// 기존에 data가 가리키고 있던 힙 공간은 초기화 해주지 않고 
		// 새로운 힙 공간의 주소를 data에 넣는 행위라고 확인하면 된다
	}
};
#endif // !SIMPLEVECTOR_H_
