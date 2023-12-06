#include <iostream>
using namespace std;

bool isStudentGraduating(int takenExams, bool isAdminHappy, bool isPayingOnTime, bool hasPaidNow) 
{
	if (takenExams >= 4) 
	{
		return true;
	}
	else if (takenExams == 3 && isAdminHappy) 
	{
		return true;
	}
	else if (takenExams == 2 && isAdminHappy && isPayingOnTime) 
	{
		return true;
	}
	else if (takenExams == 2 && isAdminHappy && isPayingOnTime) 
	{
		return true;
	}
	else if (isAdminHappy && isPayingOnTime && hasPaidNow) 
	{
		return true;
	}
	return false;

}
void printCourseConclusion(int takenExams, bool isAdminHappy, bool isPayingOnTime, bool hasPaidNow) 
{
	if (isStudentGraduating(takenExams, isAdminHappy, isPayingOnTime, hasPaidNow)) 
	{
		cout << "Good job, you passed!";
		return;
	}
	cout << "September is a fun month!";
}
int main()
{

}