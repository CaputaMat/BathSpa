#include "Product.h"

Product::Product(std::string code, std::string name, double price, ProductCategory category, int stock)
    : code_(std::move(code)), name_(std::move(name)), price_(price), category_(category), stock_(stock) {}
