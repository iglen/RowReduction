#include <iostream>
#include <vector>

using namespace std;

class Matrix {
	private:
		vector<vector<float> > data;
		void zeroOut(int rowIndex);
		vector<float> multiplyRow(float factor, int rowIndex);
		vector<float> addRows(float factor, int changingRowIndex, int factorRowIndex);

	public:
		void makeOne(int rowIndex);
		Matrix(vector<vector<float> > );
		void printMatrix();
		void rowReduction();

};
