#pragma once
#include <iostream>
#include <iomanip>
namespace matrix
{
	template <typename T>
	class Matrix
	{

	public:
		Matrix(int rows, int cols);
		T* matrix = nullptr;
		int Rows = 0;
		int Cols = 0;

		//êîíñòðêóòîð êîïèðîâàíèÿ
		Matrix(const Matrix& matr);
		T& operator () (int i,int j);
		void Fill_matrix(const T* arr);
		const Matrix<T> operator = (const Matrix & Right);
		Matrix<T> operator + (const Matrix& Right);
		Matrix<T> operator + (const T num);
		Matrix<T> operator += (const Matrix& Right);
		Matrix<T> operator += (const T num);
		Matrix<T> operator - (const Matrix& Right);
		Matrix<T> operator - (const T num);
		Matrix<T> operator -= (const T num);
		bool operator == (const Matrix& Right);
		Matrix<T> operator * (const Matrix& Right);
		Matrix<T> operator * (const T num);
		Matrix<T> operator *= (const T num);
		Matrix<T> operator / (const Matrix& Right);
		Matrix<T> operator / (const T num);
		Matrix<T> operator /= (const T num);
		~Matrix();


	};

	//áàçîâûé êîíñòðóêòîð çàïîëíÿþùèé ìàòðèöó íîëÿìè
	template <typename T>
	inline Matrix<T>::Matrix(int rows, int cols)
	{
		Rows = rows;
		Cols = cols;
		matrix = new T[rows*cols];


		T* p = matrix;
		for (int i = 0; i < rows*cols; ++i, ++p )
			*p = 0;
	}

	//êîíñòðóêòîð êîïèðîâàíèÿ
	template<typename T>
	inline Matrix<T>::Matrix(const Matrix & matr)
	{
		Rows = matr.Rows;
		Cols = matr.Cols;
		matrix = new T[Rows*Cols];

		T* p = matrix;
		for (int i = 0; i < Rows*Cols; ++i, ++p)
			*p = matr.matrix[i];
	}

	template<typename T>
	std::ostream& operator << (std::ostream & out, const Matrix<T> & m)
	{
		for (int i = 0; i < m.Rows; ++i)
		{
			for (int j = 0; j < m.Cols; ++j)
				out << std::setw(5) << m.matrix[i*m.Cols + j];
			
			std::cout << std::endl;
		}
		out << std::endl;
		return out;
	}
	
	template<typename T>
	Matrix<T> operator+(const T num, Matrix<T> & Right)
	{
		
		Matrix<T> result(Right.Rows, Right.Cols);

		for (int i = 0; i < Right.Rows; ++i)
			for (int j = 0; j < Right.Cols; ++j)
				result.matrix[i*Right.Cols + j] = Right.matrix[i*Right.Cols + j] + num;

		return Matrix<T>(result);
	}

	template<typename T>
	 inline T& Matrix<T>::operator()(int i,int j)
	{	
		if( j < 0 || j > Cols)
			throw std::exception("wrong index");
		
		return matrix[i*Cols + j];
	}



	//çàïîëåíèå ìàòðèöû èç ìàññèâà
	template <typename T>
	void Matrix<T>::Fill_matrix(const T* arr)
	{
		T* p = matrix;
		for (int i = 0; i < Rows*Cols; ++i, ++p)
			*p = arr[i];

	}

	template<typename T>
	inline const Matrix<T> Matrix<T>::operator=(const Matrix & Right)
	{
		if (&Right != this)
		{
			if (Rows != Right.Rows || Cols != Right.Cols)
			{
				delete[] matrix;
				Rows = Right.Rows;
				Cols = Right.Cols;
				matrix = new T[Rows * Cols];
			}

			for (int i = 0; i < Rows; ++i)
				for (int j = 0; j < Cols; ++j)
					matrix[i*Cols + j] = Right.matrix[i*Cols + j];
		}

		return *this;
	}


