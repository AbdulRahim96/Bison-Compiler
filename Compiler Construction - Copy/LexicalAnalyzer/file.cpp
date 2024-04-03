#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>

int dfa = 0;

void start(char c) {
    printf("\nprinting at start: %c\n", c);
    if (c == 'i') {
        dfa = 1;
    } else if (c == 'e') {
        dfa = 7;
    } else if (c == 'm') {
        dfa = 10;
    } else if (c == 'c') {
        dfa = 16;
    } else if (c == 'f') {
        dfa = 20;
    } else if (c == 'p') {
        dfa = 24;
    } else if (c == 'u') {
        dfa = 28;
    } else if (c == 'v') {
        dfa = 32;
    } else if (c == 'r') {
        dfa = 36;
    } else {
        dfa = -1;
    }
}

// if token
void state1(char c) {
    printf("\nprinting at state1: %c\n", c);
    if (c == 'f') {
        dfa = 2;
    } else if (c == 'e') {
        dfa = 7;
    } else {
        dfa = -1;
    }
}

// int token
void state9(char c) {
    printf("\nprinting at state9: %c\n", c);
    if (c == 'n') {
        dfa = 10;
    } else {
        dfa = -1;
    }
}

void state10(char c) {
    if (c == 't') {
        dfa = 2; // 'int' recognized
    } else {
        dfa = -1;
    }
}

// char token
void state18(char c) {
    if (c == 'h') {
        dfa = 19;
    } else {
        dfa = -1;
    }
}

void state19(char c) {
    if (c == 'a') {
        dfa = 20;
    } else {
        dfa = -1;
    }
}

void state20(char c) {
    if (c == 'r') {
        dfa = 2; // 'char' recognized
    } else {
        dfa = -1;
    }
}

// else token
void state7(char c) {
    if (c == 'l') {
        dfa = 8;
    } else {
        dfa = -1;
    }
}

void state8(char c) {
    if (c == 's') {
        dfa = 2; // 'else' recognized
    } else if (c == 'i') {
        dfa = 12;
    } else {
        dfa = -1;
    }
}

// elseif token
void state12(char c) {
    if (c == 'i') {
        dfa = 13;
    } else {
        dfa = -1;
    }
}

void state13(char c) {
    if (c == 'f') {
        dfa = 2; // 'elseif' recognized
    } else {
        dfa = -1;
    }
}

// inout token
void state24(char c) {
    if (c == 'n') {
        dfa = 25;
    } else {
        dfa = -1;
    }
}

void state25(char c) {
    if (c == 'p') {
        dfa = 26;
    } else {
        dfa = -1;
    }
}

void state26(char c) {
    if (c == 'u') {
        dfa = 27;
    } else {
        dfa = -1;
    }
}

void state27(char c) {
    if (c == 't') {
        dfa = 2; // 'input' recognized
    } else {
        dfa = -1;
    }
}

// print token
void state28(char c) {
    if (c == 'r') {
        dfa = 29;
    } else {
        dfa = -1;
    }
}

void state29(char c) {
    if (c == 'i') {
        dfa = 30;
    } else {
        dfa = -1;
    }
}

void state30(char c) {
    if (c == 'n') {
        dfa = 31;
    } else {
        dfa = -1;
    }
}

void state31(char c) {
    if (c == 't') {
        dfa = 2; // 'print' recognized
    } else {
        dfa = -1;
    }
}

// return token
void state32(char c) {
    if (c == 'e') {
        dfa = 33;
    } else {
        dfa = -1;
    }
}

void state33(char c) {
    if (c == 't') {
        dfa = 34;
    } else {
        dfa = -1;
    }
}

void state34(char c) {
    if (c == 'u') {
        dfa = 35;
    } else {
        dfa = -1;
    }
}

void state35(char c) {
    if (c == 'r') {
        dfa = 2; // 'return' recognized
    } else {
        dfa = -1;
    }
}

// void token
void state36(char c) {
    if (c == 'o') {
        dfa = 37;
    } else {
        dfa = -1;
    }
}

void state37(char c) {
    if (c == 'i') {
        dfa = 38;
    } else {
        dfa = -1;
    }
}

void state38(char c) {
    if (c == 'd') {
        dfa = 2; // 'void' recognized
    } else {
        dfa = -1;
    }
}

// for token
void state20_2(char c) {
    if (c == 'o') {
        dfa = 21;
    } else {
        dfa = -1;
    }
}

