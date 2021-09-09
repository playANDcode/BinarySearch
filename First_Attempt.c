#include <stdio.h>

/*
We are not removing values in array that are to be disregarded
Instead, we assume it by making the program think 
    -  we are reducing the array
    -  making index 5 or index 3, any number as index 0 for example
*/

int main(void)
{
    // Values
    int numbers[9] = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    int arr_length = sizeof(numbers) / sizeof(int);
    int index_resetter = 0;  // Value that assumes index 5 to be index 0
    int half = 0;           // The location of middle index in array
    int middle_value;       // The value of the middle index

    // Get a number to be searched in array
    int given_number;  
    printf("Number: ");
    scanf("%d", &given_number);

    // Binary Search
    while (1)
    {
        arr_length -= half;     // Assumes that len of array is being reduced
        half = arr_length / 2;
        middle_value = numbers[half + index_resetter]; 
        if (middle_value == given_number)
        {
            printf("Found!!");
            return 0;
        }
        // Half == 0 means the array has been fully searched
        else if (half == 0)
        {
            printf("Digit %i doesn't exist in the array", given_number);
            return 1;
        }
        else if (middle_value <= given_number)
        {
            index_resetter += half;
        }
    }
}
