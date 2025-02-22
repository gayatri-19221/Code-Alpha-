#include<iostream>
using namespace std;

int main()
{    
    int numsemesters;
    float totalcredits = 0, totalgradepoints = 0;
    
    cout << "Enter your semesters: ";
    cin >> numsemesters;
    
    for(int s = 1; s <= numsemesters; s++)
    {
        int numcourses;
        cout << "Enter number of courses for semester " << s << ": ";
        cin >> numcourses;
        
        for(int i = 1; i <= numcourses; i++)  
        {
            int credits;
            char grade;  
            cout << "Enter credits and grades (A-F) for course " <<  i << ": ";
            cin >> credits >> grade;
            
            
            grade = toupper(grade);
            
            float points;
            if (grade == 'A') points = 10;
            else if (grade == 'B') points = 8;
            else if (grade == 'C') points = 6;
            else if (grade == 'D') points = 4;
            else if (grade == 'E') points = 2;
            else points = 0;

            totalcredits += credits;
            totalgradepoints += points * credits;
        }
    }

    
    if (totalcredits > 0)
        cout << "CGPA: " << totalgradepoints / totalcredits << endl;
    else
        cout << "No courses taken, CGPA cannot be calculated." << endl;

    return 0;
}

