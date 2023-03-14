#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<string.h>

using namespace std;
class person {
public:
    string name[20], address[20], gender[20], dis[20], qual[20], exp[20], spec[20], phone[20], disease[20], symptoms[20], city[20];
    int cabin[20], age[20], id[20], bill[20], charge[20], room[20];
};

//admin is a person(inheritance)

class admin : public person{

public:
    int dec = 0;
    int y,z;
    admin()
	{
		
	}

    admin(int diff)
    {
        int i, x = 0;
        char ch = '/0', password[] = "12345", match[20];

        do
        {
            
			system("cls");
            cout << "\n\n\t\t\tLOGIN FORM\n\t\t\t----------";
            cout << "\n\n\n ENTER  USERNAME:- ADMIN";
            

            cout << "\n\n ENTER PASSWORD:- ";
            //getch();

            for (i = 0; i >= 0;)
            {
                ch = _getch();

                if (ch != 8 && ch != 13)
                {
                    cout << "*";
                    match[i] = ch;
                    i++;
                }
                else if (ch == 8) // if backspace is presssed
                {
                    cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
                    i--;
                }
                else if (ch == 13)
                {
                    match[i] = '\0'; // if enter is pressed, last character in match[] becomes null
                    break;         // for end of string
                }
                else
                {
                    break;
                }
            }
            if (strcmp(match, password) == 0)// comparing two strings.. if equal returns 0
            {
                cout << endl << "\n\n\t\t\tWELCOME !! LOGIN IS SUCCESSFUL :)";
                //cout << "\n\n\n Press any key to continue\n";
                _getch();
                break;
            }
            else
            {
                cout << endl << "\n\n\t\tSORRY !!  LOGIN IS UNSUCESSFUL :(" << endl;
                x++;
                _getch();
            }
        }

        while (x <= 2);

        if (x > 2)
        {
            system("cls");
            cout << "\n\n You have entered invalid password many times\n\n\tTry Later\n\n";
            exit(1);
        }


        system("cls");
        cout << "\n\n\t\tWelcome to the Admin Page";
        cout << "\n\t\t-------------------------";
       // _getch();

        cout << "\n\n 1.Add Doctors";
        cout << "\n 2.Display Doctors";
        cout << "\n 3.Update Services";
        cout << "\n 4.View Services";
        cout << "\n 5.Exit";
        cout << "\n\n Enter Your Choice: ";
    
    }

   
    void add() {       
        ofstream os;
        os.open("admin.txt", ios::app);
        int i, en;
        system("cls");
        cout << "\n\tHow many Doctors You want to add: ";
        cin >> en;
        for (i = 1; i <= en; i++)
        {
            cout << "\n\nEnter Doctor's Name: ";
            cin >> name[i];
            os << name[i] << "        ";
            cout << "Enter Age: ";
            cin >> age[i];
            os << age[i] << "      ";
            cout << "Enter Gender: ";
            cin >> gender[i];
            os << gender[i] << "           ";
            cout << "Enter Qualification: ";
            cin >> qual[i];
            os << qual[i] << "             ";
            cout << "Enter Experience: ";
            cin >> exp[i];
            os << exp[i] << "          ";
            cout << "Enter Doctor's Specialization: ";
            cin >> spec[i];
            os << spec[i] << "       ";
            cout << "Enter Address: ";
            cin >> address[i];  
            os << address[i] << "       ";
            cout << "Enter Phone Number: ";
            cin >> phone[i];
            os << phone[i] << "        ";
            z = rand()*rand()/rand()%rand();
            y = rand();
            cout << "Your ID: " << y << endl;          
            id[i] = y;
            os << id[i] << " " << endl;
            cout << "\nwe have generated your Doctor ID\n";
            cout << "\n---------------------------";
            dec++;
            _getch();

        }
        os.close();
    }




