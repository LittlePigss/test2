#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

    // 123.45#1+126.53@
    // 1#3+1#0.4
int main(){
    string input;
    string num1,num1_m,num2,num2_m; //小数和整数
    double d = 0;
    double s = 0;
    map<char,int> m;
    m['!'] = 0;
    m['@'] = 1;
    m['#'] = 2;
    int dp[3][3]{   {0,13,4},
                    {13,7,20},
                    {4,20,5},    };

    int length;
    cin >> length;
    cin >> input;
    stringstream ss(input);
    getline(ss,num1,'+');
    getline(ss,num2,'+');
    //数字提取
    stringstream ss1(num1);
    getline(ss1,num1,'.');
    getline(ss1,num1_m,'.');
    // cout << num1 << endl;
    // cout << num1_m << endl;
    stringstream ss2(num2);
    getline(ss2,num2,'.');
    getline(ss2,num2_m,'.');
    //整数运算

    for(int i=0;i<num1.size();i++){
        if(num1[i] == '!' || num1[i] == '@' || num1[i] == '#'){
            int a = m[num1[i]];
            int b = m[num2[i]];
            d = d*10 + dp[a][b];
        }else {
            d = d*10 + (num1[i] - '0') + (num2[i] - '0');
        }
    }

    //小数运算
    int count = min(num1_m.size(),num2_m.size());
    int countM = max(num1_m.size(),num2_m.size());
    //补齐长度
    if(num1_m.size() != num2_m.size()){
        if(num1_m.size() == count){
            while(num1_m.size() < countM)   num1_m += "0";
        }else{
            while(num2_m.size() < countM)   num2_m += "0";
        }
    }
    // cout << num1_m << endl;
    // cout << num2_m << endl;
    for(int i=0;i<countM;i++){
        if(num1_m[i] == '!' || num1_m[i] == '@' || num1_m[i] == '#'){
            int a = m[num1_m[i]];
            int b = m[num2_m[i]];
            s = s*10 + dp[a][b];
        }else {
            s = s*10 + (num1_m[i] - '0') + (num2_m[i] - '0');
        }
    }
    int c = countM;
    while(c > 0){
        s = s / 10;
        c--;
    }

    double res = s + d;
    cout << setprecision(countM) << fixed << res << endl;

    system("pause");
}