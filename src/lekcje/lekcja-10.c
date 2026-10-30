#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Zadania 7.3 - Listy jednokierunkowe

typedef struct element {
    int i;
    struct element *next;
} element;

/*
    7.3.1 Napisz funkcję utworz zwracającą wskaźnik do pustej listy bez głowy o elementach typu element.
*/
// utwórz pusta liste bez glowy
element* utworz() {
    return NULL;
}

/*
    7.3.2 Napisz funkcję wyczysc, która dostaje jako argument wskaźnik
// do pierwszego elementu listy wskaźnikowej bezgłowy o elementach typu element i usuwa wszystkie elementy listy.
*/
// czyszczenie listy bez glowy
void wyczysc(element *lista){
    element *tmp;
    while (lista){
        tmp = lista;
        lista = lista->next;
        free(tmp);
    }
}

/*
    7.3.3 Napisz funkcję dodaj o dwóch argumentach Lista typu element*
// oraz a typu int zwracającą wskaźnik do typu element. Funkcja powinna dodawać na początek listy reprezentowanej przez zmienną Lista
// nowy element o wartości a pola i oraz zwracać wskaźnik do pierwszego
// elementu tak powiększonej listy.
*/
// dodawanie na poczatek listy
element* dodaj(element *lista, int a){
    element *nowy = malloc(sizeof(element));
    if (!nowy) return lista;
    nowy->i = a;
    nowy->next = lista;
    return nowy;
}

/*
    7.3.4 Napisz funkcję dodajk o dwóch argumentach Lista typu element*
// i a typu int zwracającą wskaźnik do typu element. Funkcja powinna
// dodawać na koniec listy reprezentowanej przez zmienną Lista nowy
// element o wartości a pola i oraz zwracać wskaźnik do pierwszego
// elementu tak powiększonej listy.
*/
// dodawanie na koniec listy
element* dodajk(element *lista, int a){
    element *nowy = malloc(sizeof(element));
    if (!nowy) return lista;
    nowy->i = a;
    nowy->next = NULL;
    if (!lista) return nowy;
    element *p = lista;
    while (p->next) p = p->next;
    p->next = nowy;
    return lista;
}

/*
    7.3.5 Napisz funkcję dodajw o trzech argumentach Lista i elem typu
// element* oraz a typu int zwracającą wskaźnik do typu element.
// Funkcja powinna dodawać element o wartości a pola i do listy reprezentowanej przez zmienną Lista na miejscu tuż za elementem wskazywanym przez elem. W przypadku, gdy elem jest równy NULL funkcja
// powinna wstawić nowy element na początek listy. Funkcja powinna
// zwrócić jako wartość wskaźnik do pierwszego elementu powiększonej
// listy.
*/
// dodawanie za wskazanym elementem
element* dodajw(element *lista, element *elem, int a) {
    element *nowy = malloc(sizeof(element));
    if (!nowy) return lista;
    nowy->i = a;
    if (!elem) {
        nowy->next = lista;
        return nowy;
    } else {
        nowy->next = elem->next;
        elem->next = nowy;
        return lista;
    }
}

/*
    7.3.6 Napisz funkcję znajdz o dwóch argumentach Lista typu
// element* i a typu int zwracającą wskaźnik do typu element. Funkcja powinna sprawdzać, czy na liście reprezentowanej przez zmienną
// Lista znajduje się element o polu i równym a. Jeżeli tak, to funkcja
// powinna zwrócić wskaźnik do tego elementu. W przeciwnym wypadku
// funkcja powinna zwrócić wartość NULL.
*/
// szukanie elementu o zadanej wartości
element* znajdz(element *lista, int a){
    while (lista){
        if (lista->i == a) return lista;
        lista = lista->next;
    }
    return NULL;
}

/*
    7.3.7 Napisz funkcję usun o dwóch argumentach Lista typu element*
// i a typu int zwracającą wskaźnik do typu element. Funkcja powinna
// usuwać z listy reprezentowanej przez zmienną Lista element o wartości a pola i (o ile taki element znajduje się na liście) oraz zwracać
// wskaźnik do pierwszego elementu zmodyfikowanej listy (jeżeli po usunięciu elementu lista będzie pusta, to funkcja powinna zwrócić wartość
// NULL).
*/
// usuwanie elementu o zadanej wartości
element* usun(element *lista, int a){
    element *p = lista, *poprz = NULL;
    while (p && p->i != a){
        poprz = p;
        p = p->next;
    }
    if (!p) return lista;
    if (!poprz) {
        lista = p->next;
    } else {
        poprz->next = p->next;
    }
    free(p);
    return lista;
}

