#include<iostream>

using namespace std;

template<class T>
class matrix
{
	int row, col;
	T **mat;
	public:
	matrix(int, int, int);
	matrix(matrix<T> &);
    matrix<T> operator *(matrix<T> obj2);
	void display();
	~matrix();
};

template<class T>
matrix<T>::matrix(int a, int b, int flag):row(a), col(b)
{
		if(flag)
		{
			cout << endl << "Enter values for the matrix: " << endl;
			mat = new T *[row];
			for(int i = 0; i < row; i++)
			{
				mat[i] = new T [col];
				for(int j = 0; j < col; j++)
				{
					cout << "\nEnter value ( " << i+1 << ", " << j+1 << " )\n";
					cin >> mat[i][j];
				}
			}
		}
		else
		{
			mat = new T *[row];
			for(int i = 0; i < row; i++)
			{
				mat[i] = new T [col];
			}
		}
};	

template<class T>
matrix<T>::matrix(matrix<T> &obj)
{
	row = obj.row;
	col = obj.col;
	mat = new T*[row];
	for(int i = 0; i < row; i++)
	{
		mat[i] = new T [col];
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			mat[i][j] = obj.mat[i][j];
		}
	}
};

template<class T>
matrix<T> matrix<T>::operator *(matrix<T> matB)
{
	matrix<T> multi(row, matB.col, 0);
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < matB.col; j++)
		{
			multi.mat[i][j] = 0;
		}
	}
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < matB.col; j++)
		{
			for(int k = 0; k < col; k++)
			{
				multi.mat[i][j] += mat[i][k] * matB.mat[k][j];
			}
		}
	}
	return multi;
};

template<class T>
void matrix<T>::display()
{
	for(int i = 0; i < row; i++)
	{
		cout << endl;
		for(int j = 0; j < col; j++)
		{
			cout << mat[i][j] << " ";
		}
	}
	cout << endl;	
};


template<class T>
matrix<T>::~matrix()
{
	cout << "dest" << endl;
	for(int i = 0; i  < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
};

int main()
{
    int row1, col1, row2, col2, choice = 0;
    cout << "\nUsing integer matrix: \n";
    cout << "\nUsing a 3x2 and 2x3 matrix: \n";
    matrix<int> intMatA(3, 2, 1);
    matrix<int> intMatB(2, 3, 1);
    matrix<int> intMatC = intMatA * intMatB;
	cout << "\nMatrix A:\n";
	intMatA.display();
	cout << "\nMatrix B:\n";
	intMatB.display();
	cout << "\nMatrix C:\n";
	intMatC.display();
	cout << "\nUsing float matrix: \n";
    cout << "\nUsing a 3x2 and 2x3 matrix: \n";
    matrix<float> floatMatA(3, 2, 1);
    matrix<float> floatMatB(2, 3, 1);
    matrix<float> floatMatC = floatMatA * floatMatB;
	cout << "\nMatrix A:\n";
	floatMatA.display();
	cout << "\nMatrix B:\n";
	floatMatB.display();
	cout << "\nMatrix C:\n";
	floatMatC.display();
	return 0;
}