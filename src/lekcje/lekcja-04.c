// Zadania 2.2
#include<stdio.h>
#include<stdlib.h>

// 2.2.1
int main(){
    int n;
    printf("Podaj liczbe calkowita n: ");
    scanf("%d", &n);
    if(n<0){
        n = -n;
    }
    printf("Wartosc bezwzgledna z liczby to: %d", n);
    getchar();
    getchar();
    return 0;
}

// 2.2.2
int zadanie_main_2(void){
    int n, wynik=1;
    printf("Podaj liczbe calkowita n: ");
    scanf("%d", &n);
    for (int i= 1; i <= n; i++){
        wynik *= i;
    }
    printf("Suma wynosi: %d", wynik);
    getchar();
    getchar();
    return 0;
}

// 2.2.3
int najwiekszydzielnik(int n){
    for (int k = n-1; k>0; k--){
        if (n%k == 0){
            return k;
        }
    }
    return 1;
}
int zadanie_main_3(void){
    int n, k;
    printf("Podaj liczbe nieujemna calkowita n: ");
    scanf("%d", &n);
    if (n <= 2){
        printf("Błąd. Liczba n musi być większa niż 2. \n");
        return 1;
    }
    k = najwiekszydzielnik(n);
    printf("Najwiekszy dzielnik %d mniejszy od %d to %d\n", n, n, k);
    getchar();
    getchar();
    return 0;
}

// 2.2.4
int zadanie_main_4(void){
    unsigned int n;
    int wynik = 1;
    printf("Podaj potege liczby 2: ");
    scanf("%d", &n);
    for (unsigned int i = 0; i<n; i++){
        wynik *= 2;
    }
    printf("Wynik 2 do potegi %d to: %d", n, wynik);
    getchar();
    getchar();
    return 0;
}

// 2.2.5
int zadanie_main_5(void){
    int n;
    double wynik = 1.0;
    printf("Podaj potege liczby 2: ");
    scanf("%d", &n);
    if (n >= 0){
        for (int i = 0; i<n; i++){
            wynik *= 2;
        }
    }
    else {
        for (int i = 0; i<-n; i++){
            wynik /= 2;
        }
    }
    printf("Wynik 2 do potegi %d to: %lf", n, wynik);
    getchar();
    getchar();
    return 0;
}

// 2.2.6
int zadanie_main_6(void){
    unsigned int n, m;
    int wynik = 1;
    printf("Podaj liczbe n i m: ");
    scanf("%d %d", &n, &m);
    if (n != 0 || m != 0){
        for (int i=0; i<m; i++){
            wynik *= n;
        }
    }
    else {
        printf("Co najmniej jedna z liczb nie może być równa 0.");
        return 1;
    }
    printf("Wynik %d^%d to: %d", n, m, wynik);
    getchar();
    getchar();
    return 0;
}

// 2.2.7
int zadanie_main_7(void){
    int n, m;
    double wynik = 1.0;
    printf("Podaj liczby n i m: ");
    scanf("%d %d", &n, &m);
    if (n != 0 || m != 0){
        if(m<0){
            for(int i=0; i<-m; i++){
                wynik *= 1.0/n;
            }
        }
        else{
            for(int i=0; i<m; i++){
                wynik *= n;
            }
        }
    }
    else {
        printf("Liczby muszą być różne od 0.");
        return 1;
    }
    printf("Wynik liczenia %d^%d to: %lf.", n, m, wynik);
    getchar();
    getchar();
    return 0;
}

// 2.2.8
int zadanie_main_8(void){
    unsigned int n;
    int x = 0;
    printf("Podaj liczbe n: ");
    scanf("%d", &n);
    while ((x + 1)*(x + 1)<= n){
        x++;
    }
    printf("Pierwiastek kwadratowy z %d to: %d", n, x);
    getchar();
    getchar();
    return 0;
}

