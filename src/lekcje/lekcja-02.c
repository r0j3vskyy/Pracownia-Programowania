// Zadania 1.3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1.3.1
/*
// Napisz program, który wczytuje ze standardowego wejścia liczbę całkowitą n
// i wypisuje na standardowe wyjście wartość bezwzględną z n.
*/
int main() {
    int n;
    printf("Podaj liczbe calkowita n: ");
    scanf("%d", &n);
    printf("Wartosc bezwzgledna z tej liczby to: %d\n", abs(n));


    printf("Wcisnij enter, aby zakonczyc...\n");
    getchar();
    getchar();
    return 0;
}

// 1.3.2
/*
// Napisz program, który wczytuje ze standardowego wejścia dwie liczby całkowite
// i wypisuje na standardowym wyjściu większą z nich (w przypadku gdy podane liczby
// są równe, program powinien wypisać którąkolwiek z nich)
*/
int zadanie_main_2(void) {
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    if (a > b) {
        printf("Liczba %d jest wieksza.", a); 
    }
    else if (b > a) {
        printf("Liczba %d jest wieksza.", b);
    }
    else {
        printf("Liczby sa rowne.");
    }

    getchar();
    getchar();
    return 0;
}

// 1.3.3
/*
// Napisz program, który wczytuje ze standardowego wejścia trzy liczby całkowite
// i wypisuje na standardowym wyjściu największą z ich wartości (pamiętaj o przypadku
// gdy wszystkie podane liczby lub dwie z nich są równe)
*/
int zadanie_main_3(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    if (a>b) {
        if (a>c) {
            printf("Liczba %d jest najwieksza.", a);
        }
        else {
            printf("Liczba %d jest najwieksza.", c);
        }
    }
    if (b>a) {
        if (b>c) {
            printf("Liczba %d jest najwieksza.", b);
        }
        else {
            printf("Liczba %d jest najwieksza.", c);            
        }
    }
    else {
        printf("Liczby sa rowne.");
    }

    getchar();
    getchar();
    return 0;
}

// 1.3.4
/*
// Napisz program, który wczytuje ze standardowego wejścia dwie liczby całkowite
// i wypisuje tą o większej wartości bezwzględnej.
*/
int zadanie_main_4(void) {
    int a,b;
    scanf("%d %d", &a, &b);
    if (abs(a)>abs(b)) {
        printf("%d", abs(a));
    }
    else {
        printf("%d", abs(b));
    }

    getchar();
    getchar();
    return 0;
}

// 1.3.5
/*
// Napisz program obliczający pole trójkąta na podstawie wymiarów podanych przez
// użytkownika. Użytkownik powinien mieć możliwość podania długości podstawy i wysokości
// lub wszystkich boków trójkąta.
*/
int zadanie_main_5(void) {
    int wybor;
    printf("Jesli chcesz policzyc pole trojkata z a*h/2 wpisz: 1. \n");
    printf("Jesli chcesz policzyc pole trojkata z 3 bokow wpisz: 2. \n");
    scanf("%d", &wybor);
    if (wybor == 1) {
        int a, h;
        scanf("%d %d", &a, &h);
        float pole = (float)a*h/2;
        printf("Pole trojkata: %lf", pole);
    }
    if (wybor == 2) {
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        float obw = (a+b+c)/2.0;
        float pole = sqrt(obw*(obw-a)*(obw-b)*(obw-c));
        printf("Pole trojkata: %lf", pole);
    }

    getchar();
    getchar();
    return 0;
}

