#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

/*
<�ʼ� ��� ����>
- Ŭ������ �̸��� SimpleVector��� �մϴ�.
- Ÿ�Կ� �������� �ʰ� �����͸� ������ �ִ� �迭�� ��������� �����ϴ�.
- �����ڴ� �Ʒ��� ���� ���� �մϴ�.
- �⺻ �����ڴ� ũ�Ⱑ 10�� �迭�� ����ϴ�.
- ���ڸ� �ϳ� �޴� �����ڴ� �ش� ���ڿ� �ش�Ǵ� ũ���� �迭�� ����ϴ�.
- �Ʒ��� ���� ����Լ��� ���� �մϴ�.
- push_back  ���ڷ� ���� ���Ҹ�  �� �ڿ� �߰� �մϴ�.
  ��ȯ���� �����ϴ�. �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���ð�� �ƹ� ���۵� ���� �ʽ��ϴ�.
- pop_back�� ������ ������ ���Ҹ� ���� �մϴ�. ���� ������ ���Ұ� ���ٸ� �ƹ� ���۵� ���� ������,
  ���� �� ��ȯ���� �����ϴ�.
- size�� ���ڰ� ���� ���� ������ ������ ��ȯ�մϴ�.
- capacity ���� ���� �迭�� ũ�⸦ ��ȯ�մϴ�.
<���� ��� ����>
- ���� �����ڸ� ���� �մϴ�.
- �Ʒ� ����Լ��� �߰��� ����/���� �մϴ�.
- push_back���� �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���ð��,
  ���� �迭���� ũ�⸦ 5��ŭ �� �ø��� ���ο� ���ұ��� �߰��˴ϴ�.(������ �ִ� ���� �����Ǿ� �մϴ�.)
- resize�� ���� �ϳ��� ���ڷ� �޽��ϴ�.
  �ش� ������ ���� �迭�� ũ�⺸�� ������ �ƹ� ���۵� ���� �ʽ��ϴ�.
  ���� ���� �迭���� ũ�Ⱑ ũ�� �ش� ����ŭ ũ�⸦ ���Ҵ� �մϴ�.(���� ���Ҵ� �״�� �־�� �մϴ�.)
- sortData�� ���� �����͸� �����ϴ� �Լ� �Դϴ�.
  ���� �������� �ʰ� STL�� sort�Լ��� Ȱ���ؼ� ���� �մϴ�.
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
