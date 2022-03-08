#include<iostream>
using namespace std;

bool is_letter(char s)
{
    if((int(s) >= 65) && (int(s)<=90)) return true;
    else if((int(s) >= 97) && (int(s)<=122)) return true;
    else return false;
}
int main()
{
    string str;
    int count_word = 0, count_line = 0, count_char = 0;
    while(getline(cin, str) && !str.empty())
    {
        count_line += 1;
        bool flag = false;
        for(int i=0;i<str.size();i++)
        {
            char s = str[i];
            if(is_letter(s))
            {
                if(!flag)
                {
                    count_word += 1;
                    flag = true;
                }
            }
            else{
                flag = false;
            }
        }
        count_char += str.size();
    }
    count_char += count_line;
    cout<<count_char<<' '<<count_word<<' '<<count_line;
    return 0;
}