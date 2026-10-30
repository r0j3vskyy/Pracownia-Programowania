// Zadania 4.2
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
	4.2.1 Napisz funkcję, która otrzymuje dwa argumenty: nieujemną liczbę cał-
// kowitą n oraz n-elementową tablicę tab elementów typu int i:
// a) (r) nadaje wartość zero wszystkim elementom tablicy tab,
// b) (r) zapisuje do kolejnych elementów tablicy wartości równe ich in-
// deksom (do komórki o indeksie i funkcja ma zapisywać wartość i),
// c) podwaja wartość wszystkich elementów w tablicy tab,
// d) do wszystkich komórek tablicy tab wstawia wartości bezwzględne
// ich pierwotnych wartości.
*/
// a)
/*
// void zeruj ( int n, int tab[ n ] )
{
	for ( int i = 0 ; i < n ; i += 1 )
	{
		tab[ i ] = 0;
	}
}

// b)
// void index ( int n, int tab[ n ] )
{
	for ( int i = 0 ; i < n ; i += 1 )
	{
		tab[ i ] = i;
	}
}

// c)
// void podwajaj ( int n, int tab[ n ] )
{
	for ( int i = 0 ; i < n ; i += 1 )
	{
		tab[ i ] = tab[ i ] * 2;
	}
}

// d)
// void bezwzgledna ( int n, int tab[ n ] )
{
	for ( int i = 0 ; i < n ; i += 1 )
	{
		if ( tab[ i ] < 0 )
		{
			tab[ i ] = - tab[ i ];
		}
	}
}


// void wyswietl ( int n, int tab[ n ] )
{
	printf( "---\n" );

	for ( int i = 0 ; i < n ; i += 1 )
	{
		printf ( "%i \n", tab[ i ] );
	}
}


// int main()
{
	int n;

	scanf ( "%i", &n );

	int tab[ n ];

	for ( int i = 0 ; i < n ; i += 1 )
	{
		scanf ( "%i", &tab[ i ] );
	}

	wyswietl( n, tab );

	index( n, tab );

	wyswietl( n, tab );

	return 0;
}
*/
/*
    4.2.2 Napisz funckję, która otrzymuje dwa argumenty: dodatnią liczbę całkowitą n oraz n-elementową
// tablicę tab o elementach typu int i zwraca jako wartość:
// a) (r) średnią arytmetyczną elementów tablicy tab.
// b) sumę elementów tablicy tab
// c) sumę kwadratów elementów tablicy tab
*/
void oblicz(int n, int tab[], double *srednia, int *suma, int *suma_kw) {
    int suma_elementow = 0;
    int suma_elementow_kw = 0;
    for (int i = 0; i < n; i++) {
        suma_elementow += tab[i];
        suma_elementow_kw += tab[i] * tab[i];
    }
    *srednia = (double)suma_elementow / n;
    *suma = suma_elementow;
    *suma_kw = suma_elementow_kw;
}
int zadanie_main_2(void) {
    int n = 5;
    int tab[] = {1, 2, 3, 4, 5};
    double srednia;
    int suma, suma_kwadratow;

    oblicz(n, tab, &srednia, &suma, &suma_kwadratow);

    printf("Srednia arytmetyczna: %.2f\n", srednia);
    printf("Suma elementow: %d\n", suma);
    printf("Suma kwadratow elementow: %d\n", suma_kwadratow);

    return 0;
}


/*
    4.2.3 (r) Napisz funkcje, ktora otrzymuje dwa argumenty: dodatnia liczbę całkowitą n oraz n -elementową tablicę tab o elementach
// typu const int i zwraca jako wartość średnią arytmetyczną elementów tablicy tab.
*/
double srednia(unsigned int n, const int *tab) {
    double suma = 0;
    for (unsigned int i = 0; i < n; i++)
        suma += tab[i];
    return suma / n;
}