// 1.3.6
/*
// Napisz program, który wczytuje ze standardowego wejścia współczynniki układu dwóch
// równań liniowych z dwoma niewiadomymi i wypisuje na standardowym wyjściu rozwiązanie
// układu równań. W przypadku nieskończonej liczby lub braku rozwiązań program powinien
// wypisać na standardowym wyjściu odpowiednią informację.
// Podpowiedź: zaimplementuj algorytm rozwiązywania układów równań metodą wyznaczników
    (inaczej nazywaną wzorami Cramera)
*/
int zadanie_main_6(void){
    double a1, b1, c1, a2, b2, c2;
    printf("Podaj wspolczynniki pierwszego rownania linowego:");
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    printf("Podaj wspolczynniki drugiego rownania liniowego:");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    double W = a1*b2 - a2*b1;
    double Wx = c1*b2 - c2*b1;
    double Wy = a1*c2 - a2*c1;

    if (W != 0){
        double x = Wx / W;
        double y = Wy / W;
        printf("Rozwiazanie: x= %lf, y= %lf\n", x, y);
    } else if (Wx == 0 && Wy == 0){
        printf("Uklad ma nieskonczenie wiele rozwiazan.\n");
    } else {
        printf("Uklad nie ma rozwiazan.\n");
    }
    getchar();
    getchar();
    return 0;
}

// 1.3.7
/*
// Napisz program, który wczytuje ze standardowego wejścia współczynniki równania
// kwadratowego z jedną niewiadomą i wypisuje na standardowym wyjściu wszystkie rozwiązania
// rzeczywiste tego równania lub odpowiednią informację w przypadku braku rozwiązań.
*/
int zadanie_main_7(void){
    double a, b, c;
    printf("Podaj wspolczynniki a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = b*b - 4*a*c;
    if (delta > 0){
        double x1 = (-b + sqrt(delta)) / (2*a);
        double x2 = (-b - sqrt(delta)) / (2*a);
        printf("Dwa pierwiastki: x1= %lf, x2= %lf\n", x1, x2);
    } else if (delta == 0){
        double x = -b / (2*a);
        printf("Jeden pierwiastek: x= %lf", x);
    } else {
        printf("Brak pierwiastkow rzeczywistych");
    }
    getchar();
    getchar();
    return 0;
}

// 1.3.8
/*
// Napisz program, który w zależności od wyboru użytkownika wczytuje ze standardowego
// wejścia wymiary: kwadratu, prostokąta lub trójkąta i wypisuje na standardowym
// wyjściu pole figury o wczytanych wymiarach.
*/
int zadanie_main_8(void){
    int wybor;
    printf("Wybierz figure: (1-kwadrat, 2-prostokat, 3-trojkat): ");
    scanf("%d", &wybor);

    if (wybor == 1){
        double a;
        printf("Podaj bok kwadratu: ");
        scanf("%lf", &a);
        printf("Pole kwadratu: %lf\n", a*a);
    } else if (wybor == 2){
        double a,b;
        printf("Podaj boki prostokata: ");
        scanf("%lf %lf", &a, &b);
        printf("Pole prostokata: %lf\n", a*b);
    } else if (wybor == 3){
        double a, h;
        printf("Podaj podstawe i wysokosc trojkata: ");
        scanf("%lf %lf", &a, &h);
        printf("Pole trojkata: %lf\n", 0.5*a*h);
    } else {
        printf("Nieznana figura.\n");
    }
    getchar();
    getchar();
}

// 1.3.9
/*
// Napisz program kalkulator, który wykonuje wybraną przez użytkownika operację arytmetyczną
// na dwóch wczytanych liczbach. Program powinien wczytywać dane ze standardowego
// wejścia i wypisywać wynik na standardowym wyjściu.
*/
int zadanie_main_9(void){
    double a, b, wynik;
    char op;
    printf("Podaj dwie liczby: ");
    scanf("%lf %lf", &a, &b);
    printf("Podaj operator (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op){
        case '+': wynik = a+b; break;
        case '-': wynik = a-b; break;
        case '*': wynik = a*b; break;
        case '/':
            if (b != 0) wynik = a/b;
            else {printf("Dzielenie przez zero jest niemozliwe!"); return 1;}
            break;
        default: printf("Nieznany operator.\n");
        return 1;
    }
    printf("Wynik: %lf\n", wynik);

    getchar();
    getchar();
    return 0;
}