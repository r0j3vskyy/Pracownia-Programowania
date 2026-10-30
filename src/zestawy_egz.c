#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ----------------------------------------------------------------
//                               ZESTAW A11
// ----------------------------------------------------------------

// Zadanie 1.
void minArrays(int n, int tabA[], int tabB[], int tabC[]){
    for (int i=0; i<n; i++){
        tabC[i] = (tabA[i] < tabB[i]) ? tabA[i] : tabB[i];
    }
}
// Przypadek testowy
void test_minArrays(){
    int A[] = {5, 2, 8, 1};
    int B[] = {3, 4, 7, 9};
    int C[4];
    minArrays(4, A, B, C);
    printf("Test minArrays: ");
    for (int i=0; i<4; i++) printf("%d ", C[i]);
    printf("\n");
}

// Zadanie 2.
int calculate(float (*fun)(float), float x){
    int n = (int)x;
    for (int i=1; i<=n; i++){
        if (fun(i) != fun(-i)) return 0;
    }
    return 1;
}
// Przypadek testowy
float even_fun(float x) { return x * x; }
float odd_fun(float x) { return x; }

void test_calculate(){
    printf("Even: %d\n", calculate(even_fun, 3.7f)); // 1
    printf("Odd: %d\n", calculate(odd_fun, 3.7f)); // 0 
}

// Zadanie 3.
typedef struct {
    char name[32];
    char country[32];
    float record;
} Athlete;

const char* getname(Athlete arr[], int n){
    int maxIdx = 0;
    for (int i=0; i<n; i++){
        if (arr[i].record > arr[maxIdx].record) maxIdx = i;
    }
    return arr[maxIdx].name;
}
// Przypadek testowy
void test_getname(){
    Athlete arr[] = {
        {"John", "USA", 45.8f},
        {"Anna", "France", 22.3f},
        {"Tom", "Canada", 22.4f}
    };
    printf("Test getName %s\n", getname(arr, 3));
}

// Zadanie 4.
struct node {
    int i;
    struct node *next;
};

int maximum(struct node *head){
    int found = 0;
    int max = 0;
    struct node *p = head->next;
    while (p){
        if (!found || p->i > max){
            max = p->i;
            found = 1;
        }
        p = p->next;
    }
    return found ? max : 0;
}
// Przypadek testowy
void test_maximum() {
    struct node *head = malloc(sizeof(struct node));
    head->next = NULL;
    int values[] = {4,5,6,-34,0,25,11};
    struct node *last = head;
    for (int i = 0; i < 7; i++) {
        struct node *n = malloc(sizeof(struct node));
        n->i = values[i];
        n->next = NULL;
        last->next = n;
        last = n;
    }
    printf("Test maximum: %d\n", maximum(head)); // Oczekiwane: 25
    // Zwolnienie pamięci
    struct node *p = head, *tmp;
    while (p) { tmp = p; p = p->next; free(tmp); }
}

// --- MAIN TESTY ---
// int main() {
//     test_minArrays();
//     test_calculate();
//     test_getName();
//     test_maximum();
//     return 0;
// }

// ----------------------------------------------------------------
//                                 Zestaw A12
// ----------------------------------------------------------------

// Zadanie 1.
void wypisz_dzielniki(){
    int n;
    printf("Podaj n: ");
    scanf("%d", &n);
    printf("Dzielniki liczby %d: ", n);
    for (int i=2; i<= n/2; i++){
        if (n % i == 0) printf("%d ", i);
    }
    printf("\n");
}

// Zadanie 2.
int findSubstring(char *str, char *sub){
    int i,j;
    for (i=0; str[i] != '\0'; i++){
        for (j=0; sub[j] != '\0'; j++){
            if (str[i+j] != sub[j]) break;
        }
        if (sub[j] == '\0') return i;
    }
    return -1;
}
// Przypadek testowy
void test_findSubstring(){
    printf("Test1: %d\n", findSubstring("ABCD", "BC"));
    printf("Test 2: %d\n", findSubstring("Olsztyn", "xy"));
}

