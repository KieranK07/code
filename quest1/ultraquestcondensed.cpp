#include<iostream>
int main(){
double m;std::cin>>m;int c=m*100;
std::cout<<c<<" cents\nx"<<c/10000<<" $100 bills, x"<<(c%=10000)/2000<<" $20 bills, x"<<(c%=2000)/1000<<" $10 bills, x"<<(c%=1000)/500<<" $5 bills, x"<<(c%=500)/100<<" $1 bills, x"<<(c%=100)/25<<" quarters, x"<<(c%=25)/10<<" dimes, x"<<(c%=10)/5<<" nickels, x"<<(c%=5)<<" pennies.\n";
}
