    #include <stdio.h>

    #define MAX_SIZE 10000 // Maksimum Ukuran Stack

    typedef struct Stack{
        int num[MAX_SIZE];
        int top;
    } Stack;

    void push(Stack *stack, int value) {
        stack->top++;
        stack->num[stack->top] = value;
    }

    int pop(Stack *stack) {
        return stack->num[stack->top--];
    }

    int top(Stack *stack) {
        return stack->num[stack->top];
    }

    // Fungsi untuk menghitung jumlah maksimum elemen yang bisa diambil dari dua tumpukan
    int twoStacks(int maxSum, Stack a, int a_count, Stack b, int b_count){
        int sum = 0, count = 0;
        Stack stackA, stackB;
        a.top = b.top = -1; // Inisialisasi nilai top untuk stack a dan b

        // Mengisi stack A dari input
        for (int i = a_count - 1; i >= 0; i--) {
            push(&stackA, a.num[i]);
        }
        // Mengisi stack B dari input
        for (int i = b_count - 1; i >= 0; i--) {
            push(&stackB, b.num[i]);
        }
        
        // Menentukan panjang tumpukan yang akan diproses
        int length = a_count >= b_count ? b_count : a_count;

        for (int i = 0; i < length; i++) {
            // Jika penambahan eleman stack A masih memenuhi batas maxSum
            if (sum + top(&stackA) <= maxSum) {
                sum += pop(&stackA); // Menambahkan nilai dari stack A
                printf("%d\n", sum);
                count++;
            }

            // Jika penambahan eleman stack B masih memenuhi batas maxSum
            if (sum + top(&stackB) <= maxSum) {
                sum += pop(&stackB); // Menambahkan nilai dari stack B
                printf("%d\n", sum);
                count++;
            }
        }
        return count; //return nilai count dari banyaknya penjumlahan
    }

    int main(){
        Stack a, b;
        int n, m, g, maxSum;

        printf("Masukkan jumlah game: ");
        scanf("%d", &g);

        for (int i = 0; i < g; i++) {
            printf("Masukkan jumlah elemen stack a: ");
            scanf("%d", &n);
            printf("Masukkan jumlah elemen stack b: ");
            scanf("%d", &m);
            printf("Masukkan batas jumlah maksimum: ");
            scanf("%d", &maxSum);

            // Membaca elemen-elemen stack a
            for (int j = 0; j < n; j++) {
                scanf("%d", &a.num[j]);
            }
            // Membaca elemen-elemen stack b
            for (int j = 0; j < m; j++) {
                scanf("%d", &b.num[j]);
            }

            int result = twoStacks(maxSum, a, n, b, m);
            // Memanggil fungsi twoStacks dan mencetak hasilnya
            printf("Hasil game %d: %d\n", i + 1, result);
        }
        
        return 0;
    }