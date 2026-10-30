#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

// Zadania 7.2 - Złożone typy danych

/*
    7.2.1 Zdefiniuj strukturę trojkat przechowującą długości boków trójkąta.
// Napisz funkcję, która otrzymuje jako argument zmienną typu struct trojkat,
// i zwraca jako wartość obwód trójkąta przekazanego w argumencie.
*/
struct trojkat{
    double a, b, c;
};

double obwod_trojkata(struct trojkat t){
    return t.a + t.b + t.c;
}

/*
    7.2.2 Napisz funkcję, która otrzymuje jako argumenty zmienną troj1 typu struct trojkat
// zdefiniowanego w zadaniu 7.2.1 oraz zmienną troj2 wskaźnik na zmienną typu struct trojkat,
// i przepisuje zawartość zmiennej troj1 do zmiennej wskazywanej przez troj2.
*/
void przepisz_trojkat(struct trojkat troj1, struct trojkat *troj2){
    *troj2 = troj1;
}

/*
    7.2.3 Zdefiniuj strukturę punkt służącą do przechowywania współrzędnych punktów
// w trójwymiarowej przestrzeni kartezjańskiej.
// Napisz funkcję, która otrzymuje jako argumenty tablicę tab o argumentach typu struct punkt
// oraz jej rozmiar, i zwraca jako wartość najmniejszą spośród odległości pomiędzy punktami
// przechowywanymi w tablicy tab. Zakładamy, że otrzymana w argumencie tablica ma co najmniej dwa argumenty.
*/
struct punkt{
    double x, y, z;
};

double min_odleglosc(struct punkt tab[], int n){
    double min = -1;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            double dx = tab[i].x - tab[j].x;
            double dy = tab[i].y - tab[j].y;
            double dz = tab[i].z - tab[j].z;
            double d = sqrt(dx*dx + dy*dy + dz*dz);
            if (min < 0 || d < min) min=d;
        }
    }
    return min;
}

/*
    7.2.4 Napisz funkcję, która otrzymuje jako argumenty tablice tab1 i tab2 o argumentach typu struct punkt
// zdefiniowanego w rozwiązaniu zadania 7.2.3 oraz ich rozmiar, i przepisuje zawartość tablicy tab1 do tablicy tab2.
*/
void kopiuj_punkty(struct punkt tab1[], struct punkt tab2[], int n){
    for (int i=0; i<n; i++){
        tab2[i] = tab1[i];
    }
}

/*
    7.2.5 Zdefiniuj strukturę punkt10 służącą do przechowywania współrzędnych punktów
// w dziesięciowymiarowej przestrzeni kartezjańskiej.
// Do przechowywania poszczególnych wymiarów wykorzystaj tablicę dziesięcioelementową.
// Napisz funkcję, która otrzymuje jako argumenty tablice tab1 i tab2 typu struct punkt10 oraz ich wspólny rozmiar,
// i przepisuje zawartość tablicy tab1 do tablicy tab2.
*/
struct punkt10{
    double wsp[10];
};

void kopiuj_punkty10(struct punkt10 tab1[], struct punkt10 tab2[], int n){
    for (int i=0; i<n; i++)
        for (int j=0; j<10; j++)
            tab2[i].wsp[j] = tab1[i].wsp[j];
}

/*
    7.2.6 Zdefiniuj strukturę punktn służącą do przechowywania współrzędnych punktów
// w n-wymiarowej przestrzeni kartezjańskiej. Do przechowywania poszczególnych wymiarów
// wykorzystaj tablicę n-elementową. W strukturze punktn przechowuj także ilość wymiarów przestrzeni.
// Napisz funkcję, która otrzymuje jako argumenty tablice tab1 i tab2 o argumentach typu struct punktn
// oraz ich wspólny rozmiar, i przepisuje zawartość tablicy tab1 do tablicy tab2.
// Zakładamy, że tablica tab2 jest pusta (czyli nie musimy się martwić o jej poprzednią zawartość).
*/
struct punktn{
    int n;
    double *wsp;
};

