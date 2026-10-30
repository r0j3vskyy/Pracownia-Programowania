#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>
#include <ctype.h>

// Zadania 8.2 - Operacje na plikach

/*
    8.2.1 Napisz funkcję, która dostaje jako argument ścieżkę dostępu
// do pliku, otwiera plik do tekstowego czytania i zwraca jako wartość
// deskryptor świeżo otwartego pliku (w wersji dla języka C++ funkcja
// powinna zwrócić wskaźnik do obiektu klasy fstream).
*/
FILE* otworz_do_czytania(const char *sciezka){
    return fopen(sciezka, "r");
}

/*
    8.2.2 Napisz funkcję, która dostaje jako argument deskryptor do pliku
// tekstowego otwartego do czytania (w wersji dla języka C++ referencję
// do obiektu klasy fstream), wypisuje zawartość pliku na standardowe
// wyjście i zamyka plik.
*/
void wypisz_i_zamknij(FILE *plik) {
    int c;
    while ((c = fgetc(plik)) != EOF) {
        putchar(c);
    }
    fclose(plik);
}

/*
    8.2.3 Napisz funkcję, która dostaje jako argument ścieżkę dostępu
// do pliku tekstowego i wypisuje na standardowym wyjściu zawartość
// pliku z pominięciem białych znaków.
// Napisz dwie wersje funkcji dla znaków typów char i wchar_t.
*/
// wersja dla char
void wypisz_bez_bialych(const char *sciezka) {
    FILE *plik = fopen(sciezka, "r");
    if (!plik) return;
    int c;
    while ((c = fgetc(plik)) != EOF) {
        if (!isspace(c)) putchar(c);
    }
    fclose(plik);
}
// wersja dla wchar_t
void wypisz_bez_bialych_w(const wchar_t *sciezka) {
    FILE *plik = _wfopen(sciezka, L"r");
    if (!plik) return;
    wint_t c;
    while ((c = fgetwc(plik)) != WEOF) {
        if (!iswspace(c)) putwchar(c);
    }
    fclose(plik);
}

/*
    8.2.4 Napisz funkcję, która dostaje jako argumenty ścieżkę dostępu
// do pliku tekstowego oraz znak c i zwraca jako wartość liczbę wystąpień
// znaku c w podanym w argumencie pliku.
// Napisz dwie wersje funkcji dla znaków typów char i wchar_t.
*/
// wersja dla char
int licz_znak(const char *sciezka, char znak) {
    FILE *plik = fopen(sciezka, "r");
    if (!plik) return 0;
    int c, licznik = 0;
    while ((c = fgetc(plik)) != EOF) {
        if (c == znak) licznik++;
    }
    fclose(plik);
    return licznik;
}
// wersja dla wchar_t
int licz_znak_w(const wchar_t *sciezka, wchar_t znak) {
    FILE *plik = _wfopen(sciezka, L"r");
    if (!plik) return 0;
    wint_t c;
    int licznik = 0;
    while ((c = fgetwc(plik)) != WEOF) {
        if (c == znak) licznik++;
    }
    fclose(plik);
    return licznik;
}

/*
    8.2.5 Napisz funkcję, która dostaje w argumencie ścieżkę dostępu do pliku
// tekstowego i wypisuje na standardowym wyjściu statystyki występowania w pliku poszczególnych znaków (zakładamy, że znaki są typu
// char).
*/
void statystyki_znakow(const char *sciezka) {
    FILE *plik = fopen(sciezka, "r");
    if (!plik) return;
    int tab[256] = {0};
    int c;
    while ((c = fgetc(plik)) != EOF) {
        tab[(unsigned char)c]++;
    }
    fclose(plik);
    for (int i = 0; i < 256; i++) {
        if (tab[i] > 0) printf("'%c' (%d): %d\n", isprint(i) ? i : '?', i, tab[i]);
    }
}

/*
    8.2.6 Napisz funkcję, która dostaje jako argument ścieżkę dostępu do pliku
// tekstowego i zwraca jako wartość najczęściej występujący w pliku znak
    (zakładamy, że znaki są typu char).
*/
char najczestszy_znak(const char *sciezka) {
    FILE *plik = fopen(sciezka, "r");
    if (!plik) return 0;
    int tab[256] = {0};
    int c;
    while ((c = fgetc(plik)) != EOF) {
        tab[(unsigned char)c]++;
    }
    fclose(plik);
    int max = 0, idx = 0;
    for (int i = 0; i < 256; i++) {
        if (tab[i] > max) {
            max = tab[i];
            idx = i;
        }
    }
    return (char)idx;
}

