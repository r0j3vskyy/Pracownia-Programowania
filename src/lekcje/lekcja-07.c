// Zadania 5.2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>

/*
    5.2.1 Napisz funkcję wyczysc, która usuwa z tablicy przechowywany w niej napis (w sensie: umieszcza w niej poprawny napis o długości 0).
// Napisz dwie wersje funkcji wyczysc dla napisów składających się ze znaków typu char i wchar_t.
*/
void wyczysc(char *str){
    str[0] = '\0';
}
int main() {
    char str[] = "Hello, world!";
    printf("Przed wyczyszczeniem: %s\n", str);
    wyczysc(str);
    printf("Po wyczyszczeniu: %s\n", str);
    return 0;
}
void wyczysct(wchar_t *str){
    str[0] = L'\0';
}
int zadanie_main_2(void) {
    wchar_t str[] = L"Hello, world!";
    wprintf(L"Przed wyczyszczeniem: %ls\n", str);
    wyczysct(str);
    wprintf(L"Po wyczyszczeniu: %ls\n", str);
    return 0;
}

/*
    5.2.2 (r) Napisz funkcję dlugosc, która jako argument otrzymuje napis i zwraca jako wartość jego długość.
// Napisz dwie wersje funkcji dlugosc dla napisów składających się ze znaków typu char i wchar_t.
*/
int dlugosc(const char *str){
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}
int zadanie_main_3(void) {
    char str[] = "Hello, world!";
    printf("Długość napisu: %d\n", dlugosc(str));
    return 0;
}
int dlugosct(const wchar_t *str){
    int i = 0;
    while (str[i] != L'\0'){
        i++;
    }
    return i;
}
int zadanie_main_4(void) {
    wchar_t str[] = L"Hello, world!";
    wprintf(L"Długość napisu: %d\n", dlugosct(str));
    return 0;
}
/*
    5.2.3 Napisz funkcję porownaj, która jako argumenty otrzymuje dwa napisy i zwraca 1 gdy napisy są równe i 0 w przeciwnym przypadku.
// Napisz dwie wersje funkcji porownaj dla napisów składających się ze znaków typu char i wchar_t.
*/
int porownaj(const char *str1, const char *str2){
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0'){
        if (str1[i] != str2[i]){
            return 0;
        }
        i++;
    }
    return (str1[i] == str2[i]) ? 1:0;
}
int zadanie_main_5(void) {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";

    printf("Porównanie str1 i str2: %d\n", porownaj(str1, str2));
    printf("Porównanie str1 i str3: %d\n", porownaj(str1, str3));
    return 0;
}
int porownajt(const wchar_t *str1, const wchar_t *str2){
    int i = 0;
    while (str1[i] != L'\0' && str2[i] != L'\0'){
        if (str1[i] != str2[i]){
            return 0;
        }
        i++;
    }
    return (str1[i] == str2[i]) ? 1:0;
}
int zadanie_main_6(void) {
    wchar_t str1[] = L"Hello";
    wchar_t str2[] = L"Hello";
    wchar_t str3[] = L"World";

    wprintf(L"Porównanie str1 i str2: %d\n", porownajt(str1, str2));
    wprintf(L"Porównanie str1 i str3: %d\n", porownajt(str1, str3));
    return 0;
}
/*
    5.2.4 Napisz funkcję, która jako argumenty otrzymuje dwa napisy i zwraca wartość 1, gdy pierwszy napis
// jest wcześniejszy w kolejności leksykograﬁcznej i 0 w przeciwnym przypadku.
// Zakładamy, że oba napisy składają się ze znaków typu char, zawierają wyłącznie małe litery alfabetu łacińskiego,
// a system, na którym jest kompilowany i uruchamiany program, używa standardowego kodowa- nia ASCII.
*/
void przepisz1(char *dest, const char *src){
    int i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
int zadanie_main_7(void) {
    char src[] = "Hello, world!";
    char dest[50];

    przepisz1(dest, src);
    printf("Źródłowy napis: %s\n", src);
    printf("Skopiowany napis: %s\n", dest);

    return 0;
}
void przepiszt1(wchar_t *dest, const wchar_t *src){
    int i = 0;
    while (src[i] != L'\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = L'\0';
}
int zadanie_main_8(void) {
    wchar_t src[] = L"Hello, world!";
    wchar_t dest[50];

    przepiszt1(dest, src);
    wprintf(L"Źródłowy napis: %ls\n", src);
    wprintf(L"Skopiowany napis: %ls\n", dest);

    return 0;
}
/*
    5.2.5 Napisz funkcję przepisz, która otrzymuje dwie tablice znaków i przepisuje napis znajdujący się w pierwszej tablicy do drugiej tablicy.
// Zakładamy, że w drugiej tablicy jest wystarczająco dużo miejsca. Napisz dwie wersje funkcji przepisz dla napisów składających się ze znaków typu char i wchar_t.
*/
void przepisz(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {  
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; 
}
int zadanie_main_9(void) {
    char src[] = "Hello, world!";
    char dest[50];

    przepisz(dest, src);
    printf("Źródłowy napis: %s\n", src);
    printf("Skopiowany napis: %s\n", dest);

    return 0;
}

void przepiszt(wchar_t *dest, const wchar_t *src) {
    int i = 0;
    while (src[i] != L'\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = L'\0';
}
int zadanie_main_10(void) {
    wchar_t src[] = L"Hello, world!";
    wchar_t dest[50];

    przepiszt(dest, src);
    wprintf(L"Źródłowy napis: %ls\n", src);
    wprintf(L"Skopiowany napis: %ls\n", dest);

    return 0;
}

/*
    5.2.6 Napisz funkcję kopiujn, która dostaje w argumentach dwie tablice znaków nap1, nap2 oraz liczbę n i przekopiowuje
// n pierwszych znaków z napisu przechowywanego w tablicy nap1 do tablicy nap2.
// W przypadku gdy napis w tablicy nap1 jest krótszy niż n znaków, funkcja powinna po prostu przepisać cały napis. Funkcja powinna zadbać o to,
    żeby na końcu napisu w tablicy nap2 znalazł się znak o kodzie 0. Zakładamy, że w docelowej tablicy jest wystarczająco dużo miejsca. 
// Napisz dwie wersje funkcji: dla napisów składających się ze znaków typu char i wchar_t.
*/
void kopiujn(char *nap1, char *nap2, int n) {
    int i = 0;
    while (i < n && nap1[i] != '\0') {
        nap2[i] = nap1[i];
        i++;
    }
    nap2[i] = '\0';
}
int zadanie_main_11(void) {
    char nap1[] = "Hello, world!";
    char nap2[20];

    kopiujn(nap1, nap2, 10);
    printf("Skopiowany napis: %s\n", nap2);

    kopiujn(nap1, nap2, 20);
    printf("Skopiowany napis: %s\n", nap2);

    return 0;
}
void kopiujnt(wchar_t *nap1, wchar_t *nap2, int n) {
    int i = 0;
    while (i < n && nap1[i] != L'\0') {
        nap2[i] = nap1[i];
        i++;
    }
    nap2[i] = L'\0';
}
int zadanie_main_12(void) {
    wchar_t nap1[] = L"Hello, world!";
    wchar_t nap2[20];

    kopiujnt(nap1, nap2, 10);
    wprintf(L"Skopiowany napis: %ls\n", nap2);

    kopiujnt(nap1, nap2, 20);
    wprintf(L"Skopiowany napis: %ls\n", nap2);

    return 0;
}
/*
    5.2.7 Napisz funkcję sklej otrzymującą jako argumenty trzy tablice znaków i zapisującą do trzeciej tablicy konkatenację napisów znajdujących się w dwóch pierwszych tablicach 
    (czyli dla napisów ”Ala m” i ”a kota” znajdujących się w pierwszych dwóch argumentach do trzeciej tablicy powinien zostać zapisany napis ”Ala ma kota”). 
// Zakładamy, że w trzeciej tablicy jest wystarczająco dużo miejsca.
// Napisz dwie wersje funkcji sklej dla napisów składających się ze znaków typu char i wchar_t.
*/
void sklej(char *nap1, char *nap2, char *nap3) {
    int i = 0;
    while (nap1[i] != '\0') {
        nap3[i] = nap1[i];
        i++;
    }
    int j = 0;
    while (nap2[j] != '\0') {
        nap3[i + j] = nap2[j];
        j++;
    }
    nap3[i + j] = '\0';
}
int zadanie_main_13(void) {
    char nap1[] = "Ala m";
    char nap2[] = "a kota";
    char nap3[50];

    sklej(nap1, nap2, nap3);
    printf("Połączenie napisów: %s\n", nap3);

    return 0;
}
void sklejt(wchar_t *nap1, wchar_t *nap2, wchar_t *nap3) {
    int i = 0;
    while (nap1[i] != L'\0') {
        nap3[i] = nap1[i];
        i++;
    }
    int j = 0;
    while (nap2[j] != L'\0') {
        nap3[i + j] = nap2[j];
        j++;
    }
    nap3[i + j] = L'\0';
}
int zadanie_main_14(void) {
    wchar_t nap1[] = L"Ala m";
    wchar_t nap2[] = L"a kota";
    wchar_t nap3[50];

    sklejt(nap1, nap2, nap3);
    wprintf(L"Połączenie napisów: %ls\n", nap3);

    return 0;
}

/*
    5.2.8 Napisz funkcję, która otrzymuje w argumencie napis i podmienia w nim wszystkie małe litery na duże litery. 
// Zakładamy, że napis przechowywany jest w tablicy o elementach typu char, składa się wyłącznie z liter łacińskich
// i białych znaków, oraz że system, na którym jest kompilowany i uruchamiany program,
// używa standardowego kodowania ASCII.
*/
void zamiennaduze(char *napis){
    int i=0;
    while (napis[i] != '\0'){
        if (napis[i] >= 'a' && napis[i] <= 'z'){
            napis[i] = napis[i] - ('a' - 'A');
        }
        i++;
    }
}
int zadanie_main_15(void){
    char tekst[] = "Ala ma kota i biale zeby.";
    zamiennaduze(tekst);
    printf("Po zamianie: %s\n", tekst);
    return 0;
}

/*
    5.2.9 Napisz funkcję wytnij, która dostaje jako argumenty napis oraz dwie liczby całkowite n i m,
    i wycina z otrzymanego napisu znaki o indeksach od n do m ( n <= m). 
// Otrzymany w argumencie napis może mieć dowolną liczbę znaków (w tym mniejszą od n lub m)
// Napisz dwie wersje funkcji wytnij dla napisów składających się ze znaków typu char i wchar_t.
*/
void wytnij(char *napis, int n, int m){
    int i=0, j=0;
    while (napis[i] != '\0'){
        if (i<n || i>m){
            napis[j] = napis[i];
            j++;
        }
        i++;
    }
    napis[j] = '\0';
}
int zadanie_main_16(void){
    char tekst[] = "Programowanie w C";
    wytnij(tekst, 2, 5);
    printf("Po wycieciu: %s\n", tekst);
    return 0;
}

void wytnijt(wchar_t *napis, int n, int m) {
    int i = 0, j = 0;
    while (napis[i] != L'\0') {
        if (i < n || i > m) {
            napis[j] = napis[i];
            j++;
        }
        i++;
    }
    napis[j] = L'\0';
}
int zadanie_main_17(void) {
    wchar_t tekst[] = L"Programowanie w C";
    wytnijt(tekst, 2, 5);
    wprintf(L"Po wycieciu: %ls\n", tekst);
    return 0;
}

/*
    5.2.10 Napisz funkcję wytnij2, która dostaje jako argument dwa napisy nap1 i nap2,
// i wycina z napisu nap1 pierwsze wystąpienie w nim napisu nap2.
// Napisz dwie wersje funkcji wytnij2 dla napisów składających się ze znaków typu char i wchar_t.
*/
void wytnij3(char *nap1, const char *nap2){
    int i=0, j=0, k, znaleziono=0;
    while (nap1[i] != '\0' && !znaleziono){
        j = 0;
        while (nap2[j] != '\0' && nap1[i+j] == nap2[j]){
            j++;
        }
        if (nap2[j] == '\0'){
            znaleziono = 1;
            for (k=i; nap1[k+j] != '\0'; k++){
                nap1[k] = nap1[k+j];
            }
            nap1[k] = '\0';
        } else {i++;}
    }
}
int zadanie_main_18(void){
    char tekst[] = "Ala ma kota i pieska";
    wytnij3(tekst, "kota");
    printf("Po wycieciu: %s\n", tekst);
    return 0;
}


void wytnij3t(wchar_t *nap1, const wchar_t *nap2) {
    int i = 0, j = 0, k, znaleziono = 0;
    while (nap1[i] != L'\0' && !znaleziono) {
        j = 0;
        while (nap2[j] != L'\0' && nap1[i + j] == nap2[j]) {
            j++;
        }
        if (nap2[j] == L'\0') {
            znaleziono = 1;
            for (k = i; nap1[k + j] != L'\0'; k++) {
                nap1[k] = nap1[k + j];
            }
            nap1[k] = L'\0';
        } else {
            i++;
        }
    }
}
int zadanie_main_19(void) {
    wchar_t tekst[] = L"Ala ma kota i pieska";
    wytnij3t(tekst, L"kota");
    wprintf(L"Po wycieciu: %ls\n", tekst);
    return 0;
}


/*
    5.2.11 Napisz funkcję wytnijzw, która dostaje jako argument dwa napisy nap1 i nap2,
// i wycina z napisu nap1 wszystkie znaki występujące także w napisie nap2.
// Napisz dwie wersje funkcji wytnijz dla napisów składających się ze znaków typu char i wchar_t.
*/
int zawiera(char znak, const char *nap2) {
    int i = 0;
    while (nap2[i] != '\0') {
        if (nap2[i] == znak) return 1;
        i++;
    }
    return 0;
}
void wytnijzw(char *nap1, const char *nap2) {
    int i = 0, j = 0;
    while (nap1[i] != '\0') {
        if (!zawiera(nap1[i], nap2)) {
            nap1[j++] = nap1[i];
        }
        i++;
    }
    nap1[j] = '\0';
}
int zadanie_main_20(void) {
    char tekst[] = "Ala ma kota";
    wytnijzw(tekst, "aok");
    printf("Po wycieciu znakow: %s\n", tekst);
    return 0;
}


/*
    5.2.12 Napisz funkcję wytnijzn, która dostaje jako argument dwa napisy nap1 i nap2,
// i wycina z napisu nap1 wszystkie znaki niewystępujące w napisie nap2.
// Napisz dwie wersje funkcji wytnijzn dla napisów składających się ze znaków typu char i wchar_t.
*/
int zawiera2(char znak, const char *nap2) {
    int i = 0;
    while (nap2[i] != '\0') {
        if (nap2[i] == znak) return 1;
        i++;
    }
    return 0;
}
void wytnijzn(char *nap1, const char *nap2) {
    int i = 0, j = 0;
    while (nap1[i] != '\0') {
        if (zawiera2(nap1[i], nap2)) {
            nap1[j++] = nap1[i];
        }
        i++;
    }
    nap1[j] = '\0';
}
int zadanie_main_21(void) {
    char tekst[] = "informatyka";
    wytnijzn(tekst, "ioak");
    printf("Po wycieciu: %s\n", tekst);
    return 0;
}


/*
    5.2.13 Napisz funkcję wytnijtm, która dostaje jako argument dwa napisy nap1 i nap2 o równej długości
// i wycina z napisu nap1 znaki równe znakom występującym na tym samym miejscu w napisie nap2
    (znak o indeksie i usuwamy wtedy i tylko wtedy, gdy nap1[i]=nap2[i]).
// Napisz dwie wersje funkcji wytnijtm dla napisów składających się ze znaków typu char i wchar_t.
*/
void wytnijtm(char *nap1, const char *nap2) {
    int i = 0, j = 0;
    while (nap1[i] != '\0' && nap2[i] != '\0') {
        if (nap1[i] != nap2[i]) {
            nap1[j++] = nap1[i];
        }
        i++;
    }
    nap1[j] = '\0';
}
int zadanie_main_22(void) {
    char nap1[] = "informatyka";
    char nap2[] = "inwxxxxxyza";
    wytnijtm(nap1, nap2);
    printf("Po wycieciu: %s\n", nap1);
    return 0;
}

//      Dalsze zadania rozwiąż z użyciem funkcji bibliotecznych: 


/*
    5.2.14 Napisz funkcję, która wypisuje na standardowym wyjściu otrzymany w argumencie napis.
// Napisz dwie wersje funkcji: dla napisów składających się ze znaków typu char i wchar_t.
*/
void wypisz(const char *napis) {
    printf("%s\n", napis);
}
void wypiszt(const wchar_t *napis) {
    wprintf(L"%ls\n", napis);
}

/*
    5.2.16 Napisz funkcję, która dostaje jako argument tablicę znaków i wczytuje do niej napis
// ze standardowego wejścia. Napisz dwie wersje funkcji: dla tablicy składających się ze znaków typu char i wchar_t.
*/
void wczytaj(char *napis, int maxlen) {
    fgets(napis, maxlen, stdin);
    size_t len = strlen(napis);
    if (len > 0 && napis[len-1] == '\n') napis[len-1] = '\0';
}
void wczytajt(wchar_t *napis, int maxlen) {
    fgetws(napis, maxlen, stdin);
    size_t len = wcslen(napis);
    if (len > 0 && napis[len-1] == L'\n') napis[len-1] = L'\0';
}

/*
    5.2.18 Napisz funkcję, która otrzymuje w argumencie tablicę napisów (tablicę tablic a więc typ char** lub wchar_t**)
// oraz jej rozmiar i zwraca jako wartość pierwszy leksykograﬁcznie spośród przechowywanych w tablicy napisów
    (funkcja powinna zwrócić kopię znajdującego się w tablicy napisu). Zakładamy, że napisy zawierają wyłącznie małe litery łacińskie.
// Napisz dwie wersje funkcji: dla napisów składających się ze znaków typu char i wchar_t.
*/
char* pierwszy_lekso(char **tab, int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (strcmp(tab[i], tab[idx]) < 0) idx = i;
    }
    char *wynik = malloc(strlen(tab[idx]) + 1);
    strcpy(wynik, tab[idx]);
    return wynik;
}
wchar_t* pierwszy_leksot(wchar_t **tab, int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (wcscmp(tab[i], tab[idx]) < 0) idx = i;
    }
    wchar_t *wynik = malloc((wcslen(tab[idx]) + 1) * sizeof(wchar_t));
    wcscpy(wynik, tab[idx]);
    return wynik;
}

/*
    5.2.20 Napisz funkcję godzina, która dostaje w argumentach trzy liczby całkowite godz, min i sek,
// zawierające odpowiednio godziny, minuty oraz sekundy, i zwraca
// jako wartość napis zawierający godzinę w formacie godz:min:sek, w którym wartości poszczególnych pól pochodzą ze zmiennych podanych w argumentach.
// Napisz dwie wersje funkcji godzina: zwracające napisy będące tablicami znaków typu char i typu wchar_t.
*/
char* godzina(int godz, int min, int sek) {
    char *wynik = malloc(9);
    sprintf(wynik, "%02d:%02d:%02d", godz, min, sek);
    return wynik;
}
wchar_t* godzinat(int godz, int min, int sek) {
    wchar_t *wynik = malloc(9 * sizeof(wchar_t));
    swprintf(wynik, 9, L"%02d:%02d:%02d", godz, min, sek);
    return wynik;
}

/*
    5.2.22 Napisz funkcję sklej, która dostaje w argumentach trzy napisy i zwraca jako wartość napis powstały ze sklejenia napisów otrzyma- nych w argumentach. 
// Napisz dwie wersje funkcji sklej operujące na napisach składających się ze znaków typu char i typu wchar_t.
*/
char* sklej3(const char *a, const char *b, const char *c) {
    size_t len = strlen(a) + strlen(b) + strlen(c) + 1;
    char *wynik = malloc(len);
    strcpy(wynik, a);
    strcat(wynik, b);
    strcat(wynik, c);
    return wynik;
}
wchar_t* sklej3t(const wchar_t *a, const wchar_t *b, const wchar_t *c) {
    size_t len = wcslen(a) + wcslen(b) + wcslen(c) + 1;
    wchar_t *wynik = malloc(len * sizeof(wchar_t));
    wcscpy(wynik, a);
    wcscat(wynik, b);
    wcscat(wynik, c);
    return wynik;
}

/*
    5.2.24 Napisz funkcję kopiuj, która dostaje jako argumenty napis oraz tablicę znaków i przepisuje napis do otrzymanej w argumencie tablicy znaków. 
// Napisz dwie wersje funkcji kopiuj operujące na napisach składających się ze znaków typu char i typu wchar_t.
*/
void kopiuj(const char *src, char *dest) {
    strcpy(dest, src);
}
void kopiujt(const wchar_t *src, wchar_t *dest) {
    wcscpy(dest, src);
}

/*
    5.2.25 Napisz funkcję kopiuj, która dostaje jako argumenty napis oraz wskaźnik do napisu (czyli wskaźnik do wskaźnika),
// tworzy nową tablicę znaków, kopiuje do niej napis zawarty w pierwszym argumencie,
// i przypisuje wskaźnik do nowo utworzonej tablicy do zmiennej wskazywanej przez drugi argument.
// Napisz dwie wersje funkcji kopiuj operujące na napisach składających się ze znaków typu char i typu wchar_t.
*/
void kopiuj_ptr(const char *src, char **dest) {
    *dest = malloc(strlen(src) + 1);
    strcpy(*dest, src);
}
void kopiuj_ptrt(const wchar_t *src, wchar_t **dest) {
    *dest = malloc((wcslen(src) + 1) * sizeof(wchar_t));
    wcscpy(*dest, src);
}

/*
    5.2.26 Napisz funkcję, która dostaje w argumencie napis i zamienia wszystkie występujące w nim małe litery na odpowiadające im duże litery. 
// Napisz dwie wersje funkcji operujące na napisach składających się ze znaków typu char i typu wchar_t.
*/
void na_duze(char *napis) {
    for (int i = 0; napis[i] != '\0'; i++)
        if (napis[i] >= 'a' && napis[i] <= 'z')
            napis[i] = napis[i] - ('a' - 'A');
}
void na_duzet(wchar_t *napis) {
    for (int i = 0; napis[i] != L'\0'; i++)
        napis[i] = towupper(napis[i]);
}
