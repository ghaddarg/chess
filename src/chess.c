#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define NUM_FUNC 8

//#define DEBUG 1
#ifdef DEBUG
#define ENTER(x, y)    do {\
                            printf("%s:ENTER(%s)\n", x, y);\
                       } while(0)
#define EXIT(x, y)    do {\
                            printf(x);\
                            printf(":EXIT(%d)\n", y);\
                         } while(0)
#else

#define ENTER(x, y)
#define EXIT(x, y)

#endif

/*************************************/
/*            BISHOP                 */
/*************************************/
bool direction_1(char * bishop, char * pawn)
{
    //printf("%s: ENTER()\n", __func__);
    bool ret = false;
    char temp[3] = { 0 };
    memcpy(temp, bishop, strlen(bishop));
    
    while (true) {
        
        //corner case
        if (temp[0] == 'h')
            break;
            
        // direction 1
        if (temp[0] >= 0x61 && temp[0] < 0x68) {
            
            temp[0] = temp[0] + 1;
            if (temp[1] >= 0x31 && temp[1] < 0x38)
                temp[1] = temp[1] + 1;
        }
        
        //printf("temp: %s\n", temp);
        if (!strcmp(temp, pawn)) {
            ret = true;
            break;
        }
        
        if (temp[0] >= 0x68 || temp[1] >= 0x38)
            break;  
    }
    
    //printf("%s: EXIT(%d)\n", __func__, ret);
    return ret;
}
bool direction_2(char * bishop, char * pawn)
{
    //printf("%s: ENTER()\n", __func__);
    bool ret = false;
    char temp[3] = { 0 };
    memcpy(temp, bishop, strlen(bishop));
    
    while (true) {
        
        //corner case
        if (temp[1] == '1')
            break;
        
        if (temp[0] > 0x61 && temp[0] <= 0x68) {
            
            temp[0] = temp[0] - 1;
            if (temp[1] > 0x31 && temp[1] <= 0x38)
                temp[1] = temp[1] - 1;
        }
        
        //printf("temp: %s\n", temp);
        if (!strcmp(temp, pawn)) {
            ret = true;
            break;
        }
        
        if (temp[0] <= 0x61 || temp[1] >= 0x38)
            break;  
    }
    
    //printf("%s: EXIT(%d)\n", __func__, ret);
    return ret;
}
bool direction_3(char * bishop, char * pawn)
{
    //printf("%s: ENTER()\n", __func__);
    bool ret = false;
    char temp[3] = { 0 };
    memcpy(temp, bishop, strlen(bishop));
    
    while (true) {
        
        //corner case
        if (temp[0] == 'a')
            break;
            
        if (temp[0] > 0x61 && temp[0] <= 0x68) {
            
            temp[0] = temp[0] - 1;
            if (temp[1] >= 0x31 && temp[1] < 0x38)
                temp[1] = temp[1] + 1;
        }
        
        //printf("temp: %s\n", temp);
        if (!strcmp(temp, pawn)) {
            ret = true;
            break;
        }
        
        if (temp[0] <= 0x61 || temp[1] >= 0x38)
            break;  
    }
    
    //printf("%s: EXIT(%d)\n", __func__, ret);
    return ret;
}
bool direction_4(char * bishop, char * pawn)
{
    //printf("%s: ENTER()\n", __func__);
    bool ret = false;
    char temp[3] = { 0 };
    memcpy(temp, bishop, strlen(bishop));
    
    while (true) {
        
        //corner case
        if (temp[1] == '1')
            break;
            
        if (temp[0] >= 0x61 && temp[0] < 0x68) {
            
            temp[0] = temp[0] + 1;
            if (temp[1] >= 0x31 && temp[1] < 0x38)
                temp[1] = temp[1] - 1;
        }
        
        //printf("temp: %s\n", temp);
        if (!strcmp(temp, pawn)) {
            ret = true;
            break;
        }
        
        if (temp[0] >= 0x68 || temp[1] <= 0x31)
            break;  
    }
    
    //printf("%s: EXIT(%d)\n", __func__, ret);
    return ret;
}

