#include <iostream>
#include <xlnt/xlnt.hpp>
#include "DataParser.h"

int main()
{
    std::string file_path;
    std::cout << "Excel dosyasinin ismini giriniz: ";
    std::getline(std::cin, file_path); // Dosya ad�n� bo�luklu bile als�n diye getline kullan�l�r
    auto parser = Parser::DataParser{ file_path };

    return 0;
}