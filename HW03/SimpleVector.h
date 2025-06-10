#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

template <typename T>

class SimpleVector{
public:
	SimpleVector() : currentSize(0), currentCapacity(10){
		data = new T[10];
	}
	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity){
		data = new T[currentCapacity];
	}
	~SimpleVector(){
		delete data;
	}
	void push_back(const T& value){
		if(currentSize < currentCapacity)
			data[currentSize++] = value;
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
private:
	T *data;
	int currentSize;
	int currentCapacity;
	void resize(){

	}
};
#endif // !SIMPLEVECTOR_H_
