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
	lengthOne = 1;
	lengthTwo = 1;
	lengthThree = 1;
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
		lengthOne = 1;
	
	if (l2 > 0)
		lengthTwo = l2;
	else
		lengthTwo = 1;

	if (l3 > 0)
		lengthThree = l3;
	else
		lengthThree = 1;
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
Circle::Circle() {
	radius = 0;
}

string Circle::getType() const {
	return "Circle";
}

double Circle::getPerimeter() const {
	return (2 * 3.14 * radius);
}

double Circle::getArea() const {
	return ( 3.14 * pow(radius, 2) );
}

void Circle::setDims(int r) {
	if (r > 0)
		radius = r;
	else
		radius = 1;
}

// Determines the larger area between the two Shape objects
// The larger area is stored in result.
// The function doesn't need to handle shapes with equal areas.
void largerArea(Shape &a, Shape &b, double *theResult)
{
	// This pointer of the base class type will allow for the calling of the derived class functions through polymorphism
	Shape *ptrA = &a;
	Shape *ptrB = &b;

	// Two new area variables are created to store the values of the getArea function from each derived shape class for comparison
	double *area1 = new double;
	*area1 = ptrA->getArea();

	double *area2 = new double;
	*area2 = ptrB->getArea();

	// QUESTION 2
	// Write your implementation of this largerArea function here.

	if (*area1 > *area2)
		*theResult = ptrA->getArea();
	else
		*theResult = ptrB->getArea();

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

	system("pause");
	return 0;
}