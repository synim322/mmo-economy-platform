\# Branch Strategy



\## Основные ветки



\### main



`main` — стабильная ветка проекта.



В неё попадает только код, который собирается и считается рабочим.



\### dev



`dev` — основная ветка разработки.



В неё сливаются готовые feature-ветки после проверки.



\### feature/\*



`feature/\*` — ветки под отдельные задачи.



Примеры:



\- `feature/wallet-agent`

\- `feature/transaction`

\- `feature/market-order`

\- `feature/cmake-tests`

\- `feature/http-api`



\## Текущая рабочая ветка



Сейчас я работаю в ветке:



`feature/wallet-agent`



Цель этой ветки — довести до нормального состояния базовую доменную модель `Wallet + Agent`.



\## Правило работы



1\. Не работаю напрямую в `main`.

2\. Новые изменения делаю в `feature/\*`.

3\. После проверки сливаю feature-ветку в `dev`.

4\. После завершения стабильного этапа сливаю `dev` в `main`.



\## Хорошие commit messages



Хорошо:



\- `Add Wallet domain model`

\- `Add Agent ownership of Wallet`

\- `Document Git branch strategy`

\- `Refactor Wallet withdraw result`



Плохо:



\- `fix`

\- `update`

\- `changes`

\- `new code`

