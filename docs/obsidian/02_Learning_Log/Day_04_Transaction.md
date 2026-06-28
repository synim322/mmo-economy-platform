
Сегодня добавил Transaction.  
  
Понял, что вызов функции внутри if реально выполняет операцию. В ProcessTransaction сначала вызывается sender->Withdraw(amount). Если списание успешно, функция возвращает true, и только после этого выполняется recipient->Deposit(amount).  
  
Деньги списываются через цепочку:  
Transaction -> Agent::Withdraw -> Wallet::Withdraw.  
  
Деньги начисляются через цепочку:  
Transaction -> Agent::Deposit -> Wallet::Deposit.  
  
Также понял проблему циклических зависимостей: Agent не должен подключать Transaction, потому что Transaction зависит от Agent. Для указателей в Transaction.h можно использовать forward declaration.