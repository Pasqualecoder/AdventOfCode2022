#include "../adventofcode.h"
#include <string.h>

#define RUCKSACK_MAX_SIZE 49

char common_element(char string[], int size) {
    int half = size / 2;

    for (int i = 0; i < half; i++) {
        for (int j = half; j < size; j++) {
            if (string[i] == string[j]) {
                return string[i];
            }
        }
    }

    return 0;    
}

char common_badge(char string1[], int size1, char string2[], int size2, char string3[], int size3) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            for (int k = 0; k < size3; k++) {
                if (string1[i] == string2[j] && string1[i] == string3[k] && string2[j] == string3[k]) {
                    return string1[i];
                }
            }
        }
    }
}

int get_priority(char character) {
    return (character <= 'Z') ? character - ('A') + 27 
    : character - ('a' - 1);
}

int string_counter(FILE *file) {
    int i = 0;
    char ch;
    char *string;
    while ((ch = fpeek(file)) != EOF) {
        getline(NULL, 0, file);
        i++;
    }
    rewind(file);
    return i;
}

void part1(FILE *file) {
    int sum_priorities = 0;
    char ch;
    while ((ch = fpeek(file)) != EOF) {
        char rucksack[RUCKSACK_MAX_SIZE+1];
        fscanf(file, "%s", rucksack);
        getc(file);
        int rucksack_size = strlen(rucksack);

        char common = common_element(rucksack, rucksack_size);
        if (common == 0) {
            fprintf(stderr, "There is no element in both compartment!\n");
            exit(EXIT_FAILURE);
        }
        
        int priorita = get_priority(common);
        sum_priorities += priorita;
    }
    rewind(file);
    
    // the sum of the priorities of common items is 
    fprintf(stdout, "%d\n", sum_priorities);
}

void part2(FILE *file) {
    int sum_priorities = 0;
    
    char ch;
    while ((ch = fpeek(file)) != EOF) {
        char rucksack1[RUCKSACK_MAX_SIZE+1];
        char rucksack2[RUCKSACK_MAX_SIZE+1];
        char rucksack3[RUCKSACK_MAX_SIZE+1];
        fscanf(file, "%s", rucksack1);
        fscanf(file, "%s", rucksack2);
        fscanf(file, "%s", rucksack3);
        getc(file);
        int rucksack_size1 = strlen(rucksack1);
        int rucksack_size2 = strlen(rucksack2);
        int rucksack_size3 = strlen(rucksack3);

        char common = common_badge(rucksack1, rucksack_size1, rucksack2, rucksack_size2, rucksack3, rucksack_size3);
        if (common == 0) {
            fprintf(stderr, "There is no common badge!\n");
            exit(EXIT_FAILURE);
        }
        
        int priorita = get_priority(common);
        sum_priorities += priorita;
    }
    rewind(file);
    
    // the sum of the priorities of common items is 
    fprintf(stdout, "%d\n", sum_priorities);
}

int main(int argc, char const *argv[]) {
    FILE *file = open_file(INPUT_FILE);

    part1(file);
    part2(file);

    fclose(file);
    return 0;
}
