#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;


// Global varaibles
int dfa = 0;
int lookahead = 0;

vector<string> tokens;

// Count variables
int charDtCount = 0;
int idCount = 0;
int ifCount = 0;
int statementCount =0;
int PrintCount =0;
int AssignmentCount =0;
int comparisonCount =0;
int OBCount =0;
int CBCount =0;
int TerminatorCount =0;
int ElseCount=0;

// Lexical analyzer's functions

void start(char letter) {
    if(letter == '!') {
        dfa = 1;
    } else if (letter == '\'') {
        dfa = 3;
    } else if (letter == ';') {
        dfa = 6;
    }
    else if(letter == '=') {
        dfa = 7;
    }
    else if(letter == '_') {
        dfa = 9;
    }
    else if(letter == 'c') {
        dfa = 12;
    }
    else if(letter == 'e') {
        dfa = 16;
    }
    else if(letter == 'i') {
        dfa = 20;
    }
    else if(letter == 'p') {
        dfa = 22;
    } else if(letter == '{') {
        dfa = 28;
    } else if(letter == '}') {
        dfa = 29;
    } else if(letter == '%') {
        dfa = 30;
    } else {
        dfa = -1;
    }
}

void state1(char letter) {
    if (letter == '=')
    {
        dfa = 2;
    }
    else 
    {
        dfa = -1;
    }
}

