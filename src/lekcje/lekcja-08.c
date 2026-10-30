#include<stdio.h>
#include<stdlib.h>

/*
    6.2.1 Napisz funkcję, która dostaje jako argument dodatnie liczby całkowite n i m,
// tworzy dynamiczną dwuwymiarową tablicę tablic elementów typu int o wymiarach n na m,
// i zwraca jako wartość wskaźnik do niej.
*/
int **stworz_tab2d(unsigned int n, unsigned int m){
    int **tab = malloc(n * sizeof(*tab));
    if (!tab) return NULL;
    for (unsigned int i=0; i<n; i++){
        tab[i] = malloc(m * sizeof(int));
        if (!tab[i]){
            for (unsigned int j=0; j<i; j++) free(tab[j]);
            free(tab);
            return NULL;
        }
    }
    return tab;
}

/*
    6.2.2 Napisz funkcję, która dostaje jako argument dodatnie liczby całkowite n i m,
// tworzy dynamiczną dwuwymiarową tablicę elementów typu int o wymiarach n na m i zwraca
// jako wartość wskaźnik do niej.
*/
int *stworz_tab2d_flat(unsigned int n, unsigned int m){
    int *tab = malloc(n * m * sizeof(*tab));
    return tab;
}

/*
    6.2.3 Napisz funkcję, która dostaje jako argumenty wskaźnik do dwu- wymiarowej tablicy
// tablic elementów typu int oraz jej wymiary: do- datnie liczby całkowite n i m, i usuwa
// z pamięci otrzymaną tablicę.
*/
void usun_tab2d(int **tab, unsigned int n){
    for (unsigned int i=0; i<n; i++) free(tab[i]);
    free(tab);
}

/*
    6.2.4 Napisz funkcję, która dostaje jako argumenty wskaźnik do tablicy dwuwymiarowej
// elementów typu int oraz jej wymiary wymiary n i m, i usuwa z pamięci otrzymaną tablicę.
*/
void usun_tab2d_flat(int *tab){
    free(tab);
}

/*
    6.2.5 Rozwiąż zadania 6.2.1 i 6.2.3 w wersji z trójwymiarowymi tablicami tablic. 
*/
int ***stworz_tab3d(unsigned int n, unsigned int m, unsigned int k) {
    int ***tab = malloc(n * sizeof(int**));
    if (!tab) return NULL;
    for (unsigned int i=0; i<n; i++) {
        tab[i] = malloc(m * sizeof(int*));
        if (!tab[i]){
            for (unsigned int j=0; j<i; j++) free(tab[j]);
            free(tab);
            return NULL;
        }
        for (unsigned int j=0; j<m; j++) {
            tab[i][j] = malloc(k * sizeof(int));
            if (!tab[i][j]){
                for (unsigned int l=0; l<j; l++) free(tab[i][l]);
                free(tab[i]);
                for (unsigned int l=0; l<i; l++){
                    for (unsigned int m2=0; m2<m; m2++) free(tab[l][m2]);
                    free(tab[l]);
                }
                free(tab);
                return NULL;
            }
        }
    }
    return tab;
}

void usun_tab3d(int ***tab, unsigned int n, unsigned int m) {
    for (unsigned int i = 0; i < n; i++){
        for (unsigned int j=0; j<m; j++) free(tab[i][j]);
        free(tab[i]);
    }
    free(tab);
}

/*
    6.2.6 Rozwiąż zadania 6.2.2 i 6.2.4 w wersji z tablicami trójwymiarowymi. 
*/
int *stworz_tab3d_flat(unsigned int n, unsigned int m, unsigned int k) {
    int *tab = malloc(n * m * k * sizeof(int));
    return tab;
}

void usun_tab3d_flat(int *tab) {
    free(tab);
}

/*
    6.2.7 Napisz funkcję, która dostaje jako argument dodatnią liczbę całkowitą n,
// tworzy dynamiczną dwuwymiarową trójkątną tablicę tablic elementów typu int o wymiarach
// n na n i zwraca jako wartość wskaźnik do niej.
*/
int **stworz_tab2d_trojkat(unsigned int n){
    int **tab = malloc(n * sizeof(int*));
    if (!tab) return NULL;
    for (unsigned int i=0; i<n; i++){
        tab[i] = malloc((i+1) * sizeof(int));
        if (!tab[i]){
            for (unsigned int j=0; j<i; j++) free(tab[j]);
            free(tab);
            return NULL;
        }
    }
    return tab;
}

