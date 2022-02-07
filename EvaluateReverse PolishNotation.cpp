class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // ["2","1","+","3","*"]
        stack<int> stack; //create a stack to store integers
        // loop through vector and check if its an operand or an integer
        for (int i = 0; i < tokens.size(); i++ ){
            string nums = tokens[i];
            //if it's an int, push into stack
            if (isdigit(nums[0]) || nums.size() > 1) { 
                stack.push(stoi(nums)); // 2, 1, 3
                continue;
            } 
            int num1 = stack.top();
            stack.pop();
            int num2 = stack.top();  
            stack.pop();
            if (nums[0] == '+') { //add the two nums
                stack.push(num1+num2);
            } else if (nums[0] == '*') {
                stack.push(num1*num2);
            } else if (nums[0] == '-') {
                stack.push(num2-num1);
            } else {
                stack.push(num2/num1);
            }
        }
        return stack.top();
    }
};