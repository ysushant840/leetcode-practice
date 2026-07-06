class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(char ch : s) {

            // Opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Closing brackets
            else {

                // Stack empty means invalid
                if(st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                // Matching check
                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '[')) {
                    
                    return false;
                }
            }
        }

        // Stack should be empty
        return st.empty();
    }
};