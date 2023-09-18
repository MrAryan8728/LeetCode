class Solution {
public:
    int myAtoi(string s) {
        /*
        We need to handle four cases:
            Overflow
            Discarding all the leading whitespaces
            Sign of the number
            Invalid input
        */
        int n = s.size();
        int  i = 0,pos = 0,neg = 0;
        while(s[i] == ' '){
            i++;
        }

        while(s[i] == '+'){
            pos++;
            i++;
        }

        while(s[i] == '-'){
            neg++;
            i++;
        }

        double ans = 0;

        while(i < n and s[i] >= '0' and s[i] <= '9'){
            ans = ans * 10 + (s[i] - '0');
            i++;
        }

        if(neg > 0) ans = -ans;
        if(pos > 1 or neg > 1) return 0;
        if(pos > 0 and neg > 0) return 0;

        if(ans > INT_MAX) ans = INT_MAX;
        if(ans < INT_MIN) ans = INT_MIN;

        return (int)ans;
    }
};