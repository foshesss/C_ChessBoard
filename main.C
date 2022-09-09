#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct array_double_char array_double_char;
struct array_double_char {
    char **data;
    int row;
    int col;
};


array_double_char chessboardPattern(int goal) {
    array_double_char answer;
    answer.data = (char**) malloc(sizeof(char*) * (goal));

    char *rowOne = (char *) malloc(goal * 2);
    char *rowTwo = (char *) malloc(goal * 2);

    // create rows
    for (int i = 0; i < goal * 2; i+=2) {
        if (i/2 % 2 == 0) {
            *(rowOne + i) = 'W';
            *(rowTwo + i) = 'B';
        } else {
            *(rowOne + i) = 'B';
            *(rowTwo + i) = 'W';
        }

        // add space
        if (i + 1 != goal) {
            *(rowOne + i + 1) = ' ';
            *(rowTwo + i + 1) = ' ';
        }
    }

    // rowOne and rowTwo should now look like this:
    // rowOne = "W B W B W B W B W";
    // rowTwo = "B W B W B W B W B";


    // copy to fill chess board
    for (int i = 0; i < goal; i++) {
        answer.data[i] = i % 2 == 0 ? rowOne : rowTwo;
        printf("%s\n", answer.data[i]);
    }

    return answer;
}

int main()
{
    chessboardPattern(12);
    return 0;
}