/*
    4.2.4 (*) Napisz funkcje ktora otrzymuje dwa arugmenty: dodatnia liczbe calkowita n oraz n-elementowa
// tablice tab o elementach typu unsinged int i zwraca jako wartosc srednia geometryczna elementow tablicy tab
*/
/*
double srednia(int n, unsigned int tab[]){
    double iloczyn = 1.0;
    for (int i = 0; i < n; i++) {
        iloczyn *= tab[i];
    }
    return pow(iloczyn, 1.0/n);
}

int zadanie_main_3(void){
    int n = 5;
    unsigned int tab[] = {1,2,3,4,5};

    double wynik = srednia(n, tab);

    printf("Wynik wynosi: %.2f\n ", wynik);
    return 0;
}
*/

/*
    4.2.5 (*,r,!,roz) Napisz funckje, ktora otrzymuje jako argument liczbe calkowitna n (n>=3) i zwaraca jako
// wartosc najwieksza liczbe pierwsza mniejsza od n (do wyznaczenia wyniku uzyj algorytmu Eratosenesa)
*/
int pierwsza(unsigned int n) {
    if (n < 3) return -1;
    bool *sito = malloc(n * sizeof(bool));
    for (unsigned int i = 0; i < n; i++)
        sito[i] = true;
    sito[0] = sito[1] = false;
    for (unsigned int i = 2; i * i < n; i++) {
        if (sito[i]) {
            for (unsigned int j = i * i; j < n; j += i)
                sito[j] = false;
        }
    }
    int pom = -1;
    for (unsigned int i = n - 1; i >= 2; i--) {
        if (sito[i]) {
            pom = i;
            break;
        }
    }
    free(sito);
    return pom;
}
/*
    4.2.6 Napisz funkcję, która otrzymuje trzy argumenty: dodatnią liczbę
// całkowitą n oraz dwie n-elementowe tablice tab1, tab2 o elementach
// typu int i:
// a) (r) przepisuje zawartość tablicy tab1 do tablicy tab2,
// b) przepisuje zawartość tablicy tab1 do tablicy tab2 w odwrotnej kolejności
    (czyli element tab1[0] ma zostać zapisany do komórki tablicy tab2
// o indeksie n-1)
*/
// a)
    void kopiujtab(unsigned int n, int tab1[], int tab2[]){
        for (int i=0; i<n; i++){
            tab2[i] = tab1[i];
        }
    }
// b)
    void kopiujodtylu(unsigned int n, int tab1[], int tab2[]){
        for (int i=0; i<n; i++){
            tab2[n - i - 1] = tab1[i];
        }
    }
