//
//  main.c
//  4130 Assignment 1 Question 4
//
//  Created by Cheung Tsz Yin on 24/3/2018.
//  Copyright © 2018 Cheung Tsz Yin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countFunc(char recorder[]){
    
    int i = 0; char max;
    int j = 0;
    int count[27];
    for(i=0;i<27;i++){
        count[i]=0;
    }
    //printf("test1");
    for(i = 97; i < 123; i++){
        //printf("%d",strlen(recorder));
        for (j = 0; j < 1402; j++){
            //printf("%d\n",j);
            if (recorder[j] == i && recorder[j] != ' ') {
                count[i - 97]++;
            }
            
        }
        //printf("%d\n",i);
    }
    //printf("test2\n");
    max = 97; i = 0;
    
    for (i = 0; i < 27; i++){
        if (count[i] > count[max - 97] ){//&& recorder[j] != ' '){
            max = i+97;//count[i + 97];
        }
        //printf("%c has %d\n",i+97,count[i]);
    }
    
    printf("\n\n%c   %d", max, count[max - 97]);
    return max;
    
}

void cipher (char * recorder, int s){
    
    int i = 0;
    char *charMemory;
    
    for (i = 0; i < 1402; i++){
        
        if(recorder[i] == 32){
            recorder[i] = recorder[i];
            
        }
        
        else if(recorder[i] - s < 97){
            recorder[i] = recorder[i] -s +26;
            
        }
        
        //else if (recorder)
        //else if (recorder[i] - n < 97){
        //  recorder[i] = recorder[i] -n +26;
        //}
        
        else
            recorder[i] = recorder[i] - s;
        
        
    }
    printf("\n\nAfter_Decryption: \nPlaintext: \n\n");
    printf("%s", recorder);
    //printf("\n%s\n\n", recorder);
    
}

int main() {
    
    char charArray[1402];
    char memory[1402];
    int i = 0;
    int j = 0; // 26 time of apl
    int length;
    
    
    // FILE_INPUT_PART
    FILE *dataStore; // open a variable to store data
    dataStore = fopen("caesar.txt", "r"); // open the file
    if (dataStore == NULL){ // if cannot open file, terminate the program
        printf("cannot open file\n");
        exit(1);
    }
    
    fgets(charArray, 1402, dataStore);
    length = strlen(charArray);
    printf("STRING_LENGTH = %d\n", length);
    printf("Ciphertext: \n\n");
    //printf("%s", charArray);
    
    for(i = 0; i < 1402; i++){
        memory[i] = charArray[i];
    }
    
    printf(".......");
    
    int most = countFunc(memory)-'e';
    
    cipher(memory, most);
    
    printf(".......");
    
    fclose(dataStore); // close the file
    printf("\nPROGRAM_ENDED..........................................................................\n\n");
    
    return 0;
    
}


