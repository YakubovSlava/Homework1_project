### Программа парсинга JSON
Программа основана на функции parse_json, которая совместно с 
функцией parse_array реализуют посимвольный парсинг JSON-строки.
Основная задача - реализация разбора JSON, каждая Node которого может быть:
- Словарем: name (string) <-> Node
- Массивом [Node]
- Числом
- Строкой
  Нужно сделать метод установления типа Node, а также вывода на экран (т.е. когда рекурсивно распечатывается Node). Пробелы и новые строки должны игнорироваться.

Краткий обзор функции:
1) json_parser - функция, которая принимает на вход строку, являющуюся JSON, описанным выше.
Основная задача данной функции искать узлы и определять к какому типу они относятся.
Однако данная функция не может правильно обработать вложенные массивы, для их обработки вызывается следующая функция
2) array_parser - Функция, принимающая на вход строку с массивом данных. Задачей функции является разбивать на типы входные узлы.
Как и предыдущая функция, она не предназначена для обработки несоответсвующего типа узлов, а именно словарей.
Они подаются на вход функции json_parser

Обе функции обрабатывают входящую строку таким образом, чтобы удалить из нее проблелы, знаки табуляции и переносы строк.
На входе они принимают строки (std::string), и не имеют выхода (void функции). Обе печатают результат обработки данных

---
### Сбока проекта
Для того, чтобы собрать проект нужно пройти в директрию tmp (cd tmp) и выполнить шаги описанные в readme файле, находящемся в нем

---
### Выходные файлы

После успешной сборки проекта, в папке bin будут находиться:
1) Основная программа main_parser (Для запуска введите ./bin/main_parser из корня проекта)
2) Программа для проведения unit-тестов json_test (Для запуска введите ./bin/json_test из корня проекта)

Также в папке testsuite/integration_test находится python файл с интеграционными тестами integration_test.py,
который может быть запущен после сборки проекта


Немного измененный ридми для ревьювера