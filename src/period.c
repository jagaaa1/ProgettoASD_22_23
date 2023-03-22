//
// Created by jagaj on 21/12/2022.
//
#include <stdlib.h>
#include <string.h>
#include "period.h"

int period_naive(const char *string) {
	int len = strlen(string);
	for(int p = 1; p <= len; p++) {
		int valid = 1;
		for(int i = 0; i < len - p && valid; i++) {
			if(string[i] == string[i + p]) {
				valid = 1;
			} else {
				valid = 0;
			}
		}
		if(valid) {
			return p;
		}
	}
	return len;
}

int period_smart(const char *string) {
	int len = strlen(string);
	int *supporto = malloc(len * sizeof(int));
	supporto[0] = 0;
	for(int i = 1; i < len; i++) {
		int x = supporto[i - 1];
		while(x > 0 && string[x] != string[i]) {
			x = supporto[x-1];
		}
		if(string[x] == string[i]) {
			x++;
		}
		supporto[i] = x;
	}
	int supporto_len = supporto[len - 1];
	free(supporto);
	return len - supporto_len;
}