    void display()
    {
        
        system("cls");
         
        //if (dec != 0)
        //{
            cout << "\n\tRecord List of Doctors";
            cout << "\n\t-----------------------\n\n";
            cout<<"       -------------------------------------------------------------------------------------------------------------------------------------      ";
            cout << "\n\n |Name|       |Age|      |Gender|      |Qualification|   |Experience|      |Specialist|         |Address|          |Phone|        |ID| \n\n";
            cout<<"       -------------------------------------------------------------------------------------------------------------------------------------      \n";
            ifstream is("admin.txt");
            char c;

            while (!is.eof())
            {
                is.get(c);

                if (!is.eof())
                    cout << c;

            }
            _getch();
            //cout << "\n\n\n\tNo Doctors Found";
       
       // }

       /* else
        {

            cout << "\n\t\tDOCTORS";
            cout << "\n\t\t-------";

            for (int i = 1; i <= dec; i++)
            {
                //cout << "\n\n ID \t Name \t Age \t Gender \t Qualification \t Experience \t Specialist \t Address \t Phone";
                // cout << "\n" << id[i] << "\t" << name[i] << "\t" << age[i] << "\t" << sex[i] << "\t" << qual[i] << "\t" << exp[i] << "\t" << spec[i] << "\t" << address[i] << "\t" << phone[i];


                cout << "\n\nID: " << id[i];
                cout << "\nName: " << name[i];
                cout << "\nAge: " << age[i];
                cout << "\nGender: " << gender[i];
                cout << "\nQualification: " << qual[i];
                cout << "\nExperience: " << exp[i];
                cout << "\nSpecialization: " << spec[i];
                cout << "\nAddress: " << address[i];
                cout << "\nPhone Number " << phone[i];
                _getch();
            }
            cout << endl << endl;
        }*/
    }

        
    void up_services() {
        
        cout << "\n What are the updated services in your Hospital\n\n\t";
            ofstream o;
            o.open("services.txt", ios::app);
            char ch = 0;

            while (ch != '.')
            {
                cin >> ch;

                if (ch != '.')
                    o.put(ch);
            }

            o.close();
    
    }

    void view_services()
    {
        cout << "These are the records and info of your Hospital\n\n\t";
        ifstream i("services.txt");
        char c;

        while (!i.eof())
        {
            i.get(c);

            if (!i.eof())
            {
                cout << c;
            }
        }
       
    }

};

//doctor is(can be) an admin (inheritance)

class doctor : public admin{

public:
    int dec=0;
    doctor() {    }

    doctor(int elig)
    {
        int chi;
        system("cls");
        cout << "\n\t\tWelcome to our Doctors Family\n ";
        cout << "\t\t----------------------------\n";

        cout << "\n 1. Edit Info";
        cout << "\n 2. Display Info";
        cout << "\n 3. Exit";
        cout << "\n\n Enter your Choice: ";

    }
    //admin's function of add can be done here instead of info() but we have done some new filling in this info() function 
    void info() {
        //dec = 0;
        ofstream os;
        os.open("admin.txt", ios::app);
        ofstream od("doctor.txt");
        

        int i, en, p, q;
        //cout << "\n\tHow many Doctors You want to add: ";
        //cin >> en;
        for (i = 1; i <= 1; i++)
        {
            cout << "\n\nEnter Doctor's Name: ";
            cin >> name[i];      
         	os << name[i] << "        ";
            od << name[i] << "        ";
            cout << "Enter Age: ";
            cin >> age[i];
            os << age[i] << "      ";
            od << age[i] << "      ";
            cout << "Enter Gender: ";
            cin >> gender[i];
            os << gender[i] << "           ";
            od << gender[i] << "           ";
            cout << "Enter Qualification: ";
            cin >> qual[i];
            os << qual[i] << "             ";
            od << qual[i] << "             ";
            cout << "Enter Experience: ";
            cin >> exp[i];
            os << exp[i] << "          ";
            od << exp[i] << "          ";
            cout << "Enter Doctor's Specialization: ";
            cin >> spec[i];
            os << spec[i] << "       ";
            od << spec[i] << "       ";
            cout << "Enter Address: ";
            cin >> address[i];
            os << address[i] << "       ";
            od << address[i] << "       ";
            cout << "Enter Phone Number: ";
            cin >> phone[i];
            os << phone[i] << "        ";
            od << phone[i] << "        ";
            p = rand() * rand() / rand();
            q = rand();
            cout << "Your ID: " << q << endl;
            id[i] = q;
            os << id[i] << " " << endl;
            od << id[i] << " " << endl;
            cout << "\nwe have generated your Doctor ID\n";
            cout << "\nYou are registered :)";
            cout << "\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
            dec++;
            _getch();

        }
        
    }

    /*void info_display()
    {

        system("cls");

        cout << "\n\tYour Info";
        cout << "\n\t---------\n\n";
        cout << "\n\n Name        Age      Gender      Qualification   Experience      Specialist         Address          Phone         ID \n\n";
        ifstream is("doctor.txt");
        char c;

        while (!is.eof())
        {
            is.get(c);

            if (!is.eof())
                cout << c;

        }
        _getch();
    }*/


    void info_display()
    {
               
        if (dec == 0)
        {
            cout << "\n\n\n\tNo Record Found";
        }

        else
        {

            cout << "\n\t\tYour Info";
            cout << "\n\t\t---------";

            for (int i = 1; i <= dec; i++)
            {
                cout << "\n\nID: " << id[i];
                cout << "\nName: " << name[i];
                cout << "\nAge: " << age[i];
                cout << "\nGender: " << gender[i];
                cout << "\nQualification: " << qual[i];
                cout << "\nExperience: " << exp[i];
                cout << "\nSpecialization: " << spec[i];
                cout << "\nAddress: " << address[i];
                cout << "\nPhone Number " << phone[i];
            }
            cout << endl << endl;
        }
    }


};


