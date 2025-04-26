#include "File.h"

void File::print(std::ostream& os, int indent) const {
    os << std::string(indent, ' ') << "File: " << name << "\n";
}