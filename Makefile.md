# Makefile.
## But why?
На перевірках дуже часто зустрічаю горні проекти але з неправильно працюючим Makefile-ом, тому віришів написати цей "how-to". Даний Makefile не претендує на звання "ідеальний", в ньому описані тільки ті правила, які від нас вимагають. Структура директорій також може піддаватися критиці. Якщо у вас буде бажання удосконалити свій Makefile - я залишу  посилання з додатковою інформацією. Якщо ви знаєте як покращити цей туторіал або знайшли помилку - пішить у коментарях або в слак.

## мінімально валідний Makefile
### Структура 
```
16:54 $ ls
Makefile hello.c  hello.h  main.c
```
### main.c 
```C
1       #include "hello.h"
2
3       int             main(void)
4       {
5               hello();
6               return(0);
7       }
```
### hello.c
```C
1       #include <stdio.h>
2
3       void    hello(void)
4       {
5               printf("Hello, World!\n");
6       }

```
### Makefile
```Makefile
1       all: program_name
2
3       program_name: main.o hello.o
4               cc main.o hello.o -o program_name
5
6       main.o: main.c hello.h
7               cc -c main.c
8
9       hello.o: hello.c
10              cc -c hello.c
11
12      clean:
13              rm -f main.o hello.o
14
15      fclean: clean
16              rm -f program_name
17
18      re: fclean all
```

### [Правила](https://www.gnu.org/software/make/manual/make.html#Rule-Introduction)

Кожен мейкфайл складається з "Правил". Правило виглядає так:
```Makefile
ціль … : залежності …
        рецепт
        …
        …
```

ціль:
    1. виконуваний файл
    2. об'єктний файл
    3. команда мейкфайлу
    
залежність:
    1. файли від яких залежить ціль
    2. інші цілі

## [Змінні](https://www.gnu.org/software/make/manual/make.html#Variables-Simplify)
Змінні дають змогу позбудится від дублювання коду та використовувати один мейкфайл для різніх проектів з мінімальними змінами.
## [Неявні правила](https://www.gnu.org/software/make/manual/make.html#Implicit-Rules)
Мейк може сам вирішувати залежності. Для цього потрібно не вказувати рецепт правила або взагалі не писати правило. Мейкфайл зі змінними та неявними правилами:
```Makefile
1       NAME =          program_name
2
3       OBJS =          main.o hello.o
4
5       all: $(NAME)
6
7       $(NAME): $(OBJS)
8               cc $(OBJS) -o $(NAME)
9
10      main.o: main.c hello.h
11
12      hello.o: hello.c
13
14      clean:
15              rm -f $(OBJS)
16
17      fclean: clean
18              rm -f $(NAME)
19
20      re: fclean all
```
без правил для об'єктних файлів:
```Makefile
1       NAME =          program_name
2
3       OBJS =          main.o hello.o
4
5       all: $(NAME)
6
7       $(NAME): $(OBJS)
8               cc $(OBJS) -o $(NAME)
9
10      clean:
11              rm -f $(OBJS)
12
13      fclean: clean
14              rm -f $(NAME)
15
16      re: fclean all
```
## Директорії
Іноді файлів у проекті більше ніж два і виникає потреба їх структурувати. На даний момент після компіляції і лінкування корень проекту виглядає так:
```
18:59 $ ls
Makefile     hello.c      hello.h      hello.o      main.c       main.o       program_name
```
Мені подабається така структура директорій:
```
19:18 $ ls
Makefile inc      lib      obj      src
```
inc: заголовні файли
lib: бібліотеки
obj: об'єктні файли
src: сирцеві коди

Мейкфайл для такої структури:

```Makefile
1       NAME =          program_name
2
3       SRC_DIR =       ./src/
4       OBJ_DIR =       ./obj/
5       INC_DIR =       ./inc/
6       LIB_DIR =       ./lib/
7
8       SRC =           main.c hello.c
9
10      OBJ =           $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
11
12      all: $(NAME)
13
14      $(NAME): $(OBJ)
15              cc $(OBJ) -o $(NAME)
16
17      $(OBJ_DIR)%.o: %.c
18              cc -c $< -o $@ -I $(INC_DIR)
19
20      clean:
21              rm -f $(OBJ_FILES)
22
23      fclean: clean
24              rm -f $(NAME)
25
26      re: fclean all
27
28      vpath %.c $(SRC_DIR)
```

рядки:
* 3-6: змінні з директоріями проекту
* 8: змінна з сирцевими файлами. Тепер не потрібно зберігати список з об'єктними файлами, його можна отримати за допомогою [заміни по шаблону](https://www.gnu.org/software/make/manual/make.html#Substitution-Refs)
* 10: [Додавання префіксу до файлів](https://www.gnu.org/software/make/manual/make.html#File-Name-Functions). За допомогою заміни по шаблону ( `$(SRC:.c=.o)` ) отримуємо набір об'єктих файлів ( `main.o hello.o` ) і додаємо до цих файлів префікс з директорією об'єктних файлів ( `./obj/main.o ./obj/hello.o` )
* 14: наша програма тепер має залежності від об'єктних файлів що знаходяться в директорії `./obj`
* 17: так як об'єктні файли знаходяться не в корені проекту ми повинні явно вказати у цілях для цих файлів директорію у якій вони знаходяться. Синтаксис `%.o: %.c`