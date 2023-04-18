#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "exec_time.h"
#include "string_gen.h"
#include "utils.h"
#include "xlsxwriter.h"
#include "zlib.h"

int main() {
	int test_n;
	printf("Numero di Stringhe da generare:\n");
	scanf("%d", &test_n);

	char **strings = malloc(test_n * sizeof (char *));
	string_generator(strings, test_n);

	Result **naive = malloc(test_n * sizeof(Result *));
	Result **smart = malloc(test_n * sizeof(Result *));

	for(int i = 0; i < test_n; i++) {
		naive[i] = malloc(sizeof(Result));
		smart[i] = malloc(sizeof(Result));
	}

	test_execution_time(strings, test_n, naive, smart);

	lxw_workbook *file = workbook_new("test_results.xlsx");
	lxw_worksheet *sheet = workbook_add_worksheet(file, NULL);
	lxw_worksheet *sheet2 = workbook_add_worksheet(file, NULL);

	write_results(test_n, naive, smart, file, sheet);

	worst_string_generator(strings, test_n);
	test_execution_time(strings, test_n, naive, smart);
	write_results(test_n, naive, smart, file, sheet2);

	workbook_close(file);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	printf("\nTest eseguiti con successo!\n");
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("Risultati salvati.\n");
	return 0;
}
