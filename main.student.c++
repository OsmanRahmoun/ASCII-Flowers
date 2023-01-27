/**------------------------------------------
    Program 1: ASCII Flowers
    Prompt for the number of flower layers and display

    Course: CS 141, Fall 2023
    System: Linux_x86_64 and G++
    Author: George Maratos and David Hayes
 ---------------------------------------------**/

#include <iostream>
#include <iomanip>

int pattern = 0;

using namespace std;

// Function to create the spaces for the flower sections and in between the curly braces, the function takes in the number of sections, and runs a for loop to 
// create the spaces

void air_filler(int air)
{
  int space;
  space = (air - 1);
  for (space; space > 0; space--)
  {
    cout << " ";
  }
}

// Function to create the ASCII flower, it takes in the number of sections (flower heads) the user wants, and produces the flower.

void flower_maker(int sections)
{
  for (int index = 0; index < sections - 1; index++)
  {
    for (int heads = 0, decrease = 0, increase = 4, test_decrease = 1, colons_counter = 3; heads < index + 1; heads++, decrease++, increase += 2, test_decrease++, colons_counter++)
    {
        // Increases the space between the curly braces, decreases the space on the left
      air_filler(sections - decrease);
      cout << "{" << setw(increase) << right << setfill(':') << "}" << endl;
        // checks when inner loop ran as many times as the outer loop, used to produce the main part of the section
      if (heads == index)
      {
        air_filler(sections - (decrease + 1));
        cout << "{" << setw(colons_counter) << right << setfill(':') << "@" << setw(colons_counter) << right << setfill(':') << "}" << endl;
        for (int counter = heads + 1, reverse_decrease = decrease, reverse_increase = increase; counter > 0; counter--, reverse_increase -= 2, reverse_decrease--)
        {
            // Creates the bottom half of the section after creating the main section
          air_filler(sections - (reverse_decrease));
          cout << "{" << setw(reverse_increase) << right << setfill(':') << "}" << endl;
        }
      }
    }
    air_filler(sections + 1);
    cout << "---" << endl;
  }
}

// This function is used to create the stem of the ASCII Flower, it takes in the number of sections to determine the length of the flower, and uses the length to 
// create an alternating pattern within the stem
void stem_maker(int sections)
{
  for (int length = sections * 2, count = 1; length > 0; length--, count++)
  {
    if (count % 2 != 0)
    {
      if (pattern % 2 == 0)
      {
        air_filler(sections + 2);
        cout << "|/" << endl;
        pattern++;
      }
      else
      {
        air_filler(sections + 1);
        cout << "\\"
             << "|" << endl;
        pattern++;
      }
    }
    else
    {
      air_filler(sections + 2);
      cout << "|" << endl;
    }
  }
}

int main()
{
  // display the prompt to the user
  cout << "Program 1: ASCII Flowers\n"
       << "Choose from the following options:\n"
       << "   1. Display the HELLO graphic\n"
       << "   2. Display The Flower\n"
       << "   3. Exit the program\n"
       << "Your choice -> ";

  // read in the user's choice
  int menu_option;
  cin >> menu_option;

  // handle option to quit
  if (menu_option == 3)
  {
    exit(0);
  }

  // handle the HELLO graphic choice
  if (menu_option == 1)
  {
    char frame;
    cout << "Enter your frame character: ";
    cin >> frame;
    // top border
    cout << endl;
    for (int i = 0; i < 2; i++)
    {
      cout << setfill(frame) << setw(36) << ' ' << endl;
    }
    // message
    cout << setfill(frame) << setw(3) << right << " "
         << "** ** ***** **    **    *****"
         << setfill(frame) << setw(3) << left << " " << endl
         << setfill(frame) << setw(3) << right << " "
         << "** ** ***** **    **    *****"
         << setfill(frame) << setw(3) << left << " " << endl
         << setfill(frame) << setw(3) << right << " "
         << "** ** **    **    **    ** **"
         << setfill(frame) << setw(3) << left << " " << endl
         << setfill(frame) << setw(3) << right << " "
         << "***** ***** **    **    ** **"
         << setfill(frame) << setw(3) << left << " " << endl
         << setfill(frame) << setw(3) << right << " "
         << "***** ***** **    **    ** **"
         << setfill(frame) << setw(3) << left << " " << endl
         << setfill(frame) << setw(3) << right << " "
         << "** ** **    **    **    ** **"
         << setfill(frame) << setw(3) << left << " " << endl
         << setfill(frame) << setw(3) << right << " "
         << "** ** ***** ***** ***** *****"
         << setfill(frame) << setw(3) << left << " " << endl
         << setfill(frame) << setw(3) << right << " "
         << "** ** ***** ***** ***** *****"
         << setfill(frame) << setw(3) << left << " " << endl
         << right;
    // bottom border
    for (int i = 0; i < 2; i++)
    {
      cout << setfill(frame) << setw(36) << " " << endl;
    }
  }

  // handle the floral pattern TODO for students
  if (menu_option == 2)
  {
    cout << "Enter number of sections: " << endl;
    int sections;
    cin >> sections;
    air_filler(sections + 1);
    cout << "---" << endl;
    air_filler(sections);
    cout << "{:@:}" << endl;
    air_filler(sections + 1);
    cout << "---" << endl;

    if (sections > 1)
    {
      flower_maker(sections);
    }

    stem_maker(sections);
  }
  return 0;
}
