#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char * final_str;
    if (argc <= 1){
        final_str = "n";
    } else {
        size_t size = 0; // start with size 1 for \0 (terminator)
        
        for(int i = 1; i < argc; i++){
            size += strlen(argv[i]) + 1;
        }
        
        //getting the size
        final_str = malloc(size); //malloc new string
        int offset = 0;
        for(int i = 1; i < argc; i++){ // for all args
            int len = strlen(argv[i]); // get length of string
            memcpy(&final_str[offset], argv[i], len); // copy arg into finalstring at offset
            offset += len + 1; // increment offset by length of string and 1 bnus for space
            final_str[offset-1] = ' '; // add space
        }
        final_str[size-1] = '\0'; // add the terminator character, and btw removes the unwanted last space
        
        // revert the string
        int i = 0;
        int j = size - 2;
        while (i < j){
            if (final_str[i] != final_str[j]){ // XOR swapping
                final_str[i] ^= final_str[j];
                final_str[j] ^= final_str[i];
                final_str[i] ^= final_str[j];
            }
            i++;
            j--;
        }
    }
    
    //print
    while (1){
        printf("%s\n", final_str);
    }

    return 0;
}
