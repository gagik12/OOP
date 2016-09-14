#include <iostream>
#include <fstream>

typedef double Matrix3x3[3][3];
typedef double Matrix2x2[2][2];

using namespace std;

static const int MAX_SIZE = 3;

void CheckFile(ifstream & file)
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

void OutputMatrix(Matrix3x3 &matrixMinors3x3, double const& determinantMatrix3x3)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%.3f  ", matrixMinors3x3[j][i] / determinantMatrix3x3);
		}
		cout << "\n";
	}
}

double Minor(Matrix3x3 const& matrix, int & row, int & column)
{
	int minorIndexRow = 0, minorIndexColumn = 0;
	Matrix2x2 matrixMinor;
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
			matrixMinor[minorIndexRow][minorIndexColumn] = matrix[k][l];
			minorIndexRow++;
		}
		minorIndexRow = 0;
		minorIndexColumn++;
	}

	return pow(-1, (row + column)) * GetDeterminantMatrix2x2(matrixMinor);
}
//Matrix3x3 *GetTransposeMatrix(); ВОПРОС

void InverseMatrix(Matrix3x3 const& inputMatrix3x3, Matrix3x3 &inverseMatrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			inverseMatrix[i][j] = Minor(inputMatrix3x3, i, j);
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		string fileName = argv[1];
		ifstream inputFile(fileName);
		CheckFile(inputFile);

		Matrix3x3 matrix3x3;
		ReadMatrix(inputFile, matrix3x3);
		double determinant = GetDeterminantMatrix3x3(matrix3x3);
		if (determinant == 0)
		{
			cout << "Inverse matrix does not exist";
			return 1;
		}

		Matrix3x3 inverseMatrix3x3;

		InverseMatrix(matrix3x3, inverseMatrix3x3);
		OutputMatrix(inverseMatrix3x3, determinant);
	}
	else
	{
		cout << "The number of arguments must be equal to two!";
		return 1;
	}
	return 0;
}
