#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void ShowContentsFile(char*);
void CheckText(char*, char*);

int main()
{
	const int N = 30;
	char fileNameText[N];

	cout << "Enter the name of your first text file, please: ";
	cin.getline(fileNameText, N, '\n');
	char fileNameWords[N];
	cout << "Enter the name of your second text file with words, please: ";
	cin.getline(fileNameWords, N, '\n');
	system("cls");
	cout << "Text" << endl;
	ShowContentsFile(fileNameText);
	cout << "Words" << endl;
	ShowContentsFile(fileNameWords);
	CheckText(fileNameText, fileNameWords);
	system("pause");
	return 0;
}
void ShowContentsFile(char* fileName)
{
	ifstream streamIn;
	streamIn.open(fileName);
	if (!streamIn.is_open())
	{
		cout << " Cannot open file " << fileName << " to read!" << endl;
		system("pause");
		exit(1);
	}
	const int N = 30;
	char String[N] = "";
	while (!streamIn.eof())
	{
		streamIn.getline(String, N, '\n');
		cout << String << endl;
	}
	streamIn.close();
}

void CheckText(char* fileNameText, char* fileNameWords) {
	const int N = 30;
	ifstream streamIn1, streamIn2;
	ofstream of("output.bin");
	streamIn1.open(fileNameText);
	streamIn2.open(fileNameWords);
	if (!streamIn1.is_open() || !streamIn2.is_open())
	{
		cout << " Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	char String1[N] = "";
	char String2[N] = "";
	while (!streamIn2.eof()) 
	{
		int count = 0;
		streamIn2 >> String2;
		while (!streamIn1.eof()) 
		{
			streamIn1 >> String1;
			if (strcmp(String1, String2) == 0)
				count++;
		}
		streamIn1.seekg(0);
		cout << String2 << ": " << count << endl;
		of << String2 << ": " << count << endl;
	}
	streamIn1.close();
	streamIn2.close();
	of.close();
}
