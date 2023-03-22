//
// Created by jagaj on 21/12/2022.
//
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "exec_time.h"
#include "utils.h"
#include "period.h"

double duration(struct timespec start, struct timespec end) {
	return end.tv_sec - start.tv_sec
			 + ((end.tv_nsec - start.tv_nsec ) / (double) 1000000000.0);
}
double getResolution(){
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	do {
		clock_gettime(CLOCK_MONOTONIC, &end);
	} while (duration(start, end) == 0.0);
	return duration(start, end);
}

double get_median() {
	double *timing = malloc(100 * sizeof(double ));
	for(int i = 0; i < 100; i++) {
		timing[i] = getResolution();
	}

	sort(timing, 100);
	double median = timing[50];
	free(timing);

	return median;
}

double execution_time(const char *string, int (*period)(const char *string)) {
	double min_time = get_median() * (1/0.001 + 1);
	struct timespec start, end;
	int counter = 0;
	clock_gettime(CLOCK_MONOTONIC, &start);
	do {
		period(string);
		clock_gettime(CLOCK_MONOTONIC, &end);
		counter++;
	} while (duration(start, end) < min_time);

	return duration(start, end) / counter;
}

void test_execution_time(char **strings, int strings_number, Result **naive_results, Result **smart_results) {
	for(int i = 0; i < strings_number; i++){
		int len = strlen(strings[i]);
		naive_results[i]->len = len;
		naive_results[i]->time = execution_time(strings[i], period_naive);

		smart_results[i]->len = len;
		smart_results[i]->time = execution_time(strings[i], period_smart);
		free(strings[i]);
	}
}