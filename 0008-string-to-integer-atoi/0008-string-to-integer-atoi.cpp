class Solution {
public:
    int myAtoi(string s) {
        long long res=0;
        int sign=1;
        bool started=false;
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' && !started)
            continue;
            else if(s[i]=='-' && !started){
            sign=-1;
            started=true;
            continue;
            }
            else if(s[i]=='+' && !started){
            sign=1;
            started=true;
            continue;
            }
            else if(s[i]-'0'<=9 && s[i]-'0'>=0){
            res=res*10+(s[i]-'0');
            started=true;
             if (sign == 1 && res > INT_MAX)
                    return INT_MAX;
                if (sign == -1 && -res < INT_MIN)
                    return INT_MIN;
            }
            else
            break;
        }
        return res*sign;
    }
};