//
// Created by jagaj on 22/12/2022.
//

#ifndef PROGETTO_STRING_GEN_H
#define PROGETTO_STRING_GEN_H

/**
 * Genera stringhe da un alfabeto {j, m, n} in modo pseudocasuale e di lunghezza compresa
 * tra 1000 e 500000 con distribuzione esponenziale.
 * @param string_array array su cui salvare le stringhe
 * @param string_number numero di stringhe da generare
 */
void string_generator(char **string_array, int string_number);

/**
 * Genera stringhe di lunghezza compresa tra 1000 e 500000 con distribuzione esponenziale
 * costruite in modo da generare il caso peggiore dell'algoritmo naive
 * @param string_array array su cui salvare le stringhe
 * @param strings_number numero di stringhe da generare
 */
void worst_string_generator(char **string_array, int strings_number);

#endif //PROGETTO_STRING_GEN_H
