/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Save an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

// Ej 1: Funtion that finds the peak on the array, if it does not exist, return -1
int array_peak_sequential(int a[], unsigned int length) {

    int t, i = 1;
    int j = length;

    if (a[i] > a[i+1]){
        
        t = 1;
    } 
    else if (a[j] > a[j-1]) {
        
        t = j;
    }
    for (i=1 ; i < j ; i++) {

        if (a[i-1] < a[i] && a[i] > a[i+1]) {
        
          t= a[i];
        }

        else t = -1;

    }
  //please change whatever you need here to make it work.
  return t;

}

// Ej 2: Funtion that finds the peak on the array, if it does not exist, return -1
int array_peak_binary(int a[], unsigned int length) {

  //please change whatever you need here to make it work.
  return 0;
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
  char *filepath = NULL;

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* create an array of MAX_SIZE elements */
  int array[MAX_SIZE];

  /* parse the file to fill the array and obtain the actual length */
  unsigned int length = array_from_file(array, MAX_SIZE, filepath);

  /* show the ordered array in the screen */
  array_dump(array, length);

  int this_is_the_peak = array_peak_sequential(array, MAX_SIZE);
  printf("The peak is: %d", this_is_the_peak);

  //TODO: Uncomment this to do part b
  //array_peak_binary(array, MAX_SIZE);


  return (1);
}

/* 
Para compilar: gcc​-Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c
gcc​-Wall -Werror -Wextra -pedantic -std=c99 -o lab_extra *.o main.c
Para ejecutar:./lab_extra​​../input/example-unsorted.in o cualquiera de los archivos de prueba

#include<iostream>
using namespace std;
int PeakElement(int a[], int start, int end) {
   int i, mid;
   mid = (end+start+1)/2;
   if((a[mid] > a[mid+1] && mid == start)||(a[mid] > a[mid-1] && mid == end)) {
      return a[mid];
   } else if(a[mid] < a[mid-1] && a[mid] > a[mid+1]) {
      return a[mid];
   } else if(a[mid] <= a[mid+1]) {
      return PeakElement(a, mid+1, end);
   } else if(a[mid] <= a[mid-1]) {
      return PeakElement(a, start,mid-1);
   }
}
int main() {
   int n, i, p;
   cout<<"\nEnter the number of data element: ";
   cin>>n;
   int arr[n];
   for(i = 0; i < n; i++) {
      cout<<"Enter element "<<i+1<<": ";
      cin>>arr[i];
   }
   p = PeakElement(arr, 0, n-1);
   cout<<"\nThe peak element of the given array is: "<<p;
   return 0;
}

*/