class patient : public person {
public:
    int temp = 0;

    patient() {}

    patient(int p) {

        system("cls");
        cout << "\n\t\tPatient Form";
        cout << "\n\t\t------------";

        cout << "\n\n 1. Edit Info";
        cout << "\n 2. Report";
        cout << "\n 3. Bill";
        cout << "\n 4. Exit";
        cout << "\n\n Enter your Choice: ";

    }

    void detail()
    {
        ofstream op("patient.txt");
        int i, ent, s, t, u;
        cout << "\n\tHow Many Entries you want to add: ";
        cin >> ent;
        for (i = 1; i <= ent; i++)
        {
            cout << "\n\nEnter Patient's ID: ";
            cin >> id[i];
            op << id[i];
            cout << "Enter patient's Name: ";
            cin >> name[i];
            op << name[i];
            cout << "Enter patient's Age: ";
            cin >> age[i];
            op << age[i];
            cout << "Enter patient's Gender: ";
            cin >> gender[i];
            op << gender[i];
            cout << "Enter patient's City: ";
            cin >> city[i];
            op << city[i];
            cout << "Enter patient's Disease: ";
            cin >> disease[i];
            op << disease[i];
            cout << "Enter patient's Symptoms: ";
            cin >> symptoms[i];
            op << symptoms[i];
            t = rand();
            cout << "Enter Patient's Room No.: " << t;
            room[i] = t;
            op << room[i];
            _getch();
            s = rand() * rand() / rand();
            // cout << " Enter Patient's Room Charge: "<<s;
            charge[i] = s;
            op << charge[i];
            u = rand() * rand() / rand();
            //cout << " Enter Patient's Total Bill: "<<u;
            bill[i] = u;
            op << bill[i];
            temp++;
            cout << "\n";
        }
        op.close();
    }


    void report()
    {

        if (temp == 0)
        {
            cout << "\n\n\n\tNo Record Found";
        }

        else
        {

            cout << "\n\t\t Report";
            cout << "\n\t\t--------";

            for (int i = 1; i <= temp; i++)
            {
                cout << "\n\n ID:        " << id[i];
                cout << "\n Name:      " << name[i];
                cout << "\n Age:       " << age[i];
                cout << "\n Gender:    " << gender[i];
                cout << "\n Disease:   " << disease[i];
                cout << "\n Symptoms:  " << symptoms[i];
                cout << "\n City:      " << city[i];
                cout << "\n Room no:   " << room[i];
                cout << "\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
                
            }
            cout << endl << endl;
        }
    }


    void gen_bill()
    {
        if (temp == 0)
        {
            cout << "\n\n\n\tNo Record Found";
        }

        else
        {

            cout << "\n\t\t BILL";
            cout << "\n\t\t------";

            for (int i = 1; i <= temp; i++)
            {
                cout << "\n\n ID:             " << id[i];
                cout << "\n\n Name:           " << name[i];
                cout << "\n\n Room no:        " << room[i];
                cout << "\n\n Room Charges:   " << charge[i];
                cout << "\n\n Total Bill:     " << bill[i];
                cout << "\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
            }
        }
    }
};