int zadanie_main_4(void){
    int n = 5;
    int tab1[] = {1, 2, 3, 4, 5};
    int tab2[5];

    // przepisanie tablicy z tab1 do tab2
    kopiujtab(n, tab1, tab2);
    printf("Kopia tablicy w oryginalnej kolejnosci: \n");
    for (int i=0; i<n; i++){
        printf("%d ", tab2[i]);
    }
    printf("\n");

    // przepisanie tablicy z tab1 do tab2 w odwrotnej kolejnosci
    kopiujodtylu(n, tab1, tab2);
    printf("Kopia tablicy w odwrotnej kolejnosci: \n");
    for (int i=0; i<n; i++){
        printf("%d ", tab2[i]);
    }
    printf("\n");
    return 0;
}
/*
    4.2.7 Napisz funkcję, która otrzymuje cztery argumenty: dodatnią
// liczbę całkowitą n oraz trzy n-elementowe tablice tab1, tab2 i tab3
// o elementach typu int, i:
// a) przypisuje elementom tablicy tab3 sumę odpowiadających im elementów
// tablic tab1 i tab2 (do komórki tablicy tab3 o indeksie i powinna
// trafić suma elementów tab1[i] i tab2[i])
// b) przypisuje elementom tablicy tab3 większy spośród odpowiadających im
// elementów tablic tab1 i tab2 (do komórki tablicy tab3 o indeksie i
// powinien trafić większy spośród elementów tab1[i] i tab2[i])
// c) przypisuje zawartość tablicy tab1 do tablicy tab2, zawartość tablicy
// tab2 do tablicy tab3 oraz zawartość tablicy tab3 do tablicy tab1
*/
// a)
    void sumujtabki(int n, int tab1[], int tab2[], int tab3[]){
        for (int i=0; i<n; i++){
            tab3[i] = tab1[i] + tab2[i];
        }
    }
    // b)
    void wiekszetabki(int n, int tab1[], int tab2[], int tab3[]){
        for (int i=0; i<n; i++){
            tab3[i] = (tab1[i] > tab2[i] ? tab1[i] : tab2[i]);
        }
    }
    // c)
    void zmianatabek(int n, int tab1[], int tab2[], int tab3[]){
        int *temp = (int *)malloc(n * sizeof(int));
        // zachowujemy zawartość tab1
        for (int i=0; i<n; i++){
            temp[i] = tab1[i];
        }
        // nowa zawartosc tab1 pochodzi z tab3
        for (int i=0; i<n; i++){
            tab1[i] = tab3[i];
        }
        // nowa zawartosc tab3 pochodzi z tab2
        for (int i=0; i<n; i++){
            tab3[i] = tab2[i];
        }
        // nowa zawartosc tab2 pochodzi z temp (tab1)
        for (int i=0; i<n; i++){
            tab2[i] = temp[i];
        }
        free(temp);
    }
    int zadanie_main_5(void){
        int n = 5;
        int tab1[5] = {1, 2, 3, 4, 5};
        int tab2[5] = {6, 7, 8, 9, 10};
        int tab3[5] = {11, 12, 13, 14, 15};
        // a)
        sumujtabki(n, tab1, tab2, tab3);
        printf("Suma tab1+tab2: \n");
        for (int i=0; i<n; i++){
            printf("%d ", tab3[i]);
        }
        printf("\n");
        // b)
        printf("Wieksze tabki: \n");
        wiekszetabki(n, tab1, tab2, tab3);
        for (int i=0; i<n; i++){
            printf("%d ", tab3[i]);
        }
        printf("\n");
        // c)
        zmianatabek(n, tab1, tab2, tab3);
        printf("tab1 (pobrana z poprzedniej tablicy tab3): ");
        for (int i = 0; i < n; i++) {
            printf("%d ", tab1[i]);
        }
        printf("\n");
        printf("tab2 (pobrana z poprzedniej tablicy tab1): ");
        for (int i = 0; i < n; i++) {
            printf("%d ", tab2[i]);
        }
        printf("\n");
        printf("tab3 (pobrana z poprzedniej tablicy tab2): ");
        for (int i = 0; i < n; i++) {
            printf("%d ", tab3[i]);
        }
        printf("\n");

        return 0;
    }

// 4.2.8
/*
// Napisz funkcję, która otrzymuje cztery argumenty: dodatnią liczbę
// całkowitą n, n-elementowe tablice tab1 i tab2 oraz 2 · n-elementową
// tablicę tab3 o elementach typu double.
// a) Funkcja powinna przepisywać zawartość tablic tab1 i tab2 do tablicy
// tab3 w taki sposób, że na początku tablicy tab3 powinny się znaleźć
// elementy tablicy tab1, a po nich elementy tablicy tab2.
// b) Funkcja powinna przepisywać zawartość tablic tab1 i tab2 do tablicy
// tab3 w taki sposób, że w komórkach tablicy tab3 o nieparzystych indeksach
// powinny się znaleźć elementy tablicy tab1, a w komórkach tablicy tab3
// o parzystych indeksach elementy tablicy tab2.
*/
// a)
void przepisz_tablice(int n, double tab1[], double tab2[], double tab3[]) {
    for (int i = 0; i < n; i++) tab3[i] = tab1[i];
    for (int i = 0; i < n; i++) tab3[n + i] = tab2[i];
}

// b)
void przepisz_naprzemiennie(int n, double tab1[], double tab2[], double tab3[]) {
    for (int i = 0; i < n; i++) {
        tab3[2*i] = tab2[i];
        tab3[2*i+1] = tab1[i];
    }
}

