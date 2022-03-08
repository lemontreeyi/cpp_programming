#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;
int transform(int input)
{
    if((input>=0)&&(input<=25)) return input + 65;
    else if((input>=26)&&(input<=51)) return input + 71;
    else if((input>=52)&&(input<=61)) return input - 4;
    else if(input == 62) return 43;
    else if(input == 63) return 47;
    else if(input == 64) return 61;
    else exit(0);
}
void filling(int input[], bitset<8> get, int start)
{
    for(int i=0;i<8;i++)
        input[i+start] = get[7-i];
}
void input(int a[], int b[], int start_a, int start_b, int len)
{
    for(int i=0;i<len;i++)
        a[start_a+i] = b[start_b+i];
}
int bin_to_dec(int num[])
{
    int total_sum = 0;
    for(int i=0;i<8;i++){
        total_sum += num[i]*int(pow(2.0,double(7-i)));
    }
    return total_sum;
}
int main() {
    string str, temp;
    int total[100] = {0};
    char s;
    while(cin.get(s))
        str += s;

    int size = str.size();
    int count = 0;
    while(size != 0)
    {
        if(size >= 3)
        {
            int in[24]={0}; int res[4][8]={0};
            for(int i = 0; i < 3; i++) {  //三个字符为一组读入到数组中
                char s = str[str.size()-size+i];
                bitset<8> get = bitset<8>(s);
                filling(in, get, 8*i);
            }
            for(int i=0;i<24;i++){  //将三个byte拓展为4个byte
                if(i>=0 && i<6) input(res[0],in,2,0,6);
                else if(i>=6 && i<12) input(res[1],in,2,6,6);
                else if(i>=12 && i<18) input(res[2],in,2,12,6);
                else input(res[3],in,2,18,6);
            }
            for(int i=0;i<4;i++)  //将拓展后的字符编码进行记录
                total[count++] = transform(bin_to_dec(res[i]));
            size -= 3;
        }
        else if(size == 2)
        {
            int in[16]; int res[3][8] = {0};
            for(int i=0;i<2;i++){
                char s = str[str.size()-size+i];
                bitset<8> get = bitset<8>(s);
                filling(in,get,8*i);
            }
            for(int i=0;i<16;i++){
                if(i>=0 && i<6) input(res[0],in,2,0,6);
                else if(i>=6 && i<12) input(res[1],in,2,6,6);
                else input(res[2],in,2,12,4);
            }
            for(int i=0;i<4;i++){
                if(i==3) total[count++] = transform(64);
                else total[count++] = transform(bin_to_dec(res[i]));
            }
            size = 0;
        }
        else if(size == 1)
        {
            int in[8]; int res[2][8]={0};
            char s = str[str.size()-1];
            bitset<8> get = bitset<8>(s);
            filling(in,get,0);
            for(int i=0;i<8;i++){
                if(i<6) input(res[0],in,2,0,6);
                else input(res[1],in,2,6,2);
            }
            for(int i=0;i<4;i++){
                if(i==3 || i==2) total[count++] = transform(64);
                else total[count++] = transform(bin_to_dec(res[i]));
            }
            size = 0;
        }
    }
    int j = 0;
    while(total[j] != 0)
    {
        cout<<char(total[j]);
        j++;
    }
    system("pause");
}