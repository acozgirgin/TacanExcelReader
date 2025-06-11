#include <iostream>
#include <xlnt/xlnt.hpp>
#include "DataParser.h"

int main()
{
    std::string file_name;
    std::cout << "Excel dosyasinin ismini giriniz: ";
    std::getline(std::cin, file_name); // Dosya adýný boþluklu bile alsýn diye getline kullanýlýr
    auto parser = Parser::DataParser{ file_name };

    return 0;
}