/*
    7.3.8 Napisz funkcję usunw o dwóch argumentach Lista i elem typu
// element* i zwracającą wskaźnik do typu element. Funkcja powinna
// usuwać z listy reprezentowanej przez zmienną Lista element wskazywany przez elem oraz zwracać wskaźnik do pierwszego elementu
// zmodyfikowanej listy (jeżeli po usunięciu elementu lista będzie pusta,
// to funkcja powinna zwrócić wartość NULL). Dla elem równego NULL
// funkcja usunw nie powinna nic robić.
*/
// usuwanie elementu wskazywanego przez elem
element* usunw(element *lista, element *elem){
    if (!elem) return lista;
    element *p = lista, *poprz = NULL;
    while (p && p != elem){
        poprz = p;
        p = p->next;
    }
    if (!p) return lista;
    if (!poprz){
        lista = p->next;
    } else {
        poprz->next = p->next;
    }
    free(p);
    return lista;
}


/*
    7.3.9 Napisz funkcję usunw2 o dwóch argumentach Lista i elem typu
// element* i zwracającą wskaźnik do typu element. Funkcja powinna
// usuwać z listy reprezentowanej przez zmienną Lista element wskazywany przez elem->next oraz zwracać wskaźnik do pierwszego elementu zmodyfikowanej listy (jeżeli po usunięciu elementu lista będzie
// pusta, to funkcja powinna zwrócić wartość NULL). Dla elem równego
// NULL funkcja powinna usunąć pierwszy element listy (o ile taki istnieje). Dla elem różnego od NULL i elem->next równego NULL funkcja
// usunw2 nie powinna nic robić.
*/
// Usuwanie elementu wskazywanego przez elem->next lub pierwszego, jeśli elem == NULL.
element* usunw2(element *lista, element *elem) {
    if (!elem) {
        if (!lista) return NULL;
        element *tmp = lista;
        lista = lista->next;
        free(tmp);
        return lista;
    }
    if (!elem->next) return lista;
    element *tmp = elem->next;
    elem->next = tmp->next;
    free(tmp);
    return lista;
}

/*
    7.3.10 Napisz funkcję utworz tworzącą pustą listę z głową o elementach
// typu element i zwracającą jako wartość wskaźnik do głowy utworzonej
// listy.
*/
// tworzenie pustej listy z głową
element* utworz_z_glowa() {
    element *glowa = malloc(sizeof(element));
    if (!glowa) return NULL;
    glowa->next = NULL;
    return glowa;
}

/*
    7.3.11 Napisz funkcję wyczysc, która dostaje jako argument wskaźnik
// do listy wskaźnikowej z głową o elementach typu element i usuwa
// wszystkie elementy listy (razem z głową).
*/
// czyszczenie listy z głową
void wyczysc_z_glowa(element *glowa) {
    element *p = glowa;
    while (p) {
        element *tmp = p;
        p = p->next;
        free(tmp);
    }
}

/*
    7.3.12 Napisz funkcję dodaj o dwóch argumentach Lista typu element*
// i a typu int. Funkcja powinna dodawać na początek listy reprezentowanej przez zmienną Lista nowy element o wartości a pola i.
*/
// dodawanie na początek listy z głową
void dodaj_z_glowa(element *glowa, int a) {
    element *nowy = malloc(sizeof(element));
    if (!nowy) return;
    nowy->i = a;
    nowy->next = glowa->next;
    glowa->next = nowy;
}

/*
    7.3.13 Napisz funkcję dodajk o dwóch argumentach Lista typu element*
// i a typu int. Funkcja powinna dodawać na koniec listy reprezentowanej przez zmienną Lista nowy element o wartości a pola i.
*/
// dodawanie na koniec listy z głową
void dodajk_z_glowa(element *glowa, int a) {
    element *nowy = malloc(sizeof(element));
    if (!nowy) return;
    nowy->i = a;
    nowy->next = NULL;
    element *p = glowa;
    while (p->next) p = p->next;
    p->next = nowy;
}

