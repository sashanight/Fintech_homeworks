#include <iostream>
#include <assert.h> 
using namespace std;

class Rectangle
{
public:
	int length;
	int height;

	Rectangle(int _length, int _height) :length(_length), height(_height) {};
	void virtual setLength(int _length) {
		assert(_length > 0);
		this->length = _length;
	}
	void virtual setHeight(int _height) {
		assert(_height > 0);
		this->height = _height;
	}
	int virtual getLength() {
		assert(this->length > 0);
		return this->length;
	}
	int virtual getHeight() {
		assert(this->height > 0);
		return this->height;
	}
	int area() {
		int _area;
		_area = this->length * this->height;
		assert(_area > 0);
		return _area;
	}
	int perimeter() {
		int _perimeter;
		_perimeter = 2 * (this->height + this->length);
		assert(_perimeter > 0);
		return _perimeter;
	}
};

class Square : public Rectangle
{
public:
	Square(int _side) :Rectangle(_side, _side) {};
	void setLength(int _length) {
		this->length = _length;
		this->height = _length;
	}
	void setHeight(int _height) {
		this->length = _height;
		this->height = _height;
	}
};

int main() {

	// Проверка принципа Лисков
	Rectangle a_(3,1), b_(1,3);
	Square a(1), b(1);
	
	a.setHeight(4);
	a.setLength(5);
	b.setHeight(5);
	b.setLength(4);
	if (a.area() != b.area()) {
		cout << "LSP is violated" << endl;
	}
	// Принцип Лисков нарушается

	return 0;
}