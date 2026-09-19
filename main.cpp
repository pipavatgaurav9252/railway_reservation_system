#include <iostream>
#include <string>

using namespace std;

class Train
{
private:
    int train_number;
    string train_name, train_source, train_distination, train_time;

    static int train_count;

public:
    Train()
    {
        train_number = 0;
        train_name = "";
        train_source = "";
        train_distination = "";
        train_time = "";

        train_count++;
    }
    Train(int number, string name, string source, string distination, string time)
    {
        train_number = number;
        train_name = name;
        train_source = source;
        train_distination = distination;
        train_time = time;

        train_count++;
    }
    ~Train()
    {
        train_count--;
    }
    void set_train_number(int number)
    {
        train_number = number;
    }
    void set_train_name(string name)
    {
        train_name = name;
    }
    void set_train_source(string source)
    {
        train_source = source;
    }
    void set_train_distination(string distination)
    {
        train_distination = distination;
    }
    void set_train_time(string time)
    {
        train_time = time;
    }

    int get_train_number()
    {
        return train_number;
    }
    string get_train_name()
    {
        return train_name;
    }
    string get_train_source()
    {
        return train_source;
    }
    string get_train_distination()
    {
        return train_distination;
    }
    string get_train_time()
    {
        return train_time;
    }
    void inputTraindetails()
    {
        cout << "Enter train number: ";
        cin >> train_number;

        cin.ignore();

        cout << "Enter train name: ";
        getline(cin, train_name);

        cout << "Enter train source: ";
        getline(cin, train_source);

        cout << "Enter train distination: ";
        getline(cin, train_distination);

        cout << "Enter train time: ";
        getline(cin, train_time);
    }
    void displayTraindetails()
    {
        cout << " the train number is: " << train_number << endl;
        cout << " the train name is: " << train_name << endl;
        cout << " the train source is: " << train_source << endl;
        cout << " the train distination is: " << train_distination << endl;
        cout << " the train time is : " << train_time << endl;
    }

    int static get_train_count()
    {
        return train_count;
    }
};

int Train::train_count = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int total_trains = 0;

public:
    RailwaySystem()
    {
        cout << "===Enter details for 1 trains:===" << endl;
        trains[0].inputTraindetails();
        cout << endl;
        cout << "===Enter details for 2 trains:===" << endl;
        trains[1].inputTraindetails();
        cout << endl;
        cout << "===Enter details for 3 trains:===" << endl;
        trains[2].inputTraindetails();
        cout << endl;
        total_trains = 3;
    }
    void addTrain()
    {
        trains[total_trains].inputTraindetails();
        total_trains++;
    }
    void displayAllTrains()
    {
        if (total_trains == 0)
        {
            cout << "No train records found." << endl;
            return;
        }
        for (int i = 0; i < total_trains; i++)
        {
            trains[i].displayTraindetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        if (total_trains == 0)
        {
            cout << "No train records found." << endl;
            return;
        }

        for (int i = 0; i < total_trains; i++)
        {
            if (trains[i].get_train_number() == number)
            {
                trains[i].displayTraindetails();
                return;
            }
        }
        cout << "train number not matched" << endl;
    }
};

int main()
{

    RailwaySystem railway;
    int choice;

    do
    {
        cout << "\n===== Railway Reservation System =====" << endl;
        cout << "1. Add new train record" << endl;
        cout << "2. Display all train records" << endl;
        cout << "3. Search train by number" << endl;
        cout << "4. Exit program" << endl;

        cout << "\nEnter your choice between (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "===Add new train record ===" << endl;
            railway.addTrain();

            break;

        case 2:
            cout << "=== Display all train records ===" << endl;
            railway.displayAllTrains();
            break;
        case 3:
            cout << "=== Search train by number ===" << endl;
            int number;
            cout << "Enter a train number: ";
            cin >> number;
            railway.searchTrainByNumber(number);
            break;

        case 4:
            cout << "Exiting...Goodbye!" << endl;

        default:
            cout << "Invalid input." << endl;
        }
    } while (choice != 4);

    return 0;
}