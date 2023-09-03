#include "Hashing.h"

void Hashing::makeHash() {
    std::ifstream file;
    file.open(filename, std::ios_base::in);

    if (!file.is_open()) {
        throw FileExeption("could not open file " + filename);
    }

    char c;
    int hash = 1;

    while (file.get(c))
        hash += hash*7 + (int)c;

    file.close();
    std::ofstream file_out;
    file_out.open(filename, std::ios_base::app);
    file_out << '#';
    file_out << hash;
    file_out.close();
}

bool Hashing::checkHashMatching() {

    std::ifstream file;
    file.open(filename, std::ios_base::in);

    if (!file.is_open()) {
        throw FileExeption("could not open file" + filename);
    }

    char c;
    int new_hash = 0;
    file.get(c);
    while (c != '#') {
        new_hash += new_hash *7 + (int)c;
        file.get(c);
        if (file.eof() || file.fail()) {
            throw LoadExeption("file " + filename + " was changed!");
        }
    }
    int old_hash;
    file >> old_hash;
    if (old_hash != new_hash) {
        file.close();
        return false;
    }
    file.close();
    return true;
}
