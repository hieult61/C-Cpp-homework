#include <stdio.h>
#include <string.h>

char* alphabet[] = {" ","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z","1","2","3","4","5","6","7","8","9","0"};
char* morse_code[] = {"/",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----"};
int index (char* s[], char* word){
    for (int i = 0; i < 36; i++)
        if (!strcmp(s[i], word))
            return i;
}
char* decode_Morse (char *s)
{
    char plain_text[]= "";
    int i = 0;
    while (i < strlen(s)){
        char word[] = "";
        while (i < strlen(s) && s[i] != ' '){
        	char temp[1] = {s[i]};
            strcat (word, temp);
            i++;
        }
        strcat (plain_text, alphabet[index(morse_code, word)]);
        i++;
    }
    return plain_text;
}
int main(){
    //Code your solution here
    char* s;
    gets (s);
    printf ("%s", decode_Morse(s));
    return 0;
}