bool solution_bishop(char * bishop, char * pawn)
{ 
    bool ret = false;

    if (!bishop || !pawn)
        goto out;
        
    //printf("bishop: %s - pawn %s\n", bishop, pawn);
    
    if (direction_1(bishop, pawn)) {
        ret = true;
        goto out;
    }
    if (direction_2(bishop, pawn)) {
        ret = true;
        goto out;
    }
    if (direction_3(bishop, pawn)) {
        ret = true;
        goto out;
    }
    if (direction_4(bishop, pawn)) {
        ret = true;
        goto out;
    }
        
out:
    return ret;
}

/*************************************/
/*            KNIGHT                 */
/*************************************/

bool is_valid_cell(char * s)
{
    bool ret = true;
    int size = strlen(s);
    ENTER(__func__, s);
    
    if (!size || !s)
        goto out;
        
    if (!(s[1] >= 0x31 && s[1] <= 0x38 && s[0] >= 0x61 && s[0] <= 0x68))
        ret = false;
 out:
    EXIT(__func__, ret);   
    return ret;
}

void direction_1_k(char * temp)
{
    temp[0] += 1;
    temp[1] += 2;
}
void direction_2_k(char * temp)
{
    temp[0] += 2;
    temp[1] += 1;
}
void direction_3_k(char * temp)
{
    temp[0] += 1;
    temp[1] -= 2;
}
void direction_4_k(char * temp)
{
    temp[0] += 2;
    temp[1] -= 1;
}

void direction_1_opposite(char * temp)
{
    temp[0] -= 1;
    temp[1] += 2;
}
void direction_2_opposite(char * temp)
{
    temp[0] -= 2;
    temp[1] += 1;
}
void direction_3_opposite(char * temp)
{
    temp[0] -= 1;
    temp[1] -= 2;
}
void direction_4_opposite(char * temp)
{
    temp[0] -= 2;
    temp[1] -= 1;
}


int solution_knight(char * cell) 
{
    int ret = 0;
    void (*f_ptr[NUM_FUNC])(char * c);
    char temp[3] = { 0 };
    
    if (!cell || !strlen(cell))
        goto out;
    
    ENTER(__func__, cell);
    
    f_ptr[0] = direction_1_k;
    f_ptr[1] = direction_2_k;
    f_ptr[2] = direction_3_k;
    f_ptr[3] = direction_4_k;
    
    f_ptr[4] = direction_1_opposite;
    f_ptr[5] = direction_2_opposite;
    f_ptr[6] = direction_3_opposite;
    f_ptr[7] = direction_4_opposite;      
           
    for (int i = 0; i < NUM_FUNC; ++i) {
        
        memcpy(temp, cell, strlen(cell));
        f_ptr[i](temp);
        ret += is_valid_cell(temp);
    }
    
out:
    EXIT(__func__, ret);
    return ret;
}

/*************************************/
/*              MAIN                 */
/*************************************/
int main(void)
{
    int ret = 0;
    printf("HELLO CHESS WORLD\n");

    char input[22][3] = {"a1", "c3", "h1", "h3", "a5", "c3", "g1", "f3", "e3", "a7", "e7", "d6",
                    "e7", "a3", "e3", "a7", "a1", "h8", "a1", "h7", "h1", "a8"};

    for (int i = 0; i < 22; i += 2) {

        ret = solution_bishop(input[i], input[i + 1]);
        printf("Pawn @ %s will be%scaptured by the Bishop @ %s\n", input[i + 1], ret ? " ": " NOT ", input[i]);   
    }

    char input_knight[10][3] = {"a1", "c2", "d4", "g6", "a3", "b7", "h8", "h6", "g8", "a5"};
    int expected_output_knight[10] = {2, 6, 8, 6, 4, 4, 2, 4, 3, 4};

    for (int i = 0; i < 10; ++i) {
        printf("Test #%d: ", i + 1);
        if (expected_output_knight[i] != solution_knight(input_knight[i]))
            printf("FAIL\n");
        else
            printf("PASS\n");
    }

    printf("GDBYE CHESS WORLD\n");
    return ret;
}