// 4.2.9
/*
// Napisz funkcję, która otrzymuje cztery argumenty: dodatnią liczbę
// całkowitą n oraz trzy n-elementowe tablice tab1, tab2 i tab3 o elementach
// typu int i zamienia zawartości komórek otrzymanych w argumentach tablic
// w następujący sposób:
    — dla dowolnego i komórka tab1[i] powinna zawierać największą
// spośród pierwotnych wartości komórek tab1[i], tab2[i]
// oraz tab3[i],
    — dla dowolnego i komórka tab2[i] powinna zawierać drugą
// co do wielkości spośród pierwotnych wartości komórek tab1[i],
// tab2[i] oraz tab3[i],
    — dla dowolnego i komórka tab3[i] powinna zawierać najmniejszą
// spośród pierwotnych wartości komórek tab1[i], tab2[i]oraz tab3[i].
*/
void zamien_trzy(int n, int tab1[], int tab2[], int tab3[]) {
    for (int i = 0; i < n; i++) {
        int a = tab1[i], b = tab2[i], c = tab3[i];
// sortowanie trzech liczb
        int max = a, min = a, mid = a;
        if (b > max) max = b;
        if (c > max) max = c;
        if (b < min) min = b;
        if (c < min) min = c;
        mid = a + b + c - max - min;
        tab1[i] = max;
        tab2[i] = mid;
        tab3[i] = min;
    }
}

// 4.2.10
/*
// Napisz funkcję, która otrzymuje dwa argumenty: dodatnią liczbę całkowitą n
// oraz n-elementową tablicę tab o elementach typu int i:
// a) zwraca największą wartość przechowywaną w tablicy tab,
// b) zwraca najmniejszą wartość przechowywaną w tablicy tab,
// c) zwraca indeks elementu tablicy tab o największej wartości,
// d) zwraca indeks elementu tablicy tab o najmniejszej wartości,
// e) zwraca największą spośród wartości bezwzględnych elementów przechowywanych w tablicy tab,
// f) zwraca indeks elementu tablicy tab o największej wartości bezwzględnej.
*/
// a)
int max_wartosc(int n, int tab[]) {
    int max = tab[0];
    for (int i = 1; i < n; i++) if (tab[i] > max) max = tab[i];
    return max;
}
// b)
int min_wartosc(int n, int tab[]) {
    int min = tab[0];
    for (int i = 1; i < n; i++) if (tab[i] < min) min = tab[i];
    return min;
}
// c)
int max_index(int n, int tab[]) {
    int max = tab[0], idx = 0;
    for (int i = 1; i < n; i++) if (tab[i] > max) { max = tab[i]; idx = i; }
    return idx;
}
// d)
int min_index(int n, int tab[]) {
    int min = tab[0], idx = 0;
    for (int i = 1; i < n; i++) if (tab[i] < min) { min = tab[i]; idx = i; }
    return idx;
}
// e)
int max_abs(int n, int tab[]) {
    int max = abs(tab[0]);
    for (int i = 1; i < n; i++) if (abs(tab[i]) > max) max = abs(tab[i]);
    return max;
}
// f)
int max_abs_index(int n, int tab[]) {
    int max = abs(tab[0]), idx = 0;
    for (int i = 1; i < n; i++) if (abs(tab[i]) > max) { max = abs(tab[i]); idx = i; }
    return idx;
}

// 4.2.11
/*
// Napisz funkcję, która otrzymuje dwa argumenty: dodatnią liczbę całkowitą n
// oraz dwie n-elementowe tablice tab o elementach typu double
// przechowujące n-wymiarowe wektory i zwraca jako wartość iloczyn
// skalarny wektorów otrzymanych w argumentach.
*/
double iloczyn_skalarny(int n, double tab1[], double tab2[]) {
    double suma = 0.0;
    for (int i = 0; i < n; i++) suma += tab1[i] * tab2[i];
    return suma;
}

