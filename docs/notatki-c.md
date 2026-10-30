# Ściąga z języka C

Krótkie, praktyczne przykłady z tematów omawianych na zajęciach. Wszystkie fragmenty zakładają kompilację:

```bash
gcc -std=c17 -Wall -Wextra -pedantic program.c -o program
```

Najważniejsze zasady: pilnuj zakresów tablic, sprawdzaj wynik `malloc`, zwalniaj pamięć przez `free` i sprawdzaj wynik `fopen`.


## 1. Instrukcje sterujące i funkcje

```c
#include <stdio.h>

int silnia(int n) {
    int wynik = 1;
    for (int i = 2; i <= n; i++) {
        wynik *= i;
    }
    return wynik;
}

int main(void) {
    int n = 5;

    if (n > 0) {
        printf("silnia(%d) = %d\n", n, silnia(n));
    }

    int suma = 0;
    int i = 1;
    while (i <= n) {
        suma += i;
        i++;
    }
    printf("suma = %d\n", suma);
    return 0;
}
```

### Rekurencja

Każda funkcja rekurencyjna musi mieć przypadek bazowy.

```c
unsigned long long silnia_rekurencyjna(unsigned int n) {
    if (n <= 1) {
        return 1;
    }
    return n * silnia_rekurencyjna(n - 1);
}
```


## 2. Wskaźniki i pamięć dynamiczna

`&` pobiera adres, a `*` odczytuje lub modyfikuje wartość pod adresem.

```c
#include <stdio.h>
#include <stdlib.h>

void zamien(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int a = 3;
    int b = 8;
    zamien(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    size_t n = 5;
    int *tab = malloc(n * sizeof(*tab));
    if (tab == NULL) {
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < n; i++) {
        tab[i] = (int)i * 2;
        printf("%d ", tab[i]);
    }
    putchar('\n');
    free(tab);
    return EXIT_SUCCESS;
}
```

Dla `const`:

```c
const int *p;       // nie zmienisz wartości przez p
int *const p2 = &a; // nie zmienisz adresu p2
```


## 3. Tablice i napisy

Tablica ma indeksy od `0` do `n - 1`. Napis w C kończy się znakiem `\0`.

```c
#include <stdio.h>
#include <string.h>

void odwroc(int tab[], size_t n) {
    for (size_t i = 0; i < n / 2; i++) {
        int tmp = tab[i];
        tab[i] = tab[n - 1 - i];
        tab[n - 1 - i] = tmp;
    }
}

int main(void) {
    int tab[] = {1, 2, 3, 4};
    odwroc(tab, sizeof(tab) / sizeof(tab[0]));

    char tekst[32] = "ala ma kota";
    printf("tekst: %s (%zu znaków)\n", tekst, strlen(tekst));
    printf("pierwszy znak: %c\n", tekst[0]);
    return 0;
}
```

Bezpieczniejsze wczytywanie do bufora:

```c
char imie[32];
scanf("%31s", imie); // miejsce na końcowe '\0'
```

Kopiowanie napisów wymaga bufora wystarczająco dużego na tekst i `\0`:

```c
char cel[32];
snprintf(cel, sizeof(cel), "%s", "przykład");
```


## 4. Tablice dynamiczne i macierze

### Dynamiczna macierz jako tablica wierszy

```c
#include <stdlib.h>

int **utworz_macierz(size_t wiersze, size_t kolumny) {
    int **macierz = calloc(wiersze, sizeof(*macierz));
    if (macierz == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < wiersze; i++) {
        macierz[i] = calloc(kolumny, sizeof(*macierz[i]));
        if (macierz[i] == NULL) {
            while (i > 0) {
                free(macierz[--i]);
            }
            free(macierz);
            return NULL;
        }
    }
    return macierz;
}

void zwolnij_macierz(int **macierz, size_t wiersze) {
    for (size_t i = 0; i < wiersze; i++) {
        free(macierz[i]);
    }
    free(macierz);
}
```

Mnożenie macierzy `A` o wymiarach `wiersze_a x wspólny` przez `B`:

```c
for (size_t i = 0; i < wiersze_a; i++) {
    for (size_t j = 0; j < kolumny_b; j++) {
        wynik[i][j] = 0;
        for (size_t k = 0; k < wspolny; k++) {
            wynik[i][j] += a[i][k] * b[k][j];
        }
    }
}
```


## 5. Struktury, `enum` i listy

```c
#include <stdio.h>

typedef struct {
    char imie[32];
    int rok;
} Student;

typedef enum {
    NIEPOLACZONY,
    LACZENIE,
    POLACZONY
} Stan;

int main(void) {
    Student student = {"Jan", 2025};
    Stan stan = POLACZONY;
    printf("%s, %d, stan = %d\n", student.imie, student.rok, stan);
    return 0;
}
```

### Lista jednokierunkowa

```c
typedef struct Wezel {
    int wartosc;
    struct Wezel *nastepny;
} Wezel;

void wypisz_liste(const Wezel *lista) {
    for (const Wezel *p = lista; p != NULL; p = p->nastepny) {
        printf("%d ", p->wartosc);
    }
    putchar('\n');
}
```

Ostatni węzeł ma `nastepny == NULL`. Każdy węzeł utworzony przez `malloc` trzeba później zwolnić.


## 6. Pliki tekstowe

Zawsze sprawdzaj, czy `fopen` zwrócił poprawny uchwyt.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *plik = fopen("dane.txt", "r");
    if (plik == NULL) {
        perror("dane.txt");
        return EXIT_FAILURE;
    }

    int suma = 0;
    int liczba;
    while (fscanf(plik, "%d", &liczba) == 1) {
        suma += liczba;
    }

    if (fclose(plik) != 0) {
        perror("fclose");
        return EXIT_FAILURE;
    }
    printf("suma = %d\n", suma);
    return EXIT_SUCCESS;
}
```

Najczęściej używane tryby:

| Tryb | Znaczenie |
| --- | --- |
| `"r"` | odczyt istniejącego pliku |
| `"w"` | zapis, wyczyszczenie poprzedniej zawartości |
| `"a"` | dopisywanie na końcu |

Do czytania tekstu wierszami użyj `fgets`, a nie `gets` — `gets` jest usunięte ze standardu C, bo nie kontroluje rozmiaru bufora.


## Szybka lista kontrolna

- Czy indeksy mieszczą się w zakresie tablicy?
- Czy bufor napisu ma miejsce na `\0`?
- Czy wynik `malloc`/`calloc` nie jest `NULL`?
- Czy każda alokacja ma odpowiadające `free`?
- Czy plik został otwarty i zamknięty poprawnie?
- Czy funkcja rekurencyjna ma przypadek bazowy?
- Czy kompilator nie zgłasza ostrzeżeń przy `-Wall -Wextra -pedantic`?
