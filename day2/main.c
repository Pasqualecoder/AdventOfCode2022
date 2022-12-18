#include "../adventofcode.h"

typedef enum opponent_move_set {
    OPPONENT_ROCK = 'A',
    OPPONENT_PAPER = 'B',
    OPPONENT_SCISSORS = 'C'
} Opponent;

typedef enum me_move_set {
    ME_ROCK = 'X',
    ME_PAPER = 'Y',
    ME_SCISSORS = 'Z'
} Me;

typedef enum points_set {
    WIN = 6,
    DRAW = 3,
    LOSE = 0
} Points;

typedef enum result_set {
    RESULT_LOSE = 'X',
    RESULT_DRAW = 'Y', 
    RESULT_WIN = 'Z', 
} Result;

/*
returns
6: win
3: draw
0: lose
*/
int match(Opponent opponent, Me me) {
    switch (opponent)
    {
    case OPPONENT_ROCK:
        switch (me)
        {
        case ME_ROCK:
            return DRAW;
            break;
        case ME_PAPER:
            return WIN;
            break;
        case ME_SCISSORS:
            return LOSE;
            break;
        default:
            exit(EXIT_FAILURE);
            break;
        }
        break;
    case OPPONENT_PAPER:
        switch (me)
        {
        case ME_ROCK:
            return LOSE;
            break;
        case ME_PAPER:
            return DRAW;
            break;
        case ME_SCISSORS:
            return WIN;
            break;
        default:
            exit(EXIT_FAILURE);
            break;
        }
        break;
    case OPPONENT_SCISSORS:
        switch (me)
        {
        case ME_ROCK:
            return WIN;
            break;
        case ME_PAPER:
            return LOSE;
            break;
        case ME_SCISSORS:
            return DRAW;
            break;
        default:
            exit(EXIT_FAILURE);
            break;
        }
        break;
    
    default:
        exit(EXIT_FAILURE);
        break;
    }
}

// returns the ammount of points acquired in the match
int load_points(Opponent opponent, Me me) {
    int points_choice = me - 87;
    int adder = match(opponent, me);

    return points_choice + adder;
}

char choose_move(Opponent opponent, Result result) {
    switch (opponent)
    {
    case OPPONENT_ROCK:
        switch (result)
        {
        case RESULT_WIN:
            return ME_PAPER;
            break;
        case RESULT_DRAW:
            return ME_ROCK;
            break;
        case RESULT_LOSE:
            return ME_SCISSORS;
            break;
        default:
            exit(EXIT_FAILURE);
            break;
        }
        break;
    case OPPONENT_PAPER:
        switch (result)
        {
        case RESULT_WIN:
            return ME_SCISSORS;
            break;
        case RESULT_DRAW:
            return ME_PAPER;
            break;
        case RESULT_LOSE:
            return ME_ROCK;
            break;
        default:
            exit(EXIT_FAILURE);
            break;
        }
        break;
    case OPPONENT_SCISSORS:
        switch (result)
        {
        case RESULT_WIN:
            return ME_ROCK;
            break;
        case RESULT_DRAW:
            return ME_SCISSORS;
            break;
        case RESULT_LOSE:
            return ME_PAPER;
            break;
        default:
            exit(EXIT_FAILURE);
            break;
        }
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }
}

void part1(FILE *file) {
    int points = 0;
    char ch;
    
    while ((ch = fpeek(file)) != EOF) {
        char opponent, me;
        fscanf(file, "%c %c", &opponent, &me);

        points += load_points(opponent, me);

        // remove \n
        getc(file);
    }
    rewind(file);

    // The ammount of my points is:
    fprintf(stdout, "%d\n", points);
}

void part2(FILE *file) {
    int points = 0;
    char ch;
    
    while ((ch = fpeek(file)) != EOF) {
        char opponent, result;
        fscanf(file, "%c %c", &opponent, &result);

        char me = choose_move(opponent, result);
        points += load_points(opponent, me);

        // remove \n
        getc(file);
    }
    rewind(file);

    // The ammount of my points is:
    fprintf(stdout, "%d\n", points);
}

int main(int argc, char const *argv[])
{
    FILE *file = open_file(INPUT_FILE);
    
    part1(file);
    part2(file);
    
    return 0;
}
