#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class Shape
{
public:
	virtual string getType() const = 0;
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
};

///////////////////////////////////////////////////
// Please DO NOT change any code above this line.//
///////////////////////////////////////////////////

// QUESTION 1
// Copy the Triangle class header and implementation you wrote for question 1 here.
class Triangle : public Shape {
public:
	Triangle();
	string getType() const;
	double getPerimeter() const;
	double getArea() const;
	void setDims(int, int, int);
private:
	int lengthOne;
	int lengthTwo;
	int lengthThree;
};

// Triangle derived class implementation
Triangle::Triangle() {
	lengthOne = 0;
	lengthTwo = 0;
	lengthThree = 0;
}

string Triangle::getType() const {
	return "Triangle";
}

double Triangle::getPerimeter() const {
	return (lengthOne + lengthTwo + lengthThree);
}

double Triangle::getArea() const {
	double semi = ((lengthOne + lengthTwo + lengthThree) / 2);
	return ( sqrt( (semi * (semi - lengthOne)) * 
		(semi * (semi - lengthTwo)) * 
		(semi * (semi - lengthThree)) ));
}

void Triangle::setDims(int l1, int l2, int l3) {
	if (l1 > 0)
		lengthOne = l1;
	else
		lengthOne = 0;
	
	if (l2 > 0)
		lengthTwo = l2;
	else
		lengthTwo = 0;

	if (l3 > 0)
		lengthThree = l3;
	else
		lengthThree = 0;
}



// QUESTION 1 CONTINUED
// Copy the Circle class header and implementation you wrote for question 1 here.
class Circle : public Shape {
public:
	Circle();
	string getType() const;
	double getPerimeter() const;
	double getArea() const;
	void setDims(int);
private:
	int radius;
};

// Circle derived class implementation






// Determines the larger area between the two Shape objects
// The larger area is stored in result.
// The function doesn't need to handle shapes with equal areas.
void largerArea(Shape &a, Shape &b, double *theResult)
{
	// This pointer of the base class type will allow for the calling of the derived class functions through polymorphism
	Shape *ptrA = &a;

	// Same for B
	*theResult = ptrA->getArea();

	// QUESTION 2
	// Write your implementation of this largerArea function here.



}

///////////////////////////////////////////////////
// Please DO NOT change any code below this line.//
///////////////////////////////////////////////////

void describeShape(Shape &addressOfIncomingShape)
{
	// Notice this is a base class pointer (pointing to the
	// address of a derived class being passed in).

	Shape *ptr = &addressOfIncomingShape;

	cout << "This " << ptr->getType()
		<< " has a perimeter of: " << ptr->getPerimeter()
		<< " and an area of: " << ptr->getArea() << endl;
}

int main()
{
	double result;
	Triangle t;
	Circle c;
	c.setDims(2);
	t.setDims(3, 4, 5);

	describeShape(t);
	describeShape(c);

	largerArea(t, c, &result);
	cout << "The larger area is: " << result << endl << endl;

	t.setDims(6, 8, 10);
	describeShape(t);
	describeShape(c);
	largerArea(t, c, &result);
	cout << "The larger area is: " << result << endl;

	return 0;
}