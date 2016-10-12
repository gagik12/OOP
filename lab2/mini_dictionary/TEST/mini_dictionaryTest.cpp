// TrimBlanksTests.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../mini_dictionary/mini_dictionary.h"
#include <cstdio>

BOOST_AUTO_TEST_SUITE(FindTranslation_function)
	BOOST_AUTO_TEST_CASE(search_in_an_empty_dictionary)
	{
	    Dictionary dictionary = {};
		std::string find("ball");
	//	boost::optional<std::string> reference("");
		BOOST_CHECK(FindTranslation(find, dictionary).is_initialized() == false);
	}
	BOOST_AUTO_TEST_CASE(search_word_cat_in_the_dictionary)
	{
		Dictionary dictionary = { 
			{ "cat", "�����" },
			{ "ball", "���" },
			{ "meat", "����" },
		};
		std::string find = "cat";
		boost::optional<std::string> reference("�����");
		BOOST_CHECK(FindTranslation(find, dictionary) == reference);
	}
	BOOST_AUTO_TEST_CASE(are_case_independent_search_in_dictionary)
	{
		Dictionary dictionary = {
			{ "cat", "�����" },
			{ "ball", "���" },
			{ "meat", "����" },
		};
		std::string find = "BaLL";
		boost::optional<std::string> reference("���");
		BOOST_CHECK(FindTranslation(find, dictionary) == reference);
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

BOOST_AUTO_TEST_SUITE(SaveChangesToFile_function)
	BOOST_AUTO_TEST_CASE(save_the_change_in_the_dictionary_and_check)
	{
		Dictionary dictionary;
		remove("save_changes_in_file.txt");
		std::ofstream fileDictionary("save_changes_in_file.txt");
		fileDictionary << "ball|���\n" << "catch|������\n" << "year|���\n";
		SaveChangesToFile(dictionary, "save_changes_in_file.txt");

		Dictionary dictionaryCheck = GetDictionaryFromFile("save_changes_in_file.txt");
		BOOST_CHECK(dictionary == dictionaryCheck);
	}
BOOST_AUTO_TEST_SUITE_END()