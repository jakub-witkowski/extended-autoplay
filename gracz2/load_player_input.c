#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//#define MAP_SIZE_X 32
//#define MAP_SIZE_Y 32

/*#define OPPONENTS 8

 attack arrays 
int knight[OPPONENTS] = { 35, 35, 35, 35, 35, 35, 35, 35 };
int swordsman[OPPONENTS] = { 30, 30, 30, 20, 20, 30, 30, 30 };
int archer[OPPONENTS] = { 15, 15, 15, 15, 10, 10, 15, 15 };
int pikeman[OPPONENTS] = { 35, 15, 15, 15, 15, 10, 15, 10 };
int catapult[OPPONENTS] = { 40, 40, 40, 40, 40, 40, 40, 50 };
int ram[OPPONENTS] = { 10, 10, 10, 10, 10, 10, 10, 50 };
int worker[OPPONENTS] = { 5, 5, 5, 5, 5, 5, 5, 1 };*/

/* aliases for array indices  
const int vs_K = 0;
const int vs_S = 1;
const int vs_A = 2;
const int vs_P = 3;
const int vs_C = 4;
const int vs_R = 5;
const int vs_W = 6;
const int vs_B = 7;*/

typedef struct {
    char affiliation[2];
    char unit_type[2];
    int unit_id;
    int x_coord;
    int y_coord;
    int current_stamina;
    int remaining_movement;
    int attack_count;
    char is_base_busy[2];
    int training_time;
} au;

void load_player_input(char fname[], au a[], int *u, int *l)
{
    /* variables used to store data read from rozkazy.txt */
    int letters = 0;
    int spaces = 0;
    int digits = 0;
    int count = 0;
    int base_id;
    int id;
    int row_number;
    const int length = 24;
    char order[length];
    char player_input[length];
    char next_player_input[length];
    long gold = 0;
    char training_unit_affiliation[2];
    char training_unit_type[2];
    int training_unit_id;
    int training_unit_x;
    int training_unit_y;
    int training_unit_stamina;
    int training_time_left;
    //int base_busy = 0;
    char* action;
    char type[2];
    char message[12];
    int* attacker;
    //int attacker[8];
    //int versus = 0;
    int x;
    int y;
    int target_id;

    FILE * fptr; // input: player1.txt or player2.txt file, depending on function call

    fptr = fopen(fname, "r");
    if (!fptr)
        printf("Cannot find %s\n", fname);

    while (fgets(player_input, length, fptr) != NULL)
    {
        for (int i = 0; player_input[i] != '\n'; i++)  
        {
            if (isupper(player_input[i]))
            {
                letters++;
            }
            if (isblank(player_input[i]))
            {
                spaces++;
            }         
        }

        if (spaces == 1 && letters == 1)
        {
            sscanf(player_input, "%d T", &training_time_left);
            //printf("\n------------------------------------------\n");
            printf("Read training time left: %d\n", training_time_left);
            letters = 0;
            spaces = 0;
        }

        *l = training_time_left;
    }
        //printf("\n%d %d %d\n", letters, digits, spaces);
        /*if (spaces == 6)
        {
            sscanf(player_input, "%s %s %d %d %d %d %d", training_unit_affiliation, training_unit_type, &training_unit_id, &training_unit_x, &training_unit_y, &training_unit_stamina, &training_time_left);
            //printf("Read aff: %s, type: %s, id: %d, x: %d, y: %d, stamina: %d, training time left: %d\n", training_unit_affilitation, training_unit_type, training_unit_id, training_unit_x, training_unit_y, training_unit_stamina, training_time_left);
            letters = 0;
            spaces = 0;

            if ((strcmp(training_unit_affiliation, "0") == 0) && (strcmp(training_unit_type, "0") == 0))
            {
                continue;
            }
            if ((strcmp(fname, "player1.txt") == 0) && (strcmp(training_unit_affiliation, "P") == 0) && training_time_left > 0)
            {
                strcpy(a[training_unit_id].affiliation, training_unit_affiliation);
                strcpy(a[training_unit_id].unit_type, training_unit_type);
                a[training_unit_id].unit_id = training_unit_id;
                a[training_unit_id].x_coord = training_unit_x;
                a[training_unit_id].y_coord = training_unit_y;
                a[training_unit_id].current_stamina = training_unit_stamina;
                a[training_unit_id].training_time = training_time_left;
                printf("u: %d\n", *u);
                *u += 1;
                printf("u: %d\n", *u);
                printf("Dane treningu P wczytane\n");
            }
            if ((strcmp(fname, "player2.txt") == 0) && (strcmp(training_unit_affiliation, "E") == 0) && training_time_left > 0)
            {
                strcpy(a[training_unit_id].affiliation, training_unit_affiliation);
                strcpy(a[training_unit_id].unit_type, training_unit_type);
                a[training_unit_id].unit_id = training_unit_id;
                a[training_unit_id].x_coord = training_unit_x;
                a[training_unit_id].y_coord = training_unit_y;
                a[training_unit_id].current_stamina = training_unit_stamina;
                a[training_unit_id].training_time = training_time_left;
                printf("u: %d\n", *u);
                *u += 1;
                printf("u: %d\n", *u);
                printf("Dane treningu E wczytane\n");
            }
        }

    letters = 0;
    spaces = 0;
    }*/

    fclose(fptr);
}