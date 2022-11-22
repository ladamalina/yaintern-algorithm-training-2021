#include <iostream>
#include <unordered_map>

int main() {
  std::unordered_map<std::string, int64_t> accounts;
  std::string cmd;
  while (std::cin >> cmd) {
    if (cmd[0] == 'D') {
      /*
       * DEPOSIT name sum - зачислить сумму sum на счет клиента name.
       * Если у клиента нет счета, то счет создается.
       */
      std::string client;
      int64_t amount = 0;
      std::cin >> client >> amount;

      accounts[client] += amount;

    } else if (cmd[0] == 'W') {
      /*
       * WITHDRAW name sum - снять сумму sum со счета клиента name.
       * Если у клиента нет счета, то счет создается.
       */
      std::string client;
      int64_t amount = 0;
      std::cin >> client >> amount;

      accounts[client] -= amount;

    } else if (cmd[0] == 'B') {
      /*
       * BALANCE name - узнать остаток средств на счету клиента name.
       */
      std::string client;
      std::cin >> client;

      std::cout << (accounts.count(client) > 0 ? std::to_string(accounts[client]) : "ERROR") << '\n';

    } else if (cmd[0] == 'T') {
      /*
       * TRANSFER name1 name2 sum - перевести сумму sum со счета клиента name1 на счет клиента name2.
       * Если у какого-либо клиента нет счета, то ему создается счет.
       */
      std::string client_from, client_to;
      int64_t amount = 0;
      std::cin >> client_from >> client_to >> amount;

      accounts[client_from] -= amount;
      accounts[client_to] += amount;

    } else if (cmd[0] == 'I') {
      /*
       * INCOME p - начислить всем клиентам, у которых открыты счета, p% от суммы счета.
       * Проценты начисляются только клиентам с положительным остатком на счету, если у клиента остаток отрицательный,
       * то его счет не меняется. После начисления процентов сумма на счету остается целой,
       * то есть начисляется только целое число денежных единиц. Дробная часть начисленных процентов отбрасывается.
       */
      int percent = 0;
      std::cin >> percent;

      for (auto& [client, balance] : accounts) {
        balance += balance <= 0 ? 0 : static_cast<int64_t>(static_cast<double>(balance) * percent / 100);
      }
    }
  }

  return 0;
}
