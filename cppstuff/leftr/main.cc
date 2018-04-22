#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int N;
    map<string, string> productions;
    cout << "Enter N: " << endl;
    cin >> N;
    string s;
    for(int i = 0; i < N; i++) {
        cin.ignore(); // Important
        getline(cin, s);
        cout << s << endl;
        istringstream ss(s);
        istream_iterator<string> begin(ss), end;
        vector<string> parts(begin, end);
        cout << parts.size() << endl;
        productions[parts[0]] = parts[2];
    }
    for(map<string, string>::iterator it = productions.begin(); it != productions.end(); ++it) {
        cout << it->first[0] << endl;
        cout << it->second[0] << endl;
        if(it->first[0] != it->second[0])
            cout << "Left recursion doesn't Exist" << endl;
        else {
            cout << "Left recursion is present" << endl;
            istringstream ss(it->second);
            vector<string> rprod;
            for(string e; getline(ss, e, '|'); rprod.push_back(e));
            char a = rprod[0][0];
            string alpha = rprod[0].substr(1);
            char bta;
            if(rprod.size() == 2)
                bta = rprod[1][0];
            cout << a << "->" << bta << a << "'" << endl;
            cout << a << "'->" << alpha << a << "'" << "|^" << endl;
        }
    }
    return 0;
}
