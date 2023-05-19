#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void write_to_file(string str){
    int n = str.size();
    ofstream f("testpattern.txt", ios::app);
    for(int i=0;i<n-1;i++){
        f << str[i];
        f<<',';
    }
    f<< str[n-1]<<"\n";
    f.close();
}

void exhaustive_testpattern(int n)
{
   for(int i=0;i<pow(2,n);i++){
       string str="";
       int temp=i;
       while(temp){
           if(temp&1){str=to_string(1)+str;}
           else{str=to_string(0)+str;}
            
           temp=temp>>1;
       }
       for(int j=str.size();j<n;j++){
            str = to_string(0)+str;
       }
       cout << "wait for 10ns;"
            << "\n"
            << "a <= \'" << str[0] << "\'; b <= \'" << str[1] << "\'; c <= \'" << str[2] << "\'; d<= \'" << str[3] << "\'; e <= \'" << str[4] << "\'; f <= \'" << str[5] << "\'; g <= \'" << str[6] << "\'; \n";
       write_to_file(str);
   }
}

void random_testpattern(int n)
{
    // srand(time(NULL));
    string str = "";
    for (int i = 0; i < n; i++) {
       int x = ((int)rand() % 2);
       str += to_string(x);
    }
    write_to_file(str);
}

int main(){
    int n;
    cout << "Enter number of input bits : " ;
    cin >> n;
    cout << "Enter : \n" <<
        "1 for Exhaustive Test Pattern Generation \n" << "2 for Random Test Pattern Generation \n";
    int choice;
    cin >> choice;
    if(choice==1){
       exhaustive_testpattern(n);
    }
    else if(choice==2){
        cout << "Enter number of Random Test Patterns to generate \n";
        int count;
        cin >> count ;
        for(int i=0;i<count;i++){
            random_testpattern(n);
        }
    }    
}