/*
    6.2.8 Napisz funkcję, która dostaje w argumentach dwuwymiarową tablicę elementów typu int,
// o pierwszym wymiarze podanym jako drugi argument funkcji oraz drugim wymiarze równym 100 i wypełnia ją zerami.
*/
void wyzeruj2d_100(int tab[][100], unsigned int n){
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<100; j++){
            tab[i][j] = 0;
        }
    }
}

/*
    6.2.9 Napisz funkcję, która dostaje w argumentach dwuwymiarową tablicę tablic elementów
// typu int oraz jej wymiary n i m, i wypełnia ją zerami.
*/
void wyzeruj2d_dyn(int **tab, unsigned int n, unsigned int m){
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<m; j++){
            tab[i][j] = 0;
        }
    }
}

/*
    6.2.10 Napisz funkcję, która dostaje w argumentach tablicę dwuwymiarową elementów
// typu int oraz jej wymiary n i m, i wypełnia ją zerami.
*/
void wyzeruj2d(unsigned int n, unsigned int m, int tab[][m]){
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<m; j++){
            tab[i][j] = 0;
        }
    }
}

/*
    6.2.11 Napisz funkcję, która dostaje w argumentach tablicę dwuwymiarową elementów
// typu int, o pierwszym wymiarze podanym jako drugi argument funkcji oraz drugim wymiarze
// równym 100, która to funkcja zwraca jako wartość sumę wartości elementów tablicy.
*/
int suma2d_100(int tab[][100], unsigned int n){
    int suma = 0;
    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<100; j++)
            suma += tab[i][j];
    return suma;
}

/*
    6.2.12 Napisz funkcję, która dostaje w argumentach dwuwymiarową tablicę tablic o elementach
// typu int oraz jej wymiary n i m, i zwraca jako wartość sumę wartości elementów tablicy.
*/
int suma2d_dyn(int **tab, unsigned int n, unsigned int m){
    int suma = 0;
    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<m; j++)
            suma += tab[i][j];
    return suma; 
}

/*
    6.2.13 Napisz funkcję, która dostaje w argumentach tablicę dwuwymiarową o elementach typu
// int oraz jej wymiary n i m, i zwraca jako wartość sumę wartości elementów tablicy.
*/
int suma2d(unsigned int n, unsigned int m, int tab[][m]){
    int suma = 0;
    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<m; j++)
            suma += tab[i][j];
    return suma;
}

/*
    6.2.14 Napisz funkcję, która dostaje w argumentach tablicę trójwymiarową o elementach typu
// int o wymiarach 100 x 100 x 100, i zwraca jako wartość sumę wartości elementów tablicy.
*/
int suma3d_100(int tab[100][100][100]){
    int suma = 0;
    for (unsigned int i=0; i<100; i++)
        for (unsigned int j=0; j<100; j++)
            for (unsigned int k=0; k<100; k++)
                suma += tab[i][j][k];
    return suma;
}

/*
    6.2.15 Napisz funkcję, która dostaje w argumentach dodatnią liczbę całkowitą n oraz tablicę
// trójwymiarową o elementach typu int o wymiarach n x 100 x 100, i zwraca jako wartość sumę
// wartości elementów otrzymanej tablicy.
*/
int suma3d_n_100(int n, int tab[][100][100]){
    int suma = 0;
    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<100; j++)
            for (unsigned int k=0; k<100; k++)
                suma += tab[i][j][k];
    return suma;
}

/*
    6.2.16 Napisz funkcję, która dostaje jako argumenty dwuwymiarową tablicę tablic o elementach
// typu int oraz jej wymiary, i zwraca jako wartość indeks wiersza o największej średniej wartości elementów.
// Przyjmujemy, że dwa elementy leżą w tym samym wierszu, jeżeli mają taki sam pierwszy indeks.
*/
int indeks_max_srednia(int **tab, unsigned int n, unsigned int m){
    int indeks = 0;
    double max_srednia = -1e9;
    for (unsigned int i=0; i<n; i++){
        double suma = 0;
        for (unsigned int j=0; j<m; j++)
            suma += tab[i][j];
        double srednia = suma/m;
        if (srednia > max_srednia){
            max_srednia = srednia;
            indeks = i;
        }
    }
    return indeks;
}

