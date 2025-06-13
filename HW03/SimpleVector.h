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
		data = other.data; //�޸� �ּҸ� �״�� ���������� (���� ����)

		/*
		�ش� �ڵ�� ���� ���� (�� data�� �ּҰ��� �ٸ���)
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
		// ������ data�� ����Ű�� �ִ� �� ������ �ʱ�ȭ ������ �ʰ� 
		// ���ο� �� ������ �ּҸ� data�� �ִ� ������� Ȯ���ϸ� �ȴ�
	}
};
#endif // !SIMPLEVECTOR_H_
