#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    fstream infile("input.txt");
    string line;
    int locctr = 0;
    map<string, int> symtab;
    map<string, int> opcodetab;
    opcodetab["BYTE"] = 1;
    opcodetab["WORD"] = 2;
    opcodetab["DWORD"] = 4;
    getline(infile, line);
    istringstream ss(line);
    istream_iterator<string> begin(ss), end;
    vector<string> tokens(begin, end);
    if(tokens.size() == 2)
        if(tokens[0] == "START")
            locctr = atoi(tokens[1].c_str());
    else
        locctr = 0;
    cout << "Symbol table contents" << endl;
    while(getline(infile, line)) {
        istringstream ss(line);
        istream_iterator<string> begin(ss), end;
        vector<string> tokens(begin, end);
        if(tokens[0] == "END")
            break;
        else {
            if(symtab.find(tokens[0]) == symtab.end() && tokens[0] != ";")
                symtab[tokens[0]] = locctr;
            locctr += opcodetab[tokens[1]];
        }
        locctr++;
    }
    for(auto const &item: symtab) {
        cout << item.first << "\t" << item.second << endl;
    }
    return 0;
}