void kopiuj_punktyn(struct punktn tab1[], struct punktn tab2[], int rozmiar){
    for (int i=0; i<rozmiar; i++){
        tab2[i].n = tab1[i].n;
        tab2[i].wsp = malloc(tab1[i].n * sizeof(double));
        for (int j=0; j<tab1[i].n; j++)
            tab2[i].wsp[j] = tab1[i].wsp[j];
    }
}

/*
    7.2.7 Zdefiniuj strukturę zespolone służącą do przechowywania liczb zespolonych.
// Zdefiniowana struktura powinna zawierać pola im i re typu double służące do przechowywania
// odpowiednio części urojonej i rzeczywistej liczby zespolonej.
// Napisz funkcję dodaj, która dostaje dwa argumenty typu zespolone i zwraca jako wartość ich sumę.
*/
struct zespolone{
    double im, re;
};

struct zespolone dodaj(struct zespolone z1, struct zespolone z2){
    struct zespolone wynik;
    wynik.re = z1.re + z2.re;
    wynik.im = z1.im + z2.im;
    return wynik;
}

/*
    7.2.8 Zdefiniuj strukturę student służącą do przechowywania danych osobowych studenta
    (struktura powinna zawierać takie pola, jak: imie, nazwisko, adres, pesel, kierunek i numer legitymacji).
// Napisz funkcję, która otrzymuje jako argument wskaźnik na strukturę student i wczytuje dane
// ze standardowego wejścia do rekordu wskazywanego przez argument funkcji.
*/
struct student{
    char imie[50], nazwisko[50], adres[100], kierunek[50], pesel[12];
    int nr_leg;
};

void wczytaj_studenta(struct student *s){
    printf("Imie: ");           scanf("%49s", s->imie);
    printf("Nazwisko: ");       scanf("%49s", s->nazwisko);
    printf("Adres: ");          scanf("%99s", s->adres);
    printf("PESEL: ");          scanf("%11s", s->pesel);
    printf("Kierunek: ");       scanf("%49s", s->kierunek);
    printf("Nr legitymacji: "); scanf("%d",   s->nr_leg);
}

/*
    7.2.9 Zdefiniuj strukturę lista posiadającą dwa pola: jedno typu int oraz drugie będące wskaźnikiem do definiowanego typu.
*/
struct lista{
    int wartosc;
    struct lista *nast;
};

/*
    7.2.10 Zdefiniuj unię super_int, w której będzie można przechowywać zarówno zmienne typu int, jak i unsigned int.
*/
union super_int{
    int i;
    unsigned int ui;
};

/*
    7.2.11 Zdefiniuj unię Liczba, która może służyć w zależności od potrzeb do przechowywania liczby wymiernej lub liczby całkowitej.
// Zdefiniuj strukturę Dane, o dwóch polach: polu tp typu int oraz polu zaw typu Liczba.
// Napisz bezargumentową funkcję, która wczytuje ze standardowego wejścia zawartość do struktury Dane i zwraca ją jako wartość.
// Funkcja powinna pytać użytkownika, czy chce wczytać liczbę całkowitą, czy wymierną oraz w zależności od jego wyboru
// wstawić do pola tp wartość 0 lub 1. Następnie funkcja powinna wczytać do pola zaw wartość odpowiedniego typu.
*/
union liczba{
    int calkowita;
    double wymierna;
};

struct dane{
    int tp;
    union liczba zaw;
};

struct dane wczytaj_dane(){
    struct dane d;
    printf("Podaj typ liczby (0 - calkowita, 1 - wymierna)");
    scanf("%d", &d.tp);
    if (d.tp == 0){
        printf("Podaj liczbe calkowita: ");
        scanf("%d", &d.zaw.calkowita);
    } else {
        printf("Podaj liczbe wymierna: ");
        scanf("%lf", &d.zaw.wymierna);
    }
    return d;
}

