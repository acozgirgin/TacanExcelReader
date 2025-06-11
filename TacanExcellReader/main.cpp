#include <iostream>
#include <xlnt/xlnt.hpp>
#include "DataParser.h"

int main()
{
    std::string file_path;
    std::cout << "Excel dosyasinin ismini giriniz: ";
    std::getline(std::cin, file_path); // Dosya adýný boþluklu bile alsýn diye getline kullanýlýr
    auto parser = Parser::DataParser{ file_path };

    return 0;
}