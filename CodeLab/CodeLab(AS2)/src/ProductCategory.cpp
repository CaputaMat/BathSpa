#include "ProductCategory.h"

std::string categoryName(ProductCategory product_category) {
    switch (product_category) {
        case ProductCategory::DRINK:
            return "Drink";
        case ProductCategory::SNACK:
            return "Snack";
    }

    return "Item";
}