/*
    7.2.12 Zdefiniuj strukturę zespolone, która ma służyć do przechowywania liczb zespolonych oraz unię Liczba
// mogącą przechowywać liczby wymierne i całkowite. Części urojona i rzeczywista liczby zespolonej powinny być
// przechowywane w polach im i re typu Liczba. Struktura zespolone powinna mieć dodatkowe pole tp przechowujące
// informację jakiego typu wartości przechowywane są w polach im i re (zakładamy, że oba są tego samego typu).
// Napisz funkcję dodaj, która dostaje dwa argumenty typu zespolone i zwraca jako wartość ich sumę.
// Zwróć uwagę na zgodność typów składników i zwracanej wartości (suma dwóch liczb całkowitych jest liczbą całkowitą,
// natomiast jeżeli którykolwiek ze składników jest wymierny to i suma jest wymierna).
*/
struct zespolone2 {
    int tp;
    union liczba re, im;
};

struct zespolone2 dodaj_zespolone2(struct zespolone2 z1, struct zespolone2 z2) {
    struct zespolone2 wynik;
    if (z1.tp == 1 || z2.tp == 1) {
        wynik.tp = 1;
        wynik.re.wymierna = (z1.tp ? z1.re.wymierna : z1.re.calkowita) +
                            (z2.tp ? z2.re.wymierna : z2.re.calkowita);
        wynik.im.wymierna = (z1.tp ? z1.im.wymierna : z1.im.calkowita) +
                            (z2.tp ? z2.im.wymierna : z2.im.calkowita);
    } else {
        wynik.tp = 0;
        wynik.re.calkowita = z1.re.calkowita + z2.re.calkowita;
        wynik.im.calkowita = z1.im.calkowita + z2.im.calkowita;
    }
    return wynik;
}

/*
    7.2.13 Zdefiniuj strukturę figura przechowującą wymiary figur geometrycznych niezbędne do obliczenia pola.
// Struktura powinna mieć możliwość przechowywania wymiarów takich figur, jak: trójkąt, prostokąt, równoległobok i trapez.
// Rodzaj przechowywanej figury powinien być zakodowany w wartości pola fig typu int.
// Definiując strukturę, staraj się zużyć jak najmniej pamięci.
// Napisz funkcję pole, która dostaje jako argument zmienną f typu struct figura i zwraca jako wartość pole figury której wymiary przechowuje zmienna f.
*/
struct figura {
    int fig;
    union {
        struct { double a, h; };
        struct { double a2, b2, h2; };
    } wym;
};

double pole(struct figura f) {
    switch (f.fig) {
        case 0:
            return 0.5 * f.wym.a * f.wym.h;
        case 1:
            return f.wym.a * f.wym.h;
        case 2:
            return f.wym.a * f.wym.h;
        case 3:
            return 0.5 * (f.wym.a2 + f.wym.b2) * f.wym.h2;
        default:
            return 0.0;
    }
}

/*
    7.2.14 Zdefiniuj typ wyliczeniowy czworokat, mogący przyjmować wartości odpowiadające nazwom różnych czworokątów.
*/
enum czworokat{
    KWADRAT,
    PROSTOKAT,
    ROMB,
    ROWNOLEGLOBOK,
    TRAPEZ,
};

/*
    7.2.15 Zdefiniuj typ wyliczeniowy zwierzak, mogący przyjmować wartości odpowiadające nazwom różnych zwierząt domowych.
*/
enum zwierzak{
    PIES,
    KOT,
    CHOMIK,
    PAPUGA,
};
/*
    7.2.16 Zdefiniuj typ wyliczeniowy, służący do przechowywania informacji o stanie połączenia internetowego,
// o trzech wartościach odpowiadających trzem stanom: połączenie nawiązane, połączenie nienawiązane i połączenie w trakcie nawiązywania.
// Następnie zdefiniuj strukturę komputer przechowującą stan połączenia, IP podłączonego komputera (jako napis) oraz nazwę jego właściciela.
// Napisz funkcję, która jako argument otrzymuje strukturę komputer i wyświetla na standardowym wyjściu jej zawartość w sposób przyjazny dla użytkownika.
*/
enum stan_polaczenia{
    POLACZONY,
    NIEPOLACZONY,
    LACZENIE,
};