// 4.2.12
/*
// Napisz funkcję, która otrzymuje dwa argumenty: dodatnią liczbę całkowitą n
// oraz n-elementową tablicę tab o elementach typu int i:
// a) odwraca kolejność elementów tablicy tab.
// b) przesuwa o jeden w lewo wszystkie elementy tablicy
    (tak, żeby wartość elementu o indeksie n − 1 znalazła się w elemencie o indeksie n−2, wartość elementu o indeksie n−2 znalazła
// się w elemencie o indeksie n − 3, zaś wartość elementu o indeksie
    0 w elemencie o indeksie n − 1),
// c) przesuwa o jeden w prawo wszystkie elementy tablicy
    (tak, żeby wartość elementu o indeksie 0 znalazła się w elemencie
// o indeksie 1, wartość elementu o indeksie 1 znalazła się w elemencie
// o indeksie 2, zaś wartość elementu o indeksie n − 1 w elemencie
// o indeksie 0),
// d) sortuje rosnąco elementy tablicy tab (porządkuje elementy
// przechowywane w tablicy w taki sposób aby ciąg
// tab[0], tab[1],...,tab[n-1] był ciągiem niemalejącym),
// e) sortuje malejąco elementy tablicy tab.
*/
// a) Odwraca kolejność
void odwroc(int n, int tab[]) {
    for (int i = 0; i < n/2; i++) {
        int tmp = tab[i];
        tab[i] = tab[n-1-i];
        tab[n-1-i] = tmp;
    }
}
// b) Przesuwa o jeden w lewo
void przesun_lewo(int n, int tab[]) {
    int tmp = tab[0];
    for (int i = 0; i < n-1; i++) tab[i] = tab[i+1];
    tab[n-1] = tmp;
}
// c) Przesuwa o jeden w prawo
void przesun_prawo(int n, int tab[]) {
    int tmp = tab[n-1];
    for (int i = n-1; i > 0; i--) tab[i] = tab[i-1];
    tab[0] = tmp;
}
// d) Sortuje rosnąco
void sortuj_rosnaco(int n, int tab[]) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if (tab[j] > tab[j+1]) {
                int tmp = tab[j]; tab[j] = tab[j+1]; tab[j+1] = tmp;
            }
}
// e) Sortuje malejąco
void sortuj_malejaco(int n, int tab[]) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if (tab[j] < tab[j+1]) {
                int tmp = tab[j]; tab[j] = tab[j+1]; tab[j+1] = tmp;
            }
}

// 4.2.13
/*
// Napisz funkcję, która otrzymuje jako argument dodatnią liczbę całkowitą n,
// a następnie tworzy dynamiczną n-elementową tablicę
// o elementach typu int i zwraca jako wartość wskaźnik do jej pierwszego elementu
*/
int* nowa_tablica_int(int n) {
    return malloc(n * sizeof(int));
}

// 4.2.14
/*
// Napisz funkcję, która otrzymuje jako argument dodatnią liczbę
// całkowitą n, a następnie tworzy dynamiczną n-elementową tablicę
// o elementach typu double i zwraca jako wartość wskaźnik do jej pierwszego elementu.
*/
double* nowa_tablica_double(int n) {
    return malloc(n * sizeof(double));
}

// 4.2.15
/*
// Napisz funkcję, która dostaje jako argument wskaźnik do jednowymiarowej
// dynamicznej tablicy o elementach typu int i zwalnia pamięć zajmowaną
// przez przekazaną w argumencie tablicę.
*/
void zwolnij (int *tab){
    free(tab);
}

// 4.2.16
/*
// Napisz funkcję, która dostaje jako argument wskaźnik do jednowymiarowej
// dynamicznej tablicy o elementach typu double i zwalnia pamięć
// zajmowaną przez przekazaną w argumencie tablicę.
*/
void zwolnijTablice(double *tab){
    free(tab);
}
int zadanie_main_6(void){
    int n = 5;
    double *tab = malloc(n * sizeof(double));
    for (int i = 0; i<n; i++){
        tab[i] = i * 1.1;
    }
    printf("Tablica przed zwolnieniem pamięci: \n");
    for (int i=0; i<n; i++){
        printf("%0.2f ", tab[i]);
    }
    printf("\n");
    zwolnijTablice(tab);
    tab = NULL;
    return 0;
}


