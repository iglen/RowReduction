#include "matrix.h"

int main(int argc, char** argv) {
	vector<vector<float> > things;
	
	int row, column;
	cout << "rows?" << endl;
	cin >> row;
	cout << "columns?" << endl;
	cin >> column;

	for (int i = 0; i < row; i++) {
		vector<float> yo;

		for (int j = 0; j < column; j++) {
				float x;
				cout << "Whaddya want boi?" << endl;
				cin >> x;
				yo.push_back(x);
		}
		things.push_back(yo);	
	}

	Matrix a(things);
	a.printMatrix();
	a.rowReduction();
	a.printMatrix();

	return 0;
}
