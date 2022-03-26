#include <stdio.h>

int kamla_kaj_count = 0;

void kamla_printer ( char arr1[], int arr1_len) {
    for ( int i = 0; i < arr1_len -1 ; i++ ) { printf("%c", arr1[i]);}
}


int func(char arr[], char arr1[], int ghor, int malikerIndex, int char_input_number, int arr1_len) {
    if (ghor > 0){
        // malik
        for (int i = 0; i < char_input_number; i++) {
       
                arr1[malikerIndex] = arr[i];
                func(arr, arr1, ghor-1, malikerIndex+1, char_input_number, arr1_len);
            
        }
         
    }
    else if (ghor == 0) {
        //kamla
        
        for (int i =0; i < char_input_number; i++ ) {
            kamla_printer(arr1, arr1_len);
            printf("%c\n", arr[i]);
            kamla_kaj_count++;
        }

    }
}
int arr_duplicate_checker( char arr[], char ch,  int counter) {
    for (int i = 0; i <= counter; i++ ) {
        if ( arr[i] == ch) {
            return 0;
        }
    }
    return 1;
}

void repeater() {
    kamla_kaj_count = 0;
    int ghor, char_input_number;
    printf("Please enter the number of characters: ");
    fflush(stdin);
    scanf("%d", &char_input_number);
    printf("Please enter the length of the word: ");
    fflush(stdin);
    scanf("%d", &ghor);
    char char_arr[char_input_number];
    int counter = 0;
    for (int i =0; i< char_input_number; i++) {
        int ch;
        printf("%d. character: ", i+1);
        //scanf(" %c", &char_arr[i]);
        fflush(stdin);
        scanf(" %c", &ch);
        
        if (i == 0) { char_arr[counter] = ch; counter++;}
        else if (arr_duplicate_checker (char_arr, ch, counter)) {
             char_arr[counter] = ch;
             counter++;
        }
    }

    //counter = char_input_number;
    char arr1[ghor];
    func(char_arr, arr1, ghor -1, 0, counter, ghor);
    
    printf("Total Permutations: %d\n" , kamla_kaj_count);
}
int main() {
    
    
    while(1) {
        repeater();
        char ch;
        printf("Type Q to QUIT the application Or Type any keys to restart the application\n");
        fflush(stdin);
        scanf("%c", &ch);
        if(ch == 'Q') {
            break;
        }
    }

    return 0;
}