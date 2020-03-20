#include<simplecpp>
#include<sstream>
#include<iostream>
#include<fstream>
using namespace std;
main_program
{
int c=-1;//To count how many times input is taken
double sd1=0,sd2=0,sd3=0,realsum=0,usersum=0,syssum=0;
ifstream infile("timestat.txt");//reads the timestat file
while(!infile.eof())
{
string s;
getline(infile,s);//gives complete line
c++;
if(c%4==0)//if it is real time
{
int p,i;
double sum=0;
p=s.length();
for( i=0;i<p;i++)//to get single chars from the string
{
if(s[i]=='.')//searhes for . in the line
{
sum=sum+float((100*(s[i+1]-48))+(10*(s[i+2]-48))+(s[i+3]-48))/1000;//calculates the floating number and adds it to the sum
break;
}
}
realsum=realsum+sum;//adds the floating numbers
}
else
if((c-1)%4==0)//if it is user time
{
int p,i;
double sum=0;
p=s.length();
for( i=0;i<p;i++)
{
if(s[i]=='.')
{
sum=sum+float((100*(s[i+1]-48))+(10*(s[i+2]-48))+(s[i+3]-48))/1000;
break;
}
}
usersum=usersum+sum;
}
else
if((c-2)%4==0)//if it is system time
{
int p,i;
double sum=0;
p=s.length();
for( i=0;i<p;i++)
{
if(s[i]=='.')
{
sum=sum+float((100*(s[i+1]-48))+(10*(s[i+2]-48))+(s[i+3]-48))/1000;
break;
}
}
syssum=syssum+sum;
}
}
int r1;
r1=(c+1)/4;
cout<<r1<<endl;//prints number of times the code was run
cout<<realsum/r1<<" "<<usersum/r1<<" "<<syssum/r1<<endl;//prints the average of 3 times
int d=-1;
//again we want floating number from each line  for standard deviation
ifstream infile1("timestat.txt");//to read the file again
while(!infile1.eof())
{
string s;
getline(infile1,s);
d++;
if(d%4==0)
{
int p,i;
double sum=0,uf;
p=s.length();
for(i=0;i<p;i++)
{
if(s[i]=='.')
{
sum=float((100*(s[i+1]-48))+(10*(s[i+2]-48))+(s[i+3]-48))/1000;//to get the floating number from the line
uf=(sum-(realsum/100))*(sum-(realsum/100));//calculates square of diffrernce from average time
sd1=sd1+uf;//sums this difference
break;
}
}
}
else
if((d-1)%4==0)
{
int p,i;
double sum=0,uf;
p=s.length();
for( i=0;i<p;i++)
{
if(s[i]=='.')
{
sum=float((100*(s[i+1]-48))+(10*(s[i+2]-48))+(s[i+3]-48))/1000;
uf=(sum-(usersum/100))*(sum-(usersum/100));
sd2=sd2+uf;
break;
}
}
}
else
if((d-2)%4==0)
{
int p,i;
double sum=0,uf;
p=s.length();
for( i=0;i<p;i++)
{
if(s[i]=='.')
{
sum=float((100*(s[i+1]-48))+(10*(s[i+2]-48))+(s[i+3]-48))/1000;
uf=(sum-(syssum/100))*(sum-(syssum/100));
sd3=sd3+uf;
break;
}
}
}
}
double t1,t2,t3;
t1=sqrt(sd1/r1);//calculates standard deviation
t2=sqrt(sd2/r1);
t3=sqrt(sd3/r1);
cout<<t1<<" "<<t2<<" "<<t3<<endl;

int j=-1;
double u1,u2;
int u3=0;
u1=(realsum/100)-t1;//average- standard deviation for real time
u2=(realsum/100)+t1;//average+ standard deviation for real time

double v1,v2;
int v3=0;
v1=(usersum/100)-t2;//average- standard deviation for user time
v2=(usersum/100)+t2;//average+ standard deviation for user time
double w1,w2;
int w3=0;
w1=(syssum/100)-t3;//average- standard deviation for system time
w2=(syssum/100)+t3;//average+ standard deviation for system time
ifstream infile2("timestat.txt");
while(!infile2.eof())
{
string s;
getline(infile2,s);
j++;
if(j%4==0)
{
int p,i;
double sum=0;
p=s.length();
for(i=0;i<p;i++)
{
if(s[i]=='.')
{
sum=float((100*(s[i+1]-48))+(10*(s[i+2]-48))+(s[i+3]-48))/1000;//gives the floating number in the line
if(sum>u1&&sum<u2)//checks if the value is in the given range
u3++;//increases the counter
break;
}
}
}
else
if((j-1)%4==0)
{
int p,i;
double sum=0;
p=s.length();
for( i=0;i<p;i++)
{
if(s[i]=='.')
{
sum=float((100*(s[i+1]-48))+(10*(s[i+2]-48))+(s[i+3]-48))/1000;
if(sum>v1&&sum<v2)
v3++;
break;
}
}
}
else
if((j-2)%4==0)
{
int p,i;
double sum=0;
p=s.length();
for( i=0;i<p;i++)
{
if(s[i]=='.')
{
sum=float((100*(s[i+1]-48))+(10*(s[i+2]-48))+(s[i+3]-48))/1000;
if(sum>w1&&sum<w2)
w3++;
break;
}
}
}
}
cout<<u3<<" "<<v3<<" "<<w3;//prints the number of values in the given range
infile.close();
}
