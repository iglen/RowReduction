#include "matrix.h"

Matrix::Matrix(vector<vector<float> > m) {
	data = m;
}

void Matrix::printMatrix() {
	for (vector<float>& row : data) {
		printf("[");
		for (float& num : row) {
			printf("%3.2f ", num);
		}
		printf("]\n");
	}
	printf("\n");
}

void Matrix::rowReduction() {
	for (int i = 0; i < data.size(); i++) {
		makeOne(i);
		zeroOut(i);
	}
	
}

void Matrix::zeroOut(int rowIndex) {
	vector<float> row = data[rowIndex];

	for (int i = 0; i < data.size(); i++) {
		if (i == rowIndex) {
			continue;
		}

		vector<float> row = data[i];
		float factor = 0 - row[rowIndex];
		data[i] = addRows(factor, i, rowIndex); 		
	}
}

void Matrix::makeOne(int rowIndex) {
	vector<float> row = data[rowIndex];
	float val = row[rowIndex];

	if (val == 0) {
		return;
	}

	data[rowIndex] = multiplyRow(1 / val, rowIndex);
}

vector<float> Matrix::multiplyRow(float factor, int rowIndex) {
	vector<float> row = data[rowIndex];

	for (float& num : row) {
		num *= factor;
	}

	return row;
}

vector<float> Matrix::addRows(float factor, int changingRowIndex, int factorRowIndex) {
	vector<float> changingRow = data[changingRowIndex];
	vector<float> factorRow = data[factorRowIndex];

	factorRow = multiplyRow(factor, factorRowIndex);
	
	for (int i = 0; i < changingRow.size(); i++) {
		changingRow[i] += factorRow[i];
	}

	return changingRow;
}
/*

Here are the steps for row reduction:

Make the current row have a 1 in its corresponding location.

Make all other items in that column a zero.

Go to next diagonal, rinse and repeat until diagonal matrix has been satisfied.


Functions for adding vectors, multiplying vectors

*/
