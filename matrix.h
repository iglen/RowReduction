#include <iostream>
#include <vector>

typedef std::vector<float>      MatrixLine;
typedef std::vector<MatrixLine> MatrixLines;

class Matrix {
	private:
		MatrixLines data;
	
	private:
		void zeroOut(int rowIndex);
		MatrixLine multiplyRow(float factor, int rowIndex);
		MatrixLine addRows(float factor, int changingRowIndex, int factorRowIndex);

	public:
		void makeOne(int rowIndex);
		Matrix(const MatrixLines& src);
		void printMatrix();
		void rowReduction();
};
