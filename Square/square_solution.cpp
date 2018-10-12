#include <iostream>
#include <assert.h> 
using namespace std;

// It is proposed to use immutable classes.
// It seems that the exclusion of the possibility of changing the width and height of objects does not violate either mathematical or software logic.

class Rectangle
{
protected:
	const int length;
	const int height;
public:
	Rectangle(int _length, int _height) :length(_length), height(_height) {};

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
	Square(int side) : Rectangle(side,side) {};
};


int main() {
	Square e(5);
	cout << e.area() << " " << e.perimeter() << endl;
	return 0;
}