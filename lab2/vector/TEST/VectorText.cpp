// TrimBlanksTests.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../vector/ProcessVector.h"

BOOST_AUTO_TEST_SUITE(GetNumbers_function)
   BOOST_AUTO_TEST_CASE(check_empty_numbers)
   {
    	std::string inputString = "";
		BOOST_CHECK(GetNumbers(inputString).size() == 0);
    }

   BOOST_AUTO_TEST_CASE(input_string_has_numbers_1_2_3)
   {
    	std::string inputString = "1 2 3";
		BOOST_CHECK(GetNumbers(inputString)[2] == 3);
    }

   BOOST_AUTO_TEST_CASE(check_the_size_of_the_vector)
   {
	   std::string inputString = "1 2 3 4 5 3 4";
	   BOOST_CHECK(GetNumbers(inputString).size() == 7);
   }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(GetArithmeticalMean_function)
   BOOST_AUTO_TEST_CASE(check_arithmetical_mean)
   {
    	std::string inputString = "1 2 3 4 5 3 4 2";
		std::vector<double> numbers = GetNumbers(inputString);
		BOOST_CHECK(GetArithmeticalMean(numbers) == 3);
    }
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ProcessVector_function)
   BOOST_AUTO_TEST_CASE(check_the_modified_vector_elements)
   {
    	std::string inputString = "1 2 3";
		std::vector<double> numbers = GetNumbers(inputString);
		ProcessVector(numbers);
		BOOST_CHECK(numbers[2] == 5);
    }

   BOOST_AUTO_TEST_CASE(check_floating_point_numbers)
   {
    	std::string inputString = "4 6 2 7";
		std::vector<double> numbers = GetNumbers(inputString);
		ProcessVector(numbers);
		BOOST_CHECK(numbers[2] == 10.75);
    }
BOOST_AUTO_TEST_SUITE_END()