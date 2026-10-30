// Zadania 3.2
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//3.2.1 Napisz funkcje ktora otrzymujaca jako argumenty wskazniki do dowch zmiennych typu int, ktora zwraca jako wartosc mniejsza z liczb wskazywanych przez argumenty
/*
int czy_mniejsza(int *a, int*b) {
    if(*a < *b){
        return *a;
    }
    else{
        return *b;
    }
}

int main(){
    int x = 7, y = 8;
    printf("Mniejsza liczba to: %d\n", czy_mniejsza(&x,&y));
    return 0;
}
*/
//3.2.2 Napisz funkcje otrzymujaca jako arugmenty wskazniki do dwoch zmiennych typu int, ktora zwraca jako wartosc wskaznik na zmienna przechowujaca mniejsza z liczb wskazanych przez arguemnty
/*
int* mniejsza_liczba(int *a, int *b) {
    if (*a < *b) {
        return a;  }
    else {
        return b;
    }
}

int zadanie_main_2(void) {
    int x = 10, y = 5;
    int *wynik = mniejsza_liczba(&x, &y);
    printf("Mniejsza liczba to: %d\n", *wynik);
    return 0;
}
*/

//3.2.3 Napisz funkcję otrzymującą jako arguemnty wskaźnik do dwóch zmiennych typu int, która zamienia ze sobą wartości wskazywanych zmiennych
/*
void zamien(int *a, int *b){
    int pom;
    pom = *a;
    *a = *b;
    *b = pom;

}

int zadanie_main_3(void) {
    int x = 10, y = 5;
    printf("Przed zamianą: x = %d, y = %d\n", x, y);
    zamien(&x, &y);
    printf("Po zamianie: x = %d, y = %d\n", x, y);

    return 0;
}
*/

//3.2.4 Napisz funkcję otrzymującą jako argumenty wskaźniki do dwóch zmiennych typu int, która zamieniaze sobą wartości wskazywanych zmiennych tylko wtedy,gdy wskazywana przez drugi argument zmienna jest mniejsza od zmiennej wskazywanej przez pierwszy argument
/*
void zamien(int *a, int *b){
    int pom;
    if(*a > *b){
        pom = *a;
        *a = *b;
        *b = pom;
    }
}

int zadanie_main_4(void){
    int x = 12, y = 10;
    printf("Przed zamianą: x = %d, y = %d\n", x, y);
    zamien(&x, &y);
    printf("Po zamianie: x = %d, y = %d\n", x, y);

    return 0;
}
*/

//3.2.5 Napisz funkcje ktorej argumentami sa dwa wskazniki do stalych typu int zas zwracana wartoscia jest suma wartosci zmiennych wskazywanych przez argumenty
/*
int suma_wartosci(const int *a, const int *b) {
    return *a + *b;
}

int zadanie_main_5(void) {
    int x = 10, y = 20;
    int wynik = suma_wartosci(&x, &y);
    printf("Suma wartości zmiennych x i y wynosi: %d\n", wynik);
    return 0;
}

*/
//3.2.6 Napisz funkcje, ktorej argumentami sa n typu int oraz w wskaznik do int ktora przepisuje wartosc n do zmiennej wskazywanej przez w
/*
void przepisz(int n, int *w){
    *w = n;
}

int zadanie_main_6(void){
    int x = 5;
        printf("Przed przepisaniem: x = %d\n", x);
    przepisz(10, &x);
    printf("Po przepisaniu: x = %d\n", x);
    return 0;
}
*/
//3.2.9 Napisz bezargumentowa funkcje ktora rezerwuje pamiec dla pojedynczej zmiennej typu int i zwraca jako wartosc wskaznik do niej
/*
int *alokuj(){
    return malloc(sizeof(int));
}
*/

//3.2.10 Napisz bezargumentowa funkcje, ktora rezerwuje pamiec dla pojedynczej zmiennej typu double i zwraca jako wartosc wskaznik do niej
/*
double *alokuj(){
    return malloc(sizeof(double));
}
*/

// 3.2.11
int *alokuj(unsigned int n){
    return malloc(n*sizeof(int));
}

// 3.2.12
/*
// Napisz funkcję, która dostaje jako argument dodatnią liczbę całkowitą n,
// rezerwuje w pamięci blok n zmiennych typu double i zwraca jako wartość wskaźnik
// do początku zarezerwowanego bloku pamięci.
*/
double *alokuj_double(unsigned int n){
    return malloc(n* sizeof(double));
}

// 3.2.13
double wywolaj(double (*fun)(int arg), int a){
    return fun(a);
}

// 3.2.14
/*
// Napisz funkcję, która otrzymuje trzy argumenty:
    - dwa wskaźniki na funkcje o jednym argumencie typu int zwracające wartość typu int,
    - wartość n typu unsigned int,
// i zwraca true, jeżeli otrzymane w argumentach funkcje są równe dla wartości
// od 0 do n i false w przeciwnym przypadku
*/
bool porownaj_funkcje(int (*f1)(int), int(*f2)(int), unsigned int n){
    for (unsigned int i=0; i<=n; i++){
        if (f1(i) != f2(i)) return false;
    }
    return true;
}

// 3.2.15
void przepisz(int const *a, int *b){
    *b = *a;
}

// 3.2.16
void przepisz_staly(int const *a, int *const b){
    *b= *a;
}
