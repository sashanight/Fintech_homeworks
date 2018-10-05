#include <iostream>
#include <assert.h> 
using namespace std;

// ¬озможно лучше вообще отказатьс€ от наследовани€ в пользу использовани€
// абстрактного класса, который будут реализовывать классы квадрата и пр€моугольника.
// ¬ таком случае об LSP вообще не задумываемс€.

class Tetragon
{
public:
	int length;
	int height;

	virtual int getHeight() = 0;
	virtual int getLength() = 0;
	virtual void setHeight(int) = 0;
	virtual void setLength(int) = 0;

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


class Rectangle: Tetragon
{
public:
	Rectangle(int _length = 1, int _height = 1){
		this->length = _length;
		this->height = _height;
	};

	int getLength() override {
		assert(this->length > 0);
		return this->length;
	}

	int getHeight() override {
		assert(this->height > 0);
		return this->height;
	}

	void setLength(int _length) override {
		assert(_length > 0);
		this->length = _length;
	}

	void setHeight(int _height) override {
		assert(_height > 0);
		this->height = _height;
	}

};


class Square : public Tetragon
{
public:
	Square(int _side=1) {
		this->length = _side;
		this->height = _side;
	};

	int getLength() override {
		assert(this->length > 0);
		return this->length;
	}

	int getHeight() override {
		assert(this->height > 0);
		return this->height;
	}

	void setLength(int _side) override {
		assert(_side > 0);
		this->length = _side;
		this->height = _side;
	}

	void setHeight(int _side) override {
		assert(_side > 0);
		this->height = _side;
		this->length = _side;
	}
};


int main() {
	Rectangle a;
	Square b;
	return 0;
}