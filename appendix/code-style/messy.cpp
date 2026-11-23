// This program works, but it breaks the style rules of the course on purpose.
#include <iostream>
using namespace std;

int Free_Seats(int taken)
{
  constexpr int MAX_SEATS = 40;
  return MAX_SEATS - taken;
}

int main()
{
  int taken;
  taken = 28;
  // print the free seats
  cout << "Free seats: " << Free_Seats(taken) << endl;
  return 0;
}
