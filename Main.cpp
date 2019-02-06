#include <iostream>
#include <sstream>

using namespace std;


template<typename T>
T square(T x) {
	return x * x;
}
template<typename T>
T square2(T x) {
	return x - x;
}


template<typename T>
class BoVector {
	T arr[10000];
	int size;
public:
	BoVector() :size(0) {}
	void push(T x) { arr[size] = x; size++; }
	T get(int i) const { return  arr[i]; }
	int getSize() const { return size; }
	void print() const {
		for (int i = 0; i < size; i++){
			cout << arr[i] << endl; 
		}
	}
};

template<typename T>
BoVector<T> operator*(const BoVector<T>& rhs1, BoVector<T>& rhs2) {
	BoVector<T> ret;
	for (int i = 0; i < rhs1.getSize(); i++) {
		ret.push(rhs1.get(i)*rhs2.get(i));
	}
	return ret;
}
template<typename T>
BoVector<T> operator-(const BoVector<T>& rhs1, BoVector<T>& rhs2) {
	BoVector<T> ret;
	for (int i = 0; i < rhs1.getSize(); i++) {
		ret.push(rhs1.get(i)-rhs2.get(i));
	}
	return ret;
}

int main() {
	
	//cout << square(5) << endl;
	//cout << square(5.5) << endl;
		
	BoVector<int> bv;
	bv.push(1);
	bv.push(2);
	bv.push(3);
	bv.push(4);
	bv.push(5);
	//bv.print();

	cout << "Print Squared bv2:" << endl;
	bv = square2(bv);
	bv.print();
	
	cout << "Print Squared bv1:" << endl;
	bv = square(bv);
	bv.print();

	
	BoVector<string> bv2;
	bv2.push("A");
	bv2.push("B");
	bv2.push("C");
	bv2.push("D");
	bv2.push("F");
	bv2.print();


}
