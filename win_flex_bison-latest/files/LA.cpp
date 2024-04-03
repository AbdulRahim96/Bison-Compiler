#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>


using namespace std;

// Lexical Analyzer Class
class LA {
private:
    enum State { 
        START, 
        N_State, u_State, 
        _underScorSTATE, 
        DigitState, 
        VarState, 
        Arithmetic_State, 
        AssignmentState, 
        ComparisonState,
        stringState, 
        iState, 
        ORState,
        tState, hState, eState,
        wState, rState, iiState, ttState,
        eeState, nState, F_state, O_State,
        L_State, L_underscoreState, HState, IState,
        ACCEPT, 
        REJECT
        };
    State currentState;

int datatype = 0;
int vars = 0;
int digits = 0;
int terminator = 0;
int assignment_op = 0;
int comparison_op = 0;
int spaces = 0;
int string_kw = 0;
int wr_kw = 0;
int if_kw = 0;
int then_kw = 0;
int end_kw = 0;
int or_kw = 0;
int round_br = 0;
int arithmetic_op = 0;
int invalid = 0;
int for_kw = 0;

public:
int currentIndex = 0;
int totalSize;

public:
 string TokenString = "";

public:
    LA() {
        currentState = START;
    }

    // Function to move to the next state based on the input character
    void nextState(char input) {
        switch (currentState) {
            case START:
                cout << "Start state" << endl;
                if (input == 'N') {
                    currentState = N_State;
                    cout << "N state" << endl;
                }
                else if(input == '=') {
                    currentState = AssignmentState;
                }
                else if(input == '#')
                {
                    currentState = L_State;
                }
                else if(input == '>' || input == '<' || input == '!') {
                    currentState = ComparisonState;
                }
                else if(input == '%' || input == '*' || input == '+' || input == '-' || input == '/' || input == '^') {
                    currentState = Arithmetic_State;
                }
                else if(input == '_') {
                    currentState = _underScorSTATE;
                }
                else if(input == 'I') {
                    currentState = iState;
                }
                else if(input == 'F'){
                    currentState = F_state;
                }
                else if(input == 'T') {
                    currentState = tState;
                }
                else if(input == ':') {
                    currentState = ACCEPT;
                    terminator++;
                    TokenString += "terminator,";
                    currentState = START;
                }
                else if(input == '(' || input == ')') {
                    currentState = ACCEPT;
                    round_br++;
                    TokenString += "round_br,";
                    currentState = START;
                }
                else if(isdigit(input)) {
                    cout << "digit state" << endl;
                    currentState = DigitState;
                }
                else if(input == '"') {
                    currentState = stringState;
                }
                else if(input == 'W') {
                    currentState = wState;
                }
                else if(input == 'O') {
                    currentState = ORState;
                }
                else if(input == 'E') {
                    currentState = eeState;
                }
                else if(input == ' ') {
                    currentState = START;
                    cout << "Space detected" << endl;
                }
                else {
                    currentState = REJECT;
                }
                break;

#pragma Library

        case L_State:

            break;
        case L_underscoreState:

            break;

        case HState:
                if(input == 'R') {
                    currentState = ACCEPT;
                    //Lib++;
                    TokenString += "lib";
                    currentState = START;
                    
                }
                else if(input == 'I')
                {
                    currentState = IState;
                }
            break;

        case IState:

            break;

#pragma endregion

#pragma ForState 
                case F_state:
                if(input == 'o'){
                    currentState = O_State;
                }
                else{
                    currentState = REJECT;
                }
                break;

                case O_State:
                if(input == 'r'){
                    currentState = ACCEPT;
                    for_kw++;
                    TokenString += "for_kw";
                    currentState = START;
                }
                else{
                    currentState = REJECT;
                }
                break;
#pragma endregion
#pragma Datatype_token 

            case N_State:
                if (input == 'u') {
                    currentState = u_State;
                } else {
                    currentState = REJECT;
                }
                break;

            case u_State:
                if (input == 'm') {
                    currentState = ACCEPT;
                    datatype++;
                    TokenString += "datatype,";
                    currentState = START;
                } else {
                    currentState = REJECT;
                }
                break;
#pragma endregion
#pragma Arithmetic_op


            case Arithmetic_State:
                if (input == '=') {
                    currentState = ACCEPT;
                    comparison_op++;
                    TokenString += "comparison_op,";
                    currentState = START;
                } else if(input == ' ') {
                    arithmetic_op++;
                    TokenString += "arithmetic_op,";
                    currentState = START;
                } else {
                    currentState = REJECT;
                }
                break;
#pragma endregion
#pragma Comparison_op
        case AssignmentState:
                if (input == '=')
                {
                    currentState = ACCEPT;
                    comparison_op++;
                    TokenString += "comparison_op,";
                    currentState = START;
                } else if (input == ' '){
                    currentState = ACCEPT;
                    assignment_op++;
                    TokenString += "assignment_op,";
                    currentState = START;
                }
                else
                {
                    currentState = REJECT;
                }
                break;
        case ComparisonState:
                if (input == '=')
                {
                    currentState = ACCEPT;
                    comparison_op++;
                    TokenString += "comparison_op,";
                    currentState = START;
                } else {
                    currentState = REJECT;
                }
                break;
#pragma endregion
#pragma vars
        case _underScorSTATE:
                if (islower(input)) // checking if its lowercase alphabet
                {
                    cout << "at underscore state" << endl;
                    currentState = VarState;
                } else {
                    currentState = REJECT;
                }
                break;
        case VarState:
                if (islower(input)) // checking if its lowercase alphabet
                {
                    if(currentIndex >= totalSize - 1)
                    {
                        vars++;
                        TokenString += "vars,";
                        currentState = START;
                    }
                    else
                    {
                        cout << "at varState state" << endl;
                        currentState = VarState;
                    }
                    
                }
                else if(input == ' ') {
                    cout << "Space at underscore state" << endl;
                    vars++;
                    TokenString += "vars,";
                    currentState = START;
                }else if(input == ':') {
                    vars++;
                    TokenString += "vars,";
                    terminator++;
                    TokenString += "terminator,";
                    currentState = START;
                }
                else {
                    currentState = REJECT;
                }
                break;
#pragma endregion
#pragma Digits
        case DigitState:
        
                if (input >= '0' && input <= '9')
                {
                    currentState = DigitState;
                }
                else if(input == ':') {
                    digits++;
                    TokenString += "digit,";
                    
                    terminator++;
                    TokenString += "terminator,";
                    currentState = START;
                }else if(input == ' ') {
                    digits++;
                    TokenString += "digit,";
                    currentState = START;
                }
                else {
                    currentState = REJECT;
                }
                break;
#pragma endregion
#pragma String_kw
        case stringState:
                
                if (input == '"')
                {
                    currentState = ACCEPT;
                    string_kw++;
                    TokenString += "string_kw,";
                    currentState = START;
                } else {
                    currentState = stringState;
                }
                break;
#pragma endregion
#pragma if_kw
        case iState:
                if (input == 'f')
                {
                    currentState = ACCEPT;
                    if_kw++;
                    TokenString += "if_kw,";
                    currentState = START;
                } else {
                    currentState = REJECT;
                }
                break;
#pragma endregion
#pragma then_kw
        case tState:
                if (input == 'h')
                {
                    currentState = hState;
                } else {
                    currentState = REJECT;
                }
                break;
        case hState:
                if (input == 'e')
                {
                    currentState = eState;
                } else {
                    currentState = REJECT;
                }
                break;
        case eState:
                if (input == 'n')
                {
                    currentState = ACCEPT;
                    then_kw++;
                    TokenString += "then_kw,";
                    currentState = START;
                } else {
                    currentState = REJECT;
                }  
                break;
#pragma endregion
#pragma end_kw
        case eeState:
                if (input == 'n')
                {
                    currentState = nState;
                } else {
                    currentState = REJECT;
                }
                break;
        case nState:
                if (input == 'd')
                {
                    currentState = ACCEPT;
                    end_kw++;
                    TokenString += "end_kw,";
                    currentState = START;
                } else {
                    currentState = REJECT;
                }
                break;
#pragma endregion
#pragma wr_kw
        case wState:
                if (input == 'r')
                {
                    currentState = rState;
                } else {
                    currentState = REJECT;
                }
                break;
        case rState:
                if (input == 'i')
                {
                    currentState = iiState;
                } else {
                    currentState = REJECT;
                }
                break;
        case iiState:
                if (input == 't')
                {
                    currentState = ttState;
                } else {
                    currentState = REJECT;
                }
                break;
        case ttState:
                if (input == 'e')
                {
                    currentState = ACCEPT;
                    wr_kw++;
                    TokenString += "wr_kw,";
                    currentState = START;
                } else {
                    currentState = REJECT;
                }
                break;
#pragma endregion
#pragma ORState             
        case ORState:
                if (input == 'r')
                {
                    currentState = ACCEPT;
                    or_kw++;
                    TokenString += "or_kw,";
                    currentState = START;
                } else {
                    currentState = REJECT;
                }
                break;
#pragma endregion

            default:
                currentState = START;
                break;
        }
    }

