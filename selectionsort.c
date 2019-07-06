
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void populate_data(int* data, int size);
void print_data(int* data, int size, int sortedto);
int find_lowest_index(int* data, int size, int start);
void swap(int* data, int i1, int i2);
void selection_sort(int* data, int size);

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(int argc, char* argv[])
{
    puts("------------------");
    puts("| codedrome.com  |");
    puts("| Selection Sort |");
    puts("------------------\n");

    const int size = 16;

    int data[size];

    populate_data(data, size);

    selection_sort(data, size);

    return EXIT_SUCCESS;
}

//--------------------------------------------------------
// FUNCTION populate_data
//--------------------------------------------------------
void populate_data(int* data, int size)
{
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        data[i] = (rand() % 128);
    }
}

//--------------------------------------------------------
// FUNCTION print_data
//--------------------------------------------------------
void print_data(int* data, int size, int sortedto)
{
    for(int i = 0; i < size; i++)
    {
        if(i < sortedto)
            printf(GRN "%-3d " RESET, data[i]);
        else
            printf(RED "%-3d " RESET, data[i]);
    }

    printf("\n");
}

//--------------------------------------------------------
// FUNCTION selection_sort
//--------------------------------------------------------
void selection_sort(int* data, int size)
{
    puts("Unsorted...");
    print_data(data, size, 0);

    puts("Selection Sorting...");

    int sorted_to = 0;
    int index_of_lowest;

    while(sorted_to < size - 1)
    {
        index_of_lowest = find_lowest_index(data, size, sorted_to);

        swap(data, sorted_to, index_of_lowest);

        sorted_to++;

        print_data(data, size, sorted_to);
    }

    puts("Sorted!");
}

//--------------------------------------------------------
// FUNCTION swap
//--------------------------------------------------------
void swap(int* data, int i1, int i2)
{
    if(i1 != i2)
    {
        data[i1] = data[i1] ^ data[i2];
        data[i2] = data[i1] ^ data[i2];
        data[i1] = data[i1] ^ data[i2];
    }
}

//--------------------------------------------------------
// FUNCTION find_lowest_index
//--------------------------------------------------------
int find_lowest_index(int* data, int size, int start)
{
    int lowest_index = start;

    for(int i = start; i < size; i++)
    {
        if(data[i] < data[lowest_index])
        {
            lowest_index = i;
        }
    }

    return lowest_index;
}