int main()
{
	
	
    admin ad;
    doctor doc;
    patient pat;
    int ch1, ch2, ch3, ch4, differ;
begin:
    system("cls");
     int i, x = 0;
        char ch = '/0', password[] = "20001", match[20];
        string y;
        
    
        do
        {
            system("cls");
    cout<<"\t          ___________                            \n";
	cout<<"\t          |+++++++++|                             \n";
	cout<<"\t          |+++++++++|                             \n";
	cout<<"\t          |+++++++++|                             \n";
	cout<<"\t    ______|+++++++++|______     WELCOME TO TUH HOSPITAL !!!! ): \n  ";                  
	cout<<"\t   |+++++++++++++++++++++++|                      \n";
	cout<<"\t   |+++++++++++++++++++++++|                      \n";
	cout<<"\t   |_______+++++++++_______|                      \n";
	cout<<"\t          |+++++++++|                             \n";
	cout<<"\t          |+++++++++|                             \n";
	cout<<"\t          |+++++++++|                             \n";
	cout<<"\t          |_________|                              \n";
           
            cout << "\n\n\t\t\tLOGIN COMPUTER :\n\t\t\t-------------";
            cout << "\n\n\n ENTER USERNAME:- ";
            cin>>y;

            cout << "\n\n ENTER PC PASSWORD:- ";
            //getch();

            for (i = 0; i >= 0;)
            {
                ch = _getch();

                if (ch != 8 && ch != 13)
                {
                    cout << "*";
                    match[i] = ch;
                    i++;
                }
                else if (ch == 8) // if backspace is presssed
                {
                    cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
                    i--;
                }
                else if (ch == 13)
                {
                    match[i] = '\0'; // if enter is pressed, last character in match[] becomes null
                    break;         // for end of string
                }
                else
                {
                    break;
                }
            }
            if (strcmp(match, password) == 0)// comparing two strings.. if equal returns 0
            {
                cout << endl << "\n\n\t\t\tWELCOME !!\n\t\tLOGIN IS DONE SUCCESSFUL :)";
                //cout << "\n\n\n Press any key to continue\n";
                _getch();
                break;
            }
            else
            {
                cout << endl << "\n\n\t\tSORRY !!\n\t\tLOGIN IS UNSUCESSFUL :(" << endl;
                x++;
                _getch();
            }
        }

        while (x <= 2);

        if (x > 2)
        {
            system("cls");
            cout << "\n\n You Have Entered Invalid Password Many Times !!! :\n\n\tPlease Try Later !!!!\n\n";
            exit(1);
        }


    
    
    cout << "\n\n";
    cout << "\t\t******************************************************************\n";
    cout << "\t\t*                                                                *\n";
    cout << "\t\t*            -----------------------------------------           *\n";
    cout << "\t\t*            |  WELCOME TO HOSPITAL MANAGEMENT SYSTEM |          *\n";
    cout << "\t\t*            -----------------------------------------           *\n";
    cout << "\t\t*                                                                *\n";
    cout << "\t\t*                                                                *\n";
    cout << "\t\t*                                                                *\n";
    cout << "\t\t*                                                                *\n";
    cout << "\t\t*                                                                *\n";
    cout << "\t\t*                                                                *\n";
    cout << "\t\t******************************************************************\n\n\n";
    
    cout<<" \tDisplay Option :\n";
    cout << " 1. Menu " << "\n\n";
    cout << " 2. Exit " << "\n\n\n\n";
    cout << " Enter Your Choice: ";
    cin >> ch1;
    if (ch1 == 1)
    {
    menu:
        system("cls");
        cout << "\n\n";
        cout<<  "            -------------      \n";
        cout << "            | MAIN MENU |    \n";
        cout << "            -------------   \n\n\n";
        //cout << "\n\n";
        cout<<" \tDisplay Option :\n";
        cout << " 1. Admin " << endl;
        cout << " 2. Doctor  " << endl;
        cout << " 3. Patient " << endl;
        cout << " 4. Exit " << endl;
        cout << "\n\n Enter Your choice: " << " ";
        cin >> ch2;

    page1:
        if (ch2 == 1)
        {
            int differ;
            system("cls");
            admin ob1(1);
            cin >> differ;

            switch (differ)
            {
            case 1:
                system("cls");
                ad.add();
                goto menu;
                break;

            case 2:
                system("cls");
                ad.display();
                //_getch();
                goto menu;
                break;

            case 3:
                system("cls");
                ad.up_services();
                goto menu;
                break;

            case 4:
                system("cls");
                ad.view_services();
                _getch();
                goto menu;
                break;

            case 5:
                goto menu;
                break;

            default:
                cout << "\n Invalid";
                _getch();
                goto menu;
            }
        }

        if (ch2 == 2)
        {
            system("cls");
            int elig;
            cout << "\t\tTo Enter the Doctor Forum ";
            cout << " \n\n\nEnter the three digit code recieved by the Hospital: ";
            cin >> elig;

            if (elig == 786)
            {
                int chi;
                doctor ob2(elig);
                cin >> chi;

                switch (chi)
                {
                case 1:
                    system("cls");
                    doc.info();
                    goto menu;
                    break;

                case 2:
                    system("cls");
                    doc.info_display();
                    _getch();
                    goto menu;
                    break;

                case 3:
                    goto menu;
                    break;

                default:
                    cout << "\n Invalid";
                    _getch();
                    goto menu;

                }

            }
            else if (elig != 786)
            {
                cout << "\n \t\tSORRY :( \n\n\t You are not ELIGIBLE for this JOB. \n\n\n";
                _getch();
                goto menu;
            }


        }

        if (ch2 == 3)
        {
            int p;
            system("cls");
            patient ob3(1);

            cin >> p;

            switch (p) {
            case 1:
                system("cls");
                pat.detail();
                goto menu;
                break;

            case 2:
                system("cls");
                pat.report();
                _getch();
                goto menu;
                break;

            case 3:
                system("cls");
                pat.gen_bill();
                _getch();
                goto menu;
                break;

            case 4:
                goto menu;
                break;

            default:
                cout << "\n Invalid";
                _getch();
                goto menu;
            }

        }


    }
    else if (ch1==2){
        return 0;
    }

    else {
    cout << "\n\n wrong input\n\n\n";
    return 0;
}

}
