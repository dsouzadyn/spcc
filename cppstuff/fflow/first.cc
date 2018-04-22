#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    unordered_map<string, string> rules;
    int N;
    cin >> N;
    cin.ignore();
    for(int i = 0;i < N; i++) {
        string s;
        getline(cin, s);
        cout << s << endl;
        istringstream ss(s);
        vector<string> tokens;
        for(string e; getline(ss, e, ' '); tokens.push_back(e));
        rules[tokens[0]] = tokens[2];
    }
    map<string, vector<char> > first_list;
    for(auto &rule: rules) {
        string lhs = rule.first;
        string rhs = rule.second;
        while(!islower(rhs[0])) rhs = rules[rhs.substr(0, 1)];
        first_list[lhs].push_back(rhs[0]);
    }

    for(auto &firsts: first_list) {
        // if(firsts.first == "") continue;
        cout << "First(" << firsts.first << ")={ ";
        for(char c: firsts.second) {
            cout << c << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
