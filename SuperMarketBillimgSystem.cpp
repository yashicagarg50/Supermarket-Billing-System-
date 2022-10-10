#include<iostream>
#include<fstream> // this is for providing the capability of reading, creating and writing a file . supports simulataneous input and output operations on file

using namespace std;
class shopping
{
    private: // this specifier cannnot be accessed from outside of this class
        int pcode;
        float price;
        float dis;
        string pname;

    public: // this specifier we can access from out of this class 
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};

void shopping  :: menu() // the :: (scope resolution operator here is used to define the function outside the class)
{
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t\t___________________________\n";
    cout << "\t\t\t\t\t                           \n";
    cout << "\t\t\t\t\t   Supermarket Main Menu      \n";
    cout << "\t\t\t\t\t___________________________\n";
    cout << "\t\t\t\t\t                           \n";
    cout << "\t\t\t\t\t| 1) Administrator |\n";
    cout << "\t\t\t\t\t|                  |\n";
    cout << "\t\t\t\t\t| 2) Buyer         |\n";
    cout << "\t\t\t\t\t|                  |\n";
    cout << "\t\t\t\t\t| 3) Exit          |\n";
    cout << "\t\t\t\t\t|                  |\n";
    cout << "\t\t\t\t\t Please Select!";
    cin >> choice;
    switch(choice)
    {
        case 1:
            {
                cout << "\t\t\t Please Login  \n";
                cout << "\t\t\t Enter Email   \n";
                cin >> email;
                cout << "\t\t\t Password      \n";
                cin >> password;
                if(email == "robby@email.com" &&    password == "robby@123")
                {
                    administrator();
                }
                else
                {
                    cout << "Invalid email/       password";
                }
                break;
            }
        case 2:
            {
                buyer();
            }
        case 3:
            {
                exit(0);
            }
        default : 
            {
                cout << "Please select from the given options"; 
            }

    }
    goto m;
}
void shopping :: administrator()
{
    m:
    int choice;
    cout << "\n\n\n\t\t\t Administrator menu";
    cout << "\n\t\t\t|________1) Add the product________|";
    cout << "\n\t\t\t|                                  |";
    cout << "\n\t\t\t|________2) Modify the product_____|";
    cout << "\n\t\t\t|                                  |";
    cout << "\n\t\t\t|________3) Delete the product_____|";
    cout << "\n\t\t\t|                                  |";
    cout << "\n\t\t\t|________4) Back to the main menu__|";

    cout <<"\n\n\t Please enter your choice ";
    cin >> choice;
    switch(choice)
    {
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        }
        case 3:
        {
            rem();
            break;
        }
        case 4:
        {
            menu();
            break;
        }
        default :
        {
            cout << "Invalid Choice!";
        }
    }
    goto m;
}
void shopping :: buyer()
{
    m:
    int choice;
    cout << "\t\t\t 1) Buyer \n";
    cout << "\t\t\t______________  \n";
    cout << "\t\t\t 1) Buy product \n";
    cout << "\t\t\t______________  \n";
    cout << "\t\t\t 1) Go Back     \n";
    cout << "\t\t\t______________  \n";
    cout << "\t\t\t Enter your choice : ";

    cin >> choice;
    switch(choice)
    {
        case 1:
        {
        receipt();
        break;
        }
        case 2:
        {
           menu(); 
        }
        default:
        {
            cout <<"Invalid Choice!";
        }
    
    }
goto m;   
}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\n\n\t\t\t Add new product";
    cout << "\n\n\t\t\t Product code of the product";
    cin >> pcode;
    cout << "\n\n\t Name of the product ";
    cin >> pname;
    cout << "\n\n\t\t Price of the product";
    cin >> price;
    cout << "\n\n\t\t\t Discount on product";
    cin >> dis;
    //files are used to store data permanently . A stream is an abstraction that represents a device on which input and output operations are performed.A stream can basically be represented as a source or destination of characters of indefinite length.
    //ofstream : This data type represents the output file stream and is used to create files and to write information to files
    //ifstream : This data type represents the input file stream and is useed to read information from files.
    //fstream : this data type represents the file stream generally  and has the capabilities of both ofstream and ifstream which means it can create files, write information to files and read information from files.

    data.open("database.txt",ios::in);//ios::in will open the file in reading mode and ios::out will open it in writing mode

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);//ios::app stands for append mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d; //initialising the index of file
        while(!data.eof()) //eof is end of file function 
        {
            if(c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;

        }
        data.close();
    
if(token == 1)
{
    goto m;
}
else
{
    data.open("database.txt",ios::app|ios::out);//ios::app stands for append mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
}
cout << " Record Inserted !";

}
}
void shopping :: edit()
{
    m:
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "\n\t\t\t Modify the record";
    cout << "\n\t\t\t Product code :";
    cin >> pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout << "File doesn't exist! ";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data >>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey == pcode)
            {
                cout << "\n\t\t Product new code";
                cin >> c;
                cout <<"\n\t\t Name of the product : ";
                cin >> n;
                cout <<"\n\t\t Price : ";
                cin >> p;
                cout <<"\n\t\t Discount : ";
                cin >> d;
                data << " " << c << " " << n << " " << p << " " << d <<"\n";
                cout <<"\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");
 if(token == 0)
 {
    cout << "\n\n record not found sorry !";
 }
 }

}

void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t Delete product";
    cout << "\n\n\t Enter the product code :";
    cin >> pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout << "File doesn't exist !";

    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data >> pcode >> pname >> price >> dis;
        while(!data.eof())
        {
            if(pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
         data >> pcode >> pname >> price >> dis;   
        }
            data1.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt", "databse.txt");

            if(token == 0)
            {
                cout << "\n\nRecord not found !";
            }
        

    }

}
void shopping :: list()
{
    fstream data;
    data.open("satabase.txt",ios::in);
    cout << "\n\n|___________________________________________|\n";
    cout << "ProNo\t\tName\t\tPrice\n";
    cout << "\n\n|___________________________________________|\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\n" ;
        data >> pcode >> pname >> price >> dis;

    }   
    data.close(); 
}
void shopping :: receipt()
{
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout << "\n_____________________________\n";
        cout << "\n                             \n";
        cout << "\n    Please place the order   \n";
        cout << "\n                             \n";
        cout << "\n_____________________________\n";
        do
        {
            cout << "\n\nEnter Product code :";
            cin >> arrc[c];
            cout << "\n\nEnter the product quantity";
            cin >> arrq[c];
            for(int i=0; i<c ;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout << " \n\n Duplicate product code. Please try again! ";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? if yes then press y else no";
            cin >> choice; 
        }
        while(choice == 'y');
        cout << "\n\n\t\t\t___________________________RECEIPT_________________";
        cout << "\n Product No\t Product Name\t Product Quantity\t Price\t Amount with discount\n";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data >> pcode >> pname >> price >> dis;
            while(!data.eof())
            {
                if(pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis/100);
                    total = total + dis;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" <<arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis; 
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
            data.close();
    }
        cout << "\n\n_________________________________";
        cout << "\n Total Amount : " << total;
}
    int main()
    {
        shopping s;
        s.menu();
    }
