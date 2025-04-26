#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "FileSystemElement.h"
#include "File.h"
#include <filesystem>

class Directory : public FileSystemElement {
    std::string name;
    std::vector<std::unique_ptr<FileSystemElement>> elements;
public:
    // konstruktor
    explicit Directory(const std::string& name) : name(name) {}

    // Jawne rule of 5:
    // kopiowanie
    Directory(const Directory&) = delete;
    Directory& operator=(const Directory&) = delete;

    // przenoszenie
    Directory(Directory&&) = default;
    Directory& operator=(Directory&&) = default;

    // destruktor
    ~Directory() override = default;

    // dodawanie elementów do katalogu
    void add(std::unique_ptr<FileSystemElement> element);

    // operator wypisania
    friend std::ostream& operator<<(std::ostream& os, const Directory& dir);

    // wypisanie struktury
    void print(std::ostream& os, int indent = 0) const override;

    // wczytanie struktury ze ścieżki
    static std::unique_ptr<Directory> fromFilesystem(const std::filesystem::path& path);
};

#endif
