#include "Array.h"

#include <Windows.h>
#include <stdio.h>

int main() {

	array aArray;
	array_init(&aArray);

	array_add(&aArray, _strdup("One"));
	array_add(&aArray, _strdup("Two"));
	array_add(&aArray, _strdup("Three"));

	for (INT i = 0; i < array_count(&aArray); i++)
		printf("%s\n", array_get(&aArray, i));

	array_delete(&aArray, 2);

	for (INT i = 0; i < array_count(&aArray); i++)
		printf("%s\n", array_get(&aArray, i));

	array_add(&aArray, _strdup("Added"));

	for (INT i = 0; i < array_count(&aArray); i++)
		printf("%s\n", array_get(&aArray, i));

	array_set(&aArray, 2, _strdup("Setted"));

	for (INT i = 0; i < array_count(&aArray); i++)
		printf("%s\n", array_get(&aArray, i));

	array_free(&aArray);

}