// Zadanie 3.
void reverse(int n, int m, int tab[][m]){
    for (int col=0; col<m; col++){
        if (col % 2 == 1){
            for (int i=0, j= n-1; i<j; i++, j--){
                int tmp = tab[i][col];
                tab[i][col] = tab[j][col];
                tab[j][col] = tmp;
            }
        }
    }
}
// Przypadek testowy
void test_reverse() {
    int tab[4][3] = {
        {2, 3, -3},
        {1, 4, 7},
        {-3, -6, 11},
        {-2, 8, 23}
    };
    reverse(4, 3, tab);
    printf("Test reverse:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) printf("%3d ", tab[i][j]);
        printf("\n");
    }
}

// Zadanie 4.
struct elem{
    int a;
    struct elem *next;
};

void printMinNeg(struct elem *head){
    struct elem *p = head->next;
    int found = 0, min = 0;
    while (p){
        if (p->a < 0 && (!found || p->a < min)){
            min = p->a;
            found = 1;
        }
        p = p->next;
    }
    if (found) printf("%d\n", min);
}
// Przypadek testowy
void test_printMinNeg() {
    struct elem *head = malloc(sizeof(struct elem));
    head->next = NULL;
    int values[] = {4, -5, 9, -11};
    struct elem *last = head;
    for (int i = 0; i < 4; i++) {
        struct elem *n = malloc(sizeof(struct elem));
        n->a = values[i];
        n->next = NULL;
        last->next = n;
        last = n;
    }
    printf("Test printMinNeg (powinno być -11): ");
    printMinNeg(head);
    // Zwolnienie pamięci
    struct elem *p = head, *tmp;
    while (p) { tmp = p; p = p->next; free(tmp); }
}

// --- MAIN TESTY ---
// int main() {
//     wypisz_dzielniki();
//     test_findSubstring();
//     test_reverse();
//     test_printMinNeg();
//     return 0;
// }

// ----------------------------------------------------------------
//                                 Zestaw A13
// ----------------------------------------------------------------

// Zadanie 1.
int altSeries(unsigned int n){
    if (n == 0) return 3;
    if (n %2 == 0) return 2 * altSeries(n-1) -1;
    else return altSeries(n-1)*altSeries(n-1) + 1;
}
// Przypadek testowy
void test_altSeries(){
    printf("alt series: ");
    for (int i=0; i<=6; i++){
        printf("%d ", altSeries(i));
    }
    printf("\n");
}

// Zadanie 2.
void concat(int n, int tab1[], int tab2[], int tab3[]){
    for (int i=0; i<n; i++) tab3[i] = tab2[i];
    for (int i=0; i<n; i++) tab3[n+i] = tab1[i] - tab2[i];
}
// Przypadek testowy
void test_concat(){
    int t1[] = {3, 4, 5}, t2[] = {4, -5, 9}, t3[6];
    concat(3, t1, t2, t3);
    printf("Test concat: ");
    for (int i=0; i<6; i++) printf("%d ", t3[i]);
    printf("\n");
}

// Zadanie 3.
int* newArray(int **tab, int n, int m){
    int *result = malloc(n * m * sizeof(int));
    if (!result) return NULL;
    for (int i=0, k=0; i<n; i++)
        for (int j=0; j<m; j++)
            result[k++] = tab[i][j];
    return result;
}
// Przypadek testowy
void test_newArray() {
    int n = 2, m = 3;
    int **tab = malloc(n * sizeof(int*));
    tab[0] = malloc(m * sizeof(int));
    tab[1] = malloc(m * sizeof(int));
    tab[0][0] = 3; tab[0][1] = 4; tab[0][2] = -3;
    tab[1][0] = -3; tab[1][1] = 2; tab[1][2] = 11;
    int *flat = newArray(tab, n, m);
    printf("Test newArray: ");
    for (int i = 0; i < n * m; i++) printf("%d ", flat[i]);
    printf("\n"); // Oczekiwane: 3 4 -3 -3 2 11
    free(tab[0]); free(tab[1]); free(tab); free(flat);
}

