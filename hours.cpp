#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getNameAndNumShifts(string& employee_name_0, unsigned int& num_shifts_0);

void populateVectors(vector <int>& hours_worked_1, vector <int>& minutes_worked_1, const int num_shifts_1);

void combineHoursAndMinutes(const vector <int>& hours_worked_2, const vector <int>& minutes_worked_2, const int num_shifts_2, int& total_hours_2, int& total_minutes_2);

void displayResults(string employee_name_3, int num_shifts_3, int tota_hours_3, int total_minutes_3);

// void holdResultsOnScreen();

int main() {
   string employee_name = "change me";
   unsigned int num_shifts = 0;
   vector<int> hours_worked(0);
   vector<int> minutes_worked(0);
   int total_hours = -99;
   int total_minutes = -99;

   getNameAndNumShifts(employee_name, num_shifts);
   
   hours_worked.resize(num_shifts);
   minutes_worked.resize(num_shifts);

   populateVectors(hours_worked, minutes_worked, num_shifts);
   
   combineHoursAndMinutes(hours_worked, minutes_worked, num_shifts, total_hours, total_minutes);
   
   displayResults(employee_name, num_shifts, total_hours, total_minutes);

   // holdResultsOnScreen();
   
   return 0;
}

void getNameAndNumShifts(string& employee_name_0, unsigned int& num_shifts_0) {
   int temp_input_0 = -1;

   cout << "Enter employee name:" << endl;
   getline(cin, employee_name_0);
   cout << "Enter the number of shifts worked by " << employee_name_0 << " [whole numbers only]:" << endl;
   cin >> temp_input_0;

   while (temp_input_0 < 0) {
      cout << "Invalid input. Please try again:" << endl;
      cin >> temp_input_0;
   }
   num_shifts_0 = temp_input_0;
}

void populateVectors(vector <int>& hours_worked_1, vector <int>& minutes_worked_1, const int num_shifts_1) {
   int temp_hours = 0;
   int temp_minutes = 0;

   for (int i = 0; i < num_shifts_1; ++i) {
      cout << "Current hours: " << temp_hours << " | Current minutes: " << temp_minutes << endl;
      cout << "Enter hours worked during shift " << (i + 1) << " [whole numbers only]:" << endl;
      cin >> hours_worked_1.at(i);
      cout << "Enter minutes worked during shift " << (i + 1) << " [whole numbers only]:" << endl;
      cin >> minutes_worked_1.at(i);

      temp_hours += hours_worked_1.at(i);
      temp_minutes += minutes_worked_1.at(i);
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

   cout << employee_name_3 << " worked " << total_hours_3 << " hours and " << total_minutes_3 << " minutes over " << num_shifts_3 << " shifts." << endl;
   cout << "Record your results and refresh the page to start over." << endl;
}

/* void holdResultsOnScreen() {
   char quit_char = 'x';

   while (quit_char != 'q') {
      cout << "Record your results and refresh the page to start over. Enter q to quit." << endl;
      cin >> quit_char;
   }

} */
