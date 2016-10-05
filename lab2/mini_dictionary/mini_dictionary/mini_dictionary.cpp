#include "stdafx.h"
#include "mini_dictionary.h"

using namespace std;
using namespace boost;

static const string EXIT_DICTIONARY = "...";

bool IsEmptyFile(string const&fileName)
{
	ifstream file(fileName);
	return file.peek() == ifstream::traits_type::eof();
}

Dictionary GetDictionaryFromFile(string const&dictionaryFile)
{
	Dictionary dictionary;
	if (!IsEmptyFile(dictionaryFile))
	{
		ifstream dictionaryFile(dictionaryFile);
		string buffer;
		while (getline(dictionaryFile, buffer))
		{
			vector<string> translation;
			boost::split(translation, buffer, boost::is_any_of("|"));
			dictionary.insert({ translation[0], translation[1] });
		}
	}
	return dictionary;
}

void ProcessingNewWords(string const&newWord, Dictionary &dictionary, bool &isChangesInTheDictionary)
{
	cout << ">";
	string translationNewWord;
	getline(cin, translationNewWord);
	if (!translationNewWord.empty())
	{
		dictionary.insert({ newWord, translationNewWord });
		isChangesInTheDictionary = true;
		cout << "Слово " << newWord << " сохранено в словаре как " << translationNewWord << ".\n";
	}
	else
	{
		cout << "Слово " << newWord << " проигнорировано.\n";
	}
}

string FindTranslation(string &inputWord, Dictionary const&dictionary)
{
	string findWord;
	to_lower(inputWord);
	auto iterator = dictionary.find(inputWord);
	if (iterator != dictionary.end())
	{
		findWord = iterator->second;
	}
	return findWord;
}

void SaveChangesInFile(Dictionary const& dictionary, string const& dictionaryFileName)
{
	ofstream dictionaryFile(dictionaryFileName);
	for (auto translation : dictionary)
	{
		dictionaryFile << translation.first << "|" << translation.second << "\n";
	}
}

void StartTranslation(Dictionary &dictionary, string const&dictionaryFileName)
{
	string inputWord;
	string translatedWord;
	cout << ">";
	bool isChangesInTheDictionary = false;
	while (getline(cin, inputWord) && (inputWord != EXIT_DICTIONARY))
	{
		if (!inputWord.empty())
		{
			translatedWord = FindTranslation(inputWord, dictionary);
			if (!translatedWord.empty())
			{
				cout << translatedWord << "\n";
			}
			else
			{
				cout << "Неизвестное слово " << inputWord << ". Введите перевод или пустую строку для отказа.\n";
				ProcessingNewWords(inputWord, dictionary, isChangesInTheDictionary);
			}
			cout << ">";
		}
		else
		{
			cout << ">";
		}
	}
	if (isChangesInTheDictionary)
	{
		cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
		char save;
		cin >> save;
		save = tolower(save);
		if (save == 'y')
		{
			SaveChangesInFile(dictionary, dictionaryFileName);
			cout << "Изменения сохранены. До свидания." << endl;
		}
	}
}
