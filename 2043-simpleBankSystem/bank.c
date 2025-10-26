#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  long long *balance;
  int size;
} Bank;

Bank *bankCreate(long long *balance, int balanceSize) {
  Bank *bank = malloc(sizeof(Bank));
  bank->balance = balance;
  bank->size = balanceSize;
  return bank;
}

bool validateAccount(Bank *obj, int account) {
  return account >= 1 && account <= obj->size;
}

bool sufficientFunds(Bank *obj, int account, long long money) {
  return obj->balance[account - 1] >= money;
}

bool bankTransfer(Bank *obj, int account1, int account2, long long money) {
  if (!validateAccount(obj, account1) || !validateAccount(obj, account2)) {
    return false;
  }
  if (!sufficientFunds(obj, account1, money)) {
    return false;
  }
  obj->balance[account1 - 1] -= money;
  obj->balance[account2 - 1] += money;
  return true;
}

bool bankDeposit(Bank *obj, int account, long long money) {
  if (!validateAccount(obj, account)) {
    return false;
  }
  obj->balance[account - 1] += money;
  return true;
}

bool bankWithdraw(Bank *obj, int account, long long money) {
  if (!validateAccount(obj, account)) {
    return false;
  }
  if (!sufficientFunds(obj, account, money)) {
    return false;
  }
  obj->balance[account - 1] -= money;
  return true;
}

void bankFree(Bank *obj) {}

/**
 * Your Bank struct will be instantiated and called as such:
 * Bank* obj = bankCreate(balance, balanceSize);
 * bool param_1 = bankTransfer(obj, account1, account2, money);

 * bool param_2 = bankDeposit(obj, account, money);

 * bool param_3 = bankWithdraw(obj, account, money);

 * bankFree(obj);
*/
