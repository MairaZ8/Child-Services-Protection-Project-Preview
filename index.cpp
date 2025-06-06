# include <iostream>
# include <string>
# include <fstream>
#include<ctime>
#include<stdlib.h>
#include<conio.h>

using namespace std;

fstream login_details;
fstream Form;
fstream Law_des; 
fstream Case_1_Law_1;
fstream Case_2_Law_1;

static int count_law1 = 0;
static int case_count;

class org1 {

    private: 

        string name, address;
        int org_code; 
        string school_1, school_2, school_3, school_4, school_5;
        int school_code_1, school_code_2, school_code_3, school_code_4, school_code_5; 

    public: 

        org1 () {}

        org1 (string name, string address, int org_code, string school_1, string school_2, string school_3, string school_4, string school_5, int school_code_1, int school_code_2, int school_code_3, int school_code_4, int school_code_5) : name(name), address(address), org_code(org_code), school_1(school_1), school_2(school_2), school_3(school_3), school_4(school_4), school_5(school_5), school_code_1(school_code_1), school_code_2(school_code_2), school_code_3(school_code_3), school_code_4(school_code_4), school_code_5(school_code_5) {}

        int a, b, c, d, e;

            void setter () {

                school_1 = "A";
                school_code_1 = a;
                a = 123;
                school_2 = "A";
                school_code_2 = b;
                b = 123;
                school_3 = "A";
                school_code_3 = c;
                c = 123;
                school_4 = "A";
                school_code_4 = d;
                d = 123;
                school_5 = "A";
                school_code_5 = e;
                e = 123;

            }

            void getter () {

                cout<<"\nName of school: "<<school_1<<"\nSchool's code: "<<a<<endl;
                cout<<"\nName of school: "<<school_2<<"\nSchool's code: "<<b<<endl;
                cout<<"\nName of school: "<<school_3<<"\nSchool's code: "<<c<<endl;
                cout<<"\nName of school: "<<school_4<<"\nSchool's code: "<<d<<endl;
                cout<<"\nName of school: "<<school_5<<"\nSchool's code: "<<e<<endl;

            }

};

class Schools1 : public org1 {

    private: 
	
        static int count;
        int id_number;
        string first_name, middle_name, last_name;
        int age;
        string dob;
        string father_name, mother_name;
        string father_occupation, mother_occupation;
        string house_address;
        int father_contact_number, mother_contact_number, home_contact_number;
        string father_email, mother_email;
        string school_name, school_address;
        int grade;
        char section;
        string form_teacher_name;
        int num_of_siblings, current_visits;
        char out_of_ordinary;
	
	public:

        Schools1 () {}

        Schools1(int id_number, string first_name, string middle_name, string last_name, int age, string dob, string father_name, string mother_name, string father_occupation, string mother_occupation, 
        int father_contact_number, int mother_contact_number, int home_contact_number, string father_email, string mother_email, string school_name, string school_address,
        int grade, char section, string form_teacher_name, int num_of_siblings, int current_visits, string house_address, char out_of_ordinary) : first_name(first_name), middle_name(middle_name), last_name(last_name),
        age(age), dob(dob), father_name(father_name), mother_name(mother_name), father_occupation(father_occupation), mother_occupation(mother_occupation), father_contact_number(father_contact_number),
        mother_contact_number(mother_contact_number), home_contact_number(home_contact_number), father_email(father_email), mother_email(mother_email), school_name(school_name),
        school_address(school_address), grade(grade), section(section), form_teacher_name(form_teacher_name), num_of_siblings(num_of_siblings), current_visits(current_visits),
        house_address(house_address), out_of_ordinary(out_of_ordinary), id_number(id_number) {}
	
	    friend istream& operator>> (istream&, Schools1&); 

};

