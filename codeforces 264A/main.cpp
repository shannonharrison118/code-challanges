#include <iostream>
#include <vector>

int main() {
    std::string in;

    std::cin >> in;
    std::vector<int> nums(in.length());
    int beg = 0;
    int end = in.length()-1;

    for(int k = 0; k < in.length(); k++){
        if(in[k]=='l'){
            nums[end--] = k+1;
        }
        else{
            nums[beg++] = (k+1);
        }
    }
    for(int i = 0; i < nums.size(); i++){
        std::cout << nums[i] << '\n';
    }


    return 0;
}
