#ifndef FILESYSTEMELEMENT_H
#define FILESYSTEMELEMENT_H

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class FileSystemElement {
public:
    virtual ~FileSystemElement() = default;

    virtual void print(std::ostream& os, int indent = 0) const = 0;
};

#endif
