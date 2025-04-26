#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "FileSystemElement.h"
#include "File.h"
#include "Directory.h"

// tworzenie przykładowej struktury
void createExampleStructure(Directory& root) {
    root.add(std::make_unique<File>("notes.txt"));
    root.add(std::make_unique<File>("readme.md"));

    auto img = std::make_unique<Directory>("img");
    img->add(std::make_unique<File>("logo.png"));
    img->add(std::make_unique<File>("screenshot.jpg"));
    root.add(std::move(img));

    auto docs = std::make_unique<Directory>("docs");
    docs->add(std::make_unique<File>("manual.pdf"));
    root.add(std::move(docs));
}

int main() {
    // z stworzonej struktury
    Directory root("data");

    createExampleStructure(root);

    // root.print(std::cout);
    std::cout << "Przykład 1: \n" << root;


    // z realnego katalogu
    std::string path = "../data";
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
        auto dir = Directory::fromFilesystem(path);

        std::cout << "\nPrzykład 2: \n" << *dir;
    } else {
        std::cout << "Katalog '" << path << "' nie istnieje.\n";
    }
    

    return 0;
}