    void isAccepted(const string& input) {
        currentState = START;
        cout << "String: " << input << endl;
        
        totalSize = input.size();
        for (int i = 0; i < input.size(); i++)
        {
            cout << "Current: " << currentIndex << endl;
            cout << input[i] << endl;
            nextState(input[i]);
            currentIndex++;
        }
        
        
        cout << "Datatype: " << datatype << endl;
        cout << "\nVariable: " << vars << endl;
        cout << "\nassignment operator: " << assignment_op << endl;
        cout << "\nDigit: " << digits << endl;
        cout << "\nTerminator: " << terminator << endl;

     /*   return (currentState == ACCEPT || currentState == DigitState || currentState == VarState || currentState == AssignmentState || currentState == ComparisonState);*/
};
};

// Grammer Class
class Grammer {
    private:
    string TokensString = "datatype,vars,assignment_op,digit,terminator,datatype,vars,assignment_op,digit,terminator,vars,assignment_op,vars,terminator,if_kw,round_br,vars,comparison_op,vars,round_br,then_kw,wr_kw,round_br,string_kw,round_br,terminator,datatype,vars,assignment_op,digit,terminator,end_kw,";
    int lexemeIndex = 0;
    public: 
    bool verify, epsilon;
    vector<string> words;
/*
     Num _mynum = 5:
     Datatype Vars assignment_op Digit terminator

     Num _mynum = 5:
     D     V    A NT

     _mynum = 7:
       V    A NT
    
    

    S => LIB FUNCTION
    X => IFY | e
    Y => THEN_END
    Z => x | e
    U => datatypeV
    V => vars,assignment_op,O,terminator
    O => vars | digit
    T => wr_kw,round_br,string,round_br,terminator
    IF => if_kw,round_br,COMP,round_br
    COMP => vars,comparison_op,O
    THEN_END => then_kw(STATEMENTS)end_kw
    FOR => for_kw,round_br,FORDeclare,COMP,terminator,I_D,round_br,THEN_END
    FORDeclare => U | V
    I_D => vars,assignment_op,vars,arithmetic_op,O
    STATEMENTS => USTATEMENTS | VSTATEMENTS | TSTATEMENTS | XSTATEMENTS | FOR | e
    LIB => lib | e
    FUNCTION => datatype,func_kw,THEN_END
*/

public:
    void BreakDownTokens()
    {
        stringstream ss(TokensString);
        string word;
        verify = true;
        
        while (getline(ss, word, ',')) {
            words.push_back(word);
        }
        for (int i = 0; i < words.size(); i++)
        {
         //   cout << "Token: " + words[i] << endl;
        }
        epsilon = isEpsilon();
    }

