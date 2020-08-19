#include <windows.h>
#include <stdlib.h>
#include "array.h"
#include "Memory.h"

VOID array_init(array *aArray)
{
	aArray->lpData = NULL;
	aArray->iSize = 0;
	aArray->iCount = 0;
}

INT array_count(array *aArray)
{
	return aArray->iCount;
}

VOID array_add(array *aArray, LPVOID lpElement)
{
	if (aArray->iSize == 0) {

		aArray->iSize = 10;
		aArray->lpData = (LPVOID*)malloc(sizeof(LPVOID) * aArray->iSize);

		memset(aArray->lpData, 0x0, sizeof(LPVOID) * aArray->iSize);
	}

	if (aArray->iSize == aArray->iCount) {

		aArray->iSize *= 2;
		aArray->lpData = (LPVOID*)realloc(aArray->lpData, sizeof(LPVOID) * aArray->iSize);
	}

	aArray->lpData[aArray->iCount] = lpElement;
	aArray->iCount++;
}

VOID array_set(array* aArray, INT iIndex, LPVOID lpElement)
{
	if (iIndex >= aArray->iCount) 
		return;
	
	aArray->lpData[iIndex] = lpElement;
}

LPVOID array_get(array* aArray, INT iIndex)
{
	if (iIndex >= aArray->iCount)
		return NULL;
	
	return aArray->lpData[iIndex];
}

VOID array_delete(array* aArray, INT iIndex)
{
	if (iIndex >= aArray->iCount)
		return;
	
	for (INT i = iIndex + 1, j = iIndex; i < aArray->iCount; ++i) {

		aArray->lpData[j] = aArray->lpData[i];
		++j;
	}

	aArray->iCount--;
}

VOID array_free(array *aArray)
{
	free(aArray->lpData);
}