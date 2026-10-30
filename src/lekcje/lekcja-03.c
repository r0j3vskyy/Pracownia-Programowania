// Zadania 1.4
#include<stdio.h>
#include<stdlib.h>

// 1.4.1
int main() {
    int n,m;

    if (scanf("%d %d", &n, &m) != 2 || n<=0 || m<=0){
        printf("Błąd. Podaj dwie dodatnie liczby całkowite. \n");
        return 1;
    }
    for (int i=n; i<m; i+=n){
        printf("%d\n", i);
    }
    getchar();
    getchar();
    return 0;
}

// 1.4.2
int zadanie_main_2(void) {
    int m,n;
    if (scanf("%d %d", &m, &n) != 2 || m<=0 || n<=0){
        printf("Błąd. Podaj dwie dodatnie liczby całkowite. \n");
        return 1;
    }
    for (int i = 1; i<=m; i++){
        printf("%d\n", i*n);
    }
    getchar();
    getchar();
    return 0;
}

// 1.4.3
int zadanie_main_3(void){
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i=n; i=k; i+=n){
        if (i>m){
            printf("%d\n", i);
        }
    }
    getchar();
    getchar();
    return 0;
}

// 1.4.4
int zadanie_main_4(void){
    int n;
    int k = 1;
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        k = k*i;
    }
    printf("%d", k);
    getchar();
    getchar();
    return 0;
}

// 1.4.5
int zadanie_main_5(void){
    int n;
    int k=0;
    scanf("%d", &n);
    for (int i=0; i<=n; i++){
        k += i*i;
    }
    printf("%d", k);

    getchar();
    getchar();
    return 0;
}

// 1.4.6
int zadanie_main_6(void){
    int n;
    int iloczyn = 1;
    scanf("%d", &n);
    for (int i=2; i<=n; i+=2){
        if (i%2==0){
            iloczyn *= i;
        }
    }
    printf("%d", iloczyn);

    getchar();
    getchar();
    return 0;
}

// 1.4.7
int zadanie_main_7(void){
    int n,m;
    int iloczyn = 1;
    scanf("%d %d", &n, &m);
    for (int i = n; i<=m; i++){
        iloczyn *= i;
    }
    printf("%d", iloczyn);
    getchar();
    getchar();
    return 0;
}

// 1.4.8
int zadanie_main_8(void){
    int n, i, fib1=1, fib2=1, pom;
    printf("Podaj liczbe calkowita n: ");
    scanf("%d", &n);
    for(i=2; i<=n; i++){
        pom = fib1;
        fib1 = fib2+fib1;
        fib2 = pom;
    }
    printf("Element ciagu Finabocciego o indeksie %d to %d\n", n, fib1);
    getchar();
    getchar();
    return 0;
}

// 1.4.9
int zadanie_main_9(void){
    int n,m, nwd=1, max;
    printf("Podaj liczby calkowite n, m: ");
    scanf("%d %d", &n, &m);
    while (m != 0){
        int temp = m;
        m = n % m;
        n = temp;
    }
    printf("NWD: %d", n);
    getchar();
    getchar();
    return 0;
}

// 1.4.10
int zadanie_main_10(void){
    int x, i, pierw=0;
    printf("Podaj liczbe calkowita x: ");
    scanf("%d", &x);
    for(i=1; i<=x; i++)
        if (i * i <= x)
            pierw=i;
    printf("Pierwiastek z %d to w przyblizeniu %d\n", x, pierw);
    getchar();
    getchar();
    return 0;
}

// 1.4.11
int zadanie_main_11(void){
    int a, b, c, d, x;
    // a)
    printf("Podaj liczby: a, b, c, d: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    x = 1;
    while (abs(a)*x*x + b*x + c > d){
        x++;
    }
    printf("Wynik to: %d", x);
    getchar();
    getchar();
    return 0;
}


// 1.4.12
int zadanie_main_12(void){
    int n, m, pom1, pom2, suma=0, i;
    printf("Podaj liczbe calkowita n: ");
    scanf("%d", &n);
    for(i=2; i<n; i++){
        pom1 = n;
        pom2 = i;
        while (pom1*pom2 != 0)
            if (pom1<pom2)
                pom2 = pom2%pom1;
// else
                pom1 = pom1%pom2;
        if ((pom1 == 1) || (pom2 == 1))
            suma += i;
    }
    printf("Wynik obliczen to: %d \n", suma);
    getchar();
    getchar();
    return 0;
}

// 1.4.13
int zadanie_main_13(void){
    int n, silnia=1, suma=1;
    printf("Podaj liczbe calkowita n: ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        silnia *= i;
        suma += silnia;
    }
    printf("0!+1!+...+%d!= %d", n, suma);
    getchar();
    getchar();
    return 0;
}

// 1.4.14
/*
// Napisz program, który wczytuje ze standardowego wejścia liczbę n i wypisuje
// na standardowym wyjściu wszystkie trójki pitagorejskie (tj. trójki liczb całkowitych
    a,b,c takich, że a^2 + b^2 = c^2), składające się z liczb mniejszych od n.
*/
int zadanie_main_14(void){
    int n;
    printf("Podaj liczbe n: ");
    scanf("%d", &n);

    for (int a=1; a<n; a++){
        for (int b=a; b<n; b++){
            for (int c=b; c<n; c++){
                if (a*a + b*b == c*c){
                    printf("(%d, %d, %d)\n", a, b, c);
                }
            }
        }
    }
    getchar();
    getchar();
    return 0;
}
