//
// Created by jagaj on 22/12/2022.
//
#include <math.h>
#include <stdlib.h>
#include "string_gen.h"

void string_generator(char **string_array, int strings_number){
	const char alphabet[3] = {'j', 'm', 'n'};

	int len;
	double const_a = 1000;
	double const_b = pow(500, 1.0/(double) (strings_number - 1));

	for(int i = 0; i < strings_number; i++) {
		double len_d = const_a * pow(const_b, i); // n = |_ A * B^i _|
		len = (int) len_d;
		char *string = malloc((len + 1) * sizeof(char));
		string_array[i] = string;

		int period = rand() % len + 1; // generate random period in advance
		for(int j = 0; j < period; j++) { // generate period substring
			int lett = rand() % 3;
			string[j] = alphabet[lett];
		}

		for(int k = period; k < len; k++) { // generate full string from period
			string[k] = string[k % period];
		}

		string[len] = '\0';
	}
}

void worst_string_generator(char **string_array, int strings_number){

	int len;
	double const_a = 1000;
	double const_b = pow(500, 1.0/(double) (strings_number - 1));

	for(int i = 0; i < strings_number; i++) {
		double len_d = const_a * pow(const_b, i); // n = |_ A * B^i _|
		len = (int) len_d;
		char *string = malloc((len + 1) * sizeof(char));
		string_array[i] = string;

		// string will be in "aaa...ab" format

		for(int j = 0; j < len-1; j++) {
			string[j] = 'a';
		}

		string[len-1] = 'b';
		string[len] = '\0';
	}
}