struct komputer{
    enum stan_polaczenia stan;
    char ip[16];
    char wlasciciel[50];
};

void wypisz_komputer(struct komputer k){
    printf("Wlasciciel: %s\n", k.wlasciciel);
    printf("IP: %s\n", k.ip);
    printf("Stan polaczenia: ");
    switch (k.stan){
        case POLACZONY: printf("polaczenie nawiazane \n");
        case NIEPOLACZONY: printf("polaczenie nienawiazane\n");
        case LACZENIE:  printf("polaczenie w trakcie laczenia\n");
        default: printf("nieznany\n");
    }
}
/*
    7.2.17 Zdefiniuj strukturę dane_osobowe zawierającą pola: imie, nazwisko, plec, stan_cywilny.
// W zależności od płci pole stan_cywilny powinno móc mieć jedną z dwóch wartości wolny lub zonaty dla mężczyzn
// i wolna lub mezatka dla kobiet.
// Napisz funkcję wczytaj o dwóch argumentach: tablicy tab o elementów typu stan_cywilny i jej rozmiarze.
// Funkcja powinna wczytywać do komórek tablicy tab wartości podane na standardowym wejściu.
*/
enum plec {MEZCZYZNA, KOBIETA};
enum stan_cywilny_m {WOLNY, ZONATY};
enum stan_cywilny_k {WOLNA, MEZATKA};

struct dane_osobowe{
    char imie[50], nazwisko[50];
    enum plec plec;
    union {
        enum stan_cywilny_m m;
        enum stan_cywilny_k k;
    } stan;
};

void wczytaj_stan_cywilny(enum plec plec, void *stan) {
    if (plec == MEZCZYZNA) {
        int v;
        printf("Stan cywilny (0-wolny, 1-zonaty): ");
        scanf("%d", &v);
        *((enum stan_cywilny_m*)stan) = v ? ZONATY : WOLNY;
    } else {
        int v;
        printf("Stan cywilny (0-wolna, 1-mezatka): ");
        scanf("%d", &v);
        *((enum stan_cywilny_k*)stan) = v ? MEZATKA : WOLNA;
    }
}

void wczytaj(struct dane_osobowe tab[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Imie: ");      scanf("%49s", tab[i].imie);
        printf("Nazwisko: ");  scanf("%49s", tab[i].nazwisko);
        printf("Plec (0-mezczyzna, 1-kobieta): ");
        int p; scanf("%d", &p);
        tab[i].plec = p ? KOBIETA : MEZCZYZNA;
        wczytaj_stan_cywilny(tab[i].plec, &tab[i].stan);
    }
}

/*
    7.2.18 Zdefiniuj złożony typ danych dzięki któremu będzie można odnosić się do kolejnych bajtów zmiennej typu unsigned int
// jak do kolejnych elementów tablicy.
*/
union bajty_uint{
    unsigned int liczba;
    unsigned char bajt[sizeof(unsigned int)];
};

/*
    7.2.19 Wykorzystując typ danych zdefiniowany w rozwiązaniu zadania 18 napisz funkcję, która dostaje w argumentach dwie nieujemne liczby
// całkowite typu unsigned int i zwraca jako wartość nieujemną liczbę całkowitą, której kolejne bajty są iloczynami modulo 256 odpowiadających sobie bajtów liczb podanych w argumentach.
*/
unsigned int iloczyn_bajtow(unsigned int a, unsigned int b){
    union bajty_uint ua, ub, wynik;
    ua.liczba = a;
    ub.liczba = b;
    for (size_t i=0; i < sizeof(unsigned int); i++)
        wynik.bajt[i] = (ua.bajt[i] * ub.bajt[i]) % 256;
    return wynik.liczba;
}

int main(void) {
    return 0;
}
