/*
* File   : sorting.cpp
*
* Author1: Park Yongwoo
* Author2: Yun Jaesang
* Author3: Park Yuwon
* Author4: Kim Hyekang
*
* Date   :
*
* Course: Data Structures(14461_002)
*
* Summary of this file
*      :  Implement sorting algorithms and analyze their performances.
*
* Parts 1 ~ 5
* (Only Part 1, 2 and 3 will be implemented in this "sorting.cpp" file.
* On the other hand, part 4 would be plotted in Python or R.)
*
* Part 1: Implement random input generators
* Part 2: Implement sorting algorithms
* Part 3: Implement sorting evaluators
* Part 4: Plot performance comparison graphs
* Part 5: Submit 10-minutes Video Presentation Link
*/


#include <stdio.h>
#include <stdlib.h> // rand()함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리
#include <string.h>
#include <stdbool.h>
#include <memory.h>

#define MAX_STR 10000

#define MAX_RAND_NUM 3000

struct RANDS {
    FILE* pos;
    FILE* ints;
    FILE* doubles;
    FILE* fixed; // String
} *rands;

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
        char* s_arr = ((char*)arr);
        int* int_arr = ((int*)arr);
        float* float_arr = ((float*)arr);
        double* double_arr = ((double*)arr);
        // 2. Write data into file
        switch (arrType) {
        case 0: // arr is string itself
            fprintf(fd, s_arr);
            break;
        case 1: // arr is int array
            memset(tmp, 0, MAX_STR);
            for (int i = 0, j = 0; i < len; i++)
                j += sprintf(&tmp[j], "%d ", int_arr[i]);
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

/* Cautions: This function get int randType argument
 and save the data read from the file named "fileName"
 * Return value : true(success to write file)
 * randType value 0: pos(positive int), 1: ints(integers), 2:doubles, 3:fixed (point)
 */
 /*
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
*/

bool file_w(char* filename, int size, int* arr)
{
    FILE* infile = fopen(filename, "w");
    if (infile == NULL)
    {
        printf("\n File cannot be opened\n");
        return false;
        exit(1);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(infile, " %d ", arr[i]);
        }
    }
    fclose(infile);
    return true;
}

bool file_w_double(char* filename, int size, double* arr)
{
    FILE* infile = fopen(filename, "w");
    if (infile == NULL)
    {
        printf("\n File cannot be opened\n");
        return false;
        exit(1);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(infile, " %lf ", arr[i]);
        }
    }
}

bool file_r(char* filename, int* arr)
{
    FILE* infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("\n File cannot be opened\n ");
        exit(1);
        return false;

    }
    else
    {
        int num;
        int i = 0;

        while (fscanf(infile, "%d ", &num) != EOF)
        {
            arr[i] = num;
            i++;
        }

    }
    fclose(infile);
    return true;
}

bool file_r_double(char* filename, double* arr)
{
    FILE* infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("\n File cannot be opened\n ");
        exit(1);
        return false;

    }
    else
    {
        double num;
        int i = 0;
        while (fscanf(infile, "%lf ", &num) != EOF)
        {
            arr[i] = num;
            i++;
        }

    }
    fclose(infile);
    return true;
}

bool file_string_w(char* filename, int size, char str[][6])
{
    FILE* infile;
    infile = fopen(filename, "a");
    if (infile == NULL)
    {
        printf("file cannot be opened\n");
        exit(0);
        return false;
    }



    else
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(infile, " %s ", str[i]);
        }
        fclose(infile);
    }
    return true;
}

bool file_string_r(char* filename, char str[][6])
{
    FILE* infile;
    infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("file cannot be oepened\n");
        exit(0);
        return false;
    }

    else
    {
        char randomstr[6];
        int i = 0;
        while (fscanf(infile, "%s", &str) == 1)
        {
            strcpy(str[i], randomstr);
            i++;
        }
        return true;
    }
}

void printarr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
}

void printarr_double(double* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %lf ", arr[i]);
    }
}

bool file_evaluate_w(char* filename, int size, char* sortname, int* arr)
{
    FILE* infile;
    infile = fopen(filename, "a");
    if (infile == NULL)
    {
        printf("file cannot be oepened\n");
        exit(0);
        return false;
    }

    else
    {
        fprintf(infile, "%s sort\n", sortname);

        for (int i = 0; i < size; i++)
        {
            fprintf(infile, " %d ", arr[i]);
        }
    }

    fclose(infile);
    return true;
}

bool check_correct(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("there is an error in sorting..\n");
            return false;
        }

    }
    printf("sorting success!\n");
    return true;
}



/*
 Part1: Implement the following random input generator
 Level1: positive numbers
 Level2: integers (including positives, 0, and negatives)
 Level3: double precision numbers (e.g. -1000.000 < number < +1000.000)
 Level4: fixed length strings (e.g. 5-sized characters: “abcde”, “vwxyz”)
*/
FILE* pos_rand(const int n) {
    return NULL;
}
bool i_rand(const int n) {
    return false;

}
bool d_rand(const int n) {
    return false;
}