// 4.2.17
/*
// Napisz funkcję, która otrzymuje dwa argumenty: dodatnią liczbę całkowitą
// n oraz n-elementową tablicę tab o elementach typu double a następnie
// tworzy kopię tablicy tab i zwraca jako wartość wskaźnik do nowo
// utworzonej kopii.
*/
double* kopiaTablicy(int n, double tab[]) {
    double *kopia = malloc(n * sizeof(double));
    if (kopia == NULL) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        kopia[i] = tab[i];
    }
    return kopia;
}

int zadanie_main_7(void) {
    double tab[] = {3.14, 2.71, 1.41, 0.577, 1.618};
    int n = sizeof(tab) / sizeof(tab[0]);
    double *kopia = kopiaTablicy(n, tab);
    if (kopia == NULL) {
        printf("Błąd alokacji pamięci.\n");
        return 1;
    }
    printf("Oryginalna tablica:\n");
    for (int i = 0; i < n; i++) {
        printf("%.3f ", tab[i]);
    }
    printf("\n");
    printf("Kopia tablicy:\n");
    for (int i = 0; i < n; i++) {
        printf("%.3f ", kopia[i]);
    }
    printf("\n");
    free(kopia);
    return 0;
}

// 4.2.18
/*
// Napisz funkcję, która otrzymuje trzy argumenty: dodatnią liczbę całkowitą
// n oraz dwie tablice n-elementowe o elementach typu int przechowujące
// współrzędne wektorów i zwraca jako wartość wskaźnik do pierwszego elementu
// nowo utworzonej tablicy przechowującej sumę wektorów otrzymanych w argumentach.
*/
int* sumaWektorow(int n, int vec1[], int vec2[]){
    int *suma = (int *)malloc(n * sizeof(int));
    if (suma == NULL){
        return NULL;
    }
    for (int i = 0; i<n; i++){
        suma[i] = vec1[i] + vec2[i];
    }
    return suma;
}
int zadanie_main_8(void){
    int vec1[] = {1, 2, 3, 4, 5};
    int vec2[] = {5, 4, 3, 2, 1};
    int n = sizeof(vec1) / sizeof(vec1[0]);

    int *suma = sumaWektorow(n, vec1, vec2);
    printf("Wynik sumowania wektorow: \n");
    for (int i = 0; i<n; i++){
        printf("%d ", suma[i]);
    }
    printf("\n");
    free(suma);
    return 0;
}


// 4.2.19 
/*
// Napisz funkcję, która dostaje w argumentach dodatnią liczbę całkowitą
// n oraz n-elementową tablicę liczb całkowitych tab1 o elementach typu
// int i przepisuje do nowo utworzonej tablicy tab2 elementy tablicy tab1
// o wartości różnej od zera. Rozmiar tablicy tab2 powinien być równy
// liczbie niezerowych elementów tablicy tab1. Jako wartość funkcja powinna
// zwrócić wskaźnik na pierwszy element tablicy tab2.
*/
int* przepiszNiezerowe(int n, int tab1[]) {
    int liczbaniezer = 0;
    for (int i = 0; i < n; i++) {
        if (tab1[i] != 0) liczbaniezer++;
    }
    int *tab2 = (int *)malloc(liczbaniezer * sizeof(int));
    if (tab2 == NULL) return NULL;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (tab1[i] != 0) {
            tab2[j] = tab1[i];
            j++;
        }
    }
    return tab2;
}
int zadanie_main_9(void){
    int tab1[] = {0, 5, 0, -3, 8, 0, 2};
    int n = sizeof(tab1) / sizeof(tab1[0]);
    int *tab2 = przepiszNiezerowe(n, tab1);
    if (tab2 == NULL) {
        printf("Błąd alokacji pamięci.\n");
        return 1;
    }
    int liczbaNiezerowych = 0;
    for (int i = 0; i < n; i++) {
        if (tab1[i] != 0) {
            liczbaNiezerowych++;
        }
    }
    printf("Tablica niezerowych elementów:\n");
    for (int i = 0; i < liczbaNiezerowych; i++) {
        printf("%d ", tab2[i]);
    }
    printf("\n");
    free(tab2);
    return 0;
}
