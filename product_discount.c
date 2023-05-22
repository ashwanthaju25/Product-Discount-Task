#include <stdio.h>
float calculateProductTotal(int quantity, float price)
{
    return quantity * price;
}

float applyQuantityDiscount(int quantity, float price, float discountRate) 
{
    if (quantity > 10) {
        return calculateProductTotal(quantity, price) * discountRate;
    }
    return 0;
}

float calculateDiscount(int totalQuantity, int productQuantity, float productPrice) 
{
    float discount = 0;
    if (totalQuantity > 30 && productQuantity > 15) {
        int quantityAbove15 = productQuantity - 15;
        discount = quantityAbove15 * (productPrice * 0.5);
    }
    return discount;
}

int main() {
    float priceA = 20.0;
    float priceB = 40.0;
    float priceC = 50.0;

    int quantityA, quantityB, quantityC;

    char wrapA, wrapB, wrapC;

    printf("Product A Quantity: ");
    scanf("%d", &quantityA);
    printf("Wrap Product A as Gift? (Y/N): ");
    scanf(" %c", &wrapA);

    printf("Product B Quantity: ");
    scanf("%d", &quantityB);
    printf("Wrap Product B as Gift? (Y/N): ");
    scanf(" %c", &wrapB);

    printf("Product C Quantity: ");
    scanf("%d", &quantityC);
    printf("Wrap Product C as Gift? (Y/N): ");
    scanf(" %c", &wrapC);

    float totalA = calculateProductTotal(quantityA, priceA);
    float totalB = calculateProductTotal(quantityB, priceB);
    float totalC = calculateProductTotal(quantityC, priceC);
    float subtotal = totalA + totalB + totalC;

    float discountA = applyQuantityDiscount(quantityA, priceA, 0.05);
    float discountB = applyQuantityDiscount(quantityB, priceB, 0);
    float discountC = applyQuantityDiscount(quantityC, priceC, 0);
    float totalDiscount = discountA + discountB + discountC;

    int totalQuantity = quantityA + quantityB + quantityC;
    int numPackages = (totalQuantity + 9) / 10; 
    float shippingFee = numPackages * 5;
    int giftWrapFee = (wrapA == 'Y') + (wrapB == 'Y') + (wrapC == 'Y');

    float tieredDiscount = calculateDiscount(totalQuantity, quantityA, priceA);

    if (tieredDiscount > totalDiscount) {
        totalDiscount = tieredDiscount;
    }

    float total = subtotal - totalDiscount + shippingFee + giftWrapFee;

    printf("\nProduct A:\n");
    printf("Quantity: %d\n", quantityA);
    printf("Total Amount: $%.2f\n", totalA);
    printf
