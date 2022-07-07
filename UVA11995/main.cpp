#include <iostream>
#include <queue>
#include <stack>

int main() {
    int lines;
    int task;
    int num;


    while(std::cin >> lines) {
        std::queue<int> queue;
        std::stack<int> stack;
        std::priority_queue<int> priorq;

        bool q = true;
        bool s = true;
        bool pq = true;

        for(int i = 0; i < lines; i++){
            std::cin >> task >> num;
            if (task == 1) {
                queue.push(num);
                stack.push(num);
                priorq.push(num);
            }
            if(task==2) {
                if (s) {
                    if (stack.empty() || stack.top() != num)
                        s = false;
                    else
                        stack.pop();
                }
                if (q) {
                    if (queue.empty() || queue.front() != num)
                        q = false;
                    else
                        queue.pop();
                }
                if (pq) {
                    if (priorq.empty() || priorq.top() != num)
                        pq = false;
                    else
                        priorq.pop();
                }
            }
        }

        if (q && !s && !pq)
            std::cout << "queue\n";
        else if (!q && s && !pq)
            std::cout << "stack\n";
        else if (!q && !s && pq)
            std::cout << "priority queue\n";
        else if (q || s || pq)
            std::cout << "not sure\n";
        else
            std::cout << "impossible\n";
    }

    return 0;
}