bool fx_rand(const int n) {
    return false;
}


/*
 Part2: Implement the following sorting algorithms:
 Category1: Insertion sort, Selection sort, Bubble sort
 Category2: Merge sort, Quick sort
 Category3: Heap sort, Radix sort
*/
/*
void insertion_s() {
   int arr[] = { 12, 11, 13, 5, 6 };
   // 12 11 13 5 6
   // 11 12 13 5 6
   // 11 12 13 5 6
   // 5  11 12 13 6
   // 5  6  11 12 13
   int n = sizeof(arr) / sizeof(arr[0]);
   int i, key, j;
   for (i = 1; i < n; i++) {
      key = arr[i];
      j = i - 1;

      // Move elements of arr[0..i-1],
      // that are greater than key, to one
      // position ahead of their
      // current position
      while (j >= 0 && arr[j] > key)
      {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = key;
   }
}
void swap(int* xp, int* yp)
{
   int temp = *xp;
   *xp = *yp;
   *yp = temp;
}
void selection_s() {
   int arr[] = { 12, 11, 13, 5, 6 }, int n = sizeof(arr) / sizeof(arr[0]);
   int i, j, min_idx;

   // One by one move boundary of
   // unsorted subarray
   for (i = 0; i < n - 1; i++)
   {

      // Find the minimum element in
      // unsorted array
      min_idx = i;
      for (j = i + 1; j < n; j++)
         if (arr[j] < arr[min_idx])
            min_idx = j;

      // Swap the found minimum element
      // with the first element
      swap(&arr[min_idx], &arr[i]);
   }

}

*/
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap_double(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

void selectionSort_double(double arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap_double(&arr[min_idx], &arr[i]);
    }
}

void bubble_s(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);

}


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[MAX_RAND_NUM], R[MAX_RAND_NUM];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 함수 호출: mergeSort(arr, 0, arr_size - 1);
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
/*
int partition(int arr[], int low, int high)
{
   int pivot = arr[high]; // pivot
   int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

   for (int j = low; j <= high - 1; j++)
   {
      // If current element is smaller than the pivot
      if (arr[j] < pivot)
      {
         i++; // increment index of smaller element
         swap(&arr[i], &arr[j]);
      }
   }
   swap(&arr[i + 1], &arr[high]);
   return (i + 1);
}
void quick_s() {
   int arr[] = { 12, 11, 13, 5, 6 }, int n = sizeof(arr) / sizeof(arr[0]);
   int low = 0, int high = n - 1;

   if (low < high)
   {
      //pi is partitioning index, arr[p] is now
      //at right place
      int pi = partition(arr, low, high);

      // Separately sort elements before
      // partition and after partition
      quickSort(arr, low, pi - 1);
      quickSort(arr, pi + 1, high);
   }
}
void heap_s(FILE* fd) {

}*/