/*
    7.3.14 Napisz funkcję dodajw o trzech argumentach Lista oraz elem typu
// element* i a typu int. Funkcja powinna dodawać element o wartości
// a pola i do listy reprezentowanej przez zmienną Lista na miejscu tuż
// za elementem wskazywanym przez elem.
*/
// dodawanie za wskazanym elementem w liście z głową
void dodajw_z_glowa(element *glowa, element *elem, int a) {
    element *nowy = malloc(sizeof(element));
    if (!nowy) return;
    nowy->i = a;
    if (!elem) {
        nowy->next = glowa->next;
        glowa->next = nowy;
    } else {
        nowy->next = elem->next;
        elem->next = nowy;
    }
}

/*
    7.3.15 Napisz funkcję znajdz o dwóch argumentach Lista typu element*
// i a typu int zwracającą wskaźnik do typu element. Funkcja powinna
// sprawdzać, czy na liście reprezentowanej przez zmienną Lista, znajduje się element o polu i równym a. Jeżeli tak, to funkcja powinna
// zwrócić wskaźnik do tego elementu. W przeciwnym wypadku funkcja
// powinna zwrócić wartość NULL.
*/
// szukanie elementu o zadanej wartości w liście z głową
element* znajdz_z_glowa(element *glowa, int a) {
    element *p = glowa->next;
    while (p) {
        if (p->i == a) return p;
        p = p->next;
    }
    return NULL;
}

/*
    7.3.16 Napisz funkcję znajdzp o dwóch argumentach Lista typu element*
// i a typu int zwracającą wskaźnik do typu element. Funkcja powinna
// sprawdzać, czy na liście reprezentowanej przez zmienną Lista, znajduje się element o polu i równym a. Jeżeli tak, to funkcja powinna
// zwrócić wskaźnik do elementu go poprzedzającego. W przeciwnym
// wypadku funkcja powinna zwrócić wskaźnik do ostatniego elementu
// listy.
*/
// dla listy bez głowy
element* znajdzp(element *lista, int a) {
    if (!lista) return NULL;
    element *poprz = NULL, *p = lista;
    while (p) {
        if (p->i == a) return poprz;
        poprz = p;
        p = p->next;
    }
    return poprz;
}

// dla listy z głową
element* znajdzp_z_glowa(element *glowa, int a) {
    element *poprz = glowa, *p = glowa->next;
    while (p) {
        if (p->i == a) return poprz;
        poprz = p;
        p = p->next;
    }
    return poprz;
}

/*
    7.3.17 Napisz funkcję usun o dwóch argumentach Lista typu element*
// i a typu int. Funkcja powinna usuwać z listy reprezentowanej
// przez zmienną Lista element o wartości a pola i (o ile taki element
// znajduje się na liście).
*/
// dla listy z głową
void usun_z_glowa(element *glowa, int a) {
    element *poprz = glowa, *p = glowa->next;
    while (p) {
        if (p->i == a) {
            poprz->next = p->next;
            free(p);
            return;
        }
        poprz = p;
        p = p->next;
    }
}

/*
    7.3.18 Napisz funkcję usunw o dwóch argumentach Lista i elem typu
// element*. Funkcja powinna usuwać z listy reprezentowanej
// przez zmienną Lista element wskazywany przez zmienną elem.
*/
// dla listy z głową
void usunw_z_glowa(element *glowa, element *elem) {
    if (!elem) return;
    element *poprz = glowa, *p = glowa->next;
    while (p) {
        if (p == elem) {
            poprz->next = p->next;
            free(p);
            return;
        }
        poprz = p;
        p = p->next;
    }
}

/*
    7.3.19 Napisz funkcję usunw2 o dwóch argumentach Lista i elem typu
// element*. Funkcja powinna usuwać z listy reprezentowanej
// przez zmienną Lista element wskazywany przez elem->next.
*/
// dla listy z głową
void usunw2_z_glowa(element *glowa, element *elem) {
    if (!elem) {
        if (!glowa->next) return;
        element *tmp = glowa->next;
        glowa->next = tmp->next;
        free(tmp);
        return;
    }
    if (!elem->next) return;
    element *tmp = elem->next;
    elem->next = tmp->next;
    free(tmp);
}

/*
    7.3.20 Napisz funkcję zeruj, która dostaje jako argument listę wskaźnikową o elementach typu element i nadaje wartość 0 polom i we wszystkich elementach listy. Napisz dwie wersje funkcji: dla list z głową
// i dla list bez głowy.
*/
// bez głowy
void zeruj(element *lista) {
    while (lista) {
        lista->i = 0;
        lista = lista->next;
    }
}

