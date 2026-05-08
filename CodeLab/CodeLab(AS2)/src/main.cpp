#include <iomanip>
#include <iostream>

#include "Product.h"

int main() {
    std::cout << "Loading vending machine...\n";

    Product coffe("[A1]", "Coffe", 3.10, ProductCategory::DRINK, 10);
    std::cout << std::fixed << std::setprecision(2) << coffe.code() << " "
              << coffe.name() << " | £" << coffe.price() << " | " << " x"
              << coffe.stock() << " [" << categoryName(coffe.category()) << "]";

    return 0;
}
