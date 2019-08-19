#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

 struct speaker
{
    string name;
    string phone;
    string topic;
    int fee;
};

void edit(speaker data[]);
void editName(speaker [], int); //3
void editPhone(speaker [], int);//3
void editTopic(speaker [], int);//3
void editFee(speaker [], int);//3
void printList(speaker []);//1
speaker enterData(speaker[]);//2
speaker searchName(speaker []); //5
speaker searchTopic(speaker []); //4
speaker searchFee(speaker []); //6
void printSpeaker(speaker [], int);

int counter = 0;

int main()
{
    int SIZE = 10;
    int choice;
    speaker data[SIZE];
    do
    {
    cout << "Welcome to Speaker Search!" << endl;
    cout << "Enter 1 to view all speaker information." << endl;
    cout << "Enter 2 to enter new speaker information." << endl;
    cout << "Enter 3 to edit speaker information." << endl;
    cout << "Enter 4 to search speakers by topic." << endl;
    cout << "Enter 5 to search speakers by name." << endl;
    cout << "Enter 6 to search speakers by fee required." << endl;
    cin >> choice;
    while (choice < 1 || choice > 6)
    {
    cout << "Invalid option" << endl;
    cout << "Welcome to Speaker Search!" << endl;
    cout << "Enter 1 to view all speaker information." << endl;
    cout << "Enter 2 to enter new speaker information." << endl;
    cout << "Enter 3 to edit speaker information." << endl;
    cout << "Enter 4 to search speakers by topic." << endl;
    cout << "Enter 5 to search speakers by name." << endl;
    cout << "Enter 6 to search speakers by fee required." << endl;
    cin >> choice;
    }
    if(choice == 1)
    {
        if(counter == 0)
        {
            cout << "There's no data." << endl;
        }
        else
        {
        printList(data);
        }
    }
    if(choice == 2)
    {
         enterData(data);
    }
    if(choice == 3)
    {
        if(counter == 0)
        {
            cout << "No entries available." << endl;
            cout << "Please enter a speaker" << endl;
        }
        else if (choice > 0 || choice < 6)
        {
            edit(data);
        }
    } //3
    if(choice == 4)
    {
         if(counter == 0)
        {
            searchTopic(data);
        }
    }
    if(choice == 5)
    {
         if(counter == 0)
        {
          searchName(data);
        }
    }
    if(choice == 6)
    {
         if(counter == 0)
        {
            searchFee(data);
        }
    }
    } while (choice);

   return 0;
}

void printList(speaker data[])//1
{
    for(int i = 0; i < counter; i++)
    {
        cout << "Speaker Number " << (i + 1) << " " << data[i].name;
        cout << " Phone Number: " << data[i].phone;
        cout << " Topic: " << data[i].topic;
        cout << " Fee: $" << data[i].fee << endl;


    }
}

speaker enterData(speaker data[]) //2
{
    speaker keepData;
    if (counter < 10)
    {
        cout << "Enter speaker name:" << endl;
        cin.ignore();
        getline(cin, keepData.name);

    while(keepData.name.length() == 0)
    {
        cout << "Name can not be empty!" << endl;
        getline(cin, keepData.name);
    }
     cout << "Enter speaker's phone number:" << endl;
    getline(cin,keepData.phone);
    while(keepData.phone.length() == 0)
    {
        cout << "Phone number can not be empty!" << endl;
        getline(cin,keepData.phone);
    }
     cout << "Enter speaker's topic:" << endl;
    getline(cin, keepData.topic);
    while(keepData.topic.length() == 0)
    {
        cout << "Topic can not be empty!" << endl;
        getline(cin, keepData.topic);
    }
    cout << "Enter the speaker's fee:" << endl;
    cin >> keepData.fee;
    //getline(cin,keepData.phone);
    while(keepData.fee < 0)
    {
         cout << "Speaker's fee can not be less than 0!";
        cin >> keepData.fee;

    }
        data[counter].name = keepData.name;
        data[counter].phone = keepData.phone;
        data[counter].topic = keepData.topic;
        data[counter].fee = keepData.fee;
        counter++;
    }
    else
    {
        cout << "Reached max number of speakers!" << endl;
    }
    return data[counter];
}


void editName(speaker data[], int sNum)//3
{
    speaker save;
    cout << "Enter new name:" << endl;
    cin.ignore();
    getline(cin, save.name);
    while(save.name.length() == 0)
    {
        cout << "Name can not be empty!" << endl;
        getline(cin,save.name);
    }
    data[sNum - 1].name = save.name;
}

