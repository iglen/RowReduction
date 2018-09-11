#include <iostream>
#include <vector>

typedef std::vector<float>      Row;
typedef std::vector<MatrixLine> Rows;

class Matrix {
	private:
		Rows data;
	
	private:
		void zeroOut(int rowIndex);
		Row multiplyRow(float factor, int rowIndex);
		Row addRows(float factor, int changingRowIndex, int factorRowIndex);

	public:
		void makeOne(int rowIndex);
		Matrix(const Rows& src);
		void printMatrix();
		void rowReduction();
};
