#include "Calculator.hpp"
#include <iostream>
using namespace std;

int main(){

    string cmd;
    string name;
    Calculator * calc;
    double val;
    bool check;
    string x;
    string y;
    string z;
    while(cin>>cmd){
        if(cmd =="CRT"){
            cin>>val;
            calc = new Calculator(val);
            cout<<"success"<<endl;
        }
        else if(cmd=="DEF"){
            cin >> name;
            cin >> val;
            check = calc->DEF(name,val);
            if(check){
                cout<<"success"<<endl;
            }else{
                cout<<"failure"<<endl;
            }
        }else if(cmd=="ADD"){
            cin>> x;
            cin>> y;
            cin>> z;
            check = calc->ADD(x,y,z);
            if(check){
                cout<<"success"<<endl;
            }else{
                cout<<"failure"<<endl;
            }
        }else if(cmd=="SUB"){
            cin>> x;
            cin>> y;
            cin>> z;
            check = calc->SUB(x,y,z);
            if(check){
                cout<<"success"<<endl;
            }else{
                cout<<"failure"<<endl;
            }
        }else if(cmd=="REM"){
            cin>>x;
            check = calc->REM(x);
            if(check){
                cout<<"success"<<endl;
            }else{
                cout<<"failure"<<endl;
            }
        }else if (cmd == "PRT"){
            cin>>x;
            calc->PRT(x);
        }else if(cmd=="END"){
            delete calc;
            calc = nullptr;
            break;
        }
    }


}