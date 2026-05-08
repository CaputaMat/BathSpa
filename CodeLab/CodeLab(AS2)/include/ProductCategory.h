#pragma once
#include <string>

enum class ProductCategory {
    DRINK,
    SNACK
};

std::string categoryName(ProductCategory product_category);