// z głową
void zeruj_z_glowa(element *glowa) {
    element *p = glowa->next;
    while (p) {
        p->i = 0;
        p = p->next;
    }
}

/*
    7.3.21 Napisz funkcję bezwzględna, która dostaje jako argument listę wskaźnikową o elementach typu element i zapisuje do pól i wszystkich
// elementów listy wartość bezwzględną ich pierwotnej wartości. Napisz
// dwie wersje funkcji: dla list z głową i dla list bez głowy.
*/
// bez głowy
void bezwzgledna(element *lista) {
    while (lista) {
        if (lista->i < 0) lista->i = -lista->i;
        lista = lista->next;
    }
}

// z głową
void bezwzgledna_z_glowa(element *glowa) {
    element *p = glowa->next;
    while (p) {
        if (p->i < 0) p->i = -p->i;
        p = p->next;
    }
}

/*
    7.3.22 Zdefiniuj strukturę trojkat mogącą służyć jako typ elementów listy
// jednokierunkowej. Struktura trojkat powinna posiadać pola służące
// do przechowywania wszystkich boków trójkąta oraz jego pola.
// Napisz funkcję pole, która otrzymuje w argumencie listę wskaźnikową
// o elementach typu trojkat i we wszystkich elementach listy do odpowiedniego pola wstawia wartość pola trójkąta o bokach, których długość przechowuje dana struktura. Napisz dwie wersje funkcji: dla list
// z głową i dla list bez głowy.
*/
typedef struct trojkat {
    double a, b, c, pole;
    struct trojkat *next;
} trojkat;

// bez głowy
void pole_trojkat(trojkat *lista) {
    while (lista) {
        double p = (lista->a + lista->b + lista->c) / 2.0;
        lista->pole = sqrt(p * (p - lista->a) * (p - lista->b) * (p - lista->c));
        lista = lista->next;
    }
}

// z głową
void pole_trojkat_z_glowa(trojkat *glowa) {
    trojkat *p = glowa->next;
    while (p) {
        double s = (p->a + p->b + p->c) / 2.0;
        p->pole = sqrt(s * (s - p->a) * (s - p->b) * (s - p->c));
        p = p->next;
    }
}

/*
    7.3.23 Zdefiniuj strukturę trojka mającą służyć jako typ elementu jednokierunkowej listy wskaźnikowej przechowującej trójki dodatnich liczb
// całkowitych a, b, c.
// Napisz funkcję pitagoras, która dostaje w argumencie listę wskaźnikową o elementach typu trojka i usuwa z otrzymanej listy wszystkie
// elementy nieprzechowujące trójek pitagorejskich (czyli takich,
    że a^2 + b^2 = c^2). Napisz dwie wersje funkcji: dla list z głową
// i dla list bez głowy. W wersji dla list bez głowy funkcja powinna
// zwracać wskaźnik do pierwszego elementu przekształconej listy. Jeżeli
// wynikowa lista bez głowy będzie pusta, funkcja powinna zwrócić NULL.
*/
typedef struct trojka {
    int a, b, c;
    struct trojka *next;
} trojka;

// bez głowy
trojka* pitagoras(trojka *lista) {
    trojka *p = lista, *poprz = NULL;
    while (p) {
        if (p->a * p->a + p->b * p->b != p->c * p->c) {
            trojka *do_usuniecia = p;
            if (!poprz) {
                lista = p->next;
                p = lista;
            } else {
                poprz->next = p->next;
                p = p->next;
            }
            free(do_usuniecia);
        } else {
            poprz = p;
            p = p->next;
        }
    }
    return lista;
}
// z głową
void pitagoras_z_glowa(trojka *glowa) {
    trojka *poprz = glowa, *p = glowa->next;
    while (p) {
        if (p->a * p->a + p->b * p->b != p->c * p->c) {
            trojka *do_usuniecia = p;
            poprz->next = p->next;
            p = p->next;
            free(do_usuniecia);
        } else {
            poprz = p;
            p = p->next;
        }
    }
}

