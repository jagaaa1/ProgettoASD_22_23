//
// Created by jagaj on 21/12/2022.
//

#ifndef PROGETTO_UTILS_H
#define PROGETTO_UTILS_H

#include "xlsxwriter.h"

/**
 * Struttura dati per rappresentare un risultato.
 */
typedef struct result {
	 double time;
	 int len;
} Result;

/**
 * Ordina un array di double con MergeSort.
 * @param array array da ordinare
 * @param len lunghezza array
 */
void sort(double *array, int len);

/**
 * Scrive i risultati ottenuti dai test su un documento xlsx.
 * @param results_number numero dei risultati
 * @param naive_results risultati algoritmo Naive
 * @param smart_results risultati algoritmo Smart
 * @param excel xlsx sheet su cui scrivere
 */
void write_results(int results_number, Result **naive_results, Result **smart_results, lxw_workbook *file, lxw_worksheet *sheet);

#endif //PROGETTO_UTILS_H
