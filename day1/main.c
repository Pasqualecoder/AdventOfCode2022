#include "../adventofcode.h"

void part1(FILE *file) {
    int highest_elf = 0, actual_elf = 0;
    for (char ch = fpeek(file); ch != EOF; ch = fpeek(file)) {
        if (ch != '\n') {
            int tmp; // sommatory of the elf
            fscanf(file, "%d", &tmp);
            actual_elf += tmp;

            // needed to get rid of the '\n' at the end of every line
            getc(file);
        }
        else {
            if (actual_elf > highest_elf) {
                highest_elf = actual_elf;
            }
            actual_elf = 0;

            // lose the empty line
            getc(file);
        }
    }
    rewind(file);

    // The Elf who carry the most Calories is carrying: 
    printf("%d\n", highest_elf);
}


void shift_right(int array[], int size, int position);
int summatory(int array[], int size);

void part2(FILE *file) {
    int top_n = 3;
    int top_elves[] = {0, 0, 0};
    int actual_elf = 0;

    for (char ch = fpeek(file); ch != EOF; ch = fpeek(file)) {
        if (ch != '\n') {
            int tmp; // sommatory of the elf
            fscanf(file, "%d", &tmp);
            actual_elf += tmp;

            // needed to get rid of the '\n' at the end of every line
            getc(file);
        }
        else {
            for (int i = 0; i < 3; i++) {
                // make space for the new elf
                if (actual_elf > top_elves[i]) {
                    shift_right(top_elves, top_n, i);
                    top_elves[i] = actual_elf;
                    break;
                }
            }

            actual_elf = 0;

            // lose the empty line
            getc(file);
        }
    }
    rewind(file);

    // Total of calories carried by the top three of Elves is: 
    printf("%d\n", summatory(top_elves, top_n));
}

void shift_right(int array[], int size, int position) {
    for (int i = position; i < size - 1; i++) {
        array[i+1] = array[i];
    }
}

int summatory(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    FILE *file = fopen(SAMPLE_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "Cant open file\n");
        exit(EXIT_FAILURE);
    }

    part1(file);
    part2(file);
    
    fclose(file);
    return 0;
}
