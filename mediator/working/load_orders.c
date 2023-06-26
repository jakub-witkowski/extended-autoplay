#include <stdio.h>
#include <unistd.h>
#include <string.h>

//#define MAP_SIZE_X 32
//#define MAP_SIZE_Y 32

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

void load_orders(char fname[], au a[])
{
    /* variables used to store data read from rozkazy.txt */
    int id;
    char* action;
    char* type;
    int x;
    int y;
    int target_id;

    FILE * fptr;

    fptr = fopen(fname, "r");
    
    /* getting number of lines in rozkazy.txt*/
    int line_count = 0;
    char c;
        
    for (c = getc(fptr); c != EOF; c = getc(fptr))
        if (c == '\n')
            line_count++;

    /* going back to the beginning of the file */
    rewind(fptr); 
    
    for (int i = 0; i < line_count; i++)
    {
        for (c = getc(fptr); c != '\n'; c = getc(fptr))
        {
            if (c == 'B')
            {
                fseek(fptr, -3L, SEEK_CUR);
                /*if (fscanf(fptr, "%d %s %s", &id, action, type) == 3)
                    printf("Read base id: %d and training unit type: %s\n", id, type);
                else   
                    continue;*/
                fscanf(fptr, "%d %s %s", &id, action, type);
                printf("Read base id: %d and training unit type: %s\n", id, type);
                continue;
            }
            else if (c == 'M')
            {
                fseek(fptr, -3L, SEEK_CUR);
                /*if (fscanf(fptr, "%d %s %d %d", &id, action, &x, &y) == 4)
                    printf("Read id: %d and coords: x: %d y: %d\n", id, x, y);
                else
                    continue;*/
                fscanf(fptr, "%d %s %d %d", &id, action, &x, &y);
                printf("Read id: %d and coords: x: %d y: %d\n", id, x, y);
                continue;
            }
            else if (c == 'A')
            {
                fseek(fptr, -3L, SEEK_CUR);
                /*if (fscanf(fptr, "%d %s %d", &id, action, &target_id) == 3)
                    printf("Read id: %d and target id: %d\n", id, target_id);
                else
                    continue;*/
                fscanf(fptr, "%d %s %d", &id, action, &target_id);
                printf("Read id: %d and target id: %d\n", id, target_id);
                continue;
            }
            else if (c == EOF)
                break;
        }
    }    

    
    /* reading training orders 
    for (int i = 0; i < line_count; i++)
    {
        if (fscanf(fptr, "%d %s %s\n", &id, action, type) != 3)
        {
            continue;
        }
        else
        {
            printf("Read base id: %d and training unit type: %s\n", id, type);
        }
    } */

    /* reading move orders
    for (int i = 0; i < line_count; i++)
    {
        if (fscanf(fptr, "%d %s %d %d\n", &id, action, &x, &y) != 4)
        {
            continue;
        }
        else
        {
            //a[id].x_coord = x;
            //a[id].y_coord = y;
            printf("Read id: %d and coords: x: %d y: %d\n", id, x, y);
        }
    } */

    /* going back to the beginning of the file */
    
    /*for (int i = 0; i < line_count; i++)
    {
        if (fscanf(fptr, "%d %s %d\n", &id, action, &target_id) != 3)
        {
            continue;
        }
        else 
        {
            printf("Read id: %d and target id: %d\n", id, target_id);
        }
    }*/


fclose(fptr);
}