	//ñëîæåíèå ìàòðèö
	template<typename T>
	Matrix<T> Matrix<T>::operator + (const Matrix& Right)
	{
		if (Rows != Right.Rows || Cols != Right.Cols)
			throw std::exception("Íåïðàâèëüíûå ðàçìåðû ìàòðèö");

		Matrix<T> result(Rows, Cols);

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				result.matrix[i*Cols + j] = matrix[i*Cols + j] + Right.matrix[i*Cols + j];

		return Matrix(result);
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator+(const T num)
	{
		
		Matrix<T> result(Rows, Cols);

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				result.matrix[i*Cols + j] = matrix[i*Cols + j] + num;

		return Matrix(result);
	}
	
	template<typename T>
	Matrix<T> Matrix<T>::operator += (const Matrix& Right)
	{
		if (Rows != Right.Rows || Cols != Right.Cols)
			throw std::exception("Íåïðàâèëüíûå ðàçìåðû ìàòðèö");

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				matrix[i*Cols + j] = matrix[i*Cols + j] + Right.matrix[i*Cols + j];

		return *this;
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator+=(const T num)
	{
		

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				matrix[i*Cols + j] = matrix[i*Cols + j] + num;

		return *this;
	}


	
	//âû÷èòàíèå ìàòðèö
	template<typename T>
	Matrix<T> Matrix<T>::operator - (const Matrix& Right)
	{
		if (Rows != Right.Rows || Cols != Right.Cols)
			throw std::exception("Íåïðàâèëüíûå ðàçìåðû ìàòðèö");

		Matrix<T> result(Rows, Cols);

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				result.matrix[i*Cols + j] = matrix[i*Cols + j] - Right.matrix[i*Cols + j];

		return Matrix(result);
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator-(const T num)
	{
		

		Matrix<T> result(Rows, Cols);

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				result.matrix[i*Cols + j] = matrix[i*Cols + j] - num;

		return Matrix(result);
	}

	template <typename T>
	Matrix<T> operator - (const T num, const Matrix<T>& Right)
	{
		Matrix<T> result(Right.Rows, Right.Cols);


		for (int i = 0; i < Right.Rows; ++i)
			for (int j = 0; j < Right.Cols; ++j)
				result.matrix[i*Right.Cols + j] = num - Right.matrix[i*Right.Cols + j];


		return  Matrix<T>(result);
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator-=(const T num)
	{
		

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				matrix[i*Cols + j] = matrix[i*Cols + j] - num;

		return *this;
	}


	//ñðàâíåíèå ìàòðèö
	template<typename T>
	bool Matrix<T>::operator==(const Matrix & Right)
	{
		if (Rows != Right.Rows || Cols != Right.Cols)
			throw std::exception("Íåïðàâèëüíûå ðàçìåðû ìàòðèö");

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; j++)
				if (this(i,j) != Right(i,j))
					return false;

		return true;
	}


	//ïîýëåìåíòíîå óìíîæåíèå ìàòðèö
	template<typename T>
	inline Matrix<T> Matrix<T>::operator*(const Matrix & Right)
	{
		if (Rows != Right.Rows || Cols != Right.Cols)
			throw std::exception("Íåïðàâèëüíûå ðàçìåðû ìàòðèö");

		Matrix<T> result(Rows, Cols);

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				result.matrix[i*Cols + j] = matrix[i*Cols + j] * Right.matrix[i*Cols + j];

		return Matrix(result);
	}


	

	//óìíîæåíèå íà ÷èñëî
	template<typename T>
	Matrix<T> Matrix<T>::operator*(const T num)
	{
		Matrix<T> result(Rows, Cols);


		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				result.matrix[i*Cols + j] = matrix[i*Cols + j] * num;

		return Matrix(result);
	}

	template<typename T>
	inline Matrix<T> Matrix<T>::operator*=(const T num)
	{
		

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				matrix[i*Cols + j] = matrix[i*Cols + j] * num;

		return *this;
	}


	//ïðèøëîñü âûíåñòè èç êëàññà èç-çà ïðîáëåì ñ ëèíêîâêîé
	template <typename T>
	Matrix<T> operator * (const T num, const Matrix<T>& Right)
	{
		Matrix<T> result(Right.Rows, Right.Cols);


		for (int i = 0; i < Right.Rows; ++i)
			for (int j = 0; j < Right.Cols; ++j)
				result.matrix[i*Right.Cols + j] = Right.matrix[i*Right.Cols + j]  * num;


		return  Matrix<T>(result);
	}



	//ïîýëåìåíòíîå äåëåíèå ìàòðèö
	template<typename T>
	Matrix<T> Matrix<T>::operator/(const Matrix & Right)
	{
		if (Rows != Right.Rows || Cols != Right.Cols)
			throw std::exception("Íåïðàâèëüíûå ðàçìåðû ìàòðèö");

		Matrix<T> result(Rows, Cols);

		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				result.matrix[i*Cols + j] = matrix[i*Cols + j] / Right.matrix[i*Cols + j];

		return Matrix(result);


	}

	//äåëåíèå íà ÷èñëî
	template<typename T>
	inline Matrix<T> Matrix<T>::operator/(const T num)
	{
		Matrix<T> result(Rows, Cols);
		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				result(i,j) = matrix[i*Cols + j] / num;
		
		return Matrix(result);
	}

	template <typename T>
	Matrix<T> operator / (const T num, const Matrix<T>& Right)
	{
		Matrix<T> result(Right.Rows, Right.Cols);


		for (int i = 0; i < Right.Rows; ++i)
			for (int j = 0; j < Right.Cols; ++j)
				result.matrix[i*Right.Cols + j] = num / Right.matrix[i*Right.Cols + j];


		return  Matrix<T>(result);
	}


	template<typename T>
	inline Matrix<T> Matrix<T>::operator/=(const T num)
	{
		for (int i = 0; i < Rows; ++i)
			for (int j = 0; j < Cols; ++j)
				matrix[i*Cols + j] = matrix[i*Cols + j] / num;

		return *this;
	}


	template <typename T>
	Matrix<T>::~Matrix()
	{
		delete[] matrix;
	}
}