/*
    8.2.7 Napisz funkcję, która dostaje jako argument ścieżkę dostępu do pliku
// tekstowego zawierającego liczby całkowite oddzielone białymi znakami
// i zwraca jako wartość sumę znajdujących się w pliku liczb.
*/
int suma_liczb(const char *sciezka) {
    FILE *plik = fopen(sciezka, "r");
    if (!plik) return 0;
    int suma = 0, liczba;
    while (fscanf(plik, "%d", &liczba) == 1) {
        suma += liczba;
    }
    fclose(plik);
    return suma;
}

/*
    8.2.8 Napisz funkcję, która dostaje jako argument ścieżkę dostępu do pliku
// tekstowego zawierającego liczby całkowite oddzielone białymi znakami
// i zwraca jako wartość najmniejszą spośród znajdujących się w pliku
// liczb.
*/
int minimum_liczb(const char *sciezka) {
    FILE *plik = fopen(sciezka, "r");
    if (!plik) return 0;
    int liczba, min, pierwsza = 1;
    while (fscanf(plik, "%d", &liczba) == 1) {
        if (pierwsza) {
            min = liczba;
            pierwsza = 0;
        } else if (liczba < min) {
            min = liczba;
        }
    }
    fclose(plik);
    return pierwsza ? 0 : min;
}

/*
    8.2.9 Napisz funkcję, która dostaje jako argumenty ścieżki dostępu
// do dwóch plików tekstowych i zwraca jako wartość 1, jeżeli podane
// pliki mają taką samą zawartość oraz 0 w przeciwnym wypadku.
// Napisz dwie wersje funkcji dla znaków typu char i wchar_t.
*/
// wersja dla char
int porownaj_pliki(const char *sciezka1, const char *sciezka2) {
    FILE *f1 = fopen(sciezka1, "r");
    FILE *f2 = fopen(sciezka2, "r");
    if (!f1 || !f2) { if(f1) fclose(f1); if(f2) fclose(f2); return 0; }
    int c1, c2;
    do {
        c1 = fgetc(f1);
        c2 = fgetc(f2);
        if (c1 != c2) { fclose(f1); fclose(f2); return 0; }
    } while (c1 != EOF && c2 != EOF);
    fclose(f1); fclose(f2);
    return 1;
}
// wersja dla wchar_t
int porownaj_pliki_w(const wchar_t *sciezka1, const wchar_t *sciezka2) {
    FILE *f1 = _wfopen(sciezka1, L"r");
    FILE *f2 = _wfopen(sciezka2, L"r");
    if (!f1 || !f2) { if(f1) fclose(f1); if(f2) fclose(f2); return 0; }
    wint_t c1, c2;
    do {
        c1 = fgetwc(f1);
        c2 = fgetwc(f2);
        if (c1 != c2) { fclose(f1); fclose(f2); return 0; }
    } while (c1 != WEOF && c2 != WEOF);
    fclose(f1); fclose(f2);
    return 1;
}

/*
    8.2.10 Napisz funkcję, która dostaje jako argumenty ścieżki dostępu
// do dwóch plików tekstowych i zwraca jako wartość 1, jeżeli podane
// pliki mają taką samą zawartość z dokładnością do białych znaków
// oraz 0 w przeciwnym wypadku.
// Napisz dwie wersje funkcji dla znaków typu char i wchar_t.
*/
// wersja dla char
int porownaj_pliki_bez_bialych(const char *sciezka1, const char *sciezka2) {
    FILE *f1 = fopen(sciezka1, "r");
    FILE *f2 = fopen(sciezka2, "r");
    if (!f1 || !f2) { if(f1) fclose(f1); if(f2) fclose(f2); return 0; }
    int c1, c2;
    do {
        do { c1 = fgetc(f1); } while (c1 != EOF && isspace(c1));
        do { c2 = fgetc(f2); } while (c2 != EOF && isspace(c2));
        if (c1 != c2) { fclose(f1); fclose(f2); return 0; }
    } while (c1 != EOF && c2 != EOF);
    fclose(f1); fclose(f2);
    return (c1 == c2);
}
// wersja dla wchar_t
int porownaj_pliki_bez_bialych_w(const wchar_t *sciezka1, const wchar_t *sciezka2) {
    FILE *f1 = _wfopen(sciezka1, L"r");
    FILE *f2 = _wfopen(sciezka2, L"r");
    if (!f1 || !f2) { if(f1) fclose(f1); if(f2) fclose(f2); return 0; }
    wint_t c1, c2;
    do {
        do { c1 = fgetwc(f1); } while (c1 != WEOF && iswspace(c1));
        do { c2 = fgetwc(f2); } while (c2 != WEOF && iswspace(c2));
        if (c1 != c2) { fclose(f1); fclose(f2); return 0; }
    } while (c1 != WEOF && c2 != WEOF);
    fclose(f1); fclose(f2);
    return (c1 == c2);
}