// Function to get the largest element from an array
int getMax(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
    //int output[size + 1];
    int output[MAX_RAND_NUM + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++) {
        if (((array[i] / place) % 10) > max)
            max = array[i];
    }
    //int count[max + 1];
    int count[MAX_RAND_NUM + 1];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
    // Get maximum element
    int max = getMax(array, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

/*
*
 Part3: Implement the following sorting evaluator:
 Level1: Load the generated lists from files / Save the evaluation results as separate files.
 Level2: The sorting correctness
 Level3: The running time
 Level4: The stability correctness
*/
/*
bool result_load_and_saver(FILE* in) {

}
bool sort_corrector(FILE* fd) {

}
bool running_timer(FILE* fd) {

   // add logic to measure the time clock difference
   clock_gettime(CLOCK_MONOTONIC, &finish);
   elapsed = (finish.tv_sec - start.tv_sec); // seconds
   elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0; // nanoseconds
}
bool stability_corrector(FILE* fd) {

}
*/
int main() {

    // Part 1. Create Random numbers file
    /*
    RANDS *rands;

    if (!(rands->pos = pos_rand(10000))) {
       printf("Cannot Create Positive Random numbers File\n");
       exit(1);
    }
    if (!i_rand(10000)) {
       printf("Cannot Create Integer Random numbers File\n");
       exit(1);
    }
    if (!d_rand(10000)) {
       printf("Cannot Create Double-Precision Random numbers File\n");
       exit(1);
    }
    if (!fx_rand(10000)) {
       printf("Cannot Create Fixed Length Random numbers File\n");
       exit(1);
    }
    */


    int arr[MAX_RAND_NUM];
    int minusarr[MAX_RAND_NUM];
    double doublearr[MAX_RAND_NUM];

    srand(time(NULL)); // 매번 다른 시드값 생성
    int random = 0; // 정수형 변수 선언
    double randomf = 0.0; //실수형 변수 선언

    for (int i = 0; i < MAX_RAND_NUM; i++) { // 10번 반복
        random = rand(); // 난수 생성

        arr[i] = random;
    }

    random = 0;
    for (int i = 0; i < MAX_RAND_NUM; i++)
    {
        random = rand();
        minusarr[i] = -random;

    }

    randomf = 0;
    for (int i = 0; i < MAX_RAND_NUM; i++) {
        randomf = rand();

        doublearr[i] = ((double)rand() * (2000)) / (double)RAND_MAX - 1000;
    }

    char code_str[MAX_RAND_NUM][6];

    int type;

    for (int k = 0; k < MAX_RAND_NUM; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            type = rand() % 2;
            if (type == 0)
            {
                code_str[k][i] = 'a' + rand() % 26;
            }
            else
                code_str[k][i] = 'A' + rand() % 26;

        }
        code_str[k][5] = '\0';
    }



    // File Write

    int size = sizeof(arr) / sizeof(arr[0]);

    char fname[20] = "testint.txt";
    char fname2[20] = "testminus.txt";
    char fname3[20] = "tesetdouble.txt";
    char fname4[20] = "testtext.txt";



    file_w(fname, size, arr);
    /*file_w(fname2, size, minusarr);
    file_w_double(fname3, size, doublearr);
    file_string_w(fname4, size, code_str);*/

    // File Read

    int select_pos_arr[MAX_RAND_NUM];
    int select_int_arr[MAX_RAND_NUM];
    double select_double_arr[MAX_RAND_NUM];

    /*
    int insert_pos_arr[MAX_RAND_NUM];
    int insert_int_arr[MAX_RAND_NUM];
    double insert_double_arr[MAX_RAND_NUM];

    int bubble_pos_arr[MAX_RAND_NUM];
    int bubble_int_arr[MAX_RAND_NUM];
    double bubble_double_arr[MAX_RAND_NUM];

    int merge_pos_arr[MAX_RAND_NUM];
    int merge_int_arr[MAX_RAND_NUM];
    double merge_double_arr[MAX_RAND_NUM];

    int quick_pos_arr[MAX_RAND_NUM];
    int quick_int_arr[MAX_RAND_NUM];
    double quick_double_arr[MAX_RAND_NUM];

    int heap_pos_arr[MAX_RAND_NUM];
    int heap_int_arr[MAX_RAND_NUM];
    double heap_double_arr[MAX_RAND_NUM];

    int radix_pos_arr[MAX_RAND_NUM];
    int radix_int_arr[MAX_RAND_NUM];
    double radix_double_arr[MAX_RAND_NUM];

    char newcodestr[MAX_RAND_NUM][6];

    */
    double start, end;
    start = (double)clock() / CLOCKS_PER_SEC;

    selectionSort(select_pos_arr, size);

    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("프로그램 수행 시간 :%lf\n", (end - start));


    selectionSort(select_pos_arr, size);
    selectionSort(select_int_arr, size);
    selectionSort_double(select_double_arr, size);

    check_correct(select_pos_arr, size);
    file_r(fname, select_pos_arr);
    file_r(fname2, select_int_arr);
    file_r_double(fname3, select_double_arr);

    //file_r(fname, insert_pos_arr);
    //file_r(fname2,insert_int_arr);
    //file_r_double(fname3, insert_double_arr);

    //file_r(fname, bubble_pos_arr);
    //file_r(fname2,bubble_int_arr);
    //file_r_double(fname3, bubble_double_arr);

    //file_r(fname, merge_pos_arr);
    //file_r(fname2, merge_int_arr);
    //file_r_double(fname3, merge_double_arr);

    //file_r(fname, quick_pos_arr);
    //file_r(fname2, quick_int_arr);
    //file_r_double(fname3, quick_double_arr);

    //file_r(fname, heap_pos_arr);
    //file_r(fname2, heap_int_arr);
    //file_r_double(fname3, heap_double_arr);

    //file_string_r(fname4, newcodestr);



    /*
    printf("1-1. Print newarr \n");
    printarr(newarr, size);
    printf("\n1-2. Print newminusarr \n");
    printarr(newminusarr, size); // 0 ~ 음수
    printf("\n1-3. Print newdoublearr \n");
    printarr_double(newdoublearr, size);
    */

    // Part 2. Sort algorithms

    /*insertion_s();
    selection_s();
    bubble_s();
    merge_s();
    quick_s();
    heap_s();
    radix_s();*/



    //selectionSort(newcodestr,size); 문자열(level4)요거 정렬 함수 짜야댐


    /*
    printf("2-1. Print sorted newarr \n");
    printarr(newarr, size);
    printf("\n2-2. Print sorted newminusarr \n");
    printarr(newminusarr, size); // 0 ~ 음수
    printf("\n2-3. Print sorted newdoublearr \n");
    printarr_double(newdoublearr, size);
    */


    // 
    // 
    //close(fd);

    return 0;
}