// 2.2.9
/*
// Napisz funkcje, ktora dostaje jako argumenty liczbe całkowitą m (m>1) oraz
// nieujemną liczbę n i zwraca jako wartośćć ⌊m√n⌋. Rozwiąż zadanie nie wykorzystując
// funkcji bibliotecznych.
*/
int pierwiastek_calkowity(int m, unsigned int n) {
    if (m <= 1) return -1;
    int x = 0;
    while (1) {
        unsigned int potega = 1;
        for (int i = 0; i < m; i++) {
            potega *= (x + 1);
            if (potega > n) break;
        }
        if (potega > n) break;
        x++;
    }
    return x;
}

int zadanie_main_9(void) {
    int m;
    unsigned int n;
    printf("Podaj liczby m i n: ");
    scanf("%d %u", &m, &n);
    if (m > 1) {
        int wynik = pierwiastek_calkowity(m, n);
        printf("Podlogowy pierwiastek stopnia %d z %u to: %d\n", m, n, wynik);
    } else {
        printf("Liczba m musi byc wieksza niz 1.\n");
        return 1;
    }
    getchar();
    getchar();
    return 0;
}

// 2.2.10
int wzgl_pierwsza(int a, int b){
    while (b){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int wylicz_sume(int n){
    int sum = 0;
    for (int i=1; i<n; i++){
        if (wzgl_pierwsza(i, n) == 1){
            sum += 1;
        }
    }
    return sum;
}

int zadanie_main_10(void){
    unsigned int n;
    printf("Podaj liczbe: ");
    scanf("%d", &n);
    printf("Suma liczb wzglednie pierwszych z %d wynosi %d\n", n, wylicz_sume(n));
    getchar();
    getchar();
    return 0;
}


// Funkcja podłogowa (zaokrąglenie w dół).
int funkcja_podlogowa(double x){
    int wynik = (int)x;
    if (x < 0 && x != wynik){
        wynik -= 1;
    }
    return wynik;
}

// 2.2.11
// funkcja obliczajaca podlogowa sume pierwiastkow
int sumapd(int n){
    int sum = 0;
    int sqrt_i = 0;
    for (int i = 0; i<=n; i++){
        while ((sqrt_i + 1)*(sqrt_i + 1) <= i){
            sqrt_i++;
        }
        sum += sqrt_i;
    }
    return sum;
}

int zadanie_main_11(void){
    int n;
    printf("Podaj liczbe n: ");
    scanf("%d", &n);

    if (n < 0){
        printf("Liczba n musi byc nieujemna!\n");
        return 1;
    }
    printf("Suma: %d\n", sumapd(n));
    getchar();
    getchar();
    return 0;
}

// 2.2.12
int pierwiastki_calkowite(int i, int m){
    int root = 0;
    int power = 1;

    while (power <= i){
        root++;
        power = 1;
        for (int j = 0; j < m; j++){
            power *= root;
        }
        if (power > i) return root - 1;
    }
    return root;
}
int suma(int n, int m){
    int sum = 0;
    for (int i = 0; i <= n; i++){
        sum += pierwiastki_calkowite(i, m);
    }
    return sum;
}
int zadanie_main_12(void){
    int n, m;
    printf("Podaj liczby n i m (m>1): ");
    scanf("%d %d", &n, &m);

    if (n < 0 || m <= 1){
        printf("n musi być nieujemne, a m>1!\n");
        return 1;
    }
    printf("Suma: %d\n", suma(n, m));
    getchar();
    getchar();
    return 0;
}

// 2.2.13
void suma_kwadratow(int n, int tryb){
    for (int a=1; a*a <= n; a++){
        for (int b=1; b*b <= n; b++){
            if (a*a + b*b == n){
                if (tryb == 1){ 
                    printf("%d^2 + %d^2 = %d\n", a, b, n);
                }
                else if (tryb == 2 && a <= b){
                    printf("%d^2 + %d^2 = %d\n", a, b, n);
                }
            }
        }
    }
}

int zadanie_main_13(void){
    int n, tryb;
    printf("Podaj liczbe n: ");
    scanf("%d", &n);
    printf("Wybierz tryb: \n1- wszystkie rozklady \n2- bez duplikatow \n: ");
    scanf("%d", &tryb);

    if (n <= 0 || (tryb != 1 && tryb != 2)){
        printf("n musi byc dodatnie a tryb 1 lub 2!\n");
        return 1;
    }
    suma_kwadratow(n, tryb);
    getchar();
    getchar();
    return 0;
}

// 2.2.14

// 2.2.15

// 2.2.16

// 2.2.17
void zlicz(){
    static unsigned int liczba = 0;
    liczba++;
    printf("Funkcja zostala wywolana %d razy. \n", liczba);
}

// 2.2.18

// 2.2.19
int wczytaj(){
    int temp;
    static int suma = 0;
    scanf("%d", &temp);
    suma = suma+temp;
    printf("Dodalem %d, teraz mam %d \n", temp, suma);
    return temp;
}
int zadanie_main_14(void){
    printf("%d \n", wczytaj());
    printf("%d \n", wczytaj());
    return 0;
}


// 2.2.20
unsigned int silnia(unsigned int n){
    if (n <= 1)
        return 1;
        return silnia(n-1) * n;
}

// 2.2.21
unsigned int ciag_1(unsigned int n){
    if (n == 0)
        return 1;
    return 2 * ciag_1(n-1) + 5;
}


// 2.2.22
unsigned int ciag_2(unsigned int n){
    if (n == 0 || n == 1)
        return 1;
    return ciag_2(n-1) + 2*ciag_2(n-2) + 3;
}


// 2.2.23
unsigned int fib(unsigned int n){
    if (n <=1)
        return 1;
        return fib(n-1) + fib(n-2);
}

// 2.2.24
int rek_1(int n){
    if (n == 0 || n == 1)
        return 1;
    int suma = 0;
    for (int i=0; i<n; i++){
        suma = suma + rek_1(i);
    }
    return suma;
}
int zadanie_main_15(void){
    int i;
    scanf("%d", &i);
    printf("%d \n", rek_1(i));
    return 0;
}


// 2.2.25
int rek_2(int n){
    if (n == 0 || n == 1)
        return 1;
    if (n%2 == 0)
        return rek_2(n-1) +n;
    else if (n%2 == 1)
        return rek_2(n-1)*n;
}
int zadanie_main_16(void){
    int n;
    scanf("%i", &n);
    printf("%i \n", rek_2(n));
    return 0;
}


// 2.2.26
unsigned int ciag_3(unsigned int n){
    if (n <= 2)
        return 1;
// else
        switch (n%3){
            case 0: return ciag_3(n-1) + ciag_3(n-2);
            case 1: return 5 * ciag_3(n-1) + 4;
            case 2: return ciag_3(n-1);
        }
}

// 2.2.27
unsigned int f(unsigned int n, unsigned int m){
    if (n == 0)
        return m;
    if (m == 0)
        return n;
    return f(n-1, m) + f(n, m-1) + f(n-1, m-1);
}

// 2.2.28
int rek_3(int n, int m){
    if (m == 0)
        return n;
    if (n >= m)
        return n - m + rek_3(n-1, m) + rek_3(n, m-1);
    return rek_3(m,n);
}
int zadanie_main_17(void){
    int n,m;
    scanf("%i %i", &n, &m);
    printf("%i \n", rek_3(n, m));
}


// 2.2.29
unsigned int NWD(unsigned int n, unsigned int m){
    if (n == m)
        return m;
    if (n > m)
        return NWD(n%m, m);
// else
        return NWD(m%n, n);
}























int zadanie_main_18(void) {
    int win = 0;
    char literka;
    
    

    while (win < 10) {
        printf("WYGRALES? (T/N) \n ");
        scanf("%c", &literka);
        if (literka == "T"){
            win++;
            printf("winy: %d", win);
        }
        else if (literka == "N") {
            printf("noob");

        }
    }
    return 0;
}