/*
    6.2.17 Napisz funkcję, która dostaje jako argumenty dwuwymiarową tablicę tablic o elementach
// typu int oraz jej wymiary, i zwraca największą spośród średnich wartości elementów poszczególnych
// wierszy. Przyjmujemy, że dwa elementy leżą w tym samym wierszu, jeżeli mają taki sam pierwszy indeks.
*/
double max_srednia_wiersz(int **tab, unsigned int n, unsigned int m){
    double max_srednia = -1e9;
    for (unsigned int i=0; i<n; i++){
        double suma = 0;
        for (unsigned int j=0; j<m; j++)
            suma += tab[i][j];
        double srednia = suma/m;
        if (srednia > max_srednia)
            max_srednia = srednia;
    }
    return max_srednia;
}

/*
    6.2.18 Napisz funkcję, która dostaje jako argument dwuwymiarową tablicę tablic o elementach typu
// int oraz jej wymiary, i wypisuje jej zawartość na standardowym wyjściu w taki sposób, żeby
// kolejne wiersze tablicy zostały wypisane w oddzielnych wierszach standardowego wyjścia.
// Przyjmujemy, że dwa elementy leżą w tym samym wierszu, jeżeli mają taki sam drugi indeks.
*/
void wypisz2d_dyn(int **tab, unsigned int n, unsigned int m){
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<m; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
}

/*
    6.2.19 Napisz funkcję, która dostaje jako argumenty dwie dwuwymiarowe tablice tablic o elementach
// typu int oraz ich wymiary, i przepisuje zawartość pierwszej tablicy do drugiej tablicy.
*/
void kopiuj2d_dyn(int **tab1, int **tab2, unsigned int n, unsigned int m){
    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<m; j++)
            tab1[i][j] = tab2[i][j];
}

/*
    6.2.20 Napisz funkcję, która dostaje jako argumenty dwie dwuwymiarowe tablice tablic o elementach
// typu int oraz ich wymiary, i zamienia zawartości obu tablic.
*/
void zamien2d_dyn(int **tab1, int **tab2, unsigned int n, unsigned int m){
    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<m; j++){
            int temp = tab1[i][j];
            tab1[i][j] = tab2[i][j];
            tab2[i][j] = temp;
        }
}

/*
    6.2.21 Napisz funkcję, która dostaje jako argumenty dwuwymiarową tablicę tablic o elementach
// typu int oraz jej wymiary, i odwraca kolejność elementów we wszystkich wierszach otrzymanej tablicy
    (przyjmujemy, że dwa elementy tablicy leżą w tym samym wierszu, jeżeli mają taką samą pierwszą współrzędną).
*/
void odwroc_wiersze2d_dyn(int **tab, unsigned int n, unsigned int m){
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<m/2; j++){
            int temp = tab[i][j];
            tab[i][j] = tab[i][m-1-j];
            tab[i][m-1-j] = temp;
        }
    }
}

/*
    6.2.22 Napisz funkcję, która dostaje jako argumenty tablicę dwuwymiarową o elementach typu int oraz jej wymiary,
// i odwraca kolejność elementów we wszystkich wierszach otrzymanej tablicy
    (przyjmujemy, że dwa elementy tablicy leżą w tym samym wierszu, jeżeli mają taką samą pierwszą współrzędną).
*/
void odwroc_wiersze2d(unsigned int n, unsigned int m, int tab[][m]){
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<m/2; j++){
            int temp = tab[i][j];
            tab[i][j] = tab[i][m-1-j];
            tab[i][m-1-j] = temp;
        }
    }
}

/*
    6.2.23 Napisz funkcję, która dostaje jako argumenty dwuwymiarową tablicę tablic o elementach typu int oraz jej wymiary,
// i zmienia kolejność wierszy w tablicy w taki sposób, że wiersz pierwszy ma się znaleźć na miejscu drugiego,
// wiersz drugi na miejscu trzeciego itd., natomiast ostatni wiersz ma się znaleźć na miejscu pierwszego
    (przyjmujemy, że dwa elementy tablicy leżą w tym samym wierszu, jeżeli mają taką samą pierwszą współrzędną).
*/
void przesun_wiersze2d_dyn(int **tab, unsigned int n, unsigned int m){
    int *temp = tab[0];
    for (unsigned int i=0; i<n-1; i++){
        tab[i] = tab[i+1];
    }
    tab[n-1] = temp;
}

