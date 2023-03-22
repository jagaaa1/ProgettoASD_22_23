//
// Created by jagaj on 21/12/2022.
//

#ifndef PROGETTO_EXEC_TIME_H
#define PROGETTO_EXEC_TIME_H

#include <time.h>
#include "utils.h"

/**
 * Esegue 100 volte getResolution() e restituisce la mediana per avere un valore
 * piu' rappresentativo del minimo periodo di tempo misurabile dalla CPU.
 *
 * @return minimo periodo misurabile
 */
double get_median();

/**
 * Calcola il tempo di esecuzione medio dell'algoritmo fornito in relazione alla stringa fornita
 *
 * @param string la stringa fornita
 * @param period l'algortimo fornito
 * @return tempo medio di esecuzione
 */
double execution_time(const char *string, int (*period)(const char *string));

/**
 * Registra i risultati dei test del tempo di esecuzione dei due algoritmi nei due array forniti.
 *
 * @param strings array di stringhe su cui effettuare i test
 * @param strings_number numero di stringhe in strings
 * @param naive_results array su cui registrare i risultati dell'algoritmo Naive
 * @param smart_results array su cui registrare i risultati dell'algoritmo Smart
 */
void test_execution_time(char **strings, int strings_number, Result **naive_results, Result **smart_results);
#endif //PROGETTO_EXEC_TIME_H
