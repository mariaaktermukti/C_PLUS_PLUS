#include<bits/stdc++.h>
using namespace std;

class Student
{
    public:
    string name;
    int roll;
    int marks;

};

bool cmp(Student l,Student r)
{
    if(l.marks < r.marks)   //ami jei order e chai oita 1st e thakbe
    {
        return true;
    }
    else if(l.marks < r.marks)
    {
        return false;
    }
    else{
        if(l.roll < r.roll)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // return l.marks < r.marks;

}

int main()
{
    int n;
    cin>> n;
    Student a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].name >> a[i].roll >> a[i].marks;
    }
    sort(a,a+n,cmp);
      for(int i=0;i<n;i++)
    {
        cout<<a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }

    return 0;
}