/*
    6.2.24 Napisz funkcję, która dostaje jako argumenty dwuwymiarową tablicę tablic o elementach typu int oraz jej wymiary,
// i zmienia kolejność kolumn w tablicy w taki sposób, że kolumna pierwsza ma się znaleźć na miejscu drugiej,
// kolumna druga na miejscu trzeciej itd., natomiast ostatnia kolumna ma się znaleźć na miejscu pierwszej
    (przyjmujemy, że dwa elementy tablicy leżą w tej samej kolumnie, jeżeli mają taką samą drugą współrzędną).
*/
void przesun_kolumny2d_dyn(int **tab, unsigned int n, unsigned int m){
    for (unsigned int i=0; i<n; i++){
        int temp = tab[i][0];
        for (unsigned int j=0; j<m-1; j++){
            tab[i][j] = tab[i][j+1];
        }
        tab[i][m-1] = temp;
    }
}

/*
    6.2.25 Napisz funkcję, która dostaje jako argumenty dwuwymiarową kwadratową tablicę tablic
// tab o elementach typu int oraz jej wymiar, i zmienia kolejność elementów w otrzymanej tablicy
// w następujący sposób: dla dowolnych k i j element tab[k][j] ma zostać zamieniony miejscami z elementem tab[j][k].
*/
void transponuj_kwadrat_dyn(int **tab, unsigned int n){
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=i+1; j<n; j++){
            int temp = tab[i][j];
            tab[i][j] = tab[j][i];
            tab[j][i] = temp;
        }
    }
}

/*
    6.2.26 Napisz funkcję, która dostaje jako argumenty dwuwymiarową prostokątną tablicę tablic tab1
// o wymiarach n x m i elementach typu int oraz jej wymiary, i zwraca jako wartość wskaźnik do nowo
// utworzonej dwuwymiarowej tablicy tablic tab2 o wymiarach m x n zawierającej transponowaną macierz
    przechowywaną w tablicy tab1 (czyli dla dowolnych k i j zachodzi tab1[k][j]=tab2[j][k]).
*/
int **transponuj2d_dyn(int **tab1, unsigned int n, unsigned int m){
    int **tab2 = malloc(m * sizeof(*tab2));
    if (!tab2) return NULL;
    for (unsigned int i=0; i<m; i++){
        tab2[i] = malloc(n* sizeof(**tab2));
        if (!tab2[i]){
            for (unsigned int j=0; j<i; j++) {free(tab2[j]);}
            free(tab2);
            return NULL;
        }
        for (unsigned int j=0; j<n; j++){
            tab2[i][j] = tab1[j][i];
        }
    }
    return tab2;
}

/*
    6.2.27 Napisz funkcję, która dostaje jako argumenty dodatnią liczbę całkowitą n oraz trójwymiarową
// tablicę tablic tab elementów typu int o wymiarach n x n x n, i zamienia elementy tablicy w taki sposób,
    że dla dowolnych i, j, k z zakresu od 0 do n − 1, wartość z komórki tab[i][j][k] po wykonaniu funkcji
// ma się znajdować w komórce tab[k][i][j].
*/
void permutuj3d_nnn(int ***tab, unsigned int n){
    int ***temp = malloc(n * sizeof (*temp));
    for (unsigned int i=0; i<n; i++){
        temp[i] = malloc(n * sizeof(**temp));
        for (unsigned int j=0; j<n; j++){
            temp[i][j] = malloc(n * sizeof(***temp));
        }
    }
    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<n; j++)
            for (unsigned int k=0; k<n; k++)
                temp[k][i][j] = tab[i][j][k];
    for (unsigned int i=0; i<n; i++)
        for (unsigned int j=0; j<n; j++)
            for (unsigned int k=0; k<n; k++)
                tab[i][j][k] = temp[i][j][k];
    for (unsigned int i=0; i<n; i++){
        for (unsigned int j=0; j<n; j++)
            free(temp[i][j]);
        free(temp[i]);
    }
    free(temp);
}

