#include <iostream>
using namespace std;

class Matrix
{
	unsigned int row_size;
	unsigned int col_size;
	int** mtr;

public:
	unsigned int get_row_size()const
	{
		return row_size;
	}
	unsigned int get_col_size()const
	{
		return col_size;
	}

	int** get_mtr()const
	{
		return mtr;
	}


	Matrix(unsigned int row_size = 3, unsigned int col_size =3 )
	{
		
		this->row_size = row_size;
		this->col_size = col_size;
		this->mtr = new int*[row_size] {};
		for (int i = 0; i < row_size; i++) mtr[i] = new int[col_size] {};
		cout << "DefaultConstructor:\t" << this << endl;
		int arr[] = { 1,2,3,4,5,6,7,8,9 };
		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < col_size; j++)
			{
				mtr[i][j] = arr[i*col_size+j];
			}

			}
	}

	Matrix(int row_size, int col_size, const int* other)
	{
		//while (str[size++]);
		this->row_size = row_size;
		this->col_size = col_size;
		this->mtr = new int*[row_size] {};
		for (int i = 0; i < row_size; i++) mtr[i] = new int[col_size] {};
		cout << "1argConstructor: \t" << this << endl;
		for (int i = 0; i < row_size; i++)
		{
			for (int j = 0; j < col_size; j++)
			{
				mtr[i][j] = other[i*col_size + j];
			}

		}
		

	}


	~Matrix()
	{
		for (int i = 0; i < row_size; i++) delete[] this->mtr[i];
		delete[] this->mtr;// указатель на указатель, [] говорить что удалить нужно масив
		cout << "Destructor:\t" << this << endl;

	};

	// Methods

	void print()const
	{
		cout << "Row_size:\t" << row_size << endl;
		cout << "Col_size:\t" << col_size << endl;
		cout << "Mtr:\t" << endl;
		for (int i = 0; i < row_size; i++) 
		{ for( int j =0; j<col_size; j++) cout << this->mtr[i][j] << "\t";
		cout << endl;
		} 

		cout << endl;
	}
	

	

};

ostream& operator<<(ostream& os, const Matrix& obj)
{
	return os << obj.get_mtr();
}

void main() {
//TODO:
//–еализовать класс Matrix, описывающий матрицу.
//ќбеспечить операции над матрицами + -*/
//Ќаписать метод ? ? ? determinant(); который вычисл€ет определитель матрицы.
	int arr[] = { 1,2,3,4};
	Matrix M(2,2,arr);
	M.print();
	//cout << M;


 }