void login () {

    string username;
    string line_username;
    string password;
    string line_password;

    login_details.open ("login_details.txt", ios::app);

    if (!login_details) {

        cout<<"\nCouldn't open file."<<endl;

    }
    else if (login_details) {
    	ifstream file("login_details.txt");
    	
        cout<<"\nEnter your username."<<endl;
        cin>>username;
        
        string line;
        
        while (getline (file, line))
            {
            	
              

                if (line == username) {

                    cout<<"\nEnter the password."<<endl;
                    cin>>password; 

                    while (getline(file, line)) {

                     

                            if (line == password) {

                                cout<<"\nLogin successful."<<endl;

                                login_details.close();

                                    int choose;

                                    cout<<"\nEnter 1 to see information about org1."<<endl; //add infor 
                                    cin>>choose;

                                    if (choose == 1) {
 
                                        org1 o1;

                                        o1.setter();
                                        o1.getter();

                                        int code;

                                        cout<<"\nEnter the code of the school whose form you want to access."<<endl;
                                        cin>>code;

                                        if (code == o1.a) {

                                            Schools1 s1;

                                            cin>>s1;

                                        }

                                        // add more for each school.

                                    }


                                }

                            else {

                                cout<<"\nIncorrect password."<<endl;

                                login_details.close();

                            }

                    }

                }
               else {

                    cout<<"\nInvalid username."<<endl;

                    login_details.close();

                }
                }
                }




}

void forgot_pass () {

    string username;
    string line_username;
    string password;
    string line_password;

    login_details.open ("login_details.txt", ios::app);

    if (!login_details) {

        cout<<"\nCouldn't open file."<<endl;

    }
    else {
    	ifstream file("login_details.txt");
        cout<<"\nEnter your username."<<endl;
        cin>>username;
        string line;
        
       while (getline (file, line)) 
       {

                if (line == username) {

                    cout<<"\nEnter the new password."<<endl;
                    cin>>password; 

                    line_password = password;

                    login_details<<line_password<<endl;

                    login_details.close();

                    cout<<"\nPassword updated successfully."<<endl;

                }

                else{

                    cout<<"\nInvalid username."<<endl;
                
                    login_details.close();

                }

            }

    }

}

void reset_pass () {

    string username;
    string line_username;
    string password;
    string line_password;

    login_details.open ("login_details.txt", ios::app);

    if (!login_details) {

        cout<<"\nCouldn't open file."<<endl;

    }
    else {
    	string line;
    	ifstream file("login_details.txt");

        cout<<"\nEnter your username."<<endl;
        cin>>username;

        while (                getline (file, line))
            {

                if (line == username) {

                    cout<<"\nEnter the password."<<endl;
                    cin>>password; 

                    while (getline (file, line)) {

                        getline (file, line);

                            if (line == password) {

                                cout<<"\nEnter the new password."<<endl;
                                cin>>password; 

                                line_password = password;

                                file>>line_password;

                                login_details.close();

                                cout<<"\nPassword updated successfully."<<endl;

                            }

                            else {

                                cout<<"\nIncorrect password."<<endl;

                                login_details.close();
                                
                            }

                    }

                }

                else {

                    cout<<"\nInvalid username."<<endl;

                    login_details.close();

                }
            }

    }

}

class Gov {

    public:

        int option;

        void start () {

            cout<<"\nHello! Welcome to the data collection services for child protection organisation."<<endl;
            cout<<"\nEnter 1 to login.\n"<<"Enter 2 if you forgot your password."<<"\nEnter 3 to reset password."<<endl;
            cin>>option; 

            switch (option) {
            case 1:
                login ();
                break;

            case 2:
                forgot_pass ();
                break;

            case 3:
                reset_pass ();
                break;

            default:
                cout<<"\nInvalid option chosen."<<endl;
                break;
            }

        }
};

static int count = 0;

class cases : public Gov {
	

    public: 

        void case_1_law1 () {

            Case_1_Law_1.open("Case_1_Law_1.txt", ios::app);

            if (!Case_1_Law_1) {

                cout<<"\nTry again later!"<<endl;

            }
            else {

                while (!Case_1_Law_1.eof()) {

                    string output;

                    getline(Case_1_Law_1, output);

                    cout<<output<<endl;

                }
                Case_1_Law_1.close();

            }

        }

        void case_2_law1 () {

            Case_2_Law_1.open("Case_2_Law_1.txt", ios::app);

            if (!Case_2_Law_1) {

                cout<<"\nTry again later!"<<endl;

            }
            else {

                while (!Case_2_Law_1.eof()) {

                    string output;

                    getline(Case_2_Law_1, output);

                    cout<<output<<endl;

                }

                Case_2_Law_1.close();

            }

        }

};

void law (string x);

