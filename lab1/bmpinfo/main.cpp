#include <iostream>
#include <string>

using namespace std;

static const string EXTENSION = ".bmp";

FILE *OpenFileInBinarMode(string  FILE_NAME)
{
	FILE *file; 
	fopen_s(&file, FILE_NAME.c_str(), "r+b");
	if (file == NULL)
	{
		cout << "Error opening file!\n";
		exit(1);
	}
	return file;
}

bool IsBmpFile(string const& fileName)
{
	bool isBmpFile = true;
	int positionSearch = fileName.length() - EXTENSION.length();
	int pos = fileName.find(EXTENSION, positionSearch);
	if (pos <= 0)
	{
		isBmpFile = false;
	}
	return isBmpFile;
}


int main(/*int argc, char *argv[]*/)
{
	int argc = 2;
	if (argc != 2)
	{
		cout << "Invalid number of parameters!\n";
		return 1;
	}
	string fileName = "file.bmp";
	if (IsBmpFile(fileName))
	{
		cout << "File BMP" << endl;
		FILE *fileBmp = OpenFileInBinarMode(fileName);
		cout << "OPEN" << endl;
	}
	else
	{
		cout << "The file extension must be BMP!";
	}
	return 0;
}
