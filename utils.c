//
// Created by jagaj on 21/12/2022.
//
#include <stdlib.h>
#include "xlsxwriter.h"

#include "utils.h"

void merge(double *array, int left, int right, int m, int len) {
	double *b_array = malloc(len * sizeof(double));
	int i = left;
	int j = m;
	for(int k = left; k < right; k++) {
		if(i == m) {
			b_array[k] = array[j];
			j++;
		} else if(j == right) {
			b_array[k] = array[i];
			i++;
		} else if(array[i] <= array[j]) {
			b_array[k] = array[i];
			i++;
		} else if(array[i] > array[j]) {
			b_array[k] = array[j];
			j++;
		}
	}

	for(int h = left; h < right; h++) {
		array[h] = b_array[h];
	}

	free(b_array);
}

void merge_sort(double *array, int left, int right, int len) {
	if(left < right - 1) {
		int m = (left + right) / 2;
		merge_sort(array, left, m, len);
		merge_sort(array, m, right, len);
		merge(array, left, right, m, len);
	}
}

void sort(double *array, int len) {
	merge_sort(array, 0, len, len);
}

void write_results(int results_number, Result **naive_results, Result **smart_results, lxw_workbook *file, lxw_worksheet *sheet) {
	worksheet_write_string(sheet, 0, 0, "Naive", NULL);
	worksheet_write_string(sheet, 0, 3, "Smart", NULL);

	worksheet_write_string(sheet, 1, 0, "n", NULL);
	worksheet_write_string(sheet, 1, 1, "T(n)", NULL);

	worksheet_write_string(sheet, 1, 3, "n", NULL);
	worksheet_write_string(sheet, 1, 4, "T(n)", NULL);

	for(int i = 0; i < results_number; i++) {
		worksheet_write_number(sheet, i+2, 0, naive_results[i]->len, NULL);
		worksheet_write_number(sheet, i+2, 1, naive_results[i]->time, NULL);

		worksheet_write_number(sheet, i+2, 3, smart_results[i]->len, NULL);
		worksheet_write_number(sheet, i+2, 4, smart_results[i]->time, NULL);
	}

	// Crea il grafico
	lxw_chart *chart = workbook_add_chart(file, LXW_CHART_SCATTER);
	chart_axis_set_name(chart_axis_get(chart, LXW_CHART_AXIS_TYPE_X), "n");
	chart_axis_set_name(chart_axis_get(chart, LXW_CHART_AXIS_TYPE_Y), "T(n)");

	lxw_chart_series *naive = chart_add_series(chart, NULL, NULL);
	chart_series_set_name(naive, "Naive");
	chart_series_set_categories(naive, "Sheet1", 2, 0, results_number+1, 0);
	chart_series_set_values(naive, "Sheet1", 2, 1, results_number+1, 1);

	lxw_chart_series *smart = chart_add_series(chart, NULL, NULL);
	chart_series_set_name(smart, "Smart");
	chart_series_set_categories(smart, "Sheet1", 2, 3, results_number+1, 3);
	chart_series_set_values(smart, "Sheet1", 2, 4, results_number+1, 4);

	worksheet_insert_chart(sheet, CELL("H6"), chart);
}