class Law : public Gov {

    private: 
	
        static int i;
        string keyword;
	
    public: 

        Law () {}

        void compare_keywords () {

            cout<<"\nEnter the keywords for the abuse you feel you have observed."<<endl;
            cin>>keyword;

            Law_des.open("Main Law keywords.txt", ios::app);
ifstream file("Law_des.txt");
            if(!Law_des) {

                cout<<"\nCouldn't open file."<<endl;

            }
                
            else {
            	 string line;

                while (getline(file,line)) {

               

         
         

                    if (line == keyword) {
                        
                        string match = line;
                        law(line);
                        
                        Law_des.close();
                    }

                }

            }
        }

};

istream& operator>> (istream& in, Schools1& s) {

    Form.open("Form.txt", ios::app);

            if (!Form) {

                cout<<"\nSorry! Data cannot be entered right now. Please try again later."<<endl;

            }
            else {

                string id_number;
                string first_name, middle_name, last_name;
                int age;
                string dob;
                string father_name, mother_name;
                string father_occupation, mother_occupation;
                string house_address;
                int father_contact_number, mother_contact_number, home_contact_number;
                string father_email, mother_email;
                string school_name, school_address;
                int grade;
                char section;
                string form_teacher_name;
                int num_of_siblings, current_visits;

                cout<<"\nEnter national ID number of child."<<endl;
                in>>s.id_number;
                
                ifstream file("Form.txt");

                string line;

                while (getline(file,line)) {
                    // compare id number from file and entered. if not existing, take form input. if exisits, don't take input.

                    if (line != id_number) {

                        cout<<"\nEnter the first name of the child."<<endl;
                        in>>s.first_name;

//                        cout<<"\nEnter the middle name of the child."<<endl;
//                        in>>s.middle_name;
//
//                        cout<<"\nEnter the last name of the child."<<endl;
//                        in>>s.last_name;
//
//                        cout<<"\nEnterh the age of the child."<<endl;
//                        in>>s.age;
//
//                        cout<<"\nEnter the date of birth of the child."<<endl;
//                        in>>s.dob;
//
//                        cout<<"\nEnter the father's name."<<endl;
//                        in>>s.father_name;
//
//                        cout<<"\nEnter the mother's name."<<endl;
//                        in>>s.mother_name;
//
//                        cout<<"\nEntehr the father's occupation."<<endl;
//                        in>>s.father_occupation;
//
//                        cout<<"\nEnter the mother's occupation."<<endl;
//                        in>>s.mother_occupation;
//
//                        cout<<"\nEnter the father's contact number."<<endl;
//                        in>>s.father_contact_number;
//
//                        cout<<"\nEnter the mother's contact number."<<endl;
//                        in>>s.mother_contact_number;
//
//                        cout<<"\nEnter the house's address."<<endl;
//                        in>>s.house_address;
//
//                        cout<<"\nEnter the house's contact number."<<endl;
//                        in>>s.home_contact_number;
//
//                        cout<<"\nEnter the father's email."<<endl;
//                        in>>s.father_email;
//
//                        cout<<"\nEnter the mother's email."<<endl;
//                        in>>s.mother_email;
//
//                        cout<<"\nEnter the number of siblings of the child."<<endl;
//                        in>>s.num_of_siblings;
//
//                        cout<<"\nEnter the school name."<<endl;
//                        in>>s.school_name;
//
//                        cout<<"\nEnter the school's address."<<endl;
//                        in>>s.school_address;
//
//                        cout<<"\nEnter the grade of the child."<<endl;
//                        in>>s.grade;
//
//                        cout<<"\nEnter the section of the child."<<endl;
//                        in>>s.section;
//
//                        cout<<"\nEnter the form_teacher's name."<<endl;
//                        in>>s.form_teacher_name;

                        cout<<"\nEnter the duration of weekly visits. 1 for weekly, 2 for bi-weekly, 3 for monthly, and 4 for speical case."<<endl;
                        in>>s.current_visits;

                        cout<<"\nDo you observe anything out of the ordinary? (Y/N)"<<endl;
                        in>>s.out_of_ordinary;
                        
                        char x='Y'; char y='y'; char a='N'; char b='n';
                        if (s.out_of_ordinary == x|| s.out_of_ordinary == y || s.out_of_ordinary == a || s.out_of_ordinary == b) {

                            							    Form>>s.first_name;
                                Form>>s.middle_name;
                                Form>>s.last_name;
                                Form>>s.middle_name;
                                Form>>s.dob;
                                Form>>s.age;
                                Form>>s.num_of_siblings;
                                Form>>s.father_name;
                                Form>>s.father_contact_number;
                                Form>>s.father_email;
                                Form>>s.father_occupation;
                                Form>>s.mother_name;
                                Form>>s.mother_contact_number;
                                Form>>s.mother_email;
                                Form>>s.mother_occupation;
                                Form>>s.house_address;
                                Form>>s.home_contact_number;
                                Form>>s.school_name;
                                Form>>s.school_address;
                                Form>>s.grade;
                                Form>>s.section;
                                Form>>s.form_teacher_name;
                                Form>>s.current_visits;

                                Form.close();

                                cout<<"\nData entered successfully."<<endl;

                        

                                    Law l1;
                                    l1.compare_keywords();
                                    

                        }
                        else {

                            if (s.current_visits != 1 || s.current_visits != 2 || s.current_visits != 3 || s.current_visits != 4) {

                                cout<<"\nInvalid option."<<endl;

                            }
                        
                        
                    
                    }
                }
                    else {
                        
                        int option;

                        cout<<"\nRecord already exists."<<endl;
                        cout<<"Enter 1 if you want to change the grade."<<endl;
                        cout<<"Enter 2 if you want to change the section."<<endl;
                        cout<<"Enter 3 if you want to change the house's address."<<endl;
                        cout<<"Enter 4 if you want to change the house's contact number."<<endl;
                        cout<<"Enter 5 if you want to change the father's occupation."<<endl;
                        cout<<"Enter 6 if you want to change the mother's occupation."<<endl;
                        cout<<"Enter 5 if you want to change the father's contact number."<<endl;
                        cout<<"Enter 6 if you want to change the mother's contact number."<<endl;
                        cout<<"Enter 7 if you want to change the number of siblings."<<endl;
                        cout<<"Enter 8 if you want to change the form teacher's name."<<endl;
                        cout<<"Enter 9 if you want to change the duration of visits."<<endl;
                        cout<<"Enter 10 if you want to change the observation of the child's condition."<<endl;
                        cout<<"Enter 0 if you want to exit the program.";

                        cin>>option;

                        if (option == 1) {

                            Form.open("Form.txt", ios::app);

                            if (!Form) {

                                cout<<"\nCannot open file."<<endl;

                            }
                            else {

                                cout<<"\nEnter the grade of the child."<<endl;
                                in>>s.grade;

                                Form<<"Grade: "<<s.grade<<endl;

                                cout<<"\nData updated successfully."<<endl;

                                Form.close();

                            }

                        }

                        else if (option == 2) {

                            Form.open("Form.txt", ios::app);

                            if (!Form) {

                                cout<<"\nCannot open file."<<endl;

                            }
                            else {

                                cout<<"\nEnter the section of the child."<<endl;
                                in>>s.section;

                                Form<<"Section: "<<s.section<<endl;

                                cout<<"\nData updated successfully."<<endl;

                                Form.close();

                            }

                        }
                    
                        else if (option == 3) {

                            Form.open("Form.txt", ios::app);

                            if (!Form) {

                                cout<<"\nCannot open file."<<endl;

                            }
                            else {

                                cout<<"\nEnter the house's address."<<endl;
                                in>>s.house_address;
                                Form<<"House's Address: "<<s.house_address<<endl;

                                cout<<"\nData updated successfully."<<endl;

                                Form.close();

                            }

                        }

                        else if (option == 4) {

                            Form.open("Form.txt", ios::app);

                            if (!Form) {

                                cout<<"\nCannot open file."<<endl;

                            }
                            else {

                                cout<<"\nEnter the house's contact number."<<endl;
                                in>>s.home_contact_number;
                                Form<<"House contact number: "<<s.home_contact_number<<endl;

                                cout<<"\nData updated successfully."<<endl;

                                Form.close();

                            }

                        }

                        //please complete these options. in else just add, invlaid option. for option 10, if Y, then call law function.

                    }

        }
                       
    }
}