/*
    6.2.28 Napisz funkcję, która dostaje jako argumenty dodatnią liczbę całkowitą n oraz trójwymiarową
// tablicę tab elementów typu int o wymiarach n x n x n, i zamienia elementy tablicy w taki sposób,
    że dla dowolnych i, j, k z zakresu od 0 do n − 1, takich że i ≠ j ≠ k,
// wartość z komórki tab[i][j][k] po wykonaniu funkcji ma się znajdować w komórce tab[k][i][j].
*/
void permutuj3d_nnn_rozne(int ***tab, unsigned int n) {
    int ***tmp = malloc(n * sizeof(*tmp));
    for (unsigned int i = 0; i < n; i++) {
        tmp[i] = malloc(n * sizeof(**tmp));
        for (unsigned int j = 0; j < n; j++)
            tmp[i][j] = malloc(n * sizeof(***tmp));
    }
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < n; j++)
            for (unsigned int k = 0; k < n; k++)
                if (i != j && j != k && i != k)
                    tmp[k][i][j] = tab[i][j][k];
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < n; j++)
            for (unsigned int k = 0; k < n; k++)
                if (i != j && j != k && i != k)
                    tab[i][j][k] = tmp[i][j][k];
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++)
            free(tmp[i][j]);
        free(tmp[i]);
    }
    free(tmp);
}

/*
    6.2.29 Napisz funkcję, która dostaje jako argument trójwymiarową tablicę tab elementów typu int
// o wymiarach 100 x 100 x 100, i zamienia elementy tablicy w taki sposób, że dla dowolnych i, j, k
// z zakresu od 0 do 99, takich że i ≠ j ≠ k,
// wartość z komórki tab[i][j][k] po wykonaniu funkcji ma się znajdować w komórce tab[k][i][j].
*/
void permutuj3d_100_rozne(int tab[100][100][100]) {
    int tmp[100][100][100];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++)
                if (i != j && j != k && i != k)
                    tmp[k][i][j] = tab[i][j][k];
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            for (int k = 0; k < 100; k++)
                if (i != j && j != k && i != k)
                    tab[i][j][k] = tmp[i][j][k];
}

/*
    6.2.30 Napisz funkcję, która otrzymuje w argumentach dwie kwadratowe tablice tablic elementów
// typu int oraz ich wspólny wymiar, i zwraca jako wartość wynik dodawania macierzy
// przechowywanych w przekazanych argumentach.
// Wynik powinien zostać zwrócony w nowo utworzonej tablicy tablic.
*/
int **dodaj_macierze_dyn(int **tab1, int **tab2, unsigned int n) {
    int **wynik = malloc(n * sizeof(*wynik));
    if (!wynik) return NULL;
    for (unsigned int i = 0; i < n; i++) {
        wynik[i] = malloc(n * sizeof(**wynik));
        if (!wynik[i]) {
            for (unsigned int j = 0; j < i; j++) free(wynik[j]);
            free(wynik);
            return NULL;
        }
        for (unsigned int j = 0; j < n; j++)
            wynik[i][j] = tab1[i][j] + tab2[i][j];
    }
    return wynik;
}

/*
    6.2.31 Napisz funkcję, która otrzymuje w argumentach dwie kwadratowe tablice
// dwuwymiarowe elementów typu int oraz ich wspólny wymiar, i zwraca jako wartość wynik
// dodawania macierzy przechowywanych w przekazanych argumentach.
// Wynik powinien zostać zwrócony w nowo utworzonej tablicy dwuwymiarowej.
*/
void dodaj_macierze(int n, int tab1[][n], int tab2[][n], int wynik[][n]){
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            wynik[i][j] = tab1[i][j] + tab2[i][j];
}

/*
    6.2.32 Napisz funkcję, która otrzymuje w argumentach dwie kwadratowe tablice tablic
// elementów typu int oraz ich wspólny wymiar, i zwraca jako wartość wynik mnożenia macierzy
// przechowywanych w przekazanych argumentach.
// Wynik powinien zostać zwrócony w nowo utworzonej tablicy tablic.
*/
int **mnoz_macierze_dyn(int **tab1, int **tab2, unsigned int n) {
    int **wynik = malloc(n * sizeof(*wynik));
    if (!wynik) return NULL;
    for (unsigned int i = 0; i < n; i++) {
        wynik[i] = malloc(n * sizeof(**wynik));
        if (!wynik[i]) {
            for (unsigned int j = 0; j < i; j++) free(wynik[j]);
            free(wynik);
            return NULL;
        }
        for (unsigned int j = 0; j < n; j++) {
            wynik[i][j] = 0;
            for (unsigned int k = 0; k < n; k++)
                wynik[i][j] += tab1[i][k] * tab2[k][j];
        }
    }
    return wynik;
}