void state3(char letter){
    if (isdigit(letter) || letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z')
    {
        dfa = 4;

    } else {
        dfa = -1;
    }
}

void state4(char letter){
    if (isdigit(letter) || letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z')
    {
        dfa = 4;
    } else if(letter == '\''){
        dfa = 5;
    }
    else{
        dfa = -1;
    }
}

void state7(char letter){
    if (letter == '=')
    {
        dfa = 8;

    } else {
        dfa = -1;
    } 
}
    
void state9(char letter){
    if(isdigit(letter) || letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z'){
        dfa = 10;
    }
    else {
        dfa = -1;
    }
}

void state10(char letter){
    if (isdigit(letter) || letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z') {
        dfa = 10;
    }
    else if(letter == '_'){
        dfa = 11;
    }
    else {
        dfa = -1;
    }
}

void state12(char letter){
    if(letter == 'h'){
        dfa = 13;
    }
    else {
        dfa = -1;
    }
}

void state13(char letter){
    if(letter == 'a'){
        dfa = 14;
    }
    else {
        dfa = -1;
    }
}

void state14(char letter){
    if(letter == 'r'){
        dfa = 15;
    }
    else {
        dfa = -1;
    }
}

void state16(char letter){
    if(letter == 'l'){
        dfa = 17;
    }
    else {
        dfa = -1;
    }
}

void state17(char letter){
    if(letter == 's'){
        dfa = 18;
    }
    else {
        dfa = -1;
    }
}

void state18(char letter){
    if(letter == 'e'){
        dfa = 19;
    }
    else {
        dfa = -1;
    }
}

void state20(char letter){
    if(letter == 'f'){
        dfa = 21;
    }
    else {
        dfa = -1;
    }
}

void state22(char letter){
    if(letter == 'r'){
        dfa = 23;
    }
    else {
        dfa = -1;
    }
}

void state23(char letter){
    if(letter == 'i'){
        dfa = 24;
    }
    else {
        dfa = -1;
    }
}

void state24(char letter){
    if(letter == 'n'){
        dfa = 25;
    }
    else {
        dfa = -1;
    }
}

void state25(char letter){
    if(letter == 't'){
        dfa = 26;
    }
    else {
        dfa = -1;
    }
}

void state26(char letter){
    if(letter == ':'){
        dfa = 27;
    }
    else {
        dfa = -1;
    }
}

void state30(char letter) {
    if (letter == '=') {
        dfa = 8;
    } else {
        dfa = -1;
    }
}

bool isAccepted(string code) {
    // char name = 'Anusha';
    cout << code << endl;
    string token = "[";
    for(int i=0; i<code.size(); i++) {
        
        if(code[i] == ' ') {
            continue;
        }
        // cout << "currChar: " << code[i] << " dfa state: " << dfa << endl;

        if(dfa == 0) {
            start(code[i]); 
        }
         else if(dfa == 1) {
            state1(code[i]);
        }
         else if(dfa == 3) {
            state3(code[i]);
        } 
         else if(dfa == 4) {
            state4(code[i]);
        }
         else if(dfa == 7) {
            state7(code[i]);
        } 
         else if(dfa == 9) {
            state9(code[i]);
        }
         else if(dfa == 10) {
            state10(code[i]);
        }
          else if(dfa == 12) {
            state12(code[i]);
        }
          else if(dfa == 13) {
            state13(code[i]);
        } 
          else if(dfa == 14) {
            state14(code[i]);
        }  
         else if(dfa == 16) {
            state16(code[i]);
        } 
         else if(dfa == 17) {
            state17(code[i]);
        } 
         else if(dfa == 18) {
            state18(code[i]);
        }
         else if(dfa == 20) {
            state20(code[i]);
        }
          else if(dfa == 22) {
            state22(code[i]);
        }
         else if(dfa == 23) {
            state23(code[i]);
        }
          else if(dfa == 24) {
            state24(code[i]);
        } 
         else if(dfa == 25) {
            state25(code[i]);
        }  
         else if(dfa == 26) {
            state26(code[i]);
        }
         else if(dfa == 30) {
            state30(code[i]);
        }
        else {
            dfa = -1;
            cout << "yeh ghalat he: ";
            if (token.size() > 2){
                cout << token.substr(1, token.length() - 2) << endl;
            }
            else{
                cout << token.substr(1) << endl;
            }
            break;
        }
        token += code[i];

        if ((dfa == 2 || dfa == 5 || dfa == 6 || dfa == 8 || dfa == 11 || dfa == 15 || dfa == 19 ||
            dfa == 21 || dfa == 27 || dfa == 28 || dfa == 29) && i != code.size()-1){
            token += "]";
            if(token[1] == '_') {
                token = "[id]";
            }
            if(token[1] == '\'') {
                token = "[statement]";
            }
            if(token[1] == '=' || token[1] == '!') {
                token = "[comparison]";
            }

            if(token == "[char]") charDtCount++;
            else if(token == "[id]") idCount++;
            else if(token == "[statement]") statementCount++;
            else if(token == "[comparison]") comparisonCount++;
            else if(token == "[if]") ifCount++;
            else if(token == "[else]") ElseCount++;
            else if(token == "[;]") TerminatorCount++;
            else if(token == "[{]") OBCount++;
            else if(token == "[}]") CBCount++;
            else if(token == "[print:]") PrintCount++;
            else if(token == "[%=]") AssignmentCount++;
            
            // cout << "token: "<< token << endl;
            tokens.push_back(token);
            // cout << dfa << " " << token << endl;
            token = "[";

            dfa = 0;
        }
    }
    token += "]";
    tokens.push_back(token);

    if (dfa == 2 || dfa == 5 || dfa == 6 || dfa == 8 || dfa == 11 || dfa == 15 || dfa == 19 ||
        dfa == 21 || dfa == 27 || dfa == 28 || dfa == 29){
        return true;
    }
    else {
        return false;
    }
}

// Parser's functions

class Node {
    public:
        string str;
        vector<Node*> child;

        Node(string str) {
            this->str = str;
        }
};

class Tree {
    public:
        Node* root;

        Tree(Node* root) {
            this->root = root;
        }

        void printtree(Node* node) {
            if(node == nullptr) return;

            cout << node->str << endl;

            for (Node* child: node->child) {
                printtree(child);
            }
        }

};

Node* Start();
Node* Statement();
Node* StartPrime();
Node* Init();
Node* IfElse();
Node* Print();
Node* Prime();
Node* Condition();

Node* match(string current){
    cout << "lexeme to match: " << current << " and " << tokens[lookahead] << endl;
    if (current == tokens[lookahead]) {
        Node* terminal = new Node(tokens[lookahead]);
        lookahead++;
        return terminal;
    } else {
        cout << "yahan masla he: " << current << " and " << tokens[lookahead] << endl;
        cout << "Sytax error" << endl;
        exit(1);
    }
}

Node* Start() {
    // cout << "Start " << tokens[lookahead] << endl;
    Node* start = new Node("Start");
    start->child.push_back(Statement());
    start->child.push_back(StartPrime());
    return start;
}

Node* StartPrime() {
    // cout << "StartPrime " << tokens[lookahead] << endl;
    Node* startPrime = new Node("StartPrime");
    if (tokens[lookahead] == "[char]" || tokens[lookahead] == "[if]" || tokens[lookahead] == "[print:]") {
        startPrime->child.push_back(Start());
    }
    return startPrime;
}

Node* Statement() {
    // cout << "Statement " << tokens[lookahead] << endl;
    Node* statement = new Node("Statement");
    if(tokens[lookahead] == "[char]" || tokens[lookahead] == "[id]" ) {
        statement->child.push_back(Init());
    } else if(tokens[lookahead] == "[if]") {
        statement->child.push_back(IfElse());
    } else if(tokens[lookahead] == "[print:]") {
        statement->child.push_back(Print());
    }
    
    return statement;
}

Node* Init() {
    // cout << "Init "<< tokens[lookahead] << endl;
    Node* init = new Node("Init");
    init->child.push_back(match("[char]"));
    init->child.push_back(match("[id]"));
    init->child.push_back(match("[%=]"));
    init->child.push_back(match("[statement]"));
    init->child.push_back(match("[;]"));

    return init;
}

Node* IfElse() {
    // cout << "IfElse " << tokens[lookahead] << endl;
    Node* ifElse = new Node("IfElse");
    ifElse->child.push_back(match("[if]"));
    ifElse->child.push_back(Condition());
    ifElse->child.push_back(match("[{]"));
    ifElse->child.push_back(Start());    
    ifElse->child.push_back(match("[}]"));
    ifElse->child.push_back(match("[else]"));
    ifElse->child.push_back(match("[{]"));
    ifElse->child.push_back(Start());    
    ifElse->child.push_back(match("[}]"));

    return ifElse;
}

Node* Condition() {
    // cout << "Condition " << tokens[lookahead] << endl;
    Node* condition = new Node("Condition");
    condition->child.push_back(Prime());
    condition->child.push_back(match("[comparison]"));
    condition->child.push_back(Prime());

    return condition;
}

Node* Print() {
    // cout << "Print " << tokens[lookahead] << endl;
    Node* print = new Node("Print");
    print->child.push_back(match("[print:]"));
    print->child.push_back(Prime());
    print->child.push_back(match("[;]"));

    return print;
}

Node* Prime() {
    Node* prime = new Node("Prime");
    if (tokens[lookahead] == "[statement]") {
        prime->child.push_back(match("[statement]"));
    } else {
        prime->child.push_back(match("[id]"));
    } 

    return prime;
}

int main() {

    // reading from file
    ifstream file("myfile.txt"); // "name of your Sample input file"
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
        if(i == strings.size() - 1)
        FileInput += strings[i];
        else
        FileInput += strings[i] + " ";
    }
    cout  << FileInput;


   /* string code = "char name != 'Anusha';"
                  "if name != 'Anusha' {"
                     "print: name ;"
                  "}"
                  "else {"
                     "print: 'Saad';"
                  "}";*/
    // cout << code << endl;
    if(isAccepted(FileInput)) {
        cout << "Accepted" << endl;
        cout << "Total tokens: " << tokens.size() << endl;
        cout << "If tokens: " << ifCount << endl;
        cout << "Else tokens: " << ElseCount << endl;
        cout << "id tokens: " << idCount << endl;
        cout << "char tokens: " << charDtCount << endl;
        cout << "statement tokens: " << statementCount << endl;
        cout << "comaprison tokens: " << comparisonCount << endl;
        cout << "{ tokens: " << OBCount << endl;
    } else {
        cout << "Lexical Error" << endl;
        exit(1);
    }

    ofstream outFile("outputfile.txt");
    string writeString;

    writeString = "Total tokens: " + tokens.size() +
                "\nIf tokens: " + ifCount +
                "\nElse tokens: " + ElseCount +
                "\nid tokens: " + idCount +
                "\nchar tokens: " + charDtCount +
                "\nstatement tokens: " + statementCount +
                "\ncomaprison tokens: " + comparisonCount +
                "\n{ tokens: " + OBCount;
    // Check if the file is successfully opened
    if (outFile.is_open()) {
        // Write "hello" to the file
        outFile << writeString << std::endl;

        // Close the file
        outFile.close();

        std::cout << "Successfully wrote 'hello' to test.txt." << std::endl;
    }

    cout << endl << "Tokens: " << endl;
    for (int i=0; i<tokens.size(); i++) {
        cout << tokens[i] << " ";
    }
    cout << endl << endl;

    //parsing start

    Node* parseRoot = Start();

    Tree* tree = new Tree(parseRoot);
    cout << "Parsed" << endl;
    cout << "Parse tree" << endl;
    tree->printtree(parseRoot);
}