    Grammer(string str)
    {
        TokensString = str;
    }
    Grammer()
    {
        
    }

    void match()
    {
        cout << "   Leaf node =>   " + words[lexemeIndex] << endl;
        // moving header forward
        lexemeIndex++;
        epsilon = isEpsilon();
    }

    bool isEpsilon()
    {
        if(lexemeIndex >= words.size())
            return true;
        else
            return false;
    }

    void S()
    { 
        STATEMENTS();
        X();
    }

    void X()
    {
        if((verify && !epsilon) && words[lexemeIndex] == "if_kw")
        {
            cout << "IF:" << endl;
            IF();
            cout << "Y:" << endl;
            Y();
        }
        else
            return;
        
    }

    void Y()
    {
        THEN_END();
        S();
    }

    void Z()
    {
        if((verify && !epsilon) && words[lexemeIndex] == "if_kw")
        {
            X();
        }
        else
            return;
    }

    void U()
    {
        if((verify && !epsilon) && words[lexemeIndex] == "datatype")
        {
            match();
            cout << "   V:" << endl;
            V();
        }
        else
            verify = false;
        
    }

    void V()
    {
        if((verify && !epsilon) && words[lexemeIndex] == "vars")
        {
            match();
            if((verify && !epsilon) && words[lexemeIndex] == "assignment_op")
            {
                match();
                cout << "       O:" << endl;
                O();
                if((verify && !epsilon) && words[lexemeIndex] == "terminator")
                {
                    match();
                }
                else
                    verify =  false;
            }
            else
                verify =  false;
        }
        else
            verify =  false;
        
    }

