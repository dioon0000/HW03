//3번 과제

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector
{
private:
	T* data;
	int currentSize;
	int currentCapacity;

	void release()
	{
		delete[] data;
		data = nullptr;
	}

public:
	SimpleVector()
	{
		data = new T[10];
		currentSize = 0;
		currentCapacity = 10;
	}

	SimpleVector(int capacity)
	{
		data = new T[capacity];
		currentSize = 0;
		currentCapacity = capacity;
	}

	// 얕은 복사가 아니라 깊은 복사를 하고 싶다.
	SimpleVector(const SimpleVector& other)
	{
		currentSize = other.currentSize;
		currentCapacity = other.currentCapacity;
		
		data = new T[currentCapacity];

		for (int i = 0; i < currentSize; i++)
		{
			data[i] = other.data[i];
		}
	}

	~SimpleVector()
	{
		release();
	}

	//연산자 오버로딩
	T& operator[](int index)
	{
		return data[index];
	}

	void resize(int capacity)
	{
		if (currentCapacity > capacity)
		{
			return;
		}

		T* tempData = new T[capacity];

		for (int i = 0; i < currentSize; i++)
		{
			tempData[i] = data[i];
		}

		release();

		currentCapacity = capacity;
		data = tempData;			//일임. 그 집 이제 네꺼니까 네가 나올 때 치워라.
	}

	void push_back(const T& value)
	{
		if (currentSize >= currentCapacity)
		{
			resize(currentCapacity + 5);
		}

		data[currentSize] = value;
		++currentSize;
	}

	void sortData()
	{
		sort(data, data + currentSize);
	}

	void pop_back()
	{
		--currentSize;
	}
	
	int size() const
	{
		return currentSize;
	}

	int capacity() const
	{
		return currentCapacity;
	}
};

int main()
{
	// 힙 메모리 누수를 감지하는 코드
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	SimpleVector<int> sv1;

	sv1.push_back(5);
	sv1.push_back(6);
	sv1.push_back(7);

	sv1.pop_back();

	for (int i = 0; i < sv1.size(); ++i)
	{
		cout << "벡터 1의: " << i << "번째 요소 " << sv1[i] << endl;
	}

	cout << "벡터 1의 크기: " << sv1.size() << endl;
	cout << "벡터 1의 용량: " << sv1.capacity() << endl;

	cout << "\n==================================" << endl;
	
	// 기존의 객체로 복사 생성을 하고 싶을 수 있다.
	SimpleVector<int> sv2(sv1);

	sv2.resize(20);
	sv2.sortData();

	for (int i = 0; i < sv2.size(); ++i)
	{
		cout << "벡터 2의: " << i << "번째 요소 " << sv2[i] << endl;
	}

	cout << "벡터 2의 크기: " << sv2.size() << endl;
	cout << "벡터 2의 용량: " << sv2.capacity() << endl;
}