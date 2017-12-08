# Makefile.
## But why?
На перевірках дуже часто зустрічаю гарні проекти але з неправильно працюючим Makefile-ом, тому віришів написати цей "how-to". Даний Makefile не претендує на звання "ідеальний", в ньому описані тільки ті правила, які від нас вимагають. Структура директорій також може піддаватися критиці. Якщо у вас буде бажання удосконалити свій Makefile - я залишу  посилання з додатковою інформацією. Якщо ви знаєте як покращити цей туторіал або знайшли помилку - пішить у коментарях або в слак (`@gtertysh`).

## мінімально валідний Makefile
### Структура 
```
16:54 $ ls
Makefile    hello.c hello.h main.c
```
### `main.c` 
```C
1       #include "hello.h"
2
3       int             main(void)
4       {
5               hello();
6               return(0);
7       }
```
### `hello.c`
```C
1       #include <stdio.h>
2
3       void    hello(void)
4       {
5               printf("Hello, World!\n");
6       }

```
### `Makefile`
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

`ціль`:
    1. Виконуваний файл.
    2. Об'єктний файл.
    3. [Команда мейкфайла](https://www.gnu.org/software/make/manual/make.html#Makefile-Contents).
    
`залежність`:
    1. Файли від яких залежить ціль.
    2. Інші цілі.

## [Змінні](https://www.gnu.org/software/make/manual/make.html#Variables-Simplify)
Змінні дають змогу позбудитись від дублювання коду та використовувати один мейкфайл для різніх проектів з мінімальними змінами.
## [Неявні правила](https://www.gnu.org/software/make/manual/make.html#Implicit-Rules)
Мейк може сам вирішувати залежності. Для цього не потрібно вказувати рецепт правила або взагалі не писати його. Мейкфайл зі змінними та неявними правилами:
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
без цілей для об'єктних файлів:
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
Іноді файлів у проекті більше ніж два і виникає потреба їх структурувати. На даний момент після компіляції і лінкування корінь проекту виглядає наступний чином:
```
18:59 $ ls
Makefile     hello.c      hello.h      hello.o      main.c       main.o       program_name
```
Я надаю перевагу наступній струтурі дирикторій:
```
19:18 $ ls
Makefile inc      lib      obj      src
```
`inc`: заголовні файли
`lib`: бібліотеки
`obj`: об'єктні файли
`src`: сирцеві коди

Мейкфайл для даної структури:

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
* 3-6: Змінні з директоріями проекту.
* 8: Змінна зі сирцевими файлами. Тепер не потрібно зберігати список з об'єктними файлами, його можна отримати за допомогою [заміни по шаблону](https://www.gnu.org/software/make/manual/make.html#Substitution-Refs).
* 10: [Додавання префіксу до файлів](https://www.gnu.org/software/make/manual/make.html#File-Name-Functions). За допомогою заміни по шаблону ( `$(SRC:.c=.o)` ) отримуємо набір об'єктих файлів ( `main.o hello.o` ) і додаємо до цих файлів префікс з директорією об'єктних файлів ( `./obj/main.o ./obj/hello.o` ). Цей набір буде використано для цілей, які будуть компілювати ці самі файли.
* 14: Бінарний файл тепер має залежності від об'єктних файлів що знаходяться в директорії `./obj`.
* 17: Так як об'єктні файли не знаходяться в корені проекту ми повинні явно вказати у цілях директорію у якій вони знаходяться. Синтаксис `%.o: %.c` - це [шаблонні цілі](https://www.gnu.org/software/make/manual/make.html#Pattern-Rules).
* 18: `$<` та `$@` - це [автоматичні змінні](https://www.gnu.org/software/make/manual/make.html#Automatic-Variables). Якщо взяти за ціль файл `./obj/main.o` і залежність `main.c` то після підстановки значень замість змінних отримаємо:
```Makefile
./obj/main.o: main.c
        gcc -c main.c -o ./obj/main.o -I ./inc/
```
* 28: [Вказівка для пошуку певних типів файлів у вказаних директоріях](https://www.gnu.org/software/make/manual/make.html#Selective-Search). У даному випадку make буде шукати файли з розширенням `.c` у директорії `./src/`.

## Бібліотеки

Якщо ми захочемо виокристовувати функії з нестандартної бібліотеки (наприклад, `libft.a`) нам потрібно переробити наш проект та мейкфайл.

`main.c` не змінюється:
### `main.c`
```C
1       #include "hello.h"
2
3       int             main(void)
4       {
5               hello();
6               return(0);
7       }
```
### `hello.c`
```C
1       #include <libft.h>
2
3       void    hello(void)
4       {
5               ft_putstr("Hello, World!\n");
6       }
```

### `Makefile`
```Makefile
 1      # name of the executable file
 2
 3      NAME :=                 program_name
 4
 5
 6      # project directories
 7
 8      SRC_DIR :=              ./src/
 9      OBJ_DIR :=              ./obj/
10      INC_DIR :=              ./inc/
11      LIB_DIR :=              ./lib/
12
13      # project source files
14
15      SRC :=                  main.c hello.c
16
17
18      # project object files
19
20      OBJ =                   $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
21
22
23      # libraries
24
25      LIBFT =         $(LIBFT_DIR)libft.a
26      LIBFT_DIR :=    $(LIB_DIR)libft/
27      LIBFT_INC :=    $(LIBFT_DIR)includes/
28      LIBFT_FLAGS :=  -lft -L $(LIBFT_DIR)
29
30
31      # compilation flags
32
33      CC_FLAGS :=             -Wall -Wextra -Werror
34
35
36      # linking flags
37
38      LINK_FLAGS :=   $(LIBFT_FLAGS)
39
40
41      # header flags
42
43      HEADER_FLAGS := -I $(INC_DIR)  -I $(LIBFT_INC)
44
45
46      # compiler
47
48      CC :=                   gcc
49
50
51      # rules
52
53      all: $(NAME)
54
55      $(NAME): $(LIBFT) $(OBJ)
56              $(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)
57
58      $(OBJ_DIR)%.o: %.c
59              $(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)
60
61      $(LIBFT):
62              make -C $(LIBFT_DIR)
63
64      clean:
65              rm -f $(OBJ)
66              make clean -C $(LIBFT_DIR)
67
68      fclean: clean
69              rm -f $(NAME)
70              make fclean -C $(LIBFT_DIR)
71
72      re: fclean all
73
74      vpath %.c $(SRC_DIR)
```

рядки:
* 25: Файл статичної бібліотеки libft. Від неї повинен залежати виконуваний файл (рядок 55).
* 26: Директорія, в якій знаходиться файл статичної бібліотеки. Потрібна для флагу компілятора, який вказує де шукати бібліотеки при лінкуванні (рядки 28, 38, 56)
* 27: Директорія з заголовними файлами. Потрібна для компіляції об'єктних файлів, які використовують функції з бібліотки (рядок 43).
* 28: Флаги лінкування з бібліотекою (рядки 38, 56).
* 33: Стандартні флаги компіляції (рядок 59).
* 38: Загальні флаги для лінкування. Якщо в проекті використовується не одна бібліотека то ця змінна буде містити флаги усіх бібліотек (рядок 56).
* 43: Флаги з директоріями усіх заголовних файлів (рядок 59).
* 48: Якщо проект буде компілюватися на різних системах то ця змінна дозволяє легко змінити компілятор проекту.
* 55: Тепер в залежностях виконуваного файла окрім об'єктних файлів є статична бібліотека, для якої є правило (рядок 61), що компілює цю саму бібліотеку.
* 56: Тепер при лінкуванні вказуються усі бібліотеки, які використовуються у проекті. Якщо підставити замість змінних реальні значення:
```bash
gcc ./obj/main.o ./obj/hello.o -lft -L ./lib/libft/ -o program_name
```
* 59: При компілюванні вказуються флаги по нормі та директорії заголовних файлів. Якщо підставити замість змінних реальні значення: 
```bash
gcc -c ./src/hello.c -o obj/hello.o -Wall -Wextra -Werror -I ./inc/  -I ./lib/libft/includes/
```
* 61: Ціль для компіляції бібліотеки. Для цього в рецепті просто вказується мейк на Мейкфайл бібліотеки.
* 66,70: Правила Мейкфайлу бібліотеки.

## [Типи залежностей](https://www.gnu.org/software/make/manual/make.html#Prerequisite-Types)

Якщо зараз зробити комміт проекту то директорія `./obj/` не додасться до комміту, так як гіт відслідковує тільки змінни файлах. Є два варіанти вирішення проблеми:
1. Додати файл [.gitkeep](https://stackoverflow.com/questions/7229885/what-are-the-differences-between-gitignore-and-gitkeep).
2. Створити залежність в якій не враховується час останньої зміни і яка виконується перед усіма іншими.

Я надаю перевагу другому варіанту. Приклад з документації:
```Makefile
 1      # name of the executable file
 2
 3      NAME :=                 program_name
 4
 5
 6      # project directories
 7
 8      SRC_DIR :=              ./src/
 9      OBJ_DIR :=              ./obj/
10      INC_DIR :=              ./inc/
11      LIB_DIR :=              ./lib/
12
13      # project source files
14
15      SRC :=                  main.c hello.c
16
17
18      # project object files
19
20      OBJ =                   $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
21
22
23      # libraries
24
25      LIBFT =         $(LIBFT_DIR)libft.a
26      LIBFT_DIR :=    $(LIB_DIR)libft/
27      LIBFT_INC :=    $(LIBFT_DIR)includes/
28      LIBFT_FLAGS :=  -lft -L $(LIBFT_DIR)
29
30
31      # compilation flags
32
33      CC_FLAGS :=             -Wall -Wextra -Werror
34
35
36      # linking flags
37
38      LINK_FLAGS :=   $(LIBFT_FLAGS)
39
40
41      # header flags
42
43      HEADER_FLAGS := -I $(INC_DIR)  -I $(LIBFT_INC)
44
45
46      # compiler
47
48      CC :=                   gcc
49
50
51      # rules
52
53      all: $(NAME)
54
55      $(NAME): $(LIBFT) $(OBJ)
56              $(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)
57
58      $(OBJ): | $(OBJ_DIR)
59
60      $(OBJ_DIR):
61              mkdir $(OBJ_DIR)
62
63      $(OBJ_DIR)%.o: %.c
64              $(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)
65
66      $(LIBFT):
67              make -C $(LIBFT_DIR)
68
69      clean:
70              rm -f $(OBJ)
71              make clean -C $(LIBFT_DIR)
72
73      fclean: clean
74              rm -f $(NAME)
75              rm -rf $(OBJ_DIR)
76              make fclean -C $(LIBFT_DIR)
77
78      re: fclean all
79
80      vpath %.c $(SRC_DIR)
```
58-61: створення директорії `./obj/`
75: видалення директорії `./obj`

## Конклюжн
Корисні посилання:
[офіційна документація](https://www.gnu.org/software/make/manual/make.html)
[7 Things You Should Know About Make](http://www.alexeyshmalko.com/2014/7-things-you-should-know-about-make/)
[An Introduction to Makefiles](http://web.mit.edu/gnu/doc/html/make_2.html)
[A Program for Directing Recompilation](https://www.cl.cam.ac.uk/teaching/1011/UnixTools/make.pdf)
[GCC and Make. Compiling, Linking and Building C/C++ Applications](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)

## Акноледжментс
contributing editor: @khrechen.