    void O()
    {
        if((verify && !epsilon) && words[lexemeIndex] == "vars")
        {
            match();
        }
        else if((verify && !epsilon) && words[lexemeIndex] == "digit")
        {
            match();
        }
        else
            verify = false;
    }

    void T()
    {
        
        if((verify && !epsilon) && words[lexemeIndex] == "wr_kw")
        {
            match();
            if((verify && !epsilon) && words[lexemeIndex] == "round_br")
            {
                match();
                if((verify && !epsilon) && words[lexemeIndex] == "string_kw")
                {
                    match();
                    if((verify && !epsilon) && words[lexemeIndex] == "round_br")
                    {
                        match();
                        if((verify && !epsilon) && words[lexemeIndex] == "terminator")
                        {
                            match();
                        }
                        else
                            verify = false;
                    }
                    else
                        verify = false;
                }
                else
                    verify = false;
            }
            else
            {
                verify = false;
                cout << "failed at " << endl;
            }
        }
        else
            verify = false;
    }

    void IF()
    {
        if((verify && !epsilon) && words[lexemeIndex] == "if_kw")
        {
            match();
            if((verify && !epsilon) && words[lexemeIndex] == "round_br")
            {
                match();
                COMP();

                if((verify && !epsilon) && words[lexemeIndex] == "round_br")
                    {
                        match();
                    }
                else
                    {
                        verify = false;
                        cout << "failed at If Statement" << endl;
                    }
            }
            else
                {
                    verify = false;
                    cout << "failed at If Statement" << endl;
                }
        }
    }

    void COMP()
    {
        if((verify && !epsilon) && words[lexemeIndex] == "vars")
        {
            match();
            if(((verify && !epsilon) && words[lexemeIndex] == "comparison_op"))
            {
                match();
                O();
            }
        }
    }

    void THEN_END()
    {
        if((verify && !epsilon) && words[lexemeIndex] == "then_kw")
        {
            match();
            STATEMENTS();
            if((verify && !epsilon) && words[lexemeIndex] == "end_kw")
            {
                match();
            }
            else
            {
                verify = false;
                cout << "failed at THEN_END" << endl;
            }
        }
    }

    void FOR()
    {

    }

    void FORDeclare()
    {

    }

    void I_D()
    {
        
    }

    void STATEMENTS()
    {
        if((verify && !epsilon) && words[lexemeIndex] == "datatype")
        {
            cout << "U:" << endl;
            U();
            STATEMENTS();
        }
        else if((verify && !epsilon) && words[lexemeIndex] == "vars")
        {
            cout << "V:" << endl;
            V();
            STATEMENTS();
        }
        else if((verify && !epsilon) && words[lexemeIndex] == "wr_kw")
        {
            cout << "T:" << endl;
            T();
            STATEMENTS();
        }
        else if((verify && !epsilon) && words[lexemeIndex] == "if_kw")
        {
            cout << "X:" << endl;
            X();
            STATEMENTS();
        }
        else 
            return;
    }

    void LIB()
    {

    }

    void FUNCTION()
    {

    }
};



int main() {
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
    
    LA LaxicalAnalyzer = LA();

    LaxicalAnalyzer.isAccepted(FileInput);

    cout << endl;
    cout << "Current: " << LaxicalAnalyzer.currentIndex << endl;
    cout << "total size: " << LaxicalAnalyzer.totalSize << endl;
    cout << "Token: " << LaxicalAnalyzer.TokenString << endl ;
    cout << "**END OF LEXICAL ANALYZER**" << endl;

    Grammer grammer = Grammer(LaxicalAnalyzer.TokenString);
    cout << "\n\n**Initializing Grammer for the Following Tokens:**\n" << LaxicalAnalyzer.TokenString << endl;
    cout << endl;
    grammer.BreakDownTokens();
    grammer.S();

    cout << LaxicalAnalyzer.TokenString;

    if(grammer.verify == true)
        cout << "Success!" << endl;
    else
        cout << "fail!" << endl;

    
    return 0;
}
