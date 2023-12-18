if g++ -D_GLIBCXX_DEBUG -Wall -fsanitize=undefined -g -DLC_LOCAL -std=c++2a main.cpp ; then
    ./a.out
    printf "\n"
    cat output.txt
    printf "\n"
fi