/*
    7.3.24 Napisz funkcję suma, która dostaje jako argument listę wskaźnikową o elementach typu element i zwraca jako wartość sumę pól i
// ze wszystkich elementów listy. Napisz dwie wersje funkcji: dla list z głową i dla list bez głowy.
*/
// bez głowy
int suma(element *lista) {
    int s = 0;
    while (lista) {
        s += lista->i;
        lista = lista->next;
    }
    return s;
}
// z głową
int suma_z_glowa(element *glowa) {
    int s = 0;
    element *p = glowa->next;
    while (p) {
        s += p->i;
        p = p->next;
    }
    return s;
}

/*
    7.3.25 Napisz funkcję minimum, która dostaje jako argument listę wskaźnikową o elementach typu element i zwraca jako wartość najmniejszą
// spośród wartości pól i elementów listy. Napisz dwie wersje funkcji:
// dla list z głową i dla list bez głowy.
*/
// bez głowy
int minimum(element *lista) {
    if (!lista) return 0;
    int min = lista->i;
    lista = lista->next;
    while (lista) {
        if (lista->i < min) min = lista->i;
        lista = lista->next;
    }
    return min;
}
// z głową
int minimum_z_glowa(element *glowa) {
    element *p = glowa->next;
    if (!p) return 0;
    int min = p->i;
    p = p->next;
    while (p) {
        if (p->i < min) min = p->i;
        p = p->next;
    }
    return min;
}

/*
    7.3.26 Napisz funkcję minimum, która dostaje jako argument Lista listę wskaźnikową o elementach typu element i zwraca jako wartość
// wskaźnik do elementu listy o najmniejszej wartości pola i. Napisz
// dwie wersje funkcji: dla list z głową i dla list bez głowy.
*/
// bez głowy
element* minimum_elem(element *lista) {
    if (!lista) return NULL;
    element *min_elem = lista;
    lista = lista->next;
    while (lista) {
        if (lista->i < min_elem->i) min_elem = lista;
        lista = lista->next;
    }
    return min_elem;
}
// z głową
element* minimum_elem_z_glowa(element *glowa) {
    element *p = glowa->next;
    if (!p) return NULL;
    element *min_elem = p;
    p = p->next;
    while (p) {
        if (p->i < min_elem->i) min_elem = p;
        p = p->next;
    }
    return min_elem;
}

/*
    7.3.27 Napisz funkcję minimum, która dostaje jako argument listę wskaźnikową o elementach typu element i zwraca jako wartość wskaźnik
// do bezpośredniego poprzednika elementu listy o najmniejszej wartości
// pola i. Napisz dwie wersje funkcji: dla list z głową i dla list bez głowy. W przypadku listy bez głowy, jeżeli najmniejszą wartość pola i
// ma pierwszy element listy lub gdy otrzymana w argumencie lista jest
// pusta, funkcja minimum powinna zwrócić wartość NULL.
*/
// bez głowy
element* minimum_prev(element *lista) {
    if (!lista || !lista->next) return NULL;
    element *min_prev = NULL, *prev = NULL, *p = lista;
    int min = lista->i;
    while (p->next) {
        if (p->next->i < min) {
            min = p->next->i;
            min_prev = p;
        }
        p = p->next;
    }
    if (lista->i <= min) return NULL;
    return min_prev;
}
// z głową
element* minimum_prev_z_glowa(element *glowa) {
    element *min_prev = glowa, *prev = glowa, *p = glowa->next;
    if (!p) return NULL;
    int min = p->i;
    while (p->next) {
        if (p->next->i < min) {
            min = p->next->i;
            min_prev = p;
        }
        p = p->next;
    }
    return min_prev;
}

/*
    7.3.28 Napisz funkcję, która dostaje jako argument listę o elementach typu element i zwraca jako wartość największą na wartość bezwzględną
// spośród różnic pomiędzy polami i w różnych elementach listy otrzymanej w argumencie. Zakładamy, że otrzymana w argumencie funkcji lista jest co najmniej dwuelementowa. Napisz dwie wersje funkcji:
// dla list z głową i dla list bez głowy.
*/
// bez głowy
int max_roznica(element *lista) {
    int max = 0;
    for (element *p = lista; p; p = p->next) {
        for (element *q = p->next; q; q = q->next) {
            int diff = abs(p->i - q->i);
            if (diff > max) max = diff;
        }
    }
    return max;
}
// z głową
int max_roznica_z_glowa(element *glowa) {
    int max = 0;
    for (element *p = glowa->next; p; p = p->next) {
        for (element *q = p->next; q; q = q->next) {
            int diff = abs(p->i - q->i);
            if (diff > max) max = diff;
        }
    }
    return max;
}

