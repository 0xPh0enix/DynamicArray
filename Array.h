/*
	P.S � ������ ������� ������������ ������� CRT.� ������ �������� ��� ���������� Heap* ��������� ��� ��������� �� ���.�������

	������������� CRT ������ ������ ��������. 

			coded by 0xPh0enix
*/
#pragma once
#include <Windows.h>

typedef struct array_ {
	LPVOID* lpData;
	INT iSize;
	INT iCount;
} array;

VOID array_init(array*);
INT array_count(array*);
VOID array_add(array*, LPVOID);
VOID array_set(array*, INT, LPVOID);
LPVOID array_get(array*, INT);
VOID array_delete(array*, INT);
VOID array_free(array*);
