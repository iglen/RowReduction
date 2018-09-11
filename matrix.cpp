#include "matrix.h"
#include <algorithm>

using namespace std;

Matrix::Matrix(const Rows& src) {
	data = src;
}

void Matrix::printMatrix() {
	for (const Row& row : data) {
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
	for (int i = 0; i < data.size(); i++) {
		if (i == rowIndex) {
			continue;
		}

		const Row& row = data[i];
		float factor = 0 - row[rowIndex];
		data[i] = addRows(factor, i, rowIndex); 		
	}
}

void Matrix::makeOne(int rowIndex) {
	const Row& row = data[rowIndex];
	float val = row[rowIndex];

	if (val == 0) {
		return;
	}

	data[rowIndex] = multiplyRow(1 / val, rowIndex);
}

Row Matrix::multiplyRow(float factor, int rowIndex) {
	Row row = data[rowIndex];

	for_each (row.first(), row.last(), [factor](float& num) {num *= factor});

	return row;
}

MatrixLine Matrix::addRows(float factor, int changingRowIndex, int factorRowIndex) {
	Row changingRow = data[changingRowIndex];
	
	Row factorRow   = multiplyRow(factor, factorRowIndex);
	
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
