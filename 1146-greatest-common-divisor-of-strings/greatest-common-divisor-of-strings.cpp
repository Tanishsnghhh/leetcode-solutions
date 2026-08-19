class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1 ){
        return "";
        }

        int a = str1.length();
        int b = str2.length();

        int len = 0;

      for (int i = min(a, b); i >= 1; i--) {
      if (a % i == 0 && b % i == 0) {
        len = i;
        break;}
    }

    return str1.substr(0,len);
    }
};