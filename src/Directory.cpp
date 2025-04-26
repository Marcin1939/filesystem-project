#include "Directory.h"

void Directory::add(std::unique_ptr<FileSystemElement> element) {
    elements.push_back(std::move(element));
}

void Directory::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "Dir: " << name << "\n";
    for (const auto& element : elements) {
        element->print(os, indent + 2);
    }
}

std::ostream& operator<<(std::ostream& os, const Directory& dir){
    dir.print(os);
    return os;
}

std::unique_ptr<Directory> Directory::fromFilesystem(const std::filesystem::path& path) {
    auto dir = std::make_unique<Directory>(path.filename().string());

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_directory()) {
            dir->add(Directory::fromFilesystem(entry.path()));
        } else if (entry.is_regular_file()) {
            dir->add(std::make_unique<File>(entry.path().filename().string()));
        }
    }

    return dir;
}