/*
    8.2.11 Napisz funkcję, która dostaje jako argument ścieżkę dostępu do pliku,
// otwiera plik do tekstowego pisania z kursorem ustawionym na końcu pliku i zwraca jako wartość deskryptor świeżo otwartego pliku
    (w wersji dla języka C++ funkcja powinna zwrócić wskaźnik do obiektu klasy fstream).
*/
FILE* otworz_do_dopisywania(const char *sciezka) {
    return fopen(sciezka, "a");
}

/*
    8.2.12 Napisz funkcję, która dostaje jako argument deskryptor do pliku
// tekstowego otwartego do pisania (w wersji dla języka C++ referencję
// do obiektu klasy fstream) oraz liczbę n, wczytuje ze standardowego
// wejścia n wersów tekstu, zapisuje do pliku wczytany tekst i zamyka
// plik.
// Napisz dwie wersje funkcji dla znaków typów char i wchar_t.
*/
// wersja dla char
void zapisz_n_wierszy(FILE *plik, int n) {
    char buf[1024];
    for (int i = 0; i < n; i++) {
        if (fgets(buf, sizeof(buf), stdin)) {
            fputs(buf, plik);
        }
    }
    fclose(plik);
}
// wersja dla wchar_t
void zapisz_n_wierszy_w(FILE *plik, int n) {
    wchar_t buf[1024];
    for (int i = 0; i < n; i++) {
        if (fgetws(buf, sizeof(buf)/sizeof(wchar_t), stdin)) {
            fputws(buf, plik);
        }
    }
    fclose(plik);
}

/*
    8.2.13 Napisz funkcję, która dostaje jako argumenty deskryptory dwóch
// plików tekstowych i przepisuje zawartość pierwszego pliku do drugiego
// pliku.
*/
void przepisz(FILE *zrodlo, FILE *cel) {
    int c;
    while ((c = fgetc(zrodlo)) != EOF) {
        fputc(c, cel);
    }
}

/*
    8.2.14 Napisz funkcję, która dostaje jako argumenty ścieżki dostępu
// do dwóch plików (w wersji dla języka C++ referencje do obiektów
// klasy fstream) i przepisuje zawartość pierwszego pliku do drugiego
// pliku (stara zawartość drugiego pliku ma zostać skasowana).
*/
void przepisz_plik(const char *zrodlo, const char *cel) {
    FILE *f1 = fopen(zrodlo, "r");
    FILE *f2 = fopen(cel, "w");
    if (!f1 || !f2) { if(f1) fclose(f1); if(f2) fclose(f2); return; }
    int c;
    while ((c = fgetc(f1)) != EOF) {
        fputc(c, f2);
    }
    fclose(f1);
    fclose(f2);
}

/*
    8.2.15 Napisz funkcję, która dostaje jako argumenty ścieżki dostępu do dwóch
// plików i dopisuje zawartość pierwszego pliku na koniec drugiego pliku.
*/
void dopisz_plik(const char *zrodlo, const char *cel) {
    FILE *f1 = fopen(zrodlo, "r");
    FILE *f2 = fopen(cel, "a");
    if (!f1 || !f2) { if(f1) fclose(f1); if(f2) fclose(f2); return; }
    int c;
    while ((c = fgetc(f1)) != EOF) {
        fputc(c, f2);
    }
    fclose(f1);
    fclose(f2);
}

/*
    8.2.16 Napisz funkcję, która dostaje w argumentach jednowymiarową tablicę
// liczb całkowitych tab, jej rozmiar oraz ścieżkę dostępu do pliku tekstowego,
// i dopisuje w kolejnych wierszach na końcu otrzymanego pliku
// wartości kolejnych elementów tablicy tab.
*/
void dopisz_tablice(const int *tab, int n, const char *sciezka) {
    FILE *plik = fopen(sciezka, "a");
    if (!plik) return;
    for (int i = 0; i < n; i++) {
        fprintf(plik, "%d\n", tab[i]);
    }
    fclose(plik);
}

int main(void) {
    return 0;
}
