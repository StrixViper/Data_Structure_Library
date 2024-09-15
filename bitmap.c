#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;  // Bitmap data
    size_t size;          // Number of bits in the bitmap
} Bitmap;

// Initialize the bitmap with a given size (in bits)
Bitmap* createBitmap(size_t size) {
    Bitmap *bitmap = (Bitmap *)malloc(sizeof(Bitmap));
    bitmap->size = size;
    bitmap->data = (unsigned char *)calloc((size + 7) / 8, sizeof(unsigned char));
    return bitmap;
}

// Set a specific bit in the bitmap (1 = true)
void setBit(Bitmap *bitmap, size_t index) {
    if (index >= bitmap->size) return;
    bitmap->data[index / 8] |= (1 << (index % 8));
}

// Clear a specific bit in the bitmap (0 = false)
void clearBit(Bitmap *bitmap, size_t index) {
    if (index >= bitmap->size) return;
    bitmap->data[index / 8] &= ~(1 << (index % 8));
}

// Check if a specific bit is set
int checkBit(const Bitmap *bitmap, size_t index) {
    if (index >= bitmap->size) return 0;
    return (bitmap->data[index / 8] & (1 << (index % 8))) != 0;
}

// Free bitmap resources
void freeBitmap(Bitmap *bitmap) {
    free(bitmap->data);
    free(bitmap);
}

// Example usage
int main() {
    size_t n = 16;
    Bitmap *bitmap = createBitmap(n);
    
    setBit(bitmap, 3);
    setBit(bitmap, 7);
    
    printf("Bit 3: %d\n", checkBit(bitmap, 3));  // Output: 1
    printf("Bit 7: %d\n", checkBit(bitmap, 7));  // Output: 1
    printf("Bit 8: %d\n", checkBit(bitmap, 8));  // Output: 0
    
    clearBit(bitmap, 3);
    printf("Bit 3 after clear: %d\n", checkBit(bitmap, 3));  // Output: 0
    
    freeBitmap(bitmap);
    return 0;
}
