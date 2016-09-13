#include <iostream>
#include <fstream>

typedef double Matrix3x3[3][3];
typedef double Matrix2x2[2][2];

using namespace std;

static const int MAX_SIZE = 3;

void ÑheckFile(ifstream & file)
{
	if (!file.is_open())
	{
		cout << "File is not open";
		exit(1);
	}
}

void ReadMatrix(ifstream & inputFile, Matrix3x3 &matrix3x3)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			inputFile >> matrix3x3[i][j];
		}
	}
}

double GetDeterminantMatrix3x3(Matrix3x3 &matrix3x3)
{
	return matrix3x3[0][0] * matrix3x3[1][1] * matrix3x3[2][2] - matrix3x3[0][0] * matrix3x3[1][2] * matrix3x3[2][1]
		- matrix3x3[0][1] * matrix3x3[1][0] * matrix3x3[2][2] + matrix3x3[0][1] * matrix3x3[1][2] * matrix3x3[2][0]
		+ matrix3x3[0][2] * matrix3x3[1][0] * matrix3x3[2][1] - matrix3x3[0][2] * matrix3x3[1][1] * matrix3x3[2][0];
}

double GetDeterminantMatrix2x2(Matrix2x2 &matrix2x2)
{
	return (matrix2x2[0][0] * matrix2x2[1][1]) - (matrix2x2[1][0] * matrix2x2[0][1]);
}

void Minor(Matrix3x3 const& inputMatrix3x3, Matrix2x2 & minorMatrix, int & row, int & column)
{
	int minorIndexRow = 0, minorIndexColumn = 0;
	for (int k = 0; k < 3; k++)
	{
		if (row == k)
		{
			continue;
		}
		for (int l = 0; l < 3; l++)
		{
			if (column == l)
			{
				continue;
			}
			minorMatrix[minorIndexRow][minorIndexColumn] = inputMatrix3x3[k][l];
			//cout << minorMatrix[minorIndexRow][minorIndexColumn] << endl;
			minorIndexRow++;
		}
		minorIndexRow = 0;
		minorIndexColumn++;
	}
}

void TransformMatrixInMinors(Matrix3x3 const& inputMatrix3x3, Matrix3x3 &matrixMinors3x3)
{
	int row, column;
	double determinant;
	Matrix2x2 minorMatrix;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			row = i;
			column = j;
			Minor(inputMatrix3x3, minorMatrix, row, column);
			determinant = GetDeterminantMatrix2x2(minorMatrix);
			matrixMinors3x3[i][j] = determinant;
			cout << matrixMinors3x3[i][j] << endl;
		}
	}
}
int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		string fileName = argv[1];
		ifstream inputFile(fileName);
		ÑheckFile(inputFile);

		Matrix3x3 matrix3x3;
		ReadMatrix(inputFile, matrix3x3);
		double determinant = GetDeterminantMatrix3x3(matrix3x3);
		if (determinant == 0)
		{
			cout << "Inverse matrix does not exist"; 
			return 1;
		}

		Matrix3x3 matrixMinors3x3;
		TransformMatrixInMinors(matrix3x3, matrixMinors3x3);
	}
	else
	{
		cout << "The number of arguments must be equal to two!";
		return 1;
	}
	return 0;
}