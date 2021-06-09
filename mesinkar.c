/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkar.h"
#include <stdio.h>

char CC;       
boolean EOP;    

static FILE * pita;
static int retval;

void START(char * C) { 
	/* Algoritma */
	pita = fopen(C,"r");
	ADV();
}

void ADV() {
	/* Algoritma */
	retval = fscanf(pita,"%c",&CC);
	EOP = (CC == EOF);
	if (EOP) {
              fclose(pita);
 	}
}