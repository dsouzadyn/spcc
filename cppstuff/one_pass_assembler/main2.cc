#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    fstream infile("input.txt");
    string line;
    int locctr = 0;
    getline(infile, line);
    istringstream ss(line);
    map<string, int> symtab;
    map<string, int> optab;
    optab["BYTE"] = 1;
    optab["WORD"] = 2;
    optab["DWORD"] = 4;
    istream_iterator<string> begin(ss), end;
    vector<string> tokens(begin, end);
    if(tokens.size() == 2)
        if(tokens[0] == "START")
            locctr = atoi(tokens[1].c_str());
    else
        locctr = 0;
    while(getline(infile, line)) {
        istringstream ss(line);
        istream_iterator<string> begin(ss), end;
        vector<string> tokens(begin, end);
        if(tokens[0] == ";")
            continue;
        else {
            if(tokens[0] == "END")
                break;
            if(symtab.find(tokens[0]) == symtab.end())
                symtab[tokens[0]] = locctr;
            locctr += optab[tokens[1]];
        }
    }
    cout << "Symbol Table contents: " << endl;
    for(auto &item: symtab) {
        cout << item.first << "\t" << item.second << endl;
    }
    return 0;
}
