## екущая ответственность Transaction

`Transaction` отвечает за перевод средств между двумя агентами.

Она хранит:

- transactionId;
- sender;
- recipient;
- senderId;
- recipientId;
- amount;
- status;
- message.

## TransactionStatus

Статусы транзакции описываются через `enum class TransactionStatus`.

Текущие статусы:

- `Pending` — транзакция создана, но ещё не обработана;
- `Completed` — транзакция успешно выполнена;
- `InvalidParticipants` — отправитель или получатель отсутствует;
- `InsufficientFunds` — у отправителя недостаточно средств;
- `InvalidAmount` — сумма перевода некорректна.

## TransactionResult

`TransactionResult` — это объект результата выполнения операции.

Он нужен, чтобы `ProcessTransaction()` возвращал наружу структурированную информацию:

- id транзакции;
- id отправителя;
- id получателя;
- сумму;
- статус;
- сообщение.

## Idempotency

`Transaction` защищена от повторной обработки.

Если `ProcessTransaction()` вызывается повторно для уже обработанной транзакции, деньги не переводятся второй раз.

Это первый простой шаг к idempotency.