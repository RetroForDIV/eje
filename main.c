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
  //please change whatever you need here to make it work.
  return 0;
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
