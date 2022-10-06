#include<iostream>

using namespace std;

class matrix
{
	int row, col;
	int **mat;
	public:
	matrix(int, int, int);
	matrix(matrix &);
    bool sumCompatible(matrix &);
    bool multiCompatible(matrix &);
	matrix add(matrix);
	matrix sub(matrix);
	matrix multiply(matrix);
    matrix operator + (matrix mat2) {return add(mat2);};
    matrix operator - (matrix mat2) {return sub(mat2);};
    matrix operator * (matrix mat2) {return multiply(mat2);};
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

matrix::matrix(matrix &obj)
{
	row = obj.row;
	col = obj.col;
	mat = new int*[row];
	for(int i = 0; i < row; i++)
	{
		mat[i] = new int [col];
	}
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			mat[i][j] = obj.mat[i][j];
		}
	}
}

bool matrix::sumCompatible(matrix &matB)
{
    if (row == matB.row && col == matB.col) return true;
    return false;
}
bool matrix::multiCompatible(matrix &matB)
{
    if (col == matB.row) return true;
    return false;
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
	cout << "dest" << endl;
	for(int i = 0; i  < row; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}

int main()
{
    int row1, col1, row2, col2, choice = 0;
    cout << "\nEnter the number of rows and columns for the first matrix: ";
    cin >> row1 >> col1;
    matrix matA(row1, col1, 1);
    cout << "\nEnter the number of rows and columns for the second matrix: ";
    cin >> row2 >> col2;
    matrix matB(row2, col2, 1);
    cout << "\nMatrix A:" << endl;
    matA.display();
    cout << "\nMatrix B:" << endl;
    matB.display();
    cout << endl;
    while (choice != 4)
    {
        cout << "\n1 -> Add these two matrices.\n2 -> Subtract matrix B from matrix A.\n3 -> Multiply these two matrices.\n4 -> Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (matA.sumCompatible(matB))
            {
                matrix matC = matA + matB;
                cout << "\nResult matrix:" << endl;
                matC.display();
                cout << endl;
            }
            else
            {
                cout << endl << "These two matrices can not be added or subtracted together." << endl;
            }
            break;
        }
        case 2:
        {
            if (matA.sumCompatible(matB))
            {
                matrix matC = matA - matB;
                cout << "\nResult matrix:" << endl;
                matC.display();
                cout << endl;
            }
            else
            {
                cout << endl << "These two matrices can not be added or subtracted together." << endl;
            }
            break;
        }
        case 3:
        {
            matA.display();
            matB.display();
            if (matA.multiCompatible(matB))
            {
                matrix matC = matA * matB;
                cout << "\nResult matrix:" << endl;
                matC.display();
                cout << endl;
            }
            else
            {
                cout << endl << "These two matrices can not be multiplied together." << endl;
            }
            break;
        }
        case 4:
            break;
        default:
            cout << endl << "Invalid Input" << endl;
            break;
        }
    }
	return 0;
}