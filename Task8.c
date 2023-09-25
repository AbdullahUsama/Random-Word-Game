//Task 8
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
//This function checks if the given word can fit in the grid based on the given orientation.
//It takes the grid, number of rows and columns, starting position (x and y), orientation, and the word as input.
//It returns 1 if the word cannot fit in the grid and 0 if it can fit.
int check_word_will_fit(char grid[100][100],int rows,int columns,int x,int y, int orientation_deter, char str[]){
    //If the orientation is 0 (horizontal), check if the rows have enough space for the word.
    //If not, return 1. If there is enough space, check if the grid has any characters already placed in the path of the word.
    //If there are, return 1. Otherwise, return 0.
    if(orientation_deter==0){
        if(rows>=strlen(str)){
        for(int i=0; i<strlen(str); i++){

            if(grid[x][y]!='-'){
                return 1;
            }
            x++;
        }
    }
    //If the orientation is 1 (vertical), check if the columns have enough space for the word. 
//If not, return 1. If there is enough space, check if the grid has any characters already placed in the path of the word. 
//If there are, return 1. Otherwise, return 0.
    }else if(orientation_deter==1){
        if(columns>=strlen(str)){
        for(int i=0; i<strlen(str); i++){
            if(grid[x][y]!='-'){
                return 1;
            }
            y++;
        }
    }
    //If the orientation is 2 (diagonal), check if the rows and columns have enough space for the word. 
//If not, return 1. If there is enough space, check if the grid has any characters already placed in the path of the word. 
//If there are, return 1. Otherwise, return 0.
    }else if(orientation_deter==2){
        if((rows>=strlen(str))&&(columns>=strlen(str))){
        for(int i=0; i<strlen(str); i++){
            if(grid[x][y]!='-'){
                return 1;
            }
            x++;y++;
        }
    }
    }   
    return 0;
}
//This function reverses the given string. It uses a random number generator to decide whether to reverse the string or not.
void reverse_string(char str[]) {
    //Seed the random number generator with the current time and a static variable that is incremented each time the function is called.
    static int SEED1 = 0;
    srand(time(0)+SEED1);
    SEED1+=2;
    //Generate a random number between 0 and 1.
    int reverse_deter = rand() % 2;
    //If the random number is 0, reverse the string.
    //If the random number is 1, do not reverse the string.
    if(reverse_deter==0){
    int length = strlen(str);
    char temp;
    for (int i = 0; i < length/2; i++) {
        temp = str[i];
        str[i] = str[length-i-1];
        str[length-i-1] = temp;
        }
    }
}
//This function places the given word in the grid. It takes the grid, number of rows and columns, and the word as input.
//It generates random starting positions and orientations for the word and checks if it can fit in the grid using the check_word_will_fit function.
//If it cannot fit, new starting positions and orientations are generated until it can fit.
//The word is then placed in the grid and the function prints the word.
void place_words(char grid[100][100],int rows,int columns,char str[]){
    static int SEED = 0;
    srand(time(0)+SEED);
    SEED+=3;
    //Generate random starting position (x and y) and orientation for the word.
    int x, y, orientation_deter;
    x = rand() % rows; 
    y = rand() % columns;
    orientation_deter = rand() % 3;
    //Continuously generate new starting positions and orientations until the word can fit in the grid.
    while(1){
    if(check_word_will_fit(grid,rows,columns,x,y, orientation_deter, str)){
            x = rand() % rows; 
            y = rand() % columns;
            orientation_deter = rand() % 3;
        }
        else{
            break;
        }
    }
    //If the orientation is 0 (horizontal) and the rows have enough space, print the word.
    if(orientation_deter==0&&rows>=strlen(str)){printf("%s ",str);}
    //If the orientation is 1 (vertical) and the columns have enough space, print the word.
    if(orientation_deter==1&&columns>=strlen(str)){printf("%s ",str);}
    //If the orientation is 2 (diagonal) and the rows and columns have enough space, print the word.
    if(orientation_deter==2&&rows>=strlen(str)&&columns>=strlen(str)){printf("%s ",str);}
    //Reverse the word and place it in the grid based on the starting position and orientation.
    reverse_string(str);
    for(int i=0 ; i<strlen(str) ; i++){
        grid[x][y] = str[i];
        //If the orientation is 0 (horizontal), increment the x position.
        if(orientation_deter==0){
            if(rows>=strlen(str)){
            x++;
            }
        }
        //If the orientation is 1 (vertical), increment the y position.
        else if(orientation_deter==1){
            if(columns>=strlen(str)){
            y++;
            }
        }
        //If the orientation is 2 (diagonal), increment both the x and y positions.
        else if(orientation_deter==2){
            if(rows>=strlen(str)&&columns>=strlen(str)){
            x++;y++;
            }
        }
    }
}
//This function prompts the user to input the number of words and the words themselves.
//It then calls the place_words function for each word to place them in the grid.
void words_input(char words[100][100],char grid[100][100],int rows,int columns){
    int num_words;
     static int a=0;
    printf("Enter the number of words = ");
    scanf("%d",&num_words);
    printf("Enter the words : ");
    //For each word, call the place_words function to place it in the grid.
    for(int i=0 ; i<num_words ; i++){
        scanf("%s", words[i]);
        while(!a){
            printf("Hidden words are ");
            a++;
        }
        place_words(grid,rows,columns,words[i]);
    }
}
//This function initializes the grid with all spaces being '-'.
//It takes the grid and number of rows and columns as input.
void random_letters_input(char grid[100][100],int rows,int columns){
    srand(time(NULL));
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<columns ; j++){
            char random_letter = rand() % 26;
            if(grid[i][j]=='-'){
                int random_letter_case_determiner = rand() % 2;    
                if(random_letter_case_determiner){
                grid[i][j] =  random_letter+97;
                }
                else{
                    grid[i][j] = random_letter+65;
                }
            }
        }
    }
}
void generate_grid(char grid[100][100],int rows,int columns){
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<columns ; j++){
            grid[i][j]='-';
        }
    }
}
//This function prints the grid. It takes the grid, number of rows and columns as input.
void print_grid(char grid[100][100],int rows,int column){
    printf("\n");
    for(int a=0 ; a<rows ; a++){
        for(int b=0 ; b<column ; b++){
            printf(" %c",grid[a][b]);
        }
        printf("\n");
    }
}
int main(){
    char grid[100][100],words[100][100],words_entered[100];
    int rows,columns;
    printf("Enter the rows of grid = ");
    scanf("%d",&rows);
    printf("Enter the columns of grid = ");
    scanf("%d",&columns);
   
    generate_grid(grid,rows,columns);
    words_input(words,grid,rows,columns);
    random_letters_input(grid,rows,columns);
    print_grid(grid,rows,columns);
}