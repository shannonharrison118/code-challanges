#include <iostream>
#include<stack>

int main() {
    int lines=0;
    std::string par;
    std::stack<char> count;

    std::cin >> lines;
    std::cin.ignore();
    while(lines--){
        std::getline(std::cin,par);
        if (par == ""){
            std::cout << "Yes\n";
            continue;
        }
        for(int i = 0; i < par.length(); i++){
            if(par[i] == '(' || par[i] == '[')
                count.push(par[i]);
            else if(par[i] == ')'){
                if(count.empty() || count.top() != '('){
                    count.push(par[i]);
                    break;
                }
                count.pop();
            }
            else if(par[i] == ']'){
                if(count.empty() || count.top() != '['){
                    count.push(par[i]);
                    break;
                }
                count.pop();
            }
        }
        if(count.empty())
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
        while(!count.empty())
            count.pop();
    }
    return 0;
}
