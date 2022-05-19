# Network-OS
Оглавление:
+ [Lec2_3](#Lecture2_3)
   + [Program1](#Program1)
   + [Program2](#Program2)
   + [Program3](#Program3)
+ [Lec4](#Lecture4)
   + [Program4](#Program4)
   + [Program5](#Program5)
   + [Program6](#Program6)

Операционные системы, подходящие для установки и запуска программ:
- GNU/Linux.
- Mac OS.
___
## <a name="Lecture2_3">Лекции 2-3</a>
#### <a name="Program1">Program1</a>  
Пример программы динамического выделения памяти для массива.

Программа запрашивает длину массива, после чего выделяется память с помощью функции malloc. При выделении памяти возвращается указатель. Если память не выделилась, то указатель будет равен NULL. Если массив инициализирован, то выделенная память осовобождается.  

Тестирование 1 
```
Enter length of array: 1  
All fine 
```
Тестирование 2 
```
Enter length of array: -10  
Error: can't allocate memory 
```
___ 
#### <a name="Program2">Program2</a>  
Пример программы для чтения данных из файла.  

C помощью функции calloc выделяем память для массива char. Затем создаем дескриптор и открываем файл для чтения, если файла не будет, то он создастся. Выводим значение дескриптора файла. После читаем из файла 10 байт и записываем в переменную `sz` количество байт, которое удалось прочитать. Далее обязательно записываем в конец массива, в который записывали прочитанную информацию. В конце файл закрывается.  

Тестирование 
```
fd = 3  
called read( 3, c, 10). returned that 0 bytes were read.  
closed the fd.  
```
___
#### <a name="Program3">Program3</a>  
Пример программы системного вызова fork().  

После системныного вызова fork() программа делится на двое и в результате вызова функции появляется один ребенок. С помощью оператора switch-case определяем, каким является процесс - ошибка `(case -1:)` или ребенок `(case 0:)`, или родитель `(default:)`. Как правило, процесс потомка всегда больше, чем у родителя. Это можно определить с помощью функции `getpid()`.

Тестирование 
```
my pid = 22781, returned pid = 22782
my pid = 22782, returned pid = 0
```
___
## <a name="Lecture4">Лекция 4</a>
#### <a name="Program4">Program4</a>  
Сигналы. Пример работы программы.

В начале работы программы срабатывает системный вызов `signal()` и привязывает сигнал SIGUSR1 к одному из обработчиков `handler1`. После чего выполнятеся проверка на то, что мы ребенок. Если мы им оказываеся, то переопределяем обработчик `handler1` на `handler2`. Из ребенка используется системный вызов `kill()` и отправляется сигнал родителю. `handler1` и `handler2` - обрабатывающие функции, принимающие на вход наш сигнал с целочисленным типом данных.

Тестирование  
```
counter = 1  
counter = 3  
counter = 5  
```
___ 
#### <a name="Program5">Program5</a>  
Неименованные каналы. Пример работы программы.

Для работы с неименованными каналами используются два дескриптора. Системный вызов `pipe` записывает два дескриптора с обработкой ошибок. После для получения дочернего процесса используется системный вызов `fork()`, и обрабатываем ошибки. Если `cpid` = 0, то процесс - потомок. В реузльате один дескриптор используется для чтения, а второй дескриптор - для записи. То есть сообщение передается между процессами с помощью каналов.

Тестирование 
```
./prog2.out unnamed
unnamed
```
___
#### <a name="Program6">Program6</a>  
Именованные каналы. Пример работы программы.

Создаём дескриптор канала и именованный канал с правами доступа для всех. После запускается цикл прослушивания канала. Когда на какнал приходит сообщение, выводится само сообщение и количество символов, включая 0 конца строки.

Тестирование 
```
mypipe is created  
$ echo Eureka! > mypipe  
mypipe is opened  
Incomming message (8): Eureka! 
  
read error: Success  
```
___