void state21(char c) {
    if (c == 'r') {
        dfa = 2; // 'for' recognized
    } else {
        dfa = -1;
    }
}

void state2(char c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        dfa = 0; // Reset to the start state
    } else {
        dfa = -1;
    }
}

int isAccepted(char str[]) {
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
        if (dfa == 0)
            start(str[i]);
        else if (dfa == 1 || dfa == 7 || dfa == 10 || dfa == 16 ||
                 dfa == 20 || dfa == 24 || dfa == 28 || dfa == 32 ||
                 dfa == 36)
            state1(str[i]);
        else if (dfa == 9)
            state9(str[i]);
        else if (dfa == 10)
            state10(str[i]);
        else if (dfa == 18)
            state18(str[i]);
        else if (dfa == 19)
            state19(str[i]);
        else if (dfa == 20)
            state20(str[i]);
        else if (dfa == 7)
            state7(str[i]);
        else if (dfa == 8)
            state8(str[i]);
        else if (dfa == 12)
            state12(str[i]);
        else if (dfa == 13)
            state13(str[i]);
        else if (dfa == 24)
            state24(str[i]);
        else if (dfa == 25)
            state25(str[i]);
        else if (dfa == 26)
            state26(str[i]);
        else if (dfa == 27)
            state27(str[i]);
        else if (dfa == 28)
            state28(str[i]);
        else if (dfa == 29)
            state29(str[i]);
        else if (dfa == 30)
            state30(str[i]);
        else if (dfa == 31)
            state31(str[i]);
        else if (dfa == 32)
            state32(str[i]);
        else if (dfa == 33)
            state33(str[i]);
        else if (dfa == 34)
            state34(str[i]);
        else if (dfa == 35)
            state35(str[i]);
        else if (dfa == 36)
            state36(str[i]);
        else if (dfa == 37)
            state37(str[i]);
        else if (dfa == 38)
            state38(str[i]);
        else if (dfa == 20 && dfa != 2)
            state20_2(str[i]);
        else if (dfa == 21)
            state21(str[i]);
        else if (dfa == 2)
            state2(str[i]);
        else
            return 0;
    }
    return dfa == 2 || dfa == 10 || dfa == 20 || dfa == 2 || dfa == 2 || dfa == 2 || dfa == 2 || dfa == 2; // Add more conditions for other accepting states
}

int main() {

    // reading from the file
    ifstream file("input.BYTE"); // "name of our Sample input file"
    stringstream buffer;
    vector<string> strings;
    string FileInput = "";

    // Read the file content into a stringstream
    buffer << file.rdbuf();

    // Extract strings from the file
    string word;
    while (buffer >> word) {
        strings.push_back(word);
    }
    file.close();

    // Display the stored strings
    cout << "Strings from the file: " << endl;
    for (int i = 0; i < strings.size(); i++)
    {
        cout  << strings[i] << " ";
    }


    // Storing each word in a string
    for (int i = 0; i < strings.size(); i++)
    {
        FileInput += strings[i] + " ";
    }
    cout  << FileInput;




    char str[] = "int";
    if (isAccepted(str))
        printf("ACCEPTED\n");
    else
        printf("NOT ACCEPTED\n");

    char str2[] = "char";
    if (isAccepted(str2))
        printf("ACCEPTED\n");
    else
        printf("NOT ACCEPTED\n");

    char str3[] = "else";
    if (isAccepted(str3))
        printf("ACCEPTED\n");
    else
        printf("NOT ACCEPTED\n");

    char str4[] = "elseif";
    if (isAccepted(str4))
        printf("ACCEPTED\n");
    else
        printf("NOT ACCEPTED\n");

    char str5[] = "input";
    if (isAccepted(str5))
        printf("ACCEPTED\n");
    else
        printf("NOT ACCEPTED\n");

    char str6[] = "print";
    if (isAccepted(str6))
        printf("ACCEPTED\n");
    else
        printf("NOT ACCEPTED\n");

    char str7[] = "return";
    if (isAccepted(str7))
        printf("ACCEPTED\n");
    else
        printf("NOT ACCEPTED\n");

    char str8[] = "void";
    if (isAccepted(str8))
        printf("ACCEPTED\n");
    else
        printf("NOT ACCEPTED\n");

    char str9[] = "for";
    if (isAccepted(str9))
        printf("ACCEPTED\n");
    else
        printf("NOT ACCEPTED\n");

    return 0;
}