// Zadanie 4.
struct node1 {
    int x;
    struct node1 *next;
};
int sumCubeOdd(struct node1 *l) {
    int sum = 0;
    while (l) {
        if (l->x % 2 != 0)
            sum += l->x * l->x * l->x;
        l = l->next;
    }
    return sum;
}

int compareCube(struct node1 *l1, struct node1 *l2) {
    return sumCubeOdd(l1) == sumCubeOdd(l2) ? 1 : 0;
}
// Przypadek testowy
void test_compareCube() {
    // Lista 1: 3,4
    struct node1 *l1 = malloc(sizeof(struct node1));
    l1->x = 3; l1->next = malloc(sizeof(struct node1));
    l1->next->x = 4; l1->next->next = NULL;
    // Lista 2: -3,2,5
    struct node1 *l2 = malloc(sizeof(struct node1));
    l2->x = -3; l2->next = malloc(sizeof(struct node1));
    l2->next->x = 2; l2->next->next = malloc(sizeof(struct node1));
    l2->next->next->x = 5; l2->next->next->next = NULL;
    printf("Test compareCube: %d\n", compareCube(l1, l2)); // Oczekiwane: 0
    // Zwolnienie pamięci
    struct node1 *p, *tmp;
    p = l1; while (p) { tmp = p; p = p->next; free(tmp); }
    p = l2; while (p) { tmp = p; p = p->next; free(tmp); }
}

// --- MAIN TESTY ---
// int main() {
//     test_altSeries();
//     test_concat();
//     test_newArray();
//     test_compareCube();
//     return 0;
// }

// ----------------------------------------------------------------
//                                 Zestaw A14
// ----------------------------------------------------------------

// Zadanie 1.
void zamien_na_przeciwne(int *x, int *y, int *z){
    *x = -*x;
    *y = -*y;
    *z = -*z;
}
// Przypadek testowy
void test_zamien_na_przeciwne(){
    int x=5, y= -7, z=0;
    zamien_na_przeciwne(&x, &y, &z);
    printf("Test zamien na przeciwne: %d %d %d", x, y, z);
}

