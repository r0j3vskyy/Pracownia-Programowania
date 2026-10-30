# Pracownia programowania

Zbiór materiałów i ćwiczeń z przedmiotu **Pracownia programowania**. Repozytorium dokumentuje naukę języka C: od podstawowych operacji na tablicach i napisach, przez wskaźniki i struktury, po listy, pamięć dynamiczną oraz zadania egzaminacyjne.

## Zawartość

```text
.
├── docs/                 materiały pomocnicze i notatki w Markdown
├── src/
│   ├── lekcje/           materiały uporządkowane według lekcji 1–11
│   └── zestawy_egz.c     zadania egzaminacyjne
├── .vscode/              zadanie budowania aktywnego pliku w VS Code
└── README.md
```

Najważniejsze notatki i przykłady z języka C są dostępne w pliku [docs/notatki-c.md](docs/notatki-c.md).

## Kompilowanie

Wymagany jest kompilator zgodny z C17, np. GCC.

Przykładowy plik źródłowy z katalogu głównego repozytorium:

```bash
gcc -std=c17 -Wall -Wextra -pedantic -c src/lekcje/lekcja-02.c -o build/lekcja-02.o
```

Na Windows (PowerShell):

```powershell
gcc -std=c17 -Wall -Wextra -pedantic -c src\lekcje\lekcja-02.c -o build\lekcja-02.o
```

W VS Code można użyć zadania **C/C++: gcc build active file**. Wynik trafia do `build/`.

Każdy plik `lekcja-XX.c` jest osobnym programem i ma własną funkcję `main`. Przykładowo:

```powershell
gcc -std=c17 -Wall -Wextra -pedantic src\lekcje\lekcja-09.c -o build\lekcja-09.exe
```

Każdy plik zawiera również funkcje `zadanie_main_N` odpowiadające poszczególnym zadaniom. Są zachowane w kodzie, ale nie są wywoływane automatycznie przez `main`.

## Uwagi

To repozytorium ma charakter edukacyjny. Nazwy i rozwiązania odzwierciedlają kolejne etapy nauki, dlatego obok dopracowanych przykładów znajdują się również starsze eksperymenty.
