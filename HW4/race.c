#include <stdio.h>
#include <pthread.h>

#define LOOPS 100000000
int account_balance = 1000;

void *deposit(void *arg) {
    int amount = *(int *)arg;
    for (int i = 0; i < LOOPS; i++) {
        account_balance += amount;
    }
    return NULL;
}

void *withdraw(void *arg) {
    int amount = *(int *)arg;
    for (int i = 0; i < LOOPS; i++) {
        account_balance -= amount;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    int deposit_amount = 100;
    int withdraw_amount = 50;

    pthread_create(&thread1, NULL, deposit, (void *)&deposit_amount);
    pthread_create(&thread2, NULL, withdraw, (void *)&withdraw_amount);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final account balance: %d\n", account_balance);

    return 0;
}
