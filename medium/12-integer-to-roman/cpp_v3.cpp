// Pushed: 2026-10-08 17:28:31 UTC
// Difficulty: Medium
// Runtime: 0 ms
// Memory: 9.4 MB

class Solution {
public:
    string intToRoman(int num) {
    static vector<int> val {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    static vector<string> sym {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    
        string result = "";

        for (int i=0;i< val.size();i++)
        {
            if(num==0)
            break;

            int times = num/val[i];

            while (times--)
            {
            result += sym[i];
            }
            num=num%val[i];
        }

        return result;

    }
};
