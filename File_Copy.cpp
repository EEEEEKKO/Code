#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    fstream input("input.txt",ios::out);
    ofstream output("output.txt",ios::out);
    string temp = "Now Test The Copy Function\n"
                "This is second line\n"
                "Over\n";
    input << temp;
    input.close();
    input.open("input.txt");
    if(input.is_open() && output.is_open()){
        while(getline(input,line)){
            output << line << endl;
        }
    }
    else exit(1);
}