/*
    7.3.29 Napisz funkcję kopiuj, która jako argument otrzymuje jednokierunkową listę wskaźnikową o elementach typu element, tworzy kopię
// otrzymanej w argumencie listy i zwraca jako wartość wskaźnik do kopii. Napisz dwie wersje funkcji: dla list z głową i dla list bez głowy.
*/
// bez głowy
element* kopiuj(element *lista) {
    if (!lista) return NULL;
    element *kopia = NULL, *ostatni = NULL;
    while (lista) {
        element *nowy = malloc(sizeof(element));
        if (!nowy) return NULL;
        nowy->i = lista->i;
        nowy->next = NULL;
        if (!kopia) {
            kopia = nowy;
        } else {
            ostatni->next = nowy;
        }
        ostatni = nowy;
        lista = lista->next;
    }
    return kopia;
}
// z głową
element* kopiuj_z_glowa(element *glowa) {
    element *nowa_glowa = malloc(sizeof(element));
    if (!nowa_glowa) return NULL;
    nowa_glowa->next = NULL;
    element *ostatni = nowa_glowa;
    element *p = glowa->next;
    while (p) {
        element *nowy = malloc(sizeof(element));
        if (!nowy) return NULL;
        nowy->i = p->i;
        nowy->next = NULL;
        ostatni->next = nowy;
        ostatni = nowy;
        p = p->next;
    }
    return nowa_glowa;
}

/*
    7.3.30 Napisz funkcję doklej o dwóch argumentach Lista1 i Lista2
// typu element * wskazujących na dwie jednokierunkowe listy wskaźnikowe bez głowy, która wstawia na koniec listy Lista1 elementy listy
// Lista2 (funkcja nie powinna alokować w pamięci nowych zmiennych
// typu element, ale odpowiednio podpiąć już istniejące). Funkcja powinna zwracać wskaźnik do pierwszego elementu połączonej listy.
*/
// bez głowy
element* doklej(element *lista1, element *lista2) {
    if (!lista1) return lista2;
    element *p = lista1;
    while (p->next) p = p->next;
    p->next = lista2;
    return lista1;
}

