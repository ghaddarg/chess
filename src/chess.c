#include <stdbool.h>
#include <string.h>
#include <stdio.h>

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

bool solution(char * bishop, char * pawn)
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

int main(void)
{
    int ret = 0;
    printf("HELLO CHESS WORLD\n");

    char input[22][3] = {"a1", "c3", "h1", "h3", "a5", "c3", "g1", "f3", "e3", "a7", "e7", "d6",
                    "e7", "a3", "e3", "a7", "a1", "h8", "a1", "h7", "h1", "a8"};

    for (int i = 0; i < 22; i += 2) {

        ret = solution(input[i], input[i + 1]);
        printf("Pawn @ %s will be%scaptured by the Bishop @ %s\n", input[i + 1], ret ? " ": " NOT ", input[i]);
            
    }

    printf("GDBYE CHESS WORLD\n");
    return ret;
}