void editPhone(speaker data[], int sNum) //3
{
    speaker save;
    cout << "Enter new phone number:" << endl;
    getline(cin, save.phone);
    while (save.phone.length() == 0)
    {
        cout << "Phone number can not be empty!" << endl;
        getline(cin,save.phone);
    }
    data[sNum - 1].phone = save.phone;
}

void editTopic(speaker data[], int sNum) //3
{
    speaker save;
    cout << "Enter new topic:" << endl;
    getline(cin, save.topic);
    while (save.topic.length() == 0){
        cout << "Topic can not be empty!" << endl;
        cin.ignore();
        getline(cin, save.topic);
    }
    data[sNum - 1].topic = save.topic;
}

void editFee(speaker data[], int sNum) //3
{
    speaker save;
    cout << "Enter new fee: ";
    cin >> save.fee;
    cin.ignore();
    while (save.fee < 0)
    {
        cout << "Fee can not be less than $0!" << endl;
        cin >> save.fee;
    }
    data[sNum - 1].fee = save.fee;
}

speaker searchName(speaker data[]) //4
{

    string searching;
    int i = 0, itfound;
    bool found = true;
    cout << "Enter a speaker to search:" << endl;
    getline(cin,searching);
    while (searching.length() == 0)
    {
        cout << "Name to search can not be empty!" << endl;
        getline(cin,searching);
    }
    while (found && i < counter)
    {
        if(searching.compare(data[i].name))
        {
            itfound = i;
            printSpeaker(data,(i+1));
        }
        else
        {
            found = false;
            cout << "Speaker could not be found!" << endl;
        }
    }
        i++;
        return data[itfound];
}

void edit(speaker data[])
{
    int choice = 0;
    int sNum;
    printList(data);
    cout << "Enter number of speaker you wish to edit:" << endl;
    cin >> sNum;
    cin.ignore();
    while (sNum <= 0)
    {
        cout << "Invalid speaker number entered.";
        cin >> sNum;
        cin.ignore();
    }
    printSpeaker(data, sNum);
    cout << "Enter 1 to edit the speaker's name:" << endl;
    cout << "Enter 2 to edit the speaker's phone number:" << endl;
    cout << "Enter 3 to edit the speaker's topic:" << endl;
    cout << "Enter 4 to edit the speaker's fee required:" << endl;
    cin >> choice;
    cin.ignore();
    while (choice < 1 || choice > 4) {
        cout << "Invalid option" << endl;
        cin >> choice;
        cin.ignore();
    }
    if (choice == 1){
        editName(data,sNum);
    }
    else if (choice == 2)
    {
        editPhone(data, sNum);
    }
    else if (choice == 3){
        editTopic(data, sNum);
    }
    else if (choice == 4){
        editFee(data,sNum);
    }
}




speaker searchTopic(speaker data[])//4
{
    string searching;
    int i = 0, itfound;
    bool found = true;
    cout << "Enter a topic to search:" << endl;
    getline(cin,searching);
    while (searching.length() == 0)
    {
        cout << "Topic to search can not be empty!" << endl;
        getline(cin,searching);
    }
    while (found && i < counter)
    {
        if(searching.compare(data[i].topic))
        {
            itfound = i;
            printSpeaker(data,(i+1));
        }
        else
        {
            found = false;
            cout << "Topic could not be found!" << endl;

        }
           i++;
    }

    return data[itfound];

}

speaker searchFee(speaker data[])
{
    double searching;
    int i = 0, itfound;
    bool found = true;
    cout << "Enter a fee to search:" << endl;
    cin >> searching;
    cin.ignore();
    while (searching <= 0)
    {
        cout << "Fee can not be less than 0!" << endl;
        cin >> searching;
    }
    while (found && i < counter){
        if(searching == data[i].fee){
            itfound = i;
            printSpeaker(data,(i+1));
        }
        else{
            found = false;
            cout << "Fee could not be found!" << endl;
        }
        i++;
    }
    return data[itfound];
}

void printSpeaker(speaker data[], int s)
{
    int i = s - 1;
    cout << "Speaker Number " << (i + 1) << " " << data[i].name;
    cout << " Phone number: " << data[i].phone;
    cout << " Topic: " << data[i].topic;
    cout << " Fee: " << data[i].fee << endl;

}
