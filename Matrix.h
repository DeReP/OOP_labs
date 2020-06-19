#pragma once
#include <iostream>
template <typename T>
class Matrix
{

public:
	Matrix(int rows, int cols);
	T** matrix = nullptr;
	int Rows = 0;
	int Cols = 0;

	//����������� �����������
	Matrix(const Matrix& matr);

	void Fill_matrix(const T* arr);
	Matrix<T> operator + (const Matrix& Right);
	Matrix<T> operator - (const Matrix& Right);
	bool operator == (const Matrix& Right);
	Matrix<T> operator * (const Matrix& Right);
	Matrix<T> operator * (const T num);
	//friend Matrix<T> operator * (const T num, const Matrix<T>& Right);
	Matrix<T> operator / (const Matrix& Right);	
	Matrix<T> operator / (const T num);
	~Matrix(); 


};

//������� ����������� ����������� ������� ������
template <typename T>
Matrix<T>::Matrix( int rows, int cols)
{
	Rows = rows;
	Cols = cols;
	matrix = new T*[rows];

	for (int i = 0; i < rows; ++i)
		matrix[i] = new T[cols];

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			matrix[i][j] = 0;
}

//����������� �����������
template<typename T>
Matrix<T>::Matrix(const Matrix & matr)
{
	Rows = matr.Rows;
	Cols = matr.Cols;
	matrix = new T*[Rows];

	for (int i = 0; i < Rows; ++i)
		matrix[i] = new T[Cols];

	for (int i = 0; i < Rows; ++i)
		for (int j = 0; j < Cols; ++j)
			matrix[i][j] = matr.matrix[i][j];
}

//��������� ������� �� �������
template <typename T>
void Matrix<T>::Fill_matrix(const T* arr)
{
	for (int i = 0; i < Rows; ++i)
		for (int j = 0; j < Cols; ++j)
			matrix[i][j] = arr[i*Cols + j ];
	
}


//�������� ������
template<typename T>
 Matrix<T> Matrix<T>::operator + (const Matrix& Right)
{
	if (Rows != Right.Rows || Cols != Right.Cols)
		 throw std::exception("������������ ������� ������");

	Matrix<T> result(Rows,Cols);

	for (int i = 0; i < Rows; ++i)
		for (int j = 0; j < Cols; ++j)
			result.matrix[i][j] = matrix[i][j] + Right.matrix[i][j];



	return Matrix(result);	
}

 //��������� ������
 template<typename T>
 Matrix<T> Matrix<T>::operator - (const Matrix& Right)
 {
	 if (Rows != Right.Rows || Cols != Right.Cols)
		 throw std::exception("������������ ������� ������");

	 Matrix<T> result(Rows, Cols);

	 for (int i = 0; i < Rows; ++i)
		 for (int j = 0; j < Cols; ++j)
			 result.matrix[i][j] = matrix[i][j] - Right.matrix[i][j];

	 return Matrix(result);
 }

 
 //��������� ������
 template<typename T>
 bool Matrix<T>::operator==(const Matrix & Right)
 {
	 if (Rows != Right.Rows || Cols != Right.Cols)
		 throw std::exception("������������ ������� ������");

	 for (int i = 0; i < Rows; ++i)
		 for (int j = 0; j < Cols; j++)
			 if (matrix[i][j] != Right.matrix[i][j])
				 return false;

	 return true;
 }


 //������������ ��������� ������
 template<typename T>
 Matrix<T> Matrix<T>::operator*(const Matrix & Right)
 {
	 if (Rows != Right.Rows || Cols != Right.Cols)
		 throw std::exception("������������ ������� ������");

	 Matrix<T> result(Rows, Cols);

	 for (int i = 0; i < Rows; ++i)
		 for (int j = 0; j < Cols; ++j)
			 result.matrix[i][j] = matrix[i][j] * Right.matrix[i][j];

	 return Matrix(result);
 }


 /*
 ������� ��������� ������ �� ��������

 template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix&  Right)
 {
	if (Cols != Right.Rows)
		throw std::exception("������������ ������� ������");
	
	Matrix<T> result(Rows, Right.Cols);
	T** res = result.matrix;
	for (int i = 0; i < Rows; ++i)
	{
		T* r = res[i];
		for (int k = 0; k < Cols; ++k)
		{
			const T* right = Right.matrix[k];
			T th = matrix[i][k];
			for (int j = 0; j < Right.Cols; ++j)
				r[j] += th * right[j];
		}
		
	}
	
	return Matrix(result);
 }
 */

 //��������� �� �����
template<typename T>
 Matrix<T> Matrix<T>::operator*(const T num)
{
	 Matrix<T> result(Rows, Cols);


	 for (int i = 0; i < Rows; ++i)
		 for (int j = 0; j < Cols; ++j)
			 result.matrix[i][j] = matrix[i][j] * num;
			 
		 
	 return Matrix{ result };
}
 

 //�������� ������� �� ������ ��-�� ������� � ���������
 template <typename T>
 Matrix<T> operator * (const T num, const Matrix<T>& Right)
 {
	 Matrix<T> result(Right.Rows, Right.Cols);


	 for (int i = 0; i < Right.Rows; ++i)
		 for (int j = 0; j < Right.Cols; ++j)
			 result.matrix[i][j] = Right.matrix[i][j] * num;


	 return  Matrix<T>(result);
 }



//������������ ������� ������
 template<typename T>
 Matrix<T> Matrix<T>::operator/(const Matrix & Right)
 {
	 if (Rows != Right.Rows || Cols != Right.Cols)
		 throw std::exception("������������ ������� ������");

	 Matrix<T> result(Rows, Cols);

	 for (int i = 0; i < Rows; ++i)
		 for (int j = 0; j < Cols; ++j)
			 result.matrix[i][j] = matrix[i][j] / Right.matrix[i][j];

	 return Matrix(result);

	
 }

 //������� �� �����
 template<typename T>
 inline Matrix<T> Matrix<T>::operator/(const T num)
 {
	 Matrix<T> result(Rows, Cols);
	 for (int i = 0; i < Rows; ++i)
		 for (int j = 0; j < Cols; ++j)
			 result.matrix[i][j] = matrix[i][j] / num;
	 return Matrix(result);

 }
 

template <typename T>
Matrix<T>::~Matrix()
{ 
	for (int i = 0; i < Rows; ++i)
		delete[] matrix[i];

	delete[] matrix;
	
}

