#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

/*
<필수 기능 구현>
- 클래스의 이름은 SimpleVector라고 합니다.
- 타입에 의존하지 않고 데이터를 받을수 있는 배열을 멤버변수로 갖습니다.
- 생성자는 아래와 같이 구현 합니다.
- 기본 생성자는 크기가 10인 배열을 만듭니다.
- 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.
- 아래와 같은 멤버함수를 구현 합니다.
- push_back  인자로 받은 원소를  맨 뒤에 추가 합니다.
  반환값은 없습니다. 배열의 크기가 꽉 찼는데 원소가 더 들어올경우 아무 동작도 하지 않습니다.
- pop_back은 벡터의 마지막 원소를 제거 합니다. 만약 제거할 원소가 없다면 아무 동작도 하지 않으며,
  인자 및 반환값은 없습니다.
- size는 인자가 없고 현재 원소의 개수를 반환합니다.
- capacity 현재 내부 배열의 크기를 반환합니다.
<도전 기능 구현>
- 복사 생성자를 구현 합니다.
- 아래 멤버함수를 추가로 변경/구현 합니다.
- push_back에서 배열의 크기가 꽉 찼는데 원소가 더 들어올경우,
  기존 배열보다 크기를 5만큼 더 늘리고 새로운 원소까지 추가됩니다.(기존에 있던 값도 유지되야 합니다.)
- resize는 정수 하나를 인자로 받습니다.
  해당 정수가 현재 배열의 크기보다 작으면 아무 동작도 하지 않습니다.
  만약 현재 배열보다 크기가 크면 해당 값만큼 크기를 재할당 합니다.(기존 원소는 그대로 있어야 합니다.)
- sortData는 내부 데이터를 정렬하는 함수 입니다.
  직접 정렬하지 않고 STL의 sort함수를 활용해서 정렬 합니다.
*/

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
		data = other.data;
		currentCapacity = other.currentCapacity;
		currentSize = other.currentSize;
	}
	~SimpleVector(){
		delete data;
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
	}
};
#endif // !SIMPLEVECTOR_H_
