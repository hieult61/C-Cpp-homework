#include <stdio.h>

int arr_index = 0;
int result[100] = {0};

void convert_to_binary (int n){
	if (n == 0){
		result[0] = 0;
		arr_index = 1;
	}
    int binary[100] = {0};
    while (n > 0){
        binary[arr_index++] = n%2;
        n = n/2; 
    }
    for (int i = 0; i<arr_index; i++)
		result[i] = binary[i];  
}

int power(int n){
    int temp = 1;
    while (n--)
       temp *= 2;
    return temp;
}

int setOddBits(int n)
{
	convert_to_binary (n);
    int output = 0;
    int i = 0;
    while (i < arr_index){
        if (i%2 == 0)
            result[i] = 1;
        i++;
    }
    for (int i = 0; i < arr_index; i++)
        output += result[i] * power(i);
    printf ("%d\n", output);
    return output;
}

int main(){
	int a = 0;
	printf ("%d", setOddBits(a));
}
