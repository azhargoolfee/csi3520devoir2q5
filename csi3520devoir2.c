#include <stdio.h>
#include <string.h>
//Name : Azhar Goolfee
//Student number : 300277310
int main(){
    char input[150];           //input from user
    int state;      //stores the state reached
    state = 0;      //start state = 0
    printf("Hello. Please input the text that you want to test : ");        //prompts user to enter text
    fgets(input, sizeof(input), stdin);         //gets input from user
    printf("You have input : %sWe will now test if it is a comment using the state diagram from Q4.\n" , input);
    input[strlen(input) - 1] = '\0';                //removes newline character
    if(input[0] == '/'){        //checks first state
        printf("Reached state : 1\n");
        state = 1;
    }
    if(input[1] == '*' && state == 1){              //checks second state
        printf("Reached state : 2\n");
         state = 2;
    }
    if(input[(strlen(input) - 2)] == '*' && state == 2){            //checks third state
        printf("Reached state : 3\n");
        state = 3;
    }
    if(input[(strlen(input) - 1)] == '*' && state == 2){                //checks third state
        printf("Reached state : 3\n");
        state = 3;
    }
    if(input[strlen(input) - 1] == '/' && state == 3){      //checks fourth state
        printf("Reached state : 4\n");
        state = 4;
    }
    
    printf("**********************\n");
    if (state == 4){        //if 4th state is reached
        printf("\nPASS : It is a comment.");
    }
    else{       //if it is stuck in a state less than 4
        printf("\nFAIL : It is NOT a comment.\n");
        printf("Text exited at state : %d", state);
    }
    return(0);
}