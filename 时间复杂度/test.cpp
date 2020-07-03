#include <iostream>

int main(){
    std::string str="hello";
    int *p=(int *)&str;
    char a[]="abc";
    char *p1=a;
    std::cout<<str<<p<<p1<<std::endl;
    return 0;
}
