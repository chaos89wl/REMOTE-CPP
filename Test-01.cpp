#include <iostream>
#include <cstring>

int num_point(const char* word)
{
    /* 각 글자는 다음과 같은 점수를 가집니다:
    # a, e, i, o, u, l, n, s, t, r: 1점
    # d, g: 2점
    # b, c, m, p: 3점
    # f, h, v, w, y: 4점
    # k: 5점
    # j, x: 8점
    # q, z: 10점

    # word는 소문자로 이루어진 단어입니다
    # word의 각 글자에 대한 점수의 합을 반환합니다.
    */
    int points = 0;
    int length = std::strlen(word);
    for(int i = 0; i < length; i++){
        switch(word[i]){
            case 'a': case 'e': case 'i': case 'o': case 'u': case 'l': case 'n': case 's': case 't': case 'r':
                points += 1;
                break;
            case 'd': case 'g':
                points += 2;
                break;
            case 'b': case 'c': case 'm': case 'p':
                points += 3;
                break;
            case 'f': case 'h': case 'v': case 'w': case 'y':
                points += 4;
                break;
            case 'k':
                points += 5;
                break;
            case 'j': case 'x':
                points += 8;
                break;
            case 'q': case 'z':
                points += 10;
                break;
        }
    }
    return points;
}

int main()
{
    const char* word = "quacp";
    int result = num_point(word);
    std::cout << "Points ("<<word<<")" << " : " << result << std::endl;
    return 0;
}