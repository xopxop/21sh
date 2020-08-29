# Welcome to 21shell 👋
## Creating my own shell program from scratch.
> This project is the second hurdle in the sequence of three of shell projects of Hive(ecole42 Helsinki branch) to enlarge understanding of UNIX-like systems' basis.
Written in C and developed based on bash-like shells pre-exist.

### Overview
![ezgif com-gif-maker](https://user-images.githubusercontent.com/47879168/91644838-dd6c6680-ea7a-11ea-9730-7ac8c6676c06.gif)
![ezgif com-gif-maker (1)](https://user-images.githubusercontent.com/47879168/91644839-e0675700-ea7a-11ea-988c-bc9d5cba9662.gif)
### Dependency
- GCC 4.2.1
- GNU make 3.81
- Xterm terminal emulator

### Install
```sh
make
```


### Getting started
You can run the program with this simple command and use it like your daily shell program.
```sh
./21sh
```

### Run tests
```sh
$> base64 /dev/urandom | head -c 1000 | grep 42 | wc -l | sed -e 's/1/Yes/g' -e 's/0/No/g
```
```sh
mkdir test ; cd test ; ls -a ; ls | cat | wc -c > fifi ; cat fifi
```
```sh
cd /tmp; sort << HEREDOC | cat -e > foo; sed -e 's/s/SIERA/' < foo > bar; cd -; echo "HI?" >> /tmp/bar; cat /tmp/bar
```

### Main features
 ###### Functionalities
 - Redirections `>`,`>>`,`<`,`>&` and `<&`
 - Piping `|`
 - Heredoc `<<`
 - Separator `;`
 - Interpretations of `~` and `$` for env variables
 - Inhibitors `"` and `'`
 - Builtin commands `echo`,`cd`,`setenv`,`unsetenv`, `env`, `exit`
 - External simple commands
 - Command Combination of all of these features
 
 ###### Line editions
 - History navigating with `↑`or`↓`
 - Moving cursor on to the left or right word `ctrl`+`←`or`→`
 - Moving cursor on to the upper or lower line `ctrl`+`↑`or`↓`
 - Moving cursor to where the line starts or ends `home`, `end`
 - Cutting a word `ctrl` + `k`
 - Pasting a word `ctrl` + `l`


##### Todo
 -- Command Auto-completion
 -- Pasting command lines from external program
## Author

👤 **dthan**
* LinkedIn: [@Du Than](https://www.linkedin.com/in/duthan/)

👤 **ihwang**

* LinkedIn: [@Intaek Hwang](https://www.linkedin.com/in/intaek-hwang-30161b196/)