/*
    6.2.33 Napisz funkcję, która otrzymuje w argumentach trzy kwadratowe tablice tablic
// elementów typu int oraz ich wspólny wymiar, i zapisuje do trzeciej tablicy wynik mnożenia
// macierzy przechowywanych w dwóch pierwszych tablicach.
*/
void mnoz_macierze_dyn_do(int **tab1, int **tab2, int **wynik, unsigned int n){
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < n; j++) {
            wynik[i][j] = 0;
            for (unsigned int k = 0; k < n; k++)
                wynik[i][j] += tab1[i][k] * tab2[k][j];
        }
}

/*
    6.2.34 Napisz funkcję, która otrzymuje w argumentach dwie kwadratowe tablice
// dwuwymiarowe elementów typu int oraz ich wspólny wymiar,
// i zwraca jako wartość wynik mnożenia macierzy przechowywanych w przekazanych argumentach.
// Wynik powinien zostać zwrócony w nowo utworzonej tablicy dwuwymiarowej.
*/
void mnoz_macierze(int n, int tab1[][n], int tab2[][n], int wynik[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            wynik[i][j] = 0;
            for (int k = 0; k < n; k++)
                wynik[i][j] += tab1[i][k] * tab2[k][j];
        }
}

/*
    6.2.35 Napisz funkcję, która otrzymuje w argumentach dwie prostokątne dwuwymiarowe tablice tablic elementów
// typu int o wymiarach odpowiednio n x m i m x k oraz ich wymiary,
// i zwraca jako wartość wynik mnożenia macierzy przechowywanych w przekazanych argumentach.
// Wynik powinien zostać zwrócony w nowo utworzonej tablicy tablic.
*/
int **mnoz_macierze_prostokat_dyn(int **tab1, int **tab2, unsigned int n, unsigned int m, unsigned int k) {
    int **wynik = malloc(n * sizeof(*wynik));
    if (!wynik) return NULL;
    for (unsigned int i = 0; i < n; i++) {
        wynik[i] = malloc(k * sizeof(**wynik));
        if (!wynik[i]) {
            for (unsigned int j = 0; j < i; j++) free(wynik[j]);
            free(wynik);
            return NULL;
        }
        for (unsigned int j = 0; j < k; j++) {
            wynik[i][j] = 0;
            for (unsigned int l = 0; l < m; l++)
                wynik[i][j] += tab1[i][l] * tab2[l][j];
        }
    }
    return wynik;
}

/*
    6.2.36 Napisz funkcję otrzymującą dwa argumenty: dodatnią liczbę całkowitą n i dwuwymiarową
// kwadratową tablicę tablicelementów typu int o wymiarach n x n,
// i zwraca jako wartość wyznacznik macierzy przechowywanej w otrzymanej w argumencie tablicy.
*/
int wyznacznik_dyn(int **tab, unsigned int n) {
    if (n == 1) return tab[0][0];
    if (n == 2) return tab[0][0]*tab[1][1] - tab[0][1]*tab[1][0];
    int det = 0;
    for (unsigned int p = 0; p < n; p++) {
        int **minor = malloc((n-1) * sizeof(*minor));
        for (unsigned int i = 0; i < n-1; i++)
            minor[i] = malloc((n-1) * sizeof(**minor));
        for (unsigned int i = 1; i < n; i++) {
            unsigned int col = 0;
            for (unsigned int j = 0; j < n; j++) {
                if (j == p) continue;
                minor[i-1][col++] = tab[i][j];
            }
        }
        int sign = (p % 2 == 0) ? 1 : -1;
        det += sign * tab[0][p] * wyznacznik_dyn(minor, n-1);
        for (unsigned int i = 0; i < n-1; i++) free(minor[i]);
        free(minor);
    }
    return det;
}

/*
    6.2.37 Napisz funkcję otrzymującą dwa argumenty: dodatnią liczbę całkowitą n i kwadratową tablicę
// dwuwymiarową elementów typu int o wymiarach n x n,
// i zwraca jako wartość wyznacznik macierzy przechowywanej w otrzymanej w argumencie tablicy.
*/
int wyznacznik(int n, int tab[][n]) {
    if (n == 1) return tab[0][0];
    if (n == 2) return tab[0][0]*tab[1][1] - tab[0][1]*tab[1][0];
    int det = 0;
    for (int p = 0; p < n; p++) {
        int minor[n-1][n-1];
        for (int i = 1; i < n; i++) {
            int col = 0;
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                minor[i-1][col++] = tab[i][j];
            }
        }
        int sign = (p % 2 == 0) ? 1 : -1;
        det += sign * tab[0][p] * wyznacznik(n-1, minor);
    }
    return det;
}

int main(void) {
    return 0;
}