class Law1: public Law {

    private:

        string name_of_law, description;
        int jail_time;
        double fine;
        int previous_cases_code [2];

    public: 

        Law1 () {}

        Law1 (string name_of_law, string description, int jail_time, double fine) : name_of_law("XYZ"), description("XYZ"), jail_time(123), fine(123.00) {previous_cases_code[0] = 4576, previous_cases_code[1] = 7890;}


        void display_law1 (int x) {

            cout<<"\nName: "<<name_of_law<<endl;
            cout<<"Description: "<<description<<endl;
            cout<<"Maximum jail time: "<<jail_time<<endl;
            cout<<"Fine amount: "<<fine<<endl;
            cout<<"Previous cases code: "<<previous_cases_code[0]<<"\t"<<previous_cases_code[1]<<endl; 

            int num;

            cout<<"\nEnter 1 if you want to view previous cases. Enter 2 if you want to exit the program."<<endl;
            cin>>num;

            if (num == 1) {

                cases c;
                c.case_1_law1();
                c.case_2_law1();

            }

        }

    // object made based on keywords
    // display info of law 
    // give option to show related past and ongoing cases
    
    //how baout doing the following in main law class and letting these child classes just contain the above info?
    
    // form to fill for law (how long abuse, in detail description etc)
    // assign worker for case 

};

