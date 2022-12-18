#include "../adventofcode.h"

void part1(FILE *file) {
    rewind(file);
    printf();
}

void part2(FILE *file) {
    rewind(file);
    printf();
}

int main(int argc, char const *argv[]) {
    FILE *file = open_file(INPUT_FILE);

    part1(file);
    part2(file);
    
    fclose(file);
    return 0;
}
