#pragma once
#include <string>

#include "ProductCategory.h"

// Class Product definition
class Product {
public:
    // Class Product constructor
    Product(std::string code, std::string name, double price, ProductCategory category, int stock);

    // Class getter methods definition
    const std::string& code() const { return code_; }

    const std::string& name() const { return name_; }

    double price() const { return price_; }

    ProductCategory category() const { return category_; }

    int stock() const { return stock_; }

    bool inStock() const { return stock_ > 0; }

private:
    // Member Variable declaration
    std::string code_;
    std::string name_;
    double price_;
    ProductCategory category_;
    int stock_;
};
