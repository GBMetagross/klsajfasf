using namespace std;

class Sequence
{
	public:
		Sequence(); //creates an array of size 2 in dynamic memory and assigns its address to the class' double array pointer, sets maximum size to 2, and current size to 0

		// delete this after if you care
		double* getNewArr();

		Sequence(const Sequence &obj); //creates a deep copy of its constant Sequence reference parameter

		~Sequence(); //deallocates dynamic memory associated with the object’s double (array) pointer

		void insert(double newValue); //inserts its double parameter at the next available index; if the underlying array is full, doubles maximum size, creates an array of the new size, copies the contents of the old array to the new array, frees memory associated with the old array, and assigns new array’s address to object’s array pointer, then inserts parameter

		void insert(double oldArr[], int oldArrSize); //inserts the values stored in its (first) double array parameter at the end of the calling object's array – the size of the parameter array is given by its (second) integer parameter; if the calling object's underlying array is not large enough, a new array of size equal to the combined size of the parameter and the current contents should be created, and the contents of the calling object's array and the parameter copied to the new array, memory associated with the old array should be freed

		int find(double targetValue); //returns an integer equal to the number of Sequence elements whose value is equal to its double parameter

		int size(); //returns an integer equal to the number of values in the calling object

		double sum(); // returns a double equal to the sum of the values in the calling object

		double mean(); //returns a double equal to the average of the values in the calling object

		double median(); //returns a double equal to the median of the values in the calling object; you may sort the array to find the median and you may use the STL (Standard Template Library) sort function (in <algorithm> to do so.

		double stddev(); //returns a double equal to the standard deviation of the values in the Sequence; the standard deviation is the square root of the average of the squared differences from the mean: sd = root(sum(difference2)/n); you may use the sqrt function in the cmath library.

		Sequence concatenate(Sequence &obj); //returns a Sequence object that contains the contents of the calling object followed by the contents of its constant Sequence reference parameter; the size of the returned object's underlying array should be the greater of 2 and the number of values stored in it

	private:
		double *newArr;
		int currentSize;
		int maxSize;
};
