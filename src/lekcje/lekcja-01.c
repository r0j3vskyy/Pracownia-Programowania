//Zadania: 1.2
#include <stdio.h>

int main() {
    int liczba;
    double liczba2;

    printf("Bardzo \n");
    printf("dlugi \n");
    printf("napis \n");

    printf("Napis zawierajacy rozne dziwne znaczki // \\ $ & %% \n");

    printf("Podaj liczbe calkowita: ");
    scanf("%d", &liczba);

    printf("Podaj liczbe wymierna: ");
    scanf("%lf", &liczba2);
    
    printf("Wprowadzona liczba calkowita to: %d\n", liczba);
    printf("Wprowadzona liczba wymierna to: %lf\n", liczba2);

    int a;
    int b;
    int c;
    printf("Podaj liczbe calkowita 1: ");
    scanf("%d", &a);
    printf("Podaj liczbe calkowita 2: ");
    scanf("%d", &b);
    printf("Podaj liczbe calkowita 3: ");
    scanf("%d", &c);
    printf("Liczba 1 to: %d\n", a);
    printf("Liczba 2 to: %d\n", b);
    printf("Liczba 3 to: %d\n", c);
    printf("Srednia tych liczb to: %lf\n", (a+b+c)/3.0);

    int d;
    printf("Podaj liczbe calkowita 4: ");
    scanf("%d", &d);
    printf("Liczba 4 wieksza o 1 to: %d\n", d+1);

    printf("Wcisnij enter, aby zakonczyc...\n");
    getchar();
    getchar();
    return 0;
}
