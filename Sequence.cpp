#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include "Sequence.h"

using namespace std;

Sequence::Sequence()
{
	newArr = new double[2];
	maxSize = 2;
	currentSize = 0;

} //creates an array of size 2 in dynamic memory and assigns its address to the class' double array pointer, sets maximum size to 2, and current size to 0


// obj -> 1, 2, 3, 4, 5
// newArr -> 1, 2, 3, 4, 5

Sequence::Sequence(const Sequence &obj)
{
	for (int i = 0; i < currentSize; ++i)
	{
		insert(newArr[i]);
	}

} //creates a deep copy of its constant Sequence reference parameter

Sequence::~Sequence()
{
	delete[] newArr;
} //deallocates dynamic memory associated with the object’s double (array) pointer

void Sequence::insert(double newValue)
{

	if (currentSize > maxSize)
	{
		maxSize *= 2; //double max size if array is full
	}

	newArr[currentSize] = newValue;
	
	++currentSize;

} //inserts its double parameter at the next available index; if the underlying array is full, doubles maximum size, creates an array of the new size, copies the contents of the old array to the new array, frees memory associated with the old array, and assigns new array’s address to object’s array pointer, then inserts parameter

void Sequence::insert(double oldArr[], int oldArrSize)
{
	for (int i = 0; i < oldArrSize; ++i)
	{
		insert(oldArr[i]); //utilizing existing code
	}

} //inserts the values stored in its (first) double array parameter at the end of the calling object's array – the size of the parameter array is given by its (second) integer parameter; if the calling object's underlying array is not large enough, a new array of size equal to the combined size of the parameter and the current contents should be created, and the contents of the calling object's array and the parameter copied to the new array, memory associated with the old array should be freed


int Sequence::find(double targetValue)
{
	int acc = 0; //initializing accumulator for "targetValue" appearances. Returns 0 for corner case when array is empty.

	for (int i = 0; i < currentSize; ++i)
	{
		if (newArr[i] == targetValue) //checks if each value in the array is equal to the targetValue.
		{
			++acc;
		}
	}

	return acc;
} //returns an integer equal to the number of Sequence elements whose value is equal to its double parameter

int Sequence::size()
{
	return currentSize;
} //returns an integer equal to the number of values in the calling object

double Sequence::sum()
{
	double totalSum = 0; //initializing totalSum. Returns 0 for corner case when array is empty

	for (int i = 0; i < currentSize; ++i)
	{
		totalSum += newArr[i];
	}

	return totalSum;
} // returns a double equal to the sum of the values in the calling object

double Sequence::mean()
{
	if(currentSize == 0) //checking corner case when array is empty. Otherwise, it's possible that this method tries to divide by zero.
	{
		return 0;
	}

	return sum()/currentSize;
} //returns a double equal to the average of the values in the calling object

double Sequence::median()
{
	if(currentSize == 0) //checking corner case when array is empty
	{
		return 0;
	}

	sort(newArr, newArr + currentSize); //sorting the array is necessary to find medians of array length > 2

	if (currentSize % 2 == 1) //checking if currentSize is divisible by 2 
	{
		return newArr[(currentSize - 1)/2]; //because arrays start at 0, odd sized array of length "n" as its median at position (n - 1)/2
	}

	double temp = (newArr[(currentSize/2) - 1] + newArr[currentSize/2])/2;

	cout << temp << "\n";

	return temp; //because 
} //returns a double equal to the median of the values in the calling object; you may sort the array to find the median and you may use the STL (Standard Template Library) sort function (in <algorithm> to do so.

double Sequence::stddev()
{
	int tempMean = mean(); //getting the mean to use for calculations
	double totalSumSquared = 0; 

	for (int i = 0; i < currentSize; ++i)
	{
		totalSumSquared += pow((newArr[i] - tempMean), 2); //finding the sum of each value squared
	}

	return sqrt(totalSumSquared/currentSize); //standard deviation is sqrt of variance

} //returns a double equal to the standard deviation of the values in the Sequence; the standard deviation is the square root of the average of the squared differences from the mean: sd = root(sum(difference2)/n); you may use the sqrt function in the cmath library.

Sequence Sequence::concatenate(Sequence &obj)
{
	
	//toBeReturnedObject.insert(this->newArr, this->currentSize);
	
	for (int i = 0; i < obj.currentSize; i++) {
	    cout << "obj: " << *(obj.getNewArr() + i) << endl;
	    
	}
	
	insert(obj.newArr, obj.currentSize);
	
	for(int i = 0; i < 20; ++i)
	{
	    cout << newArr[i] << endl;
	}

	return *this;


} //returns a Sequence object that contains the contents of the calling object followed by the contents of its constant Sequence reference parameter; the size of the returned object's underlying array should be the greater of 2 and the number of values stored in it

double* Sequence::getNewArr() {
	return newArr;
}

int main()
{

	cout << "test\n\n";

	Sequence test;
	
    /*

	test.insert(5);
	
	
	test.insert(69);
	
	test.insert(69);
	test.insert(42.5);
	test.insert(69);
	test.insert(269);
	test.insert(-6.9);
	test.insert(6.9);
	*/
	
	/*
	
	double temp[] = {4, 7, 10};
	
	double temp2[] = {11, 17, 19, 23};
	
	test.insert(temp, 3);
	
	test.insert(temp2, 4);
	
	*/

	
	double temp1[] = {1, 3, 5, 7, 9, 11, 13};
	
	Sequence sq1;
	sq1.insert(temp1, 7);
	
	for (int i = 0; i < 8; i++) {
		cout << "elements: " << sq1.getNewArr()[i] << endl;
	}
	
	double temp2[] = {2,4,6,7,10,12, 14, 16, 18, 20, 22, 24, 26, 28};
	
	Sequence sq2;
	sq2.insert(temp2, 14);
	
	Sequence sq3;
	sq3 = sq2.concatenate(sq1);
	
	//cout << sq3 << "\n";
    
	double* testArr = sq3.getNewArr();
	
	/*

	for (int i = 0; i < 30; i++) {
		cout << "elements: " << testArr[i] << endl;
	}
	*/

	return 0;
}