/*
    7.3.31 Napisz funkcję, która dostaje w argumentach wskaźnik do listy
// wskaźnikowej o elementach typu element i odwraca kolejność elementów listy. Napisz dwie wersje funkcji: dla list z głową i dla list bez głowy. W wersji dla list bez głowy funkcja powinna zwracać wskaźnik
// do pierwszego elementu odwróconej listy.
*/
// bez głowy
element* odwroc(element *lista) {
    element *prev = NULL, *curr = lista, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// z głową
void odwroc_z_glowa(element *glowa) {
    element *prev = NULL, *curr = glowa->next, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    glowa->next = prev;
}

/*
    7.3.32 Napisz funkcję która dostaje w argumentach wskaźniki do dwóch
// list wskaźnikowych bez głowy o elementach typu element i równej
// długości, tworzy listę złożoną z elementów obu list ułożonych naprzemiennie (pierwszy ma być pierwszy element pierwszej listy, następnie pierwszy element drugiej listy, drugie element pierwszej listy itd.)
// i zwraca jako wartość wskaźnik do pierwszego elementu nowo utworzonej listy.
*/
element* naprzemiennie(element *l1, element *l2) {
    element *head = NULL, *tail = NULL;
    while (l1 && l2) {
        element *n1 = malloc(sizeof(element));
        element *n2 = malloc(sizeof(element));
        if (!n1 || !n2) return NULL;
        n1->i = l1->i; n1->next = n2;
        n2->i = l2->i; n2->next = NULL;
        if (!head) head = n1;
        else tail->next = n1;
        tail = n2;
        l1 = l1->next;
        l2 = l2->next;
    }
    return head;
}

/*
    7.3.33 Napisz funkcję, która dostaje jako argument listę wskaźnikową
// o elementach typu element i przesuwa jej elementy w taki sposób,
    że pierwszy element będzie drugi, drugi element będzie trzeci etc.
// a na pierwszym miejscu będzie ostatni element pierwotnej listy. Dla listy o długości nie większej niż 1 funkcja nie powinna nic robić. Napisz
// dwie wersje funkcji: dla list z głową i dla list bez głowy. W wersji
// dla list bez głowy funkcja powinna zwracać wskaźnik do pierwszego
// elementu przekształconej listy.
*/
// bez głowy
element* przesun(element *lista) {
    if (!lista || !lista->next) return lista;
    element *prev = NULL, *last = lista;
    while (last->next) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = lista;
    return last;
}
// z głową
void przesun_z_glowa(element *glowa) {
    if (!glowa->next || !glowa->next->next) return;
    element *prev = glowa->next, *last = glowa->next;
    while (last->next) {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = glowa->next;
    glowa->next = last;
}

/*
    7.3.34 Napisz funkcję, która dostaje jako argumenty dwie listy wskaźnikowe Lista1 i Lista2 o elementach typu element i tworzy nową listę
// o elementach tego samego typu przechowującą wartości występujące
// w polach i elementów zarówno listy Lista1 jak i Lista2. W stworzonej liście nie powinny powtarzać się przechowywane w elementach
// wartości. Funkcja powinna zwracać wskaźnik do nowo utworzonej listy.
// Napisz dwie wersje funkcji: dla list z głową i dla list bez głowy.
*/
// pomocnicza funkcja sprawdzająca czy wartość już jest na liście
int zawiera(element *lista, int a) {
    while (lista) {
        if (lista->i == a) return 1;
        lista = lista->next;
    }
    return 0;
}
// bez głowy
element* unia(element *l1, element *l2) {
    element *wynik = NULL, *tail = NULL;
    while (l1) {
        if (!zawiera(wynik, l1->i)) {
            element *nowy = malloc(sizeof(element));
            nowy->i = l1->i;
            nowy->next = NULL;
            if (!wynik) wynik = nowy;
            else tail->next = nowy;
            tail = nowy;
        }
        l1 = l1->next;
    }
    while (l2) {
        if (!zawiera(wynik, l2->i)) {
            element *nowy = malloc(sizeof(element));
            nowy->i = l2->i;
            nowy->next = NULL;
            if (!wynik) wynik = nowy;
            else tail->next = nowy;
            tail = nowy;
        }
        l2 = l2->next;
    }
    return wynik;
}
// z głową
element* unia_z_glowa(element *g1, element *g2) {
    element *wynik = malloc(sizeof(element));
    wynik->next = NULL;
    element *tail = wynik;
    element *p = g1->next;
    while (p) {
        if (!zawiera(wynik->next, p->i)) {
            element *nowy = malloc(sizeof(element));
            nowy->i = p->i;
            nowy->next = NULL;
            tail->next = nowy;
            tail = nowy;
        }
        p = p->next;
    }
    p = g2->next;
    while (p) {
        if (!zawiera(wynik->next, p->i)) {
            element *nowy = malloc(sizeof(element));
            nowy->i = p->i;
            nowy->next = NULL;
            tail->next = nowy;
            tail = nowy;
        }
        p = p->next;
    }
    return wynik;
}


/*
    7.3.35 Napisz funkcję sortującą rosnąco podaną w argumencie listę
// o elementach typu element. Napisz dwie wersje funkcji: dla list z głową
// i dla list bez głowy. W wersji dla listy bez głowy funkcja powinna
// zwracać wskaźnik do pierwszego elementu posortowanej listy.
*/
// bez głowy (sortowanie przez wstawianie)
element* sortuj(element *lista) {
    element *posortowana = NULL;
    while (lista) {
        element *wstawiany = lista;
        lista = lista->next;
        if (!posortowana || wstawiany->i < posortowana->i) {
            wstawiany->next = posortowana;
            posortowana = wstawiany;
        } else {
            element *p = posortowana;
            while (p->next && p->next->i < wstawiany->i)
                p = p->next;
            wstawiany->next = p->next;
            p->next = wstawiany;
        }
    }
    return posortowana;
}
// z głową
void sortuj_z_glowa(element *glowa) {
    element *posortowana = NULL;
    element *p = glowa->next;
    while (p) {
        element *wstawiany = p;
        p = p->next;
        if (!posortowana || wstawiany->i < posortowana->i) {
            wstawiany->next = posortowana;
            posortowana = wstawiany;
        } else {
            element *q = posortowana;
            while (q->next && q->next->i < wstawiany->i)
                q = q->next;
            wstawiany->next = q->next;
            q->next = wstawiany;
        }
    }
    glowa->next = posortowana;
}

int main(void) {
    return 0;
}
