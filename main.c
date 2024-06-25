#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'matchingStrings' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING_ARRAY strings
 *  2. STRING_ARRAY queries
 */

/*
 * To return the integer array from the function, you should:
 *     - Store the size of the array to be returned in the result_count variable
 *     - Allocate the array statically or dynamically
 */
/*  Description: Function to compare 2 strings .
 *  Argument   : str1 - string1 to compare.
               str2 - string2 to compare.
               len  - Length of string to compare.
 *  Return     : True , if string is same.             
 */ 
bool bStringCmp(char* str1, char* str2 , int len){
    bool bCompare = true; 
    for (int i = 0; i < len; i++) {
        if (str1[i] != str2[i]) {
            bCompare = false;
            break;
        }   
    }
    return bCompare;
}

/*  Description: Function calculte length of string .
 *  Argument   : str - input string. 
 *  Return     : Length of string.             
 */ 
uint8_t u8StringLen(char * str){
   uint8_t len=0;
   while(*str != '\0'){
       len++;
       str++;
   }
   return len;
}


int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    char * strS;   //Fetch a data from Strings array
    char * strQ;   //Fetch a data from Query array
    int strS_Len = 0; //length of fetched data from String array
    int strQ_Len = 0; //length of fetched data from Query array
    bool bStrIdentical = false; //True if data fetched from Query array and String array is same.
//    static int result[2000]={0};//Result array
    int* result = (int*)calloc(queries_count, sizeof(int)); // Dynamically allocate and initialize to zero   
    *result_count = queries_count; // Passed to main function. Size is same as No of queries string.
    /*Iterating through each query */
    for (int i = 0; i < queries_count; i++) {
        strQ = queries[i]; //fetching ith query
        strQ_Len = u8StringLen(strQ); // calculating length of query
        /*Iterating through each string*/
        for (int j=0; j<strings_count; j++) {
            strS = strings[j]; //fetching jth string
            strS_Len = u8StringLen(strS);// calculating length of string
            if (strS_Len != strQ_Len) {   //If length of query and string is not same then skip the jth loop.             
                continue;
            }
            //Length is same hence compare string and query
            bStrIdentical = bStringCmp(strS, strQ, strQ_Len);
            if (bStrIdentical == true) {
                result[i]++; //If query matches with a string then increment result array corresponding to query.      
            }
        }
    }   
    //return array of result of querry matches with number of strings. 
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int strings_count = parse_int(ltrim(rtrim(readline())));

    char** strings = malloc(strings_count * sizeof(char*));

    for (int i = 0; i < strings_count; i++) {
        char* strings_item = readline();

        *(strings + i) = strings_item;
    }

    int queries_count = parse_int(ltrim(rtrim(readline())));

    char** queries = malloc(queries_count * sizeof(char*));

    for (int i = 0; i < queries_count; i++) {
        char* queries_item = readline();

        *(queries + i) = queries_item;
    }

    int res_count;
    int* res = matchingStrings(strings_count, strings, queries_count, queries, &res_count);

    for (int i = 0; i < res_count; i++) {
        fprintf(fptr, "%d", *(res + i));

        if (i != res_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
