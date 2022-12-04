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

typedef enum results_set {
    DRAW = 3,
    WIN = 6,
    LOSE = 0
} Results;

/*
returns
6: win
3: draw
0: lose
*/
int result(Opponent opponent, Me me);

// returns the ammount of points acquired in the match
int load_points(Opponent opponent, Me me);

void part1(FILE *file) {
    int points = 0;
    char ch;
    
    while ((ch = fpeek(file)) != EOF)
    {
        char opponent, me;
        fscanf(file, "%c %c", &opponent, &me);

        points += load_points(opponent, me);

        // remove \n
        getc(file);
    }

    // The ammount of my points is:
    printf("%d\n", points);
}

int result(Opponent opponent, Me me) {
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

int load_points(Opponent opponent, Me me) {
    int points_choice = me - 87;
    int adder = result(opponent, me);

    return points_choice + adder;
}

int main(int argc, char const *argv[])
{
    FILE *file = open_file(INPUT_FILE);
    
    part1(file);
    
    return 0;
}
