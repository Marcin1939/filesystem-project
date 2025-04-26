# Filesystem Tree Project
Projekt w C++ umożliwiający reprezentację struktury katalogów i plików w formie drzewa.

## Funkcjonalności
- Reprezentacja plików i katalogów poprzez klasy.
- Wypisywanie struktury katalogów z zachowaniem wcięć.
- Automatyczne wczytywanie struktury z systemu plików przy użyciu `std::filesystem`.

## Struktura projektu
- `FileSystemElement.h` — klasa bazowa.
- `File.h / File.cpp` — reprezentacja pliku.
- `Directory.h / Directory.cpp` — reprezentacja katalogu.
- `Main.cpp` — przykład użycia.

## Wymagania
- C++17 lub wyższy
- CMake 3.1+ (jeśli budujesz przez CMake)

## Kompilacja i uruchomienie
```bash
mkdir build
cd build
cmake ..
make
./project
