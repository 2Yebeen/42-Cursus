# **Libft**

##### Your very first own library

##### _Summary: This project aims to code a C library regrouping usual functions that you’ll be use for all your next projects. Version: 15_

<br>

# Contents

| Chapter | Contents                                          | page |
| :-----: | :------------------------------------------------ | :--: |
|    1    | [**Introduction**](#Chapter-1)                    |  2   |
|    2    | [**Common Instrunctions**](#Chapter-2)            |  3   |
|    3    | [**Mandatory part**](#Chapter-3)                  |  4   |
|   3.1   | [**Technical Considerations**](#Chapter-3-1)      |  4   |
|   3.2   | [**Part 1 - Libc functions**](#Chapter-3-2)       |  5   |
|   3.3   | [**Part 2 - Additional functions**](#Chapter-3-3) |  6   |
|    4    | [**Bonus part**](#Chapter-4)                      |  10  |

<br>

# **Chapter 1**

## Introduction

<br>

##### _C programming can be very tedious when one doesn’t have access to those highly useful standard functions. This project allows you to re-write those functions, understand them, and learn to use them. This library will help you with all your future C projects. Take the time to expand your `libft` throughout the year. But always, make sure to check which functions are allowed !_

<br>

# **Chapter 2**

## Common Instructions

- ##### _Your project must be written in accordance with the Norm. If you have bonus files/functions, they are included in the norm check and you will receive a 0 if there is a norm error inside._

- ##### _Your functions should not quit unexpectedly (segmentation fault, bus error, double free, etc) apart from undefined behaviors. If this happens, your project will be considered non functional and will receive a 0 during the evaluation._

- ##### _All heap allocated memory space must be properly freed when necessary. No leaks will be tolerated._

- ##### _If the subject requires it, you must submit a Makefile which will compile your source files to the required output with the flags -Wall, -Wextra and -Werror, and your Makefile must not relink._

- ##### _Your Makefile must at least contain the rules $(NAME), all, clean, fclean and re._

- ##### _To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. Bonuses must be in a different file \_bonus.{c/h}. Mandatory and bonus part evaluation is done separately._

- ##### _If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. Your project’s Makefile must compile the library by using its Makefile, then compile the project._

- ##### _We encourage you to create test programs for your project even though this work won’t have to be submitted and won’t be graded. It will give you a chance to easily test your work and your peers’ work. You will find those tests especially useful during your defence. Indeed, during defence, you are free to use your tests and/or the tests of the peer you are evaluating._

- ##### _Submit your work to your assigned git repository. Only the work in the git repository will be graded. If Deepthought is assigned to grade your work, it will be done after your peer-evaluations. If an error happens in any section of your work during Deepthought’s grading, the evaluation will stop._

<br>

# Chapter 3

## Mandatory part

| **Program name**             | libft.a                                                                                        |
| ---------------------------- | ---------------------------------------------------------------------------------------------- |
| **Turn in files**            | `*.c, libft.h, Makefile`                                                                       |
| **Makefile**                 | Yes                                                                                            |
| **External functs. **        | `Detailed below`                                                                               |
| **설명**                     | `Write your own library, containing an extract of important functions for your cursus.`        |

<br>

## 3.1 Technical considerations

- ##### _It is forbidden to declare global variables._

- ##### _If you need subfunctions to write a complex function, you should define these subfunctions as `static` to avoid publishing them with your library. It would be a good habit to do this in your future projects as well._

- ##### _Submit all files in the root of your repository._

- ##### _It is forbidden to submit unused files._

- ##### _Every .c must compile with flags._

- ##### _You must use the command `ar` to create your library, using the command `libtool` is forbidden._

<br>

## 3.2 Part 1 - Libc functions

##### _In this first part, you must re-code a set of the `libc` functions, as defined in their `man`. Your functions will need to present the same prototype and behaviors as the originals. Your functions’ names must be prefixed by "`ft_`". For instance, `strlen`becomes`ft_strlen`.

> ⚠️
>
> ##### Some of the functions’ prototypes you have to re-code use the "restrict" qualifier. This keyword is part of the c99 standard. It is therefore forbidden to include it in your prototypes and to compile it with the flag `-std=c99`.
>

##### _You must re-code the following functions. These function do not need any external functions:_

- `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`
- `strlen`, `memset`, `bzero`, `memcpy`, `memmove`, `strlcpy`, `strlcat`, `strncmp`
- `toupper`, `tolower`, `strchr`, `strrchr`
- `memchr`, `memcmp`, `strnstr`, `atoi`

##### _You must also re-code the following functions, using the function "`malloc`":_

- `calloc`, `strdup`

<br>

## 3.3 Part 2 - Additional functions

##### _In this second part, you must code a set of functions that are either not included in the `libc`, or included in a different form. Some of these functions can be useful to write Part 1’s functions._

<br>

| **Function name**            | ft_substr                                                                                                                                                                                                                                                                                                                                |
| ---------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Prototype**                | `char *ft_substr(char const *s, unsigned int start, size_t len);`                                                                                                                                                                                                                                                                        |
| **Turn in files**            | -                                                                                                                                                                                                                                                                                                                                        |
| **Parameters**               | `#1. 부분 문자열 (substring) 을 생성할 원본 문자열` <br> `#2. 부분 문자열의 맨 처음 인덱스` <br> `#3. 부분 문자열의 최대 길이`                                                                                                                                                                                                           |
| **Return value**             | `부분 문자열. 할당 실패 시, NULL`                                                                                                                                                                                                                                                                                                        |
| **External functs. **        | `malloc`                                                                                                                                                                                                                                                                                                                                 |
| **Description**              | _Allocates (with malloc(3)) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’._ <br> `malloc(3) 을 이용하여 메모리를 할당받은 후, 원본 문자열 's' 로부터 부분 문자열을 생성하여 반환합니다.` <br>`부분 문자열은 인덱스 'start' 부터 시작하며, 최대 길이 'len'을 갖습니다.` |

<br>

| **함수 이름**                | ft_strjoin                                                                                                                                                                                                                                |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `char *ft_strjoin(char const *s1, char const *s2);`                                                                                                                                                                                       |
| **제출할 파일**              | -                                                                                                                                                                                                                                         |
| **매개변수**                 | `#1. 접두 문자열 (prefix string)` <br> `#2. 접미 문자열 (suffix string)`                                                                                                                                                                  |
| **반환값**                   | `새로운 문자열. 할당 실패 시, NULL`                                                                                                                                                                                                       |
| **사용가능한 <br>외부 함수** | `malloc`                                                                                                                                                                                                                                  |
| **설명**                     | _Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’._ <br> `malloc(3) 을 이용하여 메모리를 할당받은 후, 문자열 's1' 과 's2' 를 이어붙인 새로운 문자열을 생성하여 반환합니다.` |

<br>

| **함수 이름**                | ft_strtrim                                                                                                                                                                                                                                                                           |
| ---------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| **프로토타입**               | `char *ft_strtrim(char const *s1, char const *set);`                                                                                                                                                                                                                                 |
| **제출할 파일**              | -                                                                                                                                                                                                                                                                                    |
| **매개변수**                 | `#1. 양 쪽을 잘라낼 원본 문자열` <br> `#2. 제거될 문자들의 집합`                                                                                                                                                                                                                     |
| **반환값**                   | `문자가 제거된 문자열. 할당 실패 시, NULL`                                                                                                                                                                                                                                           |
| **사용가능한 <br>외부 함수** | `malloc`                                                                                                                                                                                                                                                                             |
| **설명**                     | _Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string._ <br> `malloc(3) 을 이용하여 메모리를 할당받은 후, 's1'의 양 쪽 끝에서 'set'에 지정된 문자들이 제거된 문자열 사본을 반환합니다.` |

<br>

| **함수 이름**                | ft_split                                                                                                                                                                                                                                                                                                                                                                  |
| ---------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `char **ft_split(char const *s, char c);`                                                                                                                                                                                                                                                                                                                                 |
| **제출할 파일**              | -                                                                                                                                                                                                                                                                                                                                                                         |
| **매개변수**                 | `#1. 분할할 문자열` <br> `#2. 구분자 (delimiter)`                                                                                                                                                                                                                                                                                                                         |
| **반환값**                   | `split을 통해 분할된 문자열의 배열. 할당 실패 시, NULL`                                                                                                                                                                                                                                                                                                                   |
| **사용가능한 <br>외부 함수** | `malloc, free`                                                                                                                                                                                                                                                                                                                                                            |
| **설명**                     | _Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer._ <br> `malloc(3) 을 이용하여 메모리를 할당받은 후, 구분자 'c' 를 기준으로 문자열 's'를 분할하여 그 결과를 담은 새로운 문자열 배열을 반환합니다. 문자열 배열의 끝은 NULL 포인터로 끝나야 합니다.` |

<br>

| **함수 이름**                | ft_itoa                                                                                                                                                                                                                                                                       |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `char *ft_itoa(int n);`                                                                                                                                                                                                                                                       |
| **제출할 파일**              | -                                                                                                                                                                                                                                                                             |
| **매개변수**                 | `#1. 변환할 정수`                                                                                                                                                                                                                                                             |
| **반환값**                   | `정수를 표현하는 문자열. 할당 실패 시, NULL`                                                                                                                                                                                                                                  |
| **사용가능한 <br>외부 함수** | `malloc`                                                                                                                                                                                                                                                                      |
| **설명**                     | _Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled._ <br> `malloc(3) 을 이용하여 메모리를 할당받은 후, 인자로 받은 정수를 나타내는 문자열을 반환합니다. 음수 또한 무조건 처리되어야 합니다.` |

<br>

| **함수 이름**                | ft_strmapi                                                                                                                                                                                                                                                                                                                                                                                                       |
| ---------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));`                                                                                                                                                                                                                                                                                                                                                |
| **제출할 파일**              | -                                                                                                                                                                                                                                                                                                                                                                                                                |
| **매개변수**                 | `#1. 함수를 적용할 문자열` <br> `#2. 문자열의 각 문자에 적용할 함수`                                                                                                                                                                                                                                                                                                                                             |
| **반환값**                   | `원본 문자열에서 함수 'f'를 성공적으로 적용하여 생성된 결과 문자열. 할당 실패 시, NULL`                                                                                                                                                                                                                                                                                                                          |
| **사용가능한 <br>외부 함수** | `malloc`                                                                                                                                                                                                                                                                                                                                                                                                         |
| **설명**                     | _Applies the function ’f’ to each character of the string ’s’ , and passing its index as first argument to create a new string (with malloc(3)) resulting from successive applications of ’f’._ <br> `문자열 's' 의 각 문자를 순회하며 함수 'f'를 적용하고, 해당 문자의 인덱스를 함수 'f'의 첫 번째 인자로 사용합니다. 각 문자에 함수가 적용된 새로운 문자열을 생성합니다 (malloc(3) 을 이용하여 메모리를 할당)` |

<br>

| **함수 이름**                | ft_striteri                                                                                                                                                                                                                                                                                                                                                                                                    |
| ---------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `void ft_striteri(char *s, void (*f)(unsigned int, char*));`                                                                                                                                                                                                                                                                                                                                                   |
| **제출할 파일**              | -                                                                                                                                                                                                                                                                                                                                                                                                              |
| **매개변수**                 | `#1. 함수를 적용할 문자열` <br> `#2. 문자열의 각 문자에 적용할 함수`                                                                                                                                                                                                                                                                                                                                           |
| **반환값**                   | `없음`                                                                                                                                                                                                                                                                                                                                                                                                         |
| **사용가능한 <br>외부 함수** | `없음`                                                                                                                                                                                                                                                                                                                                                                                                         |
| **설명**                     | _Applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary_ <br> `문자열 's' 의 각 문자를 순회하며 함수 'f'를 적용하고, 해당 문자의 인덱스를 함수 'f'의 첫 번째 인자로 사용합니다. 또한 각 문자의 주소값이 'f' 함수의 두 번째 인자로 사용되며, 경우에 따라 수정될 수 있습니다.` |

<br>

| **함수 이름**                | ft_putchar_fd                                                                                                  |
| ---------------------------- | -------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `void ft_putchar_fd(char c, int fd);`                                                                          |
| **제출할 파일**              | -                                                                                                              |
| **매개변수**                 | `#1. 출력할 문자` <br> `#2. 값이 쓰여질 파일 식별자 (file descriptor)`                                         |
| **반환값**                   | `없음`                                                                                                         |
| **사용가능한 <br>외부 함수** | `write`                                                                                                        |
| **설명**                     | _Outputs the character ’c’ to the given file descriptor._ <br> `제공받은 파일 식별자에 문자 'c'를 출력합니다.` |

<br>

| **함수 이름**                | ft_putstr_fd                                                                                                  |
| ---------------------------- | ------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `void ft_putstr_fd(char *s, int fd);`                                                                         |
| **제출할 파일**              | -                                                                                                             |
| **매개변수**                 | `#1. 출력할 문자열` <br> `#2. 값이 쓰여질 파일 식별자 (file descriptor)`                                      |
| **반환값**                   | `없음`                                                                                                        |
| **사용가능한 <br>외부 함수** | `write`                                                                                                       |
| **설명**                     | _Outputs the string ’s’ to the given file descriptor._ <br> `제공받은 파일 식별자에 문자열 's'를 출력합니다.` |

<br>

| **함수 이름**                | ft_putendl_fd                                                                                                                                         |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `void ft_putendl_fd(char *s, int fd);`                                                                                                                |
| **제출할 파일**              | -                                                                                                                                                     |
| **매개변수**                 | `#1. 출력할 문자열` <br> `#2. 값이 쓰여질 파일 식별자 (file descriptor)`                                                                              |
| **반환값**                   | `없음`                                                                                                                                                |
| **사용가능한 <br>외부 함수** | `write`                                                                                                                                               |
| **설명**                     | _Outputs the string ’s’ to the given file descriptor, followed by a newline._ <br> `제공받은 파일 식별자에 문자열 's'를 출력하고, 개행을 출력합니다.` |

<br>

| **함수 이름**                | ft_putnbr_fd                                                                                                 |
| ---------------------------- | ------------------------------------------------------------------------------------------------------------ |
| **프로토타입**               | `void ft_putnbr_fd(int n, int fd);`                                                                          |
| **제출할 파일**              | -                                                                                                            |
| **매개변수**                 | `#1. 출력할 정수` <br> `#2. 값이 쓰여질 파일 식별자 (file descriptor)`                                       |
| **반환값**                   | `없음`                                                                                                       |
| **사용가능한 <br>외부 함수** | `write`                                                                                                      |
| **설명**                     | _Outputs the integer ’n’ to the given file descriptor._ <br> `제공받은 파일 식별자에 정수 'n'를 출력합니다.` |

<br>

# Chapter 4

## Bonus part

##### _If you completed the mandatory part, you’ll enjoy taking it further. You can see this last section as Bonus Points._

##### _Having functions to manipulate memory and strings is very useful, but you’ll soon discover that having functions to manipulate lists is even more useful._

##### _`make bonus` will add the bonus functions to the `libft.a` library._

##### _You’ll use the following structure to represent the elements of your list. This structure must be added to your `libft.h` file._

```c
typedef struct s_list
{
    void          *content;
    struct s_list *next;
}              t_list;
```

##### _Here is a description of the fields of the t_list struct:_

- ##### _`content` : The data contained in the element. The `void *` allows to store any kind of data._

- ##### _`next` : The next element’s address or `NULL` if it’s the last element._

##### _The following functions will allow you to easily use your lists._

<br>

| **함수 이름**                | ft_lstnew                                                                                                                                                                                                                                                                                                                                                                                 |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `t_list *ft_lstnew(void *content);`                                                                                                                                                                                                                                                                                                                                                       |
| **제출할 파일**              | -                                                                                                                                                                                                                                                                                                                                                                                         |
| **매개변수**                 | `#1. 새로운 요소에 들어갈 content`                                                                                                                                                                                                                                                                                                                                                        |
| **반환값**                   | `새로운 요소 (element)`                                                                                                                                                                                                                                                                                                                                                                   |
| **사용가능한 <br>외부 함수** | `malloc`                                                                                                                                                                                                                                                                                                                                                                                  |
| **설명**                     | _Allocates (with malloc(3)) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL._ <br> `malloc(3) 을 통해 메모리를 할당하고 새로운 요소를 반환합니다. 요소 내의 변수 'content' 는 인자로 받아온 'content' 로 초기화되어야 합니다. 요소 내의 변수 'next'는 NULL로 초기화되어야 합니다.` |

<br>

| **함수 이름**                | ft_lstadd_front                                                                                         |
| ---------------------------- | ------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `void ft_lstadd_front(t_list **lst, t_list *new);`                                                      |
| **제출할 파일**              | -                                                                                                       |
| **매개변수**                 | `#1. 리스트의 맨 앞에 위치한 요소`<br>`#2. 리스트에 추가할 요소`                                        |
| **반환값**                   | `없음`                                                                                                  |
| **사용가능한 <br>외부 함수** | `없음`                                                                                                  |
| **설명**                     | _Adds the element ’new’ at the beginning of the list._ <br> `요소 'new'를 리스트의 맨 앞에 추가합니다.` |

<br>

| **함수 이름**                | ft_lstsize                                                                              |
| ---------------------------- | --------------------------------------------------------------------------------------- |
| **프로토타입**               | `int ft_lstsize(t_list *lst);`                                                          |
| **제출할 파일**              | -                                                                                       |
| **매개변수**                 | `#1. 리스트의 맨 앞에 위치한 요소`                                                      |
| **반환값**                   | `리스트의 길이`                                                                         |
| **사용가능한 <br>외부 함수** | `없음`                                                                                  |
| **설명**                     | _Counts the number of elements in a list._ <br> `리스트에 포함된 요소의 개수를 셉니다.` |

<br>

| **함수 이름**                | ft_lstlast                                                                                    |
| ---------------------------- | --------------------------------------------------------------------------------------------- |
| **프로토타입**               | `t_list *ft_lstlast(t_list *lst);`                                                            |
| **제출할 파일**              | -                                                                                             |
| **매개변수**                 | `#1. 리스트의 맨 앞에 위치한 요소`                                                            |
| **반환값**                   | `리스트의 맨 마지막 요소`                                                                     |
| **사용가능한 <br>외부 함수** | `없음`                                                                                        |
| **설명**                     | _Returns the last element of the list._ <br> `리스트의 맨 마지막에 위치한 요소를 반환합니다.` |

<br>

| **함수 이름**                | ft_lstadd_back                                                                                    |
| ---------------------------- | ------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `void ft_lstadd_back(t_list **lst, t_list *new);`                                                 |
| **제출할 파일**              | -                                                                                                 |
| **매개변수**                 | `#1. 리스트의 맨 앞에 위치한 요소의 포인터`<br>`#2. 리스트의 맨 끝에 추가할 요소`                 |
| **반환값**                   | `없음`                                                                                            |
| **사용가능한 <br>외부 함수** | `없음`                                                                                            |
| **설명**                     | _Adds the element ’new’ at the end of the list._ <br> `요소 'new'를 리스트의 맨 뒤에 추가합니다.` |

<br>

| **함수 이름**                | ft_lstdelone                                                                                                                                                                                                                                                                                                                                                      |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `void ft_lstdelone(t_list *lst, void (*del)(void *));`                                                                                                                                                                                                                                                                                                            |
| **제출할 파일**              | -                                                                                                                                                                                                                                                                                                                                                                 |
| **매개변수**                 | `#1. 삭제할 요소`<br>`#2. 요소의 content 삭제에 사용되는 함수 포인터`                                                                                                                                                                                                                                                                                             |
| **반환값**                   | `없음`                                                                                                                                                                                                                                                                                                                                                            |
| **사용가능한 <br>외부 함수** | `free`                                                                                                                                                                                                                                                                                                                                                            |
| **설명**                     | _Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element. The memory of ’next’ must not be freed._ <br> `첫 번째 인자값으로 받은 요소의 content를 두 번째 인자로 받은 함수 포인터를 이용해 해제하고, 요소 자체의 메모리를 해제합니다. next 포인터는 해제하면 안 됩니다.` |

<br>

| **함수 이름**                | ft_lstclear                                                                                                                                                                                                                                                                                                                                                 |
| ---------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `void ft_lstclear(t_list **lst, void (*del)(void *));`                                                                                                                                                                                                                                                                                                      |
| **제출할 파일**              | -                                                                                                                                                                                                                                                                                                                                                           |
| **매개변수**                 | `#1. 삭제할 요소의 포인터`<br>`#2. 요소의 content 삭제에 사용되는 함수 포인터`                                                                                                                                                                                                                                                                              |
| **반환값**                   | `없음`                                                                                                                                                                                                                                                                                                                                                      |
| **사용가능한 <br>외부 함수** | `free`                                                                                                                                                                                                                                                                                                                                                      |
| **설명**                     | _Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3). Finally, the pointer to the list must be set to NULL._ <br> `함수 'del' 과 free(3) 을 이용하여 인자값으로 받은 요소와 그 뒤에 따라오는 리스트의 모든 요소들을 삭제하고 해제합니다. 마지막으로, 리스트의 포인터는 NULL로 설정되어야 합니다.` |

<br>

| **함수 이름**                | ft_lstiter                                                                                                                                                                                          |
| ---------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `void ft_lstiter(t_list *lst, void (*f)(void *));`                                                                                                                                                  |
| **제출할 파일**              | -                                                                                                                                                                                                   |
| **매개변수**                 | `#1. 리스트상의 요소`<br>`#2. 리스트 내에서 반복 적용될 함수 포인터`                                                                                                                                |
| **반환값**                   | `없음`                                                                                                                                                                                              |
| **사용가능한 <br>외부 함수** | `없음`                                                                                                                                                                                              |
| **설명**                     | _Iterates the list ’lst’ and applies the function ’f’ to the content of each element._ <br> `리스트 'lst' 를 순회하며, 리스트에 포함된 모든 요소들의 content에 함수 'f'를 반복적으로 적용시킵니다.` |

<br>

| **함수 이름**                | ft_lstmap                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| ---------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **프로토타입**               | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`                                                                                                                                                                                                                                                                                                                                                                                                                          |
| **제출할 파일**              | -                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| **매개변수**                 | `#1. 리스트상의 요소`<br>`#2. 리스트 내에서 반복 적용될 함수 포인터`<br>`#3. 필요할 경우, 요소의 content를 삭제하는 데에 사용되는 함수`                                                                                                                                                                                                                                                                                                                                                             |
| **반환값**                   | `새로운 리스트. 할당 실패 시, NULL`                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| **사용가능한 <br>외부 함수** | `malloc, free`                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| **설명**                     | _Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed._ <br> `리스트 'lst'의 요소들을 순회하며 각 요소의 content에 함수 'f'를 연속적으로 적용시킵니다. 또한 함수 'f'를 적용시킨 결과물들을 content로 담은 새로운 리스트를 생성합니다. 'del' 함수들은 필요 시 각 요소의 content를 삭제하는 데 사용됩니다.` |
