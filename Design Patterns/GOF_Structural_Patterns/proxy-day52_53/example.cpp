#include <iostream>
using namespace std;
class Proxy
{
	public:
	Proxy(int *prow) : prow(prow) { }
	int& operator[](int j) { return prow[j]; }
	private:
	int* prow;
};
class Matrix
{
	public:
	// row major
	Matrix(int nrow, int ncol) : p(new int[nrow * ncol]), nrow(nrow), ncol(ncol)
	{
		for(int i = 0; i < nrow; ++i)
		{
			for(int j = 0; j < ncol; ++j)
			{
				p[i * ncol + j] = i * ncol + j;
			}
		}
	}
	~Matrix() { delete [] p; }
	Matrix(const Matrix&) = delete;
	Matrix& operator=(const Matrix&) = delete;
	Proxy operator[](int i) { return Proxy(p + i * ncol); }  //pointer to a row
	private:
	int* p;
	int nrow;
	int ncol;
};
int main()
{
	Matrix a(5, 4);
	cout << a[3][2] << "\n"; // a(3, 2) => write a functor
}

// proxy : reference counted string class to distinguish lvalue and rvalue usage


