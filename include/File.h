#ifndef FILE_H
#define FILE_H

#include "FileSystemElement.h"

class File : public FileSystemElement {
    std::string name;
public:
    // kontruktor
    explicit File(const std::string& name) : name(name) {}

    // Rule of 5:
    // kopiowanie
    File(const File& other) = default;
    File& operator=(const File& other) = default;

    // przenoszenie
    File(File&& other) noexcept = default;
    File& operator=(File&& other) noexcept = default;

    // destruktor
    ~File() override = default;

    // wypisanie struktury
    void print(std::ostream& os, int indent = 0) const override;
};

#endif
