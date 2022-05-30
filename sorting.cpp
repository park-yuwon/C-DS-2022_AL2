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

#define MAX_RAND_NUM 10000

struct RANDS {
    FILE* pos;
    FILE* ints;
    FILE* doubles;
    FILE* fixed; // String
};

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
            fprintf(infile, "%lf\n", arr[i]);
        }
    }
    fclose(infile);
    return true;
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
        while (fscanf(infile, "%d", &num) == 1)
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
        while (fscanf(infile, "%lf", &num) != EOF)
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
    infile = fopen(filename, "w");
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
/*
void bubble_s() {

}
void merge_s() {

}*/

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

}
void radix_s(FILE* fd) {

}
*/
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
        //arr[i] = random / 100;
        arr[i] = random;
    }

    random = 0;
    for (int i = 0; i < MAX_RAND_NUM; i++)
    {
        random = rand();
        minusarr[i] = -random / 100;

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
    char fname3[20] = "testdouble.txt";
    char fname4[20] = "testtext.txt";

    file_w(fname, size, arr);
    file_w(fname2, size, minusarr);
    file_w_double(fname3, size, doublearr);
    file_string_w(fname4, size, code_str);

    // File Read

    int select_pos_arr[MAX_RAND_NUM];
    int select_int_arr[MAX_RAND_NUM];
    double select_double_arr[MAX_RAND_NUM];

    /*int insert_pos_arr[MAX_RAND_NUM];
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

    char newcodestr[1000][6];*/

    /*int newarr[MAX_RAND_NUM];
    int newminusarr[MAX_RAND_NUM];
    double newdoublearr[MAX_RAND_NUM];
    char newcodestr[MAX_RAND_NUM][6];*/


    //file_r(fname, newarr);
    //file_r(fname2, newminusarr);
    file_r_double(fname3, select_double_arr);
    //file_string_r(fname4, newcodestr);
                      
    /*
    printf("1-1. Print newarr \n");
    printarr(newarr, size);
    printf("\n1-2. Print newminusarr \n");
    printarr(newminusarr, size); // 0 ~ 음수
    printf("\n1-3. Print newdoublearr \n");
   
    */
    printarr_double(select_double_arr, size);
    // Part 2. Sort algorithms

    /*insertion_s();
    selection_s();
    bubble_s();
    merge_s();
    quick_s();
    heap_s();
    radix_s();*/

/*
    double start, end;
    start = (double)clock() / CLOCKS_PER_SEC;

    selectionSort(newarr, size);

    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("프로그램 수행 시간 :%lf\n", (end - start));
*/

    //selectionSort(newarr, size);
    //selectionSort(newminusarr, size);
    //selectionSort_double(newdoublearr, size);
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

    printf("Hello");
    return 0;
}
