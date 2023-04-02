#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void populateVectors(vector <int>& hours_worked_1, vector <int>& minutes_worked_1, const int num_shifts_1);

void combineHoursAndMinutes(const vector <int>& hours_worked_2, const vector <int>& minutes_worked_2, const int num_shifts_2, int& total_hours_2, int& total_minutes_2);

void displayResults(string employee_name_3, int num_shifts_3, int tota_hours_3, int total_minutes_3);

int main() {
   string employee_name = "change me";
   unsigned int num_shifts = 0;
   vector<int> hours_worked;
   vector<int> minutes_worked;
   int total_hours = -99;
   int total_minutes = -99;

   cout << "Enter employee name:" << endl;
   getline(cin, employee_name);
   cout << "Enter the number of shifts worked by " << employee_name << ":" << endl;
   cin >> num_shifts;
   
   hours_worked.resize(num_shifts);
   minutes_worked.resize(num_shifts);

   populateVectors(hours_worked, minutes_worked, num_shifts);
   
   combineHoursAndMinutes(hours_worked, minutes_worked, num_shifts, total_hours, total_minutes);
   
   displayResults(employee_name, num_shifts, total_hours, total_minutes);

   return 0;
}

void populateVectors(vector <int>& hours_worked_1, vector <int>& minutes_worked_1, const int num_shifts_1) {
   for (int i = 0; i < num_shifts_1; ++i) {
      cout << "Enter hours worked during shift " << (i + 1) << " [no decimal numbers]:" << endl;
      cin >> hours_worked_1.at(i);
      cout << "Enter minutes worked during shift " << (i + 1) << " [no decimal numbers]:" << endl;
      cin >> minutes_worked_1.at(i);
   }
}

void combineHoursAndMinutes(const vector <int>& hours_worked_2, const vector <int>& minutes_worked_2, const int num_shifts_2, int& total_hours_2, int& total_minutes_2) {
   total_hours_2 = 0;
   total_minutes_2 = 0;
   
   for (int i = 0; i < num_shifts_2; ++i) {
      total_hours_2 += hours_worked_2.at(i);
   }
   for (int i = 0; i < num_shifts_2; ++i) {
      total_minutes_2 += minutes_worked_2.at(i);
   }
   total_hours_2 += total_minutes_2 / 60;
   total_minutes_2 %= 60;
}

void displayResults(string employee_name_3, int num_shifts_3, int total_hours_3, int total_minutes_3) {
   cout << fixed << setprecision(2) << employee_name_3 << " worked " << total_hours_3 << " hours and " << total_minutes_3 << " minutes (or " << (total_hours_3 + total_minutes_3 / 60.0) << " hours) over " << num_shifts_3 << " shifts." << endl;
}