// Zadanie 2.
void reverse_tab(unsigned int n, int tab[]){
    for (int i=0, j=n-1; i<j; i++, j--){
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}
// Przypadek testowy
void test_reverse_tab(){
    int tab[] = {3, 4, 5};
    reverse_tab(3, tab);
    printf("Test reverse tab: ");
    for (int i=0; i<3; i++) printf("%d ", tab[i]);
    printf("\n");
}

// Zadanie 3.
typedef struct{
    char marka[10];
    float cena;
} Pralka;

float najtansza(Pralka arr[], int n){
    float min = arr[0].cena;
    for (int i=0; i<n; i++){
        if (arr[i].cena < min) min = arr[i].cena;
    }
    return min;
}
// Przypadek testowy
void test_najtansza(){
    Pralka tab[] = {
        {"AAA", 3456},
        {"BBB", 2316},
        {"CCC", 1523}
    };
    printf("Test najtansza: %0.f\n", najtansza(tab, 3));
}

// Zadanie 4.
struct node_merge {
    int w;
    struct node_merge *next;
};

struct node_merge* merge(struct node_merge *l1, struct node_merge *l2) {
    struct node_merge *head = NULL, *tail = NULL;
    // Dodaj parzyste z l1
    while (l1) {
        if (l1->w % 2 == 0) {
            struct node_merge *nowy = malloc(sizeof(struct node_merge));
            nowy->w = l1->w;
            nowy->next = NULL;
            if (!head) head = tail = nowy;
            else { tail->next = nowy; tail = nowy; }
        }
        l1 = l1->next;
    }
    // Dodaj parzyste z l2
    while (l2) {
        if (l2->w % 2 == 0) {
            struct node_merge *nowy = malloc(sizeof(struct node_merge));
            nowy->w = l2->w;
            nowy->next = NULL;
            if (!head) head = tail = nowy;
            else { tail->next = nowy; tail = nowy; }
        }
        l2 = l2->next;
    }
    return head;
}
// Przypadek testowy
void test_merge() {
    // Lista1: 5 -> 12
    struct node_merge *l1 = malloc(sizeof(struct node_merge));
    l1->w = 5; l1->next = malloc(sizeof(struct node_merge));
    l1->next->w = 12; l1->next->next = NULL;
    // Lista2: -3 -> 54 -> 11
    struct node_merge *l2 = malloc(sizeof(struct node_merge));
    l2->w = -3; l2->next = malloc(sizeof(struct node_merge));
    l2->next->w = 54; l2->next->next = malloc(sizeof(struct node_merge));
    l2->next->next->w = 11; l2->next->next->next = NULL;
    // Merge
    struct node_merge *wynik = merge(l1, l2);
    printf("Test merge: ");
    for (struct node_merge *p = wynik; p; p = p->next) printf("%d ", p->w);
    printf("\n"); // Oczekiwane: 12 54
    // Zwolnienie pamięci
    struct node_merge *p, *tmp;
    p = l1; while (p) { tmp = p; p = p->next; free(tmp); }
    p = l2; while (p) { tmp = p; p = p->next; free(tmp); }
    p = wynik; while (p) { tmp = p; p = p->next; free(tmp); }
}

// --- MAIN TESTY ---
// int main() {
//     test_zamien_na_przeciwne();
//     test_reverse_tab();
//     test_najtansza();
//     test_merge();
//     return 0;
// }

// ----------------------------------------------------------------
//                                 Zestaw A15
// ----------------------------------------------------------------

// Zadanie 1.
int modifyAndSum(int (*modifier)(int), int number1, int number2){
    return modifier(number1) + modifier(number2);
}
// Przykładowe modyfikatory
int plusOne(int x) { return x + 1; }
int negate(int x) { return -x; }
// Przypadek testowy
void test_modifyAndSum() {
    printf("Test modifyAndSum (+1): %d\n", modifyAndSum(plusOne, 3, 7)); // 4+8=12
    printf("Test modifyAndSum (negate): %d\n", modifyAndSum(negate, 3, 7)); // -3+-7=-10
}

// Zadanie 2.
char* reverseString(char *str){
    int len = 0;
    while (str[len] != '\0') len++;
    char *rev = malloc((len+1) * sizeof(char));
    if (!rev) return NULL;
    for (int i=0; i<len; i++)
        rev[i] = str[len - 1 - i];
    rev[len] = '\0';
    return rev;
}
// Przypadek testowy
void test_reverseString(){
    char *s = "ABC";
    char *r = reverseString(s);
    printf("Test reverseString: %s\n", r);
    free(r);
}

// Zadanie 3.
typedef enum {PON, WT, SR, CZW, PT, SOB, ND} DayOfWeek;

void ptDayOfWeek(DayOfWeek d){
    switch (d){
        case PON: printf("Poniedzialek\n"); break;
        case WT: printf("Wtorek\n"); break;
        case SR: printf("Sroda\n"); break;
        case CZW: printf("Czwartek\n"); break;
        case PT: printf("Piatek\n"); break;
        case SOB: printf("Sobota\n"); break;
        case ND: printf("Niedziela\n"); break;
        default: printf("Nieznany.\n");
    }
}
// Przypadek testowy
void test_ptDayOfWeek(){
    ptDayOfWeek(PON);
    ptDayOfWeek(SOB);
    ptDayOfWeek(CZW);
}

// Zadanie 4.
struct node_lastpos {
    float value;
    struct node_lastpos *next;
};

struct node_lastpos* lastPositive(struct node_lastpos *head){
    struct node_lastpos *p = head->next;
    struct node_lastpos *last = NULL;
    while (p){
        if (p->value > 0) last = p;
        p = p->next;
    }
    return last;
}
// Przypadek testowy
void test_lastPositive() {
    struct node_lastpos *head = malloc(sizeof(struct node_lastpos));
    head->next = NULL;
    float vals[] = {-2.5, 3.1, -1.0, 7.2, -4.0};
    struct node_lastpos *last = head;
    for (int i = 0; i < 5; i++) {
        struct node_lastpos *n = malloc(sizeof(struct node_lastpos));
        n->value = vals[i];
        n->next = NULL;
        last->next = n;
        last = n;
    }
    struct node_lastpos *res = lastPositive(head);
    printf("Test lastPositive: ");
    if (res) printf("%.1f\n", res->value); // Oczekiwane: 7.2
    else printf("NULL\n");
    // Zwolnienie pamięci
    struct node_lastpos *p = head, *tmp;
    while (p) { tmp = p; p = p->next; free(tmp); }
}

// --- MAIN TESTY ---
// int main() {
//     test_modifyAndSum();
//     test_reverseString();
//     test_printDayOfWeek();
//     test_lastPositive();
//     return 0;
// }

// ----------------------------------------------------------------
//                                 Zestaw A16
// ----------------------------------------------------------------


// Zadanie 1.
double polynomial_value(unsigned int n, double x){
    if (n==0) return 1.0;
    return (x-1) * polynomial_value(n-1, x) + 1;
}
// Przypadki testowe
void test_polynomial_value(){
    printf("Test 1: n=3, x=2: %.2f\n", polynomial_value(3, 2));
    printf("test 2: n=5, x=1 %.2f\n", polynomial_value(5, 1));
}

// Zadanie 2.
int same_sign(double (*f1)(double), double (*f2)(double), int n){
    for (int i = 0; i <= n; i++) {
        double v1 = f1(-i), v2 = f2(-i);
        if ((v1 > 0 && v2 < 0) || (v1 < 0 && v2 > 0)) return 0;
        if (v1 == 0 && v2 != 0) return 0;
        if (v2 == 0 && v1 != 0) return 0;
    }
    return 1;
}
// Przykładowe funkcje
double fun1(double x) { return x * x - 1; }
double fun2(double x) { return fabs(x) - 1; }
double fun3(double x) { return -x; }
// Przypadek testowy
void test_same_sign() {
    printf("Test same_sign (fun1, fun2, n=3): %d\n", same_sign(fun1, fun2, 3)); // 1
    printf("Test same_sign (fun1, fun3, n=2): %d\n", same_sign(fun1, fun3, 2)); // 0
}

// Zadanie 3.
typedef struct {
    char tytul[50];
    int liczba_stron;
} Ksiazka;

int max_stron(Ksiazka arr[], int n){
    int max = arr[0].liczba_stron;
    for (int i=1; i<n; i++)
        if (arr[i].liczba_stron > max) max = arr[i].liczba_stron;
    return max;
}
// Przypadek testowy
void test_max_stron(){
    Ksiazka tab[] = {
        {"Pan Tadeusz", 340},
        {"Lalka", 520},
        {"Ferdydurke", 300}
    };
    printf("Test max_stron %d\n", max_stron(tab, 3));
}

// Zadanie 4.
struct elem2 {
    int x;
    struct elem2 *next;
};

void usun_ostatni_nieparzysty(struct elem2 *head){
    struct elem2 *p = head, *ostatni_prev = NULL, *ostatni = NULL;
    while (p->next){
        if (p->next->x %2 != 0){
            ostatni_prev = p;
            ostatni = p->next;
        }
        p = p->next;
    }
    if (ostatni_prev && ostatni){
        ostatni_prev->next = ostatni->next;
        free(ostatni);
    }
}
// Przypadek testowy
void test_usun_ostatni_nieparzysty() {
    struct elem2 *head = malloc(sizeof(struct elem2));
    head->next = NULL;
    int vals[] = {2, 5, 8, 7, 4, 9};
    struct elem2 *last = head;
    for (int i = 0; i < 6; i++) {
        struct elem2 *n = malloc(sizeof(struct elem2));
        n->x = vals[i];
        n->next = NULL;
        last->next = n;
        last = n;
    }
    printf("Przed usunieciem: ");
    for (struct elem2 *p = head->next; p; p = p->next) printf("%d ", p->x);
    printf("\n");
    usun_ostatni_nieparzysty(head);
    printf("Po usunieciu: ");
    for (struct elem2 *p = head->next; p; p = p->next) printf("%d ", p->x);
    printf("\n");
    // Zwolnienie pamięci
    struct elem2 *p = head, *tmp;
    while (p) { tmp = p; p = p->next; free(tmp); }
}

// --- MAIN TESTY ---
// int main() {
//     test_polynomial_value();
//     test_same_sign();
//     test_max_stron();
//     test_usun_ostatni_nieparzysty();
//     return 0;
// }

// ----------------------------------------------------------------
//                                 Zestaw A17
// ----------------------------------------------------------------

// Zadanie 1.
float* init_block(){
    float *blok = malloc(4 * sizeof(float));
    if (!blok) return NULL;
    blok[0] = 0.5f;
    blok[1] = 1.5f;
    blok[2] = 2.5f;
    blok[3] = 3.5f;
    return blok;
}
// Przypadek testowy
void test_init_block() {
    float *blok = init_block();
    if (blok) {
        printf("Test init_block: ");
        for (int i = 0; i < 4; i++) printf("%.1f ", blok[i]);
        printf("\n");
        free(blok);
    }
}

// Zadanie 2.
int count_hex_digits(char *napis){
    int licznik = 0;
    for (int i=0; napis[i] != '\0'; i++){
        char c = napis[i];
            if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'F') ||
            (c >= 'a' && c <= 'f')) licznik++;
    }
    return licznik;
}
// Przypadek testowy
void test_count_hex_digits() {
    printf("Test count_hex_digits: %d\n", count_hex_digits("Ala ma 123F koty!")); // Oczekiwane: 6
}

// Zadanie 3.
typedef struct {
    char marka[15];
    int przebieg;
} Samochod;

Samochod* init_samochod(char *marka, int przebieg){
    int len = 0;
    while (marka[len] != '\0') len++;
    if (len < 3 || przebieg <= 1000) return NULL;
    Samochod *s = malloc(sizeof(Samochod));
    if (!s) return NULL;
    int i=0;
    for (; i < 14 && marka[i] != '\0'; i++) s->marka[i] = marka[i];
    s->marka[i] = '\0';
    s->przebieg = przebieg;
    return s;
}

void dodajKilometry(Samochod *s){
    if (s) s->przebieg += 1000;
}
// Przypadek testowy
void test_Samochod() {
    Samochod *s1 = initSamochod("BMW", 1500);
    Samochod *s2 = initSamochod("VW", 2000); // za krótka marka
    Samochod *s3 = initSamochod("Toyota", 900); // za mały przebieg
    printf("Test Samochod:\n");
    if (s1) {
        printf("Marka: %s, przebieg: %d\n", s1->marka, s1->przebieg);
        dodajKilometry(s1);
        printf("Po dodaniu: %d\n", s1->przebieg);
        free(s1);
    }
    if (!s2) printf("s2 = NULL (za krótka marka)\n");
    if (!s3) printf("s3 = NULL (za mały przebieg)\n");
}

// Zadanie 4.
struct node4 {
    int x;
    struct node4 *next;
};

int suma_nieparzystych(struct node4 *head){
    int suma = 0;
    struct node4 *p = head->next;
    while (p){
        if (p->x %2 != 0) suma += p->x;
        p = p->next;
    }
    return suma;
}
// Przypadek testowy
void test_suma_nieparzystych() {
    struct node4 *head = malloc(sizeof(struct node4));
    head->next = NULL;
    int vals[] = {2, 5, 8, 7, 4, 9};
    struct node4 *last = head;
    for (int i = 0; i < 6; i++) {
        struct node4 *n = malloc(sizeof(struct node4));
        n->x = vals[i];
        n->next = NULL;
        last->next = n;
        last = n;
    }
    printf("Test suma_nieparzystych: %d\n", suma_nieparzystych(head)); // Oczekiwane: 5+7+9=21
    // Zwolnienie pamięci
    struct node4 *p = head, *tmp;
    while (p) { tmp = p; p = p->next; free(tmp); }
}

// --- MAIN TESTY ---
// int main() {
//     test_init_block();
//     test_count_hex_digits();
//     test_Samochod();
//     test_suma_nieparzystych();
//     return 0;
// }