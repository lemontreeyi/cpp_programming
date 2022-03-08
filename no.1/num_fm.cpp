#include<iostream>
using namespace std;
int main()
{
    int total_num;
    cin >> total_num;
    int sum_m = 0, sum_f = 0;
    int age; char sex; string name;
    for(int i=0;i<total_num;i++) {
        for (int j = 0; j < 3; j++) {
            switch (j) {
                case 0:cin >> age;break;
                case 1:cin >> sex;break;
                case 2:cin >> name;break;
                default:break;
            }
        }
        if(sex == 'm') sum_m += age;
        else if(sex == 'f') sum_f += age;
        else {
            cout<< "您的输入有误" <<endl;
            exit(0);
        }
    }
    cout<<"f:"<<sum_f<<endl;
    cout<<"m:"<<sum_m<<endl;
    return 0;
}