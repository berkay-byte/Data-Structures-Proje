#include <stdio.h>

/**
 * n: Disk sayisi
 * from_rod: Baslangic kulesi (A)
 * to_rod: Hedef kule (C)
 * aux_rod: Yardimci kule (B)
 */
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Temel durum: Sadece 1 disk varsa direkt tasi
    if (n == 1) {
        printf("Disk 1'i %c kulesinden %c kulesine tasi\n", from_rod, to_rod);
        return;
    }

    // 1. Adim: n-1 diski A'dan B'ye tasi (C'yi yardimci kullanarak)
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // 2. Adim: Kalan en buyuk diski A'dan C'ye tasi
    printf("Disk %d'yi %c kulesinden %c kulesine tasi\n", n, from_rod, to_rod);

    // 3. Adim: n-1 diski B'den C'ye tasi (A'yi yardimci kullanarak)
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3; // Disk sayisi (Istersen kullanicidan alabilirsin)
    printf("%d disk icin hamleler:\n", n);
    
    towerOfHanoi(n, 'A', 'C', 'B'); 
    
    return 0;
}