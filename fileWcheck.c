/*
* File Name: fileWcheck.c
* Author: Park Yuwon (Jade)
* Date: 2022-05-18
* 
* File Summary: File Writing Module
* Detail Description
* : This file has a "fileWriter2" function
*	and it gets array of any type with int arrType number
*	so it can save the array data in adequate data type into the new text file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define MAX_STR 10000
/* Cautions: This function get 'void' array "arr" as an input (so it can hold any type such as int, float and double)
 and write it into file with name "fileName"(parameter)
 * Return value : true(success to write file) 
 * arrType value 0: char*(string), 1:int, 2:float, 3:double
 */
bool fileWriter2(char* fileName, const int arrType, const void* arr, const int len) {
	FILE* fd;
	// 1. File open as w(write) mode
	fd = fopen(fileName, "w");
	if (fd == NULL) {
		printf("Failed to open file adequately: ");
		printf("data can't be writed.\n");
		return false;
	}
	else {
		char tmp[MAX_STR]; 
		int* int_arr = ((int*)arr);
		float* float_arr = ((float*)arr);
		double* double_arr = ((double*)arr);
		// 2. Write data into file
		switch (arrType) {
		case 0: // arr is string itself
			fprintf(fd, arr);
			break;
		case 1: // arr is int array
			memset(tmp, 0, MAX_STR);
			for (int i = 0, j = 0; i < len; i++)
				j += sprintf(&tmp[j], "%d ", int_arr[i]); // save third parameter into first parameter
			fprintf(fd, tmp);
			break;
		case 2: // arr is float array
			memset(tmp, 0, MAX_STR);
			for (int i = 0, j = 0; i < len; i++)
				j += sprintf(&tmp[j], "%f ", float_arr[i]);
			fprintf(fd, tmp);
			break;
		case 3: // arr is double array
			memset(tmp, 0, MAX_STR);
			for (int i = 0, j = 0; i < len; i++)
				j += sprintf(&tmp[j], "%lf ", double_arr[i]);
			fprintf(fd, tmp);
			break;
		default:
			printf("Wrong arr Type\n");
			return false;
		}
		printf("File %s opened in writing mode successfully \n\n", fileName);
	}
	// 3. Close file descriptor then the file is saved as fileName.
	fclose(fd);
	return true;
}

int main() {
	int arr1[] = { 1, 2, 3, 4, 5 };
	int len1 = sizeof(arr1) / sizeof(int);
	fileWriter2("testWfile1.txt", 1, arr1, len1);
	float arr2[] = { 0.1f, 0.2f, 0.3f, 0.4f, 0.5f };
	float len2 = sizeof(arr2) / sizeof(float);
	fileWriter2("testWfile2.txt", 2, arr2, len2);
	double arr3[] = { 0.1, 0.2, 0.3, 0.4, 0.5 };
	double len3 = sizeof(arr3) / sizeof(double);
	fileWriter2("testWfile3.txt", 3, arr3, len3);

	return 0;
}
