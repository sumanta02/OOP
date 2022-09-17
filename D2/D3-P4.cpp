#include<iostream>

using namespace std;

class matrix
{
	int row, col;
	int **mat;
	public:
	matrix(int, int, int);
	matrix add(matrix);
	matrix sub(matrix);
	matrix multiply(matrix);
	void display();
	~matrix();
};

matrix::matrix(int a, int b, int flag):row(a), col(b)
{
		if(flag)
		{
			cout << endl << "Enter values for the matrix: " << endl;
			mat = new int *[row];
			for(int i = 0; i < row; i++)
			{
				mat[i] = new int [col];
				for(int j = 0; j < col; j++)
				{
					cout << "\nEnter value ( " << i+1 << ", " << j+1 << " )\n";
					cin >> mat[i][j];
				}
			}
		}
		else
		{
			mat = new int *[row];
			for(int i = 0; i < row; i++)
			{
				mat[i] = new int [col];
			}
		}
}	
matrix matrix::add(matrix matB)
{
	matrix sum(row, matB.col, 0);
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sum.mat[i][j] = mat[i][j] + matB.mat[i][j];
		}
	}
	return sum;
}

matrix matrix::sub(matrix matB)
{
	matrix Sub(row, matB.col, 0);
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			Sub.mat[i][j] = mat[i][j] - matB.mat[i][j];
		}
	}
	return Sub;
}
matrix matrix::multiply(matrix matB)
{
	matrix multi(row, matB.col, 0);
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
}

void matrix::display()
{
	for(int i = 0; i < row; i++)
	{
		cout << endl;
		for(int j = 0; j < col; j++)
		{
			cout << mat[i][j];
		}
	}
	cout << endl;	
}

matrix::~matrix()
{
    cout << "dest";
	for(int i = 0; i  < row; i++)
	{
		delete [] mat[i];
	}
	delete [] mat;
}

int main()
{
	matrix matrixA(3, 3, 1), matrixB(3, 3, 1);
	matrixA.display();
	matrixB.display();
	matrix c = matrixA.add(matrixB);
	matrix d = matrixA.sub(matrixB);
	matrix e = matrixA.multiply(matrixB);
	c.display();
	d.display();
	e.display();
	return 0;
}