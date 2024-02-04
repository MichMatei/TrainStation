#define _CRT_SECURE_NO_WARNINGS //I tried using the strcpy_s and strtok_s but then it would error out... but when I didn't used _s and disabled warnings it worked fine
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

//check to see if the string can be a number and != 0
bool isNumber(string s) 
{
    if (s.size() == 0)
    {
        return false;
    }

    for (int i = 0; i < s.size(); i++) 
    {
        if ((s[i] >= '0' && s[i] <= '9') == false) 
        {
            return false;
        }
    }

    if (s == "0")
    {
        return false;
    }

    return true;
}

struct TrainLines
{
    int i = 0;
    int j = 0;
    int n = 0;
    char* piece = 0;
    char s[12][14] = {'\0'};
};


int main()
{
    TrainLines firstLine;
    TrainLines secondLine;
    TrainLines thirdLine;

    //boolean variable that will be set to true if the file is opened.
    bool fileOpened = false;

    char sep[] = " .,/?!#$%^*()*@";

    ifstream fin("C:/Users/matei/source/repos/TrainStation C++/TrainStation C++/stations.txt");//please change the file path to be the right one for your computer
    string name = "";

    //char var with which i will read from the file
    char file[4][105];
    int j = 0;
    int m = 0;

    if (fin)//when coding the app, the file opened corectly, so make sure to update the location if it doesn't open
    {
        //At the end, because this is true, changes made, will be outputed to the file.
        fileOpened = true;

        //reading the content of the file line by line
        while (fin.getline(file[j], 650))
        {
            j++;
            m++;
        }

        cout << "You must be the train station controller. Please enter your name: ";
        cin >> name;
        cout << endl;
        cout << "You should first take a look at the train lines before anything else so you knwo what you are dealing with..." << endl;
        cout << "In order to do that, " << name << ", you need to press P" << endl;

        string input = "";
        bool loop = true;
        while (loop)
        {
            cin >> input;
            if (input == "P" || input == "p")
            {
                cout << endl << "These are the train lines\n" << endl;

                //outputing to the console the content of the char variable that holds the stations line by line
                for (j = 0; j < m; j++)
                {
                    cout << file[j] << endl;
                }

                cout << endl;

                //tokenizing each line of the char variable into three structs, one for each line

                firstLine.piece = strtok(file[0], sep);
                while (firstLine.piece != NULL)
                {
                    strcpy(firstLine.s[firstLine.i], firstLine.piece);
                    firstLine.i++;
                    firstLine.n++;
                    firstLine.piece = strtok(NULL, sep);
                }

                secondLine.piece = strtok(file[1], sep);
                while (secondLine.piece != NULL)
                {
                    strcpy(secondLine.s[secondLine.i], secondLine.piece);
                    secondLine.i++;
                    secondLine.n++;
                    secondLine.piece = strtok(NULL, sep);
                }

                thirdLine.piece = strtok(file[2], sep);
                while (thirdLine.piece != NULL)
                {
                    strcpy(thirdLine.s[thirdLine.i], thirdLine.piece);
                    thirdLine.i++;
                    thirdLine.n++;
                    thirdLine.piece = strtok(NULL, sep);
                }
                loop = false;
            }
            else
            {
                cout << "You need to take a look at the stations before working with them! Please press P " << name << endl;
            }
        }
        loop = true;

        while (loop)
        {
            cout << "\nThese are the controls:\n";
            cout << "P to see the train lines, A to change a station's name, ADD to add a station, EXIT to exit the program\n";
            cin >> input;
            
            //when the user enter P, it will display each train line (by now, they are tokenized)
            if (input == "P" || input == "p")
            {
                cout << endl << "These are the train lines" << endl;
                
                for (firstLine.i = 0; firstLine.i < firstLine.n; firstLine.i++)
                {
                    cout << firstLine.s[firstLine.i] << " ";
                }
                cout << endl;

                for (secondLine.i = 0; secondLine.i < secondLine.n; secondLine.i++)
                {
                    cout << secondLine.s[secondLine.i] << " ";
                }
                cout << endl;

                for (thirdLine.i = 0; thirdLine.i < thirdLine.n; thirdLine.i++)
                {
                    cout << thirdLine.s[thirdLine.i] << " ";
                }
                cout << endl;
            }
            else if (input == "A" || input == "a")
            {
                char newName[1][15];
                cout << "Please enter the train line on which the station you want to amend is...\n";
                string lineNumber = "";
                bool loop = true;
                
                while (loop)
                {
                    //asking for the line where the station is
                    cin >> lineNumber; 

                    if (lineNumber == "1")
                    {
                        cout << "\nThese are the stations on this line. Please enter the number of the station you want to change\n";
                        for (firstLine.i = 0; firstLine.i < firstLine.n; firstLine.i++)
                        {
                            cout << firstLine.s[firstLine.i] << " ";
                        }
                        cout << endl;

                        int stationNumber = 0;
                        cin >> stationNumber;//enters the number of the coressponding station

                        //if there is a station on that position, it will copy the input into that position
                        if (stationNumber >= 0 && stationNumber <= firstLine.n)
                        {
                            cout << "\nEnter the new name for the station\n";
                            cin >> newName[0];

                            strcpy(firstLine.s[stationNumber - 1], newName[0]);
                            cout << "\nStation has been amended\n";
                        }
                        else
                        {
                            cout << "\nThere is no station on that position...\n";
                        }

                        loop = false;
                    }
                    else if (lineNumber == "2")
                    {
                        cout << "\nThese are the stations on this line. Please enter the number of the station you want to change\n";
                        for (secondLine.i = 0; secondLine.i < secondLine.n; secondLine.i++)
                        {
                            cout << secondLine.s[secondLine.i] << " ";
                        }
                        cout << endl;

                        int stationNumber = 0;
                        cin >> stationNumber;

                        if (stationNumber >= 0 && stationNumber <= secondLine.n)
                        {
                            cout << "\nEnter the new name for the station\n";
                            cin >> newName[0];

                            strcpy(secondLine.s[stationNumber - 1], newName[0]);
                            cout << "\nStation has been amended\n";
                        }
                        else
                        {
                            cout << "\nThere is no station on that position...\n";
                        }
                        loop = false;
                    }
                    else if (lineNumber == "3")
                    {
                        cout << "\nThese are the stations on this line. Please enter the number of the station you want to change\n";
                        for (thirdLine.i = 0; thirdLine.i < thirdLine.n; thirdLine.i++)
                        {
                            cout << thirdLine.s[thirdLine.i] << " ";
                        }
                        cout << endl;

                        int stationNumber = 0;
                        cin >> stationNumber;

                        if (stationNumber >= 0 && stationNumber <= thirdLine.n)
                        {
                            cout << "\nEnter the new name for the station\n";
                            cin >> newName[0];

                            strcpy(thirdLine.s[stationNumber - 1], newName[0]);
                            cout << "\nStation has been amended\n";
                        }
                        else
                        {
                            cout << "\nThere is no station on that position...\n";
                        }
                        loop = false;
                    }
                    else
                    {
                        cout << "That number doesn't coresspond to any of the lines...\nPlease enter a number from 1 to 3\n";
                    }
                }
                
            }
            else if (input == "ADD" || input == "Add" || input == "add")
            {
                string lineNumber = "";
                char newStation[1][15];           
                bool loop = true;

                while (loop)
                {
                    cout << "\nEnter the number of the line you want to add a new station\n";
                    cin >> lineNumber;//asks for the line where to add the new station

                    //if there is a line with that number
                    if (lineNumber == "1")
                    {
                        //displays the content of that line
                        cout << "\nThese are the stations on this line.\n";
                        for (firstLine.i = 0; firstLine.i < firstLine.n; firstLine.i++)
                        {
                            cout << firstLine.s[firstLine.i] << " ";
                        }
                        cout << endl;

                        bool smallLoop = true;

                        while (smallLoop)
                        {
                            cout << "\nEnter the number of the place you want your new station to be added at\n";
                            string place = "";
                            cin >> place;//asks for a string input but the user has to enter an integer

                            int placeInt = 0;
                            //if the string entered is an integer then placeInt takes the value of the string using stoi()
                            if (isNumber(place))
                            {
                                int placeInt = stoi(place);

                                cout << "\nEnter the name of the new station\n";
                                cin >> newStation[0];

                                //increase the vector size and add the new station at the end of the line
                                firstLine.n++;
                                for (firstLine.i = 0; firstLine.i < firstLine.n; firstLine.i++)
                                {
                                    if (firstLine.i == firstLine.n - 1)
                                    {
                                        strcpy(firstLine.s[firstLine.i], newStation[0]);
                                    }
                                }

                                //moves the newly added station from the end of the line to the user's desired place
                                for (firstLine.i = firstLine.n - 1; firstLine.i > placeInt - 1; firstLine.i--)
                                {
                                    swap(firstLine.s[firstLine.i], firstLine.s[firstLine.i - 1]);
                                }

                                loop = false;
                                smallLoop = false;
                            }
                            else
                            {
                                cout << "Invalid number";
                            }
                        }                      
                    }
                    else if (lineNumber == "2")
                    {
                        cout << "\nThese are the stations on this line.\n";
                        for (secondLine.i = 0; secondLine.i < secondLine.n; secondLine.i++)
                        {
                            cout << secondLine.s[secondLine.i] << " ";
                        }
                        cout << endl;

                        bool smallLoop = true;

                        while (smallLoop)
                        {
                            cout << "\nEnter the number of the place you want your new station to be added at\n";
                            string place = "";
                            cin >> place;

                            int placeInt = 0;

                            if (isNumber(place))
                            {
                                int placeInt = stoi(place);

                                cout << "\nEnter the name of the new station\n";
                                cin >> newStation[0];

                                secondLine.n++;
                                for (secondLine.i = 0; secondLine.i < secondLine.n; secondLine.i++)
                                {
                                    if (secondLine.i == secondLine.n - 1)
                                    {
                                        strcpy(secondLine.s[secondLine.i], newStation[0]);
                                    }
                                }

                                for (secondLine.i = secondLine.n - 1; secondLine.i > placeInt - 1; secondLine.i--)
                                {
                                    swap(secondLine.s[secondLine.i], secondLine.s[secondLine.i - 1]);
                                }

                                loop = false;
                                smallLoop = false;
                            }
                            else
                            {
                                cout << "Invalid number";
                            }
                        }
                    }
                    else if (lineNumber == "3")
                    {
                        cout << "\nThese are the stations on this line.\n";
                        for (thirdLine.i = 0; thirdLine.i < thirdLine.n; thirdLine.i++)
                        {
                            cout << thirdLine.s[thirdLine.i] << " ";
                        }
                        cout << endl;

                        bool smallLoop = true;

                        while (smallLoop)
                        {
                            cout << "\nEnter the number of the place you want your new station to be added at\n";
                            string place = "";
                            cin >> place;

                            int placeInt = 0;

                            if (isNumber(place))
                            {
                                int placeInt = stoi(place);

                                cout << "\nEnter the name of the new station\n";
                                cin >> newStation[0];

                                thirdLine.n++;
                                for (thirdLine.i = 0; thirdLine.i < thirdLine.n; thirdLine.i++)
                                {
                                    if (thirdLine.i == thirdLine.n - 1)
                                    {
                                        strcpy(thirdLine.s[thirdLine.i], newStation[0]);
                                    }
                                }

                                for (thirdLine.i = thirdLine.n - 1; thirdLine.i > placeInt - 1; thirdLine.i--)
                                {
                                    swap(thirdLine.s[thirdLine.i], thirdLine.s[thirdLine.i - 1]);
                                }

                                loop = false;
                                smallLoop = false;
                            }
                            else
                            {
                                cout << "Invalid number";
                            }
                        }
                    }
                    else
                    {
                        cout << "\nThat are no station lines with that number... Please enter a number from 1 to 3\n";
                    }
                }
                cout << "\nStation has been added. Press P if you want to check that it has gone through as intended.\n";
            }

            if (input == "Exit" || input == "EXIT" || input == "exit")
            {
                cout << "\nYour work has been saved into the text file. Hope we see you again!\n";
                loop = false;

                fin.close();
            }
        }
    }
    else
    {
        cout << "A problem occured when trying to open the files. Please check the name of the files or their location.";
    }

    //if the file was opened then output the changes made, to the file
    if (fileOpened == true)
    {
        ofstream fo("stations.txt");

        for (firstLine.i = 0; firstLine.i < firstLine.n; firstLine.i++)
        {
            if (firstLine.i == firstLine.n - 1)
            {
                fo << firstLine.s[firstLine.i];
            }
            else
            {
                fo << firstLine.s[firstLine.i] << " ";
            }
        }
        fo << endl;
        for (secondLine.i = 0; secondLine.i < secondLine.n; secondLine.i++)
        {
            if (secondLine.i == secondLine.n - 1)
            {
                fo << secondLine.s[secondLine.i];
            }
            else
            {
                fo << secondLine.s[secondLine.i] << " ";
            }
        }
        fo << endl;
        for (thirdLine.i = 0; thirdLine.i < thirdLine.n; thirdLine.i++)
        {
            if (thirdLine.i == thirdLine.n - 1)
            {
                fo << thirdLine.s[thirdLine.i];
            }
            else
            {
                fo << thirdLine.s[thirdLine.i] << " ";
            }
        }

        fo.close();
    }
    cin.get();
    return 0;
}

//The contents of the original files station in case they are needed after outputing something new

/*Edinburgh NewCastle Leeds London
NewCastle Liverpool Cardiff Bristol
Bagor Cardiff Bristol London
*/