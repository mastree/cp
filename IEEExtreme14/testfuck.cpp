#include <bits/stdc++.h>

using namespace std;

void interpretCode(const string& commands)
{
    vector<int> data(1, 0);
    vector<int>::iterator dataPtr = data.begin();

    string::const_iterator instructionPtr = commands.begin();
    stack<string::const_iterator> instructionStack;

    while (instructionPtr != commands.end())
    {
        switch (*instructionPtr)
        {
        case '<':
        {
            dataPtr--;
            break;
        }
        case '>':
        {
            dataPtr++;
            if (dataPtr == data.end()) {
                data.push_back(0);
                dataPtr = data.end()-1;
            }
            break;
        }
        case '+':
        {
            (*dataPtr) += 1;
            break;
        }
        case '-':
        {
            (*dataPtr) -= 1;
            break;
        }
        case '.':
        {
            cout << char(*dataPtr);
            break;
        }
        case ',':
        {
            char input;
            cin >> input;
            *dataPtr = input;
        }
        case '[':
        {
            instructionStack.push(instructionPtr);

            if (*dataPtr == 0)
            {
                auto startInstructionPtr = instructionPtr;
                while (++instructionPtr != commands.end())
                {
                    if (*instructionPtr == '[')
                        instructionStack.push(instructionPtr);
                    else if (*instructionPtr == ']')
                    {
                        if (instructionStack.empty())
                            throw runtime_error("Found a ']' that did not have a matching '['!");

                        auto tempInstructionPtr = instructionStack.top();
                        instructionStack.pop();

                        if (startInstructionPtr == tempInstructionPtr)
                            break;
                    }
                }
            }
            break;
        }
        case ']':
        {
            if (instructionStack.empty())
                throw runtime_error("Found a ']' that did not have a matching '['!");

            if (*dataPtr != 0)
                instructionPtr = instructionStack.top();
            else
                instructionStack.pop();

            break;
        }
        default:
            break;
        }

        instructionPtr++;
    }

    if (!instructionStack.empty())
        throw runtime_error("Found a '[' that did not have a matching ']'!");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        try
        {
        string commands = ">,>,>,<[->->+<<]>>[-<<+>>]<<<[->-<<+>]<[->+<]>>>>>>+>>>>>>>+[>>>>[-]<[-]<[-]<[-]<[-]<<<<<<<<<<<<[->>>>>>>+>>>>>>+<<<<<<<<<<<<<]>[->>>>>>>+>>>>>>+<<<<<<<<<<<<<]>[->>>>>>>+>>>>>>+<<<<<<<<<<<<<]>>+>+[<-]<[->>+<<<]>>>>[-<<<<<<<+>>>>>>>]>[-<<<<<<<+>>>>>>>]>[-<<<<<<<+>>>>>>>]>>>>>>>+[-<<<<<<<<<<<[->>+>>+<<<<]>[->>+>>+<<<<]>[-<<+>>]>[-<<+>>]+[[-]+>[<-]<[->>-<<<]>>->>>+>[<-]<[->+>[-<-]<[>>[-<<->]-<<[->->>-<<<<]]<]>>-<<<<<+>[<-]<[>>[<<->]<<[<]]>-]>>>>>>>>+]-<<<<+>+[<-]<[>>+[<<->]<<[>>>+[<<<->>]<<<[<]]]>-]>>>>[-]<<<<<<<<<<<<<<[-]>>+>+[<-]<[->>+<<<]>+>[<-]<[>>[<<->]<<[<]]>-[+>>>>>>++++++++++<<<<<<+>[<-]<[>>[<<->]<<[<]]>-[++>[<-]<[->>-<<<]>>->>+>>+>-[<-]<[<<[->>>+<<<]>>>>>+>+[<-]<[->>+<<<]<<-<]<<<<+>[<-]<[>>[<<->]<<[<]]>-]>>++++++++[->++++++<]>[-<<<<+>>>>]>>>>>+>[<-]<[>>[<<->]<<[<]]>-[++>[<-]<[->>-<<<]>>-<<<<<<<<+>+[<-]<[->>+<<<]>>>>>>>>+>[<-]<[>>[<<->]<<[<]]>-]<<[-]<<<<<+>[<-]<[>>[<<->]<<[<]]>-]<<[.<]";
        interpretCode(commands);
        }
        catch (const exception& e)
        {
            cout << endl << e.what() << endl;
        }
    }

    return 0;
}