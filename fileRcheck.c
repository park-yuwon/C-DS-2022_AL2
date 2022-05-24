/*
* File Name: fileRcheck.c
* Author: Park Yuwon (Jade)
* Date: 2022-05-18
*
* File Summary: File Reading Module
* Detail Description
* : This file has a "fileReader" function
*	
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#define MAX_STR 10000
#define MAX_ARR 10000

struct RANDS {
	int pos_len, ints_len, doubles_len, fixed_len;
	int* pos;
	int* ints;
	double* doubles;
	double* fixed;
} *rands;

/* Cautions: This function get int randType argument
 and save the data read from the file named "fileName"
 * Return value : true(success to write file)
 * randType value 0: pos(positive int), 1: ints(integers), 2:doubles, 3:fixed (point)
 */
bool fileReader(char* fileName, const int randType) {
	FILE* fd;
	// 1. File open as r(read) mode
	fd = fopen(fileName, "r");
	
	if (fd == NULL) {
		printf("Failed to open file adequately: ");
		printf("data can't be read.\n");
		return false;
	}
	else {
		int int_tmp;
		//float float_tmp;
		double double_tmp;

		// 2. Write data into file
		switch (randType) {
		case 0: // rand is pos(positive int)
			for (int i = 0; fscanf(fd, "%d ", &int_tmp) != EOF; i++) {
				rands->pos = (int*)malloc(rands->pos_len * sizeof(int));
				rands->pos[i] = int_tmp;
			}
			break;
		case 1: // rand is ints(integers) 
			for (int i = 0; fscanf(fd, "%d ", &int_tmp) != EOF; i++) {
				rands->ints = (int*)malloc(rands->ints_len * sizeof(int));
				rands->ints[i] = int_tmp;
			}
			break;
		case 2: // rand is doubles
			for (int i = 0; fscanf(fd, "%lf ", &double_tmp) != EOF; i++) {
				rands->doubles = (double*)malloc(rands->doubles_len * sizeof(double));
				rands->doubles[i] = double_tmp;
			}
			break;
		case 3: // rand is fixed (point)
			for (int i = 0; fscanf(fd, "%lf ", &double_tmp) != EOF; i++) {
				rands->fixed = (double*)malloc(rands->fixed_len * sizeof(double));
				rands->fixed[i] = double_tmp;
			}
			break;
		default:
			printf("Wrong rand Type\n");
			return false;
		}
	}

	// 3. Close file descriptor
	fclose(fd);
	return true;
}

/*
* arrType value 0: char*(string), 1:int, 2:float, 3:double
*/
void printa(void* arr, int len, int arrType) {
	char tmp[MAX_STR];
	int* int_arr = ((int*)arr);
	float* float_arr = ((float*)arr);
	double* double_arr = ((double*)arr);
	switch (arrType) {
	case 0: // arr is string itself
		printf("%s\n", tmp);
		break;
	case 1: // arr is int array
		for (int i = 0; i < len; i++)
			printf("%d ", int_arr[i]);
		break;
	case 2: // arr is float array
		for (int i = 0; i < len; i++)
			printf("%f ", float_arr[i]);
		break;
	case 3: // arr is double array
		for (int i = 0; i < len; i++)
			printf("%lf ", double_arr[i]);
		break;
	default:
		printf("Wrong arr Type\n");
	}
}

int main() {
	rands = (struct RANDS*)malloc(sizeof(struct RANDS));
	//int arr1[MAX_ARR] = { 0, };
	//float arr2[MAX_ARR] = { 0.0f };
	//double arr3[MAX_ARR] = { 0.0 };

	fileReader("testWfile1.txt", 0); // int to rand pos
	fileReader("testWfile1.txt", 1); // int to rand ints
	fileReader("textWfile3.txt", 2); // double to rand doubles
	fileReader("textWfile3.txt", 3); // double to rand fixed

	printa(rands->pos, rands->pos_len, 1);
	printa(rands->ints, rands->ints_len, 2);
	printa(rands->doubles, rands->doubles_len, 3);
	printa(rands->fixed, rands->fixed_len, 3);

	return 0;
}