class Worker : public Law {
	
	int worker_id;
	int assigned_case;
	int numberOfCases;
	bool availability;
	
	public:
		
		Worker() 
		{
			availability=true;
		}
		Worker(int id)
		{
			availability=true;
			worker_id=id;
		}
		
		void assigncase(int case_code)
		{
			availability=false;
		}
	   
		bool checkavailability()
		{
			return availability;
		}
		
		void change()
		{
			availability=false;

		}


};

void case_code () {

    case_count++;
    
    srand(time(NULL));
    int x;
    x=rand()%4;

    int case_code = 48;
    case_code = 48 + case_count * 15;

    Worker w[4];
    
    if(w[x].checkavailability())
    {
    	w[x].assigncase(case_code);
    	cout<<"Worker "<<x<<" has been assigned case: "<<case_code<<endl;
	}
	
	else
	{
		cout<<"Worker is unavailable."<<endl;
	}
	
	if(case_count>=4)
	{
		cout<<"No more cases may be considered for now."<<endl;
	}
	
//	cout<<"Press any key to exit"<<endl;
//	getch();
//	system("cls");
}

void law (string x) {

    case_code();

    if (x == "verbal abuse") {

        // need to add more keywords to for each law 
        count_law1++;

        Law1 l;

        l.display_law1 (count_law1);

    }
    //else ifs for other laws

}

void schools_choose_org1 (int x) {

    org1 O;

    O.setter ();
    O.getter ();

    int school_code;

    cout<<"\nEnter the school code to access information for the respective school."<<endl;
    cin>>school_code;

    if (school_code == O.a) {

        // go to school 1 and same for other schools

    }
    else if (school_code == O.b) {}
    else if (school_code == O.c) {}
    else if (school_code == O.d) {}
    else if (school_code == O.e) {}
    else {

        cout<<"\nInvlaid code."<<endl;

    }

}

void allow_to_choose () {

    int choose;

    cout<<"\nEnter 1 for Org1."<<"\nEnter 2 for Org2."<<"\nEnter 3 for Org3."<<"\nEnter 4 for Org4."<<"\nEnter 5 for Org5."<<"\nEnter 6 for Worker details."<<"\nEnter 7 for Law details."<<"\nEnter 8 for cases information."<<"\nEnter 9 to sign out."<<"\nEnter 0 to exit the program.";
    cin>>choose;

    if (choose == 1) {

        schools_choose_org1 (1);

    }
    else if (choose == 2) {}
    else if (choose == 3) {}
    else if (choose == 4) {}
    else if (choose == 5) {}
    else if (choose == 6) {}
    else if (choose == 7) {}
    else if (choose == 8) {}
    else if (choose == 9) {}
    else if (choose == 0) {

        cout<<"\nSigned out successfully. Have a good day."<<endl;

    }
    else {

        cout<<"\nInvalid option."<<endl;

    }
}

static int i = 0;

int main () {

    Gov g1;
    g1.start();

    return 0;

}
