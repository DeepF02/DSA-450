// Write a Code to check whether one string is a rotation of another
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function checks if passed strings (str1 and str2) are rotations of each other */
    bool areRotations(string str1, string str2)
    {
        // Check if sizes of two strings are same
        if (str1.size() != str2.size()) return false;
        string temp = str1 + str1;
        return (temp.find(str2) != string::npos); //string::npos actually means nth position of string (until the end of the string).
    }                                           //Time Complexity: O(temp.size()).
    // Auxiliary Space: O(str1.size() + str2.size()).

    /* // Method 2 using queue
    bool areRotations(string s, string s2)
    {
        if (s.size() != s2.size()) return 0;
        queue<char> q1;
        //push s1 in q1
        for (int i = 0; i < s.size(); i++)q1.push(s[i]);
        queue<char> q2;
        //push s2 in q2
        for (int i = 0; i < s2.size(); i++)q2.push(s2[i]);
        int k = s2.size();//size of q2
        while (k--)
        {
            char ch = q2.front();
            // we pop and push each char at start of q2 to back k times;
            q2.pop();
            q2.push(ch);
            //During this operation if at any point q1 == q2 then they are rotation of each other
            if (q2 == q1) return true;
        }
        return false;
    }*/
};
int32_t main()
{
    Solution obj;
    string str1 = "AACD", str2 = "ACDA";
    if (obj.areRotations(str1, str2))
        cout << "Strings are rotations of each other\n";
    else
        cout << "Strings are not rotations of each other\n";

    return 0;
}