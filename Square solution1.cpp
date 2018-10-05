#include <iostream>
#include <assert.h> 
using namespace std;

// Предлагается использование immutable классов.
// Кажется, что исключение возможность изменения ширины и высоты объектов не нарушает ни математической, ни програмнной логики.

class Rectangle
{
public:
	const int length; 
	const int height;

	Rectangle(int _length=1, int _height=1) :length(_length), height(_height) {};

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
	Square(int side=1) : Rectangle(side,side) {};

};


int main() {
	Square e(5);
	cout << e.area() << " " << e.perimeter() << endl;
	return 0;
}