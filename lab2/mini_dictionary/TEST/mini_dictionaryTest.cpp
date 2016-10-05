// TrimBlanksTests.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../mini_dictionary/mini_dictionary.h"
#include <cstdio>

BOOST_AUTO_TEST_SUITE(FindTranslation_function)
	BOOST_AUTO_TEST_CASE(search_in_an_empty_dictionary)
	{
		Dictionary dictionary;
		std::string find = "ball";
		BOOST_CHECK_EQUAL(FindTranslation(find, dictionary), "");
	}
	BOOST_AUTO_TEST_CASE(search_word_cat_in_the_dictionary)
	{
		Dictionary dictionary = { 
			{ "cat", "�����" },
			{ "ball", "���" },
			{ "meat", "����" },
		};
		std::string find = "cat";
		BOOST_CHECK_EQUAL(FindTranslation(find, dictionary), "�����");
	}
	BOOST_AUTO_TEST_CASE(are_case_independent_search_in_dictionary)
	{
		Dictionary dictionary = {
			{ "cat", "�����" },
			{ "ball", "���" },
			{ "meat", "����" },
		};
		std::string find = "BaLL";
		BOOST_CHECK_EQUAL(FindTranslation(find, dictionary), "���");
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GetDictionaryFromFile_function)
	BOOST_AUTO_TEST_CASE(get_empty_dictionary)
	{
		Dictionary dictionary;
		std::string fileName = "empty_dictionary.txt";
		BOOST_CHECK(GetDictionaryFromFile(fileName) == dictionary);
	}
	BOOST_AUTO_TEST_CASE(get_a_dictionary_with_the_words)
	{
		Dictionary dictionary = {
			{ "ball", "���" },
			{ "cat", "���" },
			{ "dog", "������" },
		};
		std::string fileName = "dictionary.txt";
		BOOST_CHECK(GetDictionaryFromFile(fileName) == dictionary);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(SaveChangesInFile_function)
	BOOST_AUTO_TEST_CASE(save_the_change_in_the_dictionary_and_check)
	{
		Dictionary dictionary;
		remove("save_changes_in_file.txt");
		std::ofstream fileDictionary("save_changes_in_file.txt");
		fileDictionary << "ball|���\n" << "catch|������\n" << "year|���\n";
		SaveChangesInFile(dictionary, "save_changes_in_file.txt");

		Dictionary dictionaryCheck = GetDictionaryFromFile("save_changes_in_file.txt");
		BOOST_CHECK(dictionary == dictionaryCheck);
	}
BOOST_AUTO_TEST_SUITE_END()