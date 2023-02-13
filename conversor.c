#include <stdio.h>
#include <math.h>
#include <string.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

void binary_to_hexadecimal(char binary[]) {
    int i, decimal = 0, length = strlen(binary);
    char hexadecimal[100];

    // Convertir binario a decimal
    for (i = 0; binary[i]; i++) {
        decimal += (binary[i] - '0') * pow(2, length - i - 1);
    }

    // Convertir decimal a hexadecimal
    i = 0;
    while (decimal != 0) {
        int temp = 0;
        temp = decimal % 16;
        if (temp < 10) {
            hexadecimal[i] = temp + 48;
            i++;
        } else {
            hexadecimal[i] = temp + 55;
            i++;
        }
        decimal /= 16;
    }

    // Mostrar resultado en orden inverso
    printf("\nEl número binario %s en hexadecimal es: 0x", binary);
    for (i = strlen(hexadecimal) - 1; i >= 0; i--) {
        printf("%c", hexadecimal[i]);
    }
}

void hexadecimal_to_binary(char hexadecimal[]) {
    int i, j, decimal = 0, length = strlen(hexadecimal);
    char binary[100];

    // Convertir hexadecimal a decimal
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - 48) * pow(16, j);
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 55) * pow(16, j);
        }
    }

    // Convertir decimal a binario
    i = 0;
    while (decimal != 0) {
        binary[i] = decimal % 2 + 48;
        decimal /= 2;
        i++;
    }

    // Mostrar resultado en orden inverso
    printf("\nEl número hexadecimal %s en binario es: ", hexadecimal);
    for (i = strlen(binary) - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
}

int hexadecimal_to_decimal(char hexadecimal[]) {
    int i, decimal = 0, length = strlen(hexadecimal);

    // Convertir hexadecimal a decimal
    for (i = length - 1; i >= 0; i--) {
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            decimal += (hexadecimal[i] - 48) * pow(16, length - i - 1);
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            decimal += (hexadecimal[i] - 55) * pow(16, length - i - 1);
        }
    }

    return decimal;
}

void decimal_to_hexadecimal(int decimal, char hexadecimal[]) {
    int i = 0, remainder;

    while (decimal != 0) {
        remainder = decimal % 16;

        if (remainder < 10) {
            hexadecimal[i++] = remainder + 48;
        } else {
            hexadecimal[i++] = remainder + 55;
        }

        decimal /= 16;
    }

    hexadecimal[i] = '\0';

    strrev(hexadecimal);
}

void decimal_to_binary(int decimal, char binary[]) {
    int i = 0, remainder;

    while (decimal != 0) {
        binary[i++] = decimal % 2 + 48;
        decimal /= 2;
    }

    binary[i] = '\0';

    strrev(binary);
}

int binary_to_decimal(char binary[]) {
    int i, decimal = 0;
    int len = strlen(binary);

    for (i = 0; i < len; i++) {
        decimal += (binary[i] - 48) * pow(2, len - i - 1);
    }

    return decimal;
}

int main() {
    char binary[100];
    char binary2[100];
    char binary3[100];
    char hexadecimal[100];
    char hexadecimal2[100];
    char hexadecimal3[100];
    int decimal;
    int decimal2;
    int decimal3;
    int decimal4;

    // Pedir número binario
    printf("Ingrese un número binario: ");
    scanf("%s", binary);

    // Pedir número hexadecimal
    printf("Ingrese un número hexadecimal: 0x");
    scanf("%s", hexadecimal);

    // Pedir número hexadecimal
    printf("Ingrese un número hexadecimal: 0x");
    scanf("%s", hexadecimal2);

    // Pedir número decimal
    printf("Ingrese un número decimal: ");
    scanf("%d", &decimal2);

     // Pedir número decimal
    printf("Ingrese un número decimal: ");
    scanf("%d", &decimal3);

    // Pedir número binario
    printf("Ingrese un número binario: ");
    scanf("%s", binary3);

    // Convertir binario a hexadecimal
    binary_to_hexadecimal(binary);

    // Convertir hexadecimal a binario
    hexadecimal_to_binary(hexadecimal);

    // Convertir hexadecimal a decimal
    decimal = hexadecimal_to_decimal(hexadecimal2);
    // Mostrar resultado
    printf("\nEl número hexadecimal %s en decimal es: %d", hexadecimal2, decimal);

    // Convertir decimal a hexadecimal
    decimal_to_hexadecimal(decimal2, hexadecimal3);
    // Mostrar resultado
    printf("\nEl número decimal %d en hexadecimal es: 0x%s", decimal2, hexadecimal3);

    // Convertir decimal a binario
    decimal_to_binary(decimal3, binary2);
    // Mostrar resultado
    printf("\nEl número decimal %d en binario es: %s", decimal3, binary2);
    
    // Convertir binario a decimal
    decimal4 = binary_to_decimal(binary3);
    // Mostrar resultado
    printf("\nEl número binario %s en decimal es: %d", binary3